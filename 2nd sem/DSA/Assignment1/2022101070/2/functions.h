#include <stdio.h>
#include <stdlib.h>

#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

int countCharOccurrences(const char* str, int length, char ch);

char findFirstNonRepeatingChar(const char* str, int length);

int* intersectionArray(int* arr1, int* arr2, int lenArr1, int lenArr2);

char* removeSubstring(char* str, int strLength, const char* substr, int substrLength);

int* maxMin(int* arr , int lenArr);

char* findLongestCommonPrefix(char** str, int numStr, int maxLen);

#endif
