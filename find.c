;jjjjjjk/*************************************************************************
	> File Name: find.c
	> Author: 
	> Mail: 
	> Created Time: Wed Aug 30 14:01:20 2017
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>
#include<errno.h>
#include <time.h>
#include"unistd.h"
#include"sys/types.h"
#include"fcntl.h"

int findfile(char *filename,char *path){
    struct stat statbuf;
    struct dirent *dirp;
    DIR *dp;
    char tmpbuf[100];
    char *ptr;
    int num;
    if(lstat(path,&statbuf) < 0){
        fprintf(stderr,"lstat is error %s",strerror(errno));
        return 0;
    }
    if(S_ISDIR(statbuf.st_mode) == 0){	//is a dir
        return 0;
    }    
    if((dp = opendir(path)) == NULL){
        fprintf(stderr,"opendir is error %s \n",strerror(errno));
        return 0;
    }
    ptr = path + strlen(path);
    *ptr++ = '/';
    *ptr = 0;
    while((dirp = readdir(dp)) != NULL){
        num = 0;
        if(strcmp(dirp->d_name,".") == 0 || strcmp(dirp->d_name,"..") == 0)
            continue;
        strcpy(ptr,dirp->d_name);
        if(strcmp(dirp->d_name,filename) ==0){
            printf("the result:%s\n",path);
        }        
        if(findfile(filename,path) != 0)       //使用递归层级查找所有当前目录下以及当前目录下胡目录下存在的同名文件
           break;
    }
    closedir(dp);
    return 0;
}

int main(int arg,char **argc)
{
   	int i=0;
int ret;
//	int resend;
char *tmppath,*path;
char *filename;
FILE *fp;
 
//	printf("111111111111111111111\n");
//	for(i = 0; i < arg; i++ )
//	printf("the %d argc is %s\n",i,argc[i]);
    if(arg != 3){
        fprintf(stderr,"args lack:%s\n",strerror(errno));
        return -1;
    }else{
    printf("the original path is %s\n",argc[1]);
    path = realpath(argc[1],tmppath);
     printf("the path: %s\n",path);
     filename = argc[2];
     printf("to find filename : %s\n",argc[2]);
    }   
    printf("start:\n\n");

    ret = findfile(filename,path);
    printf("over!\n\n");
    exit(ret);
}
