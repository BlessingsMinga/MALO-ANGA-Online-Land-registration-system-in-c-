//--------------------MALO ANGA APPLICATION-----------------------------

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include<time.h>
#include<ctype.h>
#include <process.h>

#define PR 2

void reg();
void login();
void signup();
int valiUser();
int valiAdmin();

void show_ins();
int search_u();

void starting();
void waitL();
void wait();
char printer(char s[]);

void logo();
void logo2();

//structuring coordinates
void gotoxy ( int x, int y){
	
	COORD C;
	C.X=x;
	C.Y=y;
	
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),C);
}


//Creating a structure for the user 
struct reg
{
	char name[20];
	
	char last[20];
	
	char email[20];
	
	char phone[11];
	
	char address[20];
	
	char password[10];
	
	char id[10];
	
};

//Global variables
struct reg user_num[5]; // Maximum 5 user can create an account
int size = 0;

//Creating a structure for the administrater
struct admin
{
	char user[10];
	
	char pass[10];
		
} ad;

int valid_Email(char email[]){
	int i;
	
	for(i=0;email[i] !='\0';i++){
		if(email[i] == '@'){
			return 1; //valid email
		}
	}
	
	Beep(750, 800);
    printf("Invalid email. it must contain '@' symbol.\n");
	return 0; //invalid email
}
int pass_len(char pass[]){
	
	int i;
	
	for(i=0;pass[i]!='\0';i++){
		
	}
	if(i<8){
		Beep(750, 800);
		printf("PASSWORD IS TOO SHORT.\n");
	}
	
	return i;
}

int main()
{
	starting();
	int ch;
	
	
	while(1)
	{
		
		system("color F");
		logo2();
		printf("\n\n\t\t\t   -> LOGIN\t[1]");
		printf("\n\n\t\t\t   -> SIGN UP\t[2]");
		printf("\n\n\t\t\t   -> EXIT\t\t[3]");
		printf("\n\n\t\t\t->   ENTER YOUR CHOICE: ");
		scanf("%d", &ch);
		
		system("cls");
		switch(ch)
		{
			case 1:{
				//system("cls");
			    login();
				break;
			}
			
			case 2:{
				signup();
				break;
			}
		}
		
	}
	
	return 0;
	
}

/**************** SIGNUP PROTOTYPE************************/

void signup( )
{
	
			FILE *ac;
			struct reg a;
			int valid = 0;
			
			
			system("color F");
			logo2();
		    printf("\n  **************************  SIGNUP FORM  **************************  \n\n");
		    show_ins();
		    
		    ac = fopen("accounts.txt", "a+");
		    if(ac == NULL){
		    	printf("FILE COULDN'T OPEN.");
			}
		    
		    printf("ENTER YOUR FIRST NAME: ");
		    scanf("%s", &a.name);
		    fgets(a.name, sizeof(a.name), stdin);
			
			printf("ENTER YOUR LAST NAME: ");
		    scanf("%s", &a.last);
		    fgets(a.last, sizeof(a.last), stdin);
		    
		    do{
		    	printf("ENTER YOUR EMAIL: ");
		    	scanf("%s", &a.email);
			}while(valid_Email(a.email) == 0);
			fgets(a.email, sizeof(a.email),stdin);         
			
			printf("ENTER YOUR PHONE NUMBER: ");
		    scanf("%s", &a.phone);
		    fgets(a.phone, sizeof(a.phone), stdin);
		    
		    printf("ENTER YOUR ADDRESS (CURRENT LOCATION): ");
		    scanf("%s", &a.address);
		    fgets(a.address, sizeof(a.address), stdin);
		    
		    do{
		    	printf("ENTER YOUR PASSWORD: ");
		    	scanf("%s", &a.password);
			}while(pass_len(a.password)<8);
			fgets(a.password, sizeof(a.password), stdin);
			
			fprintf(ac,"First Name: %sLast Name: %sEmail: %sPhone Number: %sAddress: %sPassword: %s",a.name, a.last, a.email, a.phone, a.address, a.password);
			
			
			user_num[size]= a;
			size++;
			
			printf("\n\n\tYOUR ACCOUNT HAS BEEN CREATED SUCCESSFULLY...%c%c", PR, PR);
		 
		    printf("\n\t_________________________________________________");
		    
		    fclose(ac);
		    
		    printf("\n\n\tPRESS ANY KEY TO EXIT....");
			getch();
			system("cls");	
		 }
         
         
	
	

void login()
{
	FILE * ac = fopen("Account.txt", "rb"); // Creating a user file text
	int b=0,i=0;
	char email[10],c=' ';
	char pword[10],code[10];
	
	//Copying the administrators username and password to the admin struct
	strcpy(ad.user,"admin");
	strcpy(ad.pass,"123");
	
	do
	{
	
	system("color F");	
	logo2();
    printf("\n **************************  LOGIN FORM  **************************  ");
    
    printf(" \n                       ENTER EMAIL: ");
    
    int index=search_u(email);
    
    if(index<0){
    	printf("USER DOESN'T EXIST...!");
	}
    scanf("%s", &email);
    printf(" \n                       ENTER PASSWORD: ");
    
    while(i<10)
    {
    	pword[i]=getch();
    	c=pword[i];
    	if(c==13) break;
    	else printf("*"); //Turning characters entered into arsterisk
    	i++;
	}
	pword[i]='\0';
	//char code=pword
	i=0;
	//scanf("%s",&pword);
    
    if(strcmp(email,ad.user)==0 && strcmp(pword,ad.pass)==0){
    	
    printf("  \n\n\n       WELCOME TO MALO ANGA ONLINE REGISTRATION SYSTEM  !! YOUR LOGIN IS SUCCESSFUL");
	printf("\n\n\n\t\t\t\tPress any key to continue...");
	getch();//holds the screen
	break;
	
	}
	else 
	{
		// Function that beeps a sound of
        // frequency 750 for 0.8 sec
        Beep(750, 800);
		printf("\n			SORRY !!! LOGIN IS UNSUCCESSFUL");
		b++;
		getch();
		printf("\n");
	}
		
	}while(b<=2);
	
	if(b>2)
	{
		printf("\nSORRY YOU HAVE ENTERED THE WRONG USERNAME AND PASSWORD FOR FOUR TIMES!!!\n");
		getch();
		system("cls");
	}
	

	system("cls");
}

int search_u( char email[]){
	
	int i,j;
	
	for(i=0;i<size;i++){
		for(j=0; user_num[i].email[j]!='\0'; j++){
			if(email[j] != user_num[i].email[j]){
				break;
			}
		}
		if(user_num[i].email[j] == '\0'  && email[j] == '\0' ){
			return i;
		}
	}
	return -1;
}

void show_ins(){
	printf("Instructions:\n");
	printf("Now please choose a email and password as credentials for system login.\n");
	printf("Email must contains @ symbol.\n");
	printf("Ensure your password is at least 8 characters long.\n\n"); 

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
        
         while(!kbhit());
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