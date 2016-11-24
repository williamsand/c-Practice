/*************************************************************************
	> File Name: va_list.c
	> Author: 
	> Mail: 
	> Created Time: Tue 08 Nov 2016 03:01:16 AM PST
 ************************************************************************/

#include<stdio.h>
#include<stdarg.h>

void test(int a,...)
{
    va_list p;
    va_list copy;
    char *test;
    int ret;
   // va_copy(copy,p);
    printf("p=%p\n",p);
    va_start(p,a);
    do{
        printf("a=%d\t",a);
        a=va_arg(p,int);
        printf("a=%p\t",p);
    }while(a!=0);
    printf("\n");
    va_end(p);
}


int main()
{
    test(23,34,34,54,556,45,0);
    //test("a","b","c","d");
    printf("i>>8= %d\n",0>>8);
}
