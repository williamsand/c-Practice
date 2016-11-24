/*************************************************************************
	> File Name: level.c
	> Author: 
	> Mail: 
	> Created Time: Wed 23 Nov 2016 04:01:58 AM PST
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdarg.h>
#include"level.h"
#include"options.h"


static void my_bprint(LOG_INFO *log_info,const char *fmt,...)
{
    va_list vl;
    va_start(vl,fmt);
    vsnprintf(log_info->name,50,fmt,vl);
    va_end(vl);

}

static void my_vbprintf(LOG_INFO *log_info, const char *fmt, va_list vl_arg)
{
    va_list vl;
    va_copy(vl,vl_arg);
    vsnprintf(log_info->log,512,fmt,vl);
    va_end(vl);
    
}

static void my_format_line(void *ctx,int level,const char *fmt,va_list vl,LOG_INFO *log_info)
{
    //TEST *ctest =ctx?(TEST *)ctx:NULL;
    TestClass *tcs = ctx? *(TestClass**)ctx : NULL; 
    if(tcs)
    {
       my_bprint(log_info,"[%s @ %p]",tcs->name,tcs->name);
    }
    my_vbprintf(log_info,fmt,vl);
    //strcat(log_info->log,"\n");
}

static void color_puts(int level,const char *str)
{
    fprintf(stderr,"\e[%dm%s\e[0m",level,str);
}

static void my_vlog(void *ctx,int level,const char *fmt,va_list vl)
{
    LOG_INFO log_info;
    memset(&log_info,0,sizeof(log_info));
    //char line[1024];
    my_format_line(ctx,level,fmt,vl,&log_info);
    //snprintf(line,sizeof(line),"%s%s",log_info.name,log_info.log);
    color_puts(34,log_info.name);
    color_puts(level,log_info.log);
    //memset(&log_info,0,sizeof(log_info));
    //memset(line,0,sizeof(line));
}

void my_log(void *ctx,int level,const char *fmt,...)
{
    va_list vl;
    va_start(vl,fmt);
    my_vlog(ctx,level,fmt,vl);
    va_end(vl);
}

