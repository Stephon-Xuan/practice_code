#include <stdio.h>
int main(){
	long long a,i,count;
	scanf("%I64d",&a);
	count = ((1+a)*a)/2;
	printf("%I64d",count); 
	return 0;
}

/*�ܲ���ѭ���Ͳ���ѭ������ʼ��*/
/*for(i = 1;i<=a;i++){
		count=count + i;
	}*/
