#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

int getstudent();
int getmember();
int getcourt();
int getcourtprice(int student, int court, int booktime);
float getgrandtotal(int member, float total);
void receipt(char nameofcus[12][30], char phone[12][15], char date[20], char foodname[20][50], char studenttype[30], char membertype[15], char courttype[40], int booktime, float courtprice, float foodprice[20], float grandtotal, int timein, int timeout, int numofcus, int foodnumber, float foodtotalprice, float total);

int main()
{
    char nameofcus[12][30], phone[12][15], date[20], foodname[20][50], studenttype[30], membertype[15], courttype[40];
    int student, member, numofcus, i, court, booktime, j, foodchoice, choice, l, exit0, foodnumber, timein, timeout;
    int k = 1;
    int* pnumofcus;
    float foodtotalprice, foodprice[20], courtprice, total;
    float grandtotal;

    grandtotal = 0.00;
    foodtotalprice = 0.00;
    printf("Welcome to the UMP Sports Complex Reservation and Rental System!");
    printf("\n\nPlease enter the booking date. ");
    scanf("%s", &date);
    printf("\nPlease enter the total number of player. ");
    scanf("%d", &numofcus);
    pnumofcus = &numofcus;
    for(i = 0; i < *pnumofcus; i++)
    {
        printf("\nEnter Customer %d's name         : ", i+1);
        scanf(" %[^\n]s", &nameofcus[i]);
        printf("Enter Customer %d's phone number : ", i+1);
        scanf("%s", &phone[i]);
        fflush(stdin);
    }
    student = getstudent();
    member = getmember();
    court = getcourt();
    printf("\nPlease enter the beginning time of booking. [24h format] ");
    scanf("%d", &timein);
    printf("\nPlease enter the ending time of booking. [24h format] ");
    scanf("%d", &timeout);
    booktime = timeout - timein;
    courtprice = getcourtprice(student, court, booktime);
    if (student == 1)
    {
        strcpy(studenttype, "UMP Student");
    }
    else
    {
        strcpy(studenttype, "Outsider");
    }
    if (member == 1)
    {
        strcpy(membertype, "Member");
    }
    else
    {
        strcpy(membertype, "Non-member");
    }
    if (court == 1)
    {
        strcpy(courttype, "Basketball Court");
    }
    else if (court == 2)
    {
        strcpy(courttype, "Netball Court");
    }
    else if (court == 3)
    {
        strcpy(courttype, "Tennis Court");
    }
    else if (court == 4)
    {
        strcpy(courttype, "Badminton Court");
    }
    else if (court == 5)
    {
        strcpy(courttype, "Futsal Court");
    }
    else if (court == 6)
    {
        strcpy(courttype, "Volleyball Court");
    }
    else
    {
        strcpy(courttype, "Squash Court");
    }


    printf("Here are the menu of the food and beverage that provided by us.\n");
    printf("1. Sandwich (RM2.00)\n2. Snacks (RM1.00)\n3. Energy Drinks (RM2.50)\n4. Soft Drinks (1.50)\n5. Mineral Water (RM1.00)\nCOMBO\n6. Sandwich + Energy Drinks (RM4.00)\n7. Sandwich + Soft Drinks (RM3.00)\n8. Sandwich + Snacks (RM2.50)\n9. Snacks + Mineral Water (RM1.50)");
    printf("\nDo you need any of them? [1 for Yes/ 2 for No] ");
    scanf("%d", &foodchoice);
    if (foodchoice == 1)
    {
    do
    {
    printf("\nPlease enter the order number.: ");
    retype: scanf("%d", &choice);

    if (choice == 1)
    {
        strcpy(foodname[k], "Sandwich");
        foodprice[k] = 2.00;
    }
    else if (choice == 2)
    {
        strcpy(foodname[k], "Snacks");
        foodprice[k] = 1.00;
    }
    else if (choice == 3)
    {
        strcpy(foodname[k], "Energy Drinks");
        foodprice[k] = 2.50;
    }
    else if (choice == 4)
    {
        strcpy(foodname[k], "Soft Drinks");
        foodprice[k] = 1.50;
    }
    else if (choice == 5)
    {
        strcpy(foodname[k], "Mineral Water");
        foodprice[k] = 1.00;
    }
    else if (choice == 6)
    {
        strcpy(foodname[k], "Sandwich + Energy Drinks");
        foodprice[k] = 4.00;
    }
    else if (choice == 7)
    {
        strcpy(foodname[k], "Sandwich + Soft Drinks");
        foodprice[k] = 3.00;
    }
    else if (choice == 8)
    {
        strcpy(foodname[k], "Sandwich + Snacks");
        foodprice[k] = 2.50;
    }
    else if (choice == 9)
    {
        strcpy(foodname[k], "Snacks + Mineral Water");
        foodprice[k] = 1.50;
    }
    else
    {
        printf("\nWrong number entered. It should be 1 to 9 only. Please enter again. ");
        goto retype;
    }
    printf("Do you want to add more? 1 yes 2 no: ");
    scanf("%d", &exit0);
    fflush(stdin);
    k++;
    }
    while (exit0 == 1);
    foodnumber = k;
    for (l = 1; l < k; l++)
    {
        foodtotalprice += foodprice[l];
    }
    }
    else
    {
    foodtotalprice = 0;
    foodnumber = 0;
    }
    total = courtprice + foodtotalprice;
    grandtotal = getgrandtotal(member, total);
    printf("\nPress ENTER for the receipt.");
    getch();
    receipt(nameofcus, phone, date, foodname, studenttype, membertype, courttype, booktime, courtprice, foodprice, grandtotal, timein, timeout, numofcus, foodnumber, foodtotalprice, total);
    return 0;
}

