#include"Login_header.h"


//defininig conditions for login of user
struct user_details
{ 
   char name[30];
   char password[30];
}w[99];

   void login()
    {
      FILE *fp;
      char c,name[30],password[30]; int z=0;
      int checku,checkp;
      
	  fp=fopen("Web_reg.txt","rb");
      
	  printf("\n\n\t\t\t\tWELCOME TO LOG IN MENU.");
	  printf("\n\n\t\t\t\t-----------------------");
      
	  for(int f=0;f<1000;f++)
      {
        printf("\n\n\t\t\t\t  ENTER USERNAME: ");
        scanf("%s",name);
        printf("\n\n\t\t\t\t  ENTER PASSWORD: ");
       
	    while((c=getch())!=13)
        {
          password[z++]=c;
          printf("%c",'*');
        }
           password[z]='\0';
      
	    while(!feof(fp))
        {
          fread(&w[f],sizeof(w[f]),1,fp);
          checku=strcmp(name,w[f].name);
          checkp=strcmp(password,w[f].password);
          
		if(checku==0&&checkp==0)
          {
            printf("\n\n\n\t\t\t SUCCESSFULL LOGIN!");
            break;
          }

        else if(checku==0&&checkp!=0)
          {
            printf("\n\n\n\t\t\tYOU HAVE ENTERED WRONG PASSWORD!! ERROR: %s??",name);
            printf("\n\n\t\t\t\t  (Press 'Y' to re-login)");
            if(getch()=='y'||getch()=='Y')
              login();
          }
        else if(checku!=0)
          {
            printf("\n\n\n\t\t\t NOT A REGISTERED USER!!\n \t\t\tPRESS ENTER FOR REGISTRATION.");
            if(getch()==13)
            reg();
          }
        }
        break;
      }
      getch();
	}