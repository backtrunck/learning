#include <assert.h>
#include "../include/reciproco.hpp"

double reciproco(int i){
        //Não deve ser 0
        assert(i!=0);
        return 1.0/i;
}
