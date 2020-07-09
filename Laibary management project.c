#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

char p[10];
int i,n;
struct book_info
{
    int id;
    char name[15];
    char author[20];
    int quntaty;
    int rack;
};
struct book_info a;
FILE *file;

void heading()
{
    printf("\n\n\n\t\t\t***************Liabary Management***************\n\n\n");
}
void passwrd()
{
    int i;
    heading();
    char p1[10]={"tanmoy125"};
    printf("\t\t\t\tEnter Password: ");
    for(i=0;i<9;i++)
    {
        scanf("%c",&p[i]);
    }


    if((strcmp(p,p1))==0)
    {
        printf("\n\n\n\t\t\t\tYour password is correct\n");
        printf("\t\t\t\Now you are log in into laibary project manu\n\n\n");

        printf("\t\t\tPlease Press Any key to go Laiary manu.............");
        fflush(stdin);
        getchar();


              system("cls");


        manu();
    }

    else
        printf("\n\n\n\t\t\t\tYour password is incorrect\n\t\t\t\t Please Try again.....\n");

        passwrd();

}
void manu()
{

    printf("\n\n\t\t\t***************************************\n");
    printf("\t\t\t\t\t~~Main Manu~~\n");
    printf("\t\t\t***************************************\n\n");
    printf("\t \t\t 1.Add Book\n");
    printf("\t \t\t 2.View Books\n");
    printf("\t \t\t 3.Search Book\n");
    printf("\t \t\t 4.Edit Book\n");
    printf("\t \t\t 5.Delete Book\n");
    printf("\t \t\t 6.Help\n");
    printf("\t \t\t 7.Exit \n");
    printf("\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\t \t\t Enter Your Choice: ");
    scanf("%d",&n);
    if(n==1)
    {

        addbook();
    }
    else if(n==2)
        {

            ViewBOok();
        }
    else if(n==3)
        {

            //Searchbook();
        }
    else if(n==4)
        {

            //Editbook();
        }
    else if(n==5)
        {

            //deletebook();
        }
    else if(n==6)
        {

            //help();
        }
    else if(n==7)
        {

            //Exit();
        }
    else
        {
            printf("\t\t\tYour Choice is wrong\n \t\t\t Try again......");

            manu();

        }

}

    void addbook()
    {
        system("cls");
        int d,count;
        printf("\n\n\n\t\t\t***************Add Book***************\n\n\n");
        file=fopen("books.dat","a");
        printf("\t\t\tEnter ID: ");
        scanf("%d",&d);
        rewind(file);
        while(fread(&a,sizeof (a),1,file)==1);
        {
            if(d==a.id)
            {
                printf("\n\t\t\t Sorry you can not add book by using this ID\n\t\t\t This ID has been used\n\t\t\t Using another ID to add book\n");
                fflush(stdin);
                getchar();
                count=1;
            }

        }
        if(count==1)
        {
            addbook();
        }
        else
        {
            a.id=d;




        printf("\t\t\tEnter Book Name: ");
        scanf("%s",&a.name);
        printf("\t\t\tEnter Author Name: ");
        scanf("%s",&a.author);
        printf("\t\t\tEnter Quntity of Books: ");
        scanf("%d",&a.quntaty);
        printf("\t\t\tEnter Self NO: ");
        scanf("%d",&a.rack);
        fseek(file,0,SEEK_END);
        fwrite(&a,sizeof(a),1,file);
        fclose(file);
        manu();

        }

    }


    /////////////
    ViewBOok()
    {
        printf("\n\n\n\t\t\t***************View Book***************\n\n\n");
        printf("\n\t ID \t Name \t Author Name \t Quntity \t Self NO\n") ;
        fopen("books.dat","rb");
        while(fread(&a,sizeof (a),1,file)==1);
        {
            printf("\t %d",a.id);
              printf("\t %s",a.name);
                printf("\t%s",a.author);
                printf("\t\t%d",a.quntaty);
                printf("\t\t%d",a.rack);
                fflush(stdin);
                getchar();
                manu();

        }


    }

int main()
{
    passwrd();

getch();
}
