#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>

float xrot = 0.0;
float yrot = 0.0;
float xdiff = 0.0;
float ydiff = 0.0;
bool mouseDown = false;
int is_depth;
static GLfloat spin = 0.0;
static GLfloat spin_speed = 1.0;
int x1=5,y1=-15,z1=10,z2=10;
void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void ukuran (int, int);
void keyboard (unsigned char key, int x, int y){
    switch (key)
    {
        //GESER KE KIRI
    case 'a':
        glTranslatef(-3.0, 0.0, 0.0);
        break;
    case 'A':
        glTranslatef(-1.0, 0.0, 0.0);
        break;
        //GESER KE KANAN
    case 'd':
        glTranslatef(3.0, 0.0, 0.0);
        break;
    case 'D':
        glTranslatef(2.0, 0.0, 0.0);
        break;
        //GESER KE ATAS
    case '7':
        glTranslatef(0.0, 1.5, 0.0);
        break;

    case '9':
        glTranslatef(0.0, -1.5f, 0.0);
        break;

        //GERAK KE DEPAN
    case 'w':
        glTranslatef(0.0, 0.0, 3.0f);
        break;
    case 'W':
        glTranslatef(0.0, 0.0, 5.5);
        break;
        //GERAK KE BELAKANG
    case 's':
        glTranslatef(0.0, 0.0, -1.5f);
        break;
    case 'S':
        glTranslatef(0.0, 0.0, -3.5f);
        break;
        //ROTATE KE KIRI
    case '4':
        glRotatef(1.0, 0.0, -5.0, 0.0);
        break;
    case 'K':
        glRotatef(5.0, 0.0, -5.0, 0.0);
        break;
        //ROTATE KE KANAN
    case '6':
        glRotatef(1.0, 0.0, 5.0, 0.0);
        break;
    case '/':
        glRotatef(2.0, 0.0, 5.0, 0.0);
        break;

    case '5':
        if(is_depth){
            is_depth=0;
            glDisable(GL_DEPTH_TEST);
        }
        else{
            is_depth=1;
            glEnable(GL_DEPTH_TEST);
        }
        break;
		case '3':
			glRotatef(1.0, 0.0, 0.0, -5.0);
			break;
			//rotate ke samping kiri
		case '1':
			glRotatef(1.0, 0.0, 0.0, 5.0);
			break;
		case 'i':
			glRotatef(5.0, 0.0, 0.0, 5.0);
			break;
			//rotate ke atas
		case '8':
			glRotatef(1.0, -5.0, 0.0, 0.0);
			break;
		case 'u':
			glRotatef(5.0, -5.0, 0.0, 0.0);
			break;
			//rotate ke bawah
		case '2':
			glRotatef(1.0, 5.0, 0.0, 0.0);
			break;
		case 'l':
			glRotatef(5.0, 5.0, 0.0, 0.0);
			break;
    }
    tampil();
}
void mouse(int button, int state, int x, int y){
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        mouseDown = true;
        xdiff = x-yrot;
        ydiff = -y + xrot;
    }else{
        mouseDown = false;
    }
    glutPostRedisplay();
}
void mouseMotion(int x, int y){
    if(mouseDown){
        yrot = x - xdiff;
        xrot = y + ydiff;
        glutPostRedisplay();
    }
}
int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(250,80);
    glutCreateWindow("Eliansion Ivan-672018311");
    init();
    glutDisplayFunc(tampil);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutReshapeFunc(ukuran);
    glutMainLoop();
    return 0;
}
void init(void){
    glClearColor(0.0,0.0,0.0,0.0);
    glEnable(GL_DEPTH_TEST);
    is_depth=1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(9.0);
    glLineWidth(6.0f);
}
void pilar_nyabang_mario(){
    //pilar 1 nyabang kiri
    //depan
    glColor3f(1,1,0);
    glVertex3f(-21.5,8,10);
    glVertex3f(-25,8,12);
    glVertex3f(-25,-12,12);
    glVertex3f(-21.5,-12,10);

    //belakang
    glVertex3f(-23,8,5.5);
    glVertex3f(-26.5,8,7.5);
    glVertex3f(-26.5,-12,7.5);
    glVertex3f(-23,-12,5);

    //kiri
    glVertex3f(-26.5,8,7.5);
    glVertex3f(-26.5,-12,7.5);
    glVertex3f(-25,-12,12);
    glVertex3f(-25,8,12);

    //kanan
    glVertex3f(-22,8,10);
    glVertex3f(-22,-12,10);
    glVertex3f(-23,-12,6);
    glVertex3f(-23,8,6);


//    //atas
//    glVertex3f(-21.5,8,10);
//    glVertex3f(-25,8,12);
//    glVertex3f(-26.5,8,7.5);
//    glVertex3f(-23,8,5.5);

    //pilar 2 nyabang kiri
    glColor3f(0,1,0);
    glVertex3f(-23,8,5.5);
    glVertex3f(-26.5,8,3.5);
    glVertex3f(-26.5,-12,3.5);
    glVertex3f(-23,-12,5);

    glVertex3f(-21.5,8,0);
    glVertex3f(-25,8,-2);
    glVertex3f(-25,-12,-2);
    glVertex3f(-21.5,-12,0);

    glVertex3f(-26.5,8,3.5);
    glVertex3f(-26.5,-12,3.5);
    glVertex3f(-25,-12,-2);
    glVertex3f(-25,8,-2);

    glVertex3f(-22,8,0);
    glVertex3f(-22,-12,0);
    glVertex3f(-23,-12,5);
    glVertex3f(-23,8,5);

    glVertex3f(-21.5,8,0);
    glVertex3f(-25,8,-2);
    glVertex3f(-26.5,8,3.5);
    glVertex3f(-23,8,5.5);
}
void kotak_depan_cabang(){
    glColor3f(1,0,0);
    //kiri
    glVertex3f(-26, 3, 2);
    glVertex3f(-26, -12, 2);
    glVertex3f(-26, -12, 8);
    glVertex3f(-26, 3, 8);

    //belakang
    glVertex3f(-28, 3, 2);
    glVertex3f(-28, -12, 2);
    glVertex3f(-22, -12, 2);
    glVertex3f(-22, 3,2);

    //depan
    glVertex3f(-28, 3, 8);
    glVertex3f(-28, -12, 8);
    glVertex3f(-22, -12, 8);
    glVertex3f(-22, 3, 8);

    //atas
    glVertex3f(-28, 3, 2);
    glVertex3f(-28, 3, 8);
    glVertex3f(-23, 3, 8);
    glVertex3f(-23, 3, 2);

}
void dua_kali_cabang(){

  glColor3f(0.5,0.5,1.5);
  //kiri
    glVertex3f(-30,2,8);
    glVertex3f(-30,2,2);
    glVertex3f(-30,-12,2);
    glVertex3f(-30,-12,8);

//    kanan
    glVertex3f(-25,2,12);
    glVertex3f(-25,2,-1);
    glVertex3f(-25,-12,-1);
    glVertex3f(-25,-12,12);


//depan belakang boleh apus
    //depan
    glVertex3f(-30,2,8);
    glVertex3f(-25,2,8);
    glVertex3f(-25,-12,8);
    glVertex3f(-30,-12,8);

    //belakang
    glVertex3f(-30,2,2);
    glVertex3f(-25,2,2);
    glVertex3f(-25,-12,2);
    glVertex3f(-30,-12,2);

    //atas
    glVertex3f(-30, 2, 2);
    glVertex3f(-30, 2, 8);
    glVertex3f(-25, 2, 8);
    glVertex3f(-25, 2, 2);

    //mau nyabang lagi ijo
    //depan
    glColor3f(0.2,1.3,2.1);
    glVertex3f(-30,2,8);//a
    glVertex3f(-25,2,12);//b
    glVertex3f(-25,-12,12);//c
    glVertex3f(-30,-12,8);//d

    //belakang nya
    glColor3f(0.2,1.3,2.1);
    glVertex3f(-30,-12,2);
    glVertex3f(-30,2,2);
    glVertex3f(-25,2,-2);//b
    glVertex3f(-25,-12,-2);

    //depannya kanan
    glColor3f(0.3,1.2,0.2);
    glVertex3f(-25,1,12);//b
    glVertex3f(-25,-12,12);//c
    glVertex3f(-30,-12,22);//c
    glVertex3f(-30,1,22);//b

    //depannya kiri
    glColor3f(0.3,1.2,0.2);
    glVertex3f(-30,1,8);//b
    glVertex3f(-30,-12,8);//c
    glVertex3f(-35,-12,18);//c
    glVertex3f(-35,1,18);

    //depan
    glColor3f(0.5,0.5,0.5);
    glVertex3f(-30,-12,22);//c
    glVertex3f(-30,1,22);
    glVertex3f(-35,1,18);
    glVertex3f(-35,-12,18);//c

    //atas ijo
    glVertex3f(-30,1,22);
    glVertex3f(-35,1,18);
    glVertex3f(-30,1,8);//a
    glVertex3f(-25,1,12);//

    //kotak belkang kiri
    glColor3f(0.3,0.5,0.2);
    glVertex3f(-30,1,2);//b
    glVertex3f(-30,-12,2);//c
    glVertex3f(-35,-12,-8);//c
    glVertex3f(-35,1,-8);

    //kotak belakang kanan
    glVertex3f(-25,1,-2);//b
    glVertex3f(-25,-12,-2);//c
    glVertex3f(-29,-12,-12);//c
    glVertex3f(-29,1,-12);

    //atas
        glVertex3f(-30,1,2);//b
        glVertex3f(-35,1,-8);
        glVertex3f(-29,1,-12);
        glVertex3f(-25,1,-2);//b



        //tutup belakang
        glVertex3f(-35,1,-8);
        glVertex3f(-29,1,-12);
        glVertex3f(-29,-12,-12);
        glVertex3f(-35,-12,-8);
//
//
//    //kotak didalam depan
//        glColor3f(0.5,0.5,0.9);
//        //depan
//    glVertex3f(-31,-12,26);//c
//    glVertex3f(-31,1,26);
//    glVertex3f(-35,1,24);
//    glVertex3f(-35,-12,24);
//
//    //belakang nya
//    glColor3f(0.5,0.5,0.9);
//    glVertex3f(-30,-12,22);//c
//    glVertex3f(-30,1,22);
//    glVertex3f(-32,1,20);
//    glVertex3f(-32,-12,20);
//
//    //kanan
//    glVertex3f(-34,1,21);
//    glVertex3f(-34,-12,21);
//    glVertex3f(-32,-12,18);
//    glVertex3f(-32,1,18);
//
//    //kiri
//    glVertex3f(-30,1,20);
//    glVertex3f(-30,-12,20);
//    glVertex3f(-32,-12,23);//c
//    glVertex3f(-32,1,23);
//
//    //atas
//    glVertex3f(-32,1,23);
//    glVertex3f(-34,1,21);
//    glVertex3f(-32,1,18);
//    glVertex3f(-30,1,20);
//



}
void dua_kali_cabang2(){
  glColor3f(0.5,0.5,1.5);
  //kiri
    glVertex3f(30,2,8);
    glVertex3f(30,2,2);
    glVertex3f(30,-12,2);
    glVertex3f(30,-12,8);

//    kanan
    glVertex3f(25,2,12);
    glVertex3f(25,2,-1);
    glVertex3f(25,-12,-1);
    glVertex3f(25,-12,12);


//depan belakang boleh apus
    //depan
    glVertex3f(30,2,8);
    glVertex3f(25,2,8);
    glVertex3f(25,-12,8);
    glVertex3f(30,-12,8);

    //belakang
    glVertex3f(30,2,2);
    glVertex3f(25,2,2);
    glVertex3f(25,-12,2);
    glVertex3f(30,-12,2);

    //atas
    glVertex3f(30, 2, 2);
    glVertex3f(30, 2, 8);
    glVertex3f(25, 2, 8);
    glVertex3f(25, 2, 2);

    //mau nyabang lagi ijo
    //depan
    glColor3f(0.2,1.3,2.1);
    glVertex3f(30,2,8);//a
    glVertex3f(25,2,12);//b
    glVertex3f(25,-12,12);//c
    glVertex3f(30,-12,8);//d

    //belakang nya
    glColor3f(0.2,1.3,2.1);
    glVertex3f(30,-12,2);
    glVertex3f(30,2,2);
    glVertex3f(25,2,-2);//b
    glVertex3f(25,-12,-2);

    //depannya kanan
    glColor3f(0.3,1.2,0.2);
    glVertex3f(25,1,12);//b
    glVertex3f(25,-12,12);//c
    glVertex3f(30,-12,22);//c
    glVertex3f(30,1,22);//b

    //depannya kiri
    glColor3f(0.3,1.2,0.2);
    glVertex3f(30,1,8);//b
    glVertex3f(30,-12,8);//c
    glVertex3f(35,-12,18);//c
    glVertex3f(35,1,18);

    //depan
    glColor3f(0.5,0.5,0.5);
    glVertex3f(30,-12,22);//c
    glVertex3f(30,1,22);
    glVertex3f(35,1,18);
    glVertex3f(35,-12,18);//c

    //atas ijo
    glVertex3f(30,1,22);
    glVertex3f(35,1,18);
    glVertex3f(30,1,8);//a
    glVertex3f(25,1,12);//

    //kotak belkang kiri
    glColor3f(0.3,0.5,0.2);
    glVertex3f(30,1,2);//b
    glVertex3f(30,-12,2);//c
    glVertex3f(35,-12,-8);//c
    glVertex3f(35,1,-8);

    //kotak belakang kanan
    glVertex3f(25,1,-2);//b
    glVertex3f(25,-12,-2);//c
    glVertex3f(29,-12,-12);//c
    glVertex3f(29,1,-12);

    //atas
        glVertex3f(30,1,2);//b
        glVertex3f(35,1,-8);
        glVertex3f(29,1,-12);
        glVertex3f(25,1,-2);//b

    //tutup belakang
        glVertex3f(35,1,-8);
        glVertex3f(29,1,-12);
        glVertex3f(29,-12,-12);
        glVertex3f(35,-12,-8);


}
void cabang_akhir_kanan(){
    glColor3f(1,0,1);
    glVertex3f(29,0,19);
    glVertex3f(29,-12,19);
    glVertex3f(29,-12,25);
    glVertex3f(29,0,25);

    glVertex3f(31,0,20);
    glVertex3f(31,-12,20);
    glVertex3f(31,-12,25);
    glVertex3f(31,0,25);

    glVertex3f(29,0,25);
    glVertex3f(29,-12,25);
    glVertex3f(31,-12,25);
    glVertex3f(31,0,25);
    glColor3f(1,1,0);
    glVertex3f(29,0,19);
    glVertex3f(29,0,25);
    glVertex3f(31,0,19);
    glVertex3f(31,0,25);

    glVertex3f(34,0,19);
    glVertex3f(34,-12,19);
    glVertex3f(37,-12,20);
    glVertex3f(37,0,20);

    glVertex3f(34,0,16);
    glVertex3f(34,-12,16);
    glVertex3f(37,-12,17);
    glVertex3f(37,0,17);
    glColor3f(1,0,1);
    glVertex3f(37,0,17);
    glVertex3f(37,-12,17);
    glVertex3f(37,-12,20);
    glVertex3f(37,0,20);

    glVertex3f(37,0,17);
    glVertex3f(34,0,16);
    glVertex3f(34,0,19);
    glVertex3f(37,0,20);

    //belakang
    glVertex3f(34,0,-6);
    glVertex3f(34,-12,-6);
    glVertex3f(37,-12,-7);
    glVertex3f(37,0,-7);

    glVertex3f(34,0,-9);
    glVertex3f(34,-12,-9);
    glVertex3f(37,-12,-10);
    glVertex3f(37,0,-10);
    glColor3f(1,0,1);
    glVertex3f(37,0,-7);
    glVertex3f(37,-12,-7);
    glVertex3f(37,-12,-10);
    glVertex3f(37,0,-10);
    glColor3f(1,1,1);
    glVertex3f(37,0,-7);
    glVertex3f(34,0,-6);
    glVertex3f(34,0,-9);
    glVertex3f(37,0,-10);

    //belakang2
    glVertex3f(28,0,-10);
    glVertex3f(28,-12,-10);
    glVertex3f(28,-12,-14);
    glVertex3f(28,0,-14);

    glVertex3f(30,0,-10);
    glVertex3f(30,-12,-10);
    glVertex3f(30,-12,-14);
    glVertex3f(30,0,-14);

    glVertex3f(30,0,-14);
    glVertex3f(30,-12,-14);
    glVertex3f(28,-12,-14);
    glVertex3f(28,0,-14);
    glColor3f(1,1,0);
    glVertex3f(30,0,-10);
    glVertex3f(28,0,-10);
    glVertex3f(28,0,-14);
    glVertex3f(30,0,-14);
}
void cabang_akhir_kiri(){
     glColor3f(1,0,1);
    glVertex3f(-29,0,19);
    glVertex3f(-29,-12,19);
    glVertex3f(-29,-12,25);
    glVertex3f(-29,0,25);

    glVertex3f(-31,0,20);
    glVertex3f(-31,-12,20);
    glVertex3f(-31,-12,25);
    glVertex3f(-31,0,25);

    glVertex3f(-29,0,25);
    glVertex3f(-29,-12,25);
    glVertex3f(-31,-12,25);
    glVertex3f(-31,0,25);
    glColor3f(1,1,0);
    glVertex3f(-29,0,19);
    glVertex3f(-29,0,25);
    glVertex3f(-31,0,19);
    glVertex3f(-31,0,25);

    glVertex3f(-34,0,19);
    glVertex3f(-34,-12,19);
    glVertex3f(-37,-12,20);
    glVertex3f(-37,0,20);

    glVertex3f(-34,0,16);
    glVertex3f(-34,-12,16);
    glVertex3f(-37,-12,17);
    glVertex3f(-37,0,17);
    glColor3f(1,0,1);
    glVertex3f(-37,0,17);
    glVertex3f(-37,-12,17);
    glVertex3f(-37,-12,20);
    glVertex3f(-37,0,20);

    glVertex3f(-37,0,17);
    glVertex3f(-34,0,16);
    glVertex3f(-34,0,19);
    glVertex3f(-37,0,20);

     //belakang
    glVertex3f(-34,0,-6);
    glVertex3f(-34,-12,-6);
    glVertex3f(-37,-12,-7);
    glVertex3f(-37,0,-7);

    glVertex3f(-34,0,-9);
    glVertex3f(-34,-12,-9);
    glVertex3f(-37,-12,-10);
    glVertex3f(-37,0,-10);
    glColor3f(1,0,1);
    glVertex3f(-37,0,-7);
    glVertex3f(-37,-12,-7);
    glVertex3f(-37,-12,-10);
    glVertex3f(-37,0,-10);
    glColor3f(1,1,1);
    glVertex3f(-37,0,-7);
    glVertex3f(-34,0,-6);
    glVertex3f(-34,0,-9);
    glVertex3f(-37,0,-10);
    //belakang2
    glVertex3f(-28,0,-10);
    glVertex3f(-28,-12,-10);
    glVertex3f(-28,-12,-14);
    glVertex3f(-28,0,-14);

    glVertex3f(-30,0,-10);
    glVertex3f(-30,-12,-10);
    glVertex3f(-30,-12,-14);
    glVertex3f(-30,0,-14);

    glVertex3f(-30,0,-14);
    glVertex3f(-30,-12,-14);
    glVertex3f(-28,-12,-14);
    glVertex3f(-28,0,-14);
    glColor3f(1,1,0);
    glVertex3f(-30,0,-10);
    glVertex3f(-28,0,-10);
    glVertex3f(-28,0,-14);
    glVertex3f(-30,0,-14);
}
void meja_resepsionis(){
    glColor3f(0,0,1);
    //pertama
    glVertex3f(-7, -11, 3);
    glVertex3f(-7, -11, 2.5);
    glVertex3f(-10, -11, 2.5);
    glVertex3f(-10, -11, 3);

    glVertex3f(-7, -12, 3);
    glVertex3f(-7, -11, 3);
    glVertex3f(-10, -11, 3);
    glVertex3f(-10, -12, 3);

    glVertex3f(-7, -12, 2.5);
    glVertex3f(-7, -11, 2.5);
    glVertex3f(-10, -11, 2.5);
    glVertex3f(-10, -12, 2.5);

    //kedua
    glVertex3f(-7, -11, 3);
    glVertex3f(-7, -11, 2.5);
    glVertex3f(-6, -11, 0);
    glVertex3f(-6, -11, 0.5);

    glVertex3f(-6, -11, 0);
    glVertex3f(-6, -11, 0.5);
    glVertex3f(-6, -12, 0.5);
    glVertex3f(-6, -12, 0);

    glVertex3f(-7, -12, 3);
    glVertex3f(-7, -11, 3);
    glVertex3f(-6, -11, 0.5);
    glVertex3f(-6, -12, 0.5);

    glVertex3f(-7, -12, 2.5);
    glVertex3f(-7, -11, 2.5);
    glVertex3f(-6, -11, 0);
    glVertex3f(-6, -12, 0);

    //letiga
    glVertex3f(-10, -11, 3);
    glVertex3f(-10, -11, 2.5);
    glVertex3f(-11, -11, 0);
    glVertex3f(-11, -11, 0.5);

    glVertex3f(-11, -11, 0);
    glVertex3f(-11, -11, 0.5);
    glVertex3f(-11, -12, 0.5);
    glVertex3f(-11, -12, 0);

    glVertex3f(-10, -12, 3);
    glVertex3f(-10, -11, 3);
    glVertex3f(-11, -11, 0.5);
    glVertex3f(-11, -12, 0.5);

    glVertex3f(-10, -12, 2.5);
    glVertex3f(-10, -11, 2.5);
    glVertex3f(-11, -11, 0);
    glVertex3f(-11, -12, 0);
}
void jendela(){
    int i, j;
    //depan kiri
    for(i=0; i<=6; i+=3){
        for(j=0; j<=12; j+=4){
            glColor3f(0,0,1);
            glVertex3f(-18.5+i,7-j,10);
            glVertex3f(-20+i,7-j,10);
            glVertex3f(-20+i,4-j,10);
            glVertex3f(-18.5+i,4-j,10);
        }
    }
    //depan kanan
    for(i=0; i<=6; i+=3){
        for(j=0; j<=12; j+=4){
            glColor3f(0,0,1);
            glVertex3f(12.5+i,7-j,10);
            glVertex3f(14+i,7-j,10);
            glVertex3f(14+i,4-j,10);
            glVertex3f(12.5+i,4-j,10);
        }
    }

    //belakang kiri
    for(i=0; i<=6; i+=3){
        for(j=0; j<=12; j+=4){
            glColor3f(0,0,1);
            glVertex3f(-18.5+i,7-j,0);
            glVertex3f(-20+i,7-j,0);
            glVertex3f(-20+i,4-j,0);
            glVertex3f(-18.5+i,4-j,0);
        }
    }

    //belakang kanan
    for(i=0; i<=6; i+=3){
        for(j=0; j<=12; j+=4){
            glColor3f(0,0,1);
            glVertex3f(12.5+i,7-j,0);
            glVertex3f(14+i,7-j,0);
            glVertex3f(14+i,4-j,0);
            glVertex3f(12.5+i,4-j,0);
        }
    }
}
void rak_kunci(){
    glColor3ub(163, 72, 15);
    glVertex3f(-7, -12, 0);
    glVertex3f(-7, -10, 0);
    glVertex3f(-10, -10, 0);
    glVertex3f(-10, -12, 0);

    glVertex3f(-7, -12, 0.5);
    glVertex3f(-7, -10, 0.5);
    glVertex3f(-10, -10, 0.5);
    glVertex3f(-10, -12, 0.5);

    glVertex3f(-7, -12, 0.5);
    glVertex3f(-7, -10, 0.5);
    glVertex3f(-7, -10, 0);
    glVertex3f(-7, -12, 0);

    glVertex3f(-10, -12, 0.5);
    glVertex3f(-10, -10, 0.5);
    glVertex3f(-10, -10, 0);
    glVertex3f(-10, -12, 0);

    glVertex3f(-10, -10, 0);
    glVertex3f(-10, -10, 0.5);
    glVertex3f(-7, -10, 0.5);
    glVertex3f(-7, -10, 0);

    glColor3f(1,1,1);
    float i;
    for(i=0; i<=2; i++){
        glVertex3f(-9.6+i, -12, 0.5);
        glVertex3f(-9.6+i, -10, 0.5);
        glVertex3f(-9.4+i, -10, 0.5);
        glVertex3f(-9.4+i, -12, 0.5);
    }

    glVertex3f(-10, -11.10, 0.5);
    glVertex3f(-10, -10.90, 0.5);
    glVertex3f(-7, -10.90, 0.5);
    glVertex3f(-7, -11.10, 0.5);
}
void sofa(){
    glColor3f(0,1,0);
    glVertex3f(-15, -12, 10);
    glVertex3f(-15, -11, 10);
    glVertex3f(-12, -11, 10);
    glVertex3f(-12, -12, 10);

    glVertex3f(-15, -11, 10);
    glVertex3f(-15, -11, 9.75);
    glVertex3f(-12, -11, 9.75);
    glVertex3f(-12, -11, 10);

    glVertex3f(-15, -11, 10);
    glVertex3f(-15, -12, 10);
    glVertex3f(-15, -12, 9.75);
    glVertex3f(-15, -11, 9.75);

    glVertex3f(-12, -11, 10);
    glVertex3f(-12, -12, 10);
    glVertex3f(-12, -12, 9.75);
    glVertex3f(-12, -11, 9.75);

    glVertex3f(-15, -12, 9.75);
    glVertex3f(-15, -11.5, 9.75);
    glVertex3f(-15, -11.5, 9);
    glVertex3f(-15, -12, 9);

    glVertex3f(-12, -12, 9.75);
    glVertex3f(-12, -11.5, 9.75);
    glVertex3f(-12, -11.5, 9);
    glVertex3f(-12, -12, 9);

    glVertex3f(-15, -12, 9.75);
    glVertex3f(-15, -11, 9.75);
    glVertex3f(-12, -11, 9.75);
    glVertex3f(-12, -12, 9.75);

    glVertex3f(-15, -12, 9);
    glVertex3f(-15, -11.5, 9);
    glVertex3f(-12, -11.5, 9);
    glVertex3f(-12, -12, 9);

    glVertex3f(-15, -11.5, 9.75);
    glVertex3f(-15, -11.5, 9);
    glVertex3f(-12, -11.5, 9);
    glVertex3f(-12, -11.5, 9.75);
}
void meja(){
    glColor3f(1,1,0);
    glVertex3f(-15, -11.5, 8);
    glVertex3f(-15, -11.5, 7);
    glVertex3f(-12, -11.5, 7);
    glVertex3f(-12, -11.5, 8);

    glVertex3f(-15, -11.4, 8);
    glVertex3f(-15, -11.4, 7);
    glVertex3f(-12, -11.4, 7);
    glVertex3f(-12, -11.4, 8);

    glVertex3f(-15, -11.4, 8);
    glVertex3f(-12, -11.4, 8);
    glVertex3f(-12, -11.5, 8);
    glVertex3f(-15, -11.5, 8);

    glVertex3f(-15, -11.4, 7);
    glVertex3f(-12, -11.4, 7);
    glVertex3f(-12, -11.5, 7);
    glVertex3f(-15, -11.5, 7);

    glVertex3f(-12, -11.4, 8);
    glVertex3f(-12, -12, 8);
    glVertex3f(-12, -12, 7);
    glVertex3f(-12, -11.4, 7);

    glVertex3f(-12.1, -11.4, 8);
    glVertex3f(-12.1, -12, 8);
    glVertex3f(-12.1, -12, 7);
    glVertex3f(-12.1, -11.4, 7);

    glVertex3f(-12, -11.4, 8);
    glVertex3f(-12, -12, 8);
    glVertex3f(-12.1, -12, 8);
    glVertex3f(-12.1, -11.4, 8);

    glVertex3f(-12, -11.4, 7);
    glVertex3f(-12, -12, 7);
    glVertex3f(-12.1, -12, 7);
    glVertex3f(-12.1, -11.4, 7);

    glVertex3f(-15, -11.4, 8);
    glVertex3f(-15, -12, 8);
    glVertex3f(-15, -12, 7);
    glVertex3f(-15, -11.4, 7);

    glVertex3f(-14.9, -11.4, 8);
    glVertex3f(-14.9, -12, 8);
    glVertex3f(-14.9, -12, 7);
    glVertex3f(-14.9, -11.4, 7);

    glVertex3f(-15, -11.4, 8);
    glVertex3f(-15, -12, 8);
    glVertex3f(-14.9, -12, 8);
    glVertex3f(-14.9, -11.4, 8);

    glVertex3f(-15, -11.4, 7);
    glVertex3f(-15, -12, 7);
    glVertex3f(-14.9, -12, 7);
    glVertex3f(-14.9, -11.4, 7);
}
void TV(){
    glColor3f(0,0,0);
    glVertex3f(-14, -11.2, 7.45);
    glVertex3f(-14, -10.5, 7.45);
    glVertex3f(-13, -10.5, 7.45);
    glVertex3f(-13, -11.2, 7.45);

    glVertex3f(-14, -11.2, 7.55);
    glVertex3f(-14, -10.5, 7.55);
    glVertex3f(-13, -10.5, 7.55);
    glVertex3f(-13, -11.2, 7.55);

    glVertex3f(-14, -11.2, 7.55);
    glVertex3f(-14, -11.2, 7.45);
    glVertex3f(-13, -11.2, 7.45);
    glVertex3f(-13, -11.2, 7.55);

    glVertex3f(-14, -10.5, 7.55);
    glVertex3f(-14, -10.5, 7.45);
    glVertex3f(-13, -10.5, 7.45);
    glVertex3f(-13, -10.5, 7.55);

    glVertex3f(-14, -11.2, 7.55);
    glVertex3f(-14, -10.5, 7.55);
    glVertex3f(-14, -10.5, 7.45);
    glVertex3f(-14, -11.2, 7.45);

    glVertex3f(-13, -11.2, 7.55);
    glVertex3f(-13, -10.5, 7.55);
    glVertex3f(-13, -10.5, 7.45);
    glVertex3f(-13, -11.2, 7.45);

    //gagang TV
    glVertex3f(-13.55, -11.4, 7.55);
    glVertex3f(-13.55, -10.5, 7.55);
    glVertex3f(-13.45, -10.5, 7.55);
    glVertex3f(-13.45, -11.4, 7.55);

    glVertex3f(-13.55, -11.4, 7.45);
    glVertex3f(-13.55, -10.5, 7.45);
    glVertex3f(-13.45, -10.5, 7.45);
    glVertex3f(-13.45, -11.4, 7.45);

    glVertex3f(-13.55, -11.4, 7.45);
    glVertex3f(-13.55, -10.5, 7.45);
    glVertex3f(-13.55, -10.5, 7.55);
    glVertex3f(-13.55, -11.4, 7.55);

    glVertex3f(-13.45, -11.4, 7.45);
    glVertex3f(-13.45, -10.5, 7.45);
    glVertex3f(-13.45, -10.5, 7.55);
    glVertex3f(-13.45, -11.4, 7.55);
}
void kabah_tengah(){
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex3f(0,8,8);
    glVertex3f(-0.6,7.3,8);
    glVertex3f(-1.5,6.5,8);
    glVertex3f(-2,6,8);
    glVertex3f(-2.6,5.2,8);
    glVertex3f(-3.4,4.3,8);
    glVertex3f(-3.9,3.6,8);
    glVertex3f(-4.5,2.4,8);
    glVertex3f(-5.1,1.1,8);
    glVertex3f(-5.1,-0.4,8);
    glVertex3f(-4.7,-0.6,8);
    glVertex3f(-4.3,-1.5,8);
    glVertex3f(-3.6,-2.2,8);
    glVertex3f(-4,-3.3,8);
    glVertex3f(-4.4,-3.9,8);
    glVertex3f(-4.8,-5.6,8);
    glVertex3f(-4.8,-12,8);
    glVertex3f(0,-12,8);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex3f(0,8,8);
    glVertex3f(0.6,7.3,8);
    glVertex3f(1.5,6.5,8);
    glVertex3f(2,6,8);
    glVertex3f(2.6,5.2,8);
    glVertex3f(3.4,4.3,8);
    glVertex3f(3.9,3.6,8);
    glVertex3f(4.5,2.4,8);
    glVertex3f(5.1,1.1,8);
    glVertex3f(5.1,-0.4,8);
    glVertex3f(4.7,-0.6,8);
    glVertex3f(4.3,-1.5,8);
    glVertex3f(3.6,-2.2,8);
    glVertex3f(4,-3.3,8);
    glVertex3f(4.4,-3.9,8);
    glVertex3f(4.8,-5.6,8);
    glVertex3f(4.8,-12,8);
    glVertex3f(0,-12,8);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1,1,0);
    glVertex3f(-6,9,7.9);
    glVertex3f(6,9,7.9);
    glVertex3f(6,-12,7.9);
    glVertex3f(-6,-12,7.9);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex3f(0,8,2);
    glVertex3f(-0.6,7.3,1.9);
    glVertex3f(-1.5,6.5,1.9);
    glVertex3f(-2,6,1.9);
    glVertex3f(-2.6,5.2,1.9);
    glVertex3f(-3.4,4.3,1.9);
    glVertex3f(-3.9,3.6,1.9);
    glVertex3f(-4.5,2.4,1.9);
    glVertex3f(-5.1,1.1,1.9);
    glVertex3f(-5.1,-0.4,1.9);
    glVertex3f(-4.7,-0.6,1.9);
    glVertex3f(-4.3,-1.5,1.9);
    glVertex3f(-3.6,-2.2,1.9);
    glVertex3f(-4,-3.3,1.9);
    glVertex3f(-4.4,-3.9,1.9);
    glVertex3f(-4.8,-5.6,1.9);
    glVertex3f(-4.8,-12,1.9);
    glVertex3f(0,-12,1.9);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0,0,0);
    glVertex3f(0,8,1.9);
    glVertex3f(0.6,7.3,1.9);
    glVertex3f(1.5,6.5,1.9);
    glVertex3f(2,6,1.9);
    glVertex3f(2.6,5.2,1.9);
    glVertex3f(3.4,4.3,1.9);
    glVertex3f(3.9,3.6,1.9);
    glVertex3f(4.5,2.4,1.9);
    glVertex3f(5.1,1.1,1.9);
    glVertex3f(5.1,-0.4,1.9);
    glVertex3f(4.7,-0.6,1.9);
    glVertex3f(4.3,-1.5,1.9);
    glVertex3f(3.6,-2.2,1.9);
    glVertex3f(4,-3.3,1.9);
    glVertex3f(4.4,-3.9,1.9);
    glVertex3f(4.8,-5.6,1.9);
    glVertex3f(4.8,-12,1.9);
    glVertex3f(0,-12,1.9);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1,1,0);
    glVertex3f(-6,9,2);
    glVertex3f(6,9,2);
    glVertex3f(6,-12,2);
    glVertex3f(-6,-12,2);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1,1,0);
    glVertex3f(-6,9,8);
    glVertex3f(6,9,8);
    glVertex3f(6,9,2);
    glVertex3f(-6,9,2);
    glEnd();
}
void AC(){
    glColor3f(1,1,1);
    glVertex3f(-12.5, -10, 0);
    glVertex3f(-12.5, -9.5, 0);
    glVertex3f(-11, -9.5, 0);
    glVertex3f(-11, -10, 0);

    glVertex3f(-12.5, -10, 0.3);
    glVertex3f(-12.5, -9.5, 0.5);
    glVertex3f(-11, -9.5, 0.5);
    glVertex3f(-11, -10, 0.3);

    glVertex3f(-12.5, -9.5, 0.5);
    glVertex3f(-11, -9.5, 0.5);
    glVertex3f(-11, -9.5, 0);
    glVertex3f(-12.5, -9.5, 0);

    glVertex3f(-12.5, -10, 0.3);
    glVertex3f(-11, -10, 0.3);
    glVertex3f(-11, -10, 0);
    glVertex3f(-12.5, -10, 0);

    glVertex3f(-11, -10, 0);
    glVertex3f(-11, -9.5, 0);
    glVertex3f(-11, -9.5, 0.5);
    glVertex3f(-11, -10, 0.3);

    glVertex3f(-12.5, -10, 0);
    glVertex3f(-12.5, -9.5, 0);
    glVertex3f(-12.5, -9.5, 0.5);
    glVertex3f(-12.5, -10, 0.3);

    glColor3f(0,0,0);
    glVertex3f(-11.2, -9.6, 0.47);
    glVertex3f(-11.2, -9.66, 0.45);
    glVertex3f(-12.3, -9.66, 0.45);
    glVertex3f(-12.3, -9.6, 0.47);

    glVertex3f(-11.2, -9.7, 0.42);
    glVertex3f(-11.2, -9.76, 0.40);
    glVertex3f(-12.3, -9.76, 0.40);
    glVertex3f(-12.3, -9.7, 0.42);

    glVertex3f(-11.2, -9.8, 0.39);
    glVertex3f(-11.2, -9.86, 0.37);
    glVertex3f(-12.3, -9.86, 0.37);
    glVertex3f(-12.3, -9.8, 0.39);
}
void kotak_depan2_cabang(){
    glColor3f(1,0,0);
    glVertex3f(28, 3, 0);
    glVertex3f(28, -12, 0);
    glVertex3f(28, -12, 10);
    glVertex3f(28, 3, 10);

    glVertex3f(28, 3, 0);
    glVertex3f(28, -12, 0);
    glVertex3f(22, -12, 0);
    glVertex3f(22, 3, 0);

    glVertex3f(28, 3, 10);
    glVertex3f(28, -12, 10);
    glVertex3f(22, -12, 10);
    glVertex3f(22, 3, 10);

    glVertex3f(28, 3, 0);
    glVertex3f(28, 3, 10);
    glVertex3f(23, 3, 10);
    glVertex3f(23, 3, 0);
}
void pilar_nyabang2_mario(){

    glColor3f(1,1,0);
    glVertex3f(21.5,8,10);
    glVertex3f(25,8,12);
    glVertex3f(25,-12,12);
    glVertex3f(21.5,-12,10);

    glVertex3f(23,8,5.5);
    glVertex3f(26.5,8,7.5);
    glVertex3f(26.5,-12,7.5);
    glVertex3f(23,-12,5);

    glVertex3f(26.5,8,7.5);
    glVertex3f(26.5,-12,7.5);
    glVertex3f(25,-12,12);
    glVertex3f(25,8,12);

    glVertex3f(22,8,10);
    glVertex3f(22,-12,10);
    glVertex3f(23,-12,6);
    glVertex3f(23,8,6);

    glVertex3f(21.5,8,10);
    glVertex3f(25,8,12);
    glVertex3f(26.5,8,7.5);
    glVertex3f(23,8,5.5);

    //pilar 2 nyabang kiri
    glColor3f(0,1,0);
    glVertex3f(23,8,5.5);
    glVertex3f(26.5,8,3.5);
    glVertex3f(26.5,-12,3.5);
    glVertex3f(23,-12,5);

    glVertex3f(21.5,8,0);
    glVertex3f(25,8,-2);
    glVertex3f(25,-12,-2);
    glVertex3f(21.5,-12,0);

    glVertex3f(26.5,8,3.5);
    glVertex3f(26.5,-12,3.5);
    glVertex3f(25,-12,-2);
    glVertex3f(25,8,-2);

    glVertex3f(22,8,0);
    glVertex3f(22,-12,0);
    glVertex3f(23,-12,5);
    glVertex3f(23,8,5);

    glVertex3f(21.5,8,0);
    glVertex3f(25,8,-2);
    glVertex3f(26.5,8,3.5);
    glVertex3f(23,8,5.5);
}
void tanah(){
    glColor3f(1,1,1);
    glVertex3f(55,-12.1,55);
    glVertex3f(-55,-12.1,55);
    glVertex3f(-55,-12.1,-55);
    glVertex3f(55,-12.1,-55);
}
void tampil(void){
glPushMatrix();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
    gluLookAt(0.0, 0.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glRotatef(xrot,1,0,0);
	glRotatef(yrot,0,1,0);
	glScalef(1.5, 1.5, 1.0);

    glBegin(GL_LINES);
        glColor3f(0,0,0);
        glVertex3f(-21.5,8,10);
        glVertex3f(-21.5,-12,10);

    glEnd();

    glBegin(GL_QUADS);
    jendela();
    glColor3ub(237, 194, 183);
    //depan kiri
    glVertex3f(-6,12,10);
    glVertex3f(-11,12,10);
    glVertex3f(-11,-12,10);
    glVertex3f(-6,-12,10);

    glVertex3f(-11,8,10);
    glVertex3f(-23,8,10);
    glVertex3f(-23,-12,10);
    glVertex3f(-11,-12,10);

    glColor3ub(255, 255, 183);
    glVertex3f(-11,8,0);
    glVertex3f(-11,8,10);
    glVertex3f(-11,12,10);
    glVertex3f(-11,12,0);

    glVertex3f(-23,8,0);
    glVertex3f(-23,8,10);
    glVertex3f(-23,-12,10);
    glVertex3f(-23,-12,0);

    glVertex3f(-6,12,0);
    glVertex3f(-6,12,10);
    glVertex3f(-6,-12,10);
    glVertex3f(-6,-12,0);

    glVertex3f(-6,12,10);
    glVertex3f(-11,12,10);
    glVertex3f(-11,12,0);
    glVertex3f(-6,12,0);

    //belakang kiri
    glColor3ub(237, 194, 183);
    glVertex3f(-6,12,0);
    glVertex3f(-11,12,0);
    glVertex3f(-11,-12,0);
    glVertex3f(-6,-12,0);

    glVertex3f(-11,8,0);
    glVertex3f(-23,8,0);
    glVertex3f(-23,-12,0);
    glVertex3f(-11,-12,0);

    glColor3ub(255, 255, 183);
    glVertex3f(11,8,0);
    glVertex3f(11,8,10);
    glVertex3f(11,12,10);
    glVertex3f(11,12,0);

    glVertex3f(23,8,0);
    glVertex3f(23,8,10);
    glVertex3f(23,-12,10);
    glVertex3f(23,-12,0);

    glVertex3f(6,12,0);
    glVertex3f(6,12,10);
    glVertex3f(6,-12,10);
    glVertex3f(6,-12,0);

    glVertex3f(6,12,10);
    glVertex3f(11,12,10);
    glVertex3f(11,12,0);
    glVertex3f(6,12,0);

    //bawah kiri
    glColor3ub(237, 194, 183);
    glVertex3f(-6,-12,0);
    glVertex3f(-23,-12,0);
    glVertex3f(-23,-12,10);
    glVertex3f(-6,-12,10);

    //depan kanan
    glVertex3f(6,12,10);
    glVertex3f(11,12,10);
    glVertex3f(11,-12,10);
    glVertex3f(6,-12,10);

    glVertex3f(11,8,10);
    glVertex3f(23,8,10);
    glVertex3f(23,-12,10);
    glVertex3f(11,-12,10);

    //belakang kanan
    glVertex3f(6,12,0);
    glVertex3f(11,12,0);
    glVertex3f(11,-12,0);
    glVertex3f(6,-12,0);

    glVertex3f(11,8,0);
    glVertex3f(23,8,0);
    glVertex3f(23,-12,0);
    glVertex3f(11,-12,0);

    glVertex3f(11,8,0);
    glVertex3f(11,8,0);
    glVertex3f(11,12,0);
    glVertex3f(11,12,0);

    //bawah kanan
    glVertex3f(6,-12,0);
    glVertex3f(23,-12,0);
    glVertex3f(23,-12,10);
    glVertex3f(6,-12,10);

    pilar_nyabang_mario();
    kotak_depan_cabang();
    dua_kali_cabang();
    kotak_depan2_cabang();
    pilar_nyabang2_mario();
    dua_kali_cabang2();
    cabang_akhir_kanan();
    cabang_akhir_kiri();
    rak_kunci();
    meja_resepsionis();
    sofa();
    AC();
    meja();
    TV();
    tanah();
    glEnd();
    kabah_tengah();



    glPopMatrix();
    glutSwapBuffers();
}




void ukuran(int lebar,int tinggi)
{
    if (tinggi==0)tinggi=1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, lebar/tinggi,5.0,500.0);
    glTranslatef(0.0,-5.0,-150.0);
    glMatrixMode(GL_MODELVIEW);
}

