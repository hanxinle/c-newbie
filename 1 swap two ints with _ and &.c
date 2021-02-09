#include <stdio.h>

void swap (int *a,int *b)  {
	int i;
	i = *a;
	*a = *b;
	*b =i;
}

/*swap0 use C++*/
void swap0 (int &a,int &b)  {
	 int p;
	 p = a;
	 a = b;
	 b = p;
}



int main()
{
	int a,b;                   
	printf("Input value of a and b:\n");
	scanf("%d %d",&a,&b);

	int *p1,*p2;               
	p1 = &a;
	p2 = &b;

	printf("\n\n");
	
	swap(p1,p2);
	printf("After 1st time swap:\na = %d \nb = %d\n",*p1,*p2);

	printf("\n");

	swap0 (a,b);
	printf("After 2nd time swap:\na = %d \nb = %d\n",*p1,*p2);

	return 0;

}
