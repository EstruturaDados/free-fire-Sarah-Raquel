#include <stdio.h>
#include <string.h>

#define MAX 10   // Tamanho máximo da mochila

// Aqui eu crio a struct que representa um item do inventário
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// Função para listar todos os itens do inventário
void listarItens(Item mochila[], int total) {
    printf("\n=== ITENS NA MOCHILA ===\n");

    if (total == 0) {
        printf("A mochila esta vazia!\n");
        return;
    }

    for (int i = 0; i < total; i++) {
        printf("Item %d:\n", i + 1);
        printf("Nome: %s\n", mochila[i].nome);
        printf("Tipo: %s\n", mochila[i].tipo);
        printf("Quantidade: %d\n\n", mochila[i].quantidade);
    }
}

// Função para remover um item pelo nome
void removerItem(Item mochila[], int *total) {
    char nomeRemover[30];
    int encontrado = 0;

    printf("Digite o nome do item para remover: ");
    scanf("%s", nomeRemover);

    // Procuro o item pelo nome
    for (int i = 0; i < *total; i++) {
        if (strcmp(mochila[i].nome, nomeRemover) == 0) {
            encontrado = 1;

            // Aqui eu "puxo" os elementos para trás para não deixar buraco
            for (int j = i; j < *total - 1; j++) {
                mochila[j] = mochila[j + 1];
            }

            (*total)--;  // Diminuo o total de itens
            printf("Item removido com sucesso!\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Item nao encontrado!\n");
    }
}

int main() {
    Item mochila[MAX];   // Vetor estático com até 10 itens
    int total = 0;       // Quantidade atual de itens inseridos
    int opcao;

    do {
        // Menu principal
        printf("\n=== DESAFIO CODIGO DA ILHA - NIVEL NOVATO ===\n");
        printf("1 - Adicionar item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:
                // Adicionar item
                if (total >= MAX) {
                    printf("Mochila cheia! Nao e possivel adicionar mais itens.\n");
                } else {
                    printf("Nome do item: ");
                    scanf("%s", mochila[total].nome);

                    printf("Tipo do item: ");
                    scanf("%s", mochila[total].tipo);

                    printf("Quantidade: ");
                    scanf("%d", &mochila[total].quantidade);

                    total++; // Aumento o total de itens inseridos
                    printf("Item adicionado com sucesso!\n");
                }
                break;

            case 2:
                removerItem(mochila, &total);
                break;

            case 3:
                listarItens(mochila, total);
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida! Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
