/*******************************************************************************
 * 48430 Fundamentals of C Programming - Assignment 2
 * Name: Malek Darwiche
 * Student ID: 12580357
 * Date of submission:
 * A brief statement on what you could achieve (less than 50 words):
 * 
 * 
 * A brief statement on what you could NOT achieve (less than 50 words):
 * 
 * 
*******************************************************************************/

/*******************************************************************************
 * List header files - do NOT use any other header files. Note that stdlib.h is
 * included in case you want to use any of the functions in there. However the
 * task can be achieved with stdio.h and string.h only.
*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*******************************************************************************
 * List preprocessing directives - you may define your own.
*******************************************************************************/
#define MAX_FLIGHTCODE_LEN 6
#define MAX_CITYCODE_LEN 3
#define MAX_NUM_FLIGHTS 5
#define DB_NAME "database"

/*******************************************************************************
 * List structs - you may define struct date_time and struct flight only. Each
 * struct definition should have only the fields mentioned in the assignment
 * description.
*******************************************************************************/
struct date_time
{
    int month;
    int day;
    int hour;
    int minute;
};
typedef struct date_time date_time_t;

struct flight 
{
    char flightCode[MAX_FLIGHTCODE_LEN+1];
    date_time_t departure_dt;
    char arrival_city[MAX_CITYCODE_LEN+1];
    date_time_t arrival_dt;
};
typedef struct flight flight_t;
/*******************************************************************************
 * Function prototypes - do NOT change the given prototypes. However you may
 * define your own functions if required.
*******************************************************************************/
void print_menu (void);
int getSelection();
void handleInput(int input);
/*******************************************************************************
 * Main
*******************************************************************************/
int main(void)
{
    /* TODO */
    flight_t flights [MAX_NUM_FLIGHTS];

    print_menu();
    int selection = getSelection();


    return 0;
}

/*******************************************************************************
 * This function prints the initial menu with all instructions on how to use
 * this program.
 * inputs:
 * - none
 * outputs:
 * - none
*******************************************************************************/
void print_menu (void)
{
    printf("\n"
    "1. add a flight\n"
    "2. display all flights to a destination\n"
    "3. save the flights to the database file\n"
    "4. load the flights from the database file\n"
    "5. exit the program\n"
    "Enter choice (number between 1-5)>\n");
}

int getSelection(){
    int input;

    if (scanf("%d", &input) == 1)
    {
        if(input < 1 || input > 6)
        {
            printf("Invalid input, please provide a number between 1-5\n");
        }
        else
        {
            /*printf("You have entered %d\n", input);*/
            return input;
        }
    }
    else
    {
        printf("Invalid input, not a number\n");
    }
}

void handleInput(int input)
{
    switch(input) {
        case 1: printf("You want to add a flight\n"); break;
        case 2: printf("You want to list all flights to a destination\n"); break;
        case 3: printf("You want to save the flights to the database file\n"); break;
        case 4: printf("You want load the flights from the database file\n"); break;
        case 5: printf("Program terminated\n"); exit(0); break;
    }
}

