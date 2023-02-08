#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
    int startaddr;
    char start[10],retype[1];
    FILE *f1,*f2;
    printf("Enter The Starting Address : ");
    scanf("%s",start);
    startaddr=strtol(start,NULL,16);
    f1=fopen("reinput.txt","r");
    f2=fopen("reoutput.txt","w");
    fscanf(f1,"%s",rectype);
    while(strcmp(rectype,"E")!=0)
    {
        if(strcmp(rectype,"H")==0)
            continue;
        else if(strcmp(rectype,"T")==0)
        {
            fscanf(f1,"%s%s",address,bitmask)
            
        }
    }
}