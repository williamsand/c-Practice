/*************************************************************************
	> File Name: myoption.c
	> Author: 
	> Mail: 
	> Created Time: Mon 24 Oct 2016 04:40:42 AM PDT
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include <stddef.h>
#include <string.h>
#include"options.h"

typedef struct myContext {
    TestClass *class;
    //TestClass class;
    int gpu;
    int cpu;
}myContext;


#define OFFSET(x) offsetof(myContext, x)
static const TestOption options[] = {
    {"gpu",  "set gpu info",  OFFSET(gpu),   OPT_TYPE_INT},
    {"cpu",  "set cpu info",  OFFSET(cpu),   OPT_TYPE_INT},
    {NULL}, 
};


/*const TestOption *opt_next(const TestOption *class,const TestOption *last)
{
    if (!last && class && class[0].name)
    {
        printf("enter class  return\n ");
        printf("class[0].name=%s\n ",class[0].name);
        printf("class[0].help=%s\n ",class[0].help);
         return class;
    }
    if (last && last[1].name)
    {
        printf("enter   last  return\n ");
         return ++last;
    }
    return NULL;
}*/

const TestOption *opt_next(const void *obj,const TestOption *last)
{
    const TestClass *class;
    if (!obj)
        return NULL;
    class = *(const TestClass**)obj;
    if (!last && class && class->option && class->option[0].name)
    {
         return class->option;
    }
    if (last && last[1].name)
    {
         printf("enter   last  return\n ");
         return ++last;
    }
    return NULL;
}

//const TestOption *opt_find(TestOption *src,const char *name)
const TestOption *opt_find(void *src,const char *name)
{
    int num=sizeof(options)/sizeof(TestOption);
    const TestOption *tmp = NULL;
    while(tmp = opt_next(src,tmp))
    {
      if( !strcmp(tmp->name,name))
      {
          printf("find out the right option\n");
          return tmp;
      }  
    }
          printf("no this option\n");
}

/*int opt_set(TestOption *src, const char *name,const char *val, myContext *target)
{
    void *dst;
    const TestOption *ret = opt_find(src,name);
          printf("ret = %p\n",ret);
    dst =(unsigned char *)target + ret->offset;
          printf("ret->offset = %d\n",ret->offset);
          printf("src= %p\n",src);
    switch(ret->type)
    {
        case OPT_TYPE_INT:
            *(int*)dst = atoi(val);
            break;
        default:
            break;
    }
    return 0;
}*/

int opt_set(void *src, const char *name,const char *val, void *target)
{
    void *dst;
    const TestOption *ret = opt_find(src,name);
          printf("ret = %p\n",ret);
    dst = src;
    target = src;
    dst =(unsigned char *)target + ret->offset;
          printf("ret->offset = %d\n",ret->offset);
          printf("src= %p\n",src);
    switch(ret->type)
    {
        case OPT_TYPE_INT:
            *(int*)dst = atoi(val);
            break;
        default:
            break;
    }
    return 0;
}

