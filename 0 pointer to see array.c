#include <stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdio.h>

int main()
{
	int a[4] = {1,2,3,4};
	int *p1  = a;
	int   i  = 0;

	printf("Use subscript:\n");
	for(i=0;i<4;i++) printf("a[%d] = %d \n",i,a[i]);

	printf("Use array's name:\n");
	for(i=0;i<4;i++) printf("a[%d] = %d\n",i,*(a+i));

	printf("Use pointer,method:\n");
	for(i = 0;i<4;i++) 	printf("a[%d] = %d\n",i,*p1++);

	return 0;

}
