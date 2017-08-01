//Binary-Search 
#include <iostream>

using namespace std;

/*
*二分查找思想：1、数组从小到大排序；2、查找的key每次和中间数比较，如果key小于mid
查找mid左侧的数组部分；如果key大于mid，则查找mid右侧的数组部分；如果相等，则直接返回mid。

输入：排序数组-array,数组大小-aSize,查找值-key
返回：返回数组中的相应位置，否则返回-1
*/
//非递归查找
int BinarySearch(int array[], int aSize, int key)
{//int array[] = { 1,2,3,4,5,6,7,8,9,10 };
	if (array == NULL || aSize <= 0)
		return -1;
	int left = 0, right = aSize - 1;
	int mid;
	while (left < right) {
		mid = (left + right) / 2;
		if (array[mid] == key)
			return mid;
		else if (array[mid] > key)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return -1;
}
//递归
int BinarySearchRecursive(int array[], int low, int high, int key)
{//int array[] = { 1,2,3,4,5,6,7,8,9,10 };
	if (array == NULL)
		return -1;
	int left = low, right = high;
	int mid = (left + right) / 2;
	if (array[mid] == key)
		return mid;
	else if (array[mid] > key)
		return BinarySearchRecursive(array, low, mid - 1, key);
	else
		return BinarySearchRecursive(array, mid + 1, high, key);
}

int main()
{
	int array[] = { 1,2,3,4,5,6,7,8,9,10 };

	cout << "No recursive:" << endl;
	cout << "position:" << BinarySearch(array, 10, 6) << endl;
	cout << "recursive:" << endl;
	cout << "position:" << BinarySearchRecursive(array, 0, 9, 6) << endl;

	getchar();
	return 0;
}
