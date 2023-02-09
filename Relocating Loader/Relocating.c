#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
  FILE *f1;
  int i,j,k,a,hex,o;
  char op[10],bit[10],line[100],adrr[15];
  printf("Enter the actual starting address:");
  scanf("%x",&a);
  f1=fopen("input.txt","r");
  do{
    fscanf(f1,"%s",line);
    if(line[0]=='T')
    {
      for(i=2,j=0;j<6;i++,j++)
        adrr[j]=line[i];
      adrr[j]='\0';
      hex = strtol(adrr, NULL, 16)+a;
      i=i+4,j=0;
      while(line[i]!='^')
        {
          bit[j]=line[i];
          i++,j++;
        }
      bit[j]='\0',k=0;
      while(line[i]!='\0')
        {
          if(line[i]!='^')
          {
            for(i=i,j=0;j<6;i++,j++)
                op[j]=line[i];
              op[j]='\0';
            if(bit[k]=='0')
              o = strtol(op, NULL, 16);            
            else
              o = strtol(op, NULL, 16)+a;
            printf("%x \t %x\n",hex,o);
            hex=hex+3,k++;
          }
          else
            i++;
        }
    }
  }while(!feof(f1));
  fclose(f1);
}