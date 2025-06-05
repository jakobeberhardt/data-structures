#include <stdio.h>
#include <string.h>

#define MAXN 1000000

static char s[MAXN + 1];            
static char t[2 * MAXN + 2];      
static int  pi[2 * MAXN + 2];       

int main(void)
{
    while (scanf("%1000000s", s) == 1)         
    {
        int n = (int)strlen(s);                

        for (int i = 0; i < n; ++i)      
            t[i] = s[n - 1 - i];
        t[n] = '#';                       
        memcpy(t + n + 1, s, n);              
        int m = 2 * n + 1;                    

        pi[0] = 0;
        for (int i = 1; i < m; ++i) {
            int j = pi[i - 1];
            while (j && t[i] != t[j])
                j = pi[j - 1];
            if (t[i] == t[j])
                ++j;
            pi[i] = j;
        }

        printf("%d\n", pi[m - 1]);
    }
    return 0;
}
