#include<stdio.h>

int main() {
    int fault = 0, frame[10], ref[10], frame_length, ref_length;
    int page_index, ref_index, replace_index = 0;
    
    printf("Enter no of frames: ");
    scanf("%d", &frame_length);
    
    for(int i = 0; i < frame_length; i++) {
        frame[i] = -1;
    }
    
    printf("Enter the length of reference string: ");
    scanf("%d", &ref_length);
    
    printf("Enter the reference string: ");
    for(int i = 0; i < ref_length; i++) {
        scanf("%d", &ref[i]);
    }
    
    for(int i = 0; i < ref_length; i++) {
        int found = 0;
        
        // Check if page is already in frame
        for(int j = 0; j < frame_length; j++) {
            if(ref[i] == frame[j]) {
                found = 1;
                break;
            }
        }
        
        // Page fault occurs
        if(!found) {
            frame[replace_index] = ref[i];
            replace_index = (replace_index + 1) % frame_length;
            fault++;
        }
        
        // Print current frame
        printf("Current frame: ");
        for(int j = 0; j < frame_length; j++) {
            printf("%d ", frame[j]);
        }
        printf("\n");
    }
    
    printf("No of page faults: %d\n", fault);
    return 0;
}