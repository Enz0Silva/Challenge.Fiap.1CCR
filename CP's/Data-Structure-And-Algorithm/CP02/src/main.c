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
 
