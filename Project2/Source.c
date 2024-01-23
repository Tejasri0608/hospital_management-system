//HOSPITAL MANAGEMENT SYSTEM
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct ad
{
    char name[30];
    char disease[30];
    int phone, age;
} x[100];
int n, i, j = 0, a = 0, sum = 0, g, flag, num=0;
char c;
void read();
void write();
void view();
void add();
void search();
void edit();
void del();
void record();
int main()
{
    read();
    int c = 0, i, q;
    printf("Simple Hospital Management System\n\n");
    int m, n;
    while (c != 7)
    {
        printf("Enter your choice\n\n1. Add Patient\n2. View Fee Chart\n3. Search Patient record\n4. Edit Patient Information\n5. Delete patient record\n6. View all patient record\n7. Exit\n\nOption= ");
        scanf("%d", &c);//choice for option
        if (c == 1)//add
        {
            add();
        }
        else if (c == 2)//view
        {
            view();
        }
        else if (c == 3)//search
        {
            search();
        }
        else if (c == 4)//edit
        {
            edit();
        }
        else if (c == 5)//delete
        {
            del();
        }
        else if (c == 6)
        {
            record();
        }
        else if (c == 7)
        {
            write();
            return 0;
        }
        else
        {
            printf("\n\nInvalid input , try again by using valid inputs");
        }
        printf("\n\n");
    }
}
void add()
{
    printf("\n\n");
    printf("Already data inputed on the database = %d\n\n", num);//how many inputs
    printf("How many entry do you want to add = \n");
    scanf("%d", &n);
    sum = n + num;
    for (i = num, j = 0; i < sum; i++)
    {
        printf("\n");
        printf("Enter patient's Name = ");
        scanf("%s", x[i].name);
        printf("Enter disease = ");
        scanf("%s", x[i].disease);
        printf("Enter the age = ");
        scanf("%d", &x[i].age);
        printf("Enter phone number = ");
        scanf("%d", &x[i].phone);
        printf("\n");
        j++;
        a++;
        num++;
    }
}

