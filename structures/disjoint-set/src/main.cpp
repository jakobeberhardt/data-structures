// main.cpp
#include <vector>
#include <algorithm>
#include <random>
#include <iostream>
#include <cassert>
#include "DisjointSet.h"
#include "QuickUnion.cpp"  // QuickUnion implementation
#include <iomanip>

// Structure to hold measured metrics.
struct Metrics {
    long totalPathLength;
    long totalPointerUpdates;
};

// Compute TPL and TPU for a DisjointSet with n elements.
// TPL is computed by walking from each element up to its representative,
// and TPU is defined here (for full compression heuristics) as:
//     TPU = TPL - (sum over roots of number of children).
// In our QuickUnion (no compression) TPU always remains 0.
Metrics measureMetrics(const DisjointSet& uf, int n) {
    long TPL = 0;
    std::vector<int> childrenCount(n, 0);
    
    // For each element, compute its depth.
    for (int i = 0; i < n; ++i) {
        int depth = 0;
        int current = i;
        while (current != uf.getParent(current)) {
            ++depth;
            current = uf.getParent(current);
        }
        TPL += depth;
    }
    
    // Count the number of children for each root.
    for (int i = 0; i < n; ++i) {
        if (uf.getParent(i) != i) {
            int parent = uf.getParent(i);
            childrenCount[parent]++;
        }
    }
    
    // For full compression (or path splitting) one may set:
    // TPU = TPL - (sum of children counts over all roots).
    // In no-compression, TPU remains 0.
    long sumChildren = 0;
    for (int i = 0; i < n; ++i) {
        if (uf.getParent(i) == i)
            sumChildren += childrenCount[i];
    }
    
    Metrics m;
    m.totalPathLength = TPL;
    m.totalPointerUpdates = TPL - sumChildren;  // Should be zero here.
    return m;
}

// Generate all distinct pairs (i, j) for i != j where i, j ∈ [0, n-1],
// and then shuffle them with a fixed seed (42) for reproducibility.
std::vector<std::pair<int, int>> generateDistinctPairs(int n) {
    std::vector<std::pair<int, int>> pairs;
    pairs.reserve(n * n - n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j)
                continue;
            pairs.push_back({i, j});
        }
    }
    std::mt19937 rng(42);
    std::shuffle(pairs.begin(), pairs.end(), rng);
    return pairs;
}

// Experimental driver function.
// n      : number of elements in the union–find instance.
// delta  : sampling frequency in terms of block count decrease (e.g., n/10).
// T      : number of experimental trials.
void runExperiment(int n, int delta, int T) {
    // Generate the master list of distinct pairs (shared by all experiments).
    const std::vector<std::pair<int,int>> masterPairs = generateDistinctPairs(n);
    
    // Determine the number of measurement steps.
    // We measure when the number of distinct blocks drops to:
//      n - delta + 1, n - 2*delta + 1, ..., and finally 1.
    int steps = (n - 1) / delta;  
    // We will record steps+1 measurements (the last measurement when 1 block remains).
    std::vector<long> accCycle(steps + 1, 0);
    std::vector<long> accTPL(steps + 1, 0);
    std::vector<long> accTPU(steps + 1, 0);
    std::vector<int> countMeasurements(steps + 1, 0);
    
    // Use a constant seed for each experiment to ensure reproducibility.
    const unsigned seed = 42;
    
    // Run T trials.
    for (int t = 0; t < T; ++t) {
        // For each trial, use the same master pairs but reshuffle.
        std::vector<std::pair<int,int>> pairs = masterPairs;
        std::mt19937 rng(seed);
        std::shuffle(pairs.begin(), pairs.end(), rng);
        
        // Create a new union–find instance.
        DisjointSet* uf = new QuickUnion(n);
        int cycleCount = 0;
        // Set the first measurement threshold (for n = 1000, delta = 100, threshold = 901).
        int nextMeasurementThreshold = n - delta + 1;
        int measurementIndex = 0;
        
        // Process each union until only one block remains.
        for (const auto &p : pairs) {
            uf->unionSets(p.first, p.second);
            cycleCount++;
            
            int currentBlocks = uf->countSets();
            // When the distinct block count reaches or drops below the current threshold, record a measurement.
            if (currentBlocks <= nextMeasurementThreshold) {
                Metrics m = measureMetrics(*uf, n);
                accCycle[measurementIndex] += cycleCount;
                accTPL[measurementIndex] += m.totalPathLength;
                accTPU[measurementIndex] += m.totalPointerUpdates;
                countMeasurements[measurementIndex]++;
                
                // Update the next measurement threshold.
                if (nextMeasurementThreshold > delta)
                    nextMeasurementThreshold -= delta;
                else
                    nextMeasurementThreshold = 1;
                measurementIndex++;
            }
            
            if (currentBlocks == 1)
                break;
        }
        delete uf;
    }
    
    std::cout << std::left
              << std::setw(18) << "Number of Blocks"
              << std::setw(15) << "CycleCount"
              << std::setw(15) << "AvgTPL"
              << std::setw(15) << "AvgTPU"
              << std::setw(20) << "Normalized TPL"
              << std::setw(20) << "Normalized TPU"
              << std::setw(15) << "Total Cost"
              << std::setw(20) << "Normalized Total Cost"
              << "\n";
              
    // Print a separator line.
    std::cout << std::string(18+15+15+15+20+20+15+20, '-') << "\n";
              
    // Print data rows with the same field widths.
    for (size_t i = 0; i < accCycle.size(); i++) {
        if (countMeasurements[i] >= 5) {
            int numBlocks;
            if (i < accCycle.size() - 1)
                numBlocks = (n - delta + 1) - (i * delta);
            else
                numBlocks = 1;
            double avgCycle = static_cast<double>(accCycle[i]) / countMeasurements[i];
            double avgTPL   = static_cast<double>(accTPL[i])   / countMeasurements[i];
            double avgTPU   = static_cast<double>(accTPU[i])   / countMeasurements[i];
            double normalizedTPL = avgTPL / n;
            double normalizedTPU = avgTPU / n;
            double totalCost = avgTPL; // for no compression, total cost = TPL
            double normalizedTotalCost = totalCost / n;
            
            std::cout << std::left
                      << std::setw(18) << numBlocks
                      << std::setw(15) << avgCycle
                      << std::setw(15) << avgTPL
                      << std::setw(15) << avgTPU
                      << std::setw(20) << normalizedTPL
                      << std::setw(20) << normalizedTPU
                      << std::setw(15) << totalCost
                      << std::setw(20) << normalizedTotalCost
                      << "\n";
        }
    }
}

int main() {
    int n = 1000;         // Number of elements (small instance).
    int delta = n / 10;   // Sample whenever the number of blocks decreases by n/10.
    int T = 20;           // Number of experimental trials.
    
    runExperiment(n, delta, T);
    return 0;
}
