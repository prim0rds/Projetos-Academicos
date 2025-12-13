# Sistema de Gerenciamento de Livros em C

Este projeto implementa um **sistema de gerenciamento de livros**
utilizando programação estruturada em C.\
Seu objetivo é permitir o cadastro, listagem, pesquisa e ordenação de
livros em um acervo limitado, aplicando conceitos fundamentais da
linguagem.

------------------------------------------------------------------------

## 🧩 Estrutura do Código

### 📁 **Struct Livro**

    struct Livro {
        int codigo;
        char titulo[50];
        char autor[50];
        char area[30];
        int ano;
        char editora[50];
    };

Armazena todas as informações essenciais de cada livro.

------------------------------------------------------------------------

## 🔧 Tecnologias e Recursos Utilizados

-   Linguagem C\
-   stdio.h, string.h, locale.h\
-   Vetores e estruturas (struct)\
-   Funções com parâmetros e ponteiros\
-   Manipulação de strings com fgets() e strcspn()\
-   Algoritmo de ordenação Bubble Sort\
-   Boas práticas de modularização e validação


