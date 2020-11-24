#include <stdio.h>
#include <stdlib.h>

int find_1_in_binary(int num)
{
	int flag = 0;
	while(num)
	{
		num = num&(num - 1);
		flag++;
	}
	
	return flag;
}

int main(int argc, char *agrv[])
{
	if( argc != 2)
	{
		printf("Please input the number\n");
		return -1;
	}		
	
	int num = atoi(agrv[1]);
	printf("the number:%d has %d '0b1' in binary\n", num, find_1_in_binary(num));
}
