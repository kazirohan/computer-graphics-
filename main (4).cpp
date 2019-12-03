#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>


int Speed_of_Game = 50;
int Game_begin=0;
int gv=0;
int LVL = 0;

int Count_score = 0;

//Movement track ar jonno
int MoveTrackTopMost = 0;
int MoveTrackTop = 0;
int MoveTrackMDL = 0;
int MoveTrackBTM = 0;

//Amar garir LRindex
int MainCarLR_index = 0 ;


//Opposite site car coming
int C1 = 0;
int C1_LR_index1=0;
int C2 = +35;
int C2_LR_index2=0;
int C3 = +70;
int C3_LR_index3=0;


const int F1=(int)GLUT_BITMAP_TIMES_ROMAN_24;

//Without using any display lists, glutBitmapCharacter renders the character in the named bitmap font.
//A 24-point proportional spaced Times Roman font. The exact bitmaps to be used is defined by the standard X glyph bitmaps for the X font named
//charecter gulo k display te pes kora

const int F2=(int)GLUT_BITMAP_HELVETICA_18 ;

//GLUT_BITMAP_HELVETICA_18
//A 18-point proportional spaced Helvetica font. The exact bitmaps to be
//used is defined by the standard X glyph bitmaps for the X font named

const int F3=(int)GLUT_BITMAP_8_BY_13;



void Funcfor_tree(int x, int y){
    int NwAxis_x=x; //new=nw
    int NwAxis_y=y;

        //Botton
        glColor3f(0.871, 0.722, 0.529);
        glBegin(GL_TRIANGLES);
        glVertex2f(NwAxis_x+11,NwAxis_y+55);
        glVertex2f(NwAxis_x+12,NwAxis_y+55-10);
        glVertex2f(NwAxis_x+10,NwAxis_y+55-10);
        glEnd();

            //Up
      glColor3f(0.133, 0.545, 0.133);
        glBegin(GL_TRIANGLES);
        glVertex2f(NwAxis_x+11,NwAxis_y+55+3);
        glVertex2f(NwAxis_x+12+3,NwAxis_y+55-3);
        glVertex2f(NwAxis_x+10-3,NwAxis_y+55-3);
        glEnd();
}


void renderBitmapString(float x, float y, void *font,const char *string){
    const char *c;
    glRasterPos2f(x, y);
    for (c=string; *c != '\0'; c++) {
        glutBitmapCharacter(font, *c);
    }
}


