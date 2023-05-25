#include <iostream>
#include "cstring.h"
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
        if (i < len)
        des[i] = '\0';
    }

// Compares two C-strings
// returns 0 if they'e the same
// return > 0 if s1 > s2
// return < 0 if s1 < s2
    int strCmp(const char* s1, const char* s2) {
        while (*s1 && (*s1 == *s2)) {
            s1++;
            s2++;
        }
        return (*s1) - (*s2);
    }

// returns 0 if they're the same
// return > 0 if s1 > s2
// return < 0 if s1 < s2
    int strnCmp(const char* s1, const char* s2, int len) {
        
        while (*s1 && (*s1 == *s2) && len - 1 > 0) {
            s1++;
            s2++;
            len--;
        }
        return (*s1) - (*s2);
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
