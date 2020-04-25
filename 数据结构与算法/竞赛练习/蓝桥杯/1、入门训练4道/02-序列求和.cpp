#include <stdio.h>
int main(){
	long long a,i,count;
	scanf("%I64d",&a);
	count = ((1+a)*a)/2;
	printf("%I64d",count); 
	return 0;
}

/*能不能循环就不用循环，初始化*/
/*for(i = 1;i<=a;i++){
		count=count + i;
	}*/
