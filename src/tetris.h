/**
 * Programarea Calculatoarelor 2011-2012
 * Tema #3 - Joc de Tetris
 *
 * Autor: Ana Nedelcu, 312CC
 *
 */

#ifndef __TETRIS_H__
#define __TETRIS_H__

#include <curses.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


#define NO_KEY_PRESSED (-1)

/**
 * Functia intoarce codul caracterului apasat sau NO_KEY_PRESSED
 * daca niciun caracter nu a fost apasat.
 */
int get_key_pressed(WINDOW *wnd) {
  int ch = wgetch(wnd);
  if (ch != ERR) {
    return ch;
  }
  return NO_KEY_PRESSED;   
}

/** Structura ce retine o pozitie de pe ecran. */
typedef struct Position {
  int row;
  int col;
} Position;

/** Structura ce retine piesele */
typedef struct piese {
  int rot;
  struct Position p[5][4];
} piese;

#endif

