#include<stdio.h>
#include<math.h> 
int main(){
	//#define PI 3.14159265358979323
	//#define PI atan(1.0)*4 
	int a;
	double b,PI;
	PI = atan(1.0)*4;
	scanf("%d",&a);
	b = PI*a*a;
	printf("%0.7f",b);
	return 0;
}

//单精度浮点数有效数字8位，双精度浮点数有效数字16位,float在计算中会自动转换成double类型
//可以使用常量来表示π，比如PI=3.14159265358979323，也可以使用数学公式来求π，比如PI=atan(1.0)*4。
