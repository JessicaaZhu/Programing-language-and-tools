#include"Time.h"
int numSeconds(int hours, int minutes, int seconds){
//	TRACE;
	int time = seconds + minutes * SECONDS_IN_A_MINUTE + hours * SECONDS_IN_A_MINUTE * MINUTES_IN_AN_HOUR;
	return time;
}

struct time calculate(struct time st1,struct time st2){
	struct time timec;
	int tsec1 = numSeconds(st1.Hours,st1.Minutes,st1.Seconds);
	int tsec2 = numSeconds(st2.Hours,st2.Minutes,st2.Seconds);
	int tsec;
	if (st1.Hours > st2.Hours){
		tsec = tsec1 - tsec2;	
	}else{
		tsec = tsec2 - tsec1;
	}
	timec.Hours = tsec / (SECONDS_IN_A_MINUTE * MINUTES_IN_AN_HOUR);
	timec.Minutes  = (tsec %( SECONDS_IN_A_MINUTE * MINUTES_IN_AN_HOUR)) / SECONDS_IN_A_MINUTE;
	timec.Seconds = tsec % SECONDS_IN_A_MINUTE;

	return timec;

}	
 
void printtime(struct time t){
	printf("%.2d : %.2d :%.2d\n",t.Hours,t.Minutes,t.Seconds);
}

void printdate(struct DateTime dt){
	char mou[12][10] = {"January","February","March", "April","May", "June","July","August","September","October","November","December"};
	printf("%s %d %d %d :%.2d\n",mou[dt.mouths - 1],dt.day,dt.year,dt.tm.Hours,dt.tm.Minutes);
}
