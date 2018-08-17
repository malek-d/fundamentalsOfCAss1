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
void dataOperation(char * o);
int isValidDate(int month, int day, int hour, int minute);

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
    print_menu();
    int selection = getSelection();
    if(selection == -1)
    {
        main();	
    }
    handleInput(selection);
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
    int input = 0;

    if (scanf("%d", &input) == 1)
    {
        if(input < 1 || input > 5)
        {
            printf("Invalid choice\n");
            return -1;
        }
        else
        {
            return input;
        }
    }
    else
    {
        printf("Invalid input, not a number\n");
        return -1;
    }
    return -1;
}

void handleInput(int input)
{
    char * write = "w";
    char * read = "r";
    switch(input) {
        case 1: addFlight(); break;
        case 2: printFlights(); break;
        case 3: dataOperation(write); break;
        case 4: dataOperation(read); break;
        case 5: exit(0); break;
    }
}

void addFlight()
{
    if(numFlights != MAX_NUM_FLIGHTS)
    {
        flight_t newFlight;
        int month, day, hour, minute;
        int validator = -1;
        while(validator == -1)
        {
            printf("Enter flight code>\n");
            scanf("%s", newFlight.flightCode);
            if(strlen(newFlight.flightCode) > 6)
            {
                printf("Invalid input\n");
            }
            else
            {
                validator = 0;
            }
        }
        printf("Enter departure info for the flight leaving SYD.\n"); 
        validator = -1;
        while(validator == -1)
        {
            printf("Enter month, date, hour and minute separated by spaces>\n");
            scanf("%d %d %d %d", &month, &day, &hour, &minute);
            validator = isValidDate(month, day, hour, minute);       
        }
        newFlight.departure_dt.month = month;
        newFlight.departure_dt.day = day;
        newFlight.departure_dt.hour = hour;
        newFlight.departure_dt.minute = minute; 

        printf("Enter arrival city code>\n");
        scanf("%s", newFlight.arrival_city);
        newFlight.arrival_city[3] = '\0';
        printf("Enter arrival info.\n");
        validator = -1;
        while(validator == -1)
        {
            
            printf("Enter month, date, hour and minute separated by spaces>\n");
            scanf("%d %d %d %d", &month, &day, &hour, &minute);
            validator = isValidDate(month, day, hour, minute);
        }
        newFlight.arrival_dt.month = month;
        newFlight.arrival_dt.day = day;
        newFlight.arrival_dt.hour = hour;
        newFlight.arrival_dt.minute = minute;
        
        flights[numFlights] = newFlight;
        ++numFlights;
    }
    else
    {
        printf("Cannot add more flights - memory full\n");
    }
    main();
}

void printFlights()
{   
    char arrival_city[MAX_CITYCODE_LEN+1];
    printf("Enter arrival city code or enter * to show all destinations>\n");
    scanf("%s", arrival_city);

    if(strcmp(arrival_city, "*" ) == 0)
    {
        if(numFlights == 0)
        {
            printf("No flights\n");
        }
        else{
            printf("Flight Origin          Destination\n");
            printf("------ --------------- ---------------\n");
            int i = 0;
            while(i < numFlights) 
            {
                printf("%-6s ", flights[i].flightCode);
                printf("SYD %02d-%02d %02d:%02d ", flights[i].departure_dt.month,
                flights[i].departure_dt.day, flights[i].departure_dt.hour, 
                flights[i].departure_dt.minute );
                
                printf("%-3s %02d-%02d %02d:%02d\n", flights[i].arrival_city, 
                flights[i].arrival_dt.month, flights[i].arrival_dt.day, 
                flights[i].arrival_dt.hour, flights[i].arrival_dt.minute);
                ++i;
            }
        }
    }
    else
    {
        int i = 0;
        int matches = 0;
        while(i < numFlights)
        {
            if(strcmp(arrival_city, flights[i].arrival_city) == 0)
            {
                matches++ ;              
            }
            ++i;
        }

        if(matches == 0)
        {
            printf("No flights\n");
        }
        else{
            i = 0;
            printf("Flight Origin          Destination\n");
            printf("------ --------------- ---------------\n");
            while(i < numFlights)
            {
                if(strcmp(arrival_city, flights[i].arrival_city) == 0)
                {
                    printf("%-6s ", flights[i].flightCode);
                    printf("SYD %02d-%02d %02d:%02d ", flights[i].departure_dt.month, flights[i].departure_dt.day, flights[i].departure_dt.hour, flights[i].departure_dt.minute );
                    printf("%-3s %02d-%02d %02d:%02d\n", flights[i].arrival_city, flights[i].arrival_dt.month, flights[i].arrival_dt.day, flights[i].arrival_dt.hour, flights[i].arrival_dt.minute);
                }
                ++i;
            }
        }
    }
    main();
}

