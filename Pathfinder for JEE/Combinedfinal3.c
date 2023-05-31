#include <stdio.h>
#include <conio.h>  //getch()
#include <stdlib.h> //system("CLS");//exit(0);
#include <string.h>
#include <limits.h>
#include <windows.h> //Message Box//Sleep(milliseconds)
#include <math.h>
#include <stdbool.h> //Bool data type
#include <time.h>
#include <unistd.h> //sleep(seconds)

int min = INT_MIN;
#define f(n) for (int i = 0; i < n; i++)
char UserID[100];
FILE *fp;

void collegepredictor();
void rankpredictor();
void collegedetails();
void mycourses();
void mocktest();
void otherresources();
void preptracker();
void scheduler();
void settings();
void notifications();
void helpdesk();
void ratings();
int admin();
void alarmclock();
int clocks();

typedef struct UserData
{
    char firstname[1000];
    char lastname[1000];
    int Date, month, year;
    char email[100];
    char gender[10];
    int class;
    char state[100];
} Data;
Data user[1000];

typedef struct paper1
{
    char p1[100];
    char p2[100];
} p;
p pep[100];
typedef struct usernameandPassword
{
    char UserID[100];
    char Password[25];
} sp;
sp up[1000];

typedef struct banned
{
    char ban_id[50];
} banned;
banned ban_arr[50];

typedef struct CR
{
    char name[100];
    int cr;
    int or ;
    char branch[100];
    char category[100];
    char gender[100];
} st;

typedef struct data
{
    char co[20];
    char state[20];
    int nr, yoe, fees, hf;
    float disf, disr, high, avg;
} dt;
dt collegedet[23];

struct Books
{
    char title[50];
    char booklink[200];
};

typedef struct event
{
    char work[100];
    int hour;
} event;
event e[1000];
typedef struct work
{
    char works[1000];
    char user[100];
    int worknumber;
} wor;
wor in[1000];

typedef struct yo
{
    char ques[200];
    char ans[200];
    int freq;
} qs;

typedef struct input
{
    char in[200];
} input;

typedef struct string
{
    char qword[30];
} string;

struct answers
{
    char sat[12];
    char mat[18][5];
    int itype[6];
    float numer[12];
} sas;
struct answers ansinput1[10];
struct answers ansinput2[10];
struct answers anssaved1[10];
struct answers anssaved2[10];

typedef struct subjecttopic
{
    char chapter[100];
    int percoverage;
    int hardness; // on scale of 1(easy),2(moderate),3(hard)
} sub;

typedef struct te
{
    char name[40];
    char password[40];
} te;

typedef struct q_a
{
    char ques[100];
    char ans[100];
} q_a;

typedef struct paper
{
    char paper1[50];
    char paper2[50];
} paper;

typedef struct stlist
{
    char id[30];
    char password[30];
} stlist;
typedef struct ub
{
    char unban_id[50];
} ub;
ub unban_arr[50];

typedef struct alarm
{
    int hour;
    int min;
    int sec;
} alarm;

void loginregisterpage();
void login();
void reg();
void forgotpassword();
void mainmenu();
int countuser();
int check_ban(char id[], banned ban_arr[], int i);

int fnow();
void takework();
void printwork();
void addwork(int);
void printallwork(int arr[], int);
void mainmenu();

void swap(st b[], int i, int j);
int partition(st b[], int l, int r);
void quicksort(st a[], int l, int r);
bool compare(char a[], char b[]);
int college(st a[], int rank, char *gender, char *cat, st b[], int number);

int printcol(int);
void printline();
void sort();

void printBook_x(struct Books book);
void payment();
// int countuser();
void print_data(int count);
void viewProfile();
int editProfile(int);
void editProfile2();
void changePassword(int);

void substr(char a[], int start, int end, char c[]);
bool compare(char a[], char b[]);
void merge(qs qsarr[], int l, int mid, int r);
void mergesort(qs qsarr[], int l, int r);
void search(qs qsarr[], input word[], int wnum, string quesans[], int quesnumber);
char str[200];

float numrate();
int check();
int find_user();
void printuserprofile();

void mockpyqs();
void createtest();
int timer(time_t begin);
int marks(int, struct answers ansi[], struct answers anss[]);
int rank(int, int);
void answering(int, int, struct answers anss[], time_t begin);

void edithelpdesk();
void addquespaper();
void list();
void ban();
void unban();
void swaphr(alarm alarms[], int i, int j);
int partition2(alarm alarms[], int l, int r);
void quicksort2(alarm alarms[], int l, int r);
int binarysearch(alarm alarms[], int n, int x);
void swapmin(alarm alarms[], int i, int j);
int partitionmin(alarm alarms[], int l, int r);
void quicksortmin(alarm alarms[], int l, int r);
int binarysearchmin(alarm alarms[], int n, int x);

int main()
{
    system("CLS");
    FILE *fptr;
    int count = countuser();
    fptr = fopen("LoginSignupPage.txt", "r");
    for (int i = 0; i < count; i++)
    {
        fscanf(fptr, "%s", &up[i].UserID);
        fscanf(fptr, "%s", &up[i].Password);
    }
LP:
    system("cls");
    printf("\n\n\n\n\n\n");
    printf("\033[1;32m\t\t\t===============================================================================================================");
    printf("\n\n\t\t\t\t\t\t\t    \033[1;36mWELCOME TO THE ALL IN ONE APP FOR JEE");
    printf("\n\n\t\t\t\t\t\t\t            \033[1;36mCOLLEGE CUM PATHFINDER\n\n");
    printf("\033[1;32m\t\t\t===============================================================================================================");
    printf("\033[1;33m\n\n\n\n\t\t\t\t\t\t    Press Enter to proceed...!!");
    if (getch() == 13)
        system("CLS");
    else
    {
        goto LP;
    }
    loginregisterpage();
    return 0;
}
void loginregisterpage()
{
    system("CLS");
S1:
    printf("\n\n\n\n\n\n");
    printf("\033[1;35m\t\t\t\t===============================================================================================================");
    printf("\033[1;34m\n\n\n\t\t\t\t\t\t\t\t1. LOGIN\t\t2. REGISTER\n\n\t\t\t\t\t\t\t\t3. ADMIN LOGIN\t\t4. Exit\n\n");
    printf("\033[1;35m\t\t\t\t===============================================================================================================");
    printf("\033[1;31m\n\n\n\t\t\t\t\t\t\t\t      ENTER YOUR CHOICE: \033[1;0m");
    int n;
    scanf("%d", &n);

    switch (n)
    {
    case 1:
        system("CLS");
        login();
        break;
    case 2:
        system("CLS");
        reg();
        break;
    case 3:
        system("CLS");
        admin();
        break;
    case 4:
        system("CLS");
        printf("\033[1;31m\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tExited\n\n\n\n\n\n\033[1;0m");
        exit(0);
    default:
    {
        printf("\033[1;31m\n\n\t\t\t\t\t\t  NO MATCH FOUND");
        printf("\033[1;37m\n\n\t\t\t\t\tPress Enter to Re-Enter your choice. \033[1;0m");
        if (getch() == 13)
        {
            system("CLS");
            goto S1;
        }
    }
    }
}
void mainmenu()
{
S2:
    system("CLS");
    system("cls");
    printf("\t\t\033[1;35m\t\t\t======================================================================================\033[1;0m");
    printf("\033[4;37m\n\n\t\t\t\t\t\t\t\t\t\tMAIN MENU\033[1;0m");
    printf("\033[1;33m\n\t\t\t\t\t\t\t\t\t1.College Predictor");
    printf("\033[1;33m\n\t\t\t\t\t\t\t\t\t2.Rank Predictor");
    printf("\033[1;32m\n\t\t\t\t\t\t\t\t\t3.College Details");
    printf("\033[1;32m\n\t\t\t\t\t\t\t\t\t4.My Courses");
    printf("\033[1;32m\n\t\t\t\t\t\t\t\t\t5.Mock Test");
    printf("\033[1;36m\n\t\t\t\t\t\t\t\t\t6.Other resources");
    printf("\033[1;36m\n\t\t\t\t\t\t\t\t\t7.Preparation Tracker");
    printf("\033[1;34m\n\t\t\t\t\t\t\t\t\t8.Clock");
    printf("\033[1;34m\n\t\t\t\t\t\t\t\t\t9.Remainder clock");
    printf("\033[1;34m\n\t\t\t\t\t\t\t\t\t10.To do list");
    printf("\033[1;35m\n\t\t\t\t\t\t\t\t\t11.Settings");
    printf("\033[1;35m\n\t\t\t\t\t\t\t\t\t12.Notifications");
    printf("\033[1;35m\n\t\t\t\t\t\t\t\t\t13.Helpdesk");
    printf("\033[1;31m\n\t\t\t\t\t\t\t\t\t14.Rate our app");
    printf("\033[1;31m\n\t\t\t\t\t\t\t\t\t15.Logout");
    printf("\033[1;31m\n\t\t\t\t\t\t\t\t\t16.Exit\n\n");
    printf("\t\t\033[1;35m\t\t\t======================================================================================\033[1;0m");
    int n;
    printf("\n\n\t\t\t\t\tEnter your choice: ");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
        collegepredictor();
        break;
    case 2:
        rankpredictor();
        break;
    case 3:
        collegedetails();
        break;
    case 4:
        mycourses();
        break;
    case 5:
        mocktest();
        break;
    case 6:
        otherresources();
        break;
    case 7:
        preptracker();
        break;
    case 8:
        clocks();
        break;
    case 9:
        alarmclock();
        break;
    case 10:
        scheduler();
        break;
    case 11:
        settings();
        break;
    case 12:
        notifications();
        break;
    case 13:
        helpdesk();
        break;
    case 14:
        ratings();
        break;
    case 15:
        loginregisterpage();
        break;
    case 16:
        system("CLS");
        printf("\033[1;31m\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tExited\n\n\n\n\n\n\033[1;0m");
        Sleep(1000);
        exit(0);
    default:
    {
        printf("\033[1;31mINVALID INPUT\n");
        printf("\033[1;32mPress Enter to re-enter the choice:\033[1;0m");
        if (getch() == 13)
        {
            system("CLS");
            goto S2;
        }
    }
    }
}
void login()
{
    system("cls");
    FILE *su = fopen("ban.txt", "r");
    int kk = 0;
    int zeo = 0;
    while (1)
    {
        kk = fscanf(su, "%s", ban_arr[zeo].ban_id);
        zeo++;
        if (kk == EOF)
        {
            break;
        }
    }
    fclose(su);
    // char UserID[100];
    int cho;
    char ch;
    int k = 0;
    char Password[25];
    FILE *fptr;
    fptr = fopen("LoginSignupPage.txt", "r");
    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tWELCOME TO LOG IN ZONE");
    printf("\n\t\t\t\t\t\t\t\t**********************");
    for (int i = 0; i < 100; i++)
    {
        printf("\033[1;32m\n\n\n\n\t\t\t\t\t\t\t\t ENTER USERNAME: ");
        scanf("%s", &UserID);
        fflush(stdin);

        if (check_ban(UserID, ban_arr, zeo) == 1)
        {
            printf("\033[7;31m\t\t\t\t\t\t\t\tTHIS ID IS BANNED\033[1;0m");
            Sleep(1000);
            login();
        }
        printf("\033[1;33m\n\n\t\t\t\t\t\t\t\t ENTER PASSWORD: \033[1;0m");
        while ((ch = getch()) != 13)
        {
            Password[k++] = ch;
            printf("%c", '*');
        }
        Password[k] = '\0';
        int check1, check2;
        int count = countuser();
        int j;
        while (!feof(fptr))
        {
            for (j = 0; j < count; j++)
            {
                check1 = strcmp(UserID, up[j].UserID);
                if (check1 == 0)
                    break;
            }
            check2 = strcmp(Password, up[j].Password);
            if (check1 == 0 && check2 == 0)
            {
                system("CLS");
                printf("\033[1;32m\n\n\n\t\t\tYOU HAVE LOGGED IN SUCCESSFULLY!!");
                printf("\033[1;36m\n\n\n\t\t\t\tWELCOME,ENJOY LEARNING\033[1;0m");
                Sleep(950);
                mainmenu();
                break;
            }
            else if (check1 == 0 && check2 != 0)
            {
                printf("\033[1;31m\n\n\n\t\t\t\t\t\t\t      WRONG PASSWORD!! Not \033[1;36m%s??\033[1;0m", UserID);
                printf("\033[1;33m\n\n Press \n'1' to re-login \n'2' if you have forgotten the password \n'3' if you want to re-registar\n'4' if you want to go to Main Section\n'5' if you want to EXIT\n\033[1;0m");
            S3:
                scanf("%d", &cho);
                if (cho == 1)
                {
                    system("CLS");
                    login();
                }
                else if (cho == 2)
                    forgotpassword();
                else if (cho == 3)
                {
                    system("CLS");
                    reg();
                }
                else if (cho == 4)
                {
                    system("CLS");
                    loginregisterpage();
                }
                else if (cho == 5)
                {
                    system("CLS");
                    printf("\033[1;31m\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tExited\n\n\n\n\n\n\033[1;0m");
                    exit(0);
                }
                else
                {
                    printf("\n\n\n Invalid Input , Re-enter the choice:");
                    goto S3;
                }
            }
            else if (check1 != 0)
            {
            Adarsh:
                printf("\n\n\n\t\t\tYou are not a Registered User\n\n \t\t\tPress '1' to register yourself.\n\t\t\tPress '2' to re-login.\n\t\t\tPress '3' to redirect to Main Section\n\t\t\t ");
                int w;
                scanf("%d", &w);
                if (w == 1)
                {
                    system("CLS");
                    reg();
                }
                else if (w == 2)
                {
                    system("CLS");
                    login();
                }
                else if (w == 3)
                {
                    system("CLS");
                    loginregisterpage();
                }
                else
                {
                    printf("\n\n\n Invalid Input , Re-enter the choice:");
                    goto Adarsh;
                }
            }
            break;
        }
        getch();
    }
    fclose(fptr);
}

