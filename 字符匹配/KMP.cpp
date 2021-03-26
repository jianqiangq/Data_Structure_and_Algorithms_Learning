#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define NotFound -1

void BuildMatch(char* pattern, int* match) {
    int i, j;
    int m = strlen(pattern);
    match[0] = -1;
    for (j=1; j<m; j++) {
        i = match[j-1];

        while(i >= 0 && pattern[i+1] != pattern[j]) {
            i = match[i];
        }

        if (pattern[i+1] == pattern[j]) match[j] = i+1;
        else match[j] = -1;
    }
    return;
}


int KMP(char* str, char* pattern) {
    int n = strlen(str);
    int m = strlen(pattern);
    int s = 0, p = 0;
    int* match = (int*) malloc(sizeof(int) * m);

    BuildMatch(pattern, match);

    while(s < n && p < m) {
        if (str[s] == pattern[p])  { s++; p++; }
        else if (p > 0) p = match[p-1] + 1;
        else s++; // 两个字符不匹配，且 p = 0 的时候，s++
    }
    /*
    s = n, p != m
    s != n, p = m
    s = n, p = m
    */
    if (p == m) {
        return s-m;
    } else return NotFound;
}

int main(){
    char str[] = "this is a simple example";
    char pattern[] = "simple";
    int p = KMP(str, pattern);
    if (p == NotFound) printf("not found");
    else printf("%s\n", str+p);

}