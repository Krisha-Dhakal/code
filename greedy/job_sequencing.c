#include <stdio.h>

void job_seq(int d[], int p[], int n);

int main() {
    int i, n, j[20], p[20], d[20];
    printf("Enter number of jobs: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter job profit: ");
        scanf("%d", &p[i]);
        j[i] = i + 1;

        printf("Enter job deadline: ");
        scanf("%d", &d[i]);
    }
    job_seq(d, p, n);

    return 0;
}

void job_seq(int d[], int p[], int n) {
    int i, r, l, k = 1;
    int jobs[20];

    for (i = 0; i < n; i++) {
        jobs[i] = -1; // Initialize the jobs array to -1
    }

    for (i = 0; i < n; i++) {
        r = (d[i] < n) ? d[i] : n; // Find the minimum of d[i] and n

        while (r >= 1) {
            if (jobs[r] == -1) { // If the slot is empty
                jobs[r] = i;
                break;
            }
            r--;
        }
    }

    printf("Job sequence: ");
    for (i = 1; i <= n; i++) {
        if (jobs[i] != -1) {
            printf("%d ", jobs[i] + 1); // Print the job number (add 1 since job indices are 0-based)
        }
    }
    printf("\n");
}
