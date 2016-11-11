#include <iostream>
#include<fstream>
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
//#include<conio.h>
#include<graphics.h>
#include "splash.h"

using namespace std;


//int m=1;
char message[15][2] = {"C" ,"o" ,"r", "r", "e", "c", "t" ," ", "A", "n", "s", "w", "e", "r"};

int MBlock[10][10]={{500,220, 630,220, 630,240, 500,240, 500,220},{500,190,630,190,630,210,500,210,500,190},
    {500,160,630,160,630,180,500,180,500,160},{500,130,630,130,630,150,500,150,500,130},{500,100,630,100,630,120,500,120,500,100},
    {500,70,630,70,630,90,500,90,500,70},{500,40,630,40,630,60,500,60,500,40},{500,10,630,10,630,30,500,30,500,10}};

char money[10][20]={"1 00 00 000","50 00 000","25 00 000","10 00 000","5 00 000","1 00 000","50 000","25 000"};

class Quiz
{
    int q_id;
    char ques[50];
    char ans1[20];
    char ans2[20];
    char ans3[20];
    char ans4[20];
    int solution;
    public:
    int count_ques();
    void add_ques();
    int display_ques(int );
    void delete_ques();
    void admin_log();
    char admin_menu();
    void play_quiz();
    void write_question(Quiz  &);
    char time_up();
    void welcome_screen();
    void ques_screen();
    void write_congrats();
    int quiz_menu();
    int randomize();
    void Write_sorry_and_prize(int);
    void writefinalcongrats();
    void Increase_Prize(int );

};


int Quiz :: count_ques()
{
    Quiz q;
    ifstream file;
    file.open("Ques.dat");
    file.seekg(0,ios::beg);
    int t=0;
    while(!file.eof() )
    {
      file.read( (char*)&q,sizeof(q) );
       ++t;
    }
    file.close();
    return t-1;
}

void Quiz :: add_ques()
{
    //cleardevice();
    system("cls");
   //restorecrtmode();
    char ch ='y';
    Quiz q1;
    ofstream fout;
    fout.open("Ques.dat",ios::app);
    //fout.seekp(ios::end);

    while(ch=='y'||ch=='Y')
    {
        cout<<"Enter the details :\n";
        cout<<"\nQuestion no. : ";
        cin>>q1.q_id;
        getchar();
        cout<<"\nQuestion : ";
        gets(q1.ques);
        cout<<"\nOption 1 : ";
        gets(q1.ans1);
        cout<<"\nOption 2 : ";
        gets(q1.ans2);
        cout<<"\nOption 3 : ";
        gets(q1.ans3);
        cout<<"\nOption 4 : ";
        gets(q1.ans4);
        cout<<"\nAns : ";
        cin>>q1.solution;
        fflush(stdin);
        fout.write((char *)&q1,sizeof(q1));
        cout<<"\nQuestion is Successfully added to file...";
        cout<<"\nDo you want to add more Question (y/n) :";
        cin>>ch;
        getchar();
    }
    fout.close();
    graphic();

}
void Quiz :: delete_ques()
{
   // cleardevice();
    system("cls");
   //restorecrtmode();
    char ch ='y',confirm;
    int Dques,flag=0;
    Quiz q1;
    ifstream fin;
    ofstream fout;
    int i=1;

    while(ch=='y'||ch=='Y')
    {
        fin.open("Ques.dat");
        fin.seekg(0,ios::beg);
        fout.open("TempQues.dat");
        cout<<"Enter the Question no. to be delete :  \n";
        cin>>Dques;

        while(!fin.eof())
        {
            fin.read((char *)&q1,sizeof(q1));
            if(q1.q_id==Dques)
            {
                flag=1;
                cout<<"\nAre you  want to delete this record?(y/n) :";
                cin>>confirm;
                if(confirm=='n')
                    fout.write((char*)&q1,sizeof(q1));
            }
            else
            {
                q1.q_id=i++;
            fout.write((char*)&q1,sizeof(q1));
            }
        }

        if(flag)
            cout<<"\nQuestion is Successfully delete from file...";
        else
            cout<<"\nRecord not found...";

         fin.close();
         fout.close();

        remove("Ques.dat");
        rename("TempQues.dat","Ques.dat");

        cout<<"\nDo you want to delete more Question (y/n) :";
        cin>>ch;
        getchar();
    }

}



