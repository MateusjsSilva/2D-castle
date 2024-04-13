#pragma once

/*
 * Computacao Grafica
 * Codigo Exemplo: Biblioteca com funcao para desenhar um circulo em OpenGL
 * Autor: Mateus Silva
 */

#include "Config.h"

#ifndef line_h
    #define line_h

     /*
      * Function to draw a line
      * Parameters:
      *   - x1, y1: Coordinates of the start point of the line.
      *   - x2, y2: Coordinates of the end point of the line.
      *   - colorR, colorG, colorB: RGB color components of the line (0.0 to 1.0).
      */
    void drawLine(float x1, float y1, float x2, float y2, float colorR, float colorG, float colorB) {
        // Set the color of the line
        glColor3f(colorR, colorG, colorB);

        // Draw the line
        glBegin(GL_LINES);
        glVertex2f(x1, y1); // Start point
        glVertex2f(x2, y2); // End point
        glEnd();
    }

#endif