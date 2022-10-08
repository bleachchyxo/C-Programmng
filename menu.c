#include <termios.h>
#include <stdio.h>

static struct termios old, new;

/* Initialize new terminal i/o settings */
void initTermios(int echo){
        tcgetattr(0, &old); //grab old terminal i/o settings
        new = old; //make new settings same as old settings
        new.c_lflag &= ~ICANON; //disable buffered i/o
        new.c_lflag &= echo ? ECHO : ~ECHO; //set echo mode
        tcsetattr(0, TCSANOW, &new); //apply terminal io settings
}

/* Restore old terminal i/o settings */
void resetTermios(void){
        tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch_(int echo){
        char ch;
        initTermios(echo);
        ch = getchar();
        resetTermios();
        return ch;
}

/*
 * Read 1 character without echo
 * getch() function definition.
 */
char getch(void){
        return getch_(0);
}

/*
 * Read 1 character with echo
 * getche() function definition.
 */
char getche(void){
        return getch_(1);
}

int main(void){
        char c;
        char cong[15] = ">Continue Game";
        char newg[10] = " New Game";
        char exitg[6] = " Exit";
        int mainmenu = 1;
        int mmenu = 3;

        while (mainmenu == 1){

        system("clear");
        printf("%s\n", cong);
        printf("%s\n", newg);
        printf("%s\n", exitg);

        c = getche();

        if(c == 'w'){
                mmenu++;
        }
        else if(c == 's'){
                mmenu--;
        }
        else if(c == 'k'){
                mmenu = 10;
        }
        else{
                printf("Not valid key\n");
        }

        switch(mmenu){
                case 10:
                        mainmenu = 2;
                        break;
                case 4:
                        mmenu = 3;
                        break;
                case 0:
                        mmenu = 1;
                        break;
                case 3:
                        cong[0] = '>';
                        newg[0] = ' ';
                        exitg[0] = ' ';
                        break;
                case 2:
                        cong[0] = ' ';
                        newg[0] = '>';
                        exitg[0] = ' ';
                        break;
                case 1:
                        cong[0] = ' ';
                        newg[0] = ' ';
                        exitg[0] = '>';
                        break;
        }

        system("clear");

        }


}
