#include <stdio.h>

int main(){
    int n;
    int arr[255] = {2,3};

    printf("%s", "Enter your number: ");
    scanf("%d", &n);

    for(int i = 1; i <= 2; i++){
        if(n % arr[i] == 0){
            printf("%d", n % arr[i]);
            printf("%s", "Number is not simple");
            break;
        }
        printf("%s", "Number is simple");
    }
    return 0;
}