/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: Wed 23 Nov 2016 05:36:42 PM PST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include"level.h"

int main()
{
    TEST test;
    char *word = "hello wold";
    int num = 1;
    strcpy(test.name,"sand");
    my_log(NULL,LEVEL_ERROR,"the level_error to say wrong: %s\n",word);
    my_log(&test,LEVEL_DEBUG,"This is[%d] nothing but say: %s\n",num,word);
    my_log(&test,LEVEL_INFO,"the level_info going say: %s\n",word);
    my_log(&test,LEVEL_ERROR,"the level_error to say wrong: %s\n",word);
    
    return 0;
}
