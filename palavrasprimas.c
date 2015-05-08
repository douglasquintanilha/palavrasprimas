/* 
	Programa de Palavras Primas 
	Primeira Fase do Processo Seletivo da Caelum
	Autor: Douglas Quintanilha Barbosa Ferreira 
*/

#include <stdio.h>
#include <strings.h>
#include <math.h>

/* 
	Como a palavra de entrada pode ter no máximo 20 caracteres, e o caractere com valor 
	mais alto é o 'Z' (52) , o maior valor possivél é de 20 * 52 = 1040  
*/
#define SOMA_MAXIMA 1040
#define NUMERO_DE_LETRAS 53   

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


/*
	Calcula todos os primos até um determinado N utilizando o Crivo de Erastóstenes
	e marca em um array com 1 quais são estes primos.
*/
void preenche_array_primos(int* primos){
	int i;
	int j;

	for (i = 0; i < SOMA_MAXIMA ; i++)
	{
		primos[i] = 1;
	}
	primos[1] = 1;
    
    for (i = 2; i <= sqrt(SOMA_MAXIMA); ++i){
        if (primos[i]){
            for (j = i * i; j <= SOMA_MAXIMA; j += i)
                primos[j] = 0;
        }
    }

}

int main (){

	char letras[NUMERO_DE_LETRAS];
	char palavra[21];
	char * caractere;
	int soma = 0;
	int i;
	int primos[SOMA_MAXIMA];
	
	preenche_array_letras(letras);
	preenche_array_primos(primos);


	while ( scanf("%s",palavra) == 1 ){
		soma = 0;
		for (i = 0; palavra[i] != '\0' ; ++i)
		{
			caractere = strchr(letras,palavra[i]);
			soma += (int) (caractere - letras);
		}

		if(primos[soma] == 1){
			printf("It is a prime word.\n");
		}else{
			printf("It is not a prime word.\n");
		}	
	}

	return 0;
}