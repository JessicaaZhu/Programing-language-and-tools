#include<stdio.h>
#define value 32

int main(){
	int number[5] = {2,255,32,-1,-255};
	int bits;
	int arr[value];
	for(int i = 0; i < 5; i++){
		int num = number[i];
		printf("%d: ",num);
		for(int j = 0; j < value; j++){
			bits = num & 1;
			arr[32-1-j] = bits;
			num = num  >> 1;
		}
		for(int j = 0;j < value; j++){
			printf("%d",arr[j]);
		}
		printf("\n");
	}


	
	
}
