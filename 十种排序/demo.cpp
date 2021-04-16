#include<iostream>
#include<vector>
using namespace std;
//����vector����vector
//���������ӡ	
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
//ѡ������ ʱ�临�Ӷ� N^2 �ռ临�Ӷ� 1  ���ȶ�
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
//ð������ ʱ�临�Ӷ� N^2 �ռ临�Ӷ� 1  �ȶ�
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
//�������� ʱ�临�Ӷ� N^2 �ռ临�Ӷ� 1  �ȶ�
void InsertSort(int* num, int len) {
	int temp;
	for (int j = 0; j < len; j++)
	{//������
		temp = num[j];
		for (int i = j; i >=0; i--)
			{//������
				while (temp<num[i])
				{
					num[i+1] = num[i];
					num[i] = temp;
				}
				
			}
	}
	
	

}
//�������� (����˫ָ��) ʱ�临�Ӷ� N*log2^N �ռ临�Ӷ� log2^N  ���ȶ�
void QuickSort(int num[], int low,int high) {
	//���÷�����
	if (low<high)
	{
		int i = low;
		int j = low - 1;//�����
		int temp = num[high];//��׼
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
//�鲢������ָ��) ʱ�临�Ӷ� N*log2^N �ռ临�Ӷ� N  �ȶ�
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
//�����������������ĵݹ麯����
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
//ϣ������ ʱ�临�Ӷ� N^1.3 �ռ临�Ӷ� 1  ���ȶ�
void ShellSort(int* num, int len) {
	//Knuth����
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
//��������
void CountSort(int* num, int len) {


}
int main() {
	int num[] = {8,3,5,1,6,2,9,7,4};//
	int len = sizeof(num) / sizeof(int);
	int low = 0,high=len-1;
	/*cout << "ѡ������ " << endl;
	SelectSort(num,len);*/
	/*cout << "ð������ " << endl;
	FoamSort(num, len);*/
	/*cout << "�������� " << endl;
	InsertSort(num, len);*/
	/*cout << "�������� " << endl;
	QuickSort(num,low,high);*/
	/*cout << "�鲢���� " << endl;
	MergeSort(num,len);*/
	/*cout << "ϣ������ " << endl;
	ShellSort(num, len);*/
	cout << "�������� " << endl;
	CountSort(num, len);

	printSort(num, len);
	return 0;
}