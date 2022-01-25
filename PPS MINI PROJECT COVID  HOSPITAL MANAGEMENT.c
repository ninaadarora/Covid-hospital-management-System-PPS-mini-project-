#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

char ans=0, ans1=0;
int ok;
int b, valid=0;
//FUNCTION DECLERATION
void WelcomeScreen(void);
void Title(void);
void MainMenu(void);
void LoginScreen(void);
void Add_rec(void);
void func_list();
void Search_rec(void);
void Vaccine_rec(void);
void ex_it(void);

void gotoxy(short x, short y) {
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

struct patient
{
    int age;
    int age_v;
    int Ward_no[3];
    char date[20];
    char Gender;
    char Gender_v;
    char First_Name[20];
    char Last_Name[20];
    char Contact_no[15];
    char Address[30];
    char Email[30];
    char Doctor[20];
    char Problem[20];
    char Name[20];
    char Last_Name_v[20];
    char Vaccine[20];
    char Aadhar_no[15];
};

struct patient p,temp_c;



 int main(void)
{

    WelcomeScreen();//Use to call WelcomeScreen function
    Title();//Use to call Title function
    LoginScreen();//Use to call Menu function




}
/* * Welcome Screen * */
void WelcomeScreen(void)
{

    printf("\n\n\n\n\n\n\n\t\t\t\t#########################################");
    printf("\n\t\t\t\t#\t\t WELCOME TO\t\t#");
    printf("\n\t\t\t\t#        COVICURE HOSPITAL SYSTEM       #");
    printf("\n\t\t\t\t#########################################");
    printf("\n\n\n\n\n Press any key to continue......\n");
    getch();//Use to holds screen for some seconds
    system("cls");

}
/* * Title Screen * */
void Title(void)
{
    printf("\n\n\t\t----------------------------------------------------------------------------------");
    printf("\n\t\t\t\t         COVICURE HOSPITAL         ");
    printf("\n\t\t----------------------------------------------------------------------------------");
}
/* * Main Menu * */
void MainMenu(void)
{
    system("cls");
    int choose;
    Title();// call Title function
    printf("\n\n\n\n\n\t\t\t\t1. Add Patients Record\n");
    printf("\n\t\t\t\t2. List Patients Record\n");
    printf("\n\t\t\t\t3. Search Patients Record\n");
    printf("\n\t\t\t\t4. Vaccination Record\n");
    printf("\n\t\t\t\t5. Exit\n");
    printf("\n\n\n \n\t\t\t\tChoose from 1 to 5:");
    scanf("%i", &choose);

    switch(choose)
    {

    case 1:
    Add_rec();
        break;
    case 2:
        func_list();
        break;
    case 3:
    Search_rec();
        break;
    case 4:
        Vaccine_rec();
        break;
    case 5:
        ex_it();
        break;

    default:
        printf("\t\t\tInvalid entry. Please enter right option :)");
        getch();
    }


}
/* * Exit Screen * */
void ex_it(void)
{
    system("cls");
    Title();
    printf("\n\n\n\n\n\t\t\tTHANK YOU FOR VISITING :)");
    getch();

}
/* * Login Screen * */
void LoginScreen(void)
{

int e=0 ;
int i;
char Username[15];
char Password[15];
char ch;
char original_Username[25]="admin";
char original_Password[15]="1234";

do
{
    printf("\n\n\n\n\t\t\t\tEnter your Username and Password :)");
    printf("\n\n\n\t\t\t\t\tUSERNAME:");
    scanf("%s",&Username);

    printf("\n\n\t\t\t\t\tPASSWORD:");

     for(i=0;i<10;i++)
 {
     ch=getch();
     Password[i]=ch;
     if(ch!=13)
        printf("*");
     if(ch==13)
        break;
 }
 Password[i]='\0';






    {
        if (strcmp(Username,original_Username)==0 && strcmp(Password,original_Password)==0)


    {
        printf("\n\n\n\t\t\t\t\t...Login Successfull...");


        getch();
        MainMenu();
        break;
    }
    else
    {
        printf("\n\t\t\tPassword in incorrect:( Try Again :)");
        e++;

        getch();
    }

 }

}
while(e<=3);
    if(e>3)
    {
    printf("You have cross the limit. You cannot login. :( :(");
    getch();
    ex_it();
    }

system("cls");
}



/* ADD RECORD*/

void Add_rec(void)
{
    system("cls");
    Title();

    char ans;
    FILE*ek;
    ek=fopen("Record2.dat","a");
    printf("\n\n\t\t\t!!!!!!!!!!!!!! Add Patients Record !!!!!!!!!!!!!\n");

    /* First Name* */
    A:
    printf("\n\t\t\tFirst Name: ");
    scanf("%s",p.First_Name);
    p.First_Name[0]=toupper(p.First_Name[0]);
    if(strlen(p.First_Name)>20||strlen(p.First_Name)<2)
    {
        printf("\n\t Invalid :( \t The max range for first name is 20 and min range is 2 :)");
        goto A;
    }
    else
    {
        for (b=0;b<strlen(p.First_Name);b++)
        {
            if (isalpha(p.First_Name[b]))
            {
                valid=1;
            }
            else
            {
                valid=0;
                break;
            }
        }
        if(!valid)
        {
            printf("\n\t\t First name contain Invalid character :(  Enter again :)");
            goto A;
        }
    }

    /* * Last name * */
    B:
    printf("\n\t\t\tLast Name: ");
    scanf("%s",p.Last_Name);
    p.Last_Name[0]=toupper(p.Last_Name[0]);
    if(strlen(p.Last_Name)>20||strlen(p.Last_Name)<2)
    {
        printf("\n\t Invalid :( \t The max range for last name is 20 and min range is 2 :)");
        goto B;
    }
    else
    {
        for (b=0;b<strlen(p.Last_Name);b++)
        {
            if (isalpha(p.Last_Name[b]))
            {
                valid=1;
            }
            else
            {
                valid=0;
                break;
            }
        }
        if(!valid)
        {
            printf("\n\t\t Last name contain Invalid character :(  Enter again :)");
            goto B;
        }
    }
/* * Gender ** */
    do
    {
        printf("\n\t\t\tGender[F/M]: ");
        scanf(" %c",&p.Gender);
        if(toupper(p.Gender)=='M'|| toupper(p.Gender)=='F')
        {
            ok =1;
        }
        else
        {
        ok =0;
        }
        if(!ok)
        {
            printf("\n\t\t Gender contain Invalid character :(  Enter either F or M :)");
        }
     }  while(!ok);
/* * Age ** */
 do{
  X:  printf("\n\t\t\tAge:");
    scanf(" %i",&p.age);

    if(p.age>=120)
    {
        printf("\n\t\t\t Invalid Age");
            goto X;
    }




}
while(!valid);
/* * Address ** */
    do
    {
    C:
    printf("\n\t\t\tAddress: ");
    scanf("%s",p.Address);
    p.Address[0]=toupper(p.Address[0]);
    if(strlen(p.Address)>20||strlen(p.Address)<4)
    {
        printf("\n\t Invalid :( \t The max range for address is 20 and min range is 4 :)");
        goto C;
    }

}while(!valid);
/* * Contact no. * */
do
{
    D:
    printf("\n\t\t\tContact no: ");
    scanf("%s",p.Contact_no);
    if(strlen(p.Contact_no)>10||strlen(p.Contact_no)!=10)
    {
        printf("\n\t Sorry :( Invalid. Contact no. must contain 10 numbers. Enter again :)");
        goto D;
    }
    else
    {
        for (b=0;b<strlen(p.Contact_no);b++)
        {
            if (!isalpha(p.Contact_no[b]))
            {
                valid=1;
            }
            else
            {
                valid=0;
                break;
            }
        }
        if(!valid)
        {
            printf("\n\t\t Contact no. contain Invalid character :(  Enter again :)");
            goto D;
        }
    }
}while(!valid);
/* * Email * */
do
{
    printf("\n\t\t\tEmail: ");
    scanf("%s",p.Email);
    if (strlen(p.Email)>30||strlen(p.Email)<8)
    {
       printf("\n\t Invalid :( \t The max range for email is 30 and min range is 8 :)");
    }
}while(strlen(p.Email)>30||strlen(p.Email)<8);
/* * Problem * */
    E:
    printf("\n\t\t\tProblem: ");
    scanf("%s",p.Problem);
    p.Problem[0]=toupper(p.Problem[0]);
    if(strlen(p.Problem)>15||strlen(p.Problem)<3)
    {
        printf("\n\t Invalid :( \t The max range for first name is 15 and min range is 3 :)");
        goto E;
    }
    else
    {
        for (b=0;b<strlen(p.Problem);b++)
        {
            if (isalpha(p.Problem[b]))
            {
                valid=1;
            }
            else
            {
                valid=0;
                break;
            }
        }
        if(!valid)
        {
            printf("\n\t\t Problem contain Invalid character :(  Enter again :)");
            goto E;
        }
    }
/* * Prescribed Doctor * */
    F:
    printf("\n\t\t\tPrescribed Doctor:");
    scanf("%s",p.Doctor);
    p.Doctor[0]=toupper(p.Doctor[0]);
    if(strlen(p.Doctor)>30||strlen(p.Doctor)<2)
    {
        printf("\n\t Invalid :( \t The max range for first name is 30 and min range is 2 :)");
        goto F;
    }
    else
    {
        for (b=0;b<strlen(p.Doctor);b++)
        {
            if (isalpha(p.Doctor[b]))
            {
                valid=1;
            }
            else
            {
                valid=0;
                break;
            }
        }
        if(!valid)
        {
            printf("\n\t\t Doctor name contain Invalid character :(  Enter again :)");
            goto F;
        }
    }

    fprintf(ek," %s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, p.Gender, p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor);
    printf("\n\n\t\t\t.... Information Record Successful ...");
    fclose(ek);//ek file is closed
    sd:
    getch();
    printf("\n\n\t\t\tDo you want to add more[Y/N]?? ");
    scanf(" %c",&ans);
    if (toupper(ans)=='Y')
    {
        Add_rec();
    }
    else if(toupper(ans)=='N')
    {
        printf("\n\t\t Thank you :) :)");
        getch();
        MainMenu();
    }
    else
    {
        printf("\n\t\tInvalid Input\n");
        goto sd;
    }
}
/* VIEW RECORD*/
void func_list()
{
    int row;
    system("cls");
    Title();
    FILE *ek;
    ek=fopen("Record2.dat","r");
    printf("\n\n\t\t\t!!!!!!!!!!!!!! List Patients Record !!!!!!!!!!!!!\n");
    gotoxy(1,15);
        printf("Full Name");
        gotoxy(20,15);
        printf("Gender");
        gotoxy(32,15);
        printf("Age");
        gotoxy(37,15);
        printf("Address");
        gotoxy(49,15);
        printf("Contact No.");
        gotoxy(64,15);
        printf("Email");
        gotoxy(88,15);
        printf("Problem");
        gotoxy(98,15);
        printf("Prescribed Doctor\n");
        printf("=================================================================================================================");
        row=17;
        while(fscanf(ek,"%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name,
                    &p.Gender, &p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor)!=EOF)
        {
            gotoxy(1,row);
            printf("%s %s",p.First_Name, p.Last_Name);
            gotoxy(20,row);
            printf("%c",p.Gender);
            gotoxy(32,row);
            printf("%i",p.age);
            gotoxy(37,row);
            printf("%s",p.Address);
            gotoxy(49,row);
            printf("%s",p.Contact_no);
            gotoxy(64,row);
            printf("%s",p.Email);
            gotoxy(88,row);
            printf("%s",p.Problem);
            gotoxy(98,row);
            printf("%s",p.Doctor);
            row++;
        }
        fclose(ek);
        getch();
        MainMenu();
}
void Search_rec(void)
{
    char name[20];
    char namel[20];
    system("cls");
    Title();// call Title function
    FILE *ek;
    ek=fopen("Record2.dat","r");
    printf("\n\n\t\t\t!!!!!!!!!!!!!! Search Patients Record !!!!!!!!!!!!!\n");
    gotoxy(12,8);
    printf("\n Enter Patient Name to be viewed:");
    scanf("%s",name);
    fflush(stdin);
    printf("\n Enter Last Name:");
    scanf("%s",namel);
    fflush(stdin);
    name[0]=toupper(name[0]);
    namel[0]=toupper(namel[0]);
    while(fscanf(ek,"%s %s %c %i %s %s %s %s %s\n", p.First_Name, p.Last_Name, &p.Gender, &p.age, p.Address, p.Contact_no, p.Email, p.Problem, p.Doctor)!=EOF)
    {
        if(strcmp(p.First_Name,name)==0 && strcmp(p.Last_Name,namel)==0)
        {
            gotoxy(1,15);
            printf("Full Name");
            gotoxy(25,15);
            printf("Gender");
            gotoxy(32,15);
            printf("Age");
            gotoxy(37,15);
            printf("Address");
            gotoxy(52,15);
            printf("Contact No.");
            gotoxy(64,15);
            printf("Email");
            gotoxy(80,15);
            printf("Problem");
            gotoxy(95,15);
            printf("Prescribed Doctor\n");
            printf("=================================================================================================================");
            gotoxy(1,18);
            printf("%s %s",p.First_Name, p.Last_Name);
            gotoxy(25,18);
            printf("%c",p.Gender);
            gotoxy(32,18);
            printf("%i",p.age);
            gotoxy(37,18);
            printf("%s",p.Address);
            gotoxy(52,18);
            printf("%s",p.Contact_no);
            gotoxy(64,18);
            printf("%s",p.Email);
            gotoxy(80,18);
            printf("%s",p.Problem);
            gotoxy(95,18);
            printf("%s",p.Doctor);
            printf("\n");
            break;
        }
       }
       if(strcmp(p.First_Name,name)!=0 || strcmp(p.Last_Name,namel)!=0)
       {

        printf("\n\n Record not found!");
        getch();
       }
    fclose(ek);
    L:
    getch();
    printf("\n\n\t\t\tDo you want to view more[Y/N]??");
    scanf("%c",&ans);
    if (toupper(ans)=='Y')
    {
        Search_rec();
    }
    else if(toupper(ans)=='N')
    {
        printf("\n\t\t Thank you :) :)");
        getch();
        MainMenu();
    }
    else
    {
        printf("\n\tInvalid Input.\n");
        goto L;
    }
}
//vaccine record

void Vaccine_rec(void)
{
    system("cls");
    Title();

    char ans1;
    FILE*ekk;
    ekk=fopen("recordvacc.dat","a");
    printf("\n\n\t\t\t!!!!!!!!!!!!!! Vaccination System!!!!!!!!!!!!!\n");
        K:
    printf("\n\t\t\t Name Of Candidate: ");
    scanf("%s",p.Name);
    p.Name[0]=toupper(p.Name[0]);
    if(strlen(p.Name)>20||strlen(p.Name)<2)
    {
        printf("\n\t Invalid :( \t The max range for  name is 20 and min range is 2 :)");
        goto K;
    }
    else
    {
        for (b=0;b<strlen(p.Name);b++)
        {
            if (isalpha(p.Name[b]))
            {
                valid=1;
            }
            else
            {
                valid=0;
                break;
            }
        }
        if(!valid)
        {
            printf("\n\t\t First name contain Invalid character :(  Enter again :)");
            goto K;
        }
    }


        H:
    printf("\n\t\t\tLast Name: ");
    scanf("%s",p.Last_Name_v);
    p.Last_Name_v[0]=toupper(p.Last_Name_v[0]);
    if(strlen(p.Last_Name_v)>20||strlen(p.Last_Name_v)<2)
    {
        printf("\n\t Invalid :( \t The max range for last name is 20 and min range is 2 :)");
        goto H;
    }
    else
    {
        for (b=0;b<strlen(p.Last_Name_v);b++)
        {
            if (isalpha(p.Last_Name_v[b]))
            {
                valid=1;
            }
            else
            {
                valid=0;
                break;
            }
        }
        if(!valid)
        {
            printf("\n\t\t Last name contain Invalid character :(  Enter again :)");
            goto H;
        }
    }
            do{
    z:

    printf("\n\t\t\tAge:");
    scanf(" %i",&p.age_v);

    if(p.age_v>=120)
    {
        printf("\n\t\t\t Invalid Age");
        goto z;
    }
}
while(!valid);
    /**/
        do
    {
        printf("\n\t\t\tGender[F/M]: ");
        scanf(" %c",&p.Gender_v);
        if(toupper(p.Gender_v)=='M'|| toupper(p.Gender_v)=='F')
        {
            ok =1;
        }
        else
        {
        ok =0;
        }
        if(!ok)
        {
            printf("\n\t\t Gender contain Invalid character :(  Enter either F or M :)");
        }
     }  while(!ok);
    printf("n\n\n\t\t Date of Vaccination (dd/mm/yy): ");
    scanf("%s",&p.date);

    /*                                    adhar no  */
    do
{
    J:
    printf("\n\t\t\tAadhar No.: ");
    scanf("%s",p.Aadhar_no);
    if(strlen(p.Aadhar_no)>12||strlen(p.Aadhar_no)!=12)
    {
        printf("\n\t Sorry :( Invalid. Contact no. must contain 12 numbers. Enter again :)");
        goto J;
    }
    else
    {
        for (b=0;b<strlen(p.Aadhar_no);b++)
        {
            if (!isalpha(p.Aadhar_no[b]))
            {
                valid=1;
            }
            else
            {
                valid=0;
                break;
            }
        }
        if(!valid)
        {
            printf("\n\t\t Aadhar no. contain Invalid character :(  Enter again :)");
            goto J;
        }
    }
}while(!valid);



    struct vaccine
    {
        char covaxin[10];
        char covishield[10];
        char sputnik[10];


    };

    struct vaccine  v,temp_c;

    printf("\n\n\n\t Choose Vaccine from Follow :");

       {

    int choose;

    printf("\n\n\n\n\n\t\t\t\t1. Covaxin\n");
    printf("\n\t\t\t\t2. Covishield\n");
    printf("\n\t\t\t\t3. Sputnik\n");
    printf("\n\n\n \n\t\t\t\tChoose from 1 to 3:");
    scanf("%i", &choose);




    switch(choose)
    {

    case 1:
        printf("\n\n\n\n\t\t\t Registration successful for Covaxine");
        strcpy(p.Vaccine,"COVAXIN");
        break;
    case 2:
         printf("\n\n\n\n\t\t\t Registration successful for Covishield");
         strcpy(p.Vaccine,"COVISHIELD");
        break;
    case 3:
         printf("\n\n\n\n\t\t\t Registration successful for Sputnik");
         strcpy(p.Vaccine, "SPUTNIK");
        break;

    default:
        printf("\t\t\tInvalid entry. Please enter right option :)");

        getch();
    }




    }

    fprintf(ekk," %s %s %i %c %c %s %s %s\n", p.Name,p.Last_Name_v, p.age_v, p.age, p.Gender_v,p.date,p.Aadhar_no,p.Vaccine);
    printf("\n\n\t\t\t.... Information Record Successful ...");
    fclose(ekk);

        L:
    getch();
    printf("\n\n\t\t\tDo you want to Exit[Y/N]??");
    scanf("%c",&ans);
    if (toupper(ans)=='Y')
    {
       MainMenu();
    }
    else if(toupper(ans)=='N')
    {
        printf("\n\t\t Thank you :) :)");
        getch();
        MainMenu();
    }
    else
    {
        printf("\n\tInvalid Input.\n");
        goto L;
    }
}
