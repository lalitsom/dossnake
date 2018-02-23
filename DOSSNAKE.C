#include<conio.h>
#include<graphics.h>
#include<time.h>
#include<stdio.h>
#include<dos.h>
#define swap(a,b) {int e; e=a; a=b; b=e;}
int snk[9555][2]={0},i,j,x1,mdk=0,y1,x2,y2,
h,m=0,g=0,gam=0,scr=0,q,w,t1,start,tim,tail=0,len=160;
void o1();
void s1();
void main()
{
int gd = DETECT,gm,dx,dy;
char c,c2;
mdk=0,m=0,g=0,gam=0,scr=0,tail=0,len=160;
loop2:
clrscr();

printf(" Enter level  or difficulty you want from 1 to 22   " );
scanf("%d",&t1);
printf("\n Initial length of snake you want  " );
scanf("%d",&len);
x1=25; y1=25; x2=600; y2=400;
if(t1>22 || t1<1 )
{ printf("invalid level "); delay(200); goto loop2; }

if(t1<15)
t1=abs(16-t1);
else
{
x1=x1+34*(t1-15); x2=x2-28*(t1-15); y1=y1+17*(t1-15); y2=y2-21*(t1-15);

if(t1==22)
 t1=0;
 if(t1!=0)
 t1=1;
}
printf("%d %d %d %d ",x1,y1,x2,y2);
getch();
clrscr();
initgraph(&gd,&gm,"C:\\TC\\BGI");
cleardevice();
setbkcolor(GREEN);

dx=1; dy=0;

rectangle(x1,y1,x2,y2);
i=x1+5; j=y1+5;
gotoxy(1,1);
printf("Press any key to continue");
getch();
gotoxy(1,1);
printf(" CONTROLS -> USE ARROW KEYS  ESC -> exit P -> PAUSE");
start = clock();

loop1:

while( !kbhit() && gam==0  )
{
show();
tim = clock()-start;
checkm();
if(i>x2-3)
{i=x1+3;}
if(i<x1+3)
{i=x2-3;}
if(j<y1+3)
{j=y2-3;}
if(j>y2-3)
{j=y1+3;}

i+=dx;
j+=dy;
o1();
delay(t1);
tail++;
snk[tail][0]=i; snk[tail][1]=j;
if(tail>len)
tail=0;

s1();

rectangle(x1,y1,x2,y2);
}

if(gam==0)
c=getch();
if(c==121)
mdk=0;
if(c==72&& dy==0  )
{dx=0; dy=-1; i=i+(2*dx); j=j+(2*dy);}
if(c==80 && dy==0)
{dx=0; dy=1;i=i+(2*dx); j=j+(2*dy); }
if(c==75 && dx==0)
{dx=-1; dy=0; i=i+(2*dx); j=j+(2*dy); }
if(c==77 && dx==0)
{dx=1; dy=0; i=i+(2*dx); j=j+(2*dy); }
if(c=='p')
{pause();}

if(c==27|| gam==1 )
{loop3: gotoxy(5,16); printf("GAME OVER"); delay(2000); closegraph(); clrscr();
printf("\n\n GAME OVER\n Score = %d \n Time taken = %d sec\n Press r to restart\n esc to EXIT \n ",scr,(tim/10));

c=getch();
if(c=='r')
{ main();}

if(c==27)
exit(0);
else
goto loop3;

}


goto loop1;



}



//functions

void o1()
{

setcolor(BLUE);
if(i<x2-47 && i>x1+47)
setcolor(RED);

circle(i,j,2);
}

void s1()
{int kl,he=0;

for(kl=1;kl<=len;kl++)
{ if(snk[kl][0]==i && snk[kl][1]==j)
  he++;
if(he==2)
gam=1;
}


setcolor(GREEN);
circle(snk[tail+1][0],snk[tail+1][1],2);
setcolor(RED);
}

int pause()
{
outtextxy(300,410,"PAUSE");
getch();
setcolor(GREEN);
outtextxy(300,410,"PAUSE");
setcolor(RED);
return 0;
}
int checkm()
{
if(mdk==0)
{mdk=1;  setcolor(GREEN); outtextxy(q,w,"*"); setcolor(RED);
 q=rand()%(x2-x1-8)+(x1+3); w=rand()%(y2-y1-8)+y1+3; setcolor(BLUE);
  outtextxy(q,w,"*"); setcolor(RED); return 0;}

if(mdk==1)
{ if( i>=(q-2) && i<=(q+9) && j>=(w-2) && j<=(w+9) )
 {len+=scr%7; scr++;
 mdk=0; checkm();}
}
return 0;
}


int show()
{
gotoxy(60,1); printf(" Score= %d, T=%d      ",scr,tim/10,len,i,j,tail);
return 0;
}
