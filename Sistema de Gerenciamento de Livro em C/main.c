// ========================================================================
// IMPORTAÇÃO DE BIBLIOTECAS
// Importação de bibliotecas essenciais para o funcionamento do programa
// ========================================================================
#include <stdio.h>
#include <string.h>
#include <locale.h>

// ===========
// CONSTANTE
// ===========
#define TAMANHO_ACERVO 20 // Definição da capacidade de armazenamento do acervo

// ===============================
// ESTRUTURA DO LIVRO
// ===============================
struct Livro {
    int codigo;
    char titulo[50];
    char autor[50];
    char area[30];
    int ano;
    char editora[50];
};

// ===============================
// PROTÓTIPOS DE FUNÇÕES
// ===============================
int menu();
void cadastrarLivro(struct Livro acervo[], int *tamanho);
void imprimirLivros(struct Livro acervo[], int tamanho);
void pesquisarLivro(struct Livro acervo[], int tamanho);
void ordenarLivros(struct Livro acervo[], int tamanho);


// ==========================================================
// FUNÇÃO PRINCIPAL: main
// Controla o fluxo do programa: exibe menu e chama funções.
// ==========================================================
int main() {

    // Habilita suporte a caracteres acentuados
    setlocale(LC_ALL, "");

    // Declaração de vetor e variáveis auxiliares
    struct Livro acervo[TAMANHO_ACERVO]; // Vetor
    int opcao; // Armazena a opção escolhida pelo usuário
    int tamanho = 0; // Total de livros cadastrados

    // Condição Do-While chamando a função menu que recebe a opção escolhida pelo usuário e efetua a lógica de escolha
    do {
        opcao = menu(); // Variável opcao recebe a atribuição da função menu que retorna a opção escolhida pelo usuário

        switch (opcao) {

            case 1:
                cadastrarLivro(acervo, &tamanho);
                break;

            case 2:
                imprimirLivros(acervo, tamanho);
                break;

            case 3:
                pesquisarLivro(acervo, tamanho);
                break;

            case 4:
                ordenarLivros(acervo, tamanho);
                break;

            case 5:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opção inválida!\n");
        }

    } while (opcao != 5);

    return 0;
}

// -------------------------------------------------------
// FUNÇÃO menu()
// Exibe o menu principal ao usuário e retorna a opção escolhida.
// É o ponto central de navegação do programa.
// -------------------------------------------------------
int menu(void) {

    int opcao; // Variável que irá armazenar a escolha do usuário

    printf("\n===================================\n");
    printf("SISTEMA DE GERENCIAMENTO DE LIVROS\n");
    printf("===================================\n\n");

    printf("Opção 1 - Cadastrar livro\n");
    printf("Opção 2 - Imprimir todos os livros\n");
    printf("Opção 3 - Pesquisar livro por código\n");
    printf("Opção 4 - Ordenar livro por ano de publicação\n");
    printf("Opção 5 - Sair do programa\n\n");

    printf("Digite uma opção: ");

    // Loop com mensagem de erro para entrada de dados diferente de um número inteiro
    while (scanf("%d", &opcao) != 1) {
        printf("Entrada inválida!\nDigite apenas números inteiros: ");
        while (getchar() != '\n'); // Limpa o primeiro buffer
    }
    while (getchar() != '\n'); // Limpa o buffer após a entrada válida

    return opcao; // Retorna opção digitada pelo usuário
}

// -------------------------------------------------------
// FUNÇÃO cadastrarLivro
// Recebe o vetor (acervo) e ponteiro para total; cadastra 1 livro.
// -------------------------------------------------------
void cadastrarLivro(struct Livro acervo[], int *tamanho) {
    /* Condição if: Se o total de livros for maior ou igual a constante TAMANHO_ACERVO 20, exibe uma mensagem de erro para o usuário
    caso a condição der falso ela prossegue e executa os dados do cadastro de livro */
    if (*tamanho >= TAMANHO_ACERVO) {
        printf("Limite máximo de livros atingidos.\n");
        return;
    }

    // Código do livro
    printf("\nDigite o código do livro: ");
    while (scanf("%d", &acervo[*tamanho].codigo) != 1) {
        printf("Entrada inválida!\nDigite apenas números inteiros: "); // Mensagem de erro
        while (getchar() != '\n'); // Limpa o primeiro buffer
    }
    while (getchar() != '\n'); // Limpa o buffer após entrada válida

    // Título
    printf("Digite o título do livro: ");
    fgets(acervo[*tamanho].titulo, 50, stdin);
    acervo[*tamanho].titulo[strcspn(acervo[*tamanho].titulo, "\n")] = '\0'; // Remove o ENTER que o fgets coloca no final da string.

    // Autor
    printf("Digite o nome do autor: ");
    fgets(acervo[*tamanho].autor, 50, stdin);
    acervo[*tamanho].autor[strcspn(acervo[*tamanho].autor, "\n")] = '\0'; // Remove o ENTER que o fgets coloca no final da string.

    // Área
    printf("Digite a área do livro: ");
    fgets(acervo[*tamanho].area, 30, stdin);
    acervo[*tamanho].area[strcspn(acervo[*tamanho].area, "\n")] = '\0';// Remove o ENTER que o fgets coloca no final da string.

    // Ano
    printf("Digite o ano de publicação: ");
    while (scanf("%d", &acervo[*tamanho].ano) != 1) {
        printf("Ano inválido!\nDigite apenas números inteiros: "); // Mensagem de erro
        while (getchar() != '\n'); // Limpa o primeiro buffer
    }
    while (getchar() != '\n'); // Limpa o buffer após a entrada válida

    // Editora
    printf("Digite a editora do livro: ");
    fgets(acervo[*tamanho].editora, 50, stdin);
    acervo[*tamanho].editora[strcspn(acervo[*tamanho].editora, "\n")] = '\0'; // Remove o ENTER que o fgets coloca no final da string.

    printf("\nLivro cadastrado com sucesso!\n"); // Mensagem de sucesso!!

    (*tamanho)++; // Acrescenta 1 no meu total de livros
}

