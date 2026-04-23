#include <stdio.h>
#include <stdlib.h>
 
#define MAX_NOTAS 10
 
float notas[MAX_NOTAS];
int   qtd_notas       = 0;
float media           = 0.0;
int   notas_inseridas = 0;
 
void exibir_menu();
void inserir_notas();
void calcular_media();
void verificar_situacao();
void exibir_resultado();
void calcular_derivada();
void limpar_tela();
void pausar();
 
int main() {
    int opcao;
 
    do {
        limpar_tela();
        exibir_menu();
 
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
 
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
 
void exibir_menu() {
    printf("==============================\n");
    printf("      SISTEMA EQUIPE XYZ      \n");
    printf("==============================\n");
    printf("  1 - Inserir notas\n");
    printf("  2 - Calcular media\n");
    printf("  3 - Verificar situacao\n");
    printf("  4 - Exibir resultado\n");
    printf("  5 - Calcular Derivada Geral\n");
    printf("  6 - Sair\n");
    printf("==============================\n");
}
 
void inserir_notas() {
    int i;
    float nota;
 
    printf("\n--- INSERIR NOTAS ---\n");
    printf("Quantas notas deseja inserir? (1 a %d): ", MAX_NOTAS);
    scanf("%d", &qtd_notas);
 
    if (qtd_notas < 1 || qtd_notas > MAX_NOTAS) {
        printf("  Quantidade invalida! Use entre 1 e %d.\n", MAX_NOTAS);
        qtd_notas = 0;
        pausar();
        return;
    }
 
    i = 0;
    while (i < qtd_notas) {
        printf("  Nota %d: ", i + 1);
        scanf("%f", &nota);
 
        if (nota < 0.0 || nota > 10.0) {
            printf("  Nota invalida! Digite um valor entre 0 e 10.\n");
        } else {
            notas[i] = nota;
            i++;
        }
    }
 
    notas_inseridas = 1;
    media = 0.0;
    printf("\n  %d nota(s) inserida(s) com sucesso!\n", qtd_notas);
    pausar();
}
 
void calcular_media() {
    int i;
    float soma = 0.0;
 
    printf("\n--- CALCULAR MEDIA ---\n");
 
    if (notas_inseridas == 0 || qtd_notas == 0) {
        printf("  Nenhuma nota inserida! Use a opcao 1 primeiro.\n");
        pausar();
        return;
    }
 
    i = 0;
    while (i < qtd_notas) {
        soma += notas[i];
        i++;
    }
 
    media = soma / qtd_notas;
    printf("  Media calculada: %.2f\n", media);
    pausar();
}
 
void verificar_situacao() {
    printf("\n--- VERIFICAR SITUACAO ---\n");
 
    if (notas_inseridas == 0) {
        printf("  Insira as notas primeiro (opcao 1).\n");
        pausar();
        return;
    }
 
    if (media == 0.0 && qtd_notas > 0) {
        printf("  Calcule a media primeiro (opcao 2).\n");
        pausar();
        return;
    }
 
    printf("  Media atual: %.2f\n\n", media);
 
    if (media >= 7.0) {
        printf("  Situacao: APROVADO\n");
        printf("  Parabens! Voce atingiu a media necessaria.\n");
    } else if (media >= 5.0) {
        printf("  Situacao: RECUPERACAO\n");
        printf("  Voce esta em recuperacao. Media minima: 7.0\n");
    } else {
        printf("  Situacao: REPROVADO\n");
        printf("  Infelizmente voce foi reprovado. Media minima: 5.0\n");
    }
 
    pausar();
}
 
void exibir_resultado() {
    int i;
    float maior, menor;
 
    printf("\n--- EXIBIR RESULTADO ---\n");
 
    if (notas_inseridas == 0) {
        printf("  Insira as notas primeiro (opcao 1).\n");
        pausar();
        return;
    }
 
    printf("  Notas inseridas:\n");
    printf("  +---------+--------+\n");
    printf("  | Prova   | Nota   |\n");
    printf("  +---------+--------+\n");
 
    maior = notas[0];
    menor = notas[0];
 
    i = 0;
    while (i < qtd_notas) {
        printf("  | P%-6d | %6.2f |\n", i + 1, notas[i]);
 
        if (notas[i] > maior) maior = notas[i];
        if (notas[i] < menor) menor = notas[i];
        i++;
    }
 
    printf("  +---------+--------+\n");
 
    if (media > 0.0 || qtd_notas > 0) {
        printf("\n  Media   : %.2f\n", media);
        printf("  Maior   : %.2f\n", maior);
        printf("  Menor   : %.2f\n", menor);
 
        if (media >= 7.0) {
            printf("  Situacao: APROVADO\n");
        } else if (media >= 5.0) {
            printf("  Situacao: RECUPERACAO\n");
        } else {
            printf("  Situacao: REPROVADO\n");
        }
    } else {
        printf("\n  (Calcule a media pela opcao 2 para ver o resultado completo)\n");
    }
 
    pausar();
}
 
void calcular_derivada_geral() {

    float coeficiente, expoente;
    float novoCoeficiente, novoExpoente;

    printf("\n--- CALCULO DE DERIVADA GERAL (ax^n) ---\n");
    printf("Digite o coeficiente (a): ");
    scanf("%f", &coeficiente);
    
    printf("Digite o expoente (n): ");
    scanf("%f", &expoente);

    // Regra da Potencia Geral: f'(x) = (a * n) * x^(n - 1)
    novoCoeficiente = coeficiente * expoente;
    novoExpoente = expoente - 1;

    printf("\n----------------------------------------\n");
    printf("Funcao original: f(x) = %.2fx^%.2f\n", coeficiente, expoente);
   
   
    // Tratamento logico para exibicao
    if (novoExpoente == 0) {
        printf("Derivada: f'(x) = %.2f\n", novoCoeficiente);
    } else if (novoExpoente == 1) {
        printf("Derivada: f'(x) = %.2fx\n", novoCoeficiente);
    } else {
        printf("Derivada: f'(x) = %.2fx^%.2f\n", novoCoeficiente, novoExpoente);
    }
    printf("----------------------------------------\n");
}
 
void limpar_tela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
 
void pausar() {
    printf("\n  Pressione Enter para continuar...");
    while (getchar() != '\n');
    getchar();
}
