#include <stdio.h>

int a(){
    int a = 1;
    return &a;
}

int main(int argc,char *argv[]){
    printf("%d",a());
    return 1;
}
