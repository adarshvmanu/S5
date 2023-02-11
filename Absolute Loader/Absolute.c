#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
  FILE *fp;
  int i,addr1,l,j,staddre;
  char name[10],line[200],objname[10],addr[10],rec[10],ch,staddr[10];
  printf("\nEnter the Program Name : " );
  scanf("%s",name);
  fp=fopen("SAMPLE.txt","r");
  fscanf(fp,"%s",line);
  for(i=2,j=0;i<8,j<6;i++,j++)
    objname[j] = line[i];
  objname[j] ='\0';
  printf("Name of Object Program : %s\n",objname);
  if(strcmp(name,objname)==0)
    do
    {
    	fscanf(fp,"%s",line);
    	if(line[0]=='T')
    	{
    		for(i=2,j=0;i<8,j<6;i++,j++)
    			staddr[j] = line[i];
    		staddr[j] ='\0';
    		staddre=strtol(staddr,NULL,16);
    		i=12;
    		while(line[i]!='$')
			{
     			if(line[i]!='^')
      			{
        			printf("00%x \t %c%c\n", staddre,line[i],line[i+1]);
        			staddre++;
        			i=i+2;
      			}
      			else i++;
			}
    	}
    	else if(line[0]='E')
    		printf("Jump to Excecution Address : %s\n",&line[2]);
    }while(line[0]!='E');
  fclose(fp);
}

/*

INPUT

H^SAMPLE^001000^0035
T^001000^0C^001003^071009$
T^002000^03^111111$
E^001000

OUTPUT

Enter the Program Name : SAMPLE
Name of Object Program : SAMPLE
001000 	 00
001001 	 10
001002 	 03
001003 	 07
001004 	 10
001005 	 09
002000 	 11
002001 	 11
002002 	 11
Jump to Excecution Address : 001000

*/