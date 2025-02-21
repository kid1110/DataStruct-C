#include "sorts.h"

void swap(void *a, void *b, size_t size)
{
    void *temp = malloc(size);
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
    free(temp);
}

void bubble_sort(void *arr, size_t n, size_t size, Comparator cmp)
{
    int flag = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            void *first = (char *)arr + j * size;
            void *second = (char *)arr + (j + 1) * size;
            if (cmp(first, second) > 0)
            {
                flag = 1;
                swap(first, second, size);
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}

void insert_sort(void *arr, size_t n, size_t size, Comparator cmp)
{
    for (int i = 1; i < n; i++)
    {
        void *base = (char *)arr + i * size;
        int j = i - 1;
        while (j >= 0 && cmp((char *)arr + j * size, base) > 0)
        {
            void *first = (char *)arr + j * size;
            void *second = (char *)arr + (j + 1) * size;
            swap(first, second, size);
            j--;
        }
        void *first = (char *)arr + j * size;
    }
}

void select_sort(void *arr, size_t n, size_t size, Comparator cmp)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            void *first = (char *)arr + i * size;
            void *second = (char *)arr + j * size;
            if (cmp(first, second) > 0)
            {
                swap(first, second, size);
            }
        }
    }
}

void quick_sort(void *arr, int left, int right, size_t size, Comparator cmp)
{
    if (left <= right)
    {
        return;
    }
    int pivot = partition(arr, left, right, size, cmp);
    quick_sort(arr, left, pivot - 1, size, cmp);
    quick_sort(arr, pivot + 1, right, size, cmp);
}

int partition(void *arr, int left, int right, size_t size, Comparator cmp)
{
    int i = left, j = right;
    while (i < j)
    {
        while (i < j && cmp((char *)arr + j * size, (char *)arr + left) >= 0)
        {
            j--;
        }
        while (i < j && cmp((char *)arr + i * size, (char *)arr + left) <= 0)
        {
            i++;
        }
        swap((char *)arr + i * size, (char *)arr + j * size, size);
    }
    swap((char *)arr + left * size, (char *)arr + i * size, size);
    return i;
}
