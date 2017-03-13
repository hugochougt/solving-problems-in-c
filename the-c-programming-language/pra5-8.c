/*
	函数day_of_year和month_day中没有进行错误检查，请解决该问题。
*/
#include <stdio.h>

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* 将某月某日的日期表示形式转换为某年中第几天的表示形式 */
int day_of_year(int year, int month, int day)
{
	int i, leap;

	leap = year % 4 == 0 && year % 100 == 0 || year % 400 == 0;

	if (month <= 0 || month > 12) {
		printf("error: month is out of range(1 - 12)\n");
		return -1;
	}

	if (day <= 0 || day > daytab[leap][month]){
		printf("error: day is out of range(1 - %d)\n", daytab[leap][month]);
		return -1;
	}

	for (i = 1; i < month; i++) {
		day += daytab[leap][i];
	}
	return day;
}

/* 将某年中第几天的日期表示形式转换为某月某日的表示形式 */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;

	leap = year % 4 == 0 && year % 100 == 0 || year % 400 == 0;
	if(yearday <= 0 || yearday > 365 + leap){
		printf("Error: out of days\n");
		return ;
	}

	for(i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	*pmonth = i;
	*pday = yearday;
}

int main()
{
	int year, month, day, yearday;
	while(1) {
		scanf("%d %d", &year, &yearday);
		month_day(year, yearday, &month, &day);
		printf("The date of No.%d in %d is %d-%d\n", yearday, year, month, day);
		printf("%d-%d is No.%d in %d\n", month, day, day_of_year(year, month, day), year);
	}
	return 0;
}
