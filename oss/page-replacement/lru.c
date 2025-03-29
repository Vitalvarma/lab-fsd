#include<stdio.h>

int main() {
    int i, j, page_index, frame_index;
    int page_faults = 0;
    int reference_string[25], page_frames[10];
    int last_used_time[10] = {0}; // Tracks when each frame was last used
    int ref_str_length, frame_count;
    int current_time = 0;

    printf("\nEnter the length of reference string: ");
    scanf("%d", &ref_str_length);
    
    printf("\nEnter the reference string: ");
    for(i = 0; i < ref_str_length; i++)
        scanf("%d", &reference_string[i]);
    
    printf("\nEnter number of page frames: ");
    scanf("%d", &frame_count);
    
    // Initialize all frames to -1 (empty)
    for(i = 0; i < frame_count; i++) {
        page_frames[i] = -1;
        last_used_time[i] = -1;
    }

    printf("\nThe Page Replacement Process:\n");
    
    for(i = 0; i < ref_str_length; i++) {
        current_time++;
        int page = reference_string[i];
        int page_found = 0;
        
        // Check if page is already in a frame
        for(frame_index = 0; frame_index < frame_count; frame_index++) {
            if(page_frames[frame_index] == page) {
                last_used_time[frame_index] = current_time;
                page_found = 1;
                break;
            }
        }
        
        if(!page_found) {
            // Find LRU frame to replace
            int lru_index = 0;
            int min_time = last_used_time[0];
            
            for(j = 1; j < frame_count; j++) {
                if(last_used_time[j] < min_time) {
                    min_time = last_used_time[j];
                    lru_index = j;
                }
            }
            
            // Replace the LRU page
            page_frames[lru_index] = page;
            last_used_time[lru_index] = current_time;
            page_faults++;
            
        }
        
        // Print current frame status
        for(j = 0; j < frame_count; j++) {
            if(page_frames[j] == -1)
                printf("[ ] ");
            else
                printf("[%d] ", page_frames[j]);
        }
        printf("\n");
    }
    
    printf("\nTotal number of Page Faults using LRU: %d\n", page_faults);
    return 0;
}