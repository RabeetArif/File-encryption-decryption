#include"Registration_header.h"


 //defininig conditions for REGISTRATION of user
struct user_details
{
   char name[30];
   char password[30];

}w[99];


void registration()
  {
	int n;
    FILE *fp;
    char c,checker[30]; int z=0;
    
	fp=fopen("Web_reg.txt","ab+");
    
	printf("\n\n\t\t\t\tWELCOME TO REGISTRATION MENU.");
    printf("\n\t\t\t\t\t-----------------------------");
    for(int f=0; f<100; f++)
    {
      printf("\n\n\t\t\t\t ENTER USERNAME: ");
      scanf("%s",checker);
        while(!feof(fp))
        {
          fread(&w[f],sizeof(w[f]),1,fp);
          if(strcmp(checker,w[f].name)==0)
            {
            printf("\n\n\t\t\t THIS USERNAME ALREDY EXISTS. SELECT ANOTHER USERNAME.");
            registration();
            }
          else
          {
            strcpy(w[f].name,checker);
            break;
          }
        }
      printf("\n\n\t\t\t\t TYPE IN YOUR DESIRED PASSWORD: ");
      while((c=getch())!=13)
        {
          w[f].password[z++]=c;
          printf("%c",'*');
        }
      fwrite(&w[f],sizeof(w[f]),1,fp);
      fclose(fp);
      printf("\n\n\tPress enter if you agree with Username and Password");
      if((c=getch())==13)
        {
        printf("\n\n\t\tSUCCESSFULL REGISTRATION.");
        printf("\n\n\t\tDO YOU WANT TO LOGIN NOW??\n\n\t\t  ");
        printf("*PRESS '1' FOR 'YES'.\n\n\t\t  * PRESS '2' FOR 'NO'.\n\n\t\t\t\t");
        scanf("%d",&n);
        switch(n)
          {
              case 1: 
                    login();
                    break;
              case 2:
                    printf("\n\n\n\t\t\t\t\tTHANKYOU FOR YOUR REGISTRATION.");
                    break;
          }
        }
        break;
      }
    getch();
  }
 
