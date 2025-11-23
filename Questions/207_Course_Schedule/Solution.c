#include <stdbool.h>
#include <stdlib.h>

typedef struct NoGrafo {
    int idCurso;
    struct NoGrafo* proximo;
} NoGrafo;

bool verificarCiclo(int cursoAtual, NoGrafo** listaAdj, int* estados) {
    if (estados[cursoAtual] == 1) return true;
    if (estados[cursoAtual] == 2) return false;

    estados[cursoAtual] = 1;
    NoGrafo* noTemp = listaAdj[cursoAtual];
    
    while (noTemp != NULL) {
        if (verificarCiclo(noTemp->idCurso, listaAdj, estados)) return true;
        noTemp = noTemp->proximo;
    }

    estados[cursoAtual] = 2;
    return false;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    NoGrafo** listaAdj = (NoGrafo**)calloc(numCourses, sizeof(NoGrafo*));
    
    for (int i = 0; i < prerequisitesSize; i++) {
        int cursoAtual = prerequisites[i][1];
        int cursoProximo = prerequisites[i][0];
        
        NoGrafo* novoNo = (NoGrafo*)malloc(sizeof(NoGrafo));
        novoNo->idCurso = cursoProximo;
        novoNo->proximo = listaAdj[cursoAtual];
        listaAdj[cursoAtual] = novoNo;
    }

    int* estados = (int*)calloc(numCourses, sizeof(int));

    for (int i = 0; i < numCourses; i++) {
        if (verificarCiclo(i, listaAdj, estados)) {
            return false;
        }
    }

    return true;
}