#include"header.h"
#include"structs.h"
void reservation()
{
    system("cls");
    printf("\n\n\t\t******** HOTEL MANAGEMENT SYSTEM ********\n\n\n");
    printf("\t\t1.New Reservation\n");
    printf("\t\t2.Show all Reservation\n");
    printf("\t\t3.Delete Reservation\n");
    printf("\t\t4.Main Menu\n");
    printf("\t\tEnter an option: ");
    int z;
    scanf("%d",&z);
    switch(z)
    {
        case 1:
               new_reservation();
               break;
         case 2:
               all_reservation();
               break;
         case 3:
               delete_reservation();
               break;
         case 4:
               main();
               break;
         default:
                 system("cls");
                 main();
    }
}

void new_reservation()
{
    struct reservation new;
   system("cls");
   printf("\n\n\t\t******** HOTEL MANAGEMENT SYSTEM ********\n\n");
   printf("\tEnter Guest Information:");
   printf("\n\n\tGuest Name: ");
   fflush(stdin);
   gets(new.name);
   printf("\tContact Number: ");
   fflush(stdin);
   gets(new.number);
   printf("\tRoom Number: ");
   fflush(stdin);
   gets(new.room);
    printf("\tArrival Date: ");
   fflush(stdin);
   gets(new.checkin);
    printf("\tStaying period(days): ");
   fflush(stdin);
   gets(new.time);

   FILE * fp;


   fp=fopen("reservation.txt","ab");
   if(fp==NULL)
   {
       printf("Error opening file\n");
       exit(0);
   }
   fwrite(&new,sizeof(struct reservation),1,fp);
   printf("\n\tReservation Successful");

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
void all_reservation()
{
    system("cls");
    printf("\n\n\t\t******** HOTEL MANAGEMENT SYSTEM ********\n\n");
    struct reservation sample;
    int y=1;
    FILE *fp;
    fp=fopen("reservation.txt","rb");
    if(fp==NULL)
      {
      goto end;
      }
    while(fread(&sample,sizeof(struct reservation),1,fp))
     {
    printf("\tReservation %d:\n\n",y);
    printf("\t\tName: %s\n",sample.name);
    printf("\t\tContact Number: %s\n",sample.number);
    printf("\t\tRoom Number: %s\n",sample.room);
    printf("\t\tArrival Date Date: %s\n",sample.checkin);
    printf("\t\tStaying Period(days): %s\n\n",sample.time);
    y++;
     }
  fclose(fp);
  end:
  if(y==1)
  {
    printf("\tNo Reservation Found\n");
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
void delete_reservation()
{
   system("cls");
   printf("\n\n\t\t******** HOTEL MANAGEMENT SYSTEM ********\n\n\n");
   printf("\tEnter room no.: ");
   char room_num[5];
   char checkin[100];
   scanf("%s",room_num);
   printf("\tEnter Arrival date: ");
   fflush(stdin);
   gets(checkin);

    int flag=0;
    struct reservation sample;
    FILE *fp;
    fp=fopen("reservation.txt","rb+");
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




    while(fread(&sample,sizeof(struct reservation),1,fp))
     {
       if((strcmp(room_num,sample.room)==0)&&(strcmp(checkin,sample.checkin)==0))
       {
        flag=1;
        continue;
       }
	fwrite(&sample,sizeof(struct reservation),1,tmp);
     }

   fclose(fp);
   fclose(tmp);
   remove("reservation.txt");
   rename("temp.txt","reservation.txt");
   end:
   if(flag==1)
   {
    printf("\n\tDelete Successful\n");
   }
   else
   {
    printf("\n\tNo Reservation found\n");
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