int getstudent()
{
    int student;

    printf("\n\nAre you a student of UMP [1 for Yes/ 2 for No] ");
    scanf("%d", &student);
    return student;
}

int getmember()
{
    int member;

    printf("\n\nAre you a member? [1 for Yes/ 2 for No] ");
    scanf("%d", &member);
    return member;
}

int getcourt()
{
    int court;

    printf("\n1. Basketball Court\n2. Netball Court\n3. Tennis Court\n4. Badminton Court\n5. Futsal Court\n6. Volleyball Court\n7. Squash Court");
    printf("\nPlease enter the court that you want to book. ");
    scanf("%d", &court);
    return court;
}


int getcourtprice(int student, int court, int booktime)
{
    float courtprice, totalcourtprice;

    if (student == 1)
    {
        if (court == 1)
        {
            if (booktime >= 8)
            {
                courtprice = 3.00;
            }
            else if (booktime >= 5)
            {
                courtprice = 4.00;
            }
            else
            {
                courtprice = 5.00;
            }
        }
        else if (court == 2)
        {
            if (booktime >= 8)
            {
                courtprice = 2.00;
            }
            else if (booktime >= 5)
            {
                courtprice = 3.00;
            }
            else
            {
                courtprice = 4.00;
            }
        }
        else if (court == 3)
        {
            if (booktime >= 8)
            {
                courtprice = 5.00;
            }
            else if (booktime >= 5)
            {
                courtprice = 6.00;
            }
            else
            {
                courtprice = 7.00;
            }
        }
        else if (court == 4)
        {
            if (booktime >= 8)
            {
                courtprice = 3.00;
            }
            else if (booktime >= 5)
            {
                courtprice = 4.00;
            }
            else
            {
                courtprice = 5.00;
            }
        }
        else if (court == 5)
        {
            if (booktime >= 8)
            {
                courtprice = 6.00;
            }
            else if (booktime >= 5)
            {
                courtprice = 7.00;
            }
            else
            {
                courtprice = 8.00;
            }
        }
        else if (court == 6)
        {
            if (booktime >= 8)
            {
                courtprice = 3.00;
            }
            else if (booktime >= 5)
            {
                courtprice = 4.00;
            }
            else
            {
                courtprice = 5.00;
            }
        }
        else
        {
            if (booktime >= 8)
            {
                courtprice = 4.00;
            }
            else if (booktime >= 5)
            {
                courtprice = 5.00;
            }
            else
            {
                courtprice = 6.00;
            }
        }
    }
    else
    {
        if (court == 1)
        {
            courtprice = 10.00;
        }
        else if (court == 2)
        {
            courtprice = 9.00;
        }
        else if (court == 3)
        {
            courtprice = 13.00;
        }
        else if (court == 4)
        {
            courtprice = 15.00;
        }
        else if (court == 5)
        {
            courtprice = 18.00;
        }
        else if (court == 6)
        {
            courtprice = 15.00;
        }
        else
        {
            courtprice = 12.00;
        }
    }
    totalcourtprice = booktime * courtprice;
    return totalcourtprice;
}

