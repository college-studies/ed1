#include <stdio.h>

int main(){
    int i=2;

    switch (i)
    {
        case 1:
            printf("Case1 ");
            break;
        case 2:
            printf("Case2 \n");
            break;
        default:
            printf("Default ");
    }
    return 0;
}