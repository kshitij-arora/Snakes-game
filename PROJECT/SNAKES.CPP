//snakes******************************************************************/
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<fstream.h>
#include "PROJECT\UTILITY.cpp"
#include "PROJECT\BOXFUNC.cpp"
int diff=0;
int score=0;
/**********************________MAINTAINING_LEADERBOARD________***************/
 class ldb
 {
    int scr;
    char nm[20];
    char diffi[10];
    public:
    void display()
    {
       cout<<rank<<".   \t"<<nm;
       gotoxy(17,rank+1);
       cout<<scr;
       gotoxy(25,rank+1);
       cout<<diffi<<endl;
    }
    void read()
    {
       cout<<"please enter name:";
       gets(nm);
       scr=score;
    }
    int retscore()
    {
       return scr;
    }
    int rank;
    ldb()
    {
	rank=1;
	scr=0;
	switch(diff)
	{
	   case 0:strcpy(diffi,"EASY");
		  break;
	   case 1:strcpy(diffi,"MEDIUM");
		  break;
	   case 2:strcpy(diffi,"HARD");
		  break;
	}
    }
 };
/**********************________ADD_SCORE________***************************/
void editfl(ldb ns)
{
  ldb hs;
  fstream fl("hs.dat",ios::in|ios::binary);
  fstream fl1("copy.dat",ios::out|ios::binary);
  if(!fl||!fl1)
     cout<<"file couldn't be opened please try again later....";
  else if(ns.retscore()!=0)
  {
     if(fl.eof())
     {
	ns.rank=1;
	fl1.write((char*)&ns,sizeof(ns));
     }
     else
     {
       while(!fl.eof())
       {
	 fl.read((char*)&hs,sizeof(hs));
	 if(hs.retscore()>ns.retscore())
	 {
	   fl1.write((char*)&hs,sizeof(hs));
	 }
	 else
	 {
	   ns.rank=hs.rank;
	   fl1.write((char*)&ns,sizeof(ns));
	   hs.rank++;
	   fl1.write((char*)&hs,sizeof(hs));
	   break;
	 }
       }
     }
     if(!fl.eof())
     {
	do
	{
	   fl.read((char*)&hs,sizeof(hs));
	   hs.rank++;
	   fl1.write((char*)&hs,sizeof(hs));
	}while(hs.rank<10||!fl.eof());
     }
     fl.close();
     fl1.close();
     remove("hs.dat");
     rename("copy.dat","hs.dat");
  }
}
/*********************________OUTPUTTING_FROM_FILE________*******************/
void readfl()
{
   ldb hs;
   fstream fl("hs.dat",ios::in|ios::binary);
   if(!fl)
       cout<<"file couldn't be opened please try again later....";
   else
   {  clrscr();
      if(fl.eof())
      {
	  cout<<"NO RECODS";
	  getch();
      }
      else
      {
	cout<<"S.No.\tName\tScore\tDifficulty\n";
	while(!fl.eof())
	{
	   fl.read((char*)&hs,sizeof(hs));
	   if(hs.retscore()!=0&&hs.rank<=10)
	      hs.display();
	}
      }
      fl.close();
   }
   getch();
}
/**************__________DIRECION&POSITION___________***********************/
 struct pos
{
  int x;
  int y;
  int d;
};
/**********______TIME_DIFFERRENCE_BETWEEN_MOVES_______*******************/
 void timek(int diff)
{
  if(diff==0)
  {
      for(unsigned long long i=0;i<3000000;i++)
	i++;
  }
  else if(diff==1)
  {
      for(unsigned long long i=0;i<2000000;i++)
	i++;
  }
  else if(diff==2)
  {
      for(unsigned long long i=0;i<1000000;i++)
	i++;
  }
}
/*********_________________FRUIT_GENERATOR_______________*************/
 pos fruitgen()
{  pos fp;
   randomize();
   fp.x=(34-random(random(34)))+6+random(random(34));
   fp.y=random(17)+6;
   fp.d=0;
   gotoxy(fp.x,fp.y);
   textcolor(RED);
   char hrt[2];
   hrt[0]=toascii(3);
   hrt[1]='\0';
   cprintf(hrt);
   return fp;
}
/***********_________________SNAKE_PRINTER_______________*************/
void psnake(pos p[],int l)
{
  gotoxy(p[0].x,p[0].y);
  textcolor(CYAN);
  char head[2];
  head[0]=char(2);
  head[1]='\0';
  cprintf(head);
  for(int i=1;i<l;i++)
  {
    gotoxy(p[i].x,p[i].y);
    cout<<char(4);
  }
}
/****************_______INCREASING_LENGTH_________*************************/
int linc(int &l, pos p[], pos fp, int &score)
{    int i=0;
     if(p[0].x==fp.x && p[0].y==fp.y)
     { i++;
       score++;
       l++;
       if(p[l-2].d==2)
       {
	  p[l-1].y=p[l-2].y-1;
	  p[l-1].x=p[l-2].x;
	  p[l-1].d=p[l-2].d;
	}
       if(p[l-2].d==4)
       {
	  p[l-1].y=p[l-2].y;
	  p[l-1].x=p[l-2].x+1;
	  p[l-1].d=p[l-2].d;
	}
       if(p[l-2].d==8)
       {
	  p[l-1].y=p[l-2].y+1;
	  p[l-1].x=p[l-2].x;
	  p[l-1].d=p[l-2].d;
	}
       if(p[l-2].d==6)
       {
	  p[l-1].y=p[l-2].y;
	  p[l-1].x=p[l-2].x-1;
	  p[l-1].d=p[l-2].d;
	}
	 if(p[0].x==75)
	    p[0].x=6;
	 if(p[0].y==24)
	    p[0].y=6;
	 if(p[0].x==5)
	    p[0].x=74;
	 if(p[0].y==5)
	    p[0].y=23;
     }
  return i;
}
/*****************_________MOVING_SNAKE_________*********************/
void move(pos p[],int l,pos fp)
{
    timek(diff);
    for(int i=l-1;i>0;i--)
    {
	p[i].x=p[i-1].x;
	p[i].y=p[i-1].y;
	p[i].d=p[i-1].d;
    }
       if(p[0].d==2)
	  p[0].y++;
       if(p[0].d==4)
	  p[0].x--;
       if(p[0].d==8)
	  p[0].y--;
       if(p[0].d==6)
	  p[0].x++;
       if(p[0].x==75)
	  p[0].x=6;
       if(p[0].y==24)
	  p[0].y=6;
       if(p[0].x==5)
	  p[0].x=74;
       if(p[0].y==5)
	  p[0].y=23;
       window(6,6,74,23);
       textbackground(YELLOW);
       clrscr();
       window(1,1,80,25);
       psnake(p,l);
       int x1=fp.x;
       int y1=fp.y;
       gotoxy(x1,y1);
       textcolor(RED);
       char hrt[2];
       hrt[0]=toascii(3);
       hrt[1]='\0';
       cprintf(hrt);
}
/**************______CHANGING_DIRECTION__________*****************/
void dir(pos p[])
{
    char i=getch();
    if((int(i)==72||int(i)==80) && (p[0].d==6 || p[0].d==4))
    {
	 if(int(i)==72)
	    p[0].d=8;
	 if(int(i)==80)
	    p[0].d=2;
    }
    if((int(i)==75||int(i)==77) && (p[0].d==2 || p[0].d==8))
    {
	 if(int(i)==75)
	    p[0].d=4;
	 if(int(i)==77)
	    p[0].d=6;
    }
}
/*****************+________GAME_ENDING________**************************/
int over(pos p[],int l)
{ int i=1;
  for(int j=1;j<l;j++)
  {
   if(p[j].x==p[0].x&&p[j].y==p[0].y)
   {
    i=0;
    break;
   }
  }
   return i;
}
/***************************************************************************/
void main()
{
    clrscr();
    char op[10][15]={"New Game","Highscores","settings","exit"};
    clrscr();
    do
    {
    graphmen(4,op,"MENU");
    if(optstr==0)
    {
     score=0;
     ldb newscr;
     clrscr();
     pos p[100];
     for(int i=0;i<100;i++)
     {
	p[i].x=0;
	p[i].y=0;
	p[i].d=6;
     }
     p[0].x=10;
     p[0].y=10;
     int l=1;
     clrscr();
     int x=0,y=1;
     pos fp;
     psnake(p,l);
     getch();
     do
     {
       window(6,6,74,23);
       textbackground(YELLOW);
       clrscr();
       window(1,1,80,25);
       x=0;
       y=1;
       fp=fruitgen();
       do
       { textcolor(RED);
	 boxfunc(5,5,75,24);
	 textcolor(BLUE);
	 boxfunc(4,4,76,25);
	 move(p,l,fp);
	 while(kbhit())
	   dir(p);
	 x=linc(l,p,fp,score);
	 y=over(p,l);
	 boxfunc(4,1,76,3);
	 gotoxy(20,2);
	 textcolor(GREEN);
	 cprintf("SCORE=");
	 char sco[6];
	 itoa(score,sco,10);
	 textcolor(0);
	 char hrt[2];
	 hrt[0]=toascii(3);
	 hrt[1]=toascii(3);
	 cprintf(hrt);
	 gotoxy(40,2);
	 textcolor(GREEN);
	 cprintf("DIFFICULTY LEVEL:-");
	 textcolor(0);
       switch (diff)
       {
	   case 0: cprintf("EASY");
		   break;
	   case 1: cprintf("MEDIUM");
		   break;
	   case 2: cprintf("HARD");
		   break;
       }
       }while(x==0&&y==1);
     }while(y==1);
     clrscr();
     newscr.read();
     editfl(newscr);
     getch();
    }
    else if(optstr==1)
    {
    readfl();
    getch();
    }
    else if(optstr==2)
    {
      char op[10][15]={"easy","medium","hard","back"};
    clrscr();
    do
    {
       graphmen1(4,op,"DIFFICULTY");
       if(optstr1==0)
       {
	 diff=0;
       }
       else if(optstr1==1)
       {
       diff=1;
       }
       else if(optstr1==2)
       {
       diff=2;
       }
       cout<<"\n\nDIFFICULTY LEVEL:-";
       switch (diff)
       {
	   case 0: cout<<"EASY";
		   getch();
		   break;
	   case 1: cout<<"MEDIUM";
		   getch();
		   break;
	   case 2: cout<<"HARD";
		   getch();
		   break;
       }
    }while(optstr1!=3);
    }
    else if(optstr==3)
    {clrscr();
    gotoxy(38,15);
    cout<<"THANKYOU";
    }
    }
    while(optstr!=3);
    getch();
}
/***************************************************************
   旼컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�
   �               SCORE=6           DIFFICULTY LEVEL:-EASY              �
   읕컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�
   旼컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�
   넬컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴커�
   납                                                                     납
   납                                                                     납
   납                                                                   납
   납                                                                   납
   납                                                                   납
   납                                                                     납
   납                                                                     납
   납                                                                     납
   납                                                                     납
   납                                                                     납
   납                                                                     납
   납                                                                     납
   납                                                                     납
   납                                                                    납
   납                                                                     납
   납                                                                     납
   납                                                                     납
   납                                                                     납
   냅컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴켸�
   읕컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴컴�

*/
