/**
 * Programarea Calculatoarelor 2011-2012
 * Tema #3 - Joc de Tetris
 *
 * Autor: Ana Nedelcu, 312CC
 *
 */

#include <curses.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/time.h>
#include<time.h>
#define cls 16
#define rs 31

#include "tetris.h"

/* Implementarea pieselor */
void imp_piese(struct piese *vp, int rows, int cols) {
  /* Pentru piesa O */
  vp[0].rot=1;
  vp[0].p[0][0].row=0;
  vp[0].p[0][0].col=cols/2+1;
  vp[0].p[0][1].row=0;
  vp[0].p[0][1].col=cols/2;
  vp[0].p[0][2].row=1;
  vp[0].p[0][2].col=cols/2;
  vp[0].p[0][3].row=1;
  vp[0].p[0][3].col=cols/2+1;
  
  /* Pentru piesa I */
  vp[1].rot=2;
  vp[1].p[0][0].row=0;
  vp[1].p[0][0].col=cols/2+1;
  vp[1].p[0][1].row=0;
  vp[1].p[0][1].col=cols/2-1;
  vp[1].p[0][2].row=0;
  vp[1].p[0][2].col=cols/2;
  vp[1].p[0][3].row=0;
  vp[1].p[0][3].col=cols/2+2;
  /* Coordonate relative ale fiecarei pozitii fata de pozitia anterioara */
  vp[1].p[1][0].row=0;
  vp[1].p[1][0].col=0;
  vp[1].p[1][1].row=2;
  vp[1].p[1][1].col=2;
  vp[1].p[1][2].row=1;
  vp[1].p[1][2].col=1;
  vp[1].p[1][3].row=-1;
  vp[1].p[1][3].col=-1;
  
  vp[1].p[2][0].row=0;
  vp[1].p[2][0].col=0;
  vp[1].p[2][1].row=-2;
  vp[1].p[2][1].col=-2;
  vp[1].p[2][2].row=-1;
  vp[1].p[2][2].col=-1;
  vp[1].p[2][3].row=1;
  vp[1].p[2][3].col=1;
  
  /* Pentru piesa S */
  vp[2].rot=2;
  vp[2].p[0][0].row=0;
  vp[2].p[0][0].col=cols/2+1;
  vp[2].p[0][1].row=0;
  vp[2].p[0][1].col=cols/2+2;
  vp[2].p[0][2].row=1;
  vp[2].p[0][2].col=cols/2;
  vp[2].p[0][3].row=1;
  vp[2].p[0][3].col=cols/2+1;
   /* Coordonate relative ale fiecarei pozitii fata de pozitia anterioara */
  vp[2].p[1][0].row=0;
  vp[2].p[1][0].col=0;
  vp[2].p[1][1].row=0;
  vp[2].p[1][1].col=0;
  vp[2].p[1][2].row=-2;
  vp[2].p[1][2].col=1;
  vp[2].p[1][3].row=0;
  vp[2].p[1][3].col=1;
  
  vp[2].p[2][0].row=0;
  vp[2].p[2][0].col=0;
  vp[2].p[2][1].row=0;
  vp[2].p[2][1].col=0;
  vp[2].p[2][2].row=2;
  vp[2].p[2][2].col=-1;
  vp[2].p[2][3].row=0;
  vp[2].p[2][3].col=-1;
  
  /* Pentru piesa Z */
  vp[3].rot=2;
  vp[3].p[0][0].row=0;
  vp[3].p[0][0].col=cols/2+1;
  vp[3].p[0][1].row=1;
  vp[3].p[0][1].col=cols/2+1;
  vp[3].p[0][2].row=0;
  vp[3].p[0][2].col=cols/2;
  vp[3].p[0][3].row=1;
  vp[3].p[0][3].col=cols/2+2;
   /* Coordonate relative ale fiecarei pozitii fata de pozitia anterioara */
  vp[3].p[1][0].row=0;
  vp[3].p[1][0].col=0;
  vp[3].p[1][1].row=0;
  vp[3].p[1][1].col=0;
  vp[3].p[1][2].row=-1;
  vp[3].p[1][2].col=2;
  vp[3].p[1][3].row=-1;
  vp[3].p[1][3].col=0;
  
  vp[3].p[2][0].row=0;
  vp[3].p[2][0].col=0;
  vp[3].p[2][1].row=0;
  vp[3].p[2][1].col=0;
  vp[3].p[2][2].row=1;
  vp[3].p[2][2].col=-2;
  vp[3].p[2][3].row=1;
  vp[3].p[2][3].col=0;
  
  /* Pentru piesa L */
  vp[4].rot=4;
  vp[4].p[0][0].row=0;
  vp[4].p[0][0].col=cols/2+1;
  vp[4].p[0][1].row=0;
  vp[4].p[0][1].col=cols/2;
  vp[4].p[0][2].row=0;
  vp[4].p[0][2].col=cols/2+2;
  vp[4].p[0][3].row=1;
  vp[4].p[0][3].col=cols/2;
  /* Coordonate relative ale fiecarei pozitii fata de pozitia anterioara */
  vp[4].p[1][0].row=0;
  vp[4].p[1][0].col=0;
  vp[4].p[1][1].row=1;
  vp[4].p[1][1].col=1;
  vp[4].p[1][2].row=-1;
  vp[4].p[1][2].col=-1;
  vp[4].p[1][3].row=0;
  vp[4].p[1][3].col=2;
  
  vp[4].p[2][0].row=0;
  vp[4].p[2][0].col=0;
  vp[4].p[2][1].row=-1;
  vp[4].p[2][1].col=1;
  vp[4].p[2][2].row=1;
  vp[4].p[2][2].col=-1;
  vp[4].p[2][3].row=-2;
  vp[4].p[2][3].col=0;
  
  vp[4].p[3][0].row=0;
  vp[4].p[3][0].col=0;
  vp[4].p[3][1].row=-1;
  vp[4].p[3][1].col=-1;
  vp[4].p[3][2].row=1;
  vp[4].p[3][2].col=1;
  vp[4].p[3][3].row=0;
  vp[4].p[3][3].col=-2;
  
  vp[4].p[4][0].row=0;
  vp[4].p[4][0].col=0;
  vp[4].p[4][1].row=1;
  vp[4].p[4][1].col=-1;
  vp[4].p[4][2].row=-1;
  vp[4].p[4][2].col=1;
  vp[4].p[4][3].row=2;
  vp[4].p[4][3].col=0;
  
  /* Pentru piesa J */
  vp[5].rot=4;
  vp[5].p[0][0].row=0;
  vp[5].p[0][0].col=cols/2+1;
  vp[5].p[0][1].row=0;
  vp[5].p[0][1].col=cols/2;
  vp[5].p[0][2].row=0;
  vp[5].p[0][2].col=cols/2+2;
  vp[5].p[0][3].row=1;
  vp[5].p[0][3].col=cols/2+2;
  /* Coordonate relative ale fiecarei pozitii fata de pozitia anterioara */
  vp[5].p[1][0].row=0;
  vp[5].p[1][0].col=0;
  vp[5].p[1][1].row=1;
  vp[5].p[1][1].col=1;
  vp[5].p[1][2].row=-1;
  vp[5].p[1][2].col=-1;
  vp[5].p[1][3].row=-2;
  vp[5].p[1][3].col=0;
  
  vp[5].p[2][0].row=0;
  vp[5].p[2][0].col=0;
  vp[5].p[2][1].row=-1;
  vp[5].p[2][1].col=1;
  vp[5].p[2][2].row=1;
  vp[5].p[2][2].col=-1;
  vp[5].p[2][3].row=0;
  vp[5].p[2][3].col=-2;
  
  vp[5].p[3][0].row=0;
  vp[5].p[3][0].col=0;
  vp[5].p[3][1].row=-1;
  vp[5].p[3][1].col=-1;
  vp[5].p[3][2].row=1;
  vp[5].p[3][2].col=1;
  vp[5].p[3][3].row=2;
  vp[5].p[3][3].col=0;
  
  vp[5].p[4][0].row=0;
  vp[5].p[4][0].col=0;
  vp[5].p[4][1].row=1;
  vp[5].p[4][1].col=-1;
  vp[5].p[4][2].row=-1;
  vp[5].p[4][2].col=1;
  vp[5].p[4][3].row=0;
  vp[5].p[4][3].col=2;
  
  /* Pentru piesa T */
  vp[6].rot=4;
  vp[6].p[0][0].row=0;
  vp[6].p[0][0].col=cols/2+1;
  vp[6].p[0][1].row=0;
  vp[6].p[0][1].col=cols/2;
  vp[6].p[0][2].row=0;
  vp[6].p[0][2].col=cols/2+2;
  vp[6].p[0][3].row=1;
  vp[6].p[0][3].col=cols/2+1;
  /* Coordonate relative ale fiecarei pozitii fata de pozitia anterioara */
  vp[6].p[1][0].row=0;
  vp[6].p[1][0].col=0;
  vp[6].p[1][1].row=-1;
  vp[6].p[1][1].col=1;
  vp[6].p[1][2].row=0;
  vp[6].p[1][2].col=0;
  vp[6].p[1][3].row=0;
  vp[6].p[1][3].col=0;
  
  vp[6].p[2][0].row=0;
  vp[6].p[2][0].col=0;
  vp[6].p[2][1].row=1;
  vp[6].p[2][1].col=-1;
  vp[6].p[2][2].row=0;
  vp[6].p[2][2].col=0;
  vp[6].p[2][3].row=-2;
  vp[6].p[2][3].col=0;
  
  vp[6].p[3][0].row=0;
  vp[6].p[3][0].col=0;
  vp[6].p[3][1].row=0;
  vp[6].p[3][1].col=0;
  vp[6].p[3][2].row=-1;
  vp[6].p[3][2].col=-1;
  vp[6].p[3][3].row=2;
  vp[6].p[3][3].col=0;
  
  vp[6].p[4][0].row=0;
  vp[6].p[4][0].col=0;
  vp[6].p[4][1].row=0;
  vp[6].p[4][1].col=0;
  vp[6].p[4][2].row=1;
  vp[6].p[4][2].col=1;
  vp[6].p[4][3].row=0;
  vp[6].p[4][3].col=0;
  
}

