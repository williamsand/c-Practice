/*************************************************************************
	> File Name: main.c
	> Author: 
	> Mail: 
	> Created Time: Sun 30 Oct 2016 05:17:47 AM PDT
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"codec.h"

static myCodec *first_codec = NULL;
static myCodec **last_codec = &first_codec;

void *aumatic(void * volatile *ptr, void *oldval, void *newval)
{
    if (*ptr == oldval) {
        *ptr = newval;
        return oldval;
    }
    return *ptr;
}

void codec_register(myCodec *codec)
{
    myCodec **p;
    p = last_codec; 
    codec->next = NULL;
    while(*p||aumatic((void * volatile *)p,NULL,codec))
        p = &(*p)->next;
    last_codec = &codec->next;
}

#define REGISTER_CODER(x)                                          \
{                                                                   \
    extern myCodec x##_codec;                                \
    if(&x##_codec)                                       \
        codec_register(&x##_codec);                        \
}

void codec_register_all(void)
{
    REGISTER_CODER(pen);    
    REGISTER_CODER(apple);    
}

myCodec *choose_codec_by_name(const char *name)
{
    myCodec *p;
    if(!name)
        return NULL;
    p = first_codec;
    while(p)
    {
        if(strcmp(p->name,name) == 0)
        {
            printf("find out the codec of name is =%s\n",p->name);
            return p;
        }
        p = p->next;
    }
    return NULL;    
}

int main(int argc ,char *argv[])
{
    PCodecContext *ctx;
    myCodec *dec;
    codec_register_all();
    ctx = (PCodecContext *)malloc(sizeof(PCodecContext));
    ctx->name = "parent codec context";
    char *name = argv[1];
    dec = choose_codec_by_name(name);
    ctx->codec = dec;
    ctx->priv_data = malloc(dec->priv_data_size);
    char *opt = argv[2];
    char *value = argv[3];
    *(const TestClass**)ctx->priv_data = dec->priv_class;
    //ctx->priv_data = dec->priv_context;
    opt_set(ctx->priv_data,opt,value,0);
    ctx->codec->myprintf(ctx);
    ctx->codec->myadd(10,20);
    free(ctx);
}
