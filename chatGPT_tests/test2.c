#include <stdio.h>

int my_f(int some_number){
    int result=some_number;
    while (some_number>1){
        result *= (some_number-1);
        some_number = some_number-1;
    }
    return result;
}

int main(){

    int f = my_f(10);
    printf("%d", f);
    return 0;

}
