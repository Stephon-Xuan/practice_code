#inclde<iostream>

using namespace std;

//散列函数，求数组下标 
int h1(key){
	return key%m;
}

int h2(key){
	return 1+(key%(m-1));
}


int h(key,i){
	
	return (h1(key)+i*h2(key))%m;
}





//插入散列中
int insert(T,key){
	
	int i = 0,j;
	while(1){
		
		j = h(key,i);
		
	} 
	
} 







//查找

 



int main(){
	
	
	
	return 0;
} 
