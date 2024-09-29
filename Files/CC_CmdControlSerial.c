//Includes
#include <stdio.h>

//Constants
#define MESSAGE1                "Welcome to the strip leds control\n\r"
#define MESSAGE2                "The application which allows you to control your led lights\n\r"
#define MESSAGE3                "Running over the hardware: "
#define HARDWARE                "Should be asked to the board\n\r"
#define MESSAGE4                "With a uC: "
#define MICROCONTROLLER         "Should be asked to the board\n\r"
#define MESSAGE5                "Board's firmware version: "
#define FIRMWARE_VER            "Should be asked to the board\n\r"
#define MESSAGE6                "Board identifier: "
#define BOARD_ID                "Should be asked to the board\n\r"
#define MESSAGE7                "Software running over command-prompt version: "
#define SOFTWARE_VER            "version 0.1\n\r"
#define MESSAGE8                "Please select the color you would like\n\r"
#define MESSAGE9                "Red(R)\n\rGreen(G)\n\rBlue(B)\n\rWhite(W)\n\rYellow(Y)\n\rPink(P)\n\rCyan(C)\n\rOff(O)\n\rOr just exit the application(E)\n\r"
#define MESSAGE10               "Wrong selection, please try again\n\r"
#define MESSAGE11               "Thanks for using our devices\n\rGoodbye!\n\r"
#define MESSAGE_RETURN 	        "\n\r"
#define MESSAGE_TRIPLERETURN 	"\n\r\n\r\n\r"
#define TRUE 1
#define FALSE 0

//Function prototypes
void setcolor(void);
void clearInputBuffer(void);

//Global variables
char caption=0;
unsigned char out=FALSE;

int main()
{
    printf (MESSAGE1);
    printf (MESSAGE2);
    printf (MESSAGE3);
    printf (HARDWARE);
    printf (MESSAGE4);
    printf (MICROCONTROLLER);
    printf (MESSAGE5);
    printf (FIRMWARE_VER); 
    printf (MESSAGE6);
    printf (BOARD_ID);
    printf (MESSAGE7);
    printf (SOFTWARE_VER);
    printf (MESSAGE8);
    printf (MESSAGE9);

    while (out==FALSE)
    {
        caption=0;
        scanf ("%c", &caption);
        clearInputBuffer();
        if (
            (caption=='R'||caption=='r')||
            (caption=='G'||caption=='g')||
            (caption=='B'||caption=='b')||
            (caption=='W'||caption=='w')||
            (caption=='Y'||caption=='y')||
            (caption=='P'||caption=='p')||
            (caption=='C'||caption=='c')||
            (caption=='O'||caption=='o')
            )
        {
            setcolor();
            out=FALSE;
        }
        else if ((caption=='E'||caption=='e'))
        {
            out=TRUE;
            printf (MESSAGE11);
        }
        else
        {
            printf (MESSAGE10);
        }
    }  
    return 0;
}

void setcolor(void)
{
    if (caption=='R'||caption=='r')
    {
        printf ("Leds vermell\n\r");
    }
    if (caption=='G'||caption=='g')
    {
        printf ("Leds verd\n\r");
    }
    if (caption=='B'||caption=='b')
    {
        printf ("Leds blau\n\r");
    }
    if (caption=='W'||caption=='w')
    {
        printf ("Leds blanc\n\r");
    }
    if (caption=='Y'||caption=='y')
    {
        printf ("Leds groc\n\r");
    }
    if (caption=='P'||caption=='p')
    {
        printf ("Leds rosa\n\r");
    }
        if (caption=='C'||caption=='c')
    {
        printf ("Leds cian\n\r");
    }
    if (caption=='O'||caption=='o')
    {
        printf ("Leds apagats\n\r");
    }
}

void clearInputBuffer(void)
//Function to clean the input buffer
{
    char character;
    
    do
    {
        character=getchar();                            //Gets a character from input buffer 
    } while ((character!='\n') && (character!=EOF));    //Until the end of string or end of file
}