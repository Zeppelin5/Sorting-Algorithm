#include <iostream>
using namespace std;

void adjustHeap(int * arrs, int p, int len) {
	int curParent = arrs[p];
	int child = 2 * p + 1;//左孩子
	while (child < len) {//判断是否存在孩子
		if (child + 1 < len&&arrs[child] < arrs[child + 1])
			child++;//返回最大的孩子。若左小于右孩子，则返回右孩子
		if (curParent < arrs[child]) {
			arrs[p] = arrs[child];//孩子大，则上移孩子
			p = child;//下移该节点（孩子的父亲）
			child = 2 * p + 1;//新孩子的位置
		}
		else
			break;//，没有孩子了，则跳出，
	}
	arrs[p] = curParent;//把curParent赋给下移的父亲
}

void heapSort(int * arrs, int len) {
	for (int i = (len - 1) / 2; i >= 0; i--) {
		adjustHeap(arrs, i, len);
	}//建堆。要做递增排序时，做大顶堆
	for (int i = len - 1; i >= 0; i--) {
		int top = arrs[0];
		arrs[0] = arrs[i];
		arrs[i] = top;//把大顶堆的顶和数组最后一个元素交换，这样大的在后面

		adjustHeap(arrs, 0, i);//筛选时，每次都从最上面开始，最后调出大顶堆
	}
}

int main()
{
	int arrs[] = { 49,38,65,97,76,13,27,49 };
	int arrLen = sizeof(arrs) / sizeof(arrs[0]);
	heapSort(arrs, arrLen);
	for (int i = 0; i < arrLen; i++)
		cout << arrs[i] << " ";
	cout << endl;

	getchar();
	return 0;
}
