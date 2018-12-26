#ifndef STRINGMANIPULATIES_H
#define STRINGMANIPULATIES_H

int str_length(char* str);
char* str_cat(char* str_left, char* str_right);
char** str_split(char* str, char* tokens, int* arrLength);
int str_comp(char* str1, char* str2);

#endif // STRINGMANIPULATIES_H
