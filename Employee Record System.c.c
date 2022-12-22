#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
//typedef Y y;
//typedef N n;


void gotoxy(int x,int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
struct Employee
{
    int Employee_No;
    char Employee_name[100];
    char Employee_department[34];
    int Employee_salary;
    int Employee_number;
};

int main()
{


    FILE *fp, *ft;
    int typ,No;
    char another;
    char empname[50];
    struct Employee e;

    while(1)
    {
        system("cls");
        gotoxy(45,5);
        printf("1. Add Account\n");
        gotoxy(45,7);
        printf("2. Show Account\n");
        gotoxy(45,9);
        printf("3. Modify Record\n");
        gotoxy(45,11);
        printf("4. Delete Account\n");
        gotoxy(45,13);
        printf("5. Exit\n");
        gotoxy(45,15);
        printf("Your choices:-");
        scanf("%d",&typ);

        switch(typ)
        {
        case 1:
            system("cls");
            fp=fopen("Employee.bin","ab+");
            fseek(fp,0,SEEK_END);
            another= 'y';
            while(another=='y')
            {
                printf("\nEnter Employee No:- ");
                scanf("%d",&e.Employee_No);
                fflush(stdin);
                printf("Enter Employee Name:- ");
                gets(e.Employee_name);
                fflush(stdin);
                printf("Enter Employee Department:- ");
                gets(e.Employee_department);
                fflush(stdin);
                printf("Enter Employee Salary:- ");
                scanf("%d",&e.Employee_salary);
                fflush(stdin);
                fwrite(&e,sizeof(e),1,fp);
                fflush(stdin);
                printf("You want to add another account(y/n):- ");
                scanf("%c",&another);
            }
            fclose(fp);
            printf("Press any key to continue");
            break;

        case 2:
            system("cls");
            fp=fopen("Employee.bin","rb+");
            rewind(fp);
            while(fread(&e,sizeof(e),1,fp)==1)
            {
                printf("Employee No:- ");
                printf("%d\n",e.Employee_No);
                fflush(stdin);
                printf("Employee Name:- ");
                printf("%s\n",e.Employee_name);
                fflush(stdin);
                printf("Employee department:- ");
                printf("%s\n",e.Employee_department);
                fflush(stdin);
                printf("Employee salary:- ");
                printf("%d\n",e.Employee_salary);
                fflush(stdin);
            }
            fclose(fp);
            getch();
            printf("Press any key to continue");
            break ;

        case 3:
            system("cls");
            fp=fopen("Employee.bin","rb+");
            another='y';
            while(another == 'y')
            {
                rewind(fp);
                printf("Enter Employee Name You Want To Modify:- ");
                fflush(stdin);
                gets(empname);
                while(fread(&e,sizeof(e),1,fp)==1)
                {

                    if(strcmp(e.Employee_name,empname)==0)
                    {
                        printf("\nEnter Employee No:- ");
                        scanf("%d",&e.Employee_No);
                        fflush(stdin);
                        printf("Enter Employee Name:- ");
                        gets(e.Employee_name);
                        fflush(stdin);
                        printf("Enter Employee Department:- ");
                        gets(e.Employee_department);
                        fflush(stdin);
                        printf("Enter Employee Salary:- ");
                        scanf("%d",&e.Employee_salary);
                        fflush(stdin);
                        fseek(fp,-sizeof(e),SEEK_CUR);
                        fwrite(&e,sizeof(e),1,fp);
                        break;
                    }
                    else{
                        printf("Please write correct name\n");
                    }
                }
                printf("You want to add another account(y/n):- ");
                fflush(stdin);
                scanf("%c",&another);
            }
            fclose(fp);
            printf("Press any key to continue");
            break;

        case 4:
            system("cls");
            another = 'y';
            fp=fopen("Employee.bin","rb+");
            while(another == 'y')
            {
                printf("\nEnter name of employee to delete: ");
                fflush(stdin);
                gets(empname);
                ft = fopen("Temp.bin","wb");
                rewind(fp);
                while(fread(&e,sizeof(e),1,fp) == 1)
                {
                    if(strcmp(e.Employee_name,empname) != 0)
                    {
                        fwrite(&e,sizeof(e),1,ft);
                    }
                     else{
                        printf("Please write correct name\n");
                        break;
                    }
                }
                fclose(fp);
                fclose(ft);
                remove("Employee.bin");
                rename("Temp.bin","Employee.bin");
                fp=fopen("Employee.bin","rb+");
                printf("Delete another record(y/n)");
                fflush(stdin);
                scanf("%c",&another);
            }
            printf("Press any key to continue");
            break;

        case 5:
            system("cls");
            return 0;
        }

    }
}






