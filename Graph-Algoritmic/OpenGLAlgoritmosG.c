#include<time.h>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>

#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define RES 1000.0
#define NMAX 99
#define GENE 5

int apt[NMAX];
int binario[GENE];
static char label[100];

void datosP() {
    int decimal, aptitud, suma = 0;
    int i, j;
    float prom = 0.00;
    
    srand((unsigned)time(0));
    printf("PRACTICA 2\n");
    
    for(i=0; i<=NMAX; i++){                         //imprime los ieros 1-99
        printf("\n%d.  \t", i);                     //para ordenar las poblaciones
        for (int i=GENE-1; i>=0; i--){                  //imprime y llena un arreglo binario aleatorio
            binario[i] = rand()%2;
            printf("%d ", binario[i]);
        }
        
        decimal = 0;
        
        for(j =0; j<GENE; j++){                         //Determinar la posicion
            decimal += binario[j]*pow(j,2);             //convierte binario a decimal
        }
        
        printf("  \tFenotipo=%d ",decimal);
        apt[i] = decimal*decimal;                       //funcion aptitud x^2
        printf("  \tAptitud=%d",apt[i]);
        
        suma += apt[i];                                 //suma total de la aptitud
    }
    
    prom=suma/100.0;
    printf("\nLa suma total es:%d", suma);
    printf("\nEl promedio es: %.2f", prom);
}

void ejes(void) {
    int i=0;
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
    
    //Para X
    glVertex3i(-20, -3, 0);
    glVertex3i(1200, -3, 0);
    
    //Para Y
    glVertex3i(-10, -10, 0);
    glVertex3i(-10, 950, 0);
    
    //Reticula sobre Y
    for(i = 0; i<48; i++) {
     glVertex3i(-15, 20*i, 0);
     glVertex3i(-10, 20*i, 0);
    }
    
    //Reticula sobre X
    for(i = 0; i<99; i++) {
        glVertex3i(10*i -3, -5, 0);
        glVertex3i(10*i -3, -10, 0);
    }
    
    glEnd();
}

void drawString (char *s)
{
    unsigned int i;
    for (i=0; i<NMAX; i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, s[i]);
}

void miNombre() {
    int x = 400;
    int y = 950;
    char *nombre = "Algoritmos Geneticos Practica 2";
    
    glColor3f(1.0, 1.0, 0.0);
    sprintf(label, "%s", nombre);
    glRasterPos2f(x, y);
    drawString(label);
    
}
void textoX() {
    int i;
    int x1 = -5;
    int y1 = -25;
    
    int index = 0;
    glColor3f(1.0, 1.0, 1.0);
    for(i =0; i<NMAX; i++) {
        sprintf(label, "%d", index);
        glRasterPos2f(x1, y1);
        drawString(label);
        index ++;
        x1 += 10;
    }
}

void textoY() {
    int i;
    int x = -30;
    
    glColor3f(1.0, 1.0, 1.0);
    for(i =0; i<NMAX; i++) {
        sprintf(label, "%d", apt[i]);
        glRasterPos2f(x, apt[i]);
        drawString(label);
    }
}

void Render(void){
    
    srand(time(NULL));
    
    int i = 0;
    int space = 0;
    int ancho = 5;
    
    float r,g,b;
    
    glClear(GL_COLOR_BUFFER_BIT);
    ejes();
    textoX();
    textoY();
    miNombre();
    for( i=0; i<NMAX; i++){
        
        //Generamos los colores random
        r = rand()%255 + 1;
        g = rand()%255 + 1;
        b = rand()%255 + 1;
        
        r = r/255.0;
        g = g/255.0;
        b = b/255.0;
        
        glColor3f(r,g,b);
        glRecti((2*i)*ancho, apt[i], (2*i-1)*ancho, 0);
    }
    glFlush();
}

void SetupRC(void){
    glClearColor(0.15, 0.15, 0.15, 1.0);
}
void ChangeSize(GLsizei w, GLsizei h){
    
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-40, RES, -50, RES, -1.0, 1.0);
    //izq, der, abajo, arriba, cerca, lejos
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
}

int main(int argc, char** argv){
    
    datosP();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(10, 10);
    glutInitWindowSize(1600 , 650);
    glutCreateWindow("Algoritmos Practica 1");
    glutDisplayFunc(Render);
    glutReshapeFunc(ChangeSize);
    SetupRC();
    glutMainLoop();
    return 0;
}