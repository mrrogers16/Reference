#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
//O(n^2)
void sort(int arr[], int size)
{
    for (int j = 0; j < size - 1; j++)
    {
        for (int i = 0; i < size - j - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}
int main()
{

    int array[] = {10, 2, 2, 4, 3, 8, 6, 45, 8, 1000, 5};
    int size = sizeof(array) / sizeof(array[0]);
    sort(array, size);
    printArray(array, size);

    return 0;
}