int isValidDate(int month, int day, int hour, int minute)
{
    if(month < 1 || month > 12 || day < 1 || day > 31 || hour < 0 || hour > 23 || minute < 0 || minute > 59)
    {
        printf("Invalid input\n");
        return -1;
    } 
    return 0;
}


void dataOperation(char * o)
{
    FILE *fp;
    if(strcmp(o, "w" ) == 0)
    {
        fp = fopen(DB_NAME, "w");   
        int i = 0;

        while(i < numFlights)
        {
            fprintf(fp, "%s %02d %02d %02d %02d %s %02d %02d %02d %02d\n", 
            flights[i].flightCode, flights[i].departure_dt.month, 
            flights[i].departure_dt.day, flights[i].departure_dt.hour, 
            flights[i].departure_dt.minute, flights[i].arrival_city, 
            flights[i].arrival_dt.month, flights[i].arrival_dt.day, 
            flights[i].arrival_dt.hour, flights[i].arrival_dt.minute);
            ++i;
        }
        fclose(fp);
    }
    else if(strcmp(o, "r" ) == 0)
    {
        fp = fopen(DB_NAME, "r"); 
        char currentline[33];
        if(!fp)
        {
            flight_t databaseFlights[MAX_NUM_FLIGHTS];
            int currentFlights = 0;
            while (fgets(currentline, sizeof(currentline), fp) != NULL) {
                /* Use tracker to determine where we are in string and point
                parser to first segment of currentline based on whitespace */
                int tracker = 0;
                char * parser = strtok(currentline, " ");
                char *delimitedWord[50];
                while(parser != NULL)
                {
                    delimitedWord[tracker++] = parser;
                    parser = strtok (NULL, " ");
                }
                flight_t newFlight;
                strcpy(newFlight.flightCode, delimitedWord[0]);

                int charToInt = atoi(delimitedWord[1]);
                newFlight.departure_dt.month = charToInt;

                charToInt = atoi(delimitedWord[2]);
                newFlight.departure_dt.day = charToInt;

                charToInt = atoi(delimitedWord[3]);
                newFlight.departure_dt.hour = charToInt;

                charToInt = atoi(delimitedWord[4]);
                newFlight.departure_dt.minute = charToInt;
                
                strcpy(newFlight.arrival_city,delimitedWord[5]);

                charToInt = atoi(delimitedWord[6]);
                newFlight.arrival_dt.month = charToInt;

                charToInt = atoi(delimitedWord[7]);
                newFlight.arrival_dt.day = charToInt;

                charToInt = atoi(delimitedWord[8]);
                newFlight.arrival_dt.hour = charToInt;

                charToInt = atoi(delimitedWord[9]);
                newFlight.arrival_dt.minute = charToInt;
                databaseFlights[currentFlights++] = newFlight; 
            }
            if(numFlights != 0){
                memset(flights, 0, sizeof(flights));
            }
            int i = 0;
            while(i < currentFlights)
            {
                flights[i] = databaseFlights[i];
                ++i;
            }
            numFlights = currentFlights;
        }
        else
        {
            printf("Read error\n");
        }
        fclose(fp);
    }
    main();
}