/* mv=mutari */
void imp_mv(struct Position *mvd, struct Position *mvl, struct Position *mvr) {
  int i;
  for(i=0;i<4;i++) {
    mvd[i].row=1;
    mvd[i].col=0;
    mvl[i].row=0;
    mvl[i].col=-1;
    mvr[i].row=0;
    mvr[i].col=1;
  }
}

void at_struct(struct Position *p,struct Position *q) {
  int i;
  for(i=0;i<4;i++) {
      p[i].row=q[i].row;
      p[i].col=q[i].col;
      
    }
}
 
/* Desenez piesa in careul de preview */
void draw_preview(struct Position *p, int cols, int color) {
  int i;
  attron(COLOR_PAIR(color));
  for(i=0;i<4;i++) {
    move(p[i].row+3,p[i].col+cols/2+7);
    addch('o');
  }
  attroff(COLOR_PAIR(color));
}

/* Sterg piesa din careul de preview */
void del_preview(struct Position *p, int cols) {
  int i;

  for(i=0;i<4;i++) {
    move(p[i].row+3,p[i].col+cols/2+7);
    addch(' ');
  }

}

/* Desenez o piesa in careul de Tetris */
void draw_piece(struct Position *p,int color) {
  int i;
  attron(COLOR_PAIR(color));
  for(i=0;i<4;i++) {
    move(p[i].row,p[i].col);
    if(p[i].row)
      addch('o');
  }
  attroff(COLOR_PAIR(color));
}

