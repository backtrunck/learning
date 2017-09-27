#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define elem_matriz(m, i, j) (*((m) + (i) + (j)))
#define CARAC_NV_LINHA '\n'
#define ESPACO_VAZIO ' '



float matriz_1[4][4] = {12.0, 1.0, 3.1, 4.4,
												13.3, 2.1, 7.3, 9.0,
												14.2, 8.8, 7.5, 6.0,
												11.0, 4.8, 9.5, 3.7};

float matriz_2[2][2] = {1.0, 2.0,
												3.0, 4.0};

float matriz_3[2][2] = {2, 1,
												1, 2};

float matriz_4[2][3] = {2, 5, 9,
												3, 6, 8};

float matriz_5[3][2] = {2, 7,
												4, 3,
												5, 2};

float matriz_6[3][3] = {5, 0, 1,
												-2, 3, 4,
												0, 2, -1};
float matriz_7[3][3] = {1, 2, 3,
												2, 1, 0,
												4, 2, 1};


float *get_linha_mtz(char *buffer)
{
	char    **itens;
        char    *item;
        int     tamanho=1;
        char    delim[] = " ";

        if (strlen(buffer) > 0) {
                item = strtok(buffer ,delim);
	        do {
	                if (item!=NULL) {
                                if (tamanho == 1)
                                        itens = (char**) malloc(sizeof(char**));
                                else
                                        realloc(itens,sizeof(char**) * tamanho);

	        	        printf("\nstrtok->%s\n",item);
                        }
                        itens[tamanho-1]=item;
                        printf("itens[%d]='%s'\n",tamanho-1,itens[tamanho-1]);
                        item = strtok(NULL ,delim);
                        tamanho++;
                } while(item != NULL);
                printf("Tamanho de Linhas Matriz = %d\n",sizeof(long ));
        }
        else   
                return NULL;
                
}
void teste_fget_linha_arq(char **buffer)
	{
		//char *buffer;
		char teste;
		int i=0;
		FILE *arq;

		arq = fopen("nome_tito","r");

		while (fget_linha_arq(arq,buffer)!= EOF){

				i++;
				printf("linha->%d buffer %s| tamanho(%i)\n",i,*buffer,strlen(*buffer));
				get_linha_mtz(*buffer);

				//teste = getchar();
				free(*buffer);
		}


	}

/*obtem a proxima linha do arquivo*/

int fget_linha_arq(FILE *arquivo,char **buffer)
{
	int tamanho = 0;
	unsigned char caracter;
	fpos_t posicao_inicial;

	fgetpos(arquivo, &posicao_inicial);

	while(1) {
		caracter = fgetc(arquivo);
                //vai contando os caracteres. No fim tem o tamanho da linha
                tamanho++;

		if (feof(arquivo) || caracter == CARAC_NV_LINHA) {
			/*Pega a posicao atual (fim da linha), vai para a posicao que estava no ínício da função (início da linha)
			lê a linha, */
	
                        fsetpos(arquivo,&posicao_inicial);
                        //aloca memoria para a leitura da linha
			*buffer = malloc((tamanho ) * sizeof(char) );
		
                        fgets(*buffer,tamanho ,arquivo);
			
                        //lê caracter de fim de linha
                        fgetc(arquivo);
			if (feof(arquivo))
				return EOF;
			else
				return tamanho;
		}
	}

}

float **fget_mtz(const char *caminho_arq)
{
	float **vet_mtz;
	char buffer[100];
	FILE *file;

	file = fopen(caminho_arq,"r");

	if (file == NULL){
		printf("Não foi possível abrir arquivo %s", caminho_arq);
		return 1;
	}

	//while (!feof(file)) {

	//}




	//buffer = fgets(file,100);

}

/*Recebe uma matriz ,sua qt de linhas e colunas
  e as linha e colunas a serem excluidas e devolve uma submatriz
  sem a linha e a coluna a ser excluida*/
float *sub_mtz(float *mtz_1,
								int l_1,
								int c_1,
								//linha a ser excluida
								int exc_lin,
								//coluna a ser excluida
								int exc_col)
{
	int i, j, k = -1, l;
	//submatriz
	float *mtz_2 = malloc((l_1 -1) * (c_1-1) * sizeof(float));
	float *mtz_aux = mtz_2;

	if (mtz_2 == NULL) {
		puts("Não foi possível alocar memória");
		return NULL;
	}

	for (i=0; i < l_1 ; i++)
		//Só processa as linhas diferentes da linha a ser excluída
		if (i != (exc_lin - 1)) {
			k++;
			for(j=0; j < c_1; j++)
				//Só processa as colunas diferentes da coluna a ser excluída
				if (j != (exc_col - 1)) {
					*mtz_aux = *(mtz_1 + c_1 * i + j);
					mtz_aux++;
				}
		}
		return mtz_2;
}

