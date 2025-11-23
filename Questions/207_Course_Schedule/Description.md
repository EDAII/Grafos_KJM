# 207. Cronograma de Cursos (Course Schedule)

**Dificuldade:** Média  
**Tópicos:** Grafos, Busca em Profundidade (DFS), Busca em Largura (BFS), Ordenação Topológica

## Descrição

Existe um total de `numCourses` cursos que você deve fazer, rotulados de `0` a `numCourses - 1`. Você recebe um array `prerequisites` onde `prerequisites[i] = [ai, bi]` indica que você **deve** fazer o curso `bi` primeiro se quiser fazer o curso `ai`.

*   Por exemplo, o par `[0, 1]` indica que para fazer o curso `0` você deve primeiro fazer o curso `1`.

Retorne `true` se você puder terminar todos os cursos. Caso contrário, retorne `false`.

## Exemplos

### Exemplo 1:

**Entrada:** `numCourses = 2`, `prerequisites = [[1,0]]`  
**Saída:** `true`  
**Explicação:** Existem um total de 2 cursos para fazer. Para fazer o curso 1, você deve ter terminado o curso 0. Portanto, é possível.

### Exemplo 2:

**Entrada:** `numCourses = 2`, `prerequisites = [[1,0],[0,1]]`  
**Saída:** `false`  
**Explicação:** Existem um total de 2 cursos para fazer. Para fazer o curso 1, você deve ter terminado o curso 0, e para fazer o curso 0, você deve também ter terminado o curso 1. Portanto, é impossível.

## Restrições:

*   `1 <= numCourses <= 2000`
*   `0 <= prerequisites.length <= 5000`
*   `prerequisites[i].length == 2`
*   `0 <= ai, bi < numCourses`
*   Todos os pares de `prerequisites[i]` são **únicos**.
