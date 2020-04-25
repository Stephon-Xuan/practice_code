/*
插入排序法的算法如下。
insertionSort (A, N) / / 包含 N 个元素的 0 起点数组 A
    for i 从 1 至 N-l
        v = A[i]
        j = i-1
        while j > = 0 且 A[j] > temp
            A[j+1] = A[j]
            j--
         A[j+1] = v
         
请编写一个程序， 用插入排序法将包含 N个元素的数列 A按升序排列。程序中需
包含上述伪代码所表示的算法。为检验算法的执行过程， 请输出各计算步骤的数组
( 完成输入后的数组，以及每次i自增后的数组 ）。

输 入 
在第1行输入定义数组长度的整数 N。在 第 2 行输入N个整数，以空格隔开
 
输 出 
输出总共有N行。插人排序法每个计算步骤的中间结果各占用 1 行。 数列的各
元素之间空 1 个空格。请注意，行尾元素后的空格等多余的空格和换行会被认
定为 Presentation Error。 

限制 
1<= N <=100
0<= A的元素 <=100 

输入示例
6
5 2 4 6 1 3

输出示例
5 2 4 6 1 3
2 5 4 6 1 3
2 4 5 6 1 3
2 4 5 6 1 3
1 2 4 5 6 3
1 2 3 4 5 6
*/ 


# include <iostream>
using namespace std;

//输出数组 
void trace(int A[],int N){
	for(int i = 0; i < N; i++){
		cout << A[i] << " ";
	}
	cout << endl;
} 


//插入排序
void insertionSort(int A[],int N)
{
	int temp,i,j;
	for(i = 1; i < N;i++){//从第二个元素开始 
		temp = A[i];//保留A[i]的值 
		j = i -1;//A[i]的前一个值的下标 
		//满足条件，在有序区将比a[i]大的数据向后移
		while(j >=0 && A[j] > temp){
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = temp;//将a[i]的值放到正确位置上
		
		trace(A,N);//输出数组			
	}
} 

int main(){
	int N;//数组长度 
	cin >> N;
	int A[N];//数组 
	for(int i = 0;i < N; i++){
		cin >> A[i];
	}
	trace(A,N); 
	insertionSort(A,N);
	return 0;
} 