int check_ban(char id[], banned ban_arr[], int i)
{

    for (int k = 0; k < i; k++)
    {
        if (strcmp(id, ban_arr[k].ban_id) == 0)
        {

            return 1;
        }
    }
    return 0;
}
void reg()
{
    system("CLS");
    char check[30];
    char ch;
    FILE *fptr2;
    fptr2 = fopen("LoginSignupPage.txt", "a+");

    printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tWELCOME TO REGISTER ZONE");
    printf("\n\t\t\t\t\t\t\t\t*************************");

    for (int i = 0; i < 100; i++)
    {
        printf("\033[1;32m\n\n\n\n\t\t\t\t\t\t\t\t  ENTER USERNAME: \033[1;0m");
        scanf("%s", &check);
        int count1 = countuser();
        for (int j = 0; j <= count1; j++)
        {

            if (strcmp(check, up[j].UserID) == 0)
            {
                printf("\033[1;31m\n\n\t\t\t\t\t\tUSERNAME ALREDY EXISTS\tTry logging in again...or change your Password\033[1;0m");
                Sleep(1000);
                // system("CLS");
            xy:
                printf("\033[1;0m\n\n\t\t\t\t\t\t\t\tPress\n\t\t\t\t\t\t\t\t'1' to try re-registering using a new user ID \n\t\t\t\t\t\t\t\t'2' to go to login page\n\t\t\t\t\t\t\t\t'3' to go to Main Section\n\t\t\t\t\t\t\t\t'4' to Exit\033[1;0m");
                int x;
                scanf("%d", &x);
                if (x == 1)
                {
                    reg();
                }
                else if (x == 2)
                {
                    login();
                }
                else if (x == 3)
                {
                    loginregisterpage();
                }
                else if (x == 4)
                {
                    system("CLS");
                    printf("\033[1;31m\n\n\n\n\n\n\t\t\t\t\t\t\t\t\tExited\n\n\n\n\n\n\033[1;0m");
                    exit(0);
                }
                else
                {
                    printf("Invalid Input , Re-enter your choice");
                    goto xy;
                }
                system("CLS");
                login();
            }
        }
        strcpy(up[count1].UserID, check);
        printf("\n\n\t\t\t\t\t\t\t\t  NEW PASSWORD: ");
        int k = 0;
        while ((ch = getch()) != 13)
        {
            up[count1].Password[k++] = ch;
            printf("%c", '*');
        }
        fprintf(fptr2, "\n%s ", up[count1].UserID);
        fprintf(fptr2, "%s\n", up[count1].Password);
        fclose(fptr2);
        printf("\033[0;36m\n\n\t\t\t\t\t\t    Press enter if you agree with Username and Password");
        if ((ch = getch()) == 13)
        {
            system("CLS");
            printf("\033[1;32m\n\n\t\tYou are successfully registered");
            printf("\n\n\n\n\n\t\t\t\t\t\t\t~~~~THANK YOU FOR REGISTERING~~~~");
            Sleep(2000);
            system("CLS");
            loginregisterpage();
        }
        break;
    }
    getch();
}
void forgotpassword()
{
    system("CLS");
    printf("\033[1;32mEnter your UserID: ");
    scanf("%s", &UserID);
    int count = countuser();
    int i, k;
    for (i = 0; i < count; i++)
    {
        k = strcmp(UserID, up[i].UserID);
        if (k == 0)
        {
            break;
        }
    }
    if (k != 0)
    {
        system("CLS");
        printf("\033[1;33m\n\nUser Not found.\n\n\n\n\n\n\t\t\t\t\t\t\t\tReturning to Main Screen....\n\033[1;0m");
        Sleep(1000);
        loginregisterpage();
    }
    changePassword(i);
}
int countuser()
{
    FILE *fp;
    fp = fopen("LoginSignupPage.txt", "r");
    char ch[100];
    int count = -1;
    int a = 0;
    for (int i = 0; a != EOF; i++)
    {
        char garbage[100];
        a = fscanf(fp, "%s", &ch);
        fscanf(fp, "%s", &garbage);
        count++;
    }
    fclose(fp);
    return count;
}

void collegepredictor()
{
    st:
    system("cls");
    
    printf("\033[1;36m\t\t\t\t\t\t\t\t~~~~COLLEGE PREDICTOR~~~~\n\n\033[1;0m");
    int rank;
    printf("ENTER THE JEE ADVANCE RANK(Category) : ");
    scanf("%d", &rank);
    if (rank<=0){
        printf("INVALID INPUT \n Re-enter your choice: ");
        sleep(2);
        goto st;
    }
    int g;
    printf("\033[1;32m\nENTER THE GENDER\n");
    printf("\033[1;36m\t\t\tENTER 1 FOR MALE\n");
    printf("\033[1;35m\t\t\tENTER 0 FOR FEMALE\n\033[1;0m");
    printf("ENTER:");
    scanf("%d", &g);
    char *gender;
    if (g == 1)
    {
        gender = "Gender-Neutral";
    }
    else if (g == 0)
    {
        gender = "Female-Only";
    }
    else
    {
        printf("\033[1;31mGender not recognized\n\033[1;0m");
        sleep(2);
        goto st;
    }

    int c;
pt:
    printf("\n\nENTER THE CATEGORY \n");
    printf("\033[0;33m\t\t\tENTER 1 FOR GEN \n");
    printf("\033[0;33m\t\t\tENTER 2 FOR GEN-EWS\n");
    printf("\033[0;33m\t\t\tENTER 3 FOR OBC-NCL\n");
    printf("\033[0;33m\t\t\tENTER 4 FOR SC\n");
    printf("\033[0;33m\t\t\tENTER 5 FOR ST\n");
    printf("\033[0;33m\t\t\tENTER 6 FOR GEN-PWD\n");
    printf("\033[0;33m\t\t\tENTER 7 FOR SC-PWD\n");
    printf("\033[0;33m\t\t\tENTER 8 FOR ST-PWD\n");
    printf("\033[0;33m\t\t\tENTER 9 FOR OBC-NCL-PWD\n");
    printf("\033[0;33m\t\t\tENTER 10 FOR GEN-EWS-PWD\n\033[1;0m");
    printf("ENTER:");
    scanf("%d", &c);

    char *cat;

    switch (c)
    {
    case 1:
        cat = "GEN";
        break;
    case 2:
        cat = "GEN-EWS";
        break;
    case 3:
        cat = "OBC-NCL";
        break;
    case 4:
        cat = "SC";
        break;
    case 5:
        cat = "ST";
        break;
    case 6:
        cat = "GEN-PWD";
        break;
    case 7:
        cat = "SC-PWD";
        break;
    case 8:
        cat = "ST-PWD";
        break;
    case 9:
        cat = "OBC-NCL-PWD";
        break;
    case 10:
        cat = "GEN-EWS-PWD";
        break;
    default:
        printf("\033[1;31mUnrecognized\n\033[1;0m");
        sleep(2);
        goto pt;
        break;
    }

    FILE *ptr;

    ptr = fopen("branch.txt", "r");
    st a[1000];
    int number = 1;
    int kk = 0;
    for (int i = 0; 1; i++)
    {
        kk = fscanf(ptr, "%s", a[i].name);
        if (kk == EOF)
        {
            number = i;
            break;
        }
        fscanf(ptr, "%s", a[i].branch);
        fscanf(ptr, "%s", a[i].category);
        fscanf(ptr, "%s", a[i].gender);
        fscanf(ptr, "%d", &a[i].or);
        fscanf(ptr, "%d", &a[i].cr);
    }
    st b[1000];

    printf("\n\n");

    college(a, rank, gender, cat, b, number);

    fclose(ptr);
    int t;
    printf("\t\t\t\nDo you want to search more college(Yes=1 ,mainmenu=0) :");
    scanf("%d", &t);
    if (t > 1)
    {
        printf("\033[1;31m\t\t\tINVALID input !");
        sleep(2);
    }
    else if (t == 0)
    {
        mainmenu();
    }
    else{
        goto st;
    }
    system("cls");
}
void swap(st b[], int i, int j)
{
    st temp = b[i];
    b[i] = b[j];
    b[j] = temp;
}

int partition(st b[], int l, int r)
{
    st pivot = b[r];
    int i = l - 1;

    for (int j = l; j < r; j++)
    {
        if (b[j].cr < pivot.cr)
        {
            i++;
            swap(b, i, j);
        }
    }
    swap(b, i + 1, r);
    return i + 1;
}

void quicksort(st a[], int l, int r)
{
    if (l < r)
    {
        int pi = partition(a, l, r);
        quicksort(a, l, pi - 1);
        quicksort(a, pi + 1, r);
    }
}
int college(st a[], int rank, char *gender, char *cat, st b[], int number)
{
    int j = 0;

    for (int i = 0; i < number; i++)
    {
        if (rank <= a[i].cr && compare(a[i].category, cat) == true && compare(gender, a[i].gender) == true)
        {
            b[j] = a[i];
            j++;
        }
    }
    quicksort(b, 0, j - 1);
    for (int i = 0; i < j; i++)
    {
        printf("%s\t\t   %s\t\t\t\t\t\t\t\t\t\t\n   %s\t  %s\t  opening rank=%d\t  closing rank=%d\n\n\n", b[i].name, b[i].branch, b[i].category, b[i].gender, b[i].or, b[i].cr);
    }
}

