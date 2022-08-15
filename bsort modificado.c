#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include "biblioteca.h"

int comp=0;
int t=0;
int f=0;

void bsort(int v[], int n) 
{
	int i,j,flag;
	
	for(i=1; i<n; i++) 
	{
		printf("\n Fase %d\n",i);
		getch();
		printVet(v,n);
		f++; //verificador de fases
		flag=0;	
		for(j=0; j<n-i; j++)
		{
			comp++; //verificador de comparações
			if(v[j]>v[j+1]) 
			{
				flag=1;
				troca(&v[j],&v[j+1]);
				t++; //verificador de trocas	
			}
		}
		if(flag==0) break;
	}
}

int menu()
{
	int op;
	
	printf(" --------- Bem-vinde ao menu ---------");
	printf("\n");
	printf("\n 1 - Digitar os valores do vetor.");
	printf("\n 2 - Gerar o vetor automaticamente.");
	
	printf("\n Insira a opção escolhida: ");
	scanf("%d",&op);
	
	return op;
}

int main() 
{
	setlocale(LC_ALL,"");
	
	int *vet,i,n,op;
	
	printf(" Informe o tamanho do vetor: ");
	scanf("%d",&n);
	printf("\n");
	vet = malloc(sizeof(int)*n);
	
	do
	{
		op = menu();
		switch(op) 
		{
			case 1:
				printf("\n Digite os valores para o vetor: \n");
				
				for(i=0;i<n;i++) 
				{
					printf(" [%d] = ",i);
					scanf("%d",&vet[i]);
				}
			break;
			case 2:
				printf("\n Valores gerados para o vetor:");
				geraVet(vet,n);
			break;
			case 0:
				printf("\n Finalizando programa!\n");
				return 0;
			default:
				printf("\n Opção Inválida!\n");
				return 0;
		}
		printVet(vet,n);
		bsort(vet,n);
		printf("\n Vetor Ordenado:");
		printVet(vet,n);
		printf("\n");
		printf(" Foram necessárias %d fases para a ordenação do vetor!",f);
		printf("\n Foram necessárias %d comparações e %d trocas para a finalização da tarefa.\n",comp,t);
		return 0;
	} while(op=!0);
}
