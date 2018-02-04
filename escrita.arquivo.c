#include <stdio.h>

int main()
{
        char nome[50];
        char endereco[100];
        char telefone [10];
        char opcao;
        
        FILE* fAgenda;

        fAgenda = fopen("agenda_telefonica.txt","w");
        
        do
        {
                printf("Digite o nome: ");
                scanf("%s",nome);
                
                printf("Digite o endereco: ");  
                scanf("%s",endereco);
                
                printf("Digite o telefone: ");
                scanf("%s",telefone);
                getchar();//Pega a quebra de linha
                
                fprintf(fAgenda,"%s\t%s\t%s\n",nome,endereco,telefone); //Grava na Agenda
                
                printf("Continuar? (S/N)\n"); //Incluir mais nomes na agenda?
                scanf("%c",&opcao);
                
                getchar();//Pega a quebra de linha

        }while(opcao != 'n' && opcao != 'N');

        fclose(fAgenda);

        return 0;

}