/* Sterg o piesa din careul de Tetris */
void del_piece(struct Position *p) {
  int i;
  for(i=0;i<4;i++) {
    move(p[i].row,p[i].col);
    if(p[i].row)
      addch(' ');
  }
}

/* Umplu matricea cu 0 */
void init_matrix(int m[rs][cls], int rows, int cols) {
  int i,j;
  for(i=0;i<=rows;i++)	
    for(j=0;j<=cols;j++)
      m[i][j]=0;
}

/* Desenez noua forma a matricei pe ecran */
void redraw_screen(int m[rs][cls],int rows,int cols) {
  int i,j;
  for(i=rows;i>=1;i--)
    for(j=1;j<=cols;j++) {
      move(i,j);
      if(m[i][j]) {
	attron(COLOR_PAIR(m[i][j]));
	addch('o');
	attroff(COLOR_PAIR(m[i][j]));
      }
      else
	addch(' ');
    }
  refresh();
}

/* Elimin liniile complete */
int collapse(int mdel[rs][cls],int mwrite[rs][cls],int rows,int cols) {
  int i=rows,j,k=rows,full=0;
  while(mdel[i][0]) {
    if(mdel[i][0]!=cols) {
      for(j=0;j<=cols;j++)
	mwrite[k][j]=mdel[i][j];
      k--;
    }
    else
      full++;
    i--;
  }
  init_matrix(mdel,rows,cols);
  if(full) 
    redraw_screen(mwrite,rows,cols);
  return full;
}

