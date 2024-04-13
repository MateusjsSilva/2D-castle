#pragma once

/*
 * Computacao Grafica
 * Codigo Exemplo: Biblioteca com funcao para desenhar um quadrado em OpenGL
 * Autor: Mateus Silva
 */

#include "Config.h"

#ifndef square_h
    #define square_h

    /* Function to draw a square
     * Parameters:
     *   - x1, y1: The coordinates of the bottom-left vertex of the square.
     *   - x2, y2: The coordinates of the top-right vertex of the square.
     *   - colorR, colorG, colorB: The RGB color components of the square (0.0 to 1.0).
     */
    void drawSquare(float x1, float x2, float y1, float y2, float colorR, float colorG, float colorB)
    {
        // Set the color of the square
        glColor3f(colorR, colorG, colorB);

        // Draw the square
        glBegin(GL_QUADS);
        glVertex2f(x1, y1); // Bottom left vertex
        glVertex2f(x2, y1); // Bottom right vertex
        glVertex2f(x2, y2); // Top right vertex
        glVertex2f(x1, y2); // Top left vertex
        glEnd();
    }
#endif