#include <iostream>

namespace sdds {

// Copies the source character string into the destination
    void strCpy(char* des, const char* src) {
        int i = 0;

        while (src[i] != '\0') {
            des[i] = src[i];
            i++;
        }
        des[i] = '\0';
    }

// Copies the source character string into the destination upto "len"
// characters. The destination will be null terminated only if the number
// of the characters copied is less than "len"
    void strnCpy(char* des, const char* src, int len) {
        int i = 0;

        while (src[i] != '\0' && i < len) {
            des[i] = src[i];
            i++;
        }
        des[i] = '\0';
    }

// Compares two C-strings 
// returns 0 if they'e the same
// return > 0 if s1 > s2
// return < 0 if s1 < s2
    int strCmp(const char* s1, const char* s2) {
        int result, i = 0;

        while (s1[i] != '\0' && s2[i] != '\0') {
            if (s1[i] < s2[i])
                result = -1;
            else if (s1[i] > s2[i])
                result = 1;
            i++;
        }
        if (s1[i] == '\0' && s2[i] == '\0')
            result = 0;
        else if (s1[i] == '\0')
            result = -1;
        else
            result = 1;
        return result;
    }

// returns 0 i thare the same
// return > 0 if s1 > s2
// return < 0 if s1 < s2
    int strnCmp(const char* s1, const char* s2, int len) {
        int result, i = 0;

        while (i < len && s1[i] != '\0' && s2[i] != '\0') {
            i++;
        }    
        result = strCmp(s1, s2);
        return result;
    } 

// returns the lenght of the C-string in characters
    int strLen(const char* s) {
      int len = 0;
        while (s[len] != '\0')
            len++;
        return len;
    }

// returns the address of first occurance of "str2" in "str1"
// returns nullptr if no match is found
    const char* strStr(const char* str1, const char* str2) {
        const char* result = nullptr;
        if (*str2 == '\0')
            result = str1;
        while (*str1 != '\0') {
            const char *p1 = str1;
            const char *p2 = str2;
            while (*p1 != '\0' && *p2 != '\0' && *p1 == *p2) {
                p1++;
                p2++;
            }
            if (*p2 == '\0')
                result = str1;
            str1++;
        }
        return result;
    }

// Concantinates "src" C-string to the end of "des"
    void strCat(char* des, const char* src) {
        int desLen = strLen(des);
        strCpy(des + desLen, src);
    }

}