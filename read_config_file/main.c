#include <stdio.h>
#include <stdlib.h>
#include "stringmanipulaties.h"

void sum(double* val1, double* val2) {
    if (val1 && val2)
        *val1 += *val2;
}

void substraction(double* val1, double* val2) {
    if (val1 && val2)
        *val1 -= *val2;
}

void division(double* val1, double* val2) {
    if (val1 && val2)
        *val1 /= *val2;
}

void calculate(char* type, double values[], int valCount) {
    if (!type)
        return;
    void (*operation)(double*, double*);
    double res = values[0];

    if (str_comp(type, "SUM"))
        operation = &sum;
    else if (str_comp(type, "SUBTRACTION"))
        operation = &substraction;
    else if (str_comp(type, "DIVISION"))
        operation = &division;
    else
        return;

    for (int i = 1; i < valCount; i++) {
        (*operation)(&res, values+i);
    }
    printf("%f\n", res);
}

int main()
{
    FILE* fp;
    fp = fopen("./conf.txt", "r");
    if (fp) {
        // Read and store file content
        fseek(fp, 0, SEEK_END);
        int length = ftell(fp);
        fseek(fp, 0, SEEK_SET);
        char* fileContent = malloc(length+1);
        char currentChar;
        int counter = 0;
        while ((currentChar = fgetc(fp)) != EOF)
            fileContent[counter++] = currentChar;
        fileContent[counter] = 0;

        // Split content in lines
        int arrLenght;
        char** lines = str_split(fileContent, "\n", &arrLenght);

        // Parse every lines
        for (int i = 0; i < arrLenght; i++) {
            int argCount;
            char** lineSplit = str_split(lines[i], "=,", &argCount);
            double values[argCount-1];
            for (int j = 1; j < argCount; j++) {
                sscanf(lineSplit[j], "VALUE:%lf", values+j-1);
            }
            calculate(lineSplit[0], values, argCount-1);

            free(*lineSplit);
            free(lineSplit);
        }

        free(fileContent);
        free(*lines);
        free(lines);
    }
    fclose(fp);
    return 0;
}
