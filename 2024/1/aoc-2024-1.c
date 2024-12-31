#include <stdio.h>
#include <stdlib.h>

void append(int** arr, int* newval, int len) {
    *arr = realloc(*arr, (len+1)*sizeof(int));
    (*arr)[len] = *newval;
}

int comp(const void* a,const void* b) {
    return *(int*)a - *(int*)b;
}

void sort(int* arr, int len) {
    qsort(arr, len, sizeof(int), comp);
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

    sort(nums1, len);
    sort(nums2, len);
   
    int total = 0;
    for (int i = 0; i < len; ++i) {
        total += abs(nums1[i] - nums2[i]);
    }

    printf("%d\n", total);
}
    //printf("\n");

