#include <stdio.h>

int main() {
    int i, j, k, n, frames, page_faults = 0;
    int reference_string[25], memory[10];

    printf("Enter the length of reference string: ");
    scanf("%d", &n);

    printf("Enter the reference string: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &reference_string[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &frames);

    for (i = 0; i < frames; i++) {
        memory[i] = -1; // Initialize frames as empty
    }

    printf("\nPage Replacement Process:\n");

    for (i = 0; i < n; i++) {
        int page = reference_string[i];
        int found = 0;

        // Check if page is already in memory
        for (j = 0; j < frames; j++) {
            if (memory[j] == page) {
                found = 1;
                break;
            }
        }

        if (!found) {
            int replace_index = 0, farthest = i + 1;

            // Find the page to replace (Optimal)
            for (j = 0; j < frames; j++) {
                int next_use = n; // Default: page not used again
                for (k = i + 1; k < n; k++) {
                    if (memory[j] == reference_string[k]) {
                        next_use = k;
                        break;
                    }
                }
                if (next_use == n) {
                    replace_index = j;
                    break;
                } else if (next_use > farthest) {
                    farthest = next_use;
                    replace_index = j;
                }
            }

            memory[replace_index] = page;
            page_faults++;
        }

        // Print current memory state
        for (j = 0; j < frames; j++) {
            printf("%d\t", memory[j] != -1 ? memory[j] : '-');
        }

        if (!found) {
            printf("PF #%d", page_faults);
        }
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", page_faults);
    return 0;
}