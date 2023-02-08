#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct symtab
{
    char label[10];
    int locn;
};
struct optab
{
    char opcode[10];
};
void main()
{
    FILE *f1,*f2,*f3;
    struct symtab s[10];
    struct optab o[4];
    strcpy(o[0].opcode,"LDA");
	strcpy(o[1].opcode,"STA");
	strcpy(o[2].opcode,"LDCH");
	strcpy(o[3].opcode,"STCH");
    int startaddr,locctr,pos=0;
    char LABEL[10],OPERAND[10],OPCODE[10];
    f1=fopen("input.txt","r+");
    f2=fopen("intermediate.txt","w");
    f3=fopen("symtab.txt","w");
    fscanf(f1,"%s%s%s",LABEL,OPCODE,OPERAND);
    if(strcmp(OPCODE,"START")==0)
    {
        startaddr=strtol(OPERAND,NULL,16);
        locctr=startaddr;
        fprintf(f2,"\t%s\t%s\t%s\n",LABEL,OPCODE,OPERAND);
        fscanf(f1,"%s%s%s",LABEL,OPCODE,OPERAND);
    }
    else
        locctr=0;
    while(strcmp(OPCODE,"END")!=0)
    {
        fprintf(f2,"%X\t",locctr);
        if(strcmp(LABEL,"**")!=0)
        {
            int errorf=0;
            for(int i=0;i<pos;i++)
            {
                if(strcmp(LABEL,s[i].label)==0)
                {
                    errorf=1;
                    break;
                }
            }
            if(errorf==0)
            {
                strcpy(s[pos].label,LABEL);
                s[pos].locn=locctr;//convert
                pos++;
                fprintf(f3,"%X\t%s\n",locctr,LABEL);
            }
        }
        int found=0;
        for(int i=0;i<5;i++)
        {
            if(strcmp(OPCODE,o[i].opcode)==0)
            {
                found=1;
                break;
            }
        }
        if(found)
            locctr+=3;
        else if(strcmp(OPCODE,"WORD")==0)
            locctr+=3;
        else if(strcmp(OPCODE,"RESW")==0)
            locctr+=3*strtol(OPERAND,NULL,16);
        else if(strcmp(OPCODE,"RESB")==0)
            locctr+=strtol(OPERAND,NULL,16);
        else if(strcmp(OPCODE,"BYTE")==0)
            locctr+=(strlen(OPERAND)-3);
        else
            printf("\nInvalid OPCODE");
        fprintf(f2,"%s\t%s\t%s\n",LABEL,OPCODE,OPERAND);
        fscanf(f1,"%s%s%s",LABEL,OPCODE,OPERAND);
    }
    fprintf(f2,"%X\t%s\t%s\t%s",locctr,LABEL,OPCODE,OPERAND);
    int programlength=locctr-startaddr;
    printf("The Program Length is : %d",programlength);
    fclose(f1);
    fclose(f2);
    fclose(f3);
}

