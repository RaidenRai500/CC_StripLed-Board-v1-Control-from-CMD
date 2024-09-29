#ifndef CC_CMD_CONTROL_SERIAL_H
    #define CC_CMD_CONTROL_SERIAL_H
    //Headers

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
    #define MESSAGE12               "Red light activated\n\r"
    #define MESSAGE13               "Green light activated\n\r"
    #define MESSAGE14               "Blue light activated\n\r"
    #define MESSAGE15               "White light activated\n\r"
    #define MESSAGE16               "Yellow light activated\n\r"
    #define MESSAGE17               "Pink light activated\n\r"
    #define MESSAGE18               "Cyan light activated\n\r"
    #define MESSAGE19               "Lights off\n\r"
    //#define MESSAGE20
    #define MESSAGE_RETURN 	        "\n\r"
    #define MESSAGE_TRIPLERETURN 	"\n\r\n\r\n\r"
    #define TRUE 1
    #define FALSE 0

    //Data types

    //Variables prototypes
    extern HANDLE hSerialPort;

    //Function prototypes
    void setcolor(char);
    void clearInputBuffer(void);
    void openSerialPort(const char*, DWORD);
    void sendCharacter(char);

#endif /*CC_CMD_CONTROL_SERIAL_H*/