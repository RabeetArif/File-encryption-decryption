#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>
#define ENCRYPTION_FORMULA  (int) Byte + 25
#define DECRYPTION_FORMULA  (int) Byte - 25

void registration();
void login();
void print_File_Status(struct stat stats);
int Encryption(char * FILENAME, char * NEW_FILENAME);
int Decryption(char * FILENAME, char * NEW_FILENAME);

//defininig conditions for login of user
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
    
	fp=fopen("system_users.txt","ab++");
    
	printf("\n\n\t\t\t\tWELCOME TO REGISTRATION MENU.");
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

   void login()
    {
      FILE *fp;
      char c,name[30],password[30]; int z=0;
      int checku,checkp;
      
	  fp=fopen("system_users.txt","rb");
      
	  printf("\n\n\t\t\t\tWELCOME TO LOG IN MENU.");
      
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
            registration();
          }
        }
        break;
      }
      getch();
	}



  void print_File_Status(struct stat stats)
{
    struct tm dt;

    printf("\nFile access: ");
    if (stats.st_mode & R_OK)
        printf("read ");
    if (stats.st_mode & W_OK)
        printf("write ");
    if (stats.st_mode & X_OK)
        printf("execute");

    //Staus to get File size
    printf("\nFile size: %d", stats.st_size);

    // Get file staus regarding the date and time it was created.
    dt = *(gmtime(&stats.st_ctime));
    printf("\nCreated on: %d-%d-%d %d:%d:%d", dt.tm_mday, dt.tm_mon, dt.tm_year + 1900, 
                                              dt.tm_hour, dt.tm_min, dt.tm_sec);
    // File modification time
    dt = *(gmtime(&stats.st_mtime));
    printf("\nModified on: %d-%d-%d %d:%d:%d", dt.tm_mday, dt.tm_mon, dt.tm_year + 1900, 
                                              dt.tm_hour, dt.tm_min, dt.tm_sec);

}

int Encryption(char * FILENAME, char * NEW_FILENAME)
{
		 FILE *inFile;		 		 		 		 		 //Declaration of  input File
		 FILE *outFile;		 		 		 		 		 //Declaration of  output File

		 char Byte;
		 char newByte;
		 int n;


		 printf("1");
		 int i=0;

		 inFile = fopen(FILENAME,"rb");
		 outFile = fopen(NEW_FILENAME, "w");

		 if(inFile==NULL)
		 		 printf("Error: Can't Open inFile");

		 if(outFile==NULL)
		 {
		 		 printf("Error: Can't open outFile.");
		     return 1;
		 }
		
     else
		 {

		 		 printf("File Opened, Encrypting");
		 		 while(1)
		 		 {
		 		 		 printf(".");


		 		 		 if(Byte!=EOF)
		 		 		 {
		 		 		 		 Byte=fgetc(inFile);

		 		 		 //printf("%d",Byte);
		 		 		 		 newByte=Byte+25;

		 		 		 		 fputc(newByte,outFile);

		 		 		 }

		 		 		 else
		 		 		 {
		 		 		 		 printf("End of File");
		 		 		 		 break;
		 		 		 }
		 		 }
		        fclose(inFile);
		        fclose(outFile);

		 }
}

int Decryption(char *FILENAME, char *NEW_FILENAME)
{
		 
		 FILE *inFile;		 		 		 		 		 //Declaration of input File
		 FILE *outFile;		 		 		 		 		 //Declaration of output File

		 char Byte;
		 char newByte;
		 printf("2");
		 int i=0;

		 inFile = fopen(FILENAME,"rb");
		 outFile = fopen(NEW_FILENAME, "w");

		 if(inFile==NULL)
		 	{
        	 printf("Error: Can't Open inFile");
      }
		 
     if(outFile==NULL)
		 {
		 		 printf("Error: Can't open outFile.");

		     return 1;
		 }
		
    else
		 {

		 		 printf("File Opened, Decrypting");
		 		 while(1)
		 		 {
		 		 		 printf(".");


		 		 		 if(Byte!=EOF)
		 		 		 {
		 		 		 		 Byte=fgetc(inFile);
		 		 		 //		 printf("%d",Byte);
		 		 		 		 newByte=Byte-25;

		 		 		 		 fputc(newByte,outFile);

		 		 		 }

		 		 		 else
		 		 		 {
		 		 		 		 printf("End of File");
		 		 		 		 break;
		 		 		 }
		 		 }
		 fclose(inFile);
		 fclose(outFile);

		 }
}

 
 int main()
{
    int opt;
    printf("\n\n\n\n\n\t\t\t\t\tWELCOME");
    printf("\n\n\t\t\tPress Enter to proceed with Login.");

 if(getch()==13)
  
  XY:
  
     printf("\n\n\nPress '1' to LOGIN.\nPress '2' for Registration.\nPress '-1' to Exit.\t");
     scanf("%d",&opt);

switch(opt)
  {
    case 1: 
        login();
        break;
   
    case 2:
        registration();
        break;

    case -1:
         exit;
         break;

    default:
         printf("\n\n\t\t\t\tNO MATCH IS FOUND");
         printf("\n\n\t\t\tPRESS ENTER TO RETURN TO LOGIN MENU.");
        
    if(getch()==13)

    goto XY;
  }
    
    int option;
    char encrypt_File[200];
		char new_encrypt_File[200];
	  char decrypt_File[200];
   	char new_decrypt_File[200];
     

        printf("\n\n\t\t\t\t\t\t\tAFTER LOGIN MENU");
        
        printf("\nDEAR USER.\nSELECT FROM THE FOLLOWING OPTIONS:\n");
        printf("PRESS '1' FOR ENCRYPTING A FILE.\nPRESS '2' FOR DECRYPTING A FILE.\nPRESS '3' TO SEE STATUS FILE.\nPRESS '-1' TO EXIT.\t");
        scanf("%d", &option);
        
        if( option == 1)
        {
             printf("Enter the Source Filename:  ");
		 		 		 scanf("%s",&encrypt_File);
		 		 		 printf("Enter the Destination Filename:   ");
		 		 		 scanf("%s",&new_encrypt_File);
		 		 		 Encryption(encrypt_File, new_encrypt_File);
        }

     else if( option == 2)
     {
            printf("Enter the Source Filename:   ");
		 		 		 scanf("%s",&decrypt_File);
		 		 		 printf("Enter the Destination Filename:   ");
		 		 		 scanf("%s",&new_decrypt_File);
		 		 		 Decryption(decrypt_File, new_decrypt_File);
     }
     
    else if(option == 3)
    {
      char path[100];
      struct stat stats;

       printf("Enter source file path: ");
       scanf("%s", path);

        if (stat(path, &stats) == 0)
      {
          print_File_Status(stats);
      }
        else
      {
          printf("File Status not reached.\n");
          printf("Dear user make sure that '%s' file exists.\n", path);
       }

      }

     else if(option == -1)
     {
        exit;
     }

     else
     {
        printf("Select from the given options.");
     }    
      return 0;
}
                    