float getgrandtotal(int member, float total)
{
    float grandtotal;

    if (member == 1)
    {
        grandtotal = total * 0.90;
    }
    else
    {
        grandtotal = total * 1.00;
    }
        grandtotal = grandtotal * 1.06;
    return grandtotal;
}

void receipt(char nameofcus[12][30], char phone[12][15], char date[20], char foodname[20][50], char studenttype[30], char membertype[15], char courttype[40], int booktime, float courtprice, float foodprice[20], float grandtotal, int timein, int timeout, int numofcus, int foodnumber, float foodtotalprice, float total)
{
    FILE *fptr;
    int i, j;
    char cmd[5000];
    fptr = fopen("Receipts.txt", "w");
    system("cls");
    fprintf(fptr, "\t\tUniversity of Malaysia Pahang");
    fprintf(fptr, "\n\n\t\tAddress : Lebuhraya Tun Razak");
    fprintf(fptr, "\n\t\t          26300 Gambang, Kuantan");
    printf(fptr, "\n\t\t          Pahang Darul Makmur");
    fprintf(fptr, "\n\n\t\tTel No  : 09-424 5000");
    fprintf(fptr, "\n\t\tEmail   : pro@ump.edu.my ");
    fprintf(fptr, "\n---------------------------------------------------");
    fprintf(fptr, "\n\t\tReservation Info");
    for (i = 0; i < numofcus; i++)
    {
        fprintf(fptr, "\nCustomer %d", i+1);
        fprintf(fptr, "\nName   : %s", nameofcus[i]);
        fprintf(fptr, "\nTel No : %s\n", phone[i]);
        fprintf(fptr, "\n");
    }
    fprintf(fptr, "----------------------------------------------------\n");
    fprintf(fptr, "\t\tBooking Info\n");
    fprintf(fptr, "Booking Date     : %s\n", date);
    fprintf(fptr, "Booking Time     : From %d to %d\n", timein, timeout);
    fprintf(fptr, "Total Duration   : %d Hours\n", booktime);
    fprintf(fptr, "Court Categories : %s\n\n", courttype);
    fprintf(fptr, "----------------------------------------------------\n");
    fprintf(fptr, "\t\tMembership Info\n");
    fprintf(fptr, "Member           : %s\n\n", membertype);
    fprintf(fptr, "----------------------------------------------------\n");
    fprintf(fptr, "\t\tFood & Beverage Service\n");
    fprintf(fptr, "Order Name\t\t\t\tPrice(RM)\n");
    if (foodnumber == 0)
    {
        fprintf(fptr, "None\t\t\t\t0.00");
    }
    else
    {
        for (j = 1; j < foodnumber; j++)
        {
            fprintf(fptr, "\n%s\t\t\t\t%.2f", foodname[j], foodprice[j]);
        }
    }
    fprintf(fptr, "\n\n----------------------------------------------------\n");
    fprintf(fptr, "\t\tTotal Price\n\n");
    fprintf(fptr, "Description\t\t\t\tUnit Price(RM)\n");
    fprintf(fptr, "%s (%d Hours)\t\t\t\t%.2f\n", courttype, booktime, courtprice);
    fprintf(fptr, "Food and Beverage\t\t\t\t%.2f\n", foodtotalprice);
    fprintf(fptr, "-----------------------------------------------------\n");
    fprintf(fptr, "\t\t\tTotal Price (RM)\t%.2f\n\n", total);
    fprintf(fptr, "Grand Total(After member discount and 6%% tax) : RM %.2f", grandtotal);
    fprintf(fptr, "\nThank You!!");
    fclose(fptr);

    fptr = fopen("Receipts.txt", "r");
    while (fgets(cmd,5000,fptr)!=NULL)
    {
        printf("%s",cmd);
    }
    fclose(fptr);
}
