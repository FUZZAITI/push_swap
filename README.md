Markdown*Este projeto foi criado como parte do currículo da 42 por Pepinhei.*

# Push_swap

## Descrição
O **Push_swap** é um projeto de algoritmos da 42 que desafia o estudante a ordenar uma pilha de números inteiros utilizando um conjunto limitado de instruções e uma pilha auxiliar. O objetivo principal é desenvolver um programa que calcule e exiba a menor sequência de operações para ordenar os dados fornecidos.

Este projeto foca no entendimento de **complexidade de algoritmos (Big O Notation)** e na manipulação eficiente de estruturas de dados.

## Instruções

### Compilação
O projeto inclui um `Makefile` com as regras usuais. Para compilar, execute:

```bash
make
Como ExecutarO programa recebe uma lista de inteiros como argumento e retorna a lista de instruções para ordená-los.Bash./push_swap 2 1 3 6 5 8

Para verificar se a lista está realmente ordenada e contar o número de operações, você pode usar o checker (se disponível) ou pipes no terminal:BashARG="4 67 3 87 23"; ./

push_swap $ARG | wc -l

ARG=$(shuf -i 1-100 -n 100 | tr '\n' ' ');./push_swap $ARG | wc -l

Operações Permitidassa, sb, ss: Swap (troca os 2 primeiros elementos).pa, pb: Push (move o elemento do topo de uma pilha para a outra).ra, rb, rr: Rotate (o primeiro elemento torna-se o último).rra, rrb, rrr: Reverse Rotate (o último elemento torna-se o primeiro).RecursosReferências RelacionadasRadix Sort Algorithm: Explicação teórica sobre o algoritmo de ordenação não comparativa.Push_swap Tutorial - Medium: Guia sobre a lógica de pilhas.Big O Notation: Entendendo a eficiência de tempo e espaço.Uso de Inteligência ArtificialNeste projeto, a IA (Gemini) foi utilizada para:Estruturação de Documentação: Criação deste arquivo README.Otimização de Algoritmo: Auxílio na adaptação do Radix Sort para o sistema de duas pilhas (A e B) e conversão de números negativos através de indexação (simplificação de dados).Explicação de Conceitos: Clarificação sobre como realizar o bitwise shift em C para processar potências de 2 na base do Radix.Escolhas TécnicasAlgoritmo Radix SortPara lidar com grandes volumes de dados (como a stack de 500 números), optei pelo Radix Sort.Diferente de algoritmos de comparação como o QuickSort, o Radix Sort ordena os números processando seus dígitos individuais (bits). No contexto do Push_swap:Indexação: Primeiro, os números são "simplificados" para índices de 0 a N-1. Isso permite lidar com números negativos e grandes lacunas entre valores.Lógica Binária: O algoritmo percorre cada bit dos números (do menos significativo para o mais significativo).Distribuição: Se o bit atual for 0, o número é enviado para a Stack B (pb). Se for 1, ele permanece na Stack A (ra).Eficiência: Essa abordagem garante uma performance previsível de $O(n \cdot k)$, onde $n$ é a quantidade de números e $k$ é o número de bits necessários para representar o maior índice.