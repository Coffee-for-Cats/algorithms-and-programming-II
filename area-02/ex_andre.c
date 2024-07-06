#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dma {
	int dia;
	int mes;
	int ano;
} data;


typedef struct dadosalunos {
	char nome[15];
	float p1,p2,p3,media;
	int matricula;
	data val;
} aluno;


main()
{
	int i;
	float maiorp1,menormedia,maiormedia;
	char nomeMaior[15];
	aluno cadastro[5];
	
	for(i=0;i<5;i++)
	{
		printf("\nDigite o nome : ");
		scanf("%s",&cadastro[i].nome);
		printf("\nDigite as notas (sempre dando ENTER) das prova1 prova 2 e prova3: ");
		scanf("%f %f %f", &cadastro[i].p1, &cadastro[i].p2, &cadastro[i].p3);
		
		/*while (cadastro[i].p1<0 || cadastro[i].p1>10 || cadastro[i].p2<0 || cadastro[i].p2>10 || cadastro[i].p3<0 || cadastro[i].p3>10);
		{
			printf("\nDigite as notas VALIDAS (sempre dando ENTER) das prova1 prova 2 e prova3: ");
			scanf("%f %f %f",&cadastro[i].p1,&cadastro[i].p2,&cadastro[i].p3);
		}
		*/
		cadastro[i].media = (cadastro[i].p1 + cadastro[i].p2 + cadastro[i].p3)/3;
		
	}
			
		for(i=0;i<5;i++)
		{
			if (i == 0 )
			{
			maiorp1 = cadastro[i].p1;
			strcpy(nomeMaior,cadastro[i].nome);		//pegando nome
			maiormedia = cadastro[i].media;
			menormedia = cadastro[i].media;
			
			}
			else
			{
			
				if(maiorp1 < cadastro[i].p1)
				{
					maiorp1 = cadastro[i].p1;	
				}
			
				if(maiormedia < cadastro[i].media)
				{
					maiormedia = cadastro[i].media;
				}
			
				if(menormedia > cadastro[i].media)
				{
					menormedia = cadastro[i].media;
				}
			}
		}
		system("CLS");
		printf("\nMaior nota Prova 1: %.2f %s \n",maiorp1,nomeMaior);
		printf("\nMaior media : %.2f %s \n",maiormedia,cadastro[i].nome);
		printf("\nMenor media : %.2f %s \n",menormedia,cadastro[i].nome);	
		
	
	
}