int Quiz :: display_ques(int a)
{
    Quiz q1;
    ifstream fin;
    fin.open("Ques.dat", ios::in );
    int m=a*sizeof(q1);
    fin.seekg(m,ios::beg);

    fin.read((char *)&q1,sizeof(q1));

//display the qeistion on crt screen for verification..
    cout<<"Q."<<q1.ques;
    cout<<"\n1."<<q1.ans1;
    cout<<"\n2."<<q1.ans2;
    cout<<"\n3."<<q1.ans3;
    cout<<"\n4."<<q1.ans4;

    q1.write_question(q1);
    fin.close();

    return q1.solution;
}
//================================================
void Quiz :: write_question(Quiz  &q1)
 {
     setcolor(12);
     int ch;
     //char temp[20];
     //int len=strlen(q1.ques);
     settextstyle(3,0,1);
    //if(len<25)
    //{
    moveto(80,290);
    outtext("Q. ");
    outtext(q1.ques);
    //}
    /*else
    {
        moveto(80,270);
        outtext("Q. ");
        //for(int i=0;i<2; ++i)
        //for(int j=i;q1.ques[i])
       // outtext(q1.ques);
    }*/
    moveto(70,370);
    outtext("1.  ");
    outtext(q1.ans1);
    moveto(340,370);
    outtext("2.  ");
    outtext(q1.ans2);
    moveto(70,435);
    outtext("3.  ");
    outtext(q1.ans3);
    moveto(340,435);
    outtext("4.  ");
    outtext(q1.ans4);

   /* outtextxy(95,370,q1.ans1);
    outtextxy(340,370,"2.");
    outtextxy(355,370,q1.ans2);
    outtextxy(70,435,"3.");
    outtextxy(95,435,q1.ans3);
    outtextxy(340,435,"4.");
    outtextxy(355,435,q1.ans4);*/
   // getch();
 //return ch;
 }

//=================================================
int Quiz :: quiz_menu()
{
   int ch;
   int gd=DETECT,gm;
  int UserBlock[]={220,100, 370,100, 410,130,   370,160, 220,160,  180,130, 220,100};
  int AdminBlock[]={220,200, 370,200, 410,230,   370,260, 220,260,  180,230, 220,200};
  int ExitBlock[]={220,300, 370,300, 410,330,   370,360, 220,360,  180,330, 220,300};
  initgraph(&gd, &gm, "C:\\TC\\BGI");
  setfillstyle(SOLID_FILL, BLUE);

floodfill(230,120,BLUE);        //background colour
setlinestyle(0,0,2);

rectangle(10,10,630,470);
rectangle(20,20,620,460);
settextstyle(1,0,2);

setfillstyle(SOLID_FILL, BLACK);

drawpoly(7,UserBlock);
fillpoly(7,UserBlock);
outtextxy(230,120,"1. USER");

drawpoly(7,AdminBlock);
fillpoly(7,AdminBlock);
outtextxy(220,220,"2. ADMIN");

drawpoly(7,ExitBlock);
fillpoly(7,ExitBlock);
outtextxy(230,320,"3. EXIT");
settextstyle(6,0,4);
setbkcolor(12);
ch=getch();
return ch;

}
//=================================================

void Quiz :: welcome_screen()
{
    int gd=DETECT,gm;
    int WelComeBlock[]={70,260, 550,260, 590,300,   550,340, 70,340,  30,300, 70,260};
  //  int PlayBlock[]={220,200, 370,200, 410,230,   370,260, 220,260,  180,230, 220,200};
    //int ExitBlock[]={220,300, 370,300, 410,330,   370,360, 220,360,  180,330, 220,300};
    initgraph(&gd, &gm, "C:\\TC\\BGI");
    setfillstyle(SOLID_FILL, BLUE);

    //floodfill(230,120,BLUE);        //background colour
    setlinestyle(0,0,2);

    rectangle(10,10,630,470);
    rectangle(20,20,620,460);
    settextstyle(1,0,2);

    setfillstyle(SOLID_FILL, BLACK);

    drawpoly(7,WelComeBlock);
    fillpoly(7,WelComeBlock);
    outtextxy(70,290," *KAUN BANEGA CROREPATI* ");
     char ch=time_up();
}


