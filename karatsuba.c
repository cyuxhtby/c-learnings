#include <stdio.h>
#include <math.h>

int getLength(int value);
int karatsuba(int a, int b);

int getLength(int value){
    if(value == 0){
        return 1;
    }
    int length = 0;
    while(value) {
        length++;
        value /= 10;
    }
    return length;
}

int karatsuba(int a, int b){
    // If either number is single digit, directly multiply
    if (a < 10 || b < 10){
        return a*b;
    }
    
    // Get the maximum number of digits between the two numbers
    int m = fmax(getLength(a), getLength(b));

    // Determine the midpoint of length
    int m2 = m/2;

    // Work with base 10 to account for positional value of each digit
    int high1 = a / pow(10, m2);
    int low1 = a % (int) pow(10, m2);
    int high2 = b / pow(10, m2);
    int low2 = b % (int) pow(10, m2);

    // Recursively calculate products
    int p0 = karatsuba(low1, low2);
    int p1 = karatsuba((low1 + high1), (low2 + high2));
    int p2 = karatsuba(high1, high2);

    // Combine the results using base10 shifts
    return (p2 * pow(10, 2 * m2)) + ((p1 - p2 - p0) * pow(10, m2) + p0);
} 

int main(){
    int a,b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    printf("Result %d\n", karatsuba(a,b));
    return 0;
}
