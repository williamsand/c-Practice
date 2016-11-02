/*************************************************************************
	> File Name: pencodec.c
	> Author: 
	> Mail: 
	> Created Time: Sun 30 Oct 2016 04:25:52 AM PDT
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#include"codec.h"
#include"options.h"

typedef struct AppleContext {
        TestClass *class;
        int gpu;
        int cpu;
}AppleContext;


#define OFFSET(x) offsetof(AppleContext, x)
static const TestOption options[] = {
        {"gpu",  "apple set gpu info",  OFFSET(gpu),   OPT_TYPE_INT},
        {"cpu",  "apple set cpu info",  OFFSET(cpu),   OPT_TYPE_INT},
        {NULL}, 
};

static const TestClass AppleClass = {
        .name = "apple_class",
        .option = options,
};

void apple_printf(PCodecContext *codectx)
{
    AppleContext *ctx = codectx->priv_data;
    printf("the pen [gpu]= %d\n",ctx->gpu);
    printf("the pen_[cpu] = %d\n",ctx->cpu);
}

int apple_add(int a,int b )
{
    printf("enter apple add oprator\n");
    printf("the  apple add result is = [%d]\n",a+b);
    return 0;
}

myCodec apple_codec = {
    .name = "apple",
    .longname = "I have a apple",
    .myprintf = apple_printf,
    .myadd = apple_add,
    .priv_data_size = sizeof(AppleClass),
    .priv_class = &AppleClass,
};