void rankpredictor()
{
    system("cls");
    printf("\t\t\t\t\t\t\t\t\033[1;33m~~~~~~~ RANK PREDICTOR ~~~~~~~");
    int markslow[17];
    int markshigh[17];
    int ranklow[17];
    int rankhigh[17];
    FILE *fp;
    fp = fopen("rank.txt", "r");
    for (int i = 0; i < 17; i++)
    {
        fscanf(fp, "%d", &markshigh[i]);
        fscanf(fp, "%d", &markslow[i]);
        fscanf(fp, "%d", &rankhigh[i]);
        fscanf(fp, "%d", &ranklow[i]);
    }
    fclose(fp);
    int n;
    int flag = 0;
Rank:
    printf("\n\n\n\n\033[1;34mEnter marks :\033[1;0m");
    scanf("%d", &n);
    if (n > 360)
    {
        printf("\n\n\n\n\033[1;31mINVALID INPUT ! Please enter again");
        goto Rank;
    }
    int i;
    for (i = 0; i < 17; i++)
    {
        if (n <= markshigh[i] && n >= markslow[i])
        {
            flag++;
            break;
        }
    }
    if (flag > 0)
    {
        printf("\n\n~~~~\033[3;32mYour predicted rank according to 2022 data is in between %d - %d~~~~\033[1;0m\n\n", rankhigh[i], ranklow[i]);
    }
    else if (flag == 0)
    {
        printf("\033[1;31mNo Eligible Rank.\n\nMarks too less.\n\n\033[1;0m");
    }
    printf("Enter 1 to return to main menu or 0 to search again\n");
    int x;
XY:
    scanf("%d", &x);
    if (x == 1)
    {
        mainmenu();
    }
    else if (x == 0)
    {
        goto Rank;
    }
    else
    {
        printf("\033[1;31mINVALID INPUT !!Please enter again\033[1;0m\n");
        goto XY;
    }
}
void collegedetails()
{
    system("cls");
    int n;
    int t = 1;
    int i = 0;
    fp = fopen("data.txt", "r");
    f(23)
    {
        fscanf(fp, "%s", &collegedet[i].co);
        fscanf(fp, "%d", &collegedet[i].nr);
        fscanf(fp, "%d", &collegedet[i].yoe);
        fscanf(fp, "%s", &collegedet[i].state);
        fscanf(fp, "%d", &collegedet[i].fees);
        fscanf(fp, "%d", &collegedet[i].hf);
        fscanf(fp, "%f", &collegedet[i].disf);
        fscanf(fp, "%f", &collegedet[i].disr);
        fscanf(fp, "%f", &collegedet[i].high);
        fscanf(fp, "%f", &collegedet[i].avg);
    }
    fclose(fp);
    while (t)
    {

        printline();
        printf("\033[4;34m\t\t\t\t\t||\t\t\t\t! WELCOME !\t\t\t\t\t||\n\033[1;0m");
        printf("\033[1;31m\t\t\t\t\t||\t\t\t!!Please select college!!\t\t\t\t||\n\033[1;0m");
        printline();
        printf("\t\t\t\t\t||\t\t\t\033[1;33m__________________________________\033[1;0m\t\t\t||\n");
        printf("\t\t\t\t\t||\t\t\t|\tcollege name     | Number|\t\t\t||\n");
        printf("\t\t\t\t\t||\t\t\t|\033[1;33m________________________|_______|\033[1;0m\t\t\t||\n");
        printf("\t\t\t\t\t||\t\t\t|\t\033[1;33mIIT MADRAS       \033[1;0m|\033[1;34m  1    \033[1;0m|\t\t\t||\n");
        printf("\t\t\t\t\t||\t\t\t|\t\033[1;33mIIT BOMBAY       \033[1;0m|\033[1;34m  2    \033[1;0m|\t\t\t||\n");
        printf("\t\t\t\t\t||\t\t\t|\t\033[1;33mIIT DELHI        \033[1;0m|\033[1;34m  3    \033[1;0m|\t\t\t||\n");
        printf("\t\t\t\t\t||\t\t\t|\t\033[1;33mIIT KANPUR       \033[1;0m|\033[1;34m  4    \033[1;0m|\t\t\t||\n");
        printf("\t\t\t\t\t||\t\t\t|\t\033[1;33mIIT KHARAGPUR    \033[1;0m|\033[1;34m  5    \033[1;0m|\t\t\t||\n");
        printf("\t\t\t\t\t||\t\t\t|\t\033[1;33mIIT ROORKEE      \033[1;0m|\033[1;34m  6    \033[1;0m|\t\t\t||\n");
        printf("\t\t\t\t\t||\t\t\t|\t\033[1;33mIIT GUWAHATI     \033[1;0m|\033[1;34m  7    \033[1;0m|\t\t\t||\n");
        printf("\t\t\t\t\t||\t\t\t|\t\033[1;33mIIT HYDRABAD     \033[1;0m|\033[1;34m  8    \033[1;0m|\t\t\t||\n");
        printf("\t\t\t\t\t||\t\t\t|\t\033[1;33mIIT VARANASI     \033[1;0m|\033[1;34m  9    \033[1;0m|\t\t\t||\n");
        printf("\t\t\t\t\t||\t\t\t|\t\033[1;33mIIT DHANBAD      \033[1;0m|\033[1;34m  10   \033[1;0m|\t\t\t||\n");
        printf("\t\t\t\t\t||\t\t\t|\t\033[1;33mIIT INDOR        \033[1;0m|\033[1;34m  11   \033[1;0m|\t\t\t||\n");
        printf("\t\t\t\t\t||\t\t\t|\t\033[1;33mIIT MANDI        \033[1;0m|\033[1;34m  12   \033[1;0m|\t\t\t||\n");
        printf("\t\t\t\t\t||\t\t\t|\t\033[1;33mIIT ROPAR        \033[1;0m|\033[1;34m  13   \033[1;0m|\t\t\t||\n");
        printf("\t\t\t\t\t||\t\t\t|\t\033[1;33mIIT GANDHINAGAR  \033[1;0m|\033[1;34m  14   \033[1;0m|\t\t\t||\n");
        printf("\t\t\t\t\t||\t\t\t|\t\033[1;33mIIT JODHPUR      \033[1;0m|\033[1;34m  15   \033[1;0m|\t\t\t||\n");
        printf("\t\t\t\t\t||\t\t\t|\t\033[1;33mIIT PATNA        \033[1;0m|\033[1;34m  16   \033[1;0m|\t\t\t||\n");
        printf("\t\t\t\t\t||\t\t\t|\t\033[1;33mIIT BHUBANESWAR  \033[1;0m|\033[1;34m  17   \033[1;0m|\t\t\t||\n");
        printf("\t\t\t\t\t||\t\t\t|\t\033[1;33mIIT TIRUPATI     \033[1;0m|\033[1;34m  18   \033[1;0m|\t\t\t||\n");
        printf("\t\t\t\t\t||\t\t\t|\t\033[1;33mIIT PALAKKAD     \033[1;0m|\033[1;34m  19   \033[1;0m|\t\t\t||\n");
        printf("\t\t\t\t\t||\t\t\t|\t\033[1;33mIIT JAMMU        \033[1;0m|\033[1;34m  20   \033[1;0m|\t\t\t||\n");
        printf("\t\t\t\t\t||\t\t\t|\t\033[1;33mIIT DHARWAD      \033[1;0m|\033[1;34m  21   \033[1;0m|\t\t\t||\n");
        printf("\t\t\t\t\t||\t\t\t|\t\033[1;33mIIT BHILAI       \033[1;0m|\033[1;34m  22   \033[1;0m|\t\t\t||\n");
        printf("\t\t\t\t\t||\t\t\t|\t\033[1;33mIIT GOA          \033[1;0m|\033[1;34m  23   \033[1;0m|\t\t\t||\n");
        printf("\t\t\t\t\t||\t\t\t|\t\033[1;31mExit             \033[1;0m|  \033[1;34m24   \033[1;0m|\t\t\t||\n");
        printf("\t\t\t\t\t||\t\t\t|________________________|_______|\t\t\t||\n\n");
        printline();
        printf("\033[1;37m\t\t\t\t\t\t\t\tPrint list according to average package = 25\n\033[1;0m");
        printline();
        for (i = 1; i > 0; i++)
        {
            printf("\t\t\t\t\tEnter your choice :");
            scanf("%d", &n);
            printline();
            if (n < 26 && n != 0)
            {
                break;
            }
            else
            {
                printf("\033[1;31m\t\t\t\t\tINVALID INPUT !!Please enter again !\n\033[1;0m");
                continue;
            }
        }
        if (n == 25)
        {
            sort();
        }
        else
        {
            printcol(n);
        }
        printf("\033[1;32m\t\t\t\t\t\nDo you want to search more college(Yes=1 ,mainmenu=0) :\033[1;0m");
        scanf("%d", &t);
        if (t > 1)
        {
            printf("\033[1;31m\t\t\t\t\tINVALID input !\033[1;0m");
        }
        else if (t == 0)
        {
            mainmenu();
        }
        system("cls");
    }
}
int printcol(int n)
{
    if (n == 24)
    {
        printf("\t\t\t\t\033[1;31m\t\t\t\t\tEXITED\033[1;0m");
        mainmenu();
    }
    else
    {
        printf("\t\t\t\t\t\t\t\033[1;34mcollege                                \033[1;0m- \033[1;35mIIT %s\n\033[1;0m", collegedet[n - 1].co);
        printf("\t\t\t\t\t\t\t\033[1;34mNIRF Ranking (2022)                    \033[1;0m- \033[1;35m%d\n\033[1;0m", collegedet[n - 1].nr);
        printf("\t\t\t\t\t\t\t\033[1;34mYear of establishment                  \033[1;0m- \033[1;35m%d\n\033[1;0m", collegedet[n - 1].yoe);
        printf("\t\t\t\t\t\t\t\033[1;34mState                                  \033[1;0m- \033[1;35m%s\n\033[1;0m", collegedet[n - 1].state);
        printf("\t\t\t\t\t\t\t\033[1;34mFees for 1 semester (2022)             \033[1;0m- \033[1;35m%d\n\033[1;0m", collegedet[n - 1].fees);
        printf("\t\t\t\t\t\t\t\033[1;34mHostel fees For one semester           \033[1;0m- \033[1;35m%d\n\033[1;0m", collegedet[n - 1].hf);
        printf("\t\t\t\t\t\t\t\033[1;34mDistance from nearest airport          \033[1;0m- \033[1;35m%.1fkm\n\033[1;0m", collegedet[n - 1].disf);
        printf("\t\t\t\t\t\t\t\033[1;34mDistance from nearest railway station  \033[1;0m- \033[1;35m%.1fkm\n\033[1;0m", collegedet[n - 1].disr);
        printf("\t\t\t\t\t\t\t\033[1;34mHighest Package                        \033[1;0m- \033[1;35m%.1fLPA\n\033[1;0m", collegedet[n - 1].high);
        printf("\t\t\t\t\t\t\t\033[1;34mAverage Package                        \033[1;0m- \033[1;35m%.1fLPA\n\033[1;0m", collegedet[n - 1].avg);
        printf("\t\t\033[1;31m\t\t\t\t\tPLEASE NOTE THAT 0 is for not available and (LPA=lakh per annum)\n\033[1;0m");
        printline();
        return 0;
    }
}

void printline()
{
    f(5)
    {
        printf("\t");
    }
    f(82)
    {
        printf("=");
    }
    printf("\n");
}

void sort()
{
    system("cls");
    int i, j, num = 23;
    float arr[23][2], temp;
    f(num)
    {
        arr[i][0] = collegedet[i].avg;
        arr[i][1] = i;
    }
    for (i = 0; i < num - 1; i++)
    {
        for (j = 0; j < num - i - 1; j++)
        {
            if (arr[j][0] < arr[j + 1][0])
            {
                temp = arr[j][0];
                arr[j][0] = arr[j + 1][0];
                arr[j + 1][0] = temp;
                temp = arr[j][1];
                arr[j][1] = arr[j + 1][1];
                arr[j + 1][1] = temp;
            }
        }
    }
    printline();
    for (i = 0; i < num; i++)
    {
        int k = arr[i][1];
        printf("\t\t\t |%d\t|", i + 1);
        printf("\t%s          - \t\t\t%.2f  LPA\t\t|\n", collegedet[k].co, arr[i][0]);
    }
    printline();
    printf("\t\t\t|\tPLEASE NOTE THAT 0 is for not available and (LPA=lakh per annum)\t|\n");
    printline();
}

void mycourses()
{

    system("cls");
    int n;
    printf("\033[1;35m\t\t\t\t\t  ================================\n\033[1;0m");
    printf("\t\t\t\t\t|| \033[1;31mJEE CRASH COURSES FOR JEE 2024 \033[1;0m||\n");
    printf("\033[1;35m\t\t\t\t\t  ================================\n\033[1;0m");
    printf("\033[1;32mPress any key to continue:\033[1;0m");
    getch();
    system("cls");

S1:
    printf("\033[1;32m\t\t\t1.Pathshala JEE Fastrack Course\n");
    printf("\033[1;33m\t\t\t2.Pathshala DROPPER JEE 2024\n\033[1;0m");
    printf("\033[1;31m\t\t\t3.EXIT \n\033[1;0m");
    printf("enter your choice to know the courses duration, validity and payment:\n");
    scanf("%d", &n);
    system("cls");
    switch (n)
    {
    case 1:
    {
        printf("\033[1;34mcourse duration: 12 months\n");
        printf("\033[1;34mcourse price: 5000/- only\ntarget:JEE ADVANCED\n\033[1;0m");
        int a;
        printf("enter key 1 for payment or press 0 to go back to the menu:\n");
        scanf("%d", &a);
        system("cls");
        switch (a)
        {
        case 0:
        {
            mainmenu();
            break;
        }
        case 1:
        {
            printf("\033[1;32mpayment is done succesfully!!!\n\033[1;0m");
            int happyASCII = 1, i;
            printf("\033[1;33m%c\033[1;0m", happyASCII);
            getch();
        }
        default:
        {
            getch();
            goto S1;
        }
        }
        break;
    }
    case 2:
    {
        printf("\033[1;34mcourse duration: 12 months\n");
        printf("\033[1;34mcourse price: 5000/- only\ntarget:JEE ADVANCED\n\033[1;0m");
        int a;
        printf("enter key 1 for payment or press 0 to go back to the menu:\n");
        scanf("%d", &a);
        switch (a)
        {
        case 0:
        {
            mainmenu();
            break;
        }
        case 1:
        {
            printf("\033[1;32mpayment is done succesfully!!!\n\033[1;0m");
            int happyASCII = 1, i;
            printf("\033[1;33m%c\033[1;0m", happyASCII);
            break;
        }
        default:
        {
            getch();
            goto S1;
        }
        }
        break;
    }
    case 3:
    {
        mainmenu();
    }
    default:
    {
        printf("\033[1;31menter valid input:\n\033[1;0m");
        goto S1;
    }
    }
}
void mocktest()
{
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 0; j < 18; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                ansinput1[i - 1].mat[j][k] = 'z';
                anssaved1[i - 1].mat[j][k] = 'z';
                ansinput2[i - 1].mat[j][k] = 'z';
                anssaved2[i - 1].mat[j][k] = 'z';
            }
        }
    }
    char ch;
    char ex;
    int arr[10] = {};
    FILE *fp;
    fp = fopen("MockTest.txt", "r");
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            fscanf(fp, "%c ", &ch);
            anssaved1[i].sat[j] = ch;
        }
        for (int j = 0; j < 18; j++)
        {
            fscanf(fp, "%s", &anssaved1[i].mat[j]);
        }
        for (int j = 0; j < 6; j++)
        {
            fscanf(fp, "%d", &anssaved1[i].itype[j]);
        }
        for (int j = 0; j < 12; j++)
        {
            fscanf(fp, "%f", &anssaved1[i].numer[j]);
        }
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            fscanf(fp, "%c ", &ch);
            anssaved2[i].sat[j] = ch;
        }
        for (int j = 0; j < 18; j++)
        {
            fscanf(fp, "%s", &anssaved2[i].mat[j]);
        }
        for (int j = 0; j < 6; j++)
        {
            fscanf(fp, "%d", &anssaved2[i].itype[j]);
        }
        for (int j = 0; j < 12; j++)
        {
            fscanf(fp, "%f", &anssaved2[i].numer[j]);
        }
    }
    fclose(fp);
    system("CLS");

    printf("\033[1;33m\t\t\t\t\t======================================================================================\033[1;0m");
    printf("\033[1;32m\n\n\t\t\t\t\t\t\t\t\t1.Mocktest of PYQs\n");
    printf("\033[1;33m\t\t\t\t\t======================================================================================\033[1;0m");
    printf("\n\n\t\t\t\tEnter your choice:");
    int choice;
