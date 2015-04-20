//
//  main.c
//  musicManager
//
//  Created by Marcos Vinicius Vieira on 19/04/15.


#include <stdio.h>
#include <string.h>
#include <locale.h>

typedef struct
{
    char musicName[31];
    char artistName[31];
    char musicGenre[31];
    int rankingPosition;
}musica;

int main() {
    setlocale(LC_ALL, "Portuguese");
    
    system("title PROGRAMA RANKING DAS MUSICAS");
    system("color f0");
    
    musica position [5];
    char options=0;
    int position2 = 1;
    int i;
    
    printf("############# RAKING DAS MUSICAS #############\n");
    
    for (i=0; i<5; i++) {
        setbuf(stdin, NULL);
        printf("Digite o nome da Musica: \n");
        scanf("%[^\n]s", position[i].musicName );
        setbuf(stdin, NULL);
        printf("Digite o nome do artista/banda: \n");
        scanf("%[^\n]s",position[i].artistName);
        setbuf(stdin, NULL);
        printf("Digite o genero da musica: \n");
        scanf("%[^\n]s",position[i].musicGenre);
        setbuf(stdin, NULL);
        while (position[i].rankingPosition<1 || position[i].rankingPosition>5) {
            setbuf(stdin, NULL);
            printf("Digite a posição desta musica entre 1 e 5: \n");
            scanf("%i", &position[i].rankingPosition);
            setbuf(stdin, NULL);
            if (position[i].rankingPosition<1 || position[i].rankingPosition>5) {
                printf("POSIÇÃO INVALIDA! VAMOS TENTAR NOVAMENTE:\n");
                setbuf(stdin, NULL);
            }
        }
        printf("\n");
    }
    
    printf("\n**********************************\n");
    printf("MUITO BEM, VERIFIQUE AS OPÇÕES ABAIXO: \n\n");
    printf("Digite C para informar uma posição no ranking e consultar as informações da musica nesta posição.\n");
    printf("Digite L para listar as muÌsicas do ranking.\n");
    printf("Digite S para sair.\n\n");
    fflush(stdin);
    
    while (options!='S'){
    printf("\nDIGITE A OPÇÃO DESEJADA(LETRA MAIUSCULA): \n");
    scanf("%[^\n]s",&options);
    setbuf(stdin, NULL);
        
        if (options=='C') {
            setbuf(stdin, NULL);
            printf("OK, AGORA DIGITE A POSIÇÃO DESEJADA: \n");
            scanf("%i", &position2);
            setbuf(stdin, NULL);
            printf("INFORMAÇÕES SOBRE A %iª POSIÇÃO: \n", position2);
            position2=position2-1;
            printf("NOME DA MUSICA:%s \n", position[position2].musicName);
            printf("BANDA/ARTISTA DA MUSICA:%s \n", position[position2].artistName);
            printf("GENERO DA MUSICA:%s \n", position[position2].musicGenre);
        }
        
        if (options=='L') {
            printf("\n\nCERTO, SEGUE ABAIXO A RELAÇÃO DA POSIÇÃO DA MUSICA, NOME & ARTISTA:\n");
            for (i=0; i<5; i++) {
                setbuf(stdin, NULL);
                printf("%i - %s, %s.\n", position[i].rankingPosition, position[i].musicName, position[i].artistName);
            }
            printf("\n");
        }
        
        if (options=='S') {
            printf("VOCÊS SAIU DO PROGRAMA, ATÉ BREVE!!!\n\n");
        }
    }
    system("PAUSE");
    return 0;
}
