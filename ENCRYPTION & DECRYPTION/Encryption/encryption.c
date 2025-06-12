#include "encryption_header.h"


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
