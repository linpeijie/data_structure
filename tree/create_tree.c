#include<stdio.h>
#include<string.h>
#include"def.h"
/* 这里因为用了字符变量，所以一定要用 getchar()吸收掉多余的'\n'字符，不然会发生错误*/

bool create_tree(BiTree* T,char definition[]){
    char ch;
    
    scanf("%c",&ch);
    getchar();                            //absorb redundant symbols
    
    if(ch == '#'){
        (*T) = NULL;
    }    
    else if(!strcmp(definition, "pre")){
        if(!((*T) = (BiTNode*)malloc(sizeof(BiTNode))))
            exit(0);
        (*T)->elem = ch;
        
        printf("enter lchild:\n");
        create_tree(&((*T)->lchild),definition);
        printf("enter rchild:\n");
        create_tree(&((*T)->rchild),definition);
    }
    else if(!strcmp(definition,"in")){
        if(!((*T) = (BiTNode*)malloc(sizeof(BiTNode))))
            exit(0);
        
        create_tree(&((*T)->lchild),definition);
        (*T)->elem = ch;
        create_tree(&((*T)->rchild),definition);
    }
    else if(!strcmp(definition,"post")){}

    return true; 
}