some:
    scanf("%d", &choice);

    if (choice == 1)
    {
        system("CLS");
        mockpyqs();
    }
    // else if (choice == 0)
    // {
    //     system("CLS");
    //     // createtest();
    // }

    else
    {
        printf("\033[1;31m\n\n\t\t\t\t\tINVALID CHOICE\033[1;0m");
        printf("\n\t\t\t\t\tRe-Enter your choice: ");
        goto some;
    }
}
void mockpyqs()
{
    FILE *pp;
    pp = fopen("paper.txt", "r");
    int z, co = -1;
    char chh[100];
    while (1)
    {
        z = fscanf(pp, "%s", &chh);
        co++;
        if (z == EOF)
        {
            break;
        }
    }
    int i;
adar:
    printf("\033[1;32m\n\n\n\n\t\t\t\t\t======================================================================================\033[1;0m");
    for (i = 1; i <= co / 2; i++)
    {
        if (i + 2 < 10)
        {
            printf("\033[1;34m\n\t\t\t\t\t\t\t\t\t%d. 201%d", i, i + 2);
        }
        else if (i == 8 || i == 9)
        {
            printf("\033[1;34m\n\t\t\t\t\t\t\t\t\t%d. 20%d", i, i + 12);
        }
        else
            printf("\033[1;34m\n\t\t\t\t\t\t\t\t\t%d.20%d", i, i + 12);
    }
    printf("\033[1;34m\n\t\t\t\t\t\t\t\t\t%d.Back to Main Menu", i++);
    printf("\033[1;34m\n\t\t\t\t\t\t\t\t\t%d.Back to previous Menu\n\n\033[1;0m", i);
    printf("\033[1;32m\t\t\t\t\t======================================================================================\033[1;0m");
    printf("\n\n\t\t\t\t\t\t\t\t\tEnter your choice: ");
    int choice;
    scanf("%d", &choice);
    printf("\n\nPress the below link to get to the question paper:\n");

    FILE *pap;
    pap = fopen("paper.txt", "r");

    int a = 0;
    i = 0;
    while (1)
    {
        if (i > (co / 2) - 1)
            break;
        a = fscanf(pap, "%s", pep[i].p1);
        a = fscanf(pap, "%s", pep[i].p2);
        i++;
    }
    printf("\n");
    for (i = 0; i < co; i++)
    {
        if (choice - 1 == i)
        {
            printf("%s\n", pep[i].p1);
            printf("%s\n", pep[i].p2);
        }
    }

    fclose(pap);
    int counte=0;
adars:
    printf("\nPress \n'1' for paper 1\n'2' for paper 2\n'3' to re-enter your choice:\n'4' for mainmenu \n");
    int non;
    scanf("%d", &non);
    int mark1 = min, mark2 = min;
    if (non == 1)
    {
        counte++;
    ada1:
        printf("As soon as you press Enter your time starts:");
        time_t begin = time(NULL);
         ss:
        if (getch() == 13)
        {
        }
        else
        {
            goto ss;
        }
        answering(choice, 0, ansinput1, begin);
        Sleep(1000);
        system("CLS");

        answering(choice, 1, ansinput1, begin);
        Sleep(1000);
        system("CLS");

        answering(choice, 2, ansinput1, begin);
        Sleep(1000);
        system("CLS");
        mark1 = marks(choice, ansinput1, anssaved1);
    }
    else if (non == 2)
    {
        counte++;
ada2:
    printf("As soon as you press Enter your time starts:");
    time_t begin = time(NULL);
    ss2:
    if (getch() == 13)
    {
    }
    else
    {
        goto ss2;
    }
        answering(choice, 0, ansinput2, begin);
        Sleep(1000);
        system("CLS");

        answering(choice, 1, ansinput2, begin);
        Sleep(1000);
        system("CLS");

        answering(choice, 2, ansinput2, begin);
        Sleep(1000);
        system("CLS");
        mark2 = marks(choice, ansinput2, anssaved2);
    }
    else if (non == 3)
    {
        goto adar;
    }
    else if (non == 4)
    {
        mainmenu();
    }
    else
    {
        printf("INVALID INPUT\nRe-enter your choice:");
        goto adars;
    }

    Sleep(100);
    
axis:
    int tot;
    if (counte==2){
        tot = mark1 + mark2;
        printf("\nThe marks you scored are: %d\n", tot);
        rank(choice, tot);
    }
    printf("Do you want to continue with the other paper: \nif 'Yes' press 0;\n Press\n '1' to calculate your marks and rank\n '2' to go to the main menu \n ");
    int y;
    fflush(stdin);
    scanf("%d", &y);
    fflush(stdin);
    if (y == 0 && non == 1)
    {
        goto ada2;
    }
    else if (y == 0 && non == 2)
    {
        goto ada1;
    }
    else if (y == 1)
    {
        if (mark1 == min && mark2 != min)
        {
            tot = mark2 * 2;
        }
        else if (mark1 != min && mark2 == min)
        {
            tot = mark1 * 2;
        }
        else if (mark1 != min && mark2 != min)
        {
            tot = mark1 + mark2;
        }
        printf("\nThe marks you scored are: %d\n", tot);
        rank(choice, tot);
    }
    else if (y == 2)
    {
        mainmenu();
    }
    else
    {
        printf("\tINVALID INPUT\nRe-enter your choice: ");
        goto axis;
    }
}
int timer(time_t begin)
{
    time_t end = time(NULL);
    int tl = (end - begin);
    int sec = tl % 60;
    int minu = sec / 60;
    int hre = minu / 60;
    minu = minu - hre * 60;
    if (minu == 3)
    {
        return -1;
    }
    if (60 - sec < 10)
    {
        printf("\t\t\t\t\t\t\t\tRemaining time is 0%d:%d:0%d", 2 - hre, 59 - minu, 59 - sec);
    }
    else if (59 - minu < 10)
    {
        printf("\t\t\t\t\t\t\t\tRemaining time is 0%d:0%d:%d", 2 - hre, 59 - minu, 59 - sec);
    }
    else if (60 - sec < 10 && 59 - minu < 10)
    {
        printf("\t\t\t\t\t\t\t\tRemaining time is 0%d:0%d:0%d", 2 - hre, 59 - minu, 59 - sec);
    }
    else
    {
        printf("\t\t\t\t\t\t\t\tRemaining time is 0%d:%d:%d", 2 - hre, 59 - minu, 59 - sec);
    }
    return 0;
}
void answering(int choice, int k, struct answers anss[], time_t begin)
{
    int checko = timer(begin);
    system("CLS");
    printf("\033[1;35m\n======================================================================================\033[1;0m");
    if (k == 0)
    {
        printf("\n\t\t\t\tPhysics:");
    }
    else if (k == 1)
    {
        printf("\n\t\t\t\tChemistry:");
    }
    else if (k == 2)
    {
        printf("\n\t\t\t\tMaths:");
    }
    printf("\033[1;35m\n======================================================================================\033[1;0m");
    char s;
    char ch;
    int in;
    float num;
    fflush(stdin);
    printf("\033[4;31m\n\n\t\t\t\tSECTION 1\n\033[1;0m");
    printf("\033[1;33m\n\t\t\tSingle Answer type questions:(4) \n\033[1;0m");
    for (int i = 0; i < 4; i++)
    {   int checko = timer(begin);
        if (checko == -1)
        {
        sss1:
            printf("\n\t\t\t\t\t\tYour time has ended.");
            printf("\t\t\t\t\t\tPress Enter to proceed.");
            if (getch() == 13)
            {
                return;
            }
            else
            {
                goto sss1;
            }
        }
        printf("\nQuestion %d: ", i + 1);
        scanf("%c", &s);
        anss[choice - 1].sat[i + k * 4] = s;
        fflush(stdin);
    }
    printf("\033[4;31m\n\n\t\t\t\tSECTION 2\n\033[1;0m");
    printf("\033[1;33m\n\t\t\tMultiple Answer type questions:(6) \n\033[1;0m");
    for (int i = 0; i < 6; i++)
    {
        
        int checko = timer(begin);
        if (checko == -1)
        {
        sss2:
            printf("\n\t\t\t\t\t\tYour time has ended.");
            printf("\t\t\t\t\t\tPress Enter to proceed.");
            if (getch() == 13)
            {
                return;
            }
            else
            {
                goto sss2;
            }
        }
        printf("\nQuestion %d: ", i + 1);
        scanf("%s", &anss[choice - 1].mat[i + k * 6]);
    }
    printf("\033[4;31m\n\n\t\t\t\tSECTION 3\n\033[1;0m");
    printf("\033[1;33m\n\t\t\tInteger Answer type questions:(3) \n\033[1;0m");
    for (int i = 0; i < 3; i++)
    {
        int checko = timer(begin);
        if (checko == -1)
        {
        sss3:
            printf("\n\t\t\t\t\t\tYour time has ended.");
            printf("\t\t\t\t\t\tPress Enter to proceed.");
            if (getch() == 13)
            {
                return;
            }
            else
            {
                goto sss3;
            }
        }
        printf("\nQuestion %d: ", i + 1);
        scanf("%d", &in);
        anss[choice - 1].itype[i + k * 3] = in;
        fflush(stdin);
    }
    printf("\033[4;31m\n\n\t\t\t\tSECTION 4\n\033[1;0m");
    printf("\033[1;33m\n\t\t\tNumerical Answer type questions:(3) \n\033[1;0m");
    for (int i = 0; i < 4; i++)
    {
        int checko = timer(begin);
        if (checko == -1)
        {
        sss4:
            printf("\n\t\t\t\t\t\tYour time has ended.");
            printf("\t\t\t\t\t\tPress Enter to proceed.");
            if (getch() == 13)
            {
                return;
            }
            else
            {
                goto sss4;
            }
        }
        printf("\nQuestion %d: ", i + 1);
        scanf("%f", &num);
        anss[choice - 1].numer[i + k * 4] = num;
        fflush(stdin);
    }
}
int marks(int choice, struct answers ansi[], struct answers anss[])
{
    float f;
    char ch;
    int sum = 0;
    int p;
    int count = 0;
    int rc = 0, wc = 0;
    for (int i = 0; i < 12; i++)
    {
        ch = ansi[choice - 1].sat[i];
        if (ch == anss[choice - 1].sat[i])
        {
            sum += 3;
        }
        else if (ch == 13)
        {
            sum += 0;
        }
        else
        {
            sum -= 1;
        }
    }
    for (int i = 0; i < 18; i++)
    {
        count = 0;
        rc = 0, wc = 0;
        for (int j = 0; j < 4; j++)
        {
            if (ansi[choice - 1].mat[i][j] == anss[choice - 1].mat[i][j])
            {
                if (anss[choice - 1].mat[i][j] == 'z')
                {
                    continue;
                }
                else
                {
                    rc++;
                }
            }
            else if (ansi[choice - 1].mat[i][j] != anss[choice - 1].mat[i][j])
                wc++;
        }
        for (int j = 0; j < 4; j++)
        {
            if (anss[choice - 1].mat[i][j] != 'z')
                count++;
        }
        if (wc > 0)
        {
            sum -= 2;
            continue;
        }
        else
        {
            if (rc == count)
                sum += 4;
            else
                sum += rc;
        }
    }
    for (int i = 0; i < 9; i++)
    {
        p = ansi[choice - 1].itype[i];
        if (p == anss[choice - 1].itype[i])
            sum += 4;
        else if (p == 13)
            sum += 0;
        else
            sum -= 1;
    }
    for (int i = 0; i < 12; i++)
    {
        f = ansi[choice - 1].numer[i];
        if (f == anss[choice - 1].numer[i])
            sum += 3;
    }
    return sum;
}
int rank(int choice, int marks)
{

    int markslow[17];
    int markshigh[17];
    int ranklow[17];
    int rankhigh[17];
    FILE *fp;

    fp = fopen("rank.txt", "r");
    for (int i = 0; i < 17; i++)
    {
        fscanf(fp, "%d", &markshigh[i]);
        fscanf(fp, "%d", &markslow[i]);
        fscanf(fp, "%d", &rankhigh[i]);
        fscanf(fp, "%d", &ranklow[i]);
    }
    fclose(fp);
    int n = marks;
    int flag = 0;
    int i;
    for (i = 0; i < 17; i++)
    {
        if (n <= markshigh[i] && n >= markslow[i])
        {
            flag++;
            break;
        }
    }
    if (flag > 0)
    {
        printf("\033[1;32mYour predicted rank according to 2022 data is in between %d - %d\n\033[1;0m", rankhigh[i], ranklow[i]);
    }
    else
    {
        printf("\033[1;31mNot eligible Marks!!\n\nPlease prefer taking drop!!\n\n\033[1;0m");
    }
    int power;
    printf("Press any key to escape:");
    getch();
}
void preptracker()
{
    system("CLS");
    printf("\033[4;34mWELCOME TO PREPARATION TRACKER\n\033[1;0m");
    int m;
    printf("\nEnter the number of topics you studied in math(Total 22 chapters):");
    scanf("%d", &m);
    fflush(stdin);
    printf("\n");
    sub math[m];
    for (int i = 0; i < m; i++)
    {
        printf("Enter the %d topic in math:", i + 1);
        gets(math[i].chapter);
        fflush(stdin);
        printf("Enter percentage coverage of this chapter:");
        scanf("%d", &math[i].percoverage);
        fflush(stdin);
        printf("How much difficulty you feel during attempting questions of this chapter(on the scale of 1-3):");
        scanf("%d", &math[i].hardness);
        fflush(stdin);
    }
    printf("\n\n");
    int p;
    printf("Enter the number of topics you studied in physics(Total 16 chapters):");
    scanf("%d", &p);
    fflush(stdin);
    printf("\n");
    sub phy[p];
    for (int i = 0; i < p; i++)
    {
        printf("Enter the %d topic in physics:", i + 1);
        gets(phy[i].chapter);
        fflush(stdin);
        printf("Enter percentage coverage of this chapter:");
        scanf("%d", &phy[i].percoverage);
        fflush(stdin);
        printf("How much difficulty you feel during attempting questions of this chapter(on the scale of 1-3):\n\n");
        scanf("%d", &phy[i].hardness);
        fflush(stdin);
    }
    printf("\n\n");
    int c;
    printf("Enter the number of topics you studied in chemistry(Total 26 chapters):");
    scanf("%d", &c);
    fflush(stdin);
    printf("\n");
    sub chem[c];
    for (int i = 0; i < c; i++)
    {
        printf("Enter the %d topic in chemistry:", i + 1);
        gets(chem[i].chapter);
        fflush(stdin);
        printf("Enter percentage coverage of this chapter:");
        scanf("%d", &chem[i].percoverage);
        fflush(stdin);
        printf("How much difficulty you feel during attempting questions of this chapter(on the scale of 1-3):");
        scanf("%d", &chem[i].hardness);
        fflush(stdin);
    }
    printf("\n\n");
    int summath = 0, sumphy = 0, sumchem = 0;
    for (int i = 0; i < m; i++)
    {
        summath = summath + math[i].percoverage;
    }
    printf("\033[1;32mTHE PERCENTAGE COVERAGE FOR MATH IS:%d\n\033[1;0m", summath / 22); // MATH HAS TOAL 22 CHAPTERS
    for (int i = 0; i < p; i++)
    {
        sumphy = sumphy + phy[i].percoverage;
    }
    printf("\033[1;32mTHE PERCENTAGE COVERAGE FOR PHYSICS IS:%d\n\033[1;0m", sumphy / 16); // PHY HAS TOTAL16 CHAPTERS
    for (int i = 0; i < c; i++)
    {
        sumchem = sumchem + chem[i].percoverage;
    }
    printf("\033[1;36mTHE PERCENTAGE COVERAGE FOR CHEM IS:%d\n\033[1;0m", sumchem / 26); // CHEM HAS 26 CHAPTERS
    printf("\n");
    printf("\033[1;34mYOUR TOTAL COVERAGE IS:%d\n\033[1;0m", (sumchem / 26 + sumphy / 16 + summath / 22));
    printf("\n\n");
    printf("\033[1;31mYOUR HARDEST TOPICS IN MATH ARE:\033[1;0m");
    for (int i = 0; i < m; i++)
    {
        if (math[i].percoverage >= 50 && math[i].hardness == 3)
        {
            puts(math[i].chapter);
        }
        else
        {
            printf("NA\n");
        }
    }
    if (m == 0)
    {
        printf("NA\n");
    }
    printf("\033[1;31mYOUR HARDEST TOPICS IN PHYSICS ARE:\033[1;0m");
    for (int i = 0; i < p; i++)
    {
        if (phy[i].percoverage >= 50 && phy[i].hardness == 3)
        {
            puts(phy[i].chapter);
        }
        else
        {
            printf("NA\n");
        }
    }
    if (p == 0)
    {
        printf("NA\n");
    }
    printf("\033[1;31mYOUR HARDEST TOPICS IN CHEMISTRY ARE:\033[1;0m");
    for (int i = 0; i < c; i++)
    {
        if (chem[i].percoverage >= 50 && chem[i].hardness == 3)
        {
            puts(chem[i].chapter);
        }
        else
        {
            printf("NA\n");
        }
    }
    if (c == 0)
    {
        printf("NA\n");
    }
    printf("\n");
    printf("\033[1;33mYOUR MODERATE CHAPTERS IN MATH ARE:\033[1;0m");
    for (int i = 0; i < m; i++)
    {
        if (math[i].percoverage >= 50 && math[i].hardness == 2)
        {
            puts(math[i].chapter);
        }
        else
        {
            printf("NA\n");
        }
    }
    if (m == 0)
    {
        printf("NA\n");
    }
    printf("\033[1;33mYOUR MODERATE CHAPTERS IN PHYSICS ARE:\033[1;0m");
    for (int i = 0; i < p; i++)
    {
        if (phy[i].percoverage >= 50 && phy[i].hardness == 2)
        {
            puts( phy[i].chapter);
        }
        else
        {
            printf("NA\n");
        }
    }
    if (p == 0)
    {
        printf("NA\n");
    }
    printf("\033[1;33mYOUR MODERATE CHAPTERS IN CHEMISTRY ARE:\033[1;0m");
    for (int i = 0; i < c; i++)
    {
        if (chem[i].percoverage >= 50 && chem[i].hardness == 2)
        {
            puts(chem[i].chapter);
        }
        else
        {
            printf("NA\n");
        }
    }
    if (c == 0)
    {
        printf("NA\n");
    }
    printf("\n");
    printf("\033[1;32mYOUR EASY CHAPTERS IN MATH ARE, COMPLETE TO 100 PERCENT:\033[1;0m");
    for (int i = 0; i < m; i++)
    {
        if (math[i].percoverage >= 50 && math[i].hardness == 1)
        {
            puts(math[i].chapter);
        }
        else
        {
            printf("NA\n");
        }
    }
    if (m == 0)
    {
        printf("NA\n");
    }
    printf("\033[1;32mYOUR EASY CHAPTERS IN PHYSICS ARE, COMPLETE TO 100 PERCENT:\033[1;0m");
    for (int i = 0; i < p; i++)
    {
        if (phy[i].percoverage >= 50 && phy[i].hardness == 1)
        {
            puts(phy[i].chapter);
        }
        else
        {
            printf("NA\n");
        }
    }
    if (p == 0)
    {
        printf("NA\n");
    }
    printf("\033[1;32mYOUR EASY CHAPTERS IN CHEMISTRY ARE, COMPLETE TO 100 PERCENT:\033[1;0m");
    for (int i = 0; i < c; i++)
    {
        if (chem[i].percoverage >= 50 && chem[i].hardness == 1)
        {
            puts(chem[i].chapter);
        }
        else
        {
            printf("NA\n");
        }
    }
    if (c == 0)
    {
        printf("NA\n");
    }
    printf("\n");
    printf("\033[1;34mTAKE A COURSE IN THESE CHAPTERS OF MATH:\033[1;0m");
    for (int i = 0; i < m; i++)
    {
        if (math[i].percoverage < 50)
        {
            puts(math[i].chapter);
        }
        else
        {
            printf("NA\n");
        }
    }
    if (m == 0)
    {
        printf("NA\n");
    }
    printf("\033[1;34mTAKE A COURSE IN THESE CHAPTERS OF PHYSICS:\033[1;0m");
    for (int i = 0; i < p; i++)
    {
        if (phy[i].percoverage < 50)
        {
            puts(phy[i].chapter);
        }
        else
        {
            printf("NA\n");
        }
    }
    if (p == 0)
    {
        printf("NA\n");
    }
    printf("\033[1;34mTAKE A COURSE IN THESE CHAPTERS OF CHEMISTRY:\033[1;0m");
    for (int i = 0; i < c; i++)
    {
        if (chem[i].percoverage < 50)
        {
            puts(chem[i].chapter);
        }
        else
        {
            printf("NA\n");
        }
    }
    if (c == 0)
    {
        printf("NA\n");
    }
    printf("\n");
    fflush(stdin);
    int xyz;
XY:
    printf("\nEnter 1 to return to main menu");
    scanf("%d", &xyz);
    if (xyz == 1)
    {
        mainmenu();
    }
    else
    {
        printf("\033[1;31mINVALID INPUT !! Please enter again\033[1;0m");
        goto XY;
    }
}
void otherresources()
{
    system("cls");
    struct Books Book1;
    struct Books Book2;
    struct Books Book3;
    struct Books Book4;
    struct Books Book5;
    struct Books Book6;
    struct Books Book7;
    struct Books Book8;
    struct Books Book9;
    struct Books Book10;
    struct Books Book11;
    struct Books Book12;
    struct Books Book13;
    struct Books Book14;
    struct Books Book15;

    strcpy(Book1.title, "\033[1;31mARIHANT VECTOR & 3D GEOMETRY\033[1;0m");
    strcpy(Book1.booklink, "\033[1;36mhttps://www.pdfdrive.com/download.pdf?id=176284536&h=f39ccc5a1b5a9024048265645ad30c7f&u=cache&ext=pdf\033[1;0m");
    strcpy(Book2.title, "\033[1;32mARIHANT INTEGRAL CALCULUS FOR JEE\033[1;0m");
    strcpy(Book2.booklink, "\033[1;36mhttps://www.pdfdrive.com/download.pdf?id=158561936&h=2074ec599d68479c06fc08067d95ca2a&u=cache&ext=pdf\033[1;0m");
    strcpy(Book3.title, "\033[1;33mARIHANT PLAY WITH GRAPH BOOK FOR JEE	\033[1;0m");
    strcpy(Book3.booklink, "\033[1;36mhttps://drive.google.com/uc?id=1dq6NawsLmxpmq3gCCmBI8DkOHHz_viZk&export=download\033[1;0m");
    strcpy(Book4.title, "\033[1;31mCENGAGE CHEMISTRY JEE BOOKS\033[1;0m");
    strcpy(Book4.booklink, "\033[1;36mhttps://drive.google.com/uc?id=1-s2VQe_NnnHaqA5JuRT1JP2Mz5tzTQoY&export=download\033[1;0m");
    strcpy(Book5.title, "\033[1;32mVK JAISWAL INORGANIC CHEMISTRY\033[1;0m");
    strcpy(Book5.booklink, "\033[1;36mhttps://www.pdfdrive.com/download.pdf?id=176214536&h=d7d773c60c1fa12f22c41703e1d8c010&u=cache&ext=pdf\033[1;0m");
    strcpy(Book6.title, "\033[1;33mMS CHOUHAN CHEMISTRY BOOK\033[1;0m");
    strcpy(Book6.booklink, "\033[1;36mhttps://www.pdfdrive.com/download.pdf?id=158469753&h=4eb49d826064b69a8a2b9361f46fc3b5&u=cache&ext=pdf\033[1;0m");
    strcpy(Book7.title, "\033[1;31mOP TANDON CHEMISTRY BOOKS FOR IIT\033[1;0m");
    strcpy(Book7.booklink, "\033[1;36mhttps://drive.google.com/uc?id=1SwfAIhFCjjAniu1lia-Ep49wu4q8fLYM&export=download\033[1;0m");
    strcpy(Book8.title, "\033[1;32mN AVASTHI PHYSICAL CHEMISTRY BOOK\033[1;0m");
    strcpy(Book8.booklink, "\033[1;36mhttps://drive.google.com/uc?id=1JcR3y1CHrCy3rNrwDXnZ-pGkfgkAILVS&export=download\033[1;0m");
    strcpy(Book9.title, "\033[1;33mDC PANDEY WAVES AND THERMODYNAMICS BOOK\033[1;0m");
    strcpy(Book9.booklink, "\033[1;36mhttps://www.pdfdrive.com/download.pdf?id=158546753&h=40751124dbf10628e9cd291da501db60&u=cache&ext=pdf\033[1;0m");
    strcpy(Book10.title, "\033[1;31mVISHAL JOSHI INORGANIC CHEMISTRY BOOK\033[1;0m");
    strcpy(Book10.booklink, "\033[1;36mhttps://www.pdfdrive.com/download.pdf?id=158393229&h=b86df4f4b0f3ddf6f6a5f298dc27dc22&u=cache&ext=pdf\033[1;0m");
    strcpy(Book11.title, "\033[1;32mL.A SENA PHYSICS BOOK FOR IIT JEE\033[1;0m	");
    strcpy(Book11.booklink, "\033[1;36mhttps://drive.google.com/uc?id=1NzOIkwW8OR5rNIr60fxaYtmUHGmrPbh8&export=download\033[1;0m");
    strcpy(Book12.title, "\033[1;33mSS KROTOV PHYSICS BOOK FOR IIT JEE\033[1;0m");
    strcpy(Book12.booklink, "\033[1;36mhttps://drive.google.com/file/d/12hMdN5X7LWsD_VPkfohvyeCgSMdM8Dg3/view?usp=sharing\033[1;0m");
    strcpy(Book13.title, "\033[1;31mI.E IRODOV PROBLEM IN GENERAL PHYSICS BOOK\033[1;0m");
    strcpy(Book13.booklink, "\033[1;36mhttps://drive.google.com/uc?id=0B_0oxH_pZb4mTk5xdGJUQnNOZ0U&export=download\033[1;0m");
    strcpy(Book14.title, "\033[1;32mWILEYS PROBLEMS IN MATHEMATICS BOOK FOR IIT JEE\033[1;0m");
    strcpy(Book14.booklink, "\033[1;36mhttps://www.pdfdrive.com/download.pdf?id=187564812&h=e2085b85105ffffd165ced2ca13a4f99&u=cache&ext=pdf\033[1;0m");
    strcpy(Book15.title, "\033[1;33mJD LEE CONCISE INORGANIC CHEMISTRY BOOK\033[1;0m");
    strcpy(Book15.booklink, "\033[1;36mhttps://www.pdfdrive.com/download.pdf?id=187541397&h=482bcd24c6f1b0465a19adccf2f528eb&u=cache&ext=pdf\033[1;0m");

    printBook_x(Book1);
    printBook_x(Book2);
    printBook_x(Book3);
    printBook_x(Book4);
    printBook_x(Book5);
    printBook_x(Book6);
    printBook_x(Book7);
    printBook_x(Book8);
    printBook_x(Book9);
    printBook_x(Book10);
    printBook_x(Book11);
    printBook_x(Book12);
    printBook_x(Book13);
    printBook_x(Book14);
    printBook_x(Book15);
    int xyz;
    printf("~~~~\033[4;35mbest youtube channels for jee preparation at full efficiency:----->>\n\n\n\033[1;0m");
    printf("for maths: \033[1;32mMohit tyagi IIT-JEE\033[1;0m\nyoutube channel link:\033[1;34mhttps://www.youtube.com/@MohitTyagi\n\n\033[1;0m");
    printf("for physics: \033[1;32mPhysics Galaxy & Physics Wallah\033[1;0m\nyoutube channel link 1:\033[1;34mhttps://www.youtube.com/@physicsgalaxyworld\033[1;0m\nyoutube channel link 2:\033[1;34mhttps://www.youtube.com/@PhysicsWallah\n\n\033[1;0m");
    printf("for chemistry: \033[1;32mMohit tyagi IIT-JEE\033[1;0m\nyoutube channel link:\033[1;34mhttps://www.youtube.com/@MohitTyagi\n\n\033[1;0m");
    printf("Enter 1 to return to main menu\n");
XY:
    scanf("%d", &xyz);
    if (xyz == 1)
    {
        mainmenu();
    }
    else
    {
        printf("\033[1;31mINVALID INPUT !! Please enter again\033[1;0m");
        goto XY;
    }
}
void printBook_x(struct Books book)
{
    printf("Book name : %s\n", book.title);
    printf("download link : %s\n\n", book.booklink);
}

