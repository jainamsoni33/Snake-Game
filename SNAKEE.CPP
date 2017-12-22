#include <stdio.h>
#include <graphics.h>
#include <stdlib.h>
#include<conio.h>
#include<dos.h>

int score,max,dir=3,x=200,y=200, x1= 150, y1= 200,l=0;  
void choice(char );
void main()
{
		int gd=DETECT,gm,i,j,points,a;
		char ch;
		clrscr();
		initgraph(&gd,&gm,"C:\\TC\\BGI"); 
		
		setcolor(GREEN); 
		rectangle(1,1,637,439);
		setcolor(GREEN); 
		rectangle(3,3,634,436);
		setcolor(BLUE);      
		settextstyle(BOLD_FONT,HORIZ_DIR,3);  /*style of the text*/
		outtextxy(45,110,"SNAKE GAME");    /*print function in graphics*/
		outtextxy(55,170,"\tMADE BY");
		outtextxy(60,220,"\t\tGURPREET AND JAINAM");
		delay(3000);
		closegraph();

		gotoxy(25,4);
		printf("Warning:DON'T TOUCH THE BORDER");
		gotoxy(17,8);
		printf("Quit:IN MIDDLE OF GAME, PRESS < Esc > TO EXIT");
		gotoxy(26,10);
		printf("Play:press any key to start ");
		gotoxy(26,14);
		printf("Control:Use W,A,S,D to move the snake");
		getch();
		initgraph(&gd,&gm,"C:\\TC\\BGI"); 
    		
                          
		setcolor(RED); 
		rectangle(0,0,638,440);
    		setviewport(1,1,637,439,1);
    		setcolor(WHITE);
    		line(x-50,y,x,y);
    
   	 while(1)                                          /*infinite loop*/
	{
		if(kbhit())                                
  	 {
     		ch=getch();
    		choice(ch);
   	 }
   	if (dir==0)
   	 {
	   
            y-=10;
	clearviewport();
	circle(x1,y1,3);
	line(x,y,x,y+50+l);

	}
	else if (dir==1)
	{
            y+=10;
	clearviewport();
	circle(x1,y1,3);
	line(x,y+l,x,y-50);
	}
	else if (dir==2)
	{
		x-=10;
	clearviewport();
	circle(x1,y1,3);
	line(x,y,x+50+l,y);
	}
	else if(dir==3)
	{
		 x+=10;
	clearviewport();
	circle(x1,y1,3);
		line(x+l,y,x-50,y);
        }
	delay(150);
	if(x>=637||x<=1||y<=1||y>=439)
	{
		cleardevice();
		setcolor(BLUE);      
		settextstyle(BOLD_FONT,HORIZ_DIR,4);  
		outtextxy(90,110,"Snake is dead!");
		delay(2000);
		clearviewport();
		closegraph();
		printf("\n\n\n\n\n\n\n\n\t\t\t\GAME OVER!");
		printf("\n\n\n\n\n\n\n\n\t\t\tYour Score is: %d", score);
		getch();
		exit(0);
	}
	if(x==x1&&y==y1)
	{
		

		delay(10);
		sound(750);
 		delay(50);
		sound(850);
		delay(50);
		nosound();
		

		clearviewport();
		l+=20;
		score++;
		x1= (rand()%64)*10;
		y1= (rand() %44)*10;
	}
    } 
}
	void choice(char ch)
	{
       		if(ch=='w')
          	{
            		dir=0;
         	}
          
 
    		else if(ch=='s')
         	{
            		dir=1;
          	}
          

 		else if(ch=='a')
         	 {
            		dir=2;
        	 }
       	   

 		else if(ch=='d')
         	{
           	dir=3;
         	}
  		else if(ch==27)
  		{
		clearviewport();
		closegraph();
		clrscr();
		printf("\n\n\n\n\n\n\n\n\n\n\t\t\tYour Score is %d",score);   
		getch();
		exit(0);
   		}
	 }




\