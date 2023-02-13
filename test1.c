#include <stdio.h>

int my_func(int n){
    int result=1;
    for (int i=1; i<=n; i++){
        result *= i;
    }
    return result;
}

int main(){

    int f = my_func(10);
    printf("%d", f);
    return 0;

}
