#include<stdio.h>
int main(){
	unsigned long f1=1,f2=1,f3=1,n,i;
	scanf("%d",&n);
	if(n>2){
		for(i=3;i<=n;i++){
			f3 = (f1+f2)%10007;
			f1=f2;
			f2=f3;
		}
	}
	printf("%d",f3);
	return 0;
}

//ţ�� 
//������ֵ�ϴ�Ļ����ݹ麯�����׳���ջ��������� 
//���ⲽ�裺���Ǵ���2�͵���3����� 
