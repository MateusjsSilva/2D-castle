/*
 * Computacao Grafica
 * Codigo Exemplo: Desenhar um castelo 2D
 * Autor: Prof. Laurindo de Sousa Britto Neto
 * Mofificado por: Mateus Silva
 */

#include "Config.h"
#include "Circle.h"
#include "Square.h"
#include "Triangle.h"
#include "Line.h"

// Global variables for defining colors
float R, G, B;

// Function prototypes for OpenGL callbacks
void init(void);
void reshape(int w, int h);
void keyboard(unsigned char key, int x, int y);
void keyboard_special(int key, int x, int y);
void display(void);

/*
 *
 * Main function
 * 
 */
int main(int argc, char** argv) 
{

    glutInit(&argc, argv); // Passagens de parametros C para o glut
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Selecao do Modo do Display e do Sistema de cor utilizado
    glutInitWindowSize(800, 600);  // Tamanho da janela do OpenGL
    glutInitWindowPosition(100, 100); //Posicao inicial da janela do OpenGL
    glutCreateWindow("2D Castle"); // Da nome para uma janela OpenGL

    init(); // Chama a funcao init();

    glutReshapeFunc(reshape); //funcao callback para redesenhar a tela
    glutDisplayFunc(display); //funcao callback de desenho
    glutKeyboardFunc(keyboard); //funcao callback do teclado
    glutSpecialFunc(keyboard_special);	//funcao callback do teclado especial
    glutMainLoop(); // executa o loop do OpenGL

    return EXIT_SUCCESS; // retorna 0 para o tipo inteiro da funcao main()
}


/*
 * 
 * Initialize OpenGL parameters
 * 
 */
void init(void) 
{
    glClearColor(1.0, 1.0, 1.0, 1.0); // Clear screen with white color
    R = 0.0;
    G = 0.0;
    B = 0.0;
}


/*
 * 
 * Ajusta a projecao para o redesenho da janela
 *
 */
void reshape(int w, int h)
{
    glViewport(0, 0, w, h); // Definindo o Viewport para o tamanho da janela

    // Reinicializa o sistema de coordenadas
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(0, w, 0, h, -1, 1); 
    // Nesse caso, ficamos com a quantidade de pixels variavel,
    // dependente da largura e altura da janela, e o
    // centro dos eixos continua a se localizar no centro
    // da tela.

    // muda para o modo GL_MODELVIEW (nao pretendemos alterar a projecao
    // quando estivermos desenhando na tela)
    glMatrixMode(GL_MODELVIEW);

}


/*
 *
 * Funcao usada na funcao callback para controlar as teclas comuns (1 Byte) do teclado
 * Recebe um valor (Key) em ASCII da tecla precionada, e caso seja ESC encerra o programa com sucesso
 * 
 */
void keyboard(unsigned char key, int x, int y) 
{

    switch (key) {
        case ESC: exit(EXIT_SUCCESS); 
            break;
    }
}


/*
 * 
 * Funcao usada na funcao callback para controlar as teclas especiais (2 Byte) do teclado
 * 
 */
void keyboard_special(int key, int x, int y) 
{

    switch (key) {
        case GLUT_KEY_F1: R = 0.0; G = 0.0; B = 1.0; // F1: muda a cor para azul
            break;
        case GLUT_KEY_F2: R = 0.0; G = 1.0; B = 0.0; // F2: muda a cor para verde
            break; 
        case GLUT_KEY_F3: R = 1.0; G = 0.0; B = 0.0; // F3: muda a cor para vermelho
            break; 
        default: 
            break;
    }
    glutPostRedisplay();
}


/*
 *
 * Funcao usada na funcao callback para desenhar na tela
 *
 */
void display(void)
{
    // Clear the color buffer
    glClear(GL_COLOR_BUFFER_BIT);

    // Set the projection mode to 2D
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 31, 0, 22);

    /*** Start Left tower ***/

        drawSquare(6, 10, 0, 8, 255, 142, 0); // retangle left tower

        /* Start small rectangle tower */
        drawSquare(6.2, 8, 1, 1.8, 255, 255, 0);
        drawSquare(8, 9.8, 2.3, 3, 255, 255, 0);
        drawSquare(6.2, 8, 3.5, 4.2, 255, 255, 0);
        /* End small rectangle tower */

        drawTriangle(4.8, 8, 8, 11, 11.2, 8, 255, 0, 0); // Draws the left tower triangle

        drawSquare(5, 8, 12, 14, 0, 255, 0); // left flag rectangle

        drawLine(8, 10.9, 8, 14, 0, 0, 0, 2); // left flag line

        glTranslatef(8, 6, 0);
        glColor3f(0, 1, 1);
        drawCircle(1, 50, true);
        glTranslatef(-8, -6, 0);

    /*** End Left tower ***/

    /*** Start Center tower ***/

        drawSquare(10, 21, 0, 6, 255, 255, 0); // center rectangle bottom

        drawSquare(13.5, 17.5, 6, 9, 255, 142, 0); // center rectangle upper (tower)

        drawTriangle(12.3, 9, 15.5, 12, 18.7, 9, 255, 0, 0); // center triangle

        drawSquare(12.5, 15.5, 13, 15, 0, 255, 0); // center flag rectangle

        drawLine(15.5, 11.9, 15.5, 15, 0, 0, 0, 2); // center flag line

        /* Start small rectangle tower */
        drawSquare(11, 13, 1, 1.7, 255, 142, 0);
        drawSquare(18, 20, 1, 1.7, 255, 142, 0);
        drawSquare(12, 14, 4.5, 5.2, 255, 142, 0);
        drawSquare(17, 19, 4.5, 5.2, 255, 142, 0);
        /* End small rectangle tower */

        drawSquare(13.5, 17.5, 0, 4, 0, 0, 0); // door

        // Draw the circles
        glTranslatef(15.5, 1.5, 0);
        glColor3f(1, 1, 0);
        drawCircle(0.5, 30, true); // circle 1
        glTranslatef(-15.5, -1.5, 0);

        glTranslatef(15.5, 1.5, 0);
        glColor3f(0, 0, 0);
        drawCircle(0.35, 30, true); // circle 2
        glTranslatef(-15.5, -1.5, 0);

        glTranslatef(15.5, 1.9, 0);
        glColor3f(1, 1, 0);
        drawCircle(0.23, 30, true); // circle 3
        glTranslatef(-15.5, -1.9, 0);

        glTranslatef(15.5, 7.5, 0);
        glColor3f(0, 1, 1);
        drawCircle(1, 30, true); // circle 4
        glTranslatef(-15.5, -7.5, 0);

    /*** End Center tower ***/

    /*** Start Right tower ***/

        drawSquare(21, 25, 0, 8, 255, 142, 0); // rectangle right tower

        /* Start small rectangle tower */
        drawSquare(23, 24.8, 1, 1.8, 255, 255, 0);
        drawSquare(21.2, 23, 2.3, 3, 255, 255, 0);
        drawSquare(23, 24.8, 3.5, 4.2, 255, 255, 0);
        /* End small rectangle tower */

        drawTriangle(19.8, 8, 23, 11, 26.2, 8, 255, 0, 0); // Draws the right tower triangle

        drawSquare(23, 26, 12, 14, 0, 255, 0); // right flag rectangle

        drawLine(23, 10.9, 23, 14, 0, 0, 0, 2); // right flag line

        glTranslatef(23, 6, 0);
        glColor3f(0, 1, 1);
        drawCircle(1, 50, true);
        glTranslatef(-23, -6, 0);

     /*** End Right tower ***/
     
     glFlush(); // Render the primitives
}