/*************************************************************************
	> File Name: test_sscanf.c
	> Author: 
	> Mail: 
	> Created Time: Wed 02 Nov 2016 05:24:45 AM PDT
 ************************************************************************/

#include<stdio.h>

int main(int argc, char *argv[])
{
    int ret = 0;
    int num, den;
    char c;
    char *val = argv[1];
    ret = sscanf(val, "%d%*1[:/]%d%c", &num, &den, &c);
    printf("ret = %d\n",ret);
    printf("num = [%d], den = [%d], c = {%c}\n",num,den,c);
}
