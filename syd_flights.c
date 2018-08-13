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
void addFlight();
void printFlights();

/*******************************************************************************
 * Global Variables
*******************************************************************************/
 flight_t flights [MAX_NUM_FLIGHTS];
 int numFlights = 0;

/*******************************************************************************
 * Main
*******************************************************************************/
int main(void)
{
    /* TODO */
   

    print_menu();
    int selection = getSelection();
    if(selection != -1)
    {
        handleInput(selection);
    }
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
        return -1;
        printf("Invalid input, not a number\n");
    }
    return -1;
}

void handleInput(int input)
{
    switch(input) {
        case 1: addFlight(); break;
        case 2: printFlights(); break;
        case 3: printf("You want to save the flights to the database file\n"); break;
        case 4: printf("You want load the flights from the database file\n"); break;
        case 5: printf("Program terminated\n"); exit(0); break;
    }
}

void addFlight()
{
    flight_t newFlight;
    int month, day, hour, minute;
    printf("Enter flight code>");
    scanf("%s", newFlight.flightCode);
    

    printf("Enter departure info for the flight leaving SYD.\n" 
    "Enter month, date, hour and minute separated by spaces> ");
    scanf("%d %d %d %d", &month, &day, &hour, &minute);
    newFlight.departure_dt.month = month;
    newFlight.departure_dt.day = day;
    newFlight.departure_dt.hour = hour;
    newFlight.departure_dt.minute = minute;
    
    printf("Enter arrival cite code>");
    scanf("%s", newFlight.arrival_city);

    printf("Enter arrival info. \n"
    "Enter month, date, hour and minute separated by spaces> ");
    scanf("%d %d %d %d", &month, &day, &hour, &minute);
    newFlight.departure_dt.month = month;
    newFlight.departure_dt.day = day;
    newFlight.departure_dt.hour = hour;
    newFlight.departure_dt.minute = minute;

    flights[numFlights] = newFlight;
    ++numFlights;
    
    main();
}

void printFlights()
{   
    int i = 0;
    if(numFlights == 0)
    {
        printf("No flights found\n");
    }
    else
    {
        while(i < numFlights) 
        {
            printf("Flight number: %d \n", i);
            printf("Destination %s\n", flights[i].arrival_city);
            printf("Depature Date (Month Day Hour Minute): %d %d %d %d \n",
            flights[i].departure_dt.month, flights[i].departure_dt.day, 
            flights[i].departure_dt.hour, flights[i].departure_dt.minute);
            printf("Arrival Date (Month Day Hour Minute): %d %d %d %d \n",
            flights[i].arrival_dt.month, flights[i].arrival_dt.day, 
            flights[i].arrival_dt.hour, flights[i].arrival_dt.minute);
            ++i;
        }
    }
}


