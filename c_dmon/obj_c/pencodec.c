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

typedef struct PenContext {
      TestClass *class;
      int gpu;
      int cpu;
}PenContext;


#define OFFSET(x) offsetof(PenContext, x)
static const TestOption options[] = {
      {"gpu",  "pen set gpu info",  OFFSET(gpu),   OPT_TYPE_INT},
      {"cpu",  "pen set cpu info",  OFFSET(cpu),   OPT_TYPE_INT},
      {NULL}, 
};

static const TestClass PenClass = {
    .name = "pen_class",
    .option = options,
};

//void pen_printf(myCodec *codec)
void pen_printf(PCodecContext  *codectx)
{
    PenContext *ctx = codectx->priv_data;
    //printf("the pen_codec of Name = %s\n",codec->name);
    printf("the pen [gpu]= %d\n",ctx->gpu);
    //printf("the pen_codec of long Name = %s\n",codec->longname);
    printf("the pen_[cpu] = %d\n",ctx->cpu);
}

int pen_add(int a,int b )
{
    printf("enter pen add oprator\n");
    printf("the pen add result is = [%d]\n",a+b);
    return 0;
}

//PenContext *PenCtx;
//PenCtx->class = &PenClass;

myCodec pen_codec = {
    .name = "pen",
    .longname = "I have a pen",
    .myprintf = pen_printf,
    .myadd = pen_add,
    .priv_data_size = sizeof(PenContext),
    .priv_class = &PenClass,
 //   .priv_context = &PenCtx,
};

