#pragma once

/*
 * Computacao Grafica
 * Codigo Exemplo: Biblioteca com funcao para desenhar um triangulo em OpenGL
 * Autor: Mateus Silva
 */

#include "Config.h"

#ifndef triangle_h
    #define triangle_h

     /*
      * Function to draw a triangle
      * Parameters:
      *   - x1, y1: The coordinates of the first vertex of the triangle.
      *   - x2, y2: The coordinates of the second vertex of the triangle.
      *   - x3, y3: The coordinates of the third vertex of the triangle.
      *   - colorR, colorG, colorB: The RGB color components of the triangle
      */
    void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3, float colorR, float colorG, float colorB)
    {
        //Converting RGB values ??from 0-255 to the range 0.0 to 1.0
        colorR /= 255.0;
        colorG /= 255.0;
        colorB /= 255.0;

        // Set the color of the triangle
        glColor3f(colorR, colorG, colorB);

        // Draw the triangle
        glBegin(GL_TRIANGLES);
        glVertex2f(x1, y1); // First vertex
        glVertex2f(x2, y2); // Second vertex
        glVertex2f(x3, y3); // Third vertex
        glEnd();
    }

#endif