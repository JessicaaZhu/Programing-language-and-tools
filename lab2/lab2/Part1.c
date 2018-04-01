#include<stdio.h>

int main(){
	printf("This is a Fabonacci sequence:\n");

	int prev = 0;
	int cur = 1;
	int next;
	printf("%d ",prev);
	printf("%d ", cur);
	int i;
	int max_value = 20;
	for(i = 2; i <= max_value; i++){
		next = cur + prev;
		prev = cur;
		cur = next;
		printf("%d ",next);
		if(i%4 == 3)printf("\n");
}

}
