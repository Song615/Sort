//#pragma once

#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <algorithm>

using namespace std;
//#include "MySwap.h"

// 对arr[l...r]部分进行patition操作
// 返回j，使得arr[l...j-1] < arr[j]且arr[j+1...r] > arr[j]
template <typename T>
int __partition(T arr[], int l, int r) {

	// 随机在arr[l...r]的范围中, 选择一个数值作为标定点pivot
	swap(arr[l], arr[rand() % (r - l + 1) + l]);

	T v = arr[l];
	int j = l;
	for (int i = l + 1; i <= r; i++)
		if (arr[i] < v) {
			j++;
			swap(arr[j], arr[i]);
		}

	swap(arr[l], arr[j]);

	return j;
}

// 对arr[l...r]部分进行快速排序
template<typename T>
void __quickSort(T arr[], int l, int r)
{
	if (l >= r)
		return;

	int p = __partition(arr, l, r);

	__quickSort(arr, l, p - 1);
	__quickSort(arr, p + 1, r);
}

// 快速排序
template<typename T>
void quickSort(T arr[], int n)
{
	srand(time(NULL));
	__quickSort(arr, 0, n - 1);
}

#endif // !QUICKSORT_H
