#include <iostream>

char* concatenar(const char* r, const char* s) {
    // Calcular o tamanho da nova string
    int lenR = 0;
    while (r[lenR] != '\0') {
        lenR++;
    }

    int lenS = 0;
    while (s[lenS] != '\0') {
        lenS++;
    }

    // Alocar memória para a nova string
    char* nova = new char[lenR + lenS + 1];  // +1 para o caractere nulo de terminação

    // Concatenar r e s na nova string
    for (int i = 0; i < lenR; i++) {
        nova[i] = r[i];
    }

    for (int i = 0; i < lenS; i++) {
        nova[lenR + i] = s[i];
    }

    // Adicionar o caractere nulo de terminação
    nova[lenR + lenS] = '\0';

    return nova;
}

int main() {
    const char* str1 = "Hello, ";
    const char* str2 = "world!";
    char* resultado = concatenar(str1, str2);

    std::cout << "String concatenada: " << resultado << std::endl;

    // Liberar a memória alocada para a string concatenada
    delete[] resultado;

    return 0;
}