char Quiz :: time_up()
{
    char timer[21][4]={"20","19","18","17","16","15","14","13","12","11","10","09","08","07","06","05","04","03","02","01" ,"00"};
    char ch;
    int j=0,k=0;
    int x=0,y=9;
    while(x<=360)
    {
        if(k>14)
        k=1;
        k++;
        setcolor(k);
        setlinestyle(0,0,1);
        circle(280,150,50);
        circle(280,150,60);
        setlinestyle(0,0,10);
        arc(280,150,x,y,55);
        if(1)
        {
            settextstyle(0,0,5);
            outtextxy(240,135,timer[j++]);
        }
        x+=18;
        y+=18;
        floodfill(280,150,BLACK);
        delay(300);
      }


    ch=getch();
    return ch;
}

//=================================================
void Quiz :: ques_screen()
{
   int gd=DETECT,gm;
   int QBlock[]={70,260, 550,260, 590,300,   550,340, 70,340,  30,300, 70,260};
   int ABlock1[]={50,360,  280,360,  300,380,  280,400,  50,400,  30,380,  50,360};
   int ABlock2[]={340,360,  570,360,  590,380,  570,400,  340,400,  320,380,  340,360};
   int ABlock3[]={50,420,  280,420,  300,440,  280,460,   50,460,   30,440,  50,420};
   int ABlock4[]={340,420,  570,420,  590,440,  570,460,  340,460,  320,440,  340,420};

    char timer[21][4]={"20","19","18","17","16","15","14","13","12","11","10","09","08","07","06","05","04","03","02","01" ,"00"};


   initgraph(&gd, &gm, "C:\\TC\\BGI");
   setlinestyle(0,0,2);

    drawpoly(7, QBlock);
    line(0,300,30,300);//left
    line(590,300,660,300);//right

    drawpoly(7,ABlock1);
    drawpoly(7,ABlock2);
    line(300,380,320,380);  //center
    line(0,380,30,380);//left
    line(590,380,650,380);//right

    drawpoly(7,ABlock3);
    drawpoly(7,ABlock4);
    line(300,440,320,440);//center
    line(0,440,30,440);//left
    line(590,440,650,440);//right



 circle(40,40, 25);
 outtextxy(23,32,"50-50");
 circle(100,40, 25);
 outtextxy(85,32,"call");
 circle(160,40, 25);
 outtextxy(148,32,"poll");

//fillpoly(7, ABlock1);
/*for(int i=0,j=0,k=1;i<10;i++,j+=5,k+=30)
{
    drawpoly(5,MBlock[i]);
    outtextxy(545+j,10+k,money[i]);
   delay(50);
}*/


    //answer = time_up();
  //getch();
 // closegraph();
}


void Quiz :: play_quiz()
{
    closegraph();
    int  Ans;
    int Q_No = 0,q_no,Ccount=0;
    while(1)
    {
         ques_screen();
         Increase_Prize(Q_No);
         Q_No++;
        if(Q_No > 8)
        {
            writefinalcongrats();
            break;
        }
        q_no = randomize();
        Ans =display_ques(q_no) ;
         int uAns=time_up();
         uAns-=48;
        /*if(uAns==48)
        {
            Write_sory_and_prize();
            break;
        }*/
        if(uAns==Ans)
        {
            Ccount++;
            Increase_Prize(Q_No);
            //write congrats message....
             moveto(150,220);
             settextstyle(3,0,1);
            for(int i = 0;i<15; i++)
            {
                setcolor(14);
                delay(20);
                outtext(message[i]);
            }
            //deleted message....
            for(int i=0;i<15;++i)
            outtextxy(120,250+i," ");
            }
        else
        {
            cout<<Ccount;
            Write_sorry_and_prize(Ccount);
            break;
        }
        closegraph();
    }
    return;

}

