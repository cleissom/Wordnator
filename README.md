# Wordnator
## Projeto: Wordnator v0.92
Descrição: Leitura e inserção de um dicionário em estrutura de dados RED BLACK TREE

## Começando:
Siga as instruções abaixo para para testar o código.

## Pré requisitos:
Arquivo dicionário .csv (inlcuso), deve estar na forma: src/dic_one_line.csv

## Instalação: 

Para execução em LINUX, comentar #define WINDOWS em interface.c

Compile os arquivos main.c; /src/interface.c; /src/leitura.c; /src/palavra.c; /src/red_black_tree.c

## Execução:
O programa lê o dicionário e insere na árvore, após isso pode-se pesquisar palavras pela interface.
Digite "exit" sem aspas para terminar o programa.

## Exportação dot file:
Para exportar o arquivo dot da árvore a cada inserção basta descomentar #define PRINT_TREE em leitura.c e executar o programa.

## Notas: 
Programa versão Beta 0.92 - busca de palavras com acentuação não funciona completamente.

## Autores:
Cleissom Fernandes da Silva

Ian Schmiegelow Dannapel

## Licença:
Wordnator está licenciado sob MIT License