float determ_mtz(float * mtz,
													//linhas da matriz
													int l_1,
													//colunas da matriz
													int c_1)
{
    int i, j;
    float elem_1, elem_2;
    float determinante = 0;
    float *sub_matriz;

    //verifica se é matriz quadrada
    if (l_1 != c_1)
			return 0;

		if(l_1 == 2) {
				//Cacula determinate matriz 2x2
				// elemento_a11 * elemento_a22
				elem_1 = *(mtz) * *(mtz + c_1 * 1 + 1);
				// elemento_a12 * elemento_a21
				elem_2 = *(mtz + 1) * *(mtz + c_1);
				//printf("1->%f 2->%f\n",elem_1,elem_2);

				printf("a11=%f, a22=%f c_1=%d\n",*(mtz),*(mtz + c_1 + 1),c_1);
				printf("determinante_2x2 %f - %f = %f \n",elem_1, elem_2, elem_1 - elem_2);
				return  elem_1 - elem_2;
		}
		else{
			for(j=0;j<c_1;j++) {
				//utilizando a primeira linha para calcular o determinante
				//método de laplace

				sub_matriz = sub_mtz(mtz,l_1,c_1,1,j+1);
				//obtem a submatriz
				determinante += *(mtz+j)* pow(-1,j+2)* determ_mtz(sub_matriz,l_1 - 1,c_1 -1);
				printf(" pivo %f determinante %f\n",*(mtz+j),determinante);
				free(sub_matriz);
			}
			return determinante;
		}
}



float *Matriz_Multiplicar(
						//Matriz 1
						float *mtz_1,
						//Qt de linha Matriz 1
						int l_1,
						//Qt de colunas Matriz 1
						int c_1,
						float *mtz_2,
						int l_2,
						int c_2)
{

	float elem_1, elem_2;

	if (c_1 != l_2)
		return(NULL);

	//ponteiro para guardar o resultado(produto)
	float *res = malloc(l_1 * c_2 * sizeof(float));

	int i, j, k = 0, soma_parcial = 0;

	for (i = 0; i < l_1; i++) {

		for (j = 0; j < c_1; j++)
			for (k = 0; k < c_2; k++) {
				elem_1 = *(mtz_1 + i * c_1 + j);
				elem_2 = *(mtz_2 + j * c_2 + k);
				*(res + i * c_2 + k) +=  elem_1 * elem_2;
			}
	}

	return(res);

}

float *somar_mtx(
					float *mtz_1,
					int l_1,
					int c_1,
					float *mtz_2,
					int linhas_2,
					int c_2)
{
	int i, j;
	int elem_1, elem_2;

	if (l_1 != linhas_2 || c_1 != c_2)
		return(NULL);

	float *soma = malloc(l_1 * c_1 * sizeof(float));


	for (i = 0; i < l_1; i++)
		for (j = 0; j < c_1; j++) {
			elem_1 = *(mtz_1 + c_1 * i + j);
			elem_2 = *(mtz_2 + c_1 * i + j);
			*(soma + c_1 * i + j) = elem_1 + elem_2;
		}

	return soma;
}

void imprime_mtx(float *matriz, int max_linhas, int max_colunas)
{
	int i, j;

	for (i = 0; i < max_linhas; i++) {
		for (j = 0; j < max_colunas; j++)	{
			if (j == max_colunas - 1)
				printf("%0.2f", *(matriz + i * max_colunas + j));
			else
				printf("%0.2f\t", *(matriz + i * max_colunas + j));
		}
		printf("\n");
	}

}



int main(void)
{

	char *buffer;

	teste_fget_linha_arq(&buffer);




	//puts("Matriz_7");
	//imprime_mtx(matriz_6, 3, 3);

	//printf("Determinante %f\n",determ_mtz(matriz_7, 3, 3));
	//imprime_mtx(sub_mtz(matriz_6,3,3,1,1), 2, 2);
	return 0;
}
