#include <stdio.h>
#include <strings.h>
#include <math.h>
#include <time.h>
#define NUMERO_DE_LETRAS 53
/*
	Gera palavras 100 de comprimento entre 1 e 20 aleatóriamente, para serem testadas no programa de palavrasprimas.
	Pode-se passar um argumento para escolher o número de palavras geradas.
*/		   


void preenche_array_letras(char *letras){
	int i = 0;
	int j = 0;

	letras[0] = '.';
	for (i = 1; i <27  ; i++,j++)
	{
		letras[i] = 'a'+ j;
	}
	for (i = 27, j = 0; i < NUMERO_DE_LETRAS ; i++ ,j++)
	{
		letras[i] = 'A'+ j;	
	}
}

int main( int argc, char * argv [] ) {

	char letras[NUMERO_DE_LETRAS];

	long palavrasGeradas;
	int i,j;
	int random;
	int tamanhoRandom; 
	preenche_array_letras(letras);
	srand(time(NULL));

	if(argc == 1){
		for (i = 0; i < 100; ++i)
		{
			tamanhoRandom = (rand()%20) +1;
			for (j= 0; j < tamanhoRandom; ++j)
			{
				random = (rand()% 52) +1;
				printf("%c",letras[random]);
			}
			printf("\n");

		}
	}	
	else{
		palavrasGeradas = strtol(argv[1], NULL, 0);
		for (i = 0; i < palavrasGeradas; ++i)
		{
			tamanhoRandom = (rand()%20) +1;
			for (j= 0; j < tamanhoRandom; ++j)
			{
				random = (rand()% 52) +1;
				printf("%c",letras[random]);
			}
			printf("\n");

		}
	}	
	

}