void view()
{
    printf("\n\n");
    int i = 0;
    char str[300], c;
    FILE* fp;
    fp = fopen("view.txt", "r");
    if (fp == NULL)
    {
            printf("error opening file");
            exit(1);
    }
    while ((c = fgetc(fp)) != EOF)
    {
            str[i] = c;
            i++;
    }
    str[i] = '\0';
    printf("%s", str);
    fclose(fp);
    printf("\n\n");
}
void edit()
{
    int q, p;
    printf("What do you want to edit ?\n");
    printf("Enter your option\n");
    printf("1.Name\n2.Disease\n3.Age\n4.Phone no.\n");
    printf("Option= ");
    scanf("%d", &q);//option
    if (q <= 5)
    {
        printf("Enter the serial no of that patient= (0 - %d)=", (num - 1));
        scanf("%d", &p);//serial number
        if (p < num)
        {
            if (q == 1)
            {
                printf("Enter the new name = ");
                scanf("%s", x[p].name);
            }
            else if (q == 2)
            {
                printf("Enter the new Disease = ");
                scanf("%s", x[p].disease);
            }
            else if (q == 3)
            {
                printf("Enter the new Age = ");
                scanf("%d", &x[p].age);
            }
            else if (q == 4)
            {
                printf("Enter the new Phone no = ");
                scanf("%d", &x[p].phone);
            }
        }
        else
        {
            printf("\n\nInvalid Serial \nTry Again !!\n\n");
        }
    }
    else
    {
        printf("\n\nInvalid option\nTry Again!!\n\n");
    }
}
void search()
{
    int s, h, f;
    char u[100];
    printf("By what do you want to search ?\n");
    printf("1.Serial no.\n2.Name\n3.Disease\n4.Phone no.\n5.Age\n\nOption = ");
    scanf("%d", &h);
    if (h == 1)
    {
        printf("Enter Serial number of the patient(0-%d) = ",num);
        scanf("%d", &s);
        if (s < num)
        {
            printf("\n");
            printf("Serial Number = %d\n", s);
            printf("Name = %s\n", x[s].name);
            printf("Disease = %s\n", x[s].disease);
            printf("Phone number = %d\nAge = %d", x[s].phone, x[s].age);
            printf("\n\n");
        }
        else
            printf("\n\nNot Found\n\n");
    }
    else if (h == 2)
    {
        int f = 1;
        printf("Enter your name = ");
        scanf("%s", u);
        for (g = 0; g < num; g++)
        {
            if (strcmp(u, x[g].name) == 0)
            {
                printf("\n");
                printf("Serial Number = %d\n", g);
                printf("Name = %s\n", x[g].name);
                printf("Disease = %s\n", x[g].disease);
                printf("Phone number = %d\nAge = %d\n", x[g].phone, x[g].age);
                printf("\n\n");
                f = 0;
            }
        }
        if (f == 1)
            printf("\nNot Found\n");
    }
    else if (h == 3)
    {
        int f = 1;
        printf("Enter Disease = ");
        scanf("%s", u);
        for (g = 0; g < num; g++)
        {
            if (strcmp(u, x[g].disease) == 0)
            {
                printf("\n");
                printf("Serial Number = %d\n", g);
                printf("Name = %s\n", x[g].name);
                printf("Disease = %s\n", x[g].disease);
                printf("Phone number = %d\nAge = %d\n", x[g].phone, x[g].age);
                printf("\n\n");
                f = 0;
            }
        }
        if (f == 1)
            printf("\nNot Found\n");
    }
    else if (h == 4)
    {
        int f = 1;
        printf("Enter Phone number = ");
        scanf("%d", &f);
        for (g = 0; g < num; g++)
        {
            if (f == x[g].phone)
            {
                printf("\n");
                printf("Serial Number = %d\n", g);
                printf("Name = %s\n", x[g].name);
                printf("Disease = %s\n", x[g].disease);
                printf("Phone number = %d\nAge = %d", x[g].phone, x[g].age);
                printf("\n\n");
                f = 0;
            }
        }
        if (f == 1)
            printf("Not Found");
    }
    else if (h == 5)
    {
        int f = 1;
        printf("Enter Age = ");
        scanf("%d", &f);
        for (g = 0; g < num; g++)
        {
            if (f == x[g].age)
            {
                printf("\n");
                printf("Serial Number = %d\n", g);
                printf("Name = %s\n", x[g].name);
                printf("Disease = %s\n", x[g].disease);
                printf("Phone number = %d\nAge = %d", x[g].phone, x[g].age);
                printf("\n\n");
                f = 0;
            }
        }
        if (f == 1)
            printf("Not Found\n\n");
    }
    else
        printf("\n\nInvalid input\n\n");
}
void del()
{
    int f, h;
    printf("Enter the serial number of the patient that you want to delete (0-%d) =",(num-1));
    scanf("%d", &f);
    if (f < num)
    {
        printf("What do you want ?\n");
        printf("1.Remove the whole record\n2.Remove Name\n3.Remove Disease\n4.Remove age\n5.Remove phone number\nOption = ");
        scanf("%d", &h);
        if (h == 1)
        {
            while (f < num)
            {
                strcpy(x[f].name, x[f + 1].name);
                strcpy(x[f].disease, x[f + 1].disease);
                x[f].age = x[f + 1].age;
                x[f].phone = x[f + 1].phone;
                f++;
            }
            num--;
        }
        else if (h == 2)
        {
            strcpy(x[f].name, "Cleared");

        }
        else if (h == 3)
        {
            strcpy(x[f].disease, "Cleared");
        }
        else if (h == 4)
        {
            x[f].age = 0;
        }
        else if (h == 5)
        {
            x[f].phone = 0;
        }
    }
    else
        printf("\n\nInvalid Serial number\n");
}
void record()
{
    int i;
    printf("all patient record\n");
    for (i = 0; i < num; i++)
    {
        printf("\n");
        printf("Serial Number = %d\n", i);
        printf("Name = %s\n", x[i].name);
        printf("Disease = %s\n", x[i].disease);
        printf("Phone number = %d\nAge = %d\n", x[i].phone, x[i].age);
        printf("\n\n");
    }
}
void read()
{
    FILE* fp = fopen("record.txt", "r");
    if (fp == NULL)
    {
        //create empty file, so that we can open it
        //in the next execution of this program
        fp = fopen("record.txt", "w");
        fclose(fp);
        printf("File does not exist, I JUST CREATED IT, exiting...\n\n\n");
        return 0;
    }
    num = fread(x, sizeof(struct ad), 100, fp);
    fclose(fp);
}
void write()
{
    FILE* fp = fopen("record.txt", "w");
    if (fp == NULL)
    {
        printf("Error");
        exit(1);
    }
    fwrite(x, sizeof(struct ad), num, fp);
    fclose(fp);
}