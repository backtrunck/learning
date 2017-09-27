#include <stdio.h>

int main(int argc, char* argv[]){
        printf("O nome deste programa é '%s'\n", argv[0]);
        printf("O programa foi chamado com %d argumentos.\n",argc-1);

        if (argc > 1){
                int i;
                printf("Os argumentos são:\n");
                for (i = 1;i < argc; ++i)
                        printf("%s ", argv[i]);
                printf("\n");
        }

        return 0;
}

