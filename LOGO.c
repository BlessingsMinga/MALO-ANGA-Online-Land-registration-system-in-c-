#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include<time.h>
#include<ctype.h>
#include <time.h>
#include <windows.h>
#include <process.h>

void gotoxy ( int x, int y){
	
	COORD C;
	C.X=x;
	C.Y=y;
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),C);
}

void starting();
void waitL();
void wait();
char printer(char s[]);

void logo();
void logo2();


int main (){
	
	starting();
	

	}
	
	
	void logo()
	{  
	
	    int i = 1;
	    
		gotoxy(90,0);
		system("color F");
		logo2();
			
		printf("\t\t\t  __________________________  WAIT ____________________________\n\n");
		//getch();
		   
		while(i<2)
	    {
		   	
		system("color 9");
        waitL();
        system("color 1");
        waitL();
        system("color 9");
        waitL();
        system("color A");
        waitL();
        system("color 2");
        waitL();
        system("color A");
        waitL();
        system("color B");
        waitL();
        system("color 3");
        waitL();
        system("color B");
        waitL();
        system("color C");
        waitL();
        system("color 4");
        waitL();
        system("color C");
        waitL();
        system("color D");
        waitL();
        system("color 5");
        waitL();
        system("color D");
        waitL();
        system("color E");
        waitL();
        system("color 6");
        waitL();
        system("color E");
        waitL();
        system("color F");
        i++;
    }
 }
	
	void logo2(){
		   printf("\n\t\t\t  _____________________________________________________________\n"
		   "\n\t\t\t  \xB2\xB2\xB2\xB2         \xB2\xB2\xB2\xB2\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t \xB2\xB2\xB2\t      \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"
		   "\n\t\t\t  \xB2\xB2\xB2\xB2\xB2\xB2     \xB2\xB2\xB2\xB2\xB2\xB2\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t \xB2\xB2\xB2\t      \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"
		   "\n\t\t\t  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t\xB2\xB2\xB2       \xB2\xB2\xB2\t \xB2\xB2\xB2\t      \xB2\xB2\xB2   \xB2\xB2\xB2"
		   "\n\t\t\t  \xB2\xB2\xB2  \xB2\xB2\xB2\xB2\xB2\xB2\xB2  \xB2\xB2\xB2\t\xB2\xB2\xB2       \xB2\xB2\xB2\t \xB2\xB2\xB2\t      \xB2\xB2\xB2   \xB2\xB2\xB2"
		   "\n\t\t\t  \xB2\xB2\xB2    \xB2\xB2\xB2    \xB2\xB2\xB2\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\t \xB2\xB2\xB2\t      \xB2\xB2\xB2   \xB2\xB2\xB2"
		   "\n\t\t\t  \xB2\xB2\xB2           \xB2\xB2\xB2\t\xB2\xB2\xB2       \xB2\xB2\xB2\t \xB2\xB2\xB2\t      \xB2\xB2\xB2   \xB2\xB2\xB2"
		   "\n\t\t\t  \xB2\xB2\xB2           \xB2\xB2\xB2\t\xB2\xB2\xB2       \xB2\xB2\xB2\t \xB2\xB2\xB2\t      \xB2\xB2\xB2   \xB2\xB2\xB2"
		   "\n\t\t\t  \xB2\xB2\xB2           \xB2\xB2\xB2\t\xB2\xB2\xB2       \xB2\xB2\xB2\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2    \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2"
		   "\n\t\t\t  \xB2\xB2\xB2           \xB2\xB2\xB2\t\xB2\xB2\xB2       \xB2\xB2\xB2\t \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2    \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n"
		   "\n\t\t\t  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 A N G A  L A N D  R E G I S T R A T I O N \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		   printf("\n\t\t\t  _____________________________________________________________\n");
	}
	void wait(){
	int i;
    for(i=0;i<6000000;i++);
}
void waitL(){
	int i;
    for(i=0;i<25;i++)
    {
        wait();
    }
}

void starting()
{
	int i;
	char s1[]="\xB2\xB2 WELCOME... \xB2\xB2";
	char s2[]="PRESS ANY KEY TO CONTINUE";
	
	waitL();
	waitL();
	
	
	
	gotoxy(50,0);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t");
	printer(s1);
	waitL();
	waitL();
	printf("\n");
	gotoxy(50,0);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t");
	printer(s2);
	while(!kbhit()); //pause execution of a program until a key is pressed 
	system("cls");
	
	logo();
	
	for(i=0;i<10;i++){
		waitL();
	}
	system("cls");
}
char printer(char s[])
{
    int i=0;
    while(s[i]!='\0')
    {
        printf("%c",s[i]);
        wait();
        wait();
        i++;
    }
}

