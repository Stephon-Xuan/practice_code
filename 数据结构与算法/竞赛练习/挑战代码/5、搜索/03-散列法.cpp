#inclde<iostream>

using namespace std;

//ɢ�к������������±� 
int h1(key){
	return key%m;
}

int h2(key){
	return 1+(key%(m-1));
}


int h(key,i){
	
	return (h1(key)+i*h2(key))%m;
}





//����ɢ����
int insert(T,key){
	
	int i = 0,j;
	while(1){
		
		j = h(key,i);
		
	} 
	
} 







//����

 



int main(){
	
	
	
	return 0;
} 
