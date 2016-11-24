/*************************************************************************
	> File Name: two_point.c
	> Author: 
	> Mail: 
	> Created Time: Thu 24 Nov 2016 03:38:28 AM PST
 ************************************************************************/

#include<stdio.h>

typedef struct _AVClass
{
    int c;
    int d;

}AVClass;

typedef struct _TEST
{
    //AVClass *class;
    int *a;
    //int a;
    int b;
}TEST;

void p_two_int(const void *obj)
{
   const int  *p = (const int *)(obj);
   printf("in p_one int address p[%p]\n",p);
   const int  *p2 = *(const int **)(obj);
   printf("in p_two int address p2[%p]\n",p2);
   const int  **p3 = (const int **)(obj);
   printf("in p_three (no deref) int address p3[%p]\n",p3);
}

void p_two_struct(const void *obj)
{
   const AVClass  *p = *(const AVClass **)(obj);
   printf("in p_two address p[%p]\n",p);

}

int main()
{
    TEST test;
    AVClass cls;
    int tt = 6;
    cls.c = 3;
    cls.d = 4;
    test.a = &tt;
    //test.a = 1;
    test.b = 2;
    //test.class = &cls;
    int *p = NULL;

   // p_two_struct(&test);
    p = *(int **)(&test);
    printf("address test[%p]\n",&test);
    printf("address a[%p]\n",test.a);
    printf("address &a[%p]\n",&test.a);
    //printf("address a[%p]\n",&test.a);
    printf("address p[%p]\n",p);
    printf("address b[%p]\n",&test.b);
    printf("_-----------------------------\n");
    p_two_int(&test);
}
