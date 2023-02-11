#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
  FILE *f1;
  int i, j, k, a, hex, o;
  char op[10], bit[10], line[100], adrr[15];
  printf("Enter the actual starting address:");
  scanf("%x", &a);
  f1 = fopen("input.txt", "r");
  do
  {
    fscanf(f1, "%s", line);
    if (line[0] == 'T')
    {
      for (i = 2, j = 0; j < 6; i++, j++)
        adrr[j] = line[i];
      adrr[j] = '\0';
      hex = strtol(adrr, NULL, 16) + a;
      i = 12, j = 0;
      while (line[i] != '^')
      {
        bit[j] = line[i];
        i++, j++;
      }
      bit[j] = '\0', k = 0;
      while (line[i] != '\0')
      {
        if (line[i] != '^')
        {
          for (i, j = 0; j < 6; i++, j++)
            op[j] = line[i];
          op[j] = '\0';
          if (bit[k] == '0')
            o = strtol(op, NULL, 16);
          else
            o = strtol(op, NULL, 16) + a;
          printf("%X \t %X\n", hex, o);
          hex = hex + 3, k++;
        }
        else
          i++;
      }
    }
  } while (!feof(f1));
  fclose(f1);
}
/*

Input
H^COPY ^000000^00107A
T^000000^1E^1111111111^140033^481039^100036^280030^300015^481061^3C0003^20002A^1C0039^30002D
T^002500^15^111000^1D0036^481061^180033^4C1000^801000^601003
E^000000

Output
Enter the actual starting address:4000
4000     485039
4003     104036
4006     280030
4009     300015
400c     485061
400f     3c4003
4012     20402a
4015     1c4039
4018     30402d
6500     485061
6503     184033
6506     4c1000
6509     801000
650c     605003

*/