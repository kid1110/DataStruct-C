
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef SORTS_H
#define SORTS_H

typedef int (*Comparator)(const void*, const void*);

void bubble_sort(void* arr, size_t n, size_t size, Comparator cmp);

void insert_sort(void* arr, size_t n, size_t size, Comparator cmp);

void select_sort(void* arr, size_t n, size_t size, Comparator cmp);


void quick_sort(void* arr, int left, int right,size_t size, Comparator cmp);



void swap(void* a, void* b,size_t size);

int partition(void* arr, int left, int right , size_t size, Comparator cmp);


#endif