#include"header.h"
#include"structs.h"

void check_in()
{
   struct guest new;
   system("cls");
   printf("\n\n\t\t******** HOTEL MANAGEMENT SYSTEM ********\n");
   printf("\n\n\tEnter guest information:-\n\n");
   printf("\tName: ");
   fflush(stdin);
   gets(new.name);
   printf("\tPhone Number: ");
   fflush(stdin);
   gets(new.number);
   printf("\tNID Number: ");
   fflush(stdin);
   gets(new.nid);
   printf("\tEmail: ");
   fflush(stdin);
   gets(new.email);
   printf("\tAddress: ");
   fflush(stdin);
   gets(new.address);
   printf("\tRoom Number: ");
   fflush(stdin);
   gets(new.room);
   printf("\tCheck-in Date: ");
   fflush(stdin);
   gets(new.in);

   strcpy(new.out,"Not Applicable");

   FILE * fp;


   fp=fopen("guest.txt","ab");
   if(fp==NULL)
   {
       printf("Error opening file\n");
       exit(0);
   }
   fwrite(&new,sizeof(struct guest),1,fp);
   printf("\n\tSuccessfully Checked-in guest");

   fclose(fp);
   printf("\n\n\tMain menu?(y/n):");
   char x;
   fflush(stdin);
   x=getchar();
   if(x=='Y'||x=='y')
   {
       main();
   }
   else
   {
       exit(0);
   }

}


void check_out()
{
   system("cls");
   printf("\n\n\t\t******** HOTEL MANAGEMENT SYSTEM ********\n\n\n");
   printf("\tEnter room no.: ");
   char room_num[5];
   char checkout[100];
   scanf("%s",room_num);

    int flag=0;
    struct guest sample;
    FILE *fp;
    fp=fopen("guest.txt","rb+");
    if(fp==NULL)
      {
      goto end;
      }

   long pos;


    while((pos = ftell(fp)) >= 0 &&fread(&sample,sizeof(struct guest),1,fp))
     {
       if((strcmp(room_num,sample.room)==0)&&(strcmp("Not Applicable",sample.out)==0))
       {
    printf("\n\tGuest Info:\n\n");
    printf("\t\tName: %s\n",sample.name);
    printf("\t\tRoom Number: %s\n",sample.room);
    printf("\t\tCheck-in Date: %s\n",sample.in);
    printf("\n\tEnter Check-out date: ");
    scanf("%s",sample.out);
    fseek(fp, pos, SEEK_SET);
	fwrite(&sample,sizeof(struct guest),1,fp);
    flag=1;
    break;
       }
     }
   fclose(fp);
   end:
   if(flag==1)
   {
    printf("\n\tCheck-out Successful\n");
   }
   else
   {
    printf("\n\tNo guest in the room\n");
   }

   printf("\n\tMain menu?(y/n):");
   char x;
   fflush(stdin);
   x=getchar();
   if(x=='Y'||x=='y')
   {
       main();
   }
   else
   {
       exit(0);
   }

}
