struct guest
{
    char name[50];
    char number[20];
    char nid[20];
    char address[100];
    char email[100];
    char room[5];
    char in[100];
    char out[100];
};


struct room
{
    char num[10];
    char capacity[10];
    char rent[10];
};

struct reservation
{
    char name[100];
    char number[100];
    char room[10];
    char checkin[100];
    char time[20];
};
