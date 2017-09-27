#include <stdio.h>
#include <stdlib.h>
#include "../include/reciproco.hpp"

int main(int argc, char **argv){
        int i;

        i = atoi(argv[1]);
        printf("O recíproco de %d é %g\n",i, reciproco(i));
        return 0;
}
