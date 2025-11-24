# Grafos_KJM

### Trabalho 04 - 22/11/2025

## Alunos  
| Matrícula | Nome |  
|-----------------------|---------------------|  
| 231026975 | Kaleb de Souza Macedo |  
| 231011533 | João Maurício Pilla Nascimento |  

## Descrição do projeto
Nossa dupla realizou algumas questões da plataforma LeetCode, no intuito de colocar em prática os conhecimentos adquiridos sobre o conteúdo de Grafos.
## Questões

**Gravação da Apresentação**:

Link da apresentação: https://youtu.be/qnP2swFIo_Y

---

|Questão | Dificuldade |
| -- | -- |
| [802. Find Eventual Safe States](https://leetcode.com/problems/find-eventual-safe-states/)  | Média |
| [2290. Minimum Obstacle Removal to Reach Corner](https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/)  | Difícil |
| [207. Course Schedule](https://leetcode.com/problems/course-schedule/)  | Média |
| [1192. Critical Connections in a Network](https://leetcode.com/problems/critical-connections-in-a-network/)  | Difícil |

## Conclusões

### 802. Find Eventual Safe States
O problema pede para, dado uma grafo de `n` nós, Retretornar um array contendo todos os nós seguros do grafo. Com um nó sendo seguro quando todos os caminhos possíveis que partem desse nó levam a um nó terminal (ou a outro nó seguro).

* Um nó é considerado terminal se não houver arestas de saída para ele.

---

### 2290. Minimum Obstacle Removal to Reach Corner
O problema pede para, dado uma matriz `m x n`, com cada célula tendo valor:

* `0` quando vazia
* `1` quando contém obsatáculo

Retorne o valor mínimo de obstáculos removidos para ir de `(0, 0)` para `(m - 1, n - 1)`.

---

### 207. Course Schedule

O problema pede para determinar se é possível concluir todos os cursos, dados os pré-requisitos. Isso pode ser modelado como um problema de detecção de ciclo em um grafo direcionado, onde os cursos são nós e os pré-requisitos são arestas.

Para resolver, utilizamos uma Busca em Profundidade (DFS) com coloração de três estados:
*   0: Não visitado
*   1: Visitando (atualmente na pilha de recursão)
*   2: Visitado (já processado)

Se durante a DFS encontrarmos um nó no estado "Visitando", detectamos um ciclo, o que significa que é impossível concluir os cursos. Se percorrermos todo o grafo sem encontrar ciclos, retornamos verdadeiro.

---

### 1192. Critical Connections in a Network

O problema pede para encontrar todas as conexões críticas em uma rede de servidores. Uma conexão é considerada crítica (ou uma "ponte" na teoria dos grafos) se sua remoção desconectar a rede, ou seja, aumentar o número de componentes conectados.

Para resolver, utilizamos o Algoritmo de Tarjan (ou uma variação baseada em DFS) para encontrar pontes. Mantemos dois arrays durante a travessia:
*   `tempoDescoberta`: O momento em que cada nó foi visitado pela primeira vez.
*   `menorTempo`: O menor tempo de descoberta alcançável a partir do nó (incluindo ele mesmo e seus descendentes na árvore DFS), podendo usar arestas de retorno.

Uma aresta `u-v` é crítica se `menorTempo[v] > tempoDescoberta[u]`, indicando que não há outro caminho de volta de `v` para `u` ou seus ancestrais.

## Dupla

<table align="center">
  <tr>
    <td align="center">
      <img src="https://avatars.githubusercontent.com/u/163928510?v=4" width=150><br>
      <b><a href="https://github.com/kalebmacedo">Kaleb de Souza</a></b><br>
    </td>
    <td align="center">
      <img src="https://avatars.githubusercontent.com/u/144487097?v=4" width=150><br>
      <b><a href="https:github.com/JMPNascimento">João Maurício</a></b><br>
    </td>
  </tr>
</table>
