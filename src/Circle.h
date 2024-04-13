#pragma once

/*
 * Computacao Grafica
 * Codigo Exemplo: Biblioteca com funcao para desenhar um circulo em OpenGL
 * Autor: Prof. Laurindo de Sousa Britto Neto
 * Mofificado por: Mateus Silva
 */

#include "Config.h"

#ifndef circle_h
    #define circle_h
    
     /*
         Draws a circle using OpenGL with the specified radius, number of line segments,
         and whether to fill the circle or just outline it.
    */
    void drawCircle(float raio, int num_linhas, bool preenchido)
    {
        int i;
        GLfloat angulo;

        angulo = (2 * M_PI) / num_linhas; // divide 360 graus em radianos pela quantidade de linhas que serao desenhadas

        if (preenchido) glBegin(GL_TRIANGLE_FAN);   // Primitiva que liga os vertices, gerando triangulos com o primeiro vertice em comum
        else glBegin(GL_LINE_LOOP);     // Primitiva que liga os vertices, gerando segmentos de reta em um loop

        for (i = 1; i <= num_linhas; i++) // FOR usado para o calculo de cada ponto pertencente aos extremos das retas
        {
            // comando que calcula as coord. da rotacao e desenha as retas na tela
            glVertex2f(-raio * sin(i * angulo), raio * cos(i * angulo));	// centro = (0,0), x = 0 e y = raio;
            //		glVertex2f(raio*cos(i * angulo) , raio*sin(i * angulo));	// centro = (0,0), x = raio e y = 0;
        }
        glEnd();
    }
#endif