#include"header.h"
#include"structs.h"


void rooms()
{
    system("cls");
    printf("\n\n\t\t******** HOTEL MANAGEMENT SYSTEM ********\n\n\n");
    printf("\t\t1.Show Available rooms\n");
    printf("\t\t2.Check Availability\n");
    printf("\t\t3.Add Room\n");
    printf("\t\t4.Delete Room\n");
    printf("\t\t5.Main menu\n\n");
    printf("\t\tEnter an option: ");
    int z;
    scanf("%d",&z);
    switch(z)
    {
        case 1:
               all_rooms();
               break;
         case 2:
               search_room();
               break;
         case 3:
               add_room();
               break;
         case 4:
               delete_room();
               break;
         case 5:
               main();
               break;
         default:
                 system("cls");
                 main();
    }
}

void all_rooms()
{
    system("cls");
    printf("\n\n\t\t******** HOTEL MANAGEMENT SYSTEM ********\n\n");
    struct room sample;
    int flag=0;
    FILE *fp;
    fp=fopen("room.txt","rb");
    if(fp==NULL)
      {
       goto end;
      }
    int y=1;

    printf("\tSl.\tRoom Number\tCapacity\tRent(Per day)\n\n");
    while(fread(&sample,sizeof(struct room),1,fp))
     {
        flag=1;
    printf("\t%d\t%s\t\t%s\t\t%s\n\n",y,sample.num,sample.capacity,sample.rent);
    y++;
     }
  fclose(fp);
  end:
  if(flag==0)
  {
    printf("\tNo Rooms Available\n");
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
void search_room()
{
    system("cls");
   printf("\n\n\t\t******** HOTEL MANAGEMENT SYSTEM ********\n\n\n");
   printf("\tEnter Room number: ");
   char room_num[20];
   fflush(stdin);
   gets(room_num);

    struct room sample;
    int flag=0;
    FILE *fp;
    fp=fopen("room.txt","rb");
    if(fp==NULL)
      {
       goto end;
      }

    while(fread(&sample,sizeof(struct room),1,fp))
     {
       if(strcmp(room_num,sample.num)==0)
       {
        flag=1;
        printf("\tRoom Available\n\n\tDetails:-\n");
        printf("\n\tRoom Number: %s",sample.num);
        printf("\n\tCapacity: %s",sample.capacity);
        printf("\n\tRent: %s\n",sample.rent);
       }
     }
   fclose(fp);
   end:
   if(flag==0)
   {
    printf("\n\t\tNot Available\n");
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
void add_room()
{
    struct room new;
   system("cls");
   printf("\n\n\t\t******** HOTEL MANAGEMENT SYSTEM ********\n");
   printf("\n\n\tEnter room information:-\n\n");
   printf("\tRoom No.: ");
   fflush(stdin);
   gets(new.num);
   printf("\tCapacity: ");
   fflush(stdin);
   gets(new.capacity);
   printf("\tRent (per day): ");
   fflush(stdin);
   gets(new.rent);

   FILE * fp;


   fp=fopen("room.txt","ab");
   if(fp==NULL)
   {
       printf("Error opening file\n");
       exit(0);
   }
   fwrite(&new,sizeof(struct room),1,fp);
   printf("\n\tSuccessfully Added Room");

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
void delete_room()
{
    system("cls");
   printf("\n\n\t\t******** HOTEL MANAGEMENT SYSTEM ********\n\n\n");
   printf("\tEnter room no.: ");
   char room_num[5];
   fflush(stdin);
   gets(room_num);
    int flag=0;
    struct room sample;
    FILE *fp;
    fp=fopen("room.txt","rb+");
    if(fp==NULL)
      {
       goto end;
      }

    FILE *tmp;
    tmp=fopen("temp.txt","ab");
    if(fp==NULL)
      {
       printf("Error opening file\n");
       exit(0);
      }




    while(fread(&sample,sizeof(struct room),1,fp))
     {
       if((strcmp(room_num,sample.num)==0))
       {
        flag=1;
        continue;
       }
	fwrite(&sample,sizeof(struct room),1,tmp);
     }

   fclose(fp);
   fclose(tmp);
   remove("room.txt");
   rename("temp.txt","room.txt");
   end:
   if(flag==1)
   {
    printf("\n\tDelete Successful\n");
   }
   else
   {
    printf("\n\tNo room found\n");
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
