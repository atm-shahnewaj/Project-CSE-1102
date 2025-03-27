#include"header.h"
#include"structs.h"

int main()
{
    system("cls");
    printf("\033[1;32m");
    menu();
    int n;
    scanf("%d",&n);
    switch(n)
    {
    case 1:
        check_in();
        break;
     case 2:
        check_out();
        break;
    case 3:
        rooms();
        break;
    case 4:
        info();
        break;
    case 5:
        reservation();
        break;
    case 6:
        exit(0);
        break;
    default:
        system("cls");
        main();
    }

    fflush(stdin);
    getch();
    return 0;
}




