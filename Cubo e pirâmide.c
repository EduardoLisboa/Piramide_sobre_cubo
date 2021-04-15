#include <GL/gl.h>
#include <GL/glut.h>

float rotate_x = 20;
float rotate_y = -20; 

void display()
{
    // Limpa a tela e o Z-Buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Reinicia transformações
    glLoadIdentity();

    glTranslatef(0.0f, -0.2f, 0.0f);
    glRotatef( rotate_x, 1.0, 0.0, 0.0 );
    glRotatef( rotate_y, 0.0, 1.0, 0.0 );

    /* ---------------------------------------------------------------- */
    /* ----------------------------- CUBO ----------------------------- */
    /* ---------------------------------------------------------------- */
    // FRENTE - Branco
    glBegin(GL_LINE_LOOP);
    glColor3f(   1.0,  1.0, 1.0 );
    glVertex3f(  0.5, -0.5, 0.5 ); // Inferior direito
    glVertex3f(  0.5,  0.5, 0.5 ); // Superior direito
    glVertex3f( -0.5,  0.5, 0.5 ); // Superior esquerdo
    glVertex3f( -0.5, -0.5, 0.5 ); // Inferior esquerdo
    glEnd();
    
    // TRASEIRA - Amarelo
    glBegin(GL_LINE_LOOP);
    glColor3f( 1.0, 1.0, 0.0 );
    glVertex3f(  0.5, -0.5, -0.5 ); // Inferior direito
    glVertex3f(  0.5,  0.5, -0.5 ); // Superior direito
    glVertex3f( -0.5,  0.5, -0.5 ); // Superior esquerdo
    glVertex3f( -0.5, -0.5, -0.5 ); // Inferior esquerdo
    glEnd();

    // DIREITA - Vermelho
    glBegin(GL_LINE_LOOP);
    glColor3f(  1.0,  0.0,  0.0 );
    glVertex3f( 0.5, -0.5, -0.5 ); // Inferior direito
    glVertex3f( 0.5,  0.5, -0.5 ); // Superior direito
    glVertex3f( 0.5,  0.5,  0.5 ); // Superior esquerdo
    glVertex3f( 0.5, -0.5,  0.5 ); // Inferior esquerdo
    glEnd();

    // ESQUERDA - Laranja
    glBegin(GL_LINE_LOOP);
    glColor3f(   1.0,  0.5,  0.0 );
    glVertex3f( -0.5, -0.5,  0.5 ); // Inferior direito
    glVertex3f( -0.5,  0.5,  0.5 ); // Superior direito
    glVertex3f( -0.5,  0.5, -0.5 ); // Superior esquerdo
    glVertex3f( -0.5, -0.5, -0.5 ); // Inferior esquerdo
    glEnd();

    /*
    Da forma como essa implementação foi feita,
    essa face abaixo é desnecessária

    // INFERIOR - Verde
    glBegin(GL_LINE_LOOP);
    glColor3f(  0.0,  1.0,  0.0);
    glVertex3f( 0.5, -0.5, -0.5); // Inferior direito
    glVertex3f( 0.5, -0.5,  0.5); // Superior direito
    glVertex3f(-0.5, -0.5,  0.5); // Superior esquerdo
    glVertex3f(-0.5, -0.5, -0.5); // Inferior esquerdo
    glEnd();
    */


    /* ---------------------------------------------------------------- */
    /* --------------------------- PIRÂMIDE --------------------------- */
    /* ---------------------------------------------------------------- */
    /*
    Vista superior da pirâmide
        e ----- d
        | \   / |
        |   a   |
        | /   \ |
        b ----- c
    */
    // Face direita da pirâmide
    glBegin(GL_LINE_LOOP);
    glColor3f(   0.0,  0.0,  1.0 );
    glVertex3f(  0.5,  0.5,  0.5 ); // C
    glVertex3f(  0.5,  0.5, -0.5 ); // D
    glVertex3f(  0.0,  1.0,  0.0 ); // A
    glEnd();

    // Face esquerda da pirâmide
    glBegin(GL_LINE_LOOP);
    glVertex3f( -0.5,  0.5, -0.5 ); // E
    glVertex3f( -0.5,  0.5,  0.5 ); // B
    glVertex3f(  0.0,  1.0,  0.0 ); // A
    glEnd();

    /*
    Da forma como essa implementação foi feita,
    essas duas faces abaixo são desnecessárias

    // Face frontal da pirâmide
    glBegin(GL_LINE_LOOP);
    glVertex3f( 0.5,  0.5,  0.5); // C
    glVertex3f(-0.5,  0.5,  0.5); // B
    glVertex3f( 0.0,  1.0,  0.0); // A
    glEnd();

    // Face traseira da pirâmide
    glBegin(GL_LINE_LOOP);
    glVertex3f( 0.5,  0.5, -0.5); // D
    glVertex3f(-0.5,  0.5, -0.5); // E
    glVertex3f( 0.0,  1.0,  0.0); // A
    glEnd();
    */

    glFlush();
    glutSwapBuffers();
}

void specialKeys(int key, int x, int y)
{
    //  Gira para a direita 5 graus
    if (key == GLUT_KEY_RIGHT)
        rotate_y -= 5;
    //  Gira para a esquerda 5 graus
    else if (key == GLUT_KEY_LEFT)
        rotate_y += 5;
    // Gira para baixo 5 graus
    else if (key == GLUT_KEY_UP)
        rotate_x += 5;
    // Gira para cima 5 graus
    else if (key == GLUT_KEY_DOWN)
        rotate_x -= 5;
    
    //  Requisitar atualização do display
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    //  Inicializa o GLUT e processa os parâmetros do usuário GLUT
    glutInit(&argc, argv);
    
    //  Requisita uma janela com buffer duplo e true color com um Z-buffer
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    
    // Cria a janela do programa
    glutCreateWindow("Casa");

    //  Habilita o teste de profundidade do Z-buffer
    glEnable(GL_DEPTH_TEST);

    // Funções
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys);

    //  Passa o controle dos eventos para o GLUT
    glutMainLoop();

    return 0;
}