#include <iostream>
#include "SortTestHelper.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
//#include "MySwap.h"

using namespace std;


// 比较InsertionSort和MergeSort两种排序算法的性能效率
// 整体而言, MergeSort的性能最优, 对于近乎有序的数组的特殊情况, 见测试2的详细注释
// 比较Merge Sort和双路快速排序两种排序算法的性能效率
int main() 
{
	int n = 1000000;

	// 测试1 一般性测试
	cout << "Test for random array, size = " << n << ", random range [0, " << n << "]" << endl;
	int* arr1 = SortTestHelper::generateRandomArray(n, 0, n);
	int* arr2 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
	SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);

	delete[] arr1;
	delete[] arr2;

	cout << endl;


	//// 测试2 测试近乎有序的数组
	//// 双路快速排序算法也可以轻松处理近乎有序的数组
	//int swapTimes = 100;
	//cout << "Test for nearly ordered array, size = " << n << ", swap time = " << swapTimes << endl;
	//arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
	//arr2 = SortTestHelper::copyIntArray(arr1, n);

	//SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
	//SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);

	//delete[] arr1;
	//delete[] arr2;

	//cout << endl;


	// 测试3 测试存在包含大量相同元素的数组
	// 使用双快速排序后, 我们的快速排序算法可以轻松的处理包含大量元素的数组
	cout << "Test for random array, size = " << n << ", random range [0,10]" << endl;
	arr1 = SortTestHelper::generateRandomArray(n, 0, 10);
	arr2 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
	SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);

	delete[] arr1;
	delete[] arr2;	system("PAUSE");

	return 0;
}