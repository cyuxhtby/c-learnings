#include <stdio.h>

int getLength(int value);
int karatsuba(int a, int b);

int main(){
    int a,b;
    printf("Enter two numbers");
    scanf("%d, %d", &a, &b);
    printf("Result %d\n", karatsuba(a,b));
    return 0;
}

int getLength(int value){
    if(value == 0){
        return 1;
    }
    int length = 0;
    while(value) {
        length++;
        value /= 10;
    }
}

int karatsuba(a, b){
    // If either number is single-digit, directly multiply
    if (a < 10 || b < 10){
        return a*b;
    }
    // TO DO
} 