// ===============================
// FUNÇÃO imprimirLivros()
// Imprime todos os livros do acervo utilizando laço FOR que percorre todo vetor
// ===============================
void imprimirLivros(struct Livro acervo[], int tamanho) {

    // Condição if: Se o total de livros cadastrado for igual a 0, exibe mensagem de erro para o usuário
    if (tamanho == 0) {
        printf("\nNenhum livro cadastrado.\n"); // Mensagem de erro
        return;
    }

    // Laço for para percorrer o vetor e imprimir todos os livros cadastrados
    for (int i = 0; i < tamanho; i++) {
        printf("\n--------- Livro %d ---------", i + 1);
        printf("\nCódigo: %d\n", acervo[i].codigo);
        printf("Título: %s\n", acervo[i].titulo);
        printf("Autor: %s\n", acervo[i].autor);
        printf("Área: %s\n", acervo[i].area);
        printf("Ano: %d\n", acervo[i].ano);
        printf("Editora: %s\n", acervo[i].editora);
        printf("-----------------------------");
        printf("\n");
    }
}

// ===============================
// FUNÇÃO pesquisarLivro()
// Busca livro pelo código
// ===============================
void pesquisarLivro(struct Livro acervo[], int tamanho) {

    int codigoBusca; // Variável que irá armazenar o código inserido pelo usuário

    printf("\nDigite o código do livro: ");

    // Loop while: Verifica se o código digitado é válido
    while (scanf("%d", &codigoBusca) != 1) {
        printf("Entrada inválida!\nDigite apenas números inteiros: "); // Mensagem de erro
        while(getchar() != '\n'); // Limpa o primeiro buffer
    }
    while(getchar() != '\n'); // Limpa o buffer após a entrada válida

    // Laço for para percorrer todo vetor e verificar se o código digitado pelo usuário é igual a algum código cadastrado no acervo
    for (int i = 0; i < tamanho; i++) {
        if (acervo[i].codigo == codigoBusca) {
            printf("\n--------- Livro Encontrado ---------");
            printf("\nTítulo: %s\n", acervo[i].titulo);
            printf("Autor: %s\n", acervo[i].autor);
            printf("Área: %s\n", acervo[i].area);
            printf("Ano de publicação: %d\n", acervo[i].ano);
            printf("Editora: %s\n", acervo[i].editora);
            printf("-----------------------------");
            return;
        }
    }

    printf("\nLivro não encontrado!\n");
}

// ===============================
// FUNÇÃO ordenarLivros()
// Bubble sort por ano crescente
// ===============================
void ordenarLivros(struct Livro acervo[], int tamanho) {

    // Condição if: Se meu total de livros for menor ou igual a 1, exibe mensagem de erro ao usuário
    if (tamanho <= 1) {
        printf("Total de livros insuficientes para ordenar!\n"); // Mensagem de erro
        return;
    }

    struct Livro temp; // Variável temporária para efetuar a troca

    // Função BubbleSort
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - 1 - i; j++) {
            if (acervo[j].ano > acervo[j + 1].ano) {
                temp = acervo[j]; // Variável temporária recebe o valor da variável na posição [j]
                acervo[j] = acervo[j + 1]; // Variável na posição [j] recebe o valor da posição [j + 1]
                acervo[j + 1] = temp; // Variável na posição [j + 1] recebe o valor da variável temporária
            }
        }
    }

    printf("\nLivros ordenados por ano!\n");

    imprimirLivros(acervo, tamanho); // Após a execução da função BubbleSort, a função imprimirLivros é reutilizada
}
