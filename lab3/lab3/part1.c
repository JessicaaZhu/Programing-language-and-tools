#include<stdio.h>
#define SECONDS_IN_A_MINUTE 60
#define MINUTES_IN_AN_HOUR 60
#define TRACE printf("This is line: %d\n",__LINE__)
int numSeconds(int hours, int minutes, int seconds);
int main(){
	int h = 10, m = 18, s = 20;
	int times = numSeconds(h,m,s);
	printf("numSeconds is %d \n",times);
}

int numSeconds(int hours, int minutes, int seconds){
	TRACE;
	int time = seconds + minutes * SECONDS_IN_A_MINUTE + hours * SECONDS_IN_A_MINUTE * MINUTES_IN_AN_HOUR;
	return time;

}

