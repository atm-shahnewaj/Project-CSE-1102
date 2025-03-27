#include"header.h"
#include"structs.h"

void info()
{
    system("cls");
    printf("\n\n\t\t******** HOTEL MANAGEMENT SYSTEM ********\n\n\n");
    printf("\t\t1.Show all Info\n");
    printf("\t\t2.Search by contact no.\n");
    printf("\t\t3.Search by name\n");
    printf("\t\t4.Delete info\n");
    printf("\t\t5.Edit info\n");
    printf("\t\t6.Main menu\n\n");
    printf("\t\tEnter an option: ");
    int z;
    scanf("%d",&z);
    switch(z)
    {
        case 1:
               all_info();
               break;
         case 2:
               search_num();
               break;
         case 3:
               search_name();
               break;
         case 4:
               delete_info();
               break;
         case 5:
               edit_info();
               break;
         case 6:
               main();
               break;
        default:
                 system("cls");
                 main();
    }
}


void all_info()
{
    system("cls");
    printf("\n\n\t\t******** HOTEL MANAGEMENT SYSTEM ********\n\n");
    struct guest sample;
    int y=1;
    FILE *fp;
    fp=fopen("guest.txt","rb");
    if(fp==NULL)
      {
       goto end;
      }



    while(fread(&sample,sizeof(struct guest),1,fp))
     {
    printf("\tGuest %d:\n\n",y);
    printf("\t\tName: %s\n",sample.name);
    printf("\t\tPhone Number: %s\n",sample.number);
    printf("\t\tNID Number: %s\n",sample.nid);
    printf("\t\tEmail: %s\n",sample.email);
    printf("\t\tAddress: %s\n",sample.address);
    printf("\t\tRoom Number: %s\n",sample.room);
    printf("\t\tCheck-in Date: %s\n",sample.in);
    printf("\t\tCheck-out Date: %s\n\n",sample.out);
    y++;
     }
  fclose(fp);
  end:
  if(y==1)
  {
    printf("\tNO Guest Found\n");
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

void search_num()
{
   system("cls");
   printf("\n\n\t\t******** HOTEL MANAGEMENT SYSTEM ********\n\n\n");
   printf("\tEnter contact number of guest: ");
   char contact_num[20];
   fflush(stdin);
   scanf("%s",contact_num);

    struct guest sample;
     int y=1;
    FILE *fp;
    fp=fopen("guest.txt","rb");
    if(fp==NULL)
      {
       goto end;
      }

    while(fread(&sample,sizeof(struct guest),1,fp))
     {
       if(strcmp(contact_num,sample.number)==0)
       {
    printf("\tGuest %d:\n\n",y);
    printf("\t\tName: %s\n",sample.name);
    printf("\t\tPhone Number: %s\n",sample.number);
    printf("\t\tNID Number: %s\n",sample.nid);
    printf("\t\tEmail: %s\n",sample.email);
    printf("\t\tAddress: %s\n",sample.address);
    printf("\t\tRoom Number: %s\n",sample.room);
    printf("\t\tCheck-in Date: %s\n",sample.in);
    printf("\t\tCheck-out Date: %s\n\n",sample.out);
    y++;
       }
     }
   fclose(fp);
   end:
   if(y==1)
   {
    printf("\n\t\tNo Guest Found\n");
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

void search_name()
{
   system("cls");
   printf("\n\n\t\t******** HOTEL MANAGEMENT SYSTEM ********\n\n\n");
   printf("\tEnter name of guest: ");
   char name[50];
   fflush(stdin);
   gets(name);

    struct guest sample;
      int y=1;
    FILE *fp;
    fp=fopen("guest.txt","rb");
    if(fp==NULL)
      {
       goto end;
      }

    while(fread(&sample,sizeof(struct guest),1,fp))
     {
       if(strcmp(name,sample.name)==0)
       {
    printf("\tGuest %d:\n\n",y);
    printf("\t\tName: %s\n",sample.name);
    printf("\t\tPhone Number: %s\n",sample.number);
    printf("\t\tNID Number: %s\n",sample.nid);
    printf("\t\tEmail: %s\n",sample.email);
    printf("\t\tAddress: %s\n",sample.address);
    printf("\t\tRoom Number: %s\n",sample.room);
    printf("\t\tCheck-in Date: %s\n",sample.in);
    printf("\t\tCheck-out Date: %s\n\n",sample.out);
    y++;
       }
     }
   fclose(fp);
   end:
   if(y==1)
   {
    printf("\n\t\tNo Guest Found\n");
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



void edit_info()
{
    system("cls");
   printf("\n\n\t\t******** HOTEL MANAGEMENT SYSTEM ********\n\n\n");
   printf("\tEnter room no.: ");
   char room_num[5];
   char checkin[100];
   scanf("%s",room_num);
   printf("\tEnter check-in date: ");
   fflush(stdin);
   gets(checkin);

    struct guest sample;
    int flag=0;
    FILE *fp;
    fp=fopen("guest.txt","rb+");
    if(fp==NULL)
      {
       goto end;
      }

   long pos;


    while((pos = ftell(fp)) >= 0 &&fread(&sample,sizeof(struct guest),1,fp))
     {
       if((strcmp(room_num,sample.room)==0)&&(strcmp(checkin,sample.in)==0))
       {

         printf("\tGuest info:\n\n");
    printf("\t\tName: %s\n",sample.name);
    printf("\t\tPhone Number: %s\n",sample.number);
    printf("\t\tNID Number: %s\n",sample.nid);
    printf("\t\tEmail: %s\n",sample.email);
    printf("\t\tAddress: %s\n",sample.address);
    printf("\t\tRoom Number: %s\n",sample.room);
    printf("\t\tCheck-in Date: %s\n",sample.in);
    printf("\t\tCheck-out Date: %s\n\n",sample.out);

    char input[100];

    fflush(stdin);
    printf("\t\tEnter new name(enter '*' to skip): ");
    fflush(stdin);
    gets(input);
    if(strcmp(input,"*")!=0)
    {
        strcpy(sample.name,input);
    }
    fflush(stdin);
    printf("\t\tEnter new Phone number(enter '*' to skip): ");
    gets(input);
    if(strcmp(input,"*")!=0)
    {
        strcpy(sample.number,input);
    }
    fflush(stdin);
    printf("\t\tEnter new nid name(enter '*' to skip): ");
    gets(input);
    if(strcmp(input,"*")!=0)
    {
        strcpy(sample.nid,input);
    }
    fflush(stdin);
    printf("\t\tEnter new Email(enter '*' to skip): ");
    gets(input);
    if(strcmp(input,"*")!=0)
    {
        strcpy(sample.email,input);
    }
    fflush(stdin);
    printf("\t\tEnter new Address(enter '*' to skip): ");
    gets(input);
    if(strcmp(input,"*")!=0)
    {
        strcpy(sample.address,input);
    }
    fflush(stdin);
    printf("\t\tEnter new room number(enter '*' to skip):");
    gets(input);
    if(strcmp(input,"*")!=0)
    {
        strcpy(sample.room,input);
    }
    fflush(stdin);
    printf("\t\tEnter new check-in date(enter '*' to skip): ");
    gets(input);
    if(strcmp(input,"*")!=0)
    {
        strcpy(sample.in,input);
    }
    fflush(stdin);
    printf("\t\tEnter new check-out date(enter '*' to skip):");
    gets(input);
    if(strcmp(input,"*")!=0)
    {
        strcpy(sample.out,input);
    }
    fflush(stdin);

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
    printf("\n\tEdit Successful\n");
   }
   else
   {
    printf("\n\tNo guest found\n");
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
void delete_info()
{
    system("cls");
   printf("\n\n\t\t******** HOTEL MANAGEMENT SYSTEM ********\n\n\n");
   printf("\tEnter room no.: ");
   char room_num[5];
   char checkin[100];
   scanf("%s",room_num);
   printf("\tEnter check-in date: ");
   fflush(stdin);
   gets(checkin);
    int flag=0;
    struct guest sample;
    FILE *fp;
    fp=fopen("guest.txt","rb+");
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

    while(fread(&sample,sizeof(struct guest),1,fp))
     {
       if((strcmp(room_num,sample.room)==0)&&(strcmp(checkin,sample.in)==0))
       {
        flag=1;
        continue;
       }
	fwrite(&sample,sizeof(struct guest),1,tmp);
     }

   fclose(fp);
   fclose(tmp);
   remove("guest.txt");
   rename("temp.txt","guest.txt");
   end:
   if(flag==1)
   {
    printf("\n\tDelete Successful\n");
   }
   else
   {
    printf("\n\tNo guest found\n");
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
