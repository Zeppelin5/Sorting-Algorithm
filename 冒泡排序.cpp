using namespace std;
#include <iostream>
void swap(int *a, int *b);  
void swapRef(int &a,int &b);
int main()  
{  
	//int *array=new int[];
	int  i, j; 
	int  array[10] = {15, 225, 34, 42, 52, 6, 7856, 865, 954, 10}; 
	//for(i=0;i<10;i++)
	//	cin>>array[i]; 
	for (i = 0; i < 10; i++)  
		//每一次由底至上地上升  
		for (j = 9; j > i; j--)  
			if (array[j] < array[j-1])  
				//swap(&array[j], &array[j-1]); 
				swapRef(array[j],array[j-1]);

	for (i = 0; i < 10; i++)  
	{  
		cout<<array[i]<<endl;
	}  
	getchar();
	getchar();
	return 0;  
}  
void swap(int *a, int *b)  
{  
	int temp;  
	temp = *a;  
	*a = *b;  
	*b = temp;  
}

void swapRef(int &a,int &b){
	int temp;
	temp=a;
	a=b;
	b=temp;
}
