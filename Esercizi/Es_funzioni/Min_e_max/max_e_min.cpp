/* Si definiscano due funzioni min e max che permettano di calcolare 
rispettivamente in minimo e il massimo di due numeri interi. */

int massimo(int x, int y){

    int max = 0;

    if(x>y){
        max = x;
    }
    else{
        max = y;
    }

    return max;
}

int minimo(int x, int y){

    int min = 0;

    if(x<y){
        min = x;
    }
    else{
        min = y;
    }

    return min;
}