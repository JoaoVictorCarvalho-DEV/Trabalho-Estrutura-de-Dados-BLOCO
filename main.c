/*
Função Inserir no início, inserior no final e inserir no meio validadas.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define TAM_PLACA 50  // Tamanho máximo da placa
#define TAM_TIPO 50   // Tamanho máximo do tipo de veículo
#define TAM_NOME 50   // Tamanho máximo do nome da pessoa
// Estrutura para armazenar os veículos
struct veiculos{
    char tipo[TAM_TIPO];
    char placa[TAM_PLACA];
    struct veiculos *proximoVeiculo;
};

struct Pessoa {
    char nome[TAM_NOME];
    char cpf[13];
    struct Pessoa *proximo;
};
typedef struct Pessoa pessoa;

struct veiculos *primeiroVeiculo = NULL;

//FUNÇÕES MENU
void menuPrincipal();
void menuVeiculo();
void opcoesMenuVeiculo(int*opcaoVeiculo);
void menuPessoa();
void opcoesMenuPessoa(int *opcaoPessoa);
//FUNÇÕES ADD VEÍCULOS
void adicionarVeiculoInicio();
void adicionarVeiculoMeio();
void adicionarVeiculoFim();

//FUNÇÕES VEÍCULOS
void buscarVeiculo();
int contadorVeiculos();
void editarVeiculos();
void excluirVeiculo();
void imprimirVeiculo(struct veiculos *primeiroVeiculo);

//FUNÇÕES ADD PESSOAS
//FUNÇÕES PESSOAS

int main(){
    setlocale(LC_ALL, "Portuguese");

    int opcao;

    do {
        system("cls");
        menuPrincipal();

        printf("\nDigite a opcao desejada: ");
        scanf("%d", &opcao);
        while (getchar() != '\n'); // limpar o buffer de entrada.

        if (opcao < 0 || opcao > 3) {
            printf("\nA opcao digitada é invalida!");
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
                    int opcaoPessoa;
                    do {
                        opcoesMenuPessoa(&opcaoPessoa);
                    }while (opcaoPessoa != 0);
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
    printf("\n4 - Editar informacoes de um veiculo");
    printf("\n5 - Excluir veiculos");
    printf("\n6 - Exibir veiculos cadastrados");
    printf("\n7 - Busca de veiculos cadastrados");
    printf("\n0 - Sair");
}
void menuPessoa() {
    printf("\n-----------<<< Gerenciamento de Pessoas>>>----------- \n");
    printf("\n1 - Adicionar pessoa");
    printf("\n2 - Retirar pessoa");
    printf("\n3 - Exibir pessoas ");
    printf("\n0 - Sair");
}

void opcoesMenuVeiculo(int *opcaoVeiculo){
    system("cls");
    menuVeiculo();

    printf("\nDigite a opcao desejada: ");
    scanf("%d", opcaoVeiculo);
    while (getchar() != '\n');  // limpar o buffer de entrada.

    if (*opcaoVeiculo < 0 || *opcaoVeiculo > 7) {
        printf("\nA opcao digitada é invalida!");
        printf("\nTente novamente.");
        system("pause");
    } else {
        system("cls");
        switch (*opcaoVeiculo) {
            case 1:
                printf("\n------------------------<<< Adicionar Veiculo no Inicio >>>---------------------- \n");
                adicionarVeiculoInicio();
                system("pause");
                break;
            case 2:
                printf("\n------------------------<<< Adicionar Veiculo no Meio >>>---------------------- \n");
                adicionarVeiculoMeio();
                system("pause");
                break;
            case 3:
                printf("\n------------------------<<< Adicionar Veiculo no Final >>>---------------------- \n");
                adicionarVeiculoFim();
                system("pause");
                break;
            case 4:
                printf("\n------------------------<<< Editar Informacoes do Veiculo >>>---------------------- \n");
                editarVeiculos();
                system("pause");
                break;
            case 5:
                printf("\n------------------------<<< Excluir Veiculo >>>---------------------- \n");
                excluirVeiculo();
                system("pause");
                break;
            case 6:
                printf("\n------------------------<<< Lista de Veiculos Cadastrados >>>---------------------- \n");
                imprimirVeiculo(primeiroVeiculo);
                system("pause");
                break;
            case 7:
                printf("\n------------------------<<< Busca de Veiculos Cadastrados >>>---------------------- \n");
                buscarVeiculo();
                system("pause");
                break;
            }
        }
}

void opcoesMenuPessoa(int *opcaoPessoa) {
    system("cls");
    menuPessoa();

    printf("\nDigite a opcao desejada: ");
    scanf("%d", opcaoPessoa);
    while (getchar() != '\n');  // limpeza de buffer

    if (opcaoPessoa<0 || *opcaoPessoa > 3) {
        printf("\n Opcao invalida!");
        printf("\nTente novamente.");
        system("pause");
    }else{
        system("cls");
        switch (*opcaoPessoa) {
            case 1:
                printf("\n------------------------<<< ADICIONAR PESSOA >>>---------------------- \n");
                printf("FUNCAO NAO CRIADA");
                system("pause");
                break;
            case 2:
                printf("\n------------------------<<< REMOVER PESSOA >>>---------------------- \n");
                printf("FUNCAO NAO CRIADA");
                system("pause");
                break;
            case 3:
                printf("\n------------------------<<< IMPRIMIR PESSOA >>>---------------------- \n");
                printf("FUNCAO NAO CRIADA");
                system("pause");
                break;
        }

    }
}
void adicionarVeiculoInicio() {
    // ponteiro para armazenar as novas informações do veículo

    struct veiculos *novoVeiculo = (struct veiculos *) malloc(sizeof(struct veiculos));
    printf("\nDigite o tipo de veiculo (carro de apoio ou caminhao): ");
    fgets(novoVeiculo->tipo, TAM_TIPO, stdin);
    novoVeiculo->tipo[strcspn(novoVeiculo->tipo, "\n")] = '\0';
    printf("Digite a placa do veiculo: ");
    fgets(novoVeiculo->placa, TAM_PLACA, stdin);
    novoVeiculo->placa[strcspn(novoVeiculo->placa, "\n")] = '\0';

    novoVeiculo->proximoVeiculo = primeiroVeiculo;
    primeiroVeiculo = novoVeiculo;
    printf(" \nO veiculo foi inserido com sucesso. \n");
}

void adicionarVeiculoMeio(){
    if (primeiroVeiculo == NULL || primeiroVeiculo->proximoVeiculo == NULL ){
        printf("É necessario ter, pelo menos, dois veículos para inserir um veiculo no meio! \n");
    } else {
        struct veiculos *novoVeiculo = (struct veiculos *) malloc(sizeof(struct veiculos));
        printf("Digite o tipo de veiculo (carro de apoio ou caminhao): ");
        fgets(novoVeiculo->tipo, TAM_TIPO, stdin);
        novoVeiculo->tipo[strcspn(novoVeiculo->tipo, "\n")] = '\0';
        printf("Digite a placa do veiculo: ");
        fgets(novoVeiculo->placa, TAM_PLACA, stdin);
        novoVeiculo->placa[strcspn(novoVeiculo->placa, "\n")] = '\0';

        printf("\nVoce ja cadastrou os seguintes veiculos:");
        imprimirVeiculo(primeiroVeiculo);

        int totalVeiculos = contadorVeiculos();
        int posicaoVeiculo = 0;
        printf("\nDigite a posicao que voce deseja inserir o veiculo: ");
        scanf("%d", &posicaoVeiculo);
        while (getchar() != '\n');  // Limpar buffer

        if (posicaoVeiculo < 2 || posicaoVeiculo > totalVeiculos) {
            printf("Nao e possivel inserir o veiculo nessa posicao.\n");
        } else {
            int qtdVeiculo = 1;
            struct veiculos *ponteiroVeiculo = primeiroVeiculo;

            while(qtdVeiculo!= totalVeiculos -1 && ponteiroVeiculo->proximoVeiculo !=NULL) {
                ponteiroVeiculo = ponteiroVeiculo->proximoVeiculo;
                qtdVeiculo++;
            }

            struct veiculos *temporario = ponteiroVeiculo->proximoVeiculo;
            ponteiroVeiculo->proximoVeiculo = novoVeiculo;
            novoVeiculo->proximoVeiculo = temporario;
            printf("O veiculo foi inserido com sucesso.\n");
        }
    }
}

void adicionarVeiculoFim(){
    if (primeiroVeiculo == NULL){
        printf("A lista de veículos está  vazia! \n");
        printf("Por favor, insira um veiculo. \n");
    }else{
        struct veiculos *novoVeiculo = (struct veiculos *) malloc(sizeof(struct veiculos));
        printf("\nDigite o tipo de veiculo (carro de apoio ou caminhao): ");
        fgets(novoVeiculo->tipo, TAM_TIPO, stdin);
        novoVeiculo->tipo[strcspn(novoVeiculo->tipo, "\n")] = '\0';
        printf("Digite a placa do veiculo: ");
        fgets(novoVeiculo->placa, TAM_PLACA, stdin);
        novoVeiculo->placa[strcspn(novoVeiculo->placa, "\n")] = '\0';

        novoVeiculo->proximoVeiculo = NULL;

        struct veiculos *ponteiroVeiculo = primeiroVeiculo;
        while(ponteiroVeiculo->proximoVeiculo != NULL){
            ponteiroVeiculo = ponteiroVeiculo->proximoVeiculo;
        };
        ponteiroVeiculo->proximoVeiculo = novoVeiculo;

		printf("\nO veeculo foi inserido com sucesso. \n");
    }
}


void buscarVeiculo(){
    if (primeiroVeiculo == NULL){
        printf("A lista de veiculos está  vazia! \n");
        printf("Por favor, insira um veículo. \n");
    }else{
        int qtdVeiculo = 1;
        char placa_buscada[TAM_PLACA];
        printf("\nDigite a placa do veiculo que você deseja localizar: ");
        fgets(placa_buscada, TAM_PLACA, stdin);
        placa_buscada[strcspn(placa_buscada, "\n")] = '\0';
        struct veiculos *atualVeiculo = primeiroVeiculo;
        while(strcmp(atualVeiculo->placa, placa_buscada) != 0 && atualVeiculo->proximoVeiculo !=NULL) {
            atualVeiculo = atualVeiculo->proximoVeiculo;
            qtdVeiculo++;
        }
        if(strcmp(atualVeiculo->placa, placa_buscada) == 0){
            printf("O veiculo foi localizado: \n");
            printf("\nVeiculo %d \n", qtdVeiculo);
            printf("Tipo de Veiculo: %s\n", atualVeiculo->tipo);
            printf("Placa do Veiculo: %s\n", atualVeiculo->placa);
        }
        else{
            printf("O veiculo não existe! \n");

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
        printf("Por favor, insira um veiculo. \n");
    } else {
        printf("\nVocê ja cadastrou os seguintes veiculos: ");
        imprimirVeiculo(primeiroVeiculo);

        int totalVeiculos = contadorVeiculos();
        int posicaoVeiculo = 0;
        printf("\nDigite a posicao do veiculo que você deseja editar: ");
        scanf("%d", &posicaoVeiculo);
        while (getchar() != '\n');  // Limpar buffer

         if (posicaoVeiculo <=0 || posicaoVeiculo > totalVeiculos) {
            printf("Posicao invalida! Por favor, insira uma posição valida.\n\n");
        } else {
            int qtdVeiculo = 1;
            struct veiculos *ponteiroVeiculo = primeiroVeiculo;

            while(qtdVeiculo!= posicaoVeiculo && ponteiroVeiculo->proximoVeiculo !=NULL) {
                ponteiroVeiculo = ponteiroVeiculo->proximoVeiculo;
                qtdVeiculo++;
            }
            printf("Digite o tipo de veiculo (carro de apoio ou caminhao): ");
            fgets(ponteiroVeiculo->tipo, TAM_TIPO, stdin);
            ponteiroVeiculo->tipo[strcspn(ponteiroVeiculo->tipo, "\n")] = '\0';
            printf("Digite a placa do veiculo: ");
            fgets(ponteiroVeiculo->placa, TAM_TIPO, stdin);
            ponteiroVeiculo->placa[strcspn(ponteiroVeiculo->placa, "\n")] = '\0';

            printf("O veiculo foi editado com sucesso.\n");
        }
    }
}

void excluirVeiculo(){

    if (primeiroVeiculo == NULL){
        printf("A lista está vazia! \n");
        printf("Por favor, insira um veiculo. \n");
        return;
    } else {
        printf("\nVocê ja cadastrou os seguintes veiculos: ");

        imprimirVeiculo(primeiroVeiculo);

        int totalVeiculos = contadorVeiculos();
        int posicaoVeiculo = 0;

        printf("\nDigite a posicao do veiculo que voce deseja excluir: ");
        scanf("%d", &posicaoVeiculo);
        while (getchar() != '\n');  // Limpar buffer

        if (posicaoVeiculo <1 || posicaoVeiculo > totalVeiculos) {
            printf("Posição invalida! Por favor, insira uma posição valida.\n\n");
            return;
        }

        struct veiculos *atualVeiculo = primeiroVeiculo;
        struct veiculos *anteriorVeiculo = NULL;

        if (posicaoVeiculo==1) {
            primeiroVeiculo = atualVeiculo->proximoVeiculo;
            free(atualVeiculo);
            printf("\nVeiculo da posição %d foi excluido com sucesso.\n", posicaoVeiculo);
        } else {
            int contador = 0;
            for (contador = 1; contador < posicaoVeiculo; contador++) {
                anteriorVeiculo = atualVeiculo;
                atualVeiculo= atualVeiculo->proximoVeiculo;
        }
        anteriorVeiculo->proximoVeiculo = atualVeiculo->proximoVeiculo;

        free(atualVeiculo);

        printf("\nVeiculo da posição %d foi excluido com sucesso.\n", posicaoVeiculo);

        }
    }
}

void imprimirVeiculo(struct veiculos *primeiroVeiculo) {

    int qtdVeiculo = 0;
    if (primeiroVeiculo == NULL){
        printf("A lista de veiculos esta  vazia! \n");
        printf("Por favor, insira um veiculo. \n");
    }else{
        struct veiculos *ponteiroVeiculo = primeiroVeiculo;
        while(ponteiroVeiculo != NULL){
            qtdVeiculo++;
            printf("\nVeiculo %d \n", qtdVeiculo);
            printf("Tipo de Veiculo: %s\n", ponteiroVeiculo->tipo);
            printf("Placa do Veiculo: %s\n", ponteiroVeiculo->placa);
            ponteiroVeiculo= ponteiroVeiculo->proximoVeiculo;
        };
        printf("\nTotal de veiculos registrados: %d\n\n", contadorVeiculos());
    }
}