void scheduler()
{
    takework();
Avik:
    system("cls");
    printf("\t\t\t\t\t\t\t\033[1;33m1.View Today's Scheduel\n\t\t\t\t\t\t\t2.Add new event\n\t\t\t\t\t\t\t\033[1;32m3.Delete event from existing list\n\t\t\t\t\t\t\t4.Return to main menu\033[1;0m");
    printf("\n\t\t\t\t\t\tEnter your choice :");
    int test, num;
    scanf("%d", &num);
    fflush(stdin);

    switch (num)
    {
    case 1:
    {
        system("cls");
        printwork();
        printf("\n");
        int so;
        printf("Press \n'1' to go back to the Previous Menu: ");
    avik:
        scanf("%d", &so);
        if (so == 1)
        {
            goto Avik;
        }
        else
        {
            printf("INVALID INPUT \n re-enter your choice: ");
            goto avik;
        }
    }
    case 2:
    {
    avik2:
        system("cls");
        printf("enter number of new events you want to add:");
        scanf("%d", &test);
        fflush(stdin);
        for (int i = 0; i < test; i++)
        {
            printf("Enter %d event :\n", i + 1);
            gets(e[i].work);
            printf("\nenter number of hours you want for this event :\n");
            scanf("%d", &e[i].hour);
            fflush(stdin);
        }
        addwork(test);
        printf("Press \n'1' to go back to the Previous Menu\n'2' to if you want to add more events.\n  ");
        int so;
        scanf("%d", &so);
        if (so == 1)
        {
            goto Avik;
        }
        else if (so == 2)
        {
            goto avik2;
        }
        else
        {
            printf("INVALID INPUT \n re-enter your choice: ");
        }
    }
    case 3:
    {
    avik3:
        system("cls");
        int nope = fnow(), i = 0, k = 0;
        char ch;
        while (i < nope)
        {
            if (strcmp(in[i].user, UserID) == 0)
            {
                printf("%d. ", ++k);
                printf("index number : %d work - ", in[i].worknumber);
                puts(in[i].works);
            }
            i++;
        }
        printf("enter how many events you want to delete:");
        scanf("%d", &test);
        fflush(stdin);
        int target[test];
        for (int i = 0; i < test; i++)
        {
            printf("enter the first/next index of work you want to delete:");
            scanf("%d", &target[i]);
            fflush(stdin);
        }
        printallwork(target, test);
        printf("Press \n'1' to go back to the Previous Menu\n'2' to if you want to delete more events.\n  ");
        int so;
        scanf("%d", &so);
        if (so == 1)
        {
            goto Avik;
        }
        else if (so == 2)
        {
            goto avik3;
        }
        else
        {
            printf("INVALID INPUT \n re-enter your choice: ");
        }
    }
    case 4:
    {
        mainmenu();
        break;
    }
    default:
    {
        printf("\033[1;31mINVALID INPUT ! Please enter again");
        Sleep(1000);
        goto Avik;
        break;
    }
    }
}

