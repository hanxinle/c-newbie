#include <stdio.h>

int sum (int a, int b)  {
  return a+b;
}

int sum1 (int a,int b)  {
  return a-b;
}

int sum2 (int a,int b)  {
  return a+b*2;
}


int cal (int (*f)(int a,int b),int a,int b)  {
  return f(a,b);
}


int main(int argc, char *argv[])  {
  int (*f)(int a,int b);
  f= sum;
  printf("%d\n",f(3,4));
  printf("%d\n",cal(sum,3,4));
     
  int (*CalGroup[3])(int a,int b) = {sum,sum1,sum2};
  printf("Function Group:\n");
  for (int i = 0;i < 3;i++)  {
    printf("%d\n",CalGroup[i](3,4));
  }    

  return 0;
}
