#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(int arr[], int start, int end) {
    while (start < end) {
        swap(&arr[start], &arr[end]);
        start++;
        end--;
    }
}

long long next_bigger_number(long long n) {
    long long temp = n;
    int counter = 0;
    
    while (temp != 0) {
        temp /= 10;                               //Lenght
        counter++;
    }
    
    int *Array = (int *)malloc(counter * sizeof(int));
    if (Array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return -1;
    }

    temp = n;
    counter = 0;
    
    while (temp != 0) {
        Array[counter] = temp % 10;                 // V array
        temp /= 10;
        counter++;
    }
    
    int Len = counter;
    reverse(Array, 0, Len - 1);
    
    int i;
    for (i = Len - 1; i >= 0; i--) {
        if (Array[i] < Array[i + 1]) {        //i = Main number
            break;
        }
    }
    if (i == -1) {
        return -1;
    }
    
    int smallest = i + 1;
    for (int j = i + 1; j < Len; j++) {
        if (Array[j] > Array[i] && Array[j] <= Array[smallest]) {
            smallest = j;                    // higher then Mainnum
        }
    }
    swap(&Array[i], &Array[smallest]);
    reverse(Array, i + 1, Len - 1);
    
    long long result = 0;
    for (int k = 0; k < Len; k++) {                   //V chislo
        result = result * 10 + Array[k];
    }
    
    return result;
}

int main() {
    long long number = 46321;
    long long result = next_bigger_number(number);
    printf("Следующие число: %lld\n", result);
    return 0;
}