/* ghost="Imaginea" (coordonatele) piesei in urmatorul moment sau
la apasarea unei taste sageata (folosita pentru a se testa 
suprapunerea cu matricea sau iesirea din ecran */
void create_ghost(struct Position *g,struct Position *p,struct Position *mv) {
  int i;
  for(i=0;i<4;i++) {
    g[i].row=p[i].row+mv[i].row;
    g[i].col=p[i].col+mv[i].col;
  }
     
}

/* Punerea piesei in matrice */
void put_piece_in_matrix(struct Position *p,int m[rs][cls],int nrp) {
  int i;
  for(i=0;i<4;i++) {
    m[p[i].row][p[i].col]=nrp+1;
    m[p[i].row][0]++;
  }
}
  

/* functie care calculeaza diferenta de timp in sutimi de secunda */
long timediff(struct timeval *t1, struct timeval *t2) {
  long ssec;
  ssec=(t2->tv_sec-t1->tv_sec)*100;
  ssec+=(t2->tv_usec-t1->tv_usec)/10000;
  return ssec;
}

/* Daca piesa poate merge in jos */
int test_down(struct Position *g, int rows) {
  int i;
  for(i=0;i<4;i++) 
    if(g[i].row>rows)
      return 0;
  return 1;
}

/* Daca piesa poate merge in sus */
int test_up(struct Position *g) {
  int i;
  for(i=0;i<4;i++) 
    if(g[i].row<1)
      return 0;
  return 1;
}

/* Daca piesa poate merge in stanga */
int test_left(struct Position *g) {
  int i;
  for(i=0;i<4;i++)
    if(g[i].col<1)
      return 0;
  return 1;
}

/* Daca piesa poate merge in dreapta */
int test_right(struct Position *g, int cols) {
  int i;
  for(i=0;i<4;i++) 
    if(g[i].col>cols)
      return 0;
  return 1;
}

/* Daca piesa nu se suprapune cu piesele deja existente
in careul de joc*/
int test_over(struct Position *g,int m[rs][cls]) {
  int i;
  for(i=0;i<4;i++)
    if(m[g[i].row][g[i].col])
      return 0;
  return 1;
}