void Race_of_life_game_start(){

    //Road
    glColor3f(0.412, 0.412, 0.412);
    glBegin(GL_POLYGON);
    glVertex2f(20,0);
    glVertex2f(20,100);
    glVertex2f(80,100);
    glVertex2f(80,0);
    glEnd();

    //Road ar left Border
    glColor3f(1.000, 1.000, 1.000);
    glBegin(GL_POLYGON);
    glVertex2f(20,0);
    glVertex2f(20,100);
    glVertex2f(23,100);
    glVertex2f(23,0);
    glEnd();

    //Road ar Right Border
    glColor3f(1.000, 1.000, 1.000);
    glBegin(GL_POLYGON);
    glVertex2f(77,0);
    glVertex2f(77,100);
    glVertex2f(80,100);
    glVertex2f(80,0);
    glEnd();


    //Road ar Middle Border
    glColor3f(1.000, 1.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(48,MoveTrackTop+80);
    glVertex2f(48,MoveTrackTop+100);
    glVertex2f(52,MoveTrackTop+100);
    glVertex2f(52,MoveTrackTop+80);
    glEnd();
    MoveTrackTop--;
    if(MoveTrackTop<-100){
        MoveTrackTop =20;
        Count_score++;
    }
    //Middle
    glColor3f(1.000, 1.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(48,MoveTrackMDL+40);
    glVertex2f(48,MoveTrackMDL+60);
    glVertex2f(52,MoveTrackMDL+60);
    glVertex2f(52,MoveTrackMDL+40);
    glEnd();



    MoveTrackMDL--;
    if(MoveTrackMDL<-60){
        MoveTrackMDL =60;
        Count_score++;
    }
    //Botton
    glColor3f(1.000, 1.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(48,MoveTrackBTM+0);
    glVertex2f(48,MoveTrackBTM+20);
    glVertex2f(52,MoveTrackBTM+20);
    glVertex2f(52,MoveTrackBTM+0);
    glEnd();
    MoveTrackBTM--;
    if(MoveTrackBTM<-20){
        MoveTrackBTM=100;
        Count_score++;
    }

    //Ahkane Score Broad

     glColor3f(0.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(80,97);
    glVertex2f(100,97);
    glVertex2f(100,98-8);
    glVertex2f(80,98-8);
    glEnd();


    //Akane Score print kora hoise
    char Point_buffer [50];
    sprintf (Point_buffer, "POINT: %d", Count_score);
    glColor3f(0.000, 1.000, 0.000);
    renderBitmapString(80.5,95,(void *)F2,Point_buffer);

    char MOMENTUM_Buffer [50];
    sprintf (MOMENTUM_Buffer, "MOMENTUM:%dKm/h", Speed_of_Game);
    glColor3f(0.000, 1.000, 0.000);
    renderBitmapString(80.5,95-2,(void *)F3,MOMENTUM_Buffer);

    if(Count_score % 50 == 0){
        int last = Count_score /50;
        if(last!=LVL){
            LVL = Count_score /50;
            Speed_of_Game=Speed_of_Game+2;

        }
    }

    char level_buffer [50];
    sprintf (level_buffer, "LEVEL: %d", LVL);
    glColor3f(0.000, 1.000, 0.000);
    renderBitmapString(80.5,95-4,(void *)F3,level_buffer);

    //Main car
    glColor3f(0.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(MainCarLR_index+26-2,5);
    glVertex2f(MainCarLR_index+26-2,7);
    glVertex2f(MainCarLR_index+30+2,7);
    glVertex2f(MainCarLR_index+30+2,5);
    glEnd();


    glColor3f(0.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(MainCarLR_index+26-2,1);
    glVertex2f(MainCarLR_index+26-2,3);
    glVertex2f(MainCarLR_index+30+2,3);
    glVertex2f(MainCarLR_index+30+2,1);
    glEnd();

    //Car Body
    glColor3f(0.678, 1.000, 0.184);
    glBegin(GL_POLYGON);
    glVertex2f(MainCarLR_index+26,1);
    glVertex2f(MainCarLR_index+26,8);
    glColor3f(0.000, 0.545, 0.545);

    glVertex2f(MainCarLR_index+28,10);
    glVertex2f(MainCarLR_index+30,8);
    glVertex2f(MainCarLR_index+30,1);
    glEnd();


    //C1
    glColor3f(0.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(C1_LR_index1+26-2,C1+100-4);
    glVertex2f(C1_LR_index1+26-2,C1+100-6);
    glVertex2f(C1_LR_index1+30+2,C1+100-6);
    glVertex2f(C1_LR_index1+30+2,C1+100-4);
    glEnd();
    glColor3f(0.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(C1_LR_index1+26-2,C1+100);
    glVertex2f(C1_LR_index1+26-2,C1+100-2);
    glVertex2f(C1_LR_index1+30+2,C1+100-2);
    glVertex2f(C1_LR_index1+30+2,C1+100);
    glEnd();
    glColor3f(1.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(C1_LR_index1+26,C1+100);
    glVertex2f(C1_LR_index1+26,C1+100-7);
    glVertex2f(C1_LR_index1+28,C1+100-9);
    glVertex2f(C1_LR_index1+30,C1+100-7);
    glVertex2f(C1_LR_index1+30,C1+100);
    glEnd();



    C1--;
    if(C1<-100){
        C1=0;
        C1_LR_index1=MainCarLR_index;
    }


    if((abs(MainCarLR_index-C1_LR_index1)<8) && (C1+100<10)){
            Game_begin = 0;
            gv=1;

    }

    //C2
    glColor3f(0.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(C2_LR_index2+26-2,C2+100-4);
    glVertex2f(C2_LR_index2+26-2,C2+100-6);
    glVertex2f(C2_LR_index2+30+2,C2+100-6);
    glVertex2f(C2_LR_index2+30+2,C2+100-4);
    glEnd();
    glColor3f(0.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(C2_LR_index2+26-2,C2+100);
    glVertex2f(C2_LR_index2+26-2,C2+100-2);
    glVertex2f(C2_LR_index2+30+2,C2+100-2);
    glVertex2f(C2_LR_index2+30+2,C2+100);
    glEnd();
    glColor3f(0.294, 0.000, 0.510);
    glBegin(GL_POLYGON);
    glVertex2f(C2_LR_index2+26,C2+100);
    glVertex2f(C2_LR_index2+26,C2+100-7);
    glVertex2f(C2_LR_index2+28,C2+100-9);
    glVertex2f(C2_LR_index2+30,C2+100-7);
    glVertex2f(C2_LR_index2+30,C2+100);
    glEnd();
    C2--;
    if(C2<-100){
        C2=0;
        C2_LR_index2=MainCarLR_index;
    }


    if((abs(MainCarLR_index-C2_LR_index2)<8) && (C2+100<10)){
            Game_begin = 0;
            gv=1;
    }


    //C3
    glColor3f(0.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(C3_LR_index3+26-2,C3+100-4);
    glVertex2f(C3_LR_index3+26-2,C3+100-6);
    glVertex2f(C3_LR_index3+30+2,C3+100-6);
    glVertex2f(C3_LR_index3+30+2,C3+100-4);
    glEnd();
    glColor3f(0.000, 0.000, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(C3_LR_index3+26-2,C3+100);
    glVertex2f(C3_LR_index3+26-2,C3+100-2);
    glVertex2f(C3_LR_index3+30+2,C3+100-2);
    glVertex2f(C3_LR_index3+30+2,C3+100);
    glEnd();
    glColor3f(1.000, 0.271, 0.000);
    glBegin(GL_POLYGON);
    glVertex2f(C3_LR_index3+26,C3+100);
    glVertex2f(C3_LR_index3+26,C3+100-7);
    glVertex2f(C3_LR_index3+28,C3+100-9);
    glVertex2f(C3_LR_index3+30,C3+100-7);
    glVertex2f(C3_LR_index3+30,C3+100);
    glEnd();
    C3--;
    if(C3<-100){
        C3=0;
        C3_LR_index3=MainCarLR_index;
    }

    if((abs(MainCarLR_index-C3_LR_index3)<8) && (C3+100<10)){
            Game_begin = 0;
            gv=1;

    }

}

void GAME_Design(){

        //Road BackRound
        glColor3f(0.36, 0.61, 0.39);
        glBegin(GL_POLYGON);
        glVertex2f(0,55);
        glVertex2f(100,55);
        glColor3f(0.604, 0.804, 0.196);
        glVertex2f(100,50-50);
        glVertex2f(0,50-50);
        glEnd();

        //Road Middle
        glColor3f(0.49, 0.49, 0.49);
        glBegin(GL_TRIANGLES);
        glVertex2f(32-2+21,55);
        glVertex2f(32+58,50-50);
        glVertex2f(32-22,50-50);
        glEnd();

        //Road Sky
        glColor3f(1, 1, 1);
        glBegin(GL_TRIANGLES);
        glVertex2f(32-2+21,55);
        glVertex2f(50+2,50-50);
        glVertex2f(50-2,50-50);
        glEnd();


        glColor3f(0.992, 0.369, 0.325);
        glBegin(GL_POLYGON);
        glVertex2f(100,100);
        glVertex2f(0,100);
        glColor3f(0.686, 0.933, 0.933);
        glVertex2f(0,55);
        glVertex2f(100,55);
        glEnd();

        //mountain 1
        glColor3f(0.20, 1.0, 0.20);
        glBegin(GL_TRIANGLES);
        glVertex2f(20,55+10);
        glVertex2f(20+7,55);
        glVertex2f(0,55);
        glEnd();

        //mountain 2
        glColor3f(0.22, 0.36, 0.20);//Green grass
        glBegin(GL_TRIANGLES);
        glVertex2f(20+15,55+12);
        glVertex2f(20+20+10,55);
        glVertex2f(0+10,55);
        glEnd();

        //mountain  4
        glColor3f(0.20, 1.0, 0.20);//parrot green
        glBegin(GL_TRIANGLES);
        glVertex2f(87,55+10);
        glVertex2f(100,55);
        glVertex2f(60,55);
        glEnd();

         //mountain 3
        glColor3f(0.22, 0.36, 0.20);
        glBegin(GL_TRIANGLES);
        glVertex2f(70,70);
        glVertex2f(90,55);
        glVertex2f(50,55);
        glEnd();


        //Tree Left
            //Bottom
        glColor3f(0.871, 0.722, 0.529);
        glBegin(GL_TRIANGLES);
        glVertex2f(11,55);
        glVertex2f(12,55-10);
        glVertex2f(10,55-10);
        glEnd();

            //Up
      glColor3f(0.133, 0.545, 0.133);
        glBegin(GL_TRIANGLES);
        glVertex2f(11,55+3);
        glVertex2f(12+3,55-3);
        glVertex2f(10-3,55-3);
        glEnd();




        Funcfor_tree(5,-15);
        Funcfor_tree(9,5);
        Funcfor_tree(85,9);
        Funcfor_tree(75,-5);





        //Game ar menu
        glColor3f(0.40,0.56,0.60);
        glBegin(GL_POLYGON);
        glVertex2f(32-4,50+5+10);
        glVertex2f(32+46,50+5+10);
        glVertex2f(32+46,50-15+10);
        glVertex2f(32-4,50-15+10);
        glEnd();

        glColor3f(00, 0, 0.000);
        glBegin(GL_POLYGON);
        glVertex2f(32-4,50+5+10);
        glVertex2f(32+46,50+5+10);
        glVertex2f(32+46,50+4+10);
        glVertex2f(32-4,50+4+10);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(32+45,50+5+10);
        glVertex2f(32+46,50+5+10);
        glVertex2f(32+46,50-15+10);
        glVertex2f(32+45,50-15+10);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(32-4,50-14+10);
        glVertex2f(32+46,50-14+10);
        glVertex2f(32+46,50-15+10);
        glVertex2f(32-4,50-15+10);
        glEnd();
        glBegin(GL_POLYGON);
        glVertex2f(32-4,50+5+10);
        glVertex2f(32-5,50+5+10);
        glVertex2f(32-5,50-15+10);
        glVertex2f(32-4,50-15+10);
        glEnd();



        //Ahkane Text ar Information dewa
        if(gv==1){
            glColor3f(1.000, 0.000, 0.000);
            renderBitmapString(35,60+10,(void *)F1,"GAME OVER");
            glColor3f(1.000, 0.000, 0.000);
            char buffer2 [50];
            sprintf (buffer2, "Your Score is : %d", Count_score);
            renderBitmapString(33,60-4+10,(void *)F1,buffer2);

        }

        glColor3f(1.000, 1.000, 0.000);
        renderBitmapString(30,80,(void *)F1,"RACE OF LIFE ");

        glColor3f(0.000, 1.000, 0.000);
        renderBitmapString(30,50+10,(void *)F2,"Press SPACE to START and ESC to Exit");
        renderBitmapString(30,50-3+10,(void *)F2,"Problems OF Life");

        glColor3f(1.000, 1.000, 1.000);
        renderBitmapString(30,50-6+10,(void *)F3,"1.CGPA as CAR1");
        renderBitmapString(30,50-8+10,(void *)F3,"2.GirlFriend as CAR2");
        renderBitmapString(30,50-10+10,(void *)F3,"3.Society as CAR3");
        renderBitmapString(30,50-12+10,(void *)F3,"4.Me as Main CAR");


        glColor3f(0.000, 1.000, 1.000);
        renderBitmapString(30-15,50-40,(void *)F3,"Life is a race ... if you don't run fast ... you will be like a broken undaa");
        renderBitmapString(30-5,50-43,(void *)F3,"Dialogue By 3 Idiots");


}



void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    if(Game_begin==1){
        // glClearColor(0.627, 0.322, 0.176,1);

        glClearColor(0.000, 0.392, 0.000,1);
        Race_of_life_game_start();
    }

    else{
        GAME_Design();//325
        //glClearColor(0.184, 0.310, 0.310,1);



    }



    glFlush();
    glutSwapBuffers();
}



void spe_key(int key, int x, int y){
        switch (key) {
        case GLUT_KEY_DOWN:
            if(Speed_of_Game>(50+(LVL*2)))
            Speed_of_Game=Speed_of_Game-2;
            break;
        case GLUT_KEY_UP:
            Speed_of_Game=Speed_of_Game+2;
            break;

        case GLUT_KEY_LEFT:
            if(MainCarLR_index>=0){
                MainCarLR_index = MainCarLR_index - (Speed_of_Game/10);
                if(MainCarLR_index<0){
                    MainCarLR_index=-1;
                }
            }
            break;


        case GLUT_KEY_RIGHT:
            if(MainCarLR_index<=44){
                MainCarLR_index = MainCarLR_index + (Speed_of_Game/10);
                if(MainCarLR_index>44){
                    MainCarLR_index = 45;
                }
            }
            break;

        default:
                break;
        }

}

void processKeys(unsigned char key, int x, int y) {

      switch (key)
            {
                case ' ':
            if(Game_begin==0){
                Game_begin = 1;
                gv = 0;
                Speed_of_Game = 50;
                MoveTrackTopMost = 0;
                MoveTrackTop = 0;
                MoveTrackMDL = 0;
                MoveTrackBTM = 0;
                MainCarLR_index = 0 ;
                C1 = 0;
                C1_LR_index1=0;
                C2 = +35;
                C2_LR_index2=0;
                C3 = +70;
                C3_LR_index3=0;
                Count_score=0;
                LVL=0;
            }
             break;

             case 27:
                 exit(0);
             break;
             default:
                break;
        }
}

void timer(int){
    glutPostRedisplay();
    glutTimerFunc(1000/Speed_of_Game,timer,0);
}



int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(750,650);
    glutInitWindowPosition(500,20);//Windows ke dane bame soranno
    glutCreateWindow("Life Racing Game by Rohan");

    glutDisplayFunc(display); //496
    // glutDisplayFunc sets the display callback for the current window.
    glutSpecialFunc(spe_key);
    glutKeyboardFunc(processKeys );

    glOrtho(0,100,0,100,-1,1);
    glClearColor(0.184, 0.310, 0.310,1);

    glutTimerFunc(1000,timer,0);
    glutMainLoop();

    return 0;
}

