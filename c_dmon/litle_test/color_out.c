/*************************************************************************
	> File Name: color_out.c
	> Author: 
	> Mail: 
	> Created Time: Tue 08 Nov 2016 01:26:55 AM PST
 ************************************************************************/

#include<stdio.h>



int main()
{
    int tint = 20;
    char *str = "now and now";
    printf("\e[31m Hello World. \e[0m \n"); // 红色字体  
    printf("\e[32m Hello World. \e[0m \n"); 
    fprintf(stderr,"\e[46m %s. \e[0m ?????\n",str); 
    printf("\e[45m hi,this is why. \e[0m \n"); 
    fprintf(stderr, "\033[38;5;%dm%s\033[0m\n", tint, str);
    return 0;
}
