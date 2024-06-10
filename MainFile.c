#include <stdio.h>
#include <stdlib.h>

// Swap
void swap(int *a, int *b) {
    int TempNum = *a;
    *a = *b;
    *b = TempNum;
}

// From a to b swap
void reverse(int arr[], int start, int end) {
    while (start < end) {
        swap(&arr[start], &arr[end]);
        start++;
        end--;
    }
}

long long next_bigger_number(long long n) {
    long long TempNum = n;
    int counter = 0;

    while (TempNum != 0) {
        TempNum /= 10;
        counter++;
    }

    int *MainArray = (int *)malloc(counter * sizeof(int));
    if (MainArray == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return -1;
    }

    // Storing in revers order
    TempNum = n;
    counter = 0;
    while (TempNum != 0) {
        MainArray[counter] = TempNum % 10;
        TempNum /= 10;
        counter++;
    }

    int Len = counter;
    reverse(MainArray, 0, Len - 1);

    int i;
    for (i = Len - 2; i >= 0; i--) {
        if (MainArray[i] < MainArray[i + 1]) {
            break;
        }
    }
    if (i == -1) {
        free(MainArray); // Free allocated memory
        return -1;
    }

    // Finnd bigger digit
    int smallest = i + 1;
    for (int j = i + 1; j < Len; j++) {
        if (MainArray[j] > MainArray[i] && MainArray[j] <= MainArray[smallest]) {
            smallest = j;
        }
    }

    swap(&MainArray[i], &MainArray[smallest]);

    reverse(MainArray, i + 1, Len - 1);

    // Arr > number
    long long result = 0;
    for (int k = 0; k < Len; k++) {
        result = result * 10 + MainArray[k];
    }

    free(MainArray); 
    return result;
}

int main() {
    long long number;
    printf("Введите число:");
    if (scanf("%lld", &number) != 1) {
        fprintf(stderr, "ошибка ввода\n");
        return 1;
    }
git rebase origin/main

    long long result = next_bigger_number(number);
    if (result == -1) {
        printf("Невозможно найти число больше\n");
    } else {
        printf("Следующие число:: %lld\n", result);
    }

    return 0;
}