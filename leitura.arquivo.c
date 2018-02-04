#include <stdio.h>
struct item_agenda
{
	char nome[50];
	char endereco[200];
	char telefone[10];
};

int ler_proximo_campo(char* buffer,char* campo,int pos_atual)
{
	int pos_anterior,i=0;

	pos_anterior = pos_atual;
	
	while(buffer[pos_atual] != '\0' && buffer[pos_atual] != '\t')
	{
		campo[i] = buffer[pos_atual];
		i++;
		pos_atual++;
	}

	campo[i] = '\0';

	if(buffer[pos_atual] == '\t')
		return pos_atual + 1;
	else
		return pos_atual = -1;
	
}

int ler_proxima_linha(FILE* arquivo,char* buffer)
{
	int i=0;
	char caracter;

	caracter = fgetc(arquivo);

	while( caracter != '\n' && caracter != EOF)
	{
		buffer[i] = caracter;
		caracter = (char) fgetc(arquivo);
		i++;
	}
	
	buffer[i]='\0';
	
	if (caracter  == '\n')
		return 0;
	else
		return 1;
}

int main()
{
        char nome[50];
        char endereco[100];
        char telefone [10];
	    char campo[100];
        char opcao;
        char buffer[200];
        FILE* fAgenda;
	    struct item_agenda item;
	    int i=0,posicao=0;
        
        fAgenda = fopen("agenda_telefonica.txt","r");
	    i = ler_proxima_linha(fAgenda,buffer);

		

	    printf("\n\n******* Agenda Telefonica *******\n");
        while (i==0)
	    {

		    posicao = ler_proximo_campo(buffer,item.nome,posicao);
		    posicao = ler_proximo_campo(buffer,item.endereco,posicao);
		    posicao = ler_proximo_campo(buffer,item.telefone,posicao);

		    printf("Nome: %s\nEndereco: %s\nTelefone:%s\n",item.nome,item.endereco,item.telefone);
		    printf("*********************************\n");

		    i = ler_proxima_linha(fAgenda,buffer);
		    posicao = 0;
	    }

	return 0;
}

