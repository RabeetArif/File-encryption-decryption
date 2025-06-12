#include <stdio.h>
#include"./Util/util_header.h"

int main()
{
    int opt;
    printf("\n\n\n\n\n\t\t\t\t\tWELCOME");
    printf("\n\n\n\n\t\t\tPress Enter to proceed with Login.");

 if(getch()==13)
  
  XY:
  
     printf("\n\n\nPress '1' to LOGIN.\n Press '2' for Registration.\n Press '-1' to Exit.");
     scanf("%d",&opt);

switch(opt)
  {
    case 1: 
        login();
        break;
   
    case 2:
        registration();
        break;

    case 3:
         exit;

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


 
