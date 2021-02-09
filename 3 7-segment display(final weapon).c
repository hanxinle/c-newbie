/*************************************************************************
1、这是我重新写的，有关七段码显示的问题，按照书上的P171的说明构建digits数
组，打印的时候，行：第一行~第三行，列：n*4列~n*4+4列，提前将digits赋值，赋
值操作可由另外的函数负责；
2、按照我的想法是先构建出七段码，只有四列，然后对每一个元素进行判断，为零
则不进行任何操作，为1则进行相应的赋值，每个数字的显示设计函数用segments
进行初始化。digits1数组表征七段码，然后用segments数组借助qiduanma[7]驱动
digits方法，决定显示的内容；(我已经在其他.cpp文件中实现了这个思路，以下
代码中注释掉的部分就是了)

这个实现的是书上的要求，不借助digits数组，只是使用segments数组就可以实现
这个过程。
*************************************************************************/

#include <stdio.h>

#define MAXSIZE 10

const int segments[10][7] =  {
		{ 1, 1, 1, 1, 1, 1, 0 },
		{ 0, 1, 1, 0, 0, 0, 0 },
		{ 1, 1, 0, 1, 1, 0, 1 },
		{ 1, 1, 1, 1, 0, 0, 1 },
		{ 0, 1, 1, 0, 0, 1, 1 },
		{ 1, 0, 1, 1, 0, 1, 1 },
		{ 1, 0, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 0, 0, 0, 0 },
		{ 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 1, 1, 1, 0, 1, 1 },

};
/*int qiduanma[7] = { 0 };*/
/************************************************************************************
*使用空格初始化该数组，如果不进行这样的初始化，也可以在声明数组后重新进行初始化
char digits1[3][4]{                                        
		{ ' ', ' ', ' ', ' ', },
		{ ' ', ' ', ' ', ' ', },
		{ ' ', ' ', ' ', ' ', },
};
*************************************************************************************/
char digits[3][40] = {0};



void clear_digits_array(void);
void process_digit(int digit,int position);
void print_digits_array(void);

int main(void)  {

	clear_digits_array();
	int digit;
	int position = -4;
	char a[20] = {0};
    
	printf("Enter your string to show in the screen:");                   /*获取用户输入数据*/
	for (int i = 0; i < 100; i++)  {                                              
		a[i] = getchar();
		if (a[i] == '\n') break;
	}

	printf("The digits is that:\n");                                      /*显示用户输入数据*/
	for (int i = 0; i < MAXSIZE; i++)  {
		if (a[i] <= '9' && a[i] >= '0')	 {
			digit = a[i] - '0';
			position += 4;
			process_digit(digit,position);
		}
	}
	print_digits_array();

	return 0;
}

void clear_digits_array(void)  {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 40; j++)
			digits[i][j] = { ' ' };
}

void process_digit(int digit, int position)  {
	/************************************************************************************************
	//*注释的代码需要借助qiduanma数组来初始化显示的内容，尽量不借助外部数组来完成程序的功能*
	for (int i = 0; i < 7; i++)  {
	qiduanma[i] = segments[digit][i];
	(qiduanma[0] == 1) ? digits[0][position + 1] = '_' : digits[0][position + 1] = ' ';
	(qiduanma[1] == 1) ? digits[1][position + 2] = '|' : digits[1][position + 2] = ' ';
	(qiduanma[2] == 1) ? digits[2][position + 2] = '|' : digits[2][position + 2] = ' ';
	(qiduanma[3] == 1) ? digits[2][position + 1] = '_' : digits[2][position + 1] = ' ';
	(qiduanma[4] == 1) ? digits[2][position + 0] = '|' : digits[2][position + 0] = ' ';
	(qiduanma[5] == 1) ? digits[1][position + 0] = '|' : digits[1][position + 0] = ' ';
	(qiduanma[6] == 1) ? digits[1][position + 1] = '_' : digits[1][position + 1] = ' ';
	}
	************************************************************************************************/
	int i;
	for (i = 0; i < 7; i++)  {

		if (segments[digit][i] == 1)  {
			switch (i){
			case 0: digits[0][position + 1] = '_'; break;
			case 1: digits[1][position + 2] = '|'; break;
			case 2: digits[2][position + 2] = '|'; break;
			case 3: digits[2][position + 1] = '_'; break;
			case 4: digits[2][position + 0] = '|'; break;
			case 5: digits[1][position + 0] = '|'; break;
			case 6: digits[1][position + 1] = '_'; break;
			}
		}
	}
}

void print_digits_array(void)  {
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 40; j++)  {
		printf("%c", digits[i][j]);
		if (j == 39) printf("\n");
		}
}
