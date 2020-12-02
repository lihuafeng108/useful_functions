//该模块把一些容易忽略的规则或者用法，用一个个小例子演示出来
#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>  //rand() malloc()
#include <time.h>    //time()

#include "useful_demo.h"

#define PRINT(s) #s  //把宏的参数字符串化
#define PRINT_N(n) printf("num"#n"=%d\n", num##n)  

struct student_info_t
{
	char  age;
	char  name[30];
	float height;
	int   money;
};

int main(int argc, char *argv)
{
	//1)右结合性运算符‘,’号
	int a = (1+2, 2+3);
	int b,c;
	b = a+10, a+20;
	c = (a+10, a+20);
	printf("a=%d, b=%d, c=%d\n",a ,b, c);  //运算结果a=5, b=15, c=25
	
	//2)测试结构成员定位宏offsetof
	printf("student_info_t->money offset:%d\n", offsetof(struct student_info_t, money));  //student_info_t->money offset:36
	
	//3)测试printf
	int dest = 12345;
	printf("dest:%8d\n", dest);  //dest:   12345
	printf("dest:%4d\n", dest);  //dest:12345
	float  dest_f  = 12345.6789;
	double dest_df = 12345.6789;
	printf("dest_f:%10.4f\n", dest_f);     //dest_f:12345.6787 (lihf:单精度问题，输入和读取值不一定相等)
	printf("dest_df:%10.4f\n", dest_df);  //dest_df:12345.6789 (lihf:双精度更加准确)
	printf("dest_df:%10.2f\n", dest_df);  //dest_df:  12345.68 (lihf:保留后面两位，会自动帮你四舍五入)
	printf("dest_df:%-10.3f\n", dest_df); //dest_df:12345.679 (lihf:默认右对齐，加负号让其左对齐)
	
	//4)%运算符的一个用处，取一个范围内的随机数
	int i;
	srand((unsigned int)time(0));  //初始化种子为随机值
	for(i=0; i<5; i++)
	{
		printf("%d ", rand()%10);  //6 5 0 2 5
	}
	printf("\n");
	
	//演示一下宏操作符#、##
	printf("%s\n", PRINT(Hello Word!));  //Hello Word!
	int num1 = 100;
	int num2 = 200;
	PRINT_N(1);
	PRINT_N(2);
	
	//测试一下assert()断言
	int test=0;
	assert(test > 0);   //编译的时候加入NDEBUG宏，断言就不会起作用:gcc useful_demo.c -DNDEBUG 
	/*  起作用后的打印如下:
	assertion "test > 0" failed: file "useful_demo.c", line 62
		199 [sig] a 21832 _cygtls::handle_exceptions: Error while dumping state (probably corrupted stack)
    Segmentation fault (core dumped)*/
	
}
