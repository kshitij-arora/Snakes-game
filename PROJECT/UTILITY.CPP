#include<conio.h>
#include<iostream.h>
#include<stdio.h>
int optstr=0;
int optstr1=0;
void graphmen(int r, char opt[10][15], char menu[15])
{  int c=0;
   do
   {
	  clrscr();
	  gotoxy(37,1);
	  textbackground(7);
	  textcolor(9);
	  cputs(menu);
	  cout<<endl;
	  textbackground(0);
	  for(int i=0;i<optstr;i++)
	  {
	     cputs(opt[i]);
	     cout<<endl;
	  }
	 textbackground(4);
	 cputs(opt[optstr]);
	 textbackground(0);
	 cout<<endl;
	 for(int k=optstr+1;k<=(r-1);k++)
	 { cputs(opt[k]);
	   cout<<endl;
	 }
	 c=getch();
	 if(c==80)
	   optstr=(optstr+1)%r;
	 else
	 if(c==72)
	 {
	   optstr=optstr-1;
	   if(optstr<0)
	   optstr=r-1;
	 }
     }
     while(c!=13);
}
/*******************************************************************/
void graphmen1(int r, char opt[10][15], char menu[15])
{  int c=0;
   do
   {
	  clrscr();
	  gotoxy(37,1);
	  textbackground(7);
	  textcolor(9);
	  cputs(menu);
	  cout<<endl;
	  textbackground(0);
	  for(int i=0;i<optstr1;i++)
	  {
	     cputs(opt[i]);
	     cout<<endl;
	  }
	 textbackground(4);
	 cputs(opt[optstr1]);
	 textbackground(0);
	 cout<<endl;
	 for(int k=optstr1+1;k<=(r-1);k++)
	 { cputs(opt[k]);
	   cout<<endl;
	 }
	 c=getch();
	 if(c==80)
	   optstr1=(optstr1+1)%r;
	 else
	 if(c==72)
	 {
	   optstr1=optstr1-1;
	   if(optstr1<0)
	   optstr1=r-1;
	 }
     }
     while(c!=13);
}

void underline(int n=79, char ch='*')
{
    for(int i=1;i<=n;i++)
      cout<<ch;
    cout<<endl;
}

void modclr(int x1, int y1, int x2, int y2)
{

 for(int i=x1;i<=x2;i++)
 {
    for(int j=y1;j<=y2;j++)
    {
       gotoxy(i,j);
       cout<<" ";
    }
 }
}

/************************__MENU__PROTOTYPE__****************************/
/*int main()
{

    char op[10][15]={"op1","op2","op3","op4","exit"};
    clrscr();
    do
    {
    graphmen(5,op,"MENU");
    if(optstr==0)
    {clrscr();
    cout<<"you selected op1";
    getch();
    }
    else
    if(optstr==1)
    {clrscr();
    cout<<"you selected op2";
    getch();
    }
    else if(optstr==2)
    {clrscr();
    cout<<"you selected op3";
    getch();
    }
    else if(optstr==3)
    {clrscr();
    cout<<"you selected op4";
    getch();
    }
    else if(optstr==4)
    {clrscr();
    cout<<"THANKYOU";
    getch();
    }
    }
    while(optstr!=4);
    getch();
    return 0;
}  */