int fnow()
{
    int c;
    char find[100];
    char find2[1000];
    int hd = -1;
    FILE *fp;
    fp = fopen("event.txt", "r");
    while (c != EOF)
    {
        c = fscanf(fp, "%s", find);
        fgets(find2, 1000, fp);
        hd++;
    }
    fclose(fp);
    return hd;
}
void takework()
{
    FILE *fptr;
    int note;
    char tk;
    int i = 0, j = fnow();
    fptr = fopen("event.txt", "r");
    while (i < j)
    {
        note = fscanf(fptr, "%s", &in[i].user);
        fgets(in[i].works, 1000, fptr);
        in[i].worknumber = i;
        i++;
    }
}

void printwork()
{
    takework();
    int nope = fnow(), i = 0, k = 0;
    char ch;
    while (i < nope)
    {
        if (strcmp(in[i].user, UserID) == 0)
        {
            printf("\033[1;36m%d. ", ++k);
            printf("index number : %d ; work - ", in[i].worknumber);
            puts(in[i].works);
        }
        i++;
    }
}

void addwork(int num)
{
    FILE *fptr;
    fptr = fopen("event.txt", "a+");
    fseek(fptr, 0, SEEK_END);
    for (int i = 0; i < num; i++)
    {
        fprintf(fptr, "\n%s %s for %dhrs", UserID, e[i].work, e[i].hour);
    }
    fclose(fptr);
}

void printallwork(int target[], int n)
{
    FILE *fp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {

            if (target[j] > target[j + 1])
            {
                int temp;
                temp = target[j];
                target[j] = target[j + 1];
                target[j + 1] = temp;
            }
        }
    }
    int count = fnow();
    fp = fopen("event.txt", "w");
    int a = 0, i = 0;
    while (a < count)
    {

        if (a == target[i])
        {
            i++;
            a++;
            continue;
        }
        else
        {
            fprintf(fp, "%s ", in[a].user);
            fputs(in[a].works, fp);
        }
        a++;
    }
    fclose(fp);
}

