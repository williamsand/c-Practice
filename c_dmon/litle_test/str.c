/*************************************************************************
	> File Name: str.c
	> Author: 
	> Mail: 
	> Created Time: Fri 18 Nov 2016 09:39:45 PM PST
 ************************************************************************/

#include<stdio.h>


int main()
{
    char buff[20];
    char a[]="hello";
    sprintf(buff,"%s\n",a);
    printf("%s\n",buff);
    return 0;
}
