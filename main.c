#include <stdio.h>
#include <stdlib.h>

/*  Construa um programa em C que utiliza uma matriz 10×3 que armazene as 
 temperaturas máxima e minima do dia, assim como a media de temperatura na ultima coluna. 
  Crie um menu de escolha que ofereça as seguintes informações:

1-temperatura minima de todos os dias.
2-temperatura máxima de todos os dias.
3-maior variação de temperatura de todos os dias.
4-Sair do programa. */

int main(int argc, char *argv[]) {
	float temp[10][3]; // coluna 0 - minima coluna 1 = maxima
	float minima, maxima, var, aux;
	int op, x;
	for(x=0;x<10;x++){
		printf("Informe a minima e maxima do dia %d:", (x+1));	
		scanf("%f %f", &temp[x][0], &temp[x][1]);
		temp[x][2] = (temp[x][0] + temp[x][1]) /2;
	}	
	do { //Faça enquanto 1..N
		printf("1-temperatura minima de todos os dias.\n");
		printf("2-temperatura máxima de todos os dias.\n");
		printf("3-maior variação de temperatura de todos os dias.\n");
		printf("4-Sair do programa.\n");
		scanf("%i", &op);
		switch(op){
			case 1:
				for(x=0;x<10;x++){
					if(x==0){
						minima=temp[x][0];	
					} else {
						if(temp[x][0] < minima) minima = temp[x][0];
					}	
				}
				printf("A minima de todos dias=%f \n", minima);
				break;
			case 2:
				for(x=0;x<10;x++){
					if(x==0){
						maxima=temp[x][1];	
					} else {
						if(temp[x][1] > maxima) maxima = temp[x][1];
					}	
				}
				printf("A maxima de todos dias=%f \n", maxima);
				break;
			case 3:
				for(x=0;x<10;x++){
					aux = temp[x][1]-temp[x][0];
					if(x==0){
						var=aux;	
					} else {
						if(aux > var) var = aux;
					}	
				}
				printf("A maior variação de todos dias=%f \n", var);
				break;
			case 4:	
				printf("Tchau !!\n");
				break;
			default:
				printf("operação invalida\n");
		}
	} while(op!=4);	

	return 0;
}
