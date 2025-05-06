# Empirical Study of Union-Find

- Jakob Eberhardt (jakob.eberhardt@estudiantat.upc.edu)

## Project Structure

- **root/**: Contains the implementation and instrumentation including the Makefile to build the executable
- **configs/**: Includes the config files used to configure the benchmarks
- **util/**: Includes irrelevant helper functions, e.g. for plotting

## Building and running the project

The executable __benchmark__ is build by executing
```bash
make
```
The config files located under __configs__ correspond to the instances used in the project and can be executed as following
```bash
./benchmark configs/small.json
```