/* functie care foloseste functia de mai sus, insa tine cont de
care dintre cele doua matrici se afla in momentul acela in 
utilizare (este "activa") */
int test_over_xmatrix(int a_m,int m1[rs][cls],int m2[rs][cls],struct Position *g) { 
  int ok;
  if(a_m==1)
    ok=test_over(g,m1);
  else
    ok=test_over(g,m2);
  return ok;
}

int main()
{
  int nrows,ncols,level,ok,i,j,score,cols,rows,nrp_preview,poz;
  int points,nrp_crt,act_m,g_poz,nr_fall,last_score,dif_score;
  struct Position lev,c,date_time,score_poz,time_poz; /* c=cursor */
 
  time_t last_t,crt_t,in_t,e_t;
  struct timeval last_fall,crt_time;
  struct tm *etime;
  long interval; 		
  
  /* Declar doua matrici pentru joc, al doilea este folosit pentru 
  implementarea collapse. Prima coloana din fiecare matrice va retine
  nr de piese de pe o linie (cand nr de piese de pe o linie este egal
  cu dimensiunea liniei, linia respectiva va fi eliminata */
  int m1[rs][cls],m2[rs][cls];
  
  struct piese vp[7];
  
  /* Declaratie pt structurile ce retin coordonatele pentru: pozitia piesei 
  curente,  piesa urmatoare, pozitia urmatoare a piesei curente, ... */ 
  struct Position piesa_crt[4],preview[4],ghost[4],mvd[4],mvl[4],mvr[4];
  
    /* Caracterul citit. */
  int p;

    /* Initializarea ferestrei si determinarea dimensiunilor acesteia. */
  WINDOW* wnd = initscr();
  start_color();
  getmaxyx(wnd, nrows, ncols);
  /* Alte intializari ale ecranului*/
  curs_set(0);
  noecho();
  cbreak();
  keypad(wnd, TRUE);
  nodelay(wnd, TRUE);
  
  /* Declar perechile de culori folosite pentru piese */
  init_pair(1, 1, 0);
  init_pair(2, 2, 0);
  init_pair(3, 3, 0);
  init_pair(4, 4, 0);
  init_pair(5, 5, 0);
  init_pair(6, 6, 0);
  init_pair(7, 7, 0);  
  
  
  /* MENIUL */
Meniu:
  clear();
  curs_set(0);
  
  level=1;
  nr_fall=0;
  interval=70;		/* 70 sutimi de secunda = 0.7 secunde */
  
  mvaddstr(1, 1, "New Game");
  mvaddstr(2, 1, "Set Starting Level <1>");
  getyx(wnd,lev.row,lev.col);
  lev.col--;
  mvaddstr(3, 1, "Quit");
  move(1,1);
  insch('>');
  refresh();
  c.row=c.col=1;

  while (1) {               
    p = get_key_pressed(wnd);
    if (tolower(p) == 'q') {
      ok=0;
      break;
    }
    if (tolower(p)=='w' || tolower(p)==KEY_UP) {
	move(c.row,c.col);
	if(c.row==1)
	  c.row=3;
	 else
	  c.row--;
	delch();
	move(c.row,c.col);
	insch('>');
	refresh();
    }
    if (tolower(p)=='s' || tolower(p)==KEY_DOWN) {
        move(c.row,c.col);
	if(c.row==3)
	  c.row=1;
	else
	  c.row++;
	delch();
	move(c.row,c.col);
	insch('>');
	refresh();
    }
    if (tolower(p)=='\n' || tolower(p)==' ') {
	if(c.row==1) {
	  ok=1;
	  break;
	  
	}
	else
	  if(c.row==3) {
	    ok=0;
	    break;
	  }
    }
    if (c.row==2 && (tolower(p)=='a' || tolower(p)==KEY_LEFT)) {
	if(level==1)
	  level=7;
	else
	  level--;
	move(lev.row,lev.col);
	delch();
	insch(level+48);
    }
    if (c.row==2 && (tolower(p)=='d' || tolower(p)==KEY_RIGHT)) {
	if(level==7)
	  level=1;
	else
	  level++;
	move(lev.row,lev.col);
	delch();
	insch(level+48);
    }
  
  }
  
  /* New Game */
  
  if(ok) {
    clear();
    nodelay(wnd, TRUE);
    
    /*Iau careul de 30 de linii si 15 coloane */
    cols=15;
    rows=30;
    
    /* Bordez careul pe ecran */ 
    for(i=0;i<=rows+1;i++) {
      move(i,0);
      addch('*');
      move(i,cols+1);
      addch('*');
    }
    for(j=0;j<=cols+1;j++) {
      move(0,j);
      addch('*');
      move(rows+1,j);
      addch('*');
    }
    
    /* Bordez un chenar de 6x6 in coltul din dreapta sus pentru 
    preview-ul piesei urmatoare */
    
    for(i=0;i<=7;i++) {
      move(i,cols+3);
      addch('*');
      move(i,cols+10);
      addch('*');
    }
    for(j=cols+3;j<=cols+10;j++) {
      move(0,j);
      addch('*');
      move(7,j);
      addch('*');
    }
    /* Informatiile din dreapta careului */
   
    mvaddstr(10,cols+3,"Date & Time: ");
    in_t=time(NULL);
    last_t=in_t;
    getyx(wnd,date_time.row,date_time.col);
    printw("%s",ctime(&last_t));
    mvaddstr(11,cols+3,"Level: ");
    getyx(wnd,lev.row,lev.col);
    printw("%d",level);
    mvaddstr(12,cols+3,"Score: ");
    getyx(wnd,score_poz.row,score_poz.col);
    score=0;
    printw("%d",score);
    mvaddstr(13,cols+3,"Time elapsed: ");
    getyx(wnd,time_poz.row,time_poz.col);
    e_t=in_t-in_t;
    etime=gmtime(&e_t);
    move(time_poz.row,time_poz.col);
    printw("%02d:%02d:%02d",etime->tm_hour,etime->tm_min,etime->tm_sec);
    
/* Diferite initializari referitoare la scor, puncte primite si viteza caderii pieselor */
    points=level*10;
    interval=70-(level-1)*8;
    dif_score=level*100;
    last_score=0;
    
    /* Implementarea pieselor si initializarea celor doua matrici*/
    imp_piese(vp,rows,cols);    
    init_matrix(m1,rows,cols);
    init_matrix(m2,rows,cols);
    act_m=1;
       
    imp_mv(mvd,mvl,mvr);
     
    srand(time(NULL));
    nrp_crt=nrp_preview=rand()%7;

    /* poz=pozitia in care se afla piesa la un moment dat in careul
    Fiecare piesa apare initial in pozitia codificata 0 (pozitia absoluta) */
    poz=0;
    at_struct(piesa_crt,vp[nrp_crt].p[poz]);
    draw_piece(piesa_crt,nrp_crt+1);
    gettimeofday(&last_fall, NULL);

    /*Se genereaza preview-ul si piesa random */
    srand(time(NULL));
    srand(rand());
    nrp_preview=rand()%7;
    at_struct(preview,vp[nrp_preview].p[poz]);
    draw_preview(preview,cols,nrp_preview+1);
    
    refresh();
    
    while(1) {
      ok=0;
      p = get_key_pressed(wnd);
      if (p != NO_KEY_PRESSED) {
	if (tolower(p) == 'q') {
	break;
	}
	 
	/* Daca s-a apasat tasta p, jocul intra in pauza */
	if(tolower(p) == 'p') {
	  mvaddstr(14,cols+3,"Game paused");
	  refresh();
	  while(1) {
	    p = get_key_pressed(wnd);
	    if (p != NO_KEY_PRESSED) {
	      if (tolower(p) == 'p') {
		mvaddstr(14,cols+3,"           ");
		refresh();
		break;
	      }
	      
	      if(tolower(p)=='m')
		goto Meniu;
	      
	      /* Daca s-a apasat q, se iese din joc */
	      if (tolower(p) == 'q') {
		ok=1;
		break;
	      }
	    }
	    /* Actualizarea timpilor din dreapta */
	    crt_t=time(NULL);
	    if(crt_t-last_t==1) {
	      last_t=crt_t;
	      move(date_time.row,date_time.col);
	      printw("%s",ctime(&crt_t));
	      e_t=crt_t-in_t;
	      etime=gmtime(&e_t);
	      move(time_poz.row,time_poz.col);
	      printw("%02d:%02d:%02d",etime->tm_hour,etime->tm_min,etime->tm_sec);
	    }   
	  }
	}
	
	if(ok) 
	  break;
	
	if(tolower(p)=='m')
	  goto Meniu;
	
	/* Daca s-a apasat tasta sageata jos, piesa se muta
	un rand mai jos */
	if(tolower(p)==KEY_DOWN) {
	  create_ghost(ghost,piesa_crt,mvd);
	  if(test_down(ghost,rows) && test_over_xmatrix(act_m,m1,m2,ghost)) {
	    del_piece(piesa_crt);
	    at_struct(piesa_crt,ghost);
	    draw_piece(piesa_crt,nrp_crt+1);
	    refresh();
	  }	
	} 

	/* Daca s-a apasat tasta sageata stanga, piesa se muta
	la stanga */
	if(tolower(p)==KEY_LEFT) {
	  create_ghost(ghost,piesa_crt,mvl);
	  if(test_left(ghost) && test_over_xmatrix(act_m,m1,m2,ghost)) {
	    del_piece(piesa_crt);
	    at_struct(piesa_crt,ghost);
	    draw_piece(piesa_crt,nrp_crt+1);
	    refresh();
	  }
	}
	
	/* Daca s-a apasat tasta sageata dreapta, piesa se muta
	la dreapta */	
	if(tolower(p)==KEY_RIGHT) {
	  create_ghost(ghost,piesa_crt,mvr);
	  if(test_right(ghost,cols) && test_over_xmatrix(act_m,m1,m2,ghost)) {
	    del_piece(piesa_crt);
	    at_struct(piesa_crt,ghost);
	    draw_piece(piesa_crt,nrp_crt+1);
	    refresh();
	  }
	}
	
	/* Daca s-a apasat tasta sageata sus si piesa nu este
	patratul se roteste */
	if(tolower(p)==KEY_UP && nrp_crt) {
	  if(poz==vp[nrp_crt].rot)
	    g_poz=1;
	  else
	    g_poz=poz+1;
	  create_ghost(ghost,piesa_crt,vp[nrp_crt].p[g_poz]);
	  if(test_up(ghost) && test_right(ghost,cols) && test_left(ghost))
	    if(test_down(ghost,rows) && test_over_xmatrix(act_m,m1,m2,ghost)) {
	      poz=g_poz;
	      del_piece(piesa_crt);
	      at_struct(piesa_crt,ghost);
	      draw_piece(piesa_crt,nrp_crt+1);
	      refresh();
	    }
	}		
      } 
      
      /* Se actualizeaza timpii din dreapta */
      crt_t=time(NULL);
      if(crt_t-last_t==1) {
	last_t=crt_t;
	move(date_time.row,date_time.col);
	printw("%s",ctime(&crt_t));
	e_t=crt_t-in_t;
	etime=gmtime(&e_t);
	move(time_poz.row,time_poz.col);
	printw("%02d:%02d:%02d",etime->tm_hour,etime->tm_min,etime->tm_sec);
	refresh();
      }   
      
      
      /* Daca e timpul ca piesa sa mai cada un rand */
      gettimeofday(&crt_time, NULL);
      if(timediff(&last_fall,&crt_time)>interval) {
	last_fall.tv_sec=crt_time.tv_sec;
	last_fall.tv_usec=crt_time.tv_usec; 
	create_ghost(ghost,piesa_crt,mvd);
	if(test_down(ghost,rows) && test_over_xmatrix(act_m,m1,m2,ghost)) {
	  nr_fall++;
	  del_piece(piesa_crt);
	  at_struct(piesa_crt,ghost);
	  draw_piece(piesa_crt,nrp_crt+1);
	  refresh();
	}
	else {
  /* Daca piesa nu a cazut deloc si nu mai poate sa mai cada,
  inseamna Game Over */
	     if(nr_fall==0) {
	      ok=0;
	      init_matrix(m1,rows,cols);
	      redraw_screen(m1,rows,cols);
	      move(rows/2,cols/2-3);
	      printw("GAME OVER");
	      while(1) {
		p = get_key_pressed(wnd);
		if (p != NO_KEY_PRESSED) {
		  
		  if(tolower(p)=='m')
		      goto Meniu;
		  
		  if (tolower(p) == 'q') {
		    ok=1;
		    break;
		  }
		}
	      }
	     if(ok)
	       break;
	    }
	    
	    /* Daca piesa a ajuns jos, se actualizeaza matricea
	    activa */
	    if(act_m==1) {
	      put_piece_in_matrix(piesa_crt,m1,nrp_crt);
	      score+=points*collapse(m1,m2,rows,cols);
	      act_m=2;
	      
	      move(score_poz.row,score_poz.col);
	      printw("%d",score);
	      
	      /* Daca s-a acumulat scorul pentru trecerea la nivelul urmator, se 
	      actualizeaza informatiile corespunzatoare */
	      if(score-last_score>dif_score && level<7) {
		last_score=score;
		level++;
		move(lev.row,lev.col);
		printw("%d",level);
		points=level*10;
		dif_score=level*100;
		interval=70-(level-1)*8;
		refresh();
	      }
	    }
	    else {
	      put_piece_in_matrix(piesa_crt,m2,nrp_crt);
	      score+=points*collapse(m2,m1,rows,cols);
	      act_m=1;
	      
	      move(score_poz.row,score_poz.col);
	      printw("%d",score);
	      
	      /* Daca s-a acumulat scorul pentru trecerea la nivelul urmator, se 
	      actualizeaza informatiile corespunzatoare */
	      if(score-last_score>dif_score && level<7) {
		last_score=score;
		level++;
		move(lev.row,lev.col);
		printw("%d",level);
		points=level*10;
		dif_score=level*100;
		interval=70-(level-1)*8;
		refresh();
	      }
	    } 
	    
	    at_struct(ghost,preview);
	    
	    /* Se genereaza un nou preview, iar piesa urmatoare devine
	    fostul preview */
	    if(test_over_xmatrix(act_m,m1,m2,ghost)) {
	      at_struct(piesa_crt,preview);
	      nrp_crt=nrp_preview;
	      draw_piece(piesa_crt,nrp_crt+1);
	    
	      del_preview(preview,cols);
	      srand(time(NULL));
	      nrp_preview=rand()%7;
	      poz=0;
	      at_struct(preview,vp[nrp_preview].p[poz]);
	      draw_preview(preview,cols,nrp_preview+1);
	    
	      refresh();
	    }
	    /* Daca piesa urmatoare nu mai poate intra in ecran fara sa se
	    suprapuna cu piesele deja existente, rezulta Game Over */
	    else {
	      ok=0;
	      init_matrix(m1,rows,cols);
	      redraw_screen(m1,rows,cols);
	      move(rows/2,cols/2-3);
	      printw("GAME OVER");
	      while(1) {
		p = get_key_pressed(wnd);
		if (p != NO_KEY_PRESSED) {
		  
		  if(tolower(p)=='m')
		    goto Meniu;
		  
		  if (tolower(p) == 'q') {
		    ok=1;
		    break;
		  }
		}
	      }
	     if(ok)
	       break;
	    }
	      
	}
	  
	
      }
	

    }
    
  }
  

  /* Distrugerea ferestrei inainte de iesirea din aplicatie. */
  endwin();
  return 0;
}

