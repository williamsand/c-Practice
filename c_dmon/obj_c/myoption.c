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

const TestOption *opt_find(void *src,const char *name,const char *unit)
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

int set_string_to_number(void *obj, void *target_obj, const TestOption *opt, const char *val, void *dst)
{
    int num;
    if( sscanf(val,"%d",&num) == 0 )
    {
       printf("enter string \n"); 
       const  TestOption *unit_opt = NULL;
       unit_opt =  opt_find(target_obj,val,opt->unit);
          //printf("unit_opt->default_val.i64 = %d\n",unit_opt->default_val.i64 );
       *(int *)dst = unit_opt->default_val.i64;  
    }
    else
    {
       printf("enter number \n"); 
       *(int*)dst = atoi(val);
    }
}

int opt_set(void *src, const char *name,const char *val, void *target)
{
    void *dst;
    const TestOption *ret_opt = opt_find(src,name,0);
          printf("ret = %p\n",ret_opt);
    dst = src;
    target = src;
    dst =(unsigned char *)target + ret_opt->offset;
          printf("ret->offset = %d\n",ret_opt->offset);
          printf("src= %p\n",src);
    switch(ret_opt->type)
    {
        case OPT_TYPE_INT:
           // *(int*)dst = atoi(val);
            set_string_to_number(src,target,ret_opt,val,dst);
            break;
        default:
            break;
    }
    return 0;
}

