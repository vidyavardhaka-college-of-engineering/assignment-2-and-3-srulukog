#include <stdio.h>

long long int assign(int n, int preference[][n]) {
    int mx = 1 << n;
    long long int dp[mx];
    
    // Initialize all values of dp to 0
    for (int i = 0; i < mx; i++) {
        dp[i] = 0;
    }
    
    // Base case
    dp[mx - 1] = 1;

    for (int mask = mx - 2; mask >= 0; mask--) {
        // Count the number of set bits in mask
        int s = 0;
        for (int j = mask; j; j >>= 1) {
            s += j & 1;
        }

        for (int i = 0; i < n; i++) {
            // If the subject i is not assigned and the student s has a preference for subject i
            if (preference[s][i] && !(mask & (1 << i))) {
                dp[mask] += dp[mask | (1 << i)];
            }
        }
    }

    return dp[0];
}

int main() {
    int n;
    printf("How many students are there?\n");
    scanf("%d", &n);

    int preference[n][n];

    printf("\nEnter the preferences of each of %d students for %d subjects\n", n, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &preference[i][j]);
        }
    }

    printf("\nTotal number of assignments that can be prepared are \n");
    printf("%lld\n", assign(n, preference));

    return 0;
}

