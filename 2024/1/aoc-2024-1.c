#include <stdio.h>
#include <stdlib.h>

void append(int* array, int newval, int len) {
    array = realloc(array, (len+1)*sizeof(*array));
    array[len] = newval;
}

int main(int argc, char *argv[]) {
    int int1, int2;

    int len = 0;
    int* nums1 = malloc(sizeof(int));
    int* nums2 = malloc(sizeof(int));

    while(EOF != fscanf(stdin, "%d  %d\n", &int1, &int2)) {
        append(nums1, int1, len);
        append(nums2, int2, len);
        len++;
    }

    for(int i = 0; i < len; i++) {
        printf("%d", nums1[i]);
    }
    printf("%s", "\n");


    for(int i = 0; i < len; i++) {
        printf("%d", nums2[i]);
    }
    printf("%s", "\n");
    
    free(nums1);
    free(nums2);
}

