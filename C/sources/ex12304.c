
# include <stdio.h> 

int main(void)
{
	char carac1,carac2;

	printf("\nDigite o primeiro caracter: ");
	
        carac1 = getc();
	//scanf("%c",&carac1);
	printf("\nDigite o segundo caracter: ");
	//scanf("%c",&carac2);
	carac2 = getc();

	printf("\nO codigo ASCII do primeiro caracter é %d", carac1);
	printf("\nO código ASCII do segundo caracter é %d\n", carac2);
	return 0;
}
