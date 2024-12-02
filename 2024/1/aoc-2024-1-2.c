#include <stdio.h>
#include <stdlib.h>

void append(int** arr, int* newval, int len) {
    *arr = realloc(*arr, (len+1)*sizeof(int));
    (*arr)[len] = *newval;
}

int main(int argc, char *argv[]) {
    int *int1 = malloc(sizeof(int));
    int *int2 = malloc(sizeof(int));

    int len = 0;
    int* nums1 = malloc(sizeof(int));
    int* nums2 = malloc(sizeof(int));

    while(EOF != fscanf(stdin, "%d  %d\n", int1, int2)) {
        append(&nums1, int1, len);
        append(&nums2, int2, len);
        len++;
    }
   
    int total = 0;
    for (int i = 0; i < len; ++i) {
        int count = 0;
        for (int j = 0; j < len; ++j) {
            if (nums1[i] == nums2[j]) {
                count++;
            }
        }
        total += nums1[i]*count;
    }

    printf("%d\n", total);
}

