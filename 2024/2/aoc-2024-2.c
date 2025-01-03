#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


void appendChar(char *str, char ch) {
    int len = strlen(str);
    str[len] = ch;
    str[len + 1] = '\0';
}

int main(int argc, char *argv[]) {
    // char* str = malloc(100*sizeof(char));

    int total = 0;
    char del = ' ';
    char str[100];
    // while (fgets(str, 100, stdin) != NULL && str[0]) {
    while(EOF != fscanf(stdin, "%[^\n]\n", str)) {
        printf("\n");
        printf(str);
        char* nums = strtok(str, &del);
        int len = sizeof(&nums) / sizeof(char);
        // printf("%d\n", len);
        int prev = -1;
        char inc = 'n';
        for (int i = 0; i < len; i++) {
            int num = atoi(&nums[i]);
            printf("%c,%d", nums[i], num);
            if (prev == -1) {
                prev = num;
                continue;
            }
            int diff = abs(num - prev);
            if ((diff < 1 || diff > 3)) {
                break;
            }
            char new_inc = 'n';
            if (num > prev) {
                new_inc = 'i';
            } else if (num < prev) {
                new_inc = 'd';
            } else {
                break;
            }
            if (inc != new_inc) break;
            total += 1;
        }

        //char* line = strtok(str, del);
        //int len = sizeof(&line) / sizeof(char);
        //for (int i = 0; i < 1; i++) { 
        //}
    }

    printf("%d\n", total);
}

