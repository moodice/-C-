#include<iostream>
#include<vector>
using namespace std;
//能用vector就用vector
//都是升序打印	
void printSort(int*num,int len) {

	for (int i = 0; i < len; i++) {
	
		cout << num[i] << "  ";
	}
	cout << endl;
}
void swap(int& a,int& b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}
//选择排序 时间复杂度 N^2 空间复杂度 1  不稳定
void SelectSort(int*num,int len) {
	int temp,j = 0;	
	for (int k = 0; k < len; k++)
	{
		for (int i = 0; i < len; i++)
		{
			if (num[i] > num[j])
			{
				temp = num[i];
				num[i] = num[j];
				num[j] = temp;
			}
		}
		j++; 
	}	
	
}
//冒泡排序 时间复杂度 N^2 空间复杂度 1  稳定
void FoamSort(int* num, int len) {
	int temp;
	for (int j = len; j >0; j--)
	{
		for (int i = 0; i+1 < len; i++)
			{
					if (num[i]>num[i+1])
							{
								temp = num[i];
								num[i] = num[i + 1];
								num[i + 1] = temp;
							}
			}
	}
	
	
}
//插入排序 时间复杂度 N^2 空间复杂度 1  稳定
void InsertSort(int* num, int len) {
	int temp;
	for (int j = 0; j < len; j++)
	{//有序区
		temp = num[j];
		for (int i = j; i >=0; i--)
			{//无序区
				while (temp<num[i])
				{
					num[i+1] = num[i];
					num[i] = temp;
				}
				
			}
	}
	
	

}
//快速排序 (经典双指针) 时间复杂度 N*log2^N 空间复杂度 log2^N  不稳定
void QuickSort(int num[], int low,int high) {
	//设置分区法
	if (low<high)
	{
		int i = low;
		int j = low - 1;//左分区
		int temp = num[high];//基准
		for (int i=low ; i <=high; i++)
		{
			if (num[i]<=temp) {
				++j;
				swap(num[i],num[j]);

			}
		}
		QuickSort(num,low,j-1 );
		QuickSort(num,j+1,high );
	}
}
//归并排序（三指针) 时间复杂度 N*log2^N 空间复杂度 N  稳定
void Merge(int* A, int* L, int leftCount, int* R, int rightCount) {
	int i, j, k;

	i = 0; j = 0; k = 0;

	while (i < leftCount && j < rightCount) {
		if (L[i] < R[j]) A[k++] = L[i++];
		else A[k++] = R[j++];
	}
	while (i < leftCount) A[k++] = L[i++];
	while (j < rightCount) A[k++] = R[j++];
}
//对整数数组进行排序的递归函数。
void MergeSort(int* A, int n) {
	int mid, i, * L, * R;
	if (n < 2) return;

	mid = n / 2;  
	L = new int[mid];
	R = new int[n - mid];

	for (i = 0; i < mid; i++) L[i] = A[i]; 
	for (i = mid; i < n; i++) R[i - mid] = A[i]; 

	MergeSort(L, mid); 
	MergeSort(R, n - mid);  
	Merge(A, L, mid, R, n - mid); 

	delete[] R;
	delete[] L;
}
//希尔排序 时间复杂度 N^1.3 空间复杂度 1  不稳定
void ShellSort(int* num, int len) {
	//Knuth序列
	int h = 1;
	while (h < len/3)
	{
		h = 3 * h + 1;
	}

	while (h = h / 2)
	{
		for (int i = h; i < len; i++)
			{
			for (int j = i; j > h-1; j-=h)
			{
				if (num[j]<num[j-h])
					{
						swap(num[j-h] , num[j]);			
					}			
			}				
			}
		
	}	
}
//计数排序
void CountSort(int* num, int len) {


}
int main() {
	int num[] = {8,3,5,1,6,2,9,7,4};//
	int len = sizeof(num) / sizeof(int);
	int low = 0,high=len-1;
	/*cout << "选择排序： " << endl;
	SelectSort(num,len);*/
	/*cout << "冒泡排序： " << endl;
	FoamSort(num, len);*/
	/*cout << "插入排序： " << endl;
	InsertSort(num, len);*/
	/*cout << "快速排序： " << endl;
	QuickSort(num,low,high);*/
	/*cout << "归并排序： " << endl;
	MergeSort(num,len);*/
	/*cout << "希尔排序： " << endl;
	ShellSort(num, len);*/
	cout << "计数排序： " << endl;
	CountSort(num, len);

	printSort(num, len);
	return 0;
}