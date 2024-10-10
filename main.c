/*
Função Inserir no início, inserior no final e inserir no meio validadas.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define TAM_PLACA 50  // Tamanho máximo da placa
#define TAM_TIPO 50   // Tamanho máximo do tipo de veículo

// Estrutura para armazenar os veículos
struct veiculos{
    char tipo[TAM_TIPO];
    char placa[TAM_PLACA];
    struct veiculos *proximoVeiculo;
};

struct veiculos *primeiroVeiculo = NULL;
void menuPrincipal();
void menuVeiculo();
void opcoesMenuVeiculo(int*opcaoVeiculo);
void adicionarVeiculoInicio();
void adicionarVeiculoMeio();
void adicionarVeiculoFim();
int contadorVeiculos();
void editarVeiculos();
void excluirVeiculo();
void imprimirVeiculo(struct veiculos *primeiroVeiculo);

int main(){
    setlocale(LC_ALL, "Portuguese");

    int opcao;

    do {
        system("cls");
        menuPrincipal();

        printf("\nDigite a opção desejada: ");
        scanf("%d", &opcao);
        while (getchar() != '\n'); // limpar o buffer de entrada.

        if (opcao < 0 || opcao > 3) {
            printf("\nA opção digitada é inválida!");
            printf("\nTente novamente.");
            system("pause");
        } else {
            system("cls");
            switch (opcao) {
                case 1: {
                    int opcaoVeiculo;
                    do {
                        opcoesMenuVeiculo(&opcaoVeiculo);
                    } while (opcaoVeiculo != 0);
                    break;
                }
                case 2:
                    printf("função a implementar\n");
                    system("pause");
                    break;
                case 3:
                    imprimirVeiculo(primeiroVeiculo);
                    system("pause");
                    break;
            }
        }
    } while (opcao != 0);

    return 0;
}

void menuPrincipal() {
    printf("\n************************************************************************\n");
    printf("\n************************* BLOCO DO EU SOZINHO **************************\n");
    printf("\n************************************************************************\n");
    printf("\n1 - Veiculos \n");
    printf("2 - Pessoas \n");
    printf("3 - Imprimir \n");
    printf("0 - Sair\n");
}

void menuVeiculo() {
	printf("\n-----------<<< Gerenciamento de Veiculos >>>----------- \n");
    printf("\n1 - Adicionar veiculos no inicio");
    printf("\n2 - Adicionar veiculos no meio");
    printf("\n3 - Adicionar veiculos no final");
    printf("\n4 - Editar informações de um veículo");
    printf("\n5 - Excluir veículos");
    printf("\n6 - Exibir veículos cadastrados");
    printf("\n0 - Sair");
}

void opcoesMenuVeiculo(int *opcaoVeiculo){
    system("cls");
    menuVeiculo();

    printf("\nDigite a opção desejada: ");
    scanf("%d", opcaoVeiculo);
    while (getchar() != '\n');  // limpar o buffer de entrada.

    if (*opcaoVeiculo < 0 || *opcaoVeiculo > 6) {
        printf("\nA opção digitada é inválida!");
        printf("\nTente novamente.");
        system("pause");
    } else {
        system("cls");
        switch (*opcaoVeiculo) {
            case 1:
                printf("\n------------------------<<< Adicionar Veículo no Início >>>---------------------- \n");
                adicionarVeiculoInicio();
                system("pause");
                break;
            case 2:
                printf("\n------------------------<<< Adicionar Veículo no Meio >>>---------------------- \n");
                adicionarVeiculoMeio();
                system("pause");
                break;
            case 3:
                printf("\n------------------------<<< Adicionar Veículo no Final >>>---------------------- \n");
                adicionarVeiculoFim();
                system("pause");
                break;
            case 4:
                printf("\n------------------------<<< Editar Informações do Veículo >>>---------------------- \n");
                editarVeiculos();
                system("pause");
                break;
            case 5:
                printf("\n------------------------<<< Excluir Veículo >>>---------------------- \n");
                excluirVeiculo();
                system("pause");
                break;
            case 6:
                printf("\n------------------------<<< Lista de Veículos Cadastrados >>>---------------------- \n");
                imprimirVeiculo(primeiroVeiculo);
                system("pause");
                break;
            }
        }
}



void adicionarVeiculoInicio() {
    // ponteiro para armazenar as novas ionformaçõpes do veículo

    struct veiculos *novoVeiculo = (struct veiculos *) malloc(sizeof(struct veiculos));
    printf("\nDigite o tipo de veículo (carro de apoio ou caminhão): ");
    fgets(novoVeiculo->tipo, TAM_TIPO, stdin);
    novoVeiculo->tipo[strcspn(novoVeiculo->tipo, "\n")] = '\0';
    printf("Digite a placa do veículo: ");
    fgets(novoVeiculo->placa, TAM_PLACA, stdin);
    novoVeiculo->placa[strcspn(novoVeiculo->placa, "\n")] = '\0';

    novoVeiculo->proximoVeiculo = primeiroVeiculo;
    primeiroVeiculo = novoVeiculo;
    printf(" \nO veículo foi inserido com sucesso. \n");
}

void imprimirVeiculo(struct veiculos *primeiroVeiculo) {

    int qtdVeiculo = 0;
    if (primeiroVeiculo == NULL){
        printf("A lista de veículos está  vazia! \n");
        printf("Por favor, insira um veículo. \n");
    }else{
        struct veiculos *ponteiroVeiculo = primeiroVeiculo;
        while(ponteiroVeiculo != NULL){
            qtdVeiculo++;
            printf("\nVeículo %d \n", qtdVeiculo);
            printf("Tipo de Veículo: %s\n", ponteiroVeiculo->tipo);
            printf("Placa do Veículo: %s\n", ponteiroVeiculo->placa);
            ponteiroVeiculo= ponteiroVeiculo->proximoVeiculo;
        };
		printf("\nTotal de veículos registrados: %d\n\n", contadorVeiculos());
    }
}

void adicionarVeiculoFim(){

    if (primeiroVeiculo == NULL){
        printf("A lista de veículos está  vazia! \n");
        printf("Por favor, insira um veículo. \n");
    }else{
        struct veiculos *novoVeiculo = (struct veiculos *) malloc(sizeof(struct veiculos));
        printf("\nDigite o tipo de veículo (carro de apoio ou caminhão): ");
        fgets(novoVeiculo->tipo, TAM_TIPO, stdin);
        novoVeiculo->tipo[strcspn(novoVeiculo->tipo, "\n")] = '\0';
        printf("Digite a placa do veículo: ");
        fgets(novoVeiculo->placa, TAM_PLACA, stdin);
        novoVeiculo->placa[strcspn(novoVeiculo->placa, "\n")] = '\0';

        novoVeiculo->proximoVeiculo = NULL;

        struct veiculos *ponteiroVeiculo = primeiroVeiculo;
        while(ponteiroVeiculo->proximoVeiculo != NULL){
            ponteiroVeiculo = ponteiroVeiculo->proximoVeiculo;
        };
        ponteiroVeiculo->proximoVeiculo = novoVeiculo;

		printf("\nO veículo foi inserido com sucesso. \n");
    }
}
void adicionarVeiculoMeio(){
    if (primeiroVeiculo == NULL || primeiroVeiculo->proximoVeiculo == NULL ){
        printf("É necessário ter, pelo menos, dois veículos para inserir um veículo no meio! \n");
    } else {
        struct veiculos *novoVeiculo = (struct veiculos *) malloc(sizeof(struct veiculos));
        printf("Digite o tipo de veículo (carro de apoio ou caminhão): ");
        fgets(novoVeiculo->tipo, TAM_TIPO, stdin);
        novoVeiculo->tipo[strcspn(novoVeiculo->tipo, "\n")] = '\0';
        printf("Digite a placa do veículo: ");
        fgets(novoVeiculo->placa, TAM_PLACA, stdin);
        novoVeiculo->placa[strcspn(novoVeiculo->placa, "\n")] = '\0';

        printf("\nVocê já cadastrou os seguintes veículos:");
        imprimirVeiculo(primeiroVeiculo);

        int totalVeiculos = contadorVeiculos();
        int posicaoDesejada = 0;
        printf("\nDigite a posição que você deseja inserir o veículo: ");
        scanf("%d", &posicaoDesejada);
        while (getchar() != '\n');  // Limpar buffer

        if (posicaoDesejada < 3 || posicaoDesejada >= totalVeiculos) {
            printf("Não é possível inserir o veículo nessa posição.\n");
        } else {
            int posicaoVeiculo = 1;
            struct veiculos *ponteiroVeiculo = primeiroVeiculo;

            while(posicaoDesejada!=posicaoVeiculo) {//posicaoVeiculo!= totalVeiculos -1 && ponteiroVeiculo->proximoVeiculo !=NULL
                ponteiroVeiculo = ponteiroVeiculo->proximoVeiculo;
                posicaoVeiculo++;
            }

            struct veiculos *temporario = ponteiroVeiculo->proximoVeiculo;
            ponteiroVeiculo->proximoVeiculo = novoVeiculo;
            novoVeiculo->proximoVeiculo = temporario;
            printf("O veículo foi inserido com sucesso.\n");
        }
    }
}

int contadorVeiculos(){
    int cont = 0;
    struct veiculos *ponteiroVeiculo = primeiroVeiculo;
    while(ponteiroVeiculo != NULL){
        cont++;
        ponteiroVeiculo= ponteiroVeiculo->proximoVeiculo;
    }
    return cont;
}

void editarVeiculos(){
    if (primeiroVeiculo == NULL){
        printf("A lista está vazia! \n");
        printf("Por favor, insira um veículo. \n");
    } else {
        printf("\nVocê já cadastrou os seguintes veículos: ");
        imprimirVeiculo(primeiroVeiculo);

        int totalVeiculos = contadorVeiculos();
        int posicaoVeiculo = 0;
        printf("\nDigite a posição do veículo que você deseja editar: ");
        scanf("%d", &posicaoVeiculo);
        while (getchar() != '\n');  // Limpar buffer

         if (posicaoVeiculo <=0 || posicaoVeiculo > totalVeiculos) {
            printf("Posição inválida! Por favor, insira uma posição válida.\n\n");
        } else {
            int qtdVeiculo = 1;
            struct veiculos *ponteiroVeiculo = primeiroVeiculo;

            while(qtdVeiculo!= posicaoVeiculo && ponteiroVeiculo->proximoVeiculo !=NULL) {
                ponteiroVeiculo = ponteiroVeiculo->proximoVeiculo;
                qtdVeiculo++;
            }
            printf("Digite o tipo de veículo (carro de apoio ou caminhão): ");
            fgets(ponteiroVeiculo->tipo, TAM_TIPO, stdin);
            ponteiroVeiculo->tipo[strcspn(ponteiroVeiculo->tipo, "\n")] = '\0';
            printf("Digite a placa do veículo: ");
            fgets(ponteiroVeiculo->placa, TAM_TIPO, stdin);
            ponteiroVeiculo->placa[strcspn(ponteiroVeiculo->placa, "\n")] = '\0';

            printf("O veículo foi editado com sucesso.\n");
        }
    }
}
void excluirVeiculo(){

    if (primeiroVeiculo == NULL){
        printf("A lista está vazia! \n");
        printf("Por favor, insira um veículo. \n");
        return;
    } else {
        printf("\nVocê já cadastrou os seguintes veículos: ");

        imprimirVeiculo(primeiroVeiculo);

        int totalVeiculos = contadorVeiculos();
        int posicaoVeiculo = 0;

        printf("\nDigite a posição do veículo que você deseja excluir: ");
        scanf("%d", &posicaoVeiculo);
        while (getchar() != '\n');  // Limpar buffer

        if (posicaoVeiculo <1 || posicaoVeiculo > totalVeiculos) {
            printf("Posição inválida! Por favor, insira uma posição válida.\n\n");
            return;
        }

        struct veiculos *atualVeiculo = primeiroVeiculo;
        struct veiculos *anteriorVeiculo = NULL;

        if (posicaoVeiculo==1) {
            primeiroVeiculo = atualVeiculo->proximoVeiculo;
            free(atualVeiculo);
            printf("\nVeículo da posição %d foi excluído com sucesso.\n", posicaoVeiculo);
        } else {
            int contador = 0;
            for (contador = 1; contador < posicaoVeiculo; contador++) {
                anteriorVeiculo = atualVeiculo;
                atualVeiculo= atualVeiculo->proximoVeiculo;
        }
        anteriorVeiculo->proximoVeiculo = atualVeiculo->proximoVeiculo;

        free(atualVeiculo);

        printf("\nVeículo da posição %d foi excluído com sucesso.\n", posicaoVeiculo);

        }
    }
}


