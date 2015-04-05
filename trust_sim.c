#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<windows.h>
float f(float P);
int main()
{
 int rout[20][20];
 float p[20][20];
 float c[20][20];
 int i,j,n;
 char ch;
 printf("Enter the number of routers: ");
 scanf("%d",&n);
 if(n>20)
 {
	printf("Number of routers too high!");
 }
 else
 {
  printf("\n---Scenario---\n");
  for(i=1;i<=n;i++)
  {
   printf("Router %d\t",i);
   Sleep(1000);
  }
  printf("\n\n---Router Connection Setup Wizard---\n");
  for(i=1;i<=n;i++)
  {
   rout[i][i]=0;
   for(j=i+1;j<=n;j++)
   {
    printf("\nIs there a connection between %d and %d?",i,j);
    printf("\nEnter Y/N:");
    fflush(stdin);
    scanf("%c",&ch);
    if(ch=='Y'||ch=='y')
     {
      rout[i][j]=rout[j][i]=1;
      printf("\nEnter Probabilistic Reputation Score, p: ");
      scanf("%f",&p[i][j]);
      p[j][i]=p[i][j];
      c[i][j]=c[j][i]=f(p[i][j]);
     }     
    else
    {
     if(ch=='N'||ch=='n')
      {
      rout[i][j]=rout[j][i]=0;
      p[i][j]=p[j][i]=0.0;
      c[i][j]=0.0;
      }
     else
     {
	  printf("Invalid input!");
	  --j;
	 }
    }
   }
  }
  printf("\n\nSetting up routing table");
  for(i=1;i<=5;i++)
  {
   Sleep((rand()%3)*1000);
   printf(".");
  }
  printf("\n\n---Routing Matrix---\n\n");
  for(i=1;i<=n;i++)
  {
   for(j=1;j<=n;j++)
   {
    if(i==j)
     printf("X  ");
    else
     printf("%d  ",rout[i][j]); 
   }
   printf("\n");
   Sleep(1000);
  }
  printf("\n\n---Reputation Matrix---\n\n");
  for(i=1;i<=n;i++)
  {
   for(j=1;j<=n;j++)
   {
    if(i==j)
     printf("X    ");
    else
     printf("%.2f  ",p[i][j]); 
   }
   printf("\n");
   Sleep(1000);
  }
  printf("\n\n---Score Matrix---\n\n");
  for(i=1;i<=n;i++)
  {
   for(j=1;j<=n;j++)
   {
    if(i==j)
     printf("X    ");
    else
     printf("%.2f  ",c[i][j]); 
   }
   printf("\n");
   Sleep(1000);
  }  
 }
 return 0;
}
/* 
*/
float f(float P)
{
	float A,B;
	printf("\n\nEnter value of evidence supporting actual event: ");
 	scanf("%f",&A);
	printf("\n\nEnter value of evidence supporting negation: ");
 	scanf("%f",&B);
 	float c=(tgamma(A+B)/(tgamma(A)*tgamma(B)))*pow(P,(A-1))*pow(P,(B-1));
 	return c;
}
