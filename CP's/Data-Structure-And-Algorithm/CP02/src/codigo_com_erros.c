#include <stdio.h>

/*Foi corrigido a sintaxe inicial, da biblioteca, para que o codigo pudesse ser compilado*/

int main() {
    float nota1, nota2, media;

    /*Foi adicionado ";" após as variaveis, para que elas podessem ser declaradas da forma correta*/

    printf("Digite a primeira nota: ");
    scanf("%f", &nota1);


    printf("Digite a segunda nota: ");
    scanf("%f", &nota2);

/*Foi adicionado o "&", no caso o E comercial, para a leitura correta da variavel novamente, erro fatal*/

    media = (nota1 + nota2) / 2;

/*Foi adicionado parenteses nas variaves "Notas", para que fosse feito a soma da forma correta, para que a formula funcionasse*/

    if (media >= 6) {
        printf("Aluno aprovado\n");
    } else {
        printf("Aluno reprovado\n");
    }

/*Foi corrigido a logica utilizada, incrementando o ">=" no lugar do "=" para que o laço de repetição seja realizado até o numero 6*/

    return 0;
}