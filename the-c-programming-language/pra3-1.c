#include<stdio.h>
#include<time.h>
#define N 10000
#define SIZE 100

int binsearch1(int x, int v[], int n);
int binsearch2(int x, int v[], int n);
int binsearch3(int x, int v[], int n);

int main() 
{
	int arr[N], num[SIZE];
	int i, target;
	clock_t start, end;
	
	for(i = 0; i < N; i++)
		arr[i] = i;
	for(i = 0; i < SIZE; i++)
		num[i] = (i + 10) * (i + 45);
 	
 	start = clock();
 	for(i = 0; i < SIZE; i++) {
		 target = binsearch1(num[i], arr, N);
		 //printf("%d : target = %d\n", i, target);
 	}
	end = clock();
 	printf("The runtime was: %ld ms\n", end - start);
 	
 	start = clock();
 	for(i = 0; i < SIZE; i++) {
		target = binsearch2(num[i], arr, N);
		//printf("%d : target = %d\n", i, target);
 	}
	end = clock();
 	printf("The runtime was: %ld ms\n", end - start);
 	
 	start = clock();
 	for(i = 0; i < SIZE; i++) {
		target = binsearch3(num[i], arr, N);
		//printf("%d : target = %d\n", i, target);
 	}
	end = clock();
 	printf("The runtime was: %ld ms\n", end - start);
 	
 	return 0;
}

/* binsearch函数：在v[0]<=v[1]<=v[2]<=...<=v[n-1]中查找x */
int binsearch1(int x, int v[], int n)
{
	int low, high, mid;
	
	low = 0;
	high = n - 1;
	while(low <= high) {
		mid = (low+high) / 2;
		if(x < v[mid])
			high = mid - 1;
		else if(x > v[mid])
			low = mid + 1;
		else	/* 找到了匹配值 */
			return mid;
	}
	return -1;	/* 没有匹配值 */
}

/*  在上面有关折半查找的例子中，while循环语句内共执行了两次测试，其实只要一次就足够
	代价是将更多的测试在循环外执行）。重写该函数，使得在循环内部只执行一次测试。
	比较两种版本函数的运行时间。*/

int binsearch2(int x, int v[], int n)
{
	int low, high, mid;
	
	low = 0;
	high = n - 1;
	mid = low + (high - low) / 2;	/* 避免加法溢出 */
	while(low <= high && x != v[mid]) {
		if(x > v[mid])
			low = mid + 1;
		else
			high = mid - 1;
		mid = low + (high - low) / 2;
	}
	if(x == v[mid])
		return mid;
	else
		return -1;
}

/* binsearch: find x in v[0]<=v[1]<=v[2]<=...<=v[n-1] */
int binsearch3(int x, int v[], int n)
{
	int low, high, mid;
	
	low = 0;
	high = n - 1;
	mid = (low+high) / 2;
	while(low <= high && x != v[mid]) {
		if(x < v[mid])
			high = mid - 1;
		else
			low = mid + 1;
		mid = (low + high) / 2;
	}
	if(x == v[mid])
		return mid;
	else
		return -1;
}
