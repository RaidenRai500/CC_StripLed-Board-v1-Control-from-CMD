//Headers
#include <stdio.h>                  //For printf, scanf and getchar
#include <windows.h>                //For serial communication
#include "CC_CmdControlSerial.h"    //Main function

//Global variables declaration
HANDLE hSerialPort;

//Functions
int main()
{    
    char caption=0;
    unsigned char out=FALSE;

    openSerialPort("COM3", 115200);
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
        caption=0;                          //Clean the character gotten
        scanf ("%c", &caption);             //Get the character
        clearInputBuffer();                 //Clean the serial's input buffer
        if (
            (caption=='R'||caption=='r')||  //Check if a correct color is selected
            (caption=='G'||caption=='g')||
            (caption=='B'||caption=='b')||
            (caption=='W'||caption=='w')||
            (caption=='Y'||caption=='y')||
            (caption=='P'||caption=='p')||
            (caption=='C'||caption=='c')||
            (caption=='O'||caption=='o')
            )
        {
            setcolor(caption);                  //If so, is send to the board              
            out=FALSE;                          //Loop again
        }
        else if ((caption=='E'||caption=='e'))  //Check for an exit order
        {
            out=TRUE;                           //Loop exit
            printf (MESSAGE11);         
        }
        else
        {
            printf (MESSAGE10);                 //If not, error message
        }
    }  
    return 0;
}

void setcolor(char action)
{
    if (action=='R'||action=='r')
    {
        printf (MESSAGE12);     //Message to the user
        sendCharacter('R');     //Order to the board
    }
    if (action=='G'||action=='g')
    {
        printf (MESSAGE13);
        sendCharacter('G');
    }
    if (action=='B'||action=='b')
    {
        printf (MESSAGE14);
        sendCharacter('B');
    }
    if (action=='W'||action=='w')
    {
        printf (MESSAGE15);
        sendCharacter('W');
    }
    if (action=='Y'||action=='y')
    {
        printf (MESSAGE16);
        sendCharacter('Y');
    }
    if (action=='P'||action=='p')
    {
        printf (MESSAGE17);
        sendCharacter('P');
    }
    if (action=='C'||action=='c')
    {
        printf (MESSAGE18);
        sendCharacter('C');
    }
    if (action=='O'||action=='o')
    {
        printf (MESSAGE19);
        sendCharacter('O');
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
void openSerialPort(const char* portName, DWORD baudRate)
{
    hSerialPort = CreateFileA(portName, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hSerialPort == INVALID_HANDLE_VALUE)
    {
        // Handle error
    }

    DCB dcb = { 0 };
    dcb.DCBlength = sizeof(DCB);
    if (!GetCommState(hSerialPort, &dcb))
    {
        // Handle error
    }

    dcb.BaudRate = baudRate;
    dcb.ByteSize = 8;
    dcb.StopBits = ONESTOPBIT;
    dcb.Parity = NOPARITY;
    if (!SetCommState(hSerialPort, &dcb))
    {
        // Handle error
    }
}

void sendCharacter(char character)
{
    DWORD bytesWritten;                                                 // Number of bytes written. Returned by WriteFile
    if (!WriteFile(hSerialPort, &character, 1, &bytesWritten, NULL))
    {
        // Handle error
    }
}