void settings()
{
    system("cls");
    int i = find_user();
    int a;
S1:
    system("cls");
    printf("\n\t\t\t\t\t\t\t(1) \033[1;31mview Profile\033[1;0m\n");
    printf("\t\t\t\t\t\t\t(2) \033[1;32medit Profile\033[1;0m\n");
    printf("\t\t\t\t\t\t\t(3) \033[1;34mchange Password\033[1;0m\n");
    printf("\t\t\t\t\t\t\t(4) \033[1;33mmain menu\033[1;0m\n");
    printf("\n\n\t\t\t\t\t\t\tenter your choice:");
    scanf("%d", &a);
    fflush(stdin);
    system("cls");
    switch (a)
    {
    case 1:
    {
        system("cls");
        viewProfile();
        printf("\t\t\t\t\t\033[1;36mpress any key to get back to settings menu:\033[1;0m\n");

        getch();

        goto S1;

        break;
    }
    case 2:
    {
        system("cls");
        editProfile2();
        printf("\t\t\t\t\t\033[1;36mpress any key to get back to settings menu:\033[1;0m");

        getch();
        goto S1;
        break;
    }
    case 3:
    {
        system("cls");
        changePassword(i);
        getch();
        goto S1;
        break;
    }
    case 4:
    {
        mainmenu();
        break;
    }
    default:
    {
        system("cls");
        printf("\033[1;31myou have entered wrong choice. Please try again!\033[1;0m\n");
        getch();
        goto S1;
    }
    }
}
void print_data(int count)
{

    FILE *fptr;
    fptr = fopen("LoginSignupPage.txt", "w");
    for (int i = 0; i < count; i++)
    {
        fprintf(fptr, "%s ", up[i].UserID);
        fprintf(fptr, "%s\n", up[i].Password);
    }
    fclose(fptr);
}
void viewProfile()
{
    int j = 0;
    FILE *fp;
    fp = fopen("userdata.txt", "r");
    int count = countuser();
    while (j < count)
    {
        fscanf(fp, "%s", &user[j].firstname);
        fscanf(fp, "%s", &user[j].lastname);
        fscanf(fp, "%d", &user[j].Date);
        fscanf(fp, "%d", &user[j].month);
        fscanf(fp, "%d", &user[j].year);
        fscanf(fp, "%s", &user[j].email);
        fscanf(fp, "%s", &user[j].gender);
        fscanf(fp, "%d", &user[j].class);
        fscanf(fp, "%s", &user[j].state);
        j++;
    }
    fclose(fp);
    int usernum = find_user();
    printf("\033[1;34m||\033[1;32myour user ID   is:\033[1;31m%s\033[1;34m          \033[1;0m\n", up[usernum].UserID);
    printf("\033[1;34m||\033[1;32myour Name      is:\033[1;31m%s %s\033[1;34m       \033[1;0m\n", user[usernum].firstname, user[usernum].lastname);
    printf("\033[1;34m||\033[1;32myour Email ID  is:\033[1;31m%s\033[1;34m          \033[1;0m\n", user[usernum].email);
    printf("\033[1;34m||\033[1;32myour DOB       is:\033[1;31m%d %d %d\033[1;34m    \033[1;0m\n", user[usernum].Date, user[usernum].month, user[usernum].year);
    printf("\033[1;34m||\033[1;32myour Gender    is:\033[1;31m%s\033[1;34m          \033[1;0m\n", user[usernum].gender);
    printf("\033[1;34m||\033[1;32myour class     is:\033[1;31m%d\033[1;34m          \033[1;0m\n", user[usernum].class);
    printf("\033[1;34m||\033[1;32myour state     is:\033[1;31m%s\033[1;34m          \033[1;0m\n", user[usernum].state);
}
void editProfile2()
{
    int count = countuser();
    int k = 0;
    while (k < count)
    {
        strcpy(user[k].firstname, "NA");
        strcpy(user[k].lastname, "NA");
        strcpy(user[k].email, "NA");
        strcpy(user[k].state, "NA");
        user[k].Date = -1;
        user[k].month = -1;
        user[k].year = -1;
        user[k].class = -1;
        strcpy(user[k].gender, "NA");
        k++;
    }
    FILE *fp;
    fp = fopen("userdata.txt", "r");
    int j = 0;
    while (j < count)
    {
        fscanf(fp, "%s", &user[j].firstname);
        fscanf(fp, "%s", &user[j].lastname);
        fscanf(fp, "%d", &user[j].Date);
        fscanf(fp, "%d", &user[j].month);
        fscanf(fp, "%d", &user[j].year);
        fscanf(fp, "%s", &user[j].email);
        fscanf(fp, "%s", &user[j].gender);
        fscanf(fp, "%d", &user[j].class);
        fscanf(fp, "%s", &user[j].state);
        j++;
    }
    fclose(fp);
    FILE *fptr;
    int n;
    fptr = fopen("LoginSignupPage.txt", "r");
    for (int i = 0; i < count; i++)
    {
        fscanf(fptr, "%s", &up[i].UserID);
        fscanf(fptr, "%s", &up[i].Password);
    }
    fclose(fptr);
    int custom;
    int usernum = find_user();
Again2:
    printf("\n0.Change UserID");
    printf("\n1.Change name");
    printf("\n2.Change Date of birth");
    printf("\n3.Change E-mail");
    printf("\n4.Change Gender");
    printf("\n5.Change Class");
    printf("\n6.Change State");
    printf("\n7.Previousmenu");
Again:
    printf("\nEnter your choice : ");
    scanf("%d", &custom);
    switch (custom)
    {
    case 0:
    {
        printf("\033[1;33menter your updated UserID:\033[1;0m");
        scanf("%s", &UserID);
        strcpy(up[usernum].UserID, UserID);
        print_data(count);
        break;
    }
    case 1:
    {
        printf("\nEnter first name :");
        scanf("%s", &user[usernum].firstname);
        printf("\nEnter last name :");
        scanf("%s", &user[usernum].lastname);
        break;
    }
    case 2:
    {
        printf("\nEnter Date of birth :");
        printf("\nEnter date :");
        scanf("%d", &user[usernum].Date);
        printf("\nEnter Month :");
        scanf("%d", &user[usernum].month);
        printf("\nEnter Year :");
        scanf("%d", &user[usernum].year);
        break;
    }
    case 3:
    {
        printf("\nEnter E-mail ID :");
        scanf("%s", &user[usernum].email);
        break;
    }
    case 4:
    {
        printf("\nEnter Gender :");
        scanf("%s", &user[usernum].gender);
        break;
    }
    case 5:
    {
        printf("\nEnter Class :");
        scanf("%d", &user[usernum].class);
        break;
    }
    case 6:
    {
        printf("\nEnter state (continuous without any space):");
        scanf("%s", &user[usernum].state);
        break;
    }
    case 7:
        settings();
    default:
    {
        printf("\nINVALID INPUT !");
        goto Again;
        break;
    }
    }
    printuserprofile();
    goto Again2;
}
int find_user()
{
    FILE *fptr2;
    int count = countuser();
    fptr2 = fopen("LoginSignupPage.txt", "r");
    for (int i = 0; i < count; i++)
    {
        fscanf(fptr2, "%s", &up[i].UserID);
        fscanf(fptr2, "%s", &up[i].Password);
    }
    fclose(fptr2);
    int j;
    int check1;
    for (j = 0; j < count; j++)
    {
        check1 = strcmp(UserID, up[j].UserID);
        if (check1 == 0)
            break;
    }
    return j;
}
void printuserprofile()
{
    FILE *fp;
    fp = fopen("userdata.txt", "w");
    for (int i = 0; i < countuser(); i++)
    {
        fprintf(fp, "%s ", user[i].firstname);
        fprintf(fp, "%s ", user[i].lastname);
        fprintf(fp, "%d ", user[i].Date);
        fprintf(fp, "%d ", user[i].month);
        fprintf(fp, "%d ", user[i].year);
        fprintf(fp, "%s ", user[i].email);
        fprintf(fp, "%s ", user[i].gender);
        fprintf(fp, "%d ", user[i].class);
        fprintf(fp, "%s\n", user[i].state);
    }
    fclose(fp);
}
void changePassword(int i)
{
    printf("\033[1;32mplease enter your new password:\033[1;0m\n");
    scanf("%s", &up[i].Password);
    printf("\033[1;32myour password is updated!!\033[1;0m\n");
    printf("\033[1;36mpress any key to get back to settings menu:\033[1;0m");
    print_data(countuser());
}
void notifications()
{
    system("CLS");
    MessageBox(0, "study hard jee advanced is nearing", "jee advanced", MB_OK);
    MessageBox(0, "all the  best for jee advanced", "jee advanced", MB_OK);
    MessageBox(0, "REGISTRATION OF JEE ADVANCED IS FROM 30 APR TO 8 MAY ", "jee advanced", MB_OK);
    MessageBox(0, "EXAM IS ON 4TH JUNE AND RESULT IS ON 18TH JUNE ", "jee advanced", MB_OK);

    printf("\nEnter '1' to return to mainmenu\t");
    int xyz;
XY:
    scanf("%d", &xyz);
    if (xyz == 1)
    {
        mainmenu();
    }
    else
    {
        printf("\033[1;31mINVALID INPUT !! Please enter again\033[1;0m");
        goto XY;
    }
}
void helpdesk()
{
    system("cls");
    printf("\t\t\t\t\t\t\t\t\033[7;32mWELCOME TO  THE HELP DESK\033[1;0m\n");
    printf("\t\t\t\t\t\t\t\t=========================\n");

    char str[200];
    fflush(stdin);
    printf("\033[1;31mENTER YOUR QUES : \033[1;0m\n");
    gets(str);
    fflush(stdin);

    FILE *qt;
    qt = fopen("ques.txt", "r");

    int uwu = 0;
    int quesnumber = 0;
    while (1)
    {
        char kh;
        uwu = fscanf(qt, "%c", &kh);
        if (kh == '?')
        {
            quesnumber++;
        }
        if(uwu==EOF){
            break;
        }
    }
    fclose(qt);

    qt = fopen("ques.txt", "r");
    qs qsarr[100];

    for (int i = 0; i < quesnumber; i++)
    {
        qsarr[i].freq = 0;
    }

    string quesans[1000];
    int z = 600;

    for (int i = 0; i < quesnumber; i++)
    {
        int j = 0;
        while (qsarr[i].ques[j - 1] != '?')
        {
            if (i != 0 && j == 0)
            {
                fscanf(qt, "%c", &quesans[z].qword[0]);
                z++;
            }
            fscanf(qt, "%c", &qsarr[i].ques[j]);
            j++;
        }
    }

    fclose(qt);

    FILE *as;
    as = fopen("ans.txt", "r");

    for (int i = 0; i < quesnumber; i++)
    {
        int j = 0;
        while (qsarr[i].ans[j - 1] != '.')
        {
            if (i != 0 && j == 0)
            {
                fscanf(as, "%c", &quesans[z].qword[0]);
                z++;
            }
            fscanf(as, "%c", &qsarr[i].ans[j]);
            j++;
        }
    }
    fclose(as);

    input word[100];

    int uu = 0;
    int wnum = 0;
    for (int i = 0; i < quesnumber; i++)
    {

        int wp = 0;
        while (str[uu + wp] != ' ' && str[uu + wp] != '\0')
        {
            word[i].in[wp] = str[uu + wp];
            wp++;
        }
        word[i].in[wp] = '\0';
        wnum++;
        if (str[uu + wp] == '\0')
        {
            break;
        }
        uu = uu + wp + 1;
    }

    printf("\n\n");
    search(qsarr, word, wnum, quesans, quesnumber);
}

void merge(qs qsarr[], int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int n2 = r - mid;
    qs a[n1];
    qs b[n2];
    for (int i = 0; i < n1; i++)
    {
        a[i] = qsarr[l + i];
    }
    for (int i = 0; i < n2; i++)
    {
        b[i] = qsarr[mid + i + 1];
    }
    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2)
    {
        if (a[i].freq > b[j].freq)
        {
            qsarr[k] = a[i];
            i++;
            k++;
        }
        else
        {
            qsarr[k] = b[j];
            j++;
            k++;
        }
    }
    while (i < n1)
    {
        qsarr[k] = a[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        qsarr[k] = b[j];
        j++;
        k++;
    }
}

void mergesort(qs qsarr[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        mergesort(qsarr, l, mid);
        mergesort(qsarr, mid + 1, r);
        merge(qsarr, l, mid, r);
    }
}

void search(qs qsarr[], input word[], int wnum, string quesans[], int quesnumber)
{

    int m = 0;
    for (int i = 0; i < wnum; i++)
    {
        for (int j = 0; j < quesnumber; j++)
        {

            if (strstr(qsarr[j].ques, word[i].in) != NULL && *(strstr(qsarr[j].ques, word[i].in) + strlen(word[i].in)) == ' ')
            {
                if (strstr(qsarr[j].ques, word[i].in) != qsarr[j].ques)
                {
                    if (*(strstr(qsarr[j].ques, word[i].in) - 1) == ' ')
                    {
                        qsarr[j].freq++;
                    }
                }
                else
                {
                    qsarr[j].freq++;
                }
            }
        }
    }

    for (int i = 0; i < wnum; i++)
    {
        for (int j = 0; j < quesnumber; j++)
        {
            if (strstr(qsarr[j].ans, word[i].in) != NULL && *(strstr(qsarr[j].ans, word[i].in) + strlen(word[i].in)) == ' ')
            {
                if (strstr(qsarr[j].ans, word[i].in) != qsarr[j].ans)
                {
                    if (*(strstr(qsarr[j].ans, word[i].in) - 1) == ' ')
                    {
                        qsarr[j].freq++;
                    }
                }
                else
                {
                    qsarr[j].freq++;
                }
            }
        }
    }

    mergesort(qsarr, 0, quesnumber - 1);
    for (int i = 0; i < quesnumber; i++)
    {
        printf("%s\n", qsarr[i].ques);
        printf("%s\n\n", qsarr[i].ans);
    }

    int qzx;
xyz:
    printf("\033[1;34mEnter 0 to return to main menu or 1 to search again\033[1;0m ");
    scanf("%d", &qzx);
    if (qzx == 0)
    {
        mainmenu();
    }
    else if (qzx == 1)
    {
        helpdesk();
    }
    else
    {
        goto xyz;
    }
}
void substr(char a[], int start, int end, char c[])
{
    int j = 0;
    for (int i = start; i <= end; i++)
    {
        c[j] = a[i];
        j++;
    }
    c[j] = '\0';
}

bool compare(char a[], char b[])
{
    if (strlen(a) != strlen(b))
    {
        return false;
    }
    for (int i = 0; i < strlen(a); i++)
    {
        if (a[i] != b[i])
        {
            return false;
        }
    }
    return true;
}

