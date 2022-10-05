#include <stdio.h>

#define ROWS 5
#define COLS 5


int result[64];
int result2[64];
int rep = 0;

void binary(int n) {
    if (n > 0) {
        result[rep] = n % 2;
        rep++;
        binary(n / 2);
    } 
}

void sortBinary() {
    for (size_t i = 0; i < rep; i++)
    {
        result2[rep-(i+1)] = result[i];
    }
    
}

int power(int n, int p) {
    if(p == 0) {
        return 1;
    }
    else {
        return n * power(n, p-1);
    }
}

int powerSpecial(int n, int p) {
    if(!(p % 2)) {
        printf("2|");
        int temp = n * n;
        return power(temp, p / 2);
    }
    else {
        printf("1|");
        return n * power(n, p-1);
    }
}

int KingRouts(int x, int y, int** av) {
    if(get2ndInt(av, y, x) == 1) return 0;
    if(x == 0 && y == 0) return 0;
    return kingRoutes(x, y-1, av) + KingRoutes(x - 1, y, av);
}

int main(const int argv, const char** argc) {
    
    int size = 0;
    binary(21);
    size = rep;
    sortBinary();
    for (size_t i = 0; i < size; ++i)
    {
        printf("%d ", result2[i]);
    }
    size = 0;
    printf("\n");

    printf("%d\n", power(5, 8));
    printf("%d", powerSpecial(5, 8));

    
    return 0;
}