//===============================================
void Quiz :: Increase_Prize(int id)
{
    for(int i=0,j=0,k=1;i<10;i++,j+=5,k+=30)
    {
        drawpoly(5,MBlock[i]);
        outtextxy(545+j,10+k,money[i]);
        //delay(50);
    }

 setfillstyle(XHATCH_FILL,YELLOW);
   for(int i=0;i<id;++i)
        fillpoly(5,MBlock[i]);
  //  getch();
}
//===============================================

int Quiz :: randomize()
{
    Quiz q;
    ifstream file;
    file.open("Ques.dat");
    file.seekg(0,ios::beg);
    int n=0;
    while(!file.eof() )
    {
      file.read( (char*)&q,sizeof(q) );
       ++n;
    }
    n-=1;
    file.close();
        srand(time(NULL));
        int rnum = rand()%n;
    return rnum;
}
void Quiz :: Write_sorry_and_prize(int count)
{
 cleardevice();
 //graphic();
 setlinestyle(0,0,1);
 rectangle(10,10,630,470);
 rectangle(20,20,620,460);
    int EndBlock[]={70,260, 550,260, 590,300,   550,340, 70,340,  30,300, 70,260};
    drawpoly(7,EndBlock);

  //moveto(30,10);
    setcolor(12);
    settextstyle(0,0,2);
    outtextxy(80,200,"Sorry! Your Answer was wrong");
    setcolor(11);
    outtextxy(80,380,"Thank you for participation.");
    setcolor(15); //clear color
    settextstyle(5,0,1);
    moveto(90,290);
    outtext("You Win :");
    outtext(" Rs  ");
    if(count>0)
    {
    outtext(money[8-count]);
    }
    else
    outtext("0");

    getch();
    closegraph();
   // Sleep(5000);

}

void Quiz :: writefinalcongrats()
{
    cleardevice();
    //system("cls");
    rectangle(10,10,630,470);
    rectangle(20,20,620,460);
    moveto(30,10);
    settextstyle(4,0,1);
    setcolor(12);
    outtextxy(50,200,"Congratulation! Your are the winner");
    outtextxy(50,250,"Thank you for participation");
    getch();
}
void Quiz :: admin_log()
{
    //cleardevice();
    //closegraph();
    char choice;
    while(1)
    {   choice=admin_menu();

        switch(choice)
        {
            case '1':   add_ques();
                            break;
            case '2':   delete_ques();
                            break;
            case '3':   break;
        }
        if(choice=='3')
            break;
    }

}

char Quiz :: admin_menu()
{
  cleardevice();
  char  ch;
   int gd=DETECT,gm;
  int AddBlock[]={220,100, 370,100, 410,130,   370,160, 220,160,  180,130, 220,100};
  int DeleteBlock[]={220,200, 370,200, 410,230,   370,260, 220,260,  180,230, 220,200};
  int ExitBlock[]={220,300, 370,300, 410,330,   370,360, 220,360,  180,330, 220,300};
  initgraph(&gd, &gm, "C:\\TC\\BGI");
  setfillstyle(SOLID_FILL, BLUE);

floodfill(230,120,BLUE);        //background colour
setlinestyle(0,0,2);

rectangle(10,10,630,470);
rectangle(20,20,620,460);
settextstyle(1,0,2);

setfillstyle(SOLID_FILL, BLACK);

drawpoly(7,AddBlock);
fillpoly(7,AddBlock);
outtextxy(230,120,"1. ADD ");

drawpoly(7,DeleteBlock);
fillpoly(7,DeleteBlock);
outtextxy(220,220,"2. DELETE");

drawpoly(7,ExitBlock);
fillpoly(7,ExitBlock);
outtextxy(230,320,"3. EXIT");
settextstyle(6,0,4);
setbkcolor(12);
ch=getch();
closegraph();
return ch;

}
//=================================================
int main()
{
    car();
    char choice;
    Quiz q;
    q.welcome_screen();

    while(1)
    {   choice=q.quiz_menu();
        switch(choice)
        {
            case '1':   q.play_quiz();
                            break;
            case '2':   q.admin_log();
                            break;
            case '3':   break;
        }
        if(choice=='3')
            break;


    }
    cleardevice();
    closegraph();
   // q.play_quiz();

    return 0;
}