void ratings()
{
    system("cls");
    char str[100000];
    float ab = numrate();
    fp = fopen("feedback.txt", "a+");
    printf("\033[1;33mPlease enter feedback\033[1;0m\n");
    gets(str);
    printf("\033[1;36mTHANK\033[1;34m YOU\033[1;36m FOR \033[1;32m YOUR\033[1;33m VALUABLE\033[1;31m FEEDBACK\033[1;0m !");
    fprintf(fp, "\n%s -", UserID);
    fprintf(fp, "%s", str);
    fclose(fp);
    int x;
XYZ:
    printf("\033[1;36mEnter 1 to return to main menu");
    scanf("%d", &x);
    if (x == 1)
    {
        mainmenu();
    }
    else
    {
        printf("\033[1;31mINVALID INPUT !! Please enter again\033[1;0m");
        goto XYZ;
    }
}
float numrate()
{
    float c;
    float sum = 0.0;
    float n;
    fp = fopen("rating.txt", "a+");
    printf("\033[1;33mPlease give rating out of ten\033[1;0m\n");
Rate:
{
    scanf("%f", &n);
    fflush(stdin);
}
    if (n > 10 || n < 0)
    {
        printf("\033[3;32mEnter valid rating\033[1;0m\n");
        goto Rate;
    }
    fprintf(fp, " %.1f", n);
    fclose(fp);
    int cal = check();
    float num = cal;
    fp = fopen("rating.txt", "r");
    for (int i = 0; i < cal; i++)
    {
        fscanf(fp, "%f", &c);
        sum += c;
        fflush(stdin);
    }
    float rating;
    rating = sum / num;
    printf("\033[3;33mOverall rating of app is=%.1f\n\033[1;0m", rating);
}

int check()
{
    fp = fopen("rating.txt", "r");
    int count = -1;
    float n1;
    int n2;
    while (n2 != EOF)
    {
        n2 = fscanf(fp, "%f", &n1);
        count++;
    }
    fclose(fp);

    return count;
}

int admin()
{
    system("cls");
    char name[40];
    fflush(stdin);
start1:
    printf("\033[1;34menter the name of the admin \033[1;0m:");
    gets(name);
    fflush(stdin);

    char password[40];
    fflush(stdin);
    printf("\033[1;36mEnter the admin's password \033[1;0m:");
    gets(password);
    fflush(stdin);
    FILE *fp;
    fp = fopen("password.txt", "r");
    char ch[100];
    int count = -1;
    int a = 0;
    for (int i = 0; a != EOF; i++)
    {
        char garbage[100];
        a = fscanf(fp, "%s", &ch);
        fscanf(fp, "%s", &garbage);
        count++;
    }
    fclose(fp);
    te admin[30];
    FILE *ptr1 = fopen("password.txt", "r");

    for (int i = 0; i < count; i++)
    {
        fscanf(ptr1, "%s", admin[i].name);
        fscanf(ptr1, "%s", admin[i].password);
    }

    int k = 0;
    for (int i = 0; i < count; i++)
    {
        if (strcmp(admin[i].name, name) == 0 && strcmp(admin[i].password, password) == 0)
        {
            k = 1;
        }
    }
    fclose(ptr1);
    if (k == 0)
    {
        int czx;
        printf("\033[1;31mWrong password. Enter 1 to return to main menu\033[1;0m");
        scanf("%d", &czx);
        if (czx == 1)
        {
            mainmenu();
        }
        else
        {
            goto start1;
        }
    }
start:
    system("cls");
    printf("\t\t\t\t\t\t\t\033[1;31m------------------------------\033[1;0m\n");
    printf("\t\t\t\t\t\t\t| \033[7;32mWELCOME TO admin'S SECTION\033[1;0m |\n");
    printf("\t\t\t\t\t\t\t\033[1;31m------------------------------\033[1;0m\n\n\n\n");

    int n;
    printf("\t\t\t\t\t\t\033[1;34mEnter 1 to add questions to the helpdesk\033[1;0m\n");
    printf("\t\t\t\t\t\t\033[1;32mEnter 2 to add question papers to the mock test section\033[1;0m\n");
    printf("\t\t\t\t\t\t\033[1;33mEnter 3 to get the list of all the users\033[1;0m\n");
    printf("\t\t\t\t\t\t\033[1;31mEnter 4 to ban some id\033[1;0m\n");
    printf("\t\t\t\t\t\t\033[1;31mEnter 5 to unban some id\033[1;0m\n");
    printf("\033[4;31mENTER : \033[1;0m");
    scanf("%d", &n);

    system("cls");
    switch (n)
    {
    case 1:
        edithelpdesk();
        int k;
        printf("\n\n\t\t\t\033[1;31mFor going to admin's section menu, enter 1 else enter 0 : \033[1;0m");
        scanf("%d", &k);
        if (k == 1)
        {
            goto start;
        }
        else
        {
            loginregisterpage();
        }
        break;
    case 2:
        addquespaper();
        printf("\n\n\t\t\t\033[1;36mFor going to admin's section menu, enter 1 else enter 0 : \033[1;0m");
        scanf("%d", &k);
        if (k == 1)
        {
            goto start;
        }
        else
        {
            loginregisterpage();
        }
        break;
    case 3:
        list();
        printf("\n\n\t\t\t\033[1;35mFor going to admin's section menu, enter 1 else enter 0 :\033[1;0m ");
        scanf("%d", &k);
        if (k == 1)
        {
            goto start;
        }
        else
        {
            loginregisterpage();
        }
        break;
    case 4:
        ban();
        printf("\n\n\t\t\t\033[1;33mFor going to admin's section menu, enter 1 else enter 0 : \033[1;0m");
        scanf("%d", &k);
        if (k == 1)
        {
            goto start;
        }
        else
        {
            loginregisterpage();
        }
        break;
    case 5:
        unban();
        printf("\n\n\t\t\t\033[1;33mFor going to admin's section menu, enter 1 else enter 0 : \033[1;0m");
        scanf("%d", &k);
        if (k == 1)
        {
            goto start;
        }
        else
        {
            loginregisterpage();
        }
        break;

    default:
        printf("\033[1;31mUNRECOGNIZED\033[1;0m\n");
        printf("\n\t\t\t\033[1;36mFor going to admin's section menu, enter 1 else enter 0 : \033[1;0m");
        scanf("%d", &k);
        if (k == 1)
        {
            goto start;
        }
        else
        {
            mainmenu();
        }
        break;
    }
}

void edithelpdesk()
{
    FILE *ptr2 = fopen("ques.txt", "a");
    int n;
    fflush(stdin);
    printf("\033[1;33mEnter number of the questions you want to enter : \033[1;0m");
    scanf("%d", &n);
    int d[100] = {n};
    int nn=0;
    q_a qarr[n];
    fflush(stdin);
    for (int i = 1; i <= n; i++)
    {
        printf("enter the question number %d : ", i);
        fgets(qarr[i].ques, 100, stdin);
        fflush(stdin);
        fprintf(ptr2, "%s", qarr[i].ques);
        if (i == d[nn])
        {    
            break;
        }
        nn++;
    }
    nn=0;
    fclose(ptr2);
    FILE *ptr3 = fopen("ans.txt", "a");
    for (int i = 1; i <= n; i++)
    {
        printf("enter answer number %d: ", i);
        fgets(qarr[i].ans, 100, stdin);
        fprintf(ptr3, "%s", qarr[i].ans);
        if (i == d[nn])
        {
            break;
        }
        nn++;
    }
    fclose(ptr3);
}

void addquespaper()
{
    int n;
    fflush(stdin);
    printf("\033[1;35mEnter the number of the question paper sets you wants to enter : \033[1;0m");
    scanf("%d", &n);
    int d[100] = {n};
    int j = 0;
    paper arr[n];
    fflush(stdin);
    FILE *ptr = fopen("paper.txt", "a");
    for (int i = 1; i <= n; i++)
    {
        printf("enter the link of paper 1 of set %d :", i);
        fgets(arr[i].paper1, 50, stdin);
        fflush(stdin);
        printf("enter the link of paper 2 of set %d : ", i);
        fgets(arr[i].paper2, 50, stdin);
        fflush(stdin);
        fprintf(ptr, "%s%s", arr[i].paper1, arr[i].paper2);
        if (i == d[j])
        {
            break;
        }
        j++;
    }
    fclose(ptr);
}

void list()
{
    stlist arr[50];
    fflush(stdin);
    FILE *ptr = fopen("LoginSignupPage.txt", "r");
    int u = 0;
    int i = 0;
    while (1)
    {
        fscanf(ptr, "%s", arr[i].id);

        u = fscanf(ptr, "%s", arr[i].password);
        if (i == 0)
        {
            printf("list\n");
        }
        if (u == EOF)
        {
            break;
        }
        printf("%s %s\n", arr[i].id, arr[i].password);
        i++;
    }
    fclose(ptr);
}

void ban()
{
    FILE *ptr = fopen("ban.txt", "a");
    char id[30];
    fflush(stdin);
    printf("\033[4;32menter the id : \033[1;0m");
    gets(id);
    fflush(stdin);
    fprintf(ptr, "%s\n", id);
    printf("\033[1;31mId banned\033[1;0m");
    fclose(ptr);
}

void unban()
{
    FILE *ou = fopen("ban.txt", "r");
    int kk = 0;
    int zeo = 0;
    while (1)
    {
        kk = fscanf(ou, "%s", unban_arr[zeo].unban_id);
        zeo++;
        if (kk == EOF)
        {
            break;
        }
    }
    fclose(ou);
    char id[50];
    fflush(stdin);
    printf("Enter the id to unban : ");
    scanf("%s", id);
    fflush(stdin);
    FILE *mou = fopen("ban.txt", "w");
    int k = 0;
    while (1)
    {
        if (strcmp(unban_arr[k].unban_id, id) == 0)
        {
            k++;
            continue;
        }
        fprintf(mou, "%s\n", unban_arr[k].unban_id);
        if (k == zeo)
        {
            break;
        }
        k++;
    }
    fclose(mou);
}

void alarmclock()
{
    printf("\t\t\t\t\t\t\t\t\t\033[7;36mAlARM CLOCK\033[1;0m\n\n");
    int h = 0, m = 0, s = 0;
    int n;
    printf("\033[1;36mEnter the number of alarms, you have to set :\033[1;0m ");
    scanf("%d", &n);

    alarm alarms[n];
    printf("\n\n\033[1;33mEnter the timings of alarms in hh mm format : \033[1;0m\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &alarms[i].hour);
        scanf("%d", &alarms[i].min);
    }

    system("cls");

    while (1)
    {
        time_t now = time(NULL);
        struct tm *cur_time = localtime(&now);
        h = cur_time->tm_hour;
        m = cur_time->tm_min;
        s = cur_time->tm_sec;

        if (binarysearch(alarms, n, h) == 1 && binarysearchmin(alarms, n, m) == 1)
        {
            Beep(700, 6000);
        }
    }
}

void swaphr(alarm alarms[], int i, int j)
{
    int temp = alarms[i].hour;
    alarms[i].hour = alarms[j].hour;
    alarms[j].hour = temp;
}

int partition2(alarm alarms[], int l, int r)
{
    int pivot = alarms[r].hour;
    int i = l - 1;
    for (int j = l; j < r; j++)
    {
        if (alarms[j].hour < pivot)
        {
            i++;
            swaphr(alarms, i, j);
        }
    }
    swaphr(alarms, i + 1, r);
    return i + 1;
}

void quicksort2(alarm alarms[], int l, int r)
{
    if (l < r)
    {
        int pi = partition2(alarms, l, r);
        quicksort2(alarms, l, pi - 1);
        quicksort2(alarms, pi + 1, r);
    }
}

int binarysearch(alarm alarms[], int n, int x)
{
    quicksort2(alarms, 0, n - 1);
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (alarms[mid].hour == x)
        {
            return 1;
        }
        else if (x < alarms[mid].hour)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}

void swapmin(alarm alarms[], int i, int j)
{
    int temp = alarms[i].min;
    alarms[i].min = alarms[j].min;
    alarms[j].min = temp;
}

int partitionmin(alarm alarms[], int l, int r)
{
    int pivot = alarms[r].min;
    int i = l - 1;
    for (int j = l; j < r; j++)
    {
        if (alarms[j].min < pivot)
        {
            i++;
            swapmin(alarms, i, j);
        }
    }
    swapmin(alarms, i + 1, r);
    return i + 1;
}

void quicksortmin(alarm alarms[], int l, int r)
{
    if (l < r)
    {
        int pi = partitionmin(alarms, l, r);
        quicksortmin(alarms, l, pi - 1);
        quicksortmin(alarms, pi + 1, r);
    }
}

int binarysearchmin(alarm alarms[], int n, int x)
{
    quicksortmin(alarms, 0, n - 1);
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (alarms[mid].min == x)
        {
            return 1;
        }
        else if (x < alarms[mid].min)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}

int clocks()
{

    int h, m, s, d, y, mon;

Ishan:

    system("cls");
    time_t now = time(NULL);
    struct tm *cur_time = localtime(&now);
    h = cur_time->tm_hour;
    m = cur_time->tm_min;
    s = cur_time->tm_sec;
    y = cur_time->tm_year + 1900;
    mon = cur_time->tm_mon + 1;
    d = cur_time->tm_mday;
    printf("Curren date = %d/%d/%d\nCurrent time = %d:%d:%d\n", d, mon, y, h, m, s);
    int p;
    printf("Press 1 to again print the time else enter 0:");
    scanf("%d", &p);
    if (p == 1)
    {
        goto Ishan;
    }
    else
    {

        mainmenu();
    }
}