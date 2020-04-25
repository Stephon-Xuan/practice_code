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

//牛逼 
//若所求值较大的话，递归函数容易出现栈溢出的现象 
//解题步骤：考虑大于2和等于3的情况 
