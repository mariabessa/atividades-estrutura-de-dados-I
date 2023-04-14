#include "r9.h"

int soma_r9(int n){
    if (n >= 9){
        return n%10 + soma_r9(n);
    }else
        return n;
}