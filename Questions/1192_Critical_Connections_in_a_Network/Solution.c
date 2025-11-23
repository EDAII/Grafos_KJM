#include <stdlib.h>
#include <stdio.h>

typedef struct NoGrafo {
    int vertice;
    struct NoGrafo* proximo;
} NoGrafo;

void adicionarAresta(NoGrafo** listaAdj, int u, int v) {
    NoGrafo* novoNo = (NoGrafo*)malloc(sizeof(NoGrafo));
    novoNo->vertice = v;
    novoNo->proximo = listaAdj[u];
    listaAdj[u] = novoNo;
}

void buscarConexoesCriticas(int verticeAtual, int verticePai, int* tempoAtual, int* tempoDescoberta, int* menorTempo, NoGrafo** listaAdj, int** resultado, int* contadorResultado) {
    tempoDescoberta[verticeAtual] = *tempoAtual;
    menorTempo[verticeAtual] = *tempoAtual;
    (*tempoAtual)++;

    NoGrafo* vizinhoTemp = listaAdj[verticeAtual];

    while (vizinhoTemp != NULL) {
        int vizinho = vizinhoTemp->vertice;

        if (vizinho == verticePai) {
            vizinhoTemp = vizinhoTemp->proximo;
            continue;
        }

        if (tempoDescoberta[vizinho] != -1) {
            if (tempoDescoberta[vizinho] < menorTempo[verticeAtual]) {
                menorTempo[verticeAtual] = tempoDescoberta[vizinho];
            }
        } else {
            buscarConexoesCriticas(vizinho, verticeAtual, tempoAtual, tempoDescoberta, menorTempo, listaAdj, resultado, contadorResultado);
            
            if (menorTempo[vizinho] < menorTempo[verticeAtual]) {
                menorTempo[verticeAtual] = menorTempo[vizinho];
            }

            if (menorTempo[vizinho] > tempoDescoberta[verticeAtual]) {
                resultado[*contadorResultado] = (int*)malloc(2 * sizeof(int));
                resultado[*contadorResultado][0] = verticeAtual;
                resultado[*contadorResultado][1] = vizinho;
                (*contadorResultado)++;
            }
        }
        vizinhoTemp = vizinhoTemp->proximo;
    }
}

int** criticalConnections(int n, int** connections, int connectionsSize, int* connectionsColSize, int* returnSize, int** returnColumnSizes) {
    NoGrafo** listaAdj = (NoGrafo**)calloc(n, sizeof(NoGrafo*));
    
    for (int i = 0; i < connectionsSize; i++) {
        adicionarAresta(listaAdj, connections[i][0], connections[i][1]);
        adicionarAresta(listaAdj, connections[i][1], connections[i][0]);
    }

    int* tempoDescoberta = (int*)malloc(n * sizeof(int));
    int* menorTempo = (int*)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        tempoDescoberta[i] = -1;
        menorTempo[i] = -1;
    }

    int** resultado = (int**)malloc(connectionsSize * sizeof(int*));
    int contadorResultado = 0;
    int tempoAtual = 0;

    buscarConexoesCriticas(0, -1, &tempoAtual, tempoDescoberta, menorTempo, listaAdj, resultado, &contadorResultado);

    *returnSize = contadorResultado;
    *returnColumnSizes = (int*)malloc(contadorResultado * sizeof(int));
    for (int i = 0; i < contadorResultado; i++) {
        (*returnColumnSizes)[i] = 2;
    }

    return resultado;
}