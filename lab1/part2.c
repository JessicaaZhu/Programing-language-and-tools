#include<stdio.h>
#include<math.h>

int main(){
	printf("This is PartA:\n");
	double x;
	double y;
	x = 2.55;
	y = 3 * pow(x,3) - 5 * pow(x,2) + 6;
	printf("value = %lf\n",y);
//	printf("value = %d\n",(int)y);
//	printf("value = %c\n",(char)y);
        double ans;
        ans = (3.31 * pow(10,-8) * 2.01 * pow(10,-7))/(7.16 * pow(10,-6)+ 2.01 *pow(10,-8));	
	printf("ans = %lf\n\n\n",ans);

	printf("This is PartB:\n");
	printf("When i = 365,j = 7\nthe next_multiple is :%d\n",365 + 7 - 365 % 7);
	printf("When i = 12258,j = 28\nthe next_multiple is :%d\n",12258 + 28 - 12258 % 28);
	printf("When i = 996,j = 4\nthe next_multiple is :%d\n\n\n",996 + 4 - 996 % 4);

	printf("This is PartC:\n");
	printf("int:\n");
	printf("   PartA:\n");
	printf("value = %d\n",(int)y);
	printf("ans = %d\n",(int)ans);
	printf("   PartB:\n");
	printf("When i = 365,j = 7\nthe next_multiple is :%d\n",365 + 7 - 365 % 7);
	printf("When i = 12258,j = 28\nthe next_multiple is :%d\n",12258 + 28 - 12258 % 28);
	printf("When i = 996,j = 4\nthe next_multiple is :%d\n\n",996 + 4 - 996 % 4);

	printf("double:\n");
	printf("   PartA:\n");
	printf("value = %lf\n",y);
	printf("ans = %lf\n",ans);

	printf("   PartB:\n");
	printf("When i = 365,j = 7\nthe next_multiple is :%lf\n",(double)365 + 7 - 365 % 7);
	printf("When i = 12258,j = 28\nthe next_multiple is :%lf\n",(double)12258 + 28 - 12258 % 28);
	printf("When i = 996,j = 4\nthe next_multiple is :%lf\n",(double)996 + 4 - 996 % 4);
	printf("char:\n");
	printf("   PartA:\n");
	printf("value = %c\n",(char)y);
	printf("ans = %c\n",(char)ans);

	printf("   PartB:\n");
	printf("When i = 365,j = 7\nthe next_multiple is :%c\n",(char)365 + 7 - 365 % 7);
	printf("When i = 12258,j = 28\nthe next_multiple is :%c\n",(char)12258 + 28 - 12258 % 28);
	printf("When i = 996,j = 4\nthe next_multiple is :%c\n",(char)996 + 4 - 996 % 4);

	return 0;




}
