#include<iostream.h>
#include<conio.h>

int boxfunc(int c1, int r1, int c2, int r2)
{
   int ulc,urc,lrc,llc;
   ulc=218;
   urc=191;
   llc=192;
   lrc=217;
   gotoxy(c1,r1);
   cout<<char(ulc);
   gotoxy(c2,r1);
   cout<<char(urc);
   gotoxy(c1,r2);
   cout<<char(llc);
   gotoxy(c2,r2);
   cout<<char(lrc);
   for(int i=c1+1;i<=c2-1;i++)
   {   gotoxy(i,r1);
       cout<<char(196);
       gotoxy(i,r2);
       cout<<char(196);
   }
   for(i=r1+1;i<=r2-1;i++)
   {   gotoxy(c1,i);
       cout<<char(179);
       gotoxy(c2,i);
       cout<<char(179);
   }
   return 0;

}
/*int main()
{   clrscr();
    boxfunc(31,5,49,17);
    boxfunc(37,2,43,5);
    boxfunc(38,3,39,4);
    boxfunc(41,3,42,4);
    boxfunc(35,17,39,22);
    boxfunc(41,17,45,22);
    boxfunc(20,7,31,9);
    boxfunc(49,7,60,9);
    getch();
    return 0;
} */