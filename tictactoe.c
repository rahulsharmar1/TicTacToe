#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
int showboard(char a[]);
int mark(int m, char a[], char p);
int checkwin(char a[]);
int main()
{
/****************Game STARTS****************/
	int choice,mrk,ck,i,win,chance,agn;
	char player[3];
	char xo[10];
/**********Intro and Choice - Page 1**********/
	strt:
	
	choice=0;
	mrk=0;
	ck=0;
	win=1;
	chance=0;
	strcpy(player,"  ");
	strcpy(xo,"123456789");

	printf("TicTacToe X|O\t\tBy RS\n");
	while(choice==0)
	{
		printf("Player 1\nSelect Between X O\n");
		printf("1. X\n2. O\n:  ");
		scanf("%d",&choice);
		choice=(int)choice;
		if (choice==1||choice==2)
		{
			player[0]=(choice==1)?'X':'O';
			player[1]=(choice==1)?'O':'X';
		}
		else
		{
		printf("\nInvalid Choice!!\n\n");
		choice=0;
		}
	}
	printf("\n\nYour Choice is %c",player[0]);
	printf("\nPlayer 1 : %c\nPlayer 2 : %c",player[0],player[1]);
	printf("\n\n\nPress any key to continue...");
	getch();
	system("cls");
/****************Page 1 ENDS****************/

/**********How to Play - Page 2**********/
	printf("TicTacToe X|O\t\tBy RS\n");
	printf("\n\nHow To Play:-\n\n");
	showboard(xo);
	printf("\n\nInput Like This");
	printf("\n\n\nPress any key to continue...");
	getch();
	system("cls");
/****************Page 2 ENDS****************/

/**********Game Starts - Page 3**********/
	strcpy(xo,"         ");
	while(chance<9 && win!=0)
	{
		for (i = 0; i < 2 && win!=0 && chance<9; ++i)
		{
			again:
			printf("TicTacToe X|O\t\tBy RS\n");
			showboard(xo);
			printf("\n\nEnter where to mark Player %d : ",i+1);
			scanf("%d",&mrk);
			if (mrk>0 && mrk<=9)
			{
				ck=mark(mrk,xo,player[i]);
				if (ck==1)
				{
					goto again;
				}
			}
			else
			{
				printf("\nEnter Right Choice. Between 1 To 9...\n\n");
				mrk=0;
			}
			chance++;
			win=checkwin(xo);
		}
	}
	if (win==0)
	{
		system("cls");
		printf("TicTacToe X|O\t\tBy RS\n");
		showboard(xo);
		printf("\nPlayer %d Wins the Game\n",i);
	}
	else
	{
		system("cls");
		printf("TicTacToe X|O\t\tBy RS\n");
		showboard(xo);
		printf("\nMatch Draws\n");
	}
/****************Page 3 ENDS****************/

	printf("\n\n\nPress any key to continue...");
	getch();
	system("cls");
	printf("\n\nWant to play again? (Press 1) Or Exit by entering 2!! : ");
	scanf("%d",&agn);
	if (agn==1)
	{
		system("cls");
		goto strt;
		
	}
	else
	{
		printf("\nThank You For Playing..");
		printf("\n\n\nPress any key to continue...");
	}
	getch();
	return 0;
/****************Game ENDS****************/
}

int showboard(char a[])
{
	printf("\n");
	printf("\t   |   |   \n");
	printf("\t %c | %c | %c \n",a[0],a[1],a[2]);
	printf("\t   |   |   \n");
	printf("      ---------------\n");
	printf("\t   |   |   \n");
	printf("\t %c | %c | %c \n",a[3],a[4],a[5]);
	printf("\t   |   |   \n");
	printf("      ---------------\n");
	printf("\t   |   |   \n");
	printf("\t %c | %c | %c \n",a[6],a[7],a[8]);
	printf("\t   |   |   \n");
	return 0;
}

int mark(int m, char a[], char p)
{
	if (a[m-1]=='X' || a[m-1]=='O')
	{
		printf("\n\nAlerdy Used!!!!\n\n");

		return 1;
	}
	else
	{
		switch (m)
		{
			case 1:
				a[0]=p;
				break;
			case 2:
				a[1]=p;
				break;
			case 3:
				a[2]=p;
				break;
			case 4:
				a[3]=p;
				break;
			case 5:
				a[4]=p;
				break;
			case 6:
				a[5]=p;
				break;
			case 7:
				a[6]=p;
				break;
			case 8:
				a[7]=p;
				break;
			case 9:
				a[8]=p;
				break;
			default:
				printf("Error\n");
				break;
		}
	}
	return 0;
}

int checkwin(char a[])
{
	/******************************************Horizontal Win******************************************/
	if ( (a[0]=='X' && a[1]=='X' && a[2]=='X') || (a[0]=='O' && a[1]=='O' && a[2]=='O') )
	{
		
		return 0;
	}
	else if ( (a[3]=='X' && a[4]=='X' && a[5]=='X') || (a[3]=='O' && a[4]=='O' && a[5]=='O') )
	{
		
		return 0;
	}
	else if ( (a[6]=='X' && a[7]=='X' && a[8]=='X') || (a[6]=='O' && a[7]=='O' && a[8]=='O') )
	{
		
		return 0;
	}
	/*************************************XXX Horizontal Win XXX*************************************/

	/******************************************Vertical Win******************************************/
	else if ( (a[0]=='X' && a[3]=='X' && a[6]=='X') || (a[0]=='O' && a[3]=='O' && a[6]=='O') )
	{
		
		return 0;
	}
	else if ( (a[1]=='X' && a[4]=='X' && a[7]=='X') || (a[1]=='O' && a[4]=='O' && a[7]=='O') )
	{
		
		return 0;
	}
	else if ( (a[2]=='X' && a[5]=='X' && a[8]=='X') || (a[2]=='O' && a[5]=='O' && a[8]=='O') )
	{
		
		return 0;
	}
	/*************************************XXX Vertical Win XXX*************************************/

	/******************************************Diagonal Win******************************************/
	else if ( (a[0]=='X' && a[4]=='X' && a[8]=='X') || (a[0]=='O' && a[4]=='O' && a[8]=='O') )
	{
		
		return 0;
	}
	else if ( (a[2]=='X' && a[4]=='X' && a[6]=='X') || (a[2]=='O' && a[4]=='O' && a[6]=='O') )
	{
		
		return 0;
	}
	/*************************************XXX Diagonal Win XXX*************************************/
	return 1;
}