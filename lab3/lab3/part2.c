#include<stdio.h>
#include"Time.h"
int main(){
	printf("This is partA:\n");
	TRACE;
	struct time t1 = {1,30,45};
	struct time t2 = {16,30,45};
	struct time t3 = {0,1,1};
	struct time t4 = {23,59,59};
	struct time t5 = {12,0,0};

	struct time c1 = calculate(t1,t2);
	struct time c2 = calculate(t3,t4);
	struct time c3 = calculate(t5,t5);

	printtime(c1);
	printtime(c2);
	printtime(c3);
	
	printf("\n\n");
	printf("This is partB: \n");

	struct DateTime dt1 = { JAN, 19, 1809, { 12, 1 } };
	struct DateTime dt2 = { NOV, 11, 1922, { 6, 0 } };
	struct DateTime dt3 = { JAN, 6, 2000, { 8, 22 } };
	printdate(dt1);
	printdate(dt2);
	printdate(dt3);
	return 0;
}
