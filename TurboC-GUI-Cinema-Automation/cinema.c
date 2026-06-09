#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
//hocam bazi buglar kaldi. sanirim fazla derine inip nestedlarda ufak hatalar yaptim. 
//bu kadar yetistirebildim yaklasik 7 gunde
//C://TURBOC3//BIN konumunda bazi txt dosyalari var onlari olusturup sonra calistirabilirseniz veri tabani aktif durumda
//a.txt icinde 30 yazan bir dosya
//c.txt icinde 30 yazan bir dosya
//f.txt icinde ilk 3 satirda 0 yazan bir dosya
//f.txt icinde ilk 3 satirda 0 yazan bir dosya
//f.txt icinde ilk 3 satirda 0 yazan bir dosya
void fightclub()
{ FILE *f;
f=fopen("C:\\TURBOC3\\BIN\\f.txt","r");
int dizi[3];
for(int l=0;l<3;l++)
fscanf(f,"%d\n",&dizi[l]);
fclose(f);
cleardevice();
union REGS i,o;
int x1,y1,tikla;
i.x.ax=1;
int86(0x33,&i,&o);
i.x.ax=3;
outtextxy(getmaxx()/2-100,getmaxy()/2-230,"SALON 1 KOLTUKLARI");
setcolor(WHITE);
line(getmaxx()/2-100,getmaxy()/2+195,getmaxx()/2+100,getmaxy()/2+195);
outtextxy(getmaxx()/2-30,getmaxy()/2+170,"SAHNE");
rectangle(getmaxx()/2-200,getmaxy()/2-200,getmaxx()/2+200,getmaxy()/2+200);
rectangle(getmaxx()/2-160,getmaxy()/2-100,getmaxx()/2-60,getmaxy()/2-50);
rectangle(getmaxx()/2-50,getmaxy()/2-100,getmaxx()/2+50,getmaxy()/2-50);
rectangle(getmaxx()/2+60,getmaxy()/2-100,getmaxx()/2+160,getmaxy()/2-50);
if(dizi[0]==1)
{
setfillstyle(SOLID_FILL,RED),
floodfill(getmaxx()/2-150,getmaxy()/2-90,WHITE);
}
if(dizi[1]==1)
{
setfillstyle(SOLID_FILL,RED),
floodfill(getmaxx()/2-40,getmaxy()/2-90,WHITE);
}
if(dizi[2]==1)
{
setfillstyle(SOLID_FILL,RED),
floodfill(getmaxx()/2+70,getmaxy()/2-90,WHITE);
}
while(!kbhit())
{
x1=o.x.cx;
y1=o.x.dx;
int86(0x33,&i,&o);
tikla=o.x.bx&7;
if((x1>=(getmaxx()/2-160) && x1<=(getmaxx()/2-60))&&(y1>=(getmaxy()/2-100) &&
y1<=(getmaxy()/2+200)))
{
if (tikla==1){
setfillstyle(SOLID_FILL,RED),
floodfill(getmaxx()/2-150,getmaxy()/2-90,WHITE);
dizi[0]=1;
goto ozgur;}
}
if((x1>=(getmaxx()/2-50) && x1<=(getmaxx()/2+50))&&(y1>=(getmaxy()/2-100) &&
y1<=(getmaxy()/2+200)))
{
if(tikla==1){
setfillstyle(SOLID_FILL,RED),
floodfill(getmaxx()/2-40,getmaxy()/2-90,WHITE);
dizi[1]=1;
goto ozgur;}
}
if((x1>=(getmaxx()/2+60) && x1<=(getmaxx()/2+160))&&(y1>=(getmaxy()/2-100) &&
y1<=(getmaxy()/2+200)))
{
if(tikla==1){
setfillstyle(SOLID_FILL,RED),
floodfill(getmaxx()/2+70,getmaxy()/2-90,WHITE);
dizi[2]=1;
goto ozgur;
}
}
}
ozgur:
f=fopen("C:\\TURBOC3\\BIN\\f.txt","w");
for(int u=0;u<3;u++)
{
fprintf(f,"%d\n",dizi[u]);
}
fclose(f);
}
void godfather()
{ FILE *g;
g=fopen("C:\\TURBOC3\\BIN\\g.txt","r");
int dizi[3];
for(int l=0;l<3;l++)
fscanf(g,"%d\n",&dizi[l]);
fclose(g);
cleardevice();
union REGS i,o;
int x1,y1,tikla;
i.x.ax=1;
int86(0x33,&i,&o);
i.x.ax=3;
outtextxy(getmaxx()/2-100,getmaxy()/2-230,"SALON 2 KOLTUKLARI");
setcolor(WHITE);
line(getmaxx()/2-100,getmaxy()/2+195,getmaxx()/2+100,getmaxy()/2+195);
outtextxy(getmaxx()/2-30,getmaxy()/2+170,"SAHNE");
rectangle(getmaxx()/2-200,getmaxy()/2-200,getmaxx()/2+200,getmaxy()/2+200);
rectangle(getmaxx()/2-160,getmaxy()/2-100,getmaxx()/2-60,getmaxy()/2-50);
rectangle(getmaxx()/2-50,getmaxy()/2-100,getmaxx()/2+50,getmaxy()/2-50);
rectangle(getmaxx()/2+60,getmaxy()/2-100,getmaxx()/2+160,getmaxy()/2-50);
if(dizi[0]==1)
{
setfillstyle(SOLID_FILL,RED),
floodfill(getmaxx()/2-150,getmaxy()/2-90,WHITE);
}
if(dizi[1]==1)
{
setfillstyle(SOLID_FILL,RED),
floodfill(getmaxx()/2-40,getmaxy()/2-90,WHITE);
}
if(dizi[2]==1)
{
setfillstyle(SOLID_FILL,RED),
floodfill(getmaxx()/2+70,getmaxy()/2-90,WHITE);
}
while(!kbhit())
{
x1=o.x.cx;
y1=o.x.dx;
int86(0x33,&i,&o);
tikla=o.x.bx&7;
if((x1>=(getmaxx()/2-160) && x1<=(getmaxx()/2-60))&&(y1>=(getmaxy()/2-100) &&
y1<=(getmaxy()/2+200)))
{
if (tikla==1){
setfillstyle(SOLID_FILL,RED),
floodfill(getmaxx()/2-150,getmaxy()/2-90,WHITE);
dizi[0]=1;
goto ozgur;}
}
if((x1>=(getmaxx()/2-50) && x1<=(getmaxx()/2+50))&&(y1>=(getmaxy()/2-100) &&
y1<=(getmaxy()/2+200)))
{
if(tikla==1){
setfillstyle(SOLID_FILL,RED),
floodfill(getmaxx()/2-40,getmaxy()/2-90,WHITE);
dizi[1]=1;
goto ozgur;}
}
if((x1>=(getmaxx()/2+60) && x1<=(getmaxx()/2+160))&&(y1>=(getmaxy()/2-100) &&
y1<=(getmaxy()/2+200)))
{
if(tikla==1){
setfillstyle(SOLID_FILL,RED),
floodfill(getmaxx()/2+70,getmaxy()/2-90,WHITE);
dizi[2]=1;
goto ozgur;
}
}
}
ozgur:
g=fopen("C:\\TURBOC3\\BIN\\g.txt","w");
for(int u=0;u<3;u++)
{
fprintf(g,"%d\n",dizi[u]);
}
fclose(g);
}
void matrix()
{ FILE *m;
m=fopen("C:\\TURBOC3\\BIN\\m.txt","r");
int dizi[3];
for(int l=0;l<3;l++)
fscanf(m,"%d\n",&dizi[l]);
fclose(m);
cleardevice();
union REGS i,o;
int x1,y1,tikla;
i.x.ax=1;
int86(0x33,&i,&o);
i.x.ax=3;
outtextxy(getmaxx()/2-100,getmaxy()/2-230,"SALON 3 KOLTUKLARI");
setcolor(WHITE);
line(getmaxx()/2-100,getmaxy()/2+195,getmaxx()/2+100,getmaxy()/2+195);
outtextxy(getmaxx()/2-30,getmaxy()/2+170,"SAHNE");
rectangle(getmaxx()/2-200,getmaxy()/2-200,getmaxx()/2+200,getmaxy()/2+200);
rectangle(getmaxx()/2-160,getmaxy()/2-100,getmaxx()/2-60,getmaxy()/2-50);
rectangle(getmaxx()/2-50,getmaxy()/2-100,getmaxx()/2+50,getmaxy()/2-50);
rectangle(getmaxx()/2+60,getmaxy()/2-100,getmaxx()/2+160,getmaxy()/2-50);
if(dizi[0]==1)
{
setfillstyle(SOLID_FILL,RED),
floodfill(getmaxx()/2-150,getmaxy()/2-90,WHITE);
}
if(dizi[1]==1)
{
setfillstyle(SOLID_FILL,RED),
floodfill(getmaxx()/2-40,getmaxy()/2-90,WHITE);
}
if(dizi[2]==1)
{
setfillstyle(SOLID_FILL,RED),
floodfill(getmaxx()/2+70,getmaxy()/2-90,WHITE);
}
while(!kbhit())
{
x1=o.x.cx;
y1=o.x.dx;
int86(0x33,&i,&o);
tikla=o.x.bx&7;
if((x1>=(getmaxx()/2-160) && x1<=(getmaxx()/2-60))&&(y1>=(getmaxy()/2-100) &&
y1<=(getmaxy()/2+200)))
{
if (tikla==1){
setfillstyle(SOLID_FILL,RED),
floodfill(getmaxx()/2-150,getmaxy()/2-90,WHITE);
dizi[0]=1;
goto ozgur;}
}
if((x1>=(getmaxx()/2-50) && x1<=(getmaxx()/2+50))&&(y1>=(getmaxy()/2-100) &&
y1<=(getmaxy()/2+200)))
{
if(tikla==1){
setfillstyle(SOLID_FILL,RED),
floodfill(getmaxx()/2-40,getmaxy()/2-90,WHITE);
dizi[1]=1;
goto ozgur;}
}
if((x1>=(getmaxx()/2+60) && x1<=(getmaxx()/2+160))&&(y1>=(getmaxy()/2-100) &&
y1<=(getmaxy()/2+200)))
{
if(tikla==1){
setfillstyle(SOLID_FILL,RED),
floodfill(getmaxx()/2+70,getmaxy()/2-90,WHITE);
dizi[2]=1;
goto ozgur;
}
}
}
ozgur:
m=fopen("C:\\TURBOC3\\BIN\\m.txt","w");
for(int u=0;u<3;u++)
{
fprintf(m,"%d\n",dizi[u]);
}
fclose(m);
}
void ekranCiz()
{
setcolor(WHITE);
setfillstyle(SOLID_FILL,LIGHTGRAY);
bar(getmaxx()/2-80,120,getmaxx()/2+80,400);
floodfill(getmaxx()/2-75,125,LIGHTGRAY);
setcolor(LIGHTGRAY);
setlinestyle(0,0,1);
settextstyle(1,0,1);
outtextxy(getmaxx()/2-55,75,"FILM LISTESI");
setcolor(DARKGRAY);
settextstyle(2,0,7);
outtextxy(getmaxx()/2-74,136,"FIGHT CLUB");
outtextxy(getmaxx()/2-74,182,"GODFATHER");
outtextxy(getmaxx()/2-74,232,"MATRIX");
outtextxy(getmaxx()/2-74,370,"GERI DON");
setcolor(LIGHTGRAY);
rectangle(getmaxx()/2-80,120,getmaxx()/2+80,400);
}
void alanBoya(int gRenk)
{
switch(gRenk)
{case 1:
cleardevice();
ekranCiz();
setcolor(RED);
setfillstyle(BKSLASH_FILL,RED);
floodfill(2,2,LIGHTGRAY);
setcolor(BLUE);
setfillstyle(SOLID_FILL,BLUE);
rectangle(getmaxx()/2-80,120,getmaxx()/2+80,172);
floodfill(getmaxx()/2-75,125,BLUE);
setcolor(DARKGRAY);
settextstyle(2,0,7);
outtextxy(getmaxx()/2-74,136,"FIGHT CLUB");
break;
case 2:
cleardevice();
ekranCiz();
setcolor(BLUE);
setfillstyle(SOLID_FILL,BLUE);
rectangle(getmaxx()/2-80,172,getmaxx()/2+80,224);
floodfill(getmaxx()/2-75,175,BLUE);
setcolor(DARKGRAY);
settextstyle(2,0,7);
outtextxy(getmaxx()/2-74,182,"GODFATHER");
break;
case 3:
cleardevice();
ekranCiz();
setfillstyle(XHATCH_FILL,GREEN);
floodfill(2,2,LIGHTGRAY);
setcolor(BLUE);
setfillstyle(SOLID_FILL,BLUE);
rectangle(getmaxx()/2-80,224,getmaxx()/2+80,276);
floodfill(getmaxx()/2-75,230,BLUE);
setcolor(DARKGRAY);
settextstyle(2,0,7);
outtextxy(getmaxx()/2-74,232,"MATRIX");
break;
case 4:
cleardevice();
ekranCiz();
setfillstyle(SOLID_FILL,LIGHTCYAN);
floodfill(2,2,LIGHTGRAY);
setcolor(BLUE);
setfillstyle(SOLID_FILL,BLUE);
rectangle(getmaxx()/2-80,348,getmaxx()/2+80,400);
floodfill(getmaxx()/2-75,360,BLUE);
setcolor(DARKGRAY);
settextstyle(2,0,7);
outtextxy(getmaxx()/2-74,370,"GERI DON");
break;
}
}
void filmler()
{enbasa:
union REGS i,o;
int x1,y1,tikla,renk=0;
i.x.ax=1;
int86(0x33,&i,&o);
i.x.ax=3;
cleardevice();
settextstyle(0,0,0);
delay(3000);
cleardevice();
ekranCiz();
while(!kbhit())
{
int86(0x33,&i,&o);
tikla=o.x.bx&7;
outtextxy(40,getmaxy()/2,"BU EKRANDA SOL CLICK HAREKET SAG CLICK GIRIS GOREVINDEDIR");
if(tikla==1)
{renk++;
if(renk>4)
{renk=1;}
alanBoya(renk);
}
if (tikla==2)
{if(renk==1)
fightclub();
else if(renk==2)
godfather();
else if (renk==3)
matrix();
else if(renk==4)
goto kurtar;
}
}
}
kurtar:
void atistirmaliklar()
{FILE*d;
d=fopen("C:\\TURBOC3\\BIN\\a.txt","r");
int popcorn,coke;
fscanf(d,"%d",&popcorn);
fclose(d);
FILE*a;
a=fopen("C:\\TURBOC3\\BIN\\c.txt","r");
fscanf(a,"%d",&coke);
fclose(a);
cleardevice();
setlinestyle(0,0,0);
delay(50);
for(int ra = 0; ra < 200;ra++)
{setcolor(rand() % 10);
circle(rand() % 640, rand() % 480, rand() % 25);
delay(1);
}
int tikla,x1,y1;
union REGS i,o;
i.x.ax=1;
int86(0x33,&i,&o);
i.x.ax=3;
rectangle(0,0,getmaxx(),getmaxy());
setlinestyle(0,0,3);
setfillstyle(WIDE_DOT_FILL,RED);
setcolor(LIGHTGRAY);
rectangle(80,getmaxy()/2-40,296,getmaxy()/2+40);
floodfill(85,getmaxy()/2,LIGHTGRAY);
setcolor(LIGHTGRAY);
setlinestyle(0,0,3);
setfillstyle(WIDE_DOT_FILL,RED);
rectangle(getmaxx()-296,getmaxy()/2-40,getmaxx()-80,getmaxy()/2+40);
floodfill(getmaxx()-292,getmaxy()/2,LIGHTGRAY);
setlinestyle(3,1,1);
rectangle(76,getmaxy()/2-44,300,getmaxy()/2+44);
rectangle(getmaxx()-300,getmaxy()/2-44,getmaxx()-76,getmaxy()/2+44);
settextstyle(7,0,2);
outtextxy(134,getmaxy()/2-15,"POPCORN");
settextstyle(7,0,2);
outtextxy(getmaxx()-228,getmaxy()/2-15,"COKE");
setcolor(RED);
setlinestyle(0,0,3);
setfillstyle(XHATCH_FILL,RED);
circle(getmaxx()-40,getmaxy()-40,15);
floodfill(getmaxx()-46,getmaxy()-43,RED);
settextstyle(0,0,0);
setcolor(LIGHTCYAN);
outtextxy(getmaxx()-48,getmaxy()-43,"<=");
settextstyle(4,2,6);
outtextxy(getmaxx()/2-30,40,"E");
settextstyle(4,2,6);
outtextxy(getmaxx()/2-30,getmaxy()-60,"E");
if(popcorn==0)
{
setcolor(RED);
line(136,getmaxy()/2-5,226,getmaxy()/2+15);
}
if(coke==0)
{
setcolor(RED);
line(386,getmaxy()/2-5,466,getmaxy()/2+15);
}
while(!kbhit())
{
x1=o.x.cx;
y1=o.x.dx;
int86(0x33,&i,&o);
tikla=o.x.bx&7;
if((x1>=(getmaxx()-55) && x1<=(getmaxx()-25))&&(y1>=(getmaxy()-55) && y1<=(getmaxy()-25)))
{
if (tikla==1)
goto no;
}
if((x1>=(80) && x1<=(296))&&(y1>=(getmaxy()/2-40) && y1<=(getmaxy()/2+40)))
{
if(tikla==1){
tikla=0;
if(popcorn>0);
popcorn=popcorn-1;
d=fopen("C:\\TURBOC3\\BIN\\a.txt","w");
fprintf(d,"%d",popcorn);
fclose(d);
}
}
if((x1>=(getmaxx()-296) && x1<=(getmaxx()-80))&&(y1>=(getmaxy()/2-40) && y1<=(getmaxy()/2+40)))
{
if(tikla==1){
tikla=0;
if(coke>0)
coke--;
a=fopen("C:\\TURBOC3\\BIN\\c.txt","w");
fprintf(a,"%d",coke);
fclose(a);
}
}
}
no:
}
void kullanicigiris(int x1,int y1)
{basla:
cleardevice();
for(int a=0; a<=500; a++)
{
int p=rand()%getmaxx();
int o=rand()%getmaxy();
putpixel(p,o,3);
}
int tikla;
union REGS i,o;
i.x.ax=1;
int86(0x33,&i,&o);
i.x.ax=3;
rectangle(0,0,getmaxx(),getmaxy());
setlinestyle(0,0,3);
setfillstyle(WIDE_DOT_FILL,BLUE);
setcolor(LIGHTGRAY);
rectangle(80,getmaxy()/2-40,296,getmaxy()/2+40);
floodfill(85,getmaxy()/2,LIGHTGRAY);
setcolor(LIGHTGRAY);
setlinestyle(0,0,3);
setfillstyle(WIDE_DOT_FILL,RED);
rectangle(getmaxx()-296,getmaxy()/2-40,getmaxx()-80,getmaxy()/2+40);
floodfill(getmaxx()-292,getmaxy()/2,LIGHTGRAY);
setlinestyle(3,1,1);
rectangle(76,getmaxy()/2-44,300,getmaxy()/2+44);
rectangle(getmaxx()-300,getmaxy()/2-44,getmaxx()-76,getmaxy()/2+44);
settextstyle(7,0,2);
outtextxy(134,getmaxy()/2-15,"FILMLER");
settextstyle(7,0,2);
outtextxy(getmaxx()-288,getmaxy()/2-15,"ATISTIRMALIKLAR");
setcolor(RED);
setlinestyle(0,0,3);
setfillstyle(XHATCH_FILL,RED);
circle(getmaxx()-40,getmaxy()-40,15);
floodfill(getmaxx()-46,getmaxy()-43,RED);
settextstyle(0,0,0);
setcolor(LIGHTCYAN);
outtextxy(getmaxx()-48,getmaxy()-43,"<=");
settextstyle(4,2,6);
outtextxy(getmaxx()/2-30,40,"E");
settextstyle(4,2,6);
outtextxy(getmaxx()/2-30,getmaxy()-60,"E");
while(!kbhit())
{
x1=o.x.cx;
y1=o.x.dx;
int86(0x33,&i,&o);
tikla=o.x.bx&7;
{
if (tikla==1)
goto etiket;
}
{
if(tikla==1){
filmler();
goto basla;}
}
{
if(tikla==1){
atistirmaliklar();
goto basla;
}
}
}
if((x1>=(getmaxx()-55) && x1<=(getmaxx()-25))&&(y1>=(getmaxy()-55) && y1<=(getmaxy()-25)))
if((x1>=(80) && x1<=(296))&&(y1>=(getmaxy()/2-40) && y1<=(296,getmaxy()/2+40)))
if((x1>=(getmaxx()-296) && x1<=(getmaxx()-80))&&(y1>=(getmaxy()/2-40) &&
y1<=(296,getmaxy()/2+40)))
etiket:
}
void yoneticigiris()
{cleardevice();
FILE *f;
FILE *m;
FILE *g;
f=fopen("C:\\TURBOC3\\BIN\\f.txt","w");
g=fopen("C:\\TURBOC3\\BIN\\g.txt","w");
m=fopen("C:\\TURBOC3\\BIN\\m.txt","w");
int tikla,x1,y1;
union REGS i,o;
i.x.ax=1;
int86(0x33,&i,&o);
i.x.ax=3;
rectangle(70,80,260,150);
outtextxy(74,90,"Salon sifirla");
while(!kbhit())
{
x1=o.x.cx;
y1=o.x.dx;
int86(0x33,&i,&o);
tikla=o.x.bx&7;
if((x1>=(70) && x1<=(260))&&(y1>=(80) && y1<=(150)))
{
if (tikla==1)
{
for(int l=0;l<3;l++)
{
fprintf(f,"%d\n",0);
fprintf(g,"%d\n",0);
fprintf(m,"%d\n",0);
}
fclose(f);
fclose(g);
fclose(m);
goto label;
}
}
}
label:
}
void anamenu()
{
cleardevice();
for(int i=0; i<=500; i++)
{
int x=rand()%getmaxx();
int y=rand()%getmaxy();
putpixel(x,y,3);
}
setcolor(DARKGRAY);
settextstyle(4,0,6);
outtextxy(60,30,"S MOVIE THEATER");
settextstyle(4,2,6);
outtextxy(20,getmaxy()/2,"E");
settextstyle(4,2,6);
outtextxy(550,getmaxy()/2,"E");
setcolor(LIGHTGRAY);
setlinestyle(3,1,1);
rectangle(getmaxx()/2-108,getmaxy()/2-124,getmaxx()/2+108,getmaxy()/2-1);
rectangle(getmaxx()/2-108,getmaxy()/2+1,getmaxx()/2+108,getmaxy()/2+124);
setlinestyle(0,0,3);
rectangle(getmaxx()/2-104,getmaxy()/2-120,getmaxx()/2+104,getmaxy()/2-5);
rectangle(getmaxx()/2-104,getmaxy()/2+5,getmaxx()/2+104,getmaxy()/2+120);
settextstyle(7,0,2);
outtextxy(getmaxx()/2-100,getmaxy()/2-75,"KULLANICI GIRISI");
settextstyle(7,0,2);
outtextxy(getmaxx()/2-91,getmaxy()/2+48,"YONETICI GIRISI");
rectangle(0,0,getmaxx(),getmaxy());
}
int main()
{
union REGS i,o;
int gd=DETECT,gm,tikla,x1,y1;
initgraph(&gd,&gm," ");
i.x.ax=1;
int86(0x33,&i,&o);
i.x.ax=3;
anamenu();
while(!kbhit())
{
x1=o.x.cx;
y1=o.x.dx;
int86(0x33,&i,&o);
tikla=o.x.bx&7;
if((x1>=(getmaxx()/2-104) && x1<=(getmaxx()/2+104))&&(y1>=(getmaxy()/2-120) &&
y1<=(getmaxy()/2-5)))
{
if(tikla==1)
{cleardevice();
setcolor(DARKGRAY);
settextstyle(4,0,6);
outtextxy(60,30,"S MOVIE THEATER");
settextstyle(4,2,6);
outtextxy(20,getmaxy()/2,"E");
settextstyle(4,2,6);
outtextxy(550,getmaxy()/2,"E");
setcolor(LIGHTGRAY);
setlinestyle(3,1,1);
rectangle(getmaxx()/2-106,getmaxy()/2-122,getmaxx()/2+110,getmaxy()/2-3);
rectangle(getmaxx()/2-108,getmaxy()/2+1,getmaxx()/2+108,getmaxy()/2+124);
setlinestyle(0,0,3);
rectangle(getmaxx()/2-102,getmaxy()/2-122,getmaxx()/2+106,getmaxy()/2-7);
rectangle(getmaxx()/2-104,getmaxy()/2+5,getmaxx()/2+104,getmaxy()/2+120);
settextstyle(7,0,2);
outtextxy(getmaxx()/2-98,getmaxy()/2-77,"KULLANICI GIRISI");
settextstyle(7,0,2);
outtextxy(getmaxx()/2-91,getmaxy()/2+48,"YONETICI GIRISI");
rectangle(0,0,getmaxx(),getmaxy());
delay(250);
kullanicigiris(x1,y1);
anamenu();
}
}
if((x1>=(getmaxx()/2-104) && x1<=(getmaxx()/2+104))&&(y1>=(getmaxy()/2+5) &&
y1<=(getmaxy()/2+120)))
{
if(tikla==1)
{cleardevice();
setcolor(DARKGRAY);
settextstyle(4,0,6);
outtextxy(60,30,"S MOVIE THEATER");
settextstyle(4,2,6);
outtextxy(20,getmaxy()/2,"E");
settextstyle(4,2,6);
outtextxy(550,getmaxy()/2,"E");
setcolor(LIGHTGRAY);
setlinestyle(3,1,1);
rectangle(getmaxx()/2-108,getmaxy()/2-124,getmaxx()/2+108,getmaxy()/2-1);
rectangle(getmaxx()/2-106,getmaxy()/2-1,getmaxx()/2+110,getmaxy()/2+122);
setlinestyle(0,0,3);
rectangle(getmaxx()/2-104,getmaxy()/2-120,getmaxx()/2+104,getmaxy()/2-5);
rectangle(getmaxx()/2-102,getmaxy()/2+3,getmaxx()/2+106,getmaxy()/2+118);
settextstyle(7,0,2);
outtextxy(getmaxx()/2-100,getmaxy()/2-75,"KULLANICI GIRISI");
settextstyle(7,0,2);
outtextxy(getmaxx()/2-91,getmaxy()/2+48,"YONETICI GIRISI");
rectangle(0,0,getmaxx(),getmaxy());
delay(250);
yoneticigiris();
anamenu();
}
}
}
getch();
closegraph();
return 0;
}