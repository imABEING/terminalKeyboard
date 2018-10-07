//ROLEX ALEXX
//TERMINAL KEYBOARD
//
//
//
//to compile: make terminalKeyboard
//to run: ./terminalKeyboard
//
//
//

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdio>
#include <string.h>
#include <cstdlib>
using namespace std;

#define NEWLINE '\n'
#define LINE "___________________________________"
#define TITLE "  TERMINAL KEYBOARD"
#define AUTHOR "  by ROLEX ALEXX"
#define SIZE 12

class terminalKeyboard {
    FILE *Point;
    char csdFile[256] = "terminalKeyboard.csd";
    char commandline [1000] = "csound -odac -d -O null ";

public:
    int system();
    int exit();
    int sort();
    void heading();
    void keyboardUI();

    terminalKeyboard();
    ~terminalKeyboard();

private:
    //string n ("SIZE");
    float freq;
    int reps;
    int myInt;
    char note;
    int* data;
};

terminalKeyboard::terminalKeyboard(){
    data = new int;
}

terminalKeyboard::~terminalKeyboard() {
    delete[] data;
}

void terminalKeyboard::heading()
{
    ::system("clear");
	cout << "\n \t \t \t " << LINE << " \n";
	cout << "\n \t \t \t \t " << TITLE << " \n";
	cout << "\n \t \t \t \t " << AUTHOR << "\n";
	cout << "\t \t \t " << LINE << "\n";
	cout << "\n \t \t \t " << LINE << " \n";
    cout << NEWLINE; 

}

void terminalKeyboard::keyboardUI()
{
    heading();
    cout << NEWLINE << NEWLINE << NEWLINE << NEWLINE; 


    cout << "\t \t \t ==== ====  ==== == ==== === ===== ===== ==";
    cout << NEWLINE;
    cout << "\t \t \t!    |    ||    |  !  |     |     |     |  !";
    cout << NEWLINE;
    cout << "\t \t \t!    |    ||    |  !  |     |     |     |  !";
    cout << NEWLINE;
    cout << "\t \t \t!    |    ||    |  !  |     |     |     |  !";
    cout << NEWLINE;
    cout << "\t \t \t!    |  W ||  E |  !  |  T  |  Y  |  U  |  !";
    cout << NEWLINE;
    cout << "\t \t \t!    |    ||    |  !  |     |     |     |  !";
    cout << NEWLINE;
    cout << "\t \t \t!    |    ||    |  !  |     |     |     |  !";
    cout << NEWLINE;
    cout << "\t \t \t!    |    ||    |  !  |     |     |     |  !";
    cout << NEWLINE;
    cout << "\t \t \t!     ----  ----   !   ----- ----- -----   !";
    cout << NEWLINE;
    cout << "\t \t \t!      |     |     !     |     |     |     !";
    cout << NEWLINE;
    cout << "\t \t \t!      |     |     !     |     |     |     !";
    cout << NEWLINE;
    cout << "\t \t \t!      |     |     !     |     |     |     !";
    cout << NEWLINE;
    cout << "\t \t \t!   A  |  S  |  D  !  F  |  G  |  H  |  J  !";
    cout << NEWLINE;
    cout << "\t \t \t!      |     |     !     |     |     |     !";
    cout << NEWLINE;
    cout << "\t \t \t!      |     |     !     |     |     |     !";
    cout << NEWLINE;
    cout << "\t \t \t ====== ===== ===== ===== ===== ===== =====";
    cout << NEWLINE;

    cout << NEWLINE << NEWLINE << NEWLINE << NEWLINE;

    cout << "\t \t \t \t Enter X to EXIT";
    cout << NEWLINE << NEWLINE;
}

int terminalKeyboard::exit()
{
    return 0;
}

int terminalKeyboard::sort()
{     
    keyboardUI();

      cin >> note;

          switch(note)
        {   
            case 'a':
            freq=523.25;
            //C
            break;

            case 'w':
            freq=554.37;
            cout << "C#";
            //C#
            break;
                
            case 's':
            freq=587.33;
            //D
            break;    
            
            case 'e':
            freq=622.25;
            //D#
            break;
            
            case 'd':
            freq=659.25;
            //E
            break;

            case 'f':
            freq=698.46;
            //F
            break;

            case 't':
            freq=739.99;
            //F#
            break;

            case 'g':
            freq=783.99;
            //G
            break;

            case 'y':
            freq=830.61;
            //G#
            break;

            case 'h':
            freq=880.00;
            //A
            break;

            case 'u':
            freq=932.33;
            //A#
            break;

            case 'j':
            freq=987.77;
            //B
            break;

            case 'x':
            return 0;
            break;

            default:
                printf("That was not a note name.");
        }

    Point = fopen(csdFile, "w");
    if(Point != NULL)
        
    {   
           
        fprintf(Point,"<CsoundSynthesizer>\n");
        fprintf(Point,"<CsInstruments>\n");
        fprintf(Point,"instr testing\n");
        fprintf(Point," a1 oscili 10000, p5, 1\n");
        fprintf(Point," k1 linen 1, .2, p3, .1\n");
        fprintf(Point," out a1 * k1\n");
        fprintf(Point,"endin\n");
        fprintf(Point,"</CsInstruments>\n");
        fprintf(Point,"<CsScore>\n");
        fprintf(Point,"f 1  0 8192 10   1 ; GEN10 to compute a sine wave\n");

        
        fprintf(Point,"i \"testing\" %d .2 0 %f\n", reps, freq);
        
        
        fprintf(Point,"e 0.3\n");
        fprintf(Point,"</CsScore>\n");
        fprintf(Point,"</CsoundSynthesizer>\n");
    }
    
    fclose(Point);
    strcat(commandline, csdFile);
    ::system (commandline);
       
    cout << "You entered: " << note << "\n";

    sort();

return 0;
}

int main()
{
    terminalKeyboard run;
    run.sort();
    return 0;
}
