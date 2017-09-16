#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a=0x01234567;
	int i=0;
	char *p = (char *) &a;
	for(i=1;i<=sizeof(int);i++)
	printf("%x ", *p++);
	return 0;
}
