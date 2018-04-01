#include<stdio.h>
#include<limits.h>
#include<stdlib.h>
#include<time.h>
#define value 32

int main(){
	srand(time(NULL));	
	int num = rand()%INT_MAX + rand()%INT_MIN;
	int bits;
	int arr[value];
	printf("%d: ",num);
	for(int i = 0; i < value; i++){
		bits = num & 1;
		arr[value-1-i] = bits;
		num = num >> 1;
	}
	for(int j = 0; j < value; j++){
		printf("%d",arr[j]);
	}
	printf("\n");
	return 0;
}

