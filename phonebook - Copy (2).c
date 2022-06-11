#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>


struct contact {
    long ph;
    char name[20];
} list;

char query[20],name[20];
FILE *fp, *ft;
int i,n,ch,l;

int main()
{
main:

    system("cls");
    printf("\n\t **** Welcome to Contact Management System ****");
    printf("\n\n\n\t\t\tMAIN MENU\n\t\t=====================\n\t\tPress 1 Add a new Contact\n\t\tPress2 List all Contacts\n\t\tPress 3 Delete a Contact\n\t\tPress 0 Exit\n\t\t=================\n\t\t");
    printf("Enter the choice:");
    scanf("%d",&ch);
    switch(ch)
    {
    case 0:
        printf("\n\n\t\tAre you sure you want to exit?");
        break;
    case 1:
        system("cls");
        fp=fopen("contact.dll","a");
        for (;;)
        {
            fflush(stdin);

            printf("To exit enter blank space in the name input\nName (Use identical):");
            scanf("%[^\n]",&list.name);
            if(stricmp(list.name,"")==0 || stricmp(list.name," ")==0)
                break;
            fflush(stdin);
            printf("Phone:");
            scanf("%ld",&list.ph);
            fwrite(&list,sizeof(list),1,fp);
        }

        fclose(fp);
        break;
    case 2:
        system("cls");
        printf("\n\t\t================================\n\t\t\tLIST OF CONTACTS\n\t\t================================\n\nName\t\tPhone No\n==============================================================\n\n");

        for(i=97; i<=122; i=i+1)

        {

            fp=fopen("contact.dll","r");
            fflush(stdin);

            while(fread(&list,sizeof(list),1,fp)==1)
            {
            if(list.name[0]==i || list.name[0]==i-32)
                {

                    printf("\n%s\t\t %ld\n",list.name,list.ph);

                }
            }
            fclose(fp);
        }
        break;

    case 3:

        system("cls");
        fflush(stdin);
        printf("\n\n\t..::DELETE A CONTACT\n\t==========================\n\t..::Enter the name of contact to delete:");

        scanf("%[^\n]",&name);

        fp=fopen("contact.dll","r");

        ft=fopen("temp.dat","w");

        while(fread(&list,sizeof(list),1,fp)!=0)

            if (stricmp(name,list.name)!=0)

                fwrite(&list,sizeof(list),1,ft);

        fclose(fp);
        fclose(ft);
        remove("contact.dll");
        rename("temp.dat","contact.dll");
        break;
    default:
        printf("Invalid choice");
        break;

    }
    printf("\n\n\n..::Enter the Choice:\n\n\t[1] Main Menu\t\t[0] Exit\n");
    scanf("%d",&ch);
    switch (ch)
    {
    case 1:
        goto main;
    case 0:
        break;
    default:
        printf("Invalid choice");
        break;

    }
    return 0;
}
