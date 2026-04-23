#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
/* ----------------------------------------
   CONSTANTES E VARIAVEIS GLOBAIS
   ---------------------------------------- */
#define MAX_NOTAS 10
 
float notas[MAX_NOTAS];
int   qtd_notas    = 0;
float media        = 0.0;
int   notas_inseridas = 0; /* flag: 1 se as notas ja foram inseridas */
 
/* ----------------------------------------
   DECLARACAO DAS FUNCOES
   ---------------------------------------- */
void exibir_menu();
void inserir_notas();
void calcular_media();
void verificar_situacao();
void exibir_resultado();
void calcular_derivada();
void limpar_tela();
void pausar();
 
/* ============================================================
   COMMIT 1 - MEMBRO A
   Estrutura do menu e loop principal (do-while + switch-case)
   ============================================================ */
int main() {
    int opcao;
 
    /* do-while: continua em execucao ate o usuario escolher sair (opcao 6) */
    do {
        limpar_tela();
        exibir_menu();
 
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
 
        /* switch-case: direciona para a funcao correta */
        switch (opcao) {
            case 1:
                inserir_notas();
                break;
            case 2:
                calcular_media();
                break;
            case 3:
                verificar_situacao();
                break;
            case 4:
                exibir_resultado();
                break;
            case 5:
                calcular_derivada();
                break;
            case 6:
                printf("\n  Encerrando o sistema. Ate logo!\n\n");
                break;
            default:
                printf("\n  Opcao invalida! Tente novamente.\n");
                pausar();
        }
 
    } while (opcao != 6); 
 
    return 0;
}
 
/* Exibe o menu principal */
void exibir_menu() {
    printf("==============================\n");
    printf("      SISTEMA EQUIPE XYZ      \n");
    printf("==============================\n");
    printf("  1 - Inserir notas\n");
    printf("  2 - Calcular media\n");
    printf("  3 - Verificar situacao\n");
    printf("  4 - Exibir resultado\n");
    printf("  5 - Calcular derivada\n");
    printf("  6 - Sair\n");
    printf("==============================\n");
}
 
void inserir_notas() {
    int i;
    float nota;
 
    printf("\n--- INSERIR NOTAS ---\n");
    printf("Quantas notas deseja inserir? (1 a %d): ", MAX_NOTAS);
    scanf("%d", &qtd_notas);
 
    /* if-else: valida a quantidade informada */
    if (qtd_notas < 1 || qtd_notas > MAX_NOTAS) {
        printf("  Quantidade invalida! Use entre 1 e %d.\n", MAX_NOTAS);
        qtd_notas = 0;
        pausar();
        return;
    }
 
    i = 0;
    /* while: le cada nota com validacao de intervalo 0-10 */
    while (i < qtd_notas) {
        printf("  Nota %d: ", i + 1);
        scanf("%f", &nota);
 
        /* if-else: verifica se a nota esta no intervalo valido */
        if (nota < 0.0 || nota > 10.0) {
            printf("  Nota invalida! Digite um valor entre 0 e 10.\n");
            /* nao incrementa i, repete a leitura desta nota */
        } else {
            notas[i] = nota;
            i++;
        }
    }
 
    notas_inseridas = 1;
    media = 0.0; /* reseta a media ao inserir novas notas */
    printf("\n  %d nota(s) inserida(s) com sucesso!\n", qtd_notas);
    pausar();
}
     
    void calcular_media() {
    int i;
    float soma = 0.0;
 
    printf("\n--- CALCULAR MEDIA ---\n");
 
    /* if-else: verifica se ha notas inseridas antes de calcular */
    if (notas_inseridas == 0 || qtd_notas == 0) {
        printf("  Nenhuma nota inserida! Use a opcao 1 primeiro.\n");
        pausar();
        return;
    }
 
    /* soma todas as notas */
    i = 0;
    while (i < qtd_notas) {
        soma += notas[i];
        i++;
    }
 
    media = soma / qtd_notas;
    printf("  Media calculada: %.2f\n", media);
    pausar();
}
 


    