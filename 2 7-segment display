/**********************************************************************************************************************
使用字符串数组来实现七段码方法打印，不能实现横向数字，但是较刚刚写的程序简洁很多，C语言不提供table，使用table可以如
博客中看到那样打印table即可完成题目要求。
**********************************************************************************************************************/
#include<stdio.h>

#define MAXSIZE 100


const  char * digits[] = {                                           
 " __ ", "    ", " __ ", " __ ", "    ", " __ ", " __ ", " __ ", " __ ", " __ ",   /*共30个元素，const char digits[30][5]会浪费存储空间*/
 "|  |", "   |", " __|", " __|", "|__|", "|__ ", "|__ ", "   |", "|__|", "|__|",   /*5代表每个字符串最大字符数*/
 "|__|", "   |", "|__ ", " __|", "   |", " __|", "|__|", "   |", "|__|", " __|", 
};

void printDigit(int digit);

int main(void)
{
	char input[100] = { 0 };
	int digit;

	printf("Enter the digits:");
	for (int i = 0; i < MAXSIZE; i++){
		input[i] = getchar();
		if (input[i] == '\n') break;
	}

	for (int i = 0; i < MAXSIZE; i++){
		if (input[i] > '0' && input[i] < '9'){
			digit = input[i] - '0';
			printDigit(digit);
		}
	}
	return 0;
}


void printDigit(int digit)
{
	if (digit < 10 && digit > -1){
		for (int i = 0; i < 3; i++){
			printf("%s\n", digits[digit + i * 10]);                                 
	    }
	}
	else{
		printf("bad digit!ERROR!");     
		return;                                                      //return出现在返回值为void的函数中，作用：函数printDigit将直接返回
	}
	
}


 
