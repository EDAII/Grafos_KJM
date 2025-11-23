# 1192. Conexões Críticas em uma Rede (Critical Connections in a Network)

**Dificuldade:** Difícil  
**Tópicos:** Grafos, Conectividade, Pontes (Bridges), Algoritmo de Tarjan

## Descrição

Existem `n` servidores numerados de `0` a `n - 1` conectados por conexões servidor-a-servidor não direcionadas, formando uma rede onde `connections[i] = [ai, bi]` representa uma conexão entre os servidores `ai` e `bi`. Qualquer servidor pode alcançar outros servidores direta ou indiretamente através da rede.

Uma *conexão crítica* é uma conexão que, se removida, fará com que alguns servidores não consigam alcançar algum outro servidor.

Retorne todas as conexões críticas na rede em qualquer ordem.

## Exemplos

### Exemplo 1:

**Entrada:** `n = 4`, `connections = [[0,1],[1,2],[2,0],[1,3]]`  
**Saída:** `[[1,3]]`  
**Explicação:** `[[3,1]]` também é aceito.

### Exemplo 2:

**Entrada:** `n = 2`, `connections = [[0,1]]`  
**Saída:** `[[0,1]]`

## Restrições:

*   `2 <= n <= 10^5`
*   `n - 1 <= connections.length <= 10^5`
*   `0 <= ai, bi <= n - 1`
*   `ai != bi`
*   Não há conexões repetidas.
