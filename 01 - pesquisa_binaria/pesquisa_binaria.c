#include <stdio.h>

// metodo iterativo
int pesquisa_binaria(int v[], int n, int x) {
    int inicio = 0;
    int fim = n - 1;
    int meio = (inicio + fim) / 2;
    while(inicio <= fim) {
        meio = (inicio + fim) / 2;
        if(x == v[meio]) {
            return meio;
        }
        else if(x < v[meio]) {
            fim = meio - 1;
        }
        else {
            inicio = meio + 1;
        }
    }
    return -999; // nao encontrado
}

// inicializador metodo recursivo
int inicializador_recursivo(int v[], int n, int x) {
    int inicio = 0;
    int fim = n - 1;
    int meio = (inicio + fim) / 2;
    return pesquisa_binaria_recursiva(v, inicio, fim, meio, x);
}

// metodo recursivo
int pesquisa_binaria_recursiva(int v[], int inicio, int fim, int meio, int x) {
    meio = (inicio + fim) / 2;
    if(x == v[meio]) {
        return meio;
    }
    else if(inicio >= fim) {
        return -999; // nao encontrado
    }
    else if(x < v[meio]) {
        fim = meio - 1;
        pesquisa_binaria_recursiva(v, inicio, fim, meio, x);
    }
    else {
        inicio = meio + 1;
        pesquisa_binaria_recursiva(v, inicio, fim, meio, x);
    }
}

int main() {
    int v[] = {1, 1, 2, 3, 5, 8, 13};
    int n = sizeof(v)/sizeof(v[0]); // quantidade de posicoes do vetor
    printf("%d ", pesquisa_binaria(v, n, 11));
    printf("%d ", pesquisa_binaria(v, n, 13));
    printf("%d ", inicializador_recursivo(v, n, 11));
    printf("%d ", inicializador_recursivo(v, n, 13));
    return 0;
}
