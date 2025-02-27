#include <stdio.h>

void bubble(int* arr, size_t len) {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len-1-i; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int arr[10] = {1,3,5,7,9,2,4,6,8,10};
    bubble(arr, 10);
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
