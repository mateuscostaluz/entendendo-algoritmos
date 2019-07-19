#include <stdio.h>

int pesquisa_binaria(int v[], int inicio, int fim, int meio, int x) {
    if(x == v[meio]) {
        return meio;
    }
    else if (inicio == fim) {
        return -999; // nao encontrado
    }
    else if(x < v[meio]) {
        fim = meio - 1;
        int meio = (inicio + fim) / 2;
        pesquisa_binaria(v, inicio, fim, meio, x);
    }
    else if(x > v[meio]){
        inicio = meio + 1;
        int meio = (inicio + fim) / 2;
        pesquisa_binaria(v, inicio, fim, meio, x);
    }
}

int inicializador_pesquisa_binaria(int v[], int n, int x) {
    int inicio = 0;
    int fim = n - 1;
    int meio = (inicio + fim) / 2;
    return pesquisa_binaria(v, inicio, fim, meio, x);
}

int main() {
    int v[] = {1, 1, 2, 3, 5, 8, 13};
    int n = sizeof(v)/sizeof(v[0]); // quantidade de posicoes do vetor
    printf("%d ", inicializador_pesquisa_binaria(v, n, 11));
    printf("%d ", inicializador_pesquisa_binaria(v, n, 13));
    return 0;
}
