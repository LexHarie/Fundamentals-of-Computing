#include <stdio.h>



int findDivisibility(int *x, int *y) {

    if (*x % *y == 0) {

        return *y;

    } else {

        return -1;

    }

}



int main() {

    int x = 24;

    int y;

    int array[x];  

    int count = 0;

    

    for (y = 2; y <= x; y++) {

        int result = findDivisibility(&x, &y);

        if (result != -1) { 

            array[count] = result;

            printf("%d\n", result);

            count++;

        }

    }



    return 0;

}