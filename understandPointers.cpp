#include<stdio.h>

int main(){
    printf("hgsfedw");
    int num, *ptr, **ptr1;
    printf("%d",ptr);
    ptr = &num;
    // printf("%d \t %d",&ptr,&num);
    ptr1 = &ptr;
    printf("%d \t %d \t %d",num,&num,&num+1);
    printf("\n%d \t %d \t %d \t %d \t %d",ptr,&ptr,&ptr+1,ptr+1,*ptr);
    printf("\n%d \t %d \t %d \t %d \t %d",ptr1, &ptr1,&ptr1+1,*ptr1+1,**ptr1);
    
}