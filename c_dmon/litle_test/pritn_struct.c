/*************************************************************************
	> File Name: pritn_struct.c
	> Author: 
	> Mail: 
	> Created Time: Tue 22 Nov 2016 03:48:45 AM PST
 ************************************************************************/

#include<stdio.h>
#include<string.h>

typedef struct _TEST
{
    int a;
    int b;
    char c[4];
}TEST;

void print_struct(void *truct,int size)
{

    printf("address---->+0[%p]\n",truct);
    unsigned char *tt = (unsigned char *)truct;
    printf("address---->+4[%p]\n",tt+4);
    printf("address---->+4[%c]\n",*(tt+4));
   
}

int main()
{
    TEST test;
    test.a = 1;
    test.b = 2;
    strcpy(test.c,"hi");
    int size = sizeof(test);
    
    printf("address of a [%p]\n",&test.a);
    printf("address of b [%p]\n",&test.b);
    print_struct(&test,size);
}

