#include "cadeia.h"
#include <stdio.h>

int str_tamanho(char *s) {
    int tamanho = 0;
    while (*s != '\0') {
        tamanho++;
        s++;
    }
    return tamanho;
}

void str_copia(char *s, char *d) {
    while (*s != '\0') {
        *d = *s;
        s++;
        d++;
    }
    *d = '\0';
}

void str_concatena(char *s, char *d) {
    while (*d != '\0') {
        d++;
    }
    while (*s != '\0') {
        *d = *s;
        s++;
        d++;
    }
    *d = '\0';
}