
#ifndef LAB3_H_
#define LAB3_H_
#include<stdio.h>
#define SECONDS_IN_A_MINUTE 60
#define MINUTES_IN_AN_HOUR 60
#define TRACE printf("This is line %d\n",__LINE__);
//int numSeconds(int hours, int minutes, int seconds);

//int tsec,h,m,s;
struct time{
	int Hours;
	int Minutes;
	int Seconds;
};

enum Mouths{JAN = 1,Feb,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC};
struct DateTime{
	enum Mouths mouths;
	int day;
	int year;
      	struct time tm;
};
int numSeconds(int hours, int minutes, int seconds);
void printtime(struct time t);
void printdate(struct DateTime dt);
struct time calculate (struct time st1,struct time st2);


#endif
