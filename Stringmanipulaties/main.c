#include <stdio.h>
#include <stdlib.h>

int str_length(char* str) {
    unsigned int i = 0;
    while (str[i] != 0) {
        i++;
    }
    return i;
}

char* str_cat(char* str_left, char* str_right) {
    if (str_left == 0 || str_right == 0)
        return 0;
    int length_1 = str_length(str_left);
    int length_2 = str_length(str_right);
    char* ret = malloc(sizeof *ret * (length_1 + length_2 + 1));
    for (int i = 0; i < length_1; i++) {
        ret[i] = str_left[i];
    }
    for (int i = 0; i < length_2; i++) {
        ret[length_1 + i] = str_right[i];
    }
    ret[length_1 + length_2] = 0;
    return ret;
}

char** str_split(char* str, char* tokens, int* arrLength) {
    if (str == 0)
        return 0;
    int strLength = str_length(str);
    int indexes[strLength];
    indexes[0] = -1;
    unsigned int counter = 1, i = 0, j = 0;
    while (str[i] != 0) {
        j = 0;
        while (tokens[j] != 0) {
            if (str[i] == tokens[j])
                indexes[counter++] = i;
            j++;
        }
        i++;
    }
    indexes[counter] = str_length(str);
    char* words = malloc(sizeof *words * strLength * counter);
    char** arr = malloc(sizeof *arr * counter);
    for (i = 0; i < counter; i++) {
        arr[i] = words + i*strLength;
        for (int j = 0; j < strLength; j++) {
            if (j < (indexes[i+1]-indexes[i]-1)) {
                arr[i][j] = str[indexes[i]+j+1];
            } else {
                arr[i][j] = 0;
            }
        }
    }
    if (arrLength)
        *arrLength = counter;
    return arr;
}

int main() {
    char str[16] = "this is a test";
    printf("%d\n", str_length(str));

    char str1[16] =  "hello";
    char str2[16] =  " world";
    char* res = str_cat(str1, str2);
    printf("%s\n", res);
    free(res);

    int arrLength;
    char** splitRes = str_split(str, " ", &arrLength);
    for (int i = 0; i < arrLength; i++)
        printf("%s\n", splitRes[i]);
    free(*splitRes);
    free(splitRes);

    return 0;
}
























