#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
GLUquadricObj *qobj;
float angle = 0.0f;
//static int giro = 0;

void SetupRC(void){
    
    
    GLfloat diffuseLight[] = {0.8, 0.8, 0.8, 1.0};
    //GLfloat especular[] = {1.0, 0.0, 0.0};
    
    glEnable(GL_DEPTH_TEST);
    
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    //glEnable(GL_LIGHT1);
    
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
    //glLightfv(GL_LIGHT1, GL_SPECULAR, especular);
    
    
    glEnable(GL_COLOR_MATERIAL);
    
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glClearColor(0.078, 0.31, 0.47, 1.0);
}

void Render(void){
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glPushMatrix();
    glTranslatef(0.0, -5.0, -25.0);
    glRotatef(angle, 0.0, 1.0, 0.0);
    
    glPushMatrix();
    glColor3f(0.49, 0.72, 0.89);
    glTranslatef(0.0, -5.0, 0.0);
    glScalef(3.0, 0.05, 3.0);
    glutSolidCube(8.0);     //Plano
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-270.0, -100.0, -200.0);
    glPointSize(1.5);
    
    glBegin(GL_POINTS);
    GLint i;
    
    for(i=0; i<1500; i++){
        GLint x = rand()%750;
        GLint y = rand()%750;
        GLint z = rand()%750;
        glColor3f(1.0, 1.0, 1.0);
        glVertex3f(x, y, z);    // La nieve
    }
    
    glEnd();
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(0.75, 0.89, 0.98);
    glTranslatef(0.0, -1.0, 0.0);
    glutSolidSphere(4.0, 25.0, 25.0);   // primera esfera
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(0.75, 0.89, 0.98);
    glTranslatef(0.0, 4.5, 0.0);
    glutSolidSphere(2.5, 25.0, 25.0);   // segunda esfera
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(-0.8, 5.0, 2.3);
    glutSolidSphere(0.35, 25.0, 25.0);   // ojo_1 esfera
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(0.0, 0.0, 0.0);
    glTranslatef(0.8, 5.0, 2.3);
    glutSolidSphere(0.35, 25.0, 25.0);   // ojo_2 esfera
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(1.0, 0.51, 0.0);
    qobj = gluNewQuadric();
    glTranslatef(0.0, 4.2, 2.0);
    glutSolidCone(0.5, 1.5, 10, 10);   //Nariz
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(0.75, 0.89, 0.98);
    glTranslatef(-8.50, -2.0, 5.0);
    glutSolidSphere(2.5, 25.0, 25.0);   // segunda esfera
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(0.75, 0.89, 0.98);
    glTranslatef(8.50, -3.4, -1.5);
    glutSolidSphere(1.5, 25.0, 25.0);   // segunda esfera
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(0.2, 0.2, 0.2);
    qobj = gluNewQuadric();
    glTranslatef(0.0, 8.0, 0.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    gluCylinder(qobj, 1.0, 1.0, 1.5, 15, 15);   //Sombrero
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(0.2, 0.2, 0.2);
    qobj = gluNewQuadric();
    glTranslatef(0.0, 6.8, 0.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    gluDisk(qobj, 0.0, 2.0, 20.0, 20.0);   //Base_sombrero
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(0.7, 0.0, 0.1);
    qobj = gluNewQuadric();
    glTranslatef(0.0, 3.0, 0.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    gluCylinder(qobj, 2.5, 2.5, 1.5, 15, 15);   //Sombrero
    glPopMatrix();
    
    //================================== Pino
    
    glPushMatrix();
    glColor3f(0.37, 0.18, 0.0);
    qobj = gluNewQuadric();
    glTranslatef(-7.0, -2.0, -7.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    gluCylinder(qobj, 1.0, 1.0, 2.5, 15, 15);   //Tronco
    glPopMatrix();
    
    glPushMatrix();
    glColor3f(0.0, 0.43, 0.08);
    qobj = gluNewQuadric();
    glTranslatef(-7.0, -2.2, -7.0);
    glRotatef(-90, 1.0, 0.0, 0.0);
    glutSolidCone(4.0, 15.5, 15, 15);   //Arbusto
    glPopMatrix();
    glPopMatrix();
    
    glutSwapBuffers();
}
void update(int value){
    angle += 1.0;
    if(angle > 360)
        angle = 0.0f;
    glutPostRedisplay();
    glutTimerFunc(25, update, 0);
}

void ChangeSize(GLsizei w, GLsizei h){
    
    GLfloat aspectRatio;
    if(h==0)
        h=1;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    aspectRatio = (GLfloat)w/(GLfloat)h;
    gluPerspective(60.0, aspectRatio, 1.0, 400.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv){
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(850, 650);
    glutCreateWindow("Proyecto de Nieve");
    glutDisplayFunc(Render);
    glutReshapeFunc(ChangeSize);
    SetupRC();
    
    glutTimerFunc(25, update, 0);
    glutMainLoop();
    return 0;
}