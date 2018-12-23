

//#include "buffers.h"
//#include "screenIO.h"
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include <time.h>

// davedith-b
#include "termedit.h"

#ifndef buffers_h
#define buffers_h

//#include "structs.h"

void goToNextBuffer();
void goToPrevBuffer();
void closeBuffer();

#endif
/*
Copyright 2001-2003 David Gucwa

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/
#ifndef features_h
#define features_h

void search();
void replace();
void tryCompile();
void gotoLine(int line);
void toggleAutoIndent();
void toggleBottomRow();

#endif

/*
Copyright 2001-2003 David Gucwa

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/
#ifndef fileIO_h
#define fileIO_h

char *doSave(char *filename);
void save();
void saveAs();
void load(char *filename);
void askLoad();

#endif
/*
Copyright 2001-2003 David Gucwa

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/
#ifndef keyboard_h
#define keyboard_h

void keyHit(int keypress, char undoNow);
void listChoice(int n, char **choices, char *answer, char *message);

#endif
/*
Copyright 2001-2003 David Gucwa

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/
#ifndef main_h
#define main_h

#include <stdio.h>

//#include "structs.h"

char scrollDown();
char scrollUp();
void doArguments(int argc, char *argv[]);
void quit(char *text);
void displayHelp();
void displayVersion();
void sigcatch();
void loadSettings();
void writeRC(FILE *fp);
void tryQuit();
void nothing();
void logMsg(char *msg);
void radixSort(char **strings, int number);
void randomizedQuickSort(char **strings, int low, int high);

typedef void (*ptrToFunction)();

void addLineAfter(struct line *whichLine, char *data);
void connectLines(struct line *baseline);
void determineLineNum(struct position *p);
void countTabs(struct line *l);
void determineCursX(struct position *p);
ptrToFunction Fn_ptr[12]; //Bindings for the Fn keys; Fx = Fn_ptr[x-1]

extern int maxY,maxX;
extern int helpBarUpdate;

extern char *version;

//Preferences and default values
extern int maxUndoLength;
extern char undoEnabled;
extern char autoIndent;
extern int numberOfBuffers;
extern char bottomRowToggle;
extern char bufferQuit;
extern char tabWidth;
extern char smartCursor;
extern char optimize;

extern int *lastDisplayed; /* Number of characters last displayed on various lines */
extern char displayWholeScreen; /* Whether to refresh the whole screen */

extern struct buffer *buffers;
extern struct buffer *currentBuffer;
extern int currentBufferNum;

#endif
/*
Copyright 2001-2003 David Gucwa

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/
#ifndef move_h
#define move_h

//#include "structs.h"

char positionDown(struct position *p);
char positionUp(struct position *p);
void moveUp(struct position *p);
void moveDown(struct position *p);
char moveLeft(struct position *p); //Returns 1 when you hit the beginning of the buffer
char moveRight(struct position *p); //Returns 1 when you hit the end of the buffer
char scrollDown();
char scrollUp();

#endif
/*
Copyright 2001-2003 David Gucwa

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/
#ifndef screenIO_h
#define screenIO_h

//#include "structs.h"

void displayScreen();
void showRow();
void helpBar();
void displayBottomRow();
void displayLine(int line, struct position *pos);

#endif
/*
Copyright 2001-2003 David Gucwa

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/
#ifndef structs_h
#define structs_h

struct line {
  unsigned char *data;
  unsigned int length;
  struct line *next;
  struct line *prev;
  unsigned char hasTabs;
};

struct position {
  struct line *l;
  unsigned int offset;
  unsigned int lineNum;
  unsigned int cursX,cursY;
  unsigned int wantCursX;
};

struct undoMove {
  /* Reverses some modification to a buffer */
  unsigned int line, offset;
  char c; /* What was added or removed */
};

struct buffer {
  char searchString[80];
  int numLines;
  struct line *head,*tail;
  struct position cursor;
  struct position topLine;
  struct position lineUpdate;
  char keepGoing;
  struct line **currentLine;
  char fname[80];
  int lineNumBak;
  char updated;
  struct undoMove *undoMoves;
  int undoBufferPointer;
  int undoBufferLength;
};

#endif
/*
Copyright 2001-2003 David Gucwa

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/
#ifndef undo_h
#define undo_h

void Do(int keypress);
void addToUndo(int keypress);
void Undo();

#endif
// davedith-e


extern int numberOfBuffers;
extern int helpBarUpdate;
extern char smartCursor;

extern struct buffer *buffers;
extern struct buffer *currentBuffer;
extern int currentBufferNum;

void keyHit(int keypress, char undoNow);
void quit(char *text);

void goToNextBuffer()
{
  currentBufferNum++;
  if(currentBufferNum == numberOfBuffers) currentBufferNum = 0;
  currentBuffer = &buffers[currentBufferNum];
  currentBuffer->lineUpdate = currentBuffer->topLine;
  currentBuffer->lineUpdate.lineNum = 0;
  currentBuffer->keepGoing = 1;
  helpBarUpdate=1;
}

void goToPrevBuffer()
{
  currentBufferNum--;
  if(currentBufferNum == -1) currentBufferNum = numberOfBuffers - 1;
  currentBuffer = &buffers[currentBufferNum];
  currentBuffer->lineUpdate = currentBuffer->topLine;
  currentBuffer->lineUpdate.lineNum = 0;
  currentBuffer->keepGoing = 1;
  helpBarUpdate=1;
}

void closeBuffer()
{
  struct buffer *b = currentBuffer;
  char tempSmartCursor = smartCursor;
  smartCursor = 0;

  //Go to the very beginning of the buffer
  while(currentBuffer->cursor.l!=currentBuffer->head->next || currentBuffer->cursor.offset!=0)
    keyHit(259, 0); //Key_Up

  //Wipe out lines
  while(currentBuffer->numLines)
    keyHit(21, 0); //Ctrl-U
  keyHit(21, 0); //Last remaining line

  currentBuffer->updated = 0;
  strcpy(currentBuffer->fname, "");
  
  while(strcmp(currentBuffer->fname, "") == 0 && !currentBuffer->updated) {
    goToPrevBuffer();
    if(currentBuffer == b) quit("");
  }
  smartCursor = tempSmartCursor;
  //helpBarUpdate = 1;
  //currentBuffer->lineUpdate.offset = -1;
  displayScreen();
}
/*
Copyright 2001-2003 David Gucwa

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

//#include "features.h"
//#include "main.h"
//#include "screenIO.h"
//#include "fileIO.h"
//#include "keyboard.h"
//#include "buffers.h"
//#include "move.h"

void search()
{
  unsigned char *t;
  int offset;
  struct line *l = *currentBuffer->currentLine;
  char down=1; //Whether or not the found word is below the current position
  char count=2;

  if (currentBuffer->head->next->next == currentBuffer->tail && currentBuffer->head->next->length == 1) {
    //No characters in the buffer
    return;
  }
  
  if (helpBarUpdate==0 || strcmp(currentBuffer->searchString,"")==0) {
    displayBottomRow();
    mvaddstr(maxY-1,0,"Search for what word?");
    mvgetstr(maxY-1,22,currentBuffer->searchString);
  }
  if (l == currentBuffer->tail->prev && currentBuffer->cursor.offset >= l->length - 2) {
    l = currentBuffer->head->next;
    offset = 0;
    down = 0;
  }
  else {
    offset = currentBuffer->cursor.offset + 1;
  }
  while (1) {
    t = (unsigned char *)strstr(l->data + offset, currentBuffer->searchString);
    if (t!=NULL) break;
    offset = 0;
    l = l->next;
    if (l==((*currentBuffer->currentLine)->next)) count--;
    if (l==currentBuffer->tail) { 
      l = currentBuffer->head->next; 
      down=0; 
    }
    if (count==0) break;
  }
  
  if (t==NULL) {
    displayBottomRow();
    mvaddstr(maxY-1,0,"String not found.");
    helpBarUpdate=2;
    strcpy(currentBuffer->searchString,"");
    return;
  }
  
  offset = t - l->data;
  
  if (down) {
    while(currentBuffer->cursor.l != l)
      moveDown(&currentBuffer->cursor);
  }
  else {
    while(currentBuffer->cursor.l != l)
      moveUp(&currentBuffer->cursor);
  }
  
  while(currentBuffer->cursor.offset < offset) {
    if (moveRight(&currentBuffer->cursor) == 1) break;
  }

  while(currentBuffer->cursor.offset > offset) {
    if (moveLeft(&currentBuffer->cursor) == 1) break;
  }

  currentBuffer->lineUpdate = currentBuffer->topLine;
  currentBuffer->lineUpdate.lineNum = 0;
  currentBuffer->keepGoing = 1;
  
  helpBarUpdate = 2;
}

void replace()
{
  static char replaceString[80];
  static char findString[80];
  unsigned char *t;
  int offset;
  struct line *l = *currentBuffer->currentLine;
  char down=1; //Whether or not the found word is below the current position
  char count=2;

  if(helpBarUpdate==0 || !strcmp(findString,"") || !strcmp(replaceString,""))
  {
    displayBottomRow();
    mvaddstr(maxY-1, 0, "Replace what?");
    mvgetstr(maxY-1, 14, findString);
    displayBottomRow();
    mvaddstr(maxY-1, 0, "Replace with what?");
    mvgetstr(maxY-1, 19, replaceString);
  }
  offset = currentBuffer->cursor.offset + 1;
  while(1)
  {
    t = (unsigned char *)strstr(l->data + offset, findString);
    if(t!=NULL) break;
    offset = 0;
    l = l->next;
    if(l==((*currentBuffer->currentLine)->next)) count--;
    if(l==currentBuffer->tail) { l = currentBuffer->head->next; down=0; }
    if(count==0) break;
  }

  if(t==NULL)
  {
    displayBottomRow();
    mvaddstr(maxY-1,0,"String not found.");
    helpBarUpdate=2;
    strcpy(findString,"");
    return;
  }

  offset = t - l->data;

  if (down) {
    while(currentBuffer->cursor.l != l)
      moveDown(&currentBuffer->cursor);
  }
  else {
    while(currentBuffer->cursor.l != l)
      moveUp(&currentBuffer->cursor);
  }

  while(currentBuffer->cursor.offset < offset) {
    if (moveRight(&currentBuffer->cursor) == 1) break;
  }

  while(currentBuffer->cursor.offset > offset) {
    if (moveLeft(&currentBuffer->cursor) == 1) break;
  }

  //Delete the findstring
  for(offset = strlen(findString);offset;offset--)
    keyHit(330, 0);

  //Add the replacestring
  for(offset=0;offset<strlen(replaceString);offset++)
    keyHit(replaceString[offset], 0);

  currentBuffer->lineUpdate = currentBuffer->topLine;
  currentBuffer->lineUpdate.lineNum = 0;
  currentBuffer->keepGoing = 1;

  helpBarUpdate = 2;
}

void tryCompile()
{
  FILE *fp;
  displayBottomRow();
  mvaddstr(maxY-1,0,"Running Makefile...");
  ungetch(' ');
  getch();
  if(strcmp(currentBuffer->fname, "")) save();
  system("make 2>dav.err >/dev/null");
  fp = fopen("dav.err","r");
  fgetc(fp);
  if(feof(fp))
  {
    displayBottomRow();
    mvaddstr(maxY-1,0,"Compile successful.");
    helpBarUpdate = 2;
  }
  else
  {
    displayBottomRow();
    while(currentBuffer->head->next->next != currentBuffer->tail || currentBuffer->head->next->length!=1)
      goToNextBuffer();
    load("dav.err");
    currentBuffer->lineUpdate = currentBuffer->cursor;
    currentBuffer->lineUpdate.lineNum = 0;
    currentBuffer->keepGoing=1;
    helpBarUpdate = 1;
  }
  fclose(fp);
  system("rm dav.err");
}

void gotoLine(int line)
{
  while(currentBuffer->cursor.lineNum < line - 1) {
    if(scrollDown()) {
      break;
    }
  }
  
  while (currentBuffer->cursor.lineNum < line - 1) {
    if (positionDown(&currentBuffer->cursor)) {
      break;
    }
  }
  
  currentBuffer->lineUpdate = currentBuffer->topLine;
  currentBuffer->lineUpdate.lineNum = 0;
  currentBuffer->keepGoing = 1;
  displayScreen();
}

void toggleAutoIndent()
{
  currentBuffer->lineUpdate.offset = -1;
  autoIndent = !autoIndent;
  displayBottomRow();
  mvaddstr(maxY-1,0,"Auto indenting set to");
  mvaddch(maxY-1,22,autoIndent+48);
  helpBarUpdate = 2;
}

void toggleBottomRow()
{
  bottomRowToggle = !bottomRowToggle;
  helpBar();
  currentBuffer->lineUpdate.offset = -1;
}
/*
Copyright 2001-2003 David Gucwa

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/dir.h>
#include <ncurses.h>

//#include "fileIO.h"
//#include "structs.h"
//#include "screenIO.h"
//#include "keyboard.h"
//#include "main.h"

extern struct buffer *currentBuffer;
extern int helpBarUpdate;
extern int maxY;
extern char autoIndent;

void save()
{
  if(!strcmp(currentBuffer->fname, "")) {
    doSave(".");
  }
  else {
    doSave(currentBuffer->fname);
  }
  currentBuffer->lineUpdate = currentBuffer->topLine;
  currentBuffer->lineUpdate.lineNum = 0;
  currentBuffer->lineUpdate.cursY = 0;
  currentBuffer->keepGoing=1;
}

void saveAs()
{
  char *ptr = (char *)malloc(strlen(currentBuffer->fname));
  strcpy(ptr, currentBuffer->fname);
  if(!strcmp(doSave("."), "")) {
    strcpy(currentBuffer->fname, ptr);
  }
  free(ptr);
  currentBuffer->lineUpdate = currentBuffer->topLine;
  currentBuffer->lineUpdate.lineNum = 0;
  currentBuffer->lineUpdate.cursY = 0;
  currentBuffer->keepGoing=1;
}

char *doSave(char *filename) {
  int t;
  FILE *fp;
  struct line *l = currentBuffer->head->next;
  struct stat s;

  helpBarUpdate = 1;

  if(!strcmp(filename, ""))
    return "";                                                                                              

  stat(filename, &s);

  if(S_ISDIR(s.st_mode)) {
    while(1) {
      char newFile[256];
      DIR *dir = opendir(filename);
      char **choices = malloc(sizeof(char *));
      int n = 1;
      char answer[256];
      struct dirent *d;

      choices[0] = malloc(7);
      strcpy(choices[0], "Cancel");
      while(1)
      {
        d = readdir(dir);
        if(d==NULL) break;
        n++;
        choices = realloc(choices, n*sizeof(char *));
        choices[n-1] = malloc(256);
        sprintf(choices[n-1], d->d_name);
      }
      closedir(dir);
      
      if (optimize == 0) { //Memory efficiency
        randomizedQuickSort(&choices[1], 0, n-2);
      }
      else { //Cpu efficiency
        radixSort(&choices[1], n-1);
      }
      
      listChoice(n, choices, answer, "File to save as?");
      if(!strcmp(answer, "DAV_CANCEL")) {
        newFile[0] = '\0';
      }
      else if(!strcmp(answer, ".")) {
        sprintf(newFile, "%s", filename);
      }
      else if(!strcmp(answer, "..")) {
        sprintf(newFile, "%s/%s", filename, answer);
      }
      else {
        sprintf(newFile, "%s/%s", filename, answer);
      }
      for(n--;n>=0;n--) {
        free(choices[n]);
      }
      free(choices);
      return doSave(newFile);
    }
  }

  fp = fopen(filename, "w");
  helpBarUpdate = 2;
  if(fp==NULL)
  {
    mvaddstr(maxY-1,0,
    "You do not have the proper permissions to save to that file");
    return "";
  }
  while(l!=currentBuffer->tail->prev)
  {
    for(t=0;t<l->length;t++)
      putc(l->data[t],fp);
    l = l->next;
  }
  for(t=0;t<l->length-1;t++)
    putc(l->data[t],fp);
  fclose(fp);
  displayBottomRow();
  mvaddstr(maxY-1,0,"File successfully saved.");
  strcpy(currentBuffer->fname, filename);
  currentBuffer->updated = 0;
  return currentBuffer->fname;
}

void load(char *filename)
{
  char t;
  int i;
  struct stat s;
  FILE *fp;
  stat(filename, &s);

  if(!strcmp(filename, ""))
    return;

  if(S_ISDIR(s.st_mode)) //File is a directory
  {
    DIR *dir = opendir(filename);
    char **choices = malloc(sizeof(char *));
    int n = 1;
    char answer[256];
    char newFile[256];
    struct dirent *d;

    choices[0] = malloc(7);
    strcpy(choices[0], "Cancel");

    while(1)
    {
      d = readdir(dir);
      if(d==NULL) break;
      n++;
      choices = realloc(choices, n*sizeof(char *));
      choices[n-1] = malloc(256);
      sprintf(choices[n-1], d->d_name);
    }
    closedir(dir);
    
    if (optimize == 0) { //Memory efficiency
      randomizedQuickSort(&choices[1], 0, n-2);
    } 
    else { //Cpu efficiency
      radixSort(&choices[1], n-1);
    }
    
    listChoice(n, choices, answer, "File to load?");
    if(!strcmp(answer, "DAV_CANCEL"))
    {
      currentBuffer->lineUpdate = currentBuffer->topLine;
      currentBuffer->keepGoing=1;
      currentBuffer->lineUpdate.lineNum = 0;
      currentBuffer->lineUpdate.cursY = 0;
      newFile[0] = '\0';
    }
    else if(!strcmp(answer, ".")) {
      sprintf(newFile, "%s", filename);
    }
    else if(!strcmp(answer, "..")) {
      sprintf(newFile, "%s/%s", filename, answer);
    }
    else {
      sprintf(newFile, "%s/%s", filename, answer);
    }
    for(n--;n>=0;n--)
      free(choices[n]);
    free(choices);
    load(newFile);
    return;
  }
  fp = fopen(filename,"r");

  strcpy(currentBuffer->fname, filename);
  if(fp==NULL)
  {
    displayBottomRow();
    mvaddstr(maxY-1,0,"Couldn't open file.");
    helpBarUpdate=2;
    return;
  }

  //Go to the very beginning of the buffer
  while(currentBuffer->cursor.l!=currentBuffer->head->next || currentBuffer->cursor.offset!=0)
    keyHit(259, 0); //Key_Up

  //Wipe out lines
  while(currentBuffer->numLines)
    keyHit(21, 0); //Ctrl-U
  keyHit(21, 0); //Last remaining line

  //Turn off autoindenting and read from the file
  t = autoIndent;
  autoIndent = 0;
  i = (int)getc(fp);
  if(i=='\n') i=13;
  while(i!=EOF)
  {
    keyHit(i,0);
    i = (int)getc(fp);
    if(i=='\n') i=13;
  }
  fclose(fp);
  autoIndent = t;

  //Go back up to the top
  while(currentBuffer->cursor.l!=currentBuffer->head->next || currentBuffer->cursor.offset!=0)
    keyHit(259, 0); //Key_Up

  currentBuffer->lineUpdate = currentBuffer->cursor;
  currentBuffer->keepGoing=1;
  currentBuffer->lineUpdate.lineNum = 0;
  currentBuffer->lineUpdate.cursY = 0;
  currentBuffer->updated = 0;
}

void askLoad()
{
  load(".");
  helpBarUpdate = 1;
}
/*
Copyright 2001-2003 David Gucwa

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

//#include "keyboard.h"
//#include "main.h"
//#include "screenIO.h"
//#include "undo.h"
//#include "move.h"

void keyHit(int keypress, char undoNow)
{
  int t=0,t2=0;
  int x;
  static char ctrl=0;
  unsigned char *ptr;
  unsigned char **data;

  if(keypress==27) { 
    ctrl=3; 
    return; 
  }
  if(keypress==79 && ctrl==3) { 
    ctrl--; 
    return; 
  }
  if(keypress==99 && ctrl==2) {
    currentBuffer->lineUpdate.offset = -1;
    ctrl=0;
    helpBarUpdate = 1;
    data = &((*currentBuffer->currentLine)->data);
    t=currentBuffer->cursor.cursY;
    currentBuffer->lineUpdate = currentBuffer->cursor;
    currentBuffer->lineUpdate.lineNum = currentBuffer->cursor.cursY;
    while((*data)[currentBuffer->cursor.offset]!=' ' && (*data)[currentBuffer->cursor.offset]!='\n'
    && (*data)[currentBuffer->cursor.offset]!=9)
      if(moveRight(&currentBuffer->cursor)) break;
    while((*data)[currentBuffer->cursor.offset]==' ' || (*data)[currentBuffer->cursor.offset]=='\n'
    || (*data)[currentBuffer->cursor.offset]==9)
      if(moveRight(&currentBuffer->cursor)) break;
    return;
  }
  if(keypress==100 && ctrl==2) {
    currentBuffer->lineUpdate.offset = -1;
    ctrl=0;
    helpBarUpdate = 1;
    data = &((*currentBuffer->currentLine)->data);
    t=currentBuffer->cursor.cursY;
    currentBuffer->lineUpdate = currentBuffer->cursor;
    currentBuffer->lineUpdate.lineNum = currentBuffer->cursor.cursY;
    moveLeft(&currentBuffer->cursor);
    while((*data)[currentBuffer->cursor.offset]==' ' || (*data)[currentBuffer->cursor.offset]=='\n'
    || (*data)[currentBuffer->cursor.offset]==9)
      if(moveLeft(&currentBuffer->cursor)) break;
    while((*data)[currentBuffer->cursor.offset]!=' ' && (*data)[currentBuffer->cursor.offset]!='\n'
    && (*data)[currentBuffer->cursor.offset]!=9)
      if(moveLeft(&currentBuffer->cursor)) break;
    moveRight(&currentBuffer->cursor);
    return;
  }
  if(keypress==91 && ctrl==3) { 
    ctrl--; 
    return; 
  }
  if(keypress==55 && ctrl==2) { 
    ctrl=1; 
    return; 
  }
  else if((keypress==94 && ctrl==1) || keypress==391)
  {
    currentBuffer->cursor.cursY = currentBuffer->cursor.cursX = currentBuffer->cursor.offset = 0;
    currentBuffer->cursor.l = currentBuffer->head->next;
    currentBuffer->topLine = currentBuffer->cursor;
    currentBuffer->lineUpdate = currentBuffer->cursor;
    currentBuffer->lineUpdate.lineNum = 0;
    currentBuffer->keepGoing=1;
    ctrl=0;
    return;
  }
  else if(keypress==335 || keypress==386)
  {
    *currentBuffer->currentLine = currentBuffer->tail->prev;
    currentBuffer->cursor.offset = (*currentBuffer->currentLine)->length - 1;
    determineCursX(&currentBuffer->cursor);
    currentBuffer->cursor.cursY=0;
    currentBuffer->topLine=currentBuffer->cursor;
    currentBuffer->topLine.cursX = currentBuffer->topLine.offset = 0;
    for(t=0;t<maxY-4;t++)
      scrollUp();
    currentBuffer->lineUpdate=currentBuffer->topLine;
    currentBuffer->lineUpdate.lineNum=0;
    currentBuffer->keepGoing=1;
    return;
  }
  ctrl=0;
  switch(keypress)
  {
    case 410:
      displayBottomRow();
      break;
    case -1: /* Window Resizing */
      {
        struct line *tempLine = currentBuffer->cursor.l;
        t = currentBuffer->cursor.offset;
        
        /* Reset to top left */
        keyHit(262, 0); /* Home key */
        while (currentBuffer->cursor.cursY > 0) {
          keyHit(259, 0); /* Up key */
        }
        
        getmaxyx(stdscr,maxY,maxX);
        free(lastDisplayed);
        lastDisplayed = (int *)malloc(maxY*sizeof(int));
        memset(lastDisplayed,0,maxY*sizeof(int));
        helpBar();
        while (currentBuffer->cursor.l != tempLine) {
          keyHit(258, 0); /* Down key */
        }
        while (currentBuffer->cursor.offset < t) {
          keyHit(261, 0); /* Right key */
        }
        while (currentBuffer->cursor.offset > t) {
          keyHit(260, 0); /* Left */
        }
        currentBuffer->lineUpdate = currentBuffer->topLine;
        currentBuffer->lineUpdate.lineNum = 0;
        currentBuffer->keepGoing = 1;
        
        /* Tell the display to refresh the whole screen */
        displayWholeScreen = 1;
        
        break;
      }

    case 265: //Function keys
    case 266:
    case 267:
    case 268:
    case 269:
    case 270:
    case 271:
    case 272:
    case 273:
    case 274:
    case 275:
    case 276:
      currentBuffer->lineUpdate.offset = -1;
      (*Fn_ptr[keypress-265])();
      break;

    case 258: //Down
      currentBuffer->lineUpdate.offset = -1;
      moveDown(&currentBuffer->cursor);
      if(smartCursor) {
        while(currentBuffer->cursor.wantCursX > currentBuffer->cursor.cursX
              && currentBuffer->cursor.cursX < ((*currentBuffer->currentLine)->length % maxX) - 1) {
          moveRight(&currentBuffer->cursor);
        }
      }
      break;

    case 259: //Up
      currentBuffer->lineUpdate.offset = -1;
      moveUp(&currentBuffer->cursor);
      if(smartCursor) {
        while(currentBuffer->cursor.wantCursX > currentBuffer->cursor.cursX
              && currentBuffer->cursor.cursX < ((*currentBuffer->currentLine)->length % maxX) - 1) {
          moveRight(&currentBuffer->cursor);
        }
      }
      break;

    case 260: /* Left */
      currentBuffer->lineUpdate.offset = -1;
      moveLeft(&currentBuffer->cursor);
      currentBuffer->cursor.wantCursX = currentBuffer->cursor.cursX;
      break;

    case 261: /* Right */
      currentBuffer->lineUpdate.offset = -1;
      moveRight(&currentBuffer->cursor);
      currentBuffer->cursor.wantCursX = currentBuffer->cursor.cursX;
      break;

    case 338: /* PgDn */
      currentBuffer->lineUpdate.offset = -1;
      x = currentBuffer->cursor.cursY + 2;
      for(t=maxY-1; t; t--) {
        moveDown(&currentBuffer->cursor);
      }
      for(t=0; t<maxY-x; t++) {
        scrollDown();
      }
      if(smartCursor) {
        while(currentBuffer->cursor.wantCursX > currentBuffer->cursor.cursX
           && currentBuffer->cursor.cursX < (*currentBuffer->currentLine)->length - 1) {
          moveRight(&currentBuffer->cursor);
        }
      }
      
      break;

    case 339: //PgUp
      currentBuffer->lineUpdate.offset = -1;
      x = currentBuffer->cursor.cursY;
      for(t=0;t<maxY-1;t++)
        moveUp(&currentBuffer->cursor);
      for(t=0;t<x;t++)
        scrollUp();
      if(smartCursor) {
        while(currentBuffer->cursor.wantCursX > currentBuffer->cursor.cursX
           && currentBuffer->cursor.cursX < (*currentBuffer->currentLine)->length - 1) {
          moveRight(&currentBuffer->cursor);
        }
      }
      break;

    case 262: //Home
      currentBuffer->lineUpdate.offset = -1;
      while(currentBuffer->cursor.cursX) moveLeft(&currentBuffer->cursor);
      currentBuffer->cursor.wantCursX = currentBuffer->cursor.cursX;
      break;

    case 360: //End
      t2=currentBuffer->topLine.lineNum;
      while(1) {
        t=moveRight(&currentBuffer->cursor);
        if(t==1) break;
        else if(t>1) {
          moveLeft(&currentBuffer->cursor);
          break;
        }
      }
      currentBuffer->lineUpdate.offset = -1;
      if(t2!=currentBuffer->topLine.lineNum) scrollUp();
      currentBuffer->cursor.wantCursX = currentBuffer->cursor.cursX;
      break;

    case 263: //Backspace
    case 8: //Shift- or Ctrl-Backspace
      if(*currentBuffer->currentLine==currentBuffer->head->next && currentBuffer->cursor.offset==0) {
        currentBuffer->lineUpdate.offset = -1;
        break;
      }
      moveLeft(&currentBuffer->cursor);
      //Continue on to delete

    case 330: //Delete
      if((*currentBuffer->currentLine)->next==currentBuffer->tail && currentBuffer->cursor.offset==(*currentBuffer->currentLine)->length-1) break;
      if(undoNow) Do(0);
      if((*currentBuffer->currentLine)->data[currentBuffer->cursor.offset]==9) (*currentBuffer->currentLine)->hasTabs--;
      x = ((*currentBuffer->currentLine)->data[currentBuffer->cursor.offset]=='\n');
      (*currentBuffer->currentLine)->length--;

      ptr = (*currentBuffer->currentLine)->data;
      memmove(ptr + currentBuffer->cursor.offset, ptr + currentBuffer->cursor.offset + 1, currentBuffer->cursor.l->length - currentBuffer->cursor.offset);
      (*currentBuffer->currentLine)->data = (unsigned char *)realloc((*currentBuffer->currentLine)->data, (*currentBuffer->currentLine)->length);

      currentBuffer->lineUpdate = currentBuffer->cursor;
      currentBuffer->lineUpdate.lineNum = currentBuffer->cursor.cursY;
      if(!((*currentBuffer->currentLine)->length%maxX)) currentBuffer->keepGoing=1;
      if(x) { connectLines(*currentBuffer->currentLine); currentBuffer->keepGoing=1; }
      currentBuffer->updated = 1;
      currentBuffer->cursor.wantCursX = currentBuffer->cursor.cursX;
      break;

    case 21: //Ctrl-U
      keyHit(262,undoNow); //Home
      for(x=(*currentBuffer->currentLine)->length;x;x--) {
        keyHit(330,undoNow); //Delete
      }
      break;

    case 11: //Ctrl-K
      if(currentBuffer->cursor.offset==(*currentBuffer->currentLine)->length - 1) {
        keyHit(330,undoNow);
        break;
      }
      x = currentBuffer->cursor.cursX;
      keyHit(360, undoNow); //End
      if(currentBuffer->cursor.l->data[currentBuffer->cursor.offset] != '\n') {
        keyHit(330, undoNow); //Delete
      }
      while(currentBuffer->cursor.cursX > x) {
        keyHit(263, undoNow); //Backspace
      }
      break;

    case 13: //Enter
      if(undoNow) Do(1);
      currentBuffer->updated = 1;
      currentBuffer->cursor.cursY++;
      currentBuffer->cursor.cursX = 0;
      currentBuffer->cursor.lineNum++;

      if(autoIndent) {
        for(t2=0;(*currentBuffer->currentLine)->data[t2]==9 && t2<currentBuffer->cursor.offset;t2++);
        for(t=t2;(*currentBuffer->currentLine)->data[t]==' ' && t<currentBuffer->cursor.offset;t++);
        t-=t2;
      }

      addLineAfter(*currentBuffer->currentLine, "");
      x = (*currentBuffer->currentLine)->length;

      ptr = (unsigned char *)malloc(x - currentBuffer->cursor.offset);
      memmove(ptr, (*currentBuffer->currentLine)->data + currentBuffer->cursor.offset, x - currentBuffer->cursor.offset);
      free((*currentBuffer->currentLine)->next->data);
      (*currentBuffer->currentLine)->next->data = ptr;
      (*currentBuffer->currentLine)->next->length = x - currentBuffer->cursor.offset;

      (*currentBuffer->currentLine)->data = (unsigned char *)realloc((*currentBuffer->currentLine)->data, currentBuffer->cursor.offset + 1);
      (*currentBuffer->currentLine)->length = currentBuffer->cursor.offset + 1;

      (*currentBuffer->currentLine)->data[(*currentBuffer->currentLine)->length - 1] = '\n';
      *currentBuffer->currentLine = (*currentBuffer->currentLine)->next;
      currentBuffer->cursor.offset = 0;
      countTabs(*currentBuffer->currentLine);
      countTabs((*currentBuffer->currentLine)->next);
      if(autoIndent) {
        for(;t2;t2--) keyHit(9, undoNow);
        for(;t;t--) keyHit(' ',undoNow);
      }
      currentBuffer->lineUpdate=currentBuffer->cursor;
      do {
        moveLeft(&currentBuffer->lineUpdate);
      } while(currentBuffer->lineUpdate.offset);
      do {
        moveLeft(&currentBuffer->lineUpdate);
      } while(currentBuffer->lineUpdate.offset);
      currentBuffer->lineUpdate.lineNum = currentBuffer->lineUpdate.cursY;
      currentBuffer->keepGoing=1;
      if(currentBuffer->cursor.cursY==maxY-1) scrollDown();
      currentBuffer->cursor.wantCursX = currentBuffer->cursor.cursX;
      break;

    default: //Anything that adds to the text
      if(undoNow) Do(1);
      currentBuffer->lineUpdate=currentBuffer->cursor;
      currentBuffer->lineUpdate.lineNum = currentBuffer->cursor.cursY;
      if(!((*currentBuffer->currentLine)->length % maxX)) currentBuffer->keepGoing = 1;

      if(keypress==9) //Tab
      {
        currentBuffer->cursor.cursX += tabWidth - 1 - (currentBuffer->cursor.cursX % tabWidth);
        (*currentBuffer->currentLine)->hasTabs++;
      }

      x = (*currentBuffer->currentLine)->length;

      (*currentBuffer->currentLine)->data = realloc((*currentBuffer->currentLine)->data, x + 1);
      memmove((*currentBuffer->currentLine)->data + currentBuffer->cursor.offset + 1, (*currentBuffer->currentLine)->data + currentBuffer->cursor.offset, x - currentBuffer->cursor.offset);
      (*currentBuffer->currentLine)->data[currentBuffer->cursor.offset] = (unsigned char)keypress;

      (*currentBuffer->currentLine)->length++;
      currentBuffer->cursor.offset++;
      currentBuffer->cursor.cursX++;
      if(currentBuffer->cursor.cursX>=maxX)
      {
        currentBuffer->cursor.cursX = 0;
        if(++currentBuffer->cursor.cursY>=maxY-1) scrollDown();
      }
      currentBuffer->cursor.wantCursX = currentBuffer->cursor.cursX;
      currentBuffer->updated = 1;
  }
}

void listChoice(int n, char **choices, char *answer, char *message)
{
  int start = 0;
  int end;
  int selected = 0;
  int t;
  int line;
  int keypress;
  char newName[256];
  int x,y;
  char focus = 0;

  newName[0] = '\0';

  while(1)
  {  
    for(y=0;y<maxY;y++)
      for(x=0;x<maxX;x++)
        mvaddch(y,x,' ');

    line = 0;
    end = (start + maxY - 1 >= n) ? n : start + maxY - 1;
    for(t=start;t<end;t++)
    {
      mvaddstr(line, 2, choices[t]);
      line++;
    }
    if(!focus) mvaddstr(selected - start, 0, "->");
    mvaddstr(maxY-1, 0, message);
    mvaddstr(maxY-1, strlen(message)+1, newName);

    keypress = getch();
    if(keypress == 258) { //Down
      focus = 0;
      if(selected < n-1) selected++;
      if(selected - start == maxY-1)
        start++;
    }
    else if(keypress == 259) { //Up
      focus = 0;
      if(selected) selected--;
      if(selected < start) start--;
    }
    else if(keypress == 13) { //Enter
      strcpy(answer, focus ? newName : choices[selected]);
      if(focus == 0 && selected == 0) //Special case, cancel
        strcpy(answer, "DAV_CANCEL");
      break;
    }
    else if(keypress == 263) { //Backspace
      focus = 1;
      if(strlen(newName) != 0)
        newName[strlen(newName) - 1] = '\0';
    }
    else if(keypress == 338) { //PgDn
      int t;
      focus = 0;
      for(t=0;t<maxY;t++) {
        if(selected < n-1) selected++;
        if(selected - start == maxY-1)
          start++;
      }
    }
    else if(keypress == 339) { //PgUp
      int t;
      focus = 0;
      for(t=0;t<maxY;t++) {
        if(selected) selected--;
        if(selected < start) start--;
      }
    }
    else if(keypress == 410) { //Window Resizing

    }
    else if(keypress == -1) { //Window Resizing
      getmaxyx(stdscr,maxY,maxX);
      free(lastDisplayed);
      lastDisplayed = (int *)malloc(maxY*sizeof(int));
      memset(lastDisplayed,0,maxY*sizeof(int));
      while(selected - start >= maxY-1)
        start++;
    }
    else {
      focus = 1;
      newName[strlen(newName) + 1] = '\0';
      newName[strlen(newName)] = keypress;
    }
  }

  for(y=0;y<maxY;y++)
    for(x=0;x<maxX;x++)
      mvaddch(y,x,' ');
}
/*
Copyright 2001-2003 David Gucwa

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <signal.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>
#include <sys/dir.h>

//#include "main.h"
//#include "buffers.h"
//#include "structs.h"
//#include "fileIO.h"
//#include "screenIO.h"
//#include "keyboard.h"
//#include "features.h"
//#include "undo.h"
//#include "move.h"

int maxY,maxX;
int helpBarUpdate=0;

char *version = "0.8.5";

/* Preferences and default values */
int maxUndoLength = 500;
char undoEnabled=1;
char autoIndent=1;
int numberOfBuffers = 10;
char bottomRowToggle = 1;
char bufferQuit = 0;
char tabWidth = 8;
char smartCursor = 1;
char optimize = 0;

int *lastDisplayed; //Number of characters last displayed on various lines
char displayWholeScreen = 0;

struct buffer *buffers;
struct buffer *currentBuffer;
int currentBufferNum = 0;


int main(int argc, char *argv[])
{
  int x,y;
  int keypress; 

  signal(2,sigcatch);

  Fn_ptr[0] = search;
  Fn_ptr[1] = save;
  Fn_ptr[2] = saveAs;
  Fn_ptr[3] = askLoad;
  Fn_ptr[4] = tryQuit;
  Fn_ptr[5] = Undo;
  Fn_ptr[7] = toggleAutoIndent;
  Fn_ptr[8] = tryCompile;
  Fn_ptr[9] = toggleBottomRow;
  loadSettings();

  if(numberOfBuffers > 100) numberOfBuffers = 100;  
  buffers = (struct buffer *)malloc(numberOfBuffers * sizeof(struct buffer));
  
  //Set up initial buffers
  for(x=0;x<numberOfBuffers;x++)
  {
    buffers[x].head = (struct line *)malloc(sizeof(struct line));
    buffers[x].tail = (struct line *)malloc(sizeof(struct line));
    buffers[x].head->next = buffers[x].tail;
    buffers[x].head->data = NULL;
    buffers[x].tail->prev = buffers[x].head;
    buffers[x].tail->next = buffers[x].tail;
    buffers[x].tail->data = NULL;
    buffers[x].tail->hasTabs = 0;

    currentBuffer = &buffers[x];
    addLineAfter(buffers[x].head, " ");

    buffers[x].cursor.l = buffers[x].head->next;
    buffers[x].cursor.offset = 0;
    buffers[x].cursor.lineNum = 0;
    buffers[x].topLine.l = buffers[x].head->next;
    buffers[x].topLine.offset = 0;
    buffers[x].topLine.lineNum = 0;
    buffers[x].topLine.cursX = buffers[x].topLine.cursY = 0;
    buffers[x].cursor.cursX = buffers[x].cursor.cursY = 0;
    buffers[x].cursor.wantCursX = 0;
    buffers[x].currentLine = &buffers[x].cursor.l;
    buffers[x].lineUpdate.offset = -1;

    buffers[x].numLines = 0;
    buffers[x].updated = 0;
    if(undoEnabled) buffers[x].undoMoves = (struct undoMove *)malloc(maxUndoLength*sizeof(struct undoMove));
    buffers[x].undoBufferPointer = buffers[x].undoBufferLength = 0;
  }

  currentBuffer = &buffers[0];
 
  initscr();
  cbreak();
  nonl();
  intrflush(stdscr, FALSE);
  keypad(stdscr, TRUE);
  getmaxyx(stdscr,maxY,maxX);
  for(x=0;x<maxX;x++)
    for(y=0;y<maxY;y++)
      mvaddch(y,x,' ');
  move(0,0);
  lastDisplayed = (int *)malloc(maxY*sizeof(int));

  if(argc>=2) doArguments(argc,argv);

  helpBar();
  showRow();
  
  while(1)
  {
    move(currentBuffer->cursor.cursY,currentBuffer->cursor.cursX);
    keypress=getch();
    keyHit(keypress,undoEnabled);
    displayScreen();
    showRow();
    if(helpBarUpdate)
    {
      helpBarUpdate--;
      if(!helpBarUpdate) helpBar();
    }
  }
  return 0;
}

void nothing()
{
  currentBuffer->lineUpdate.offset = -1;
}

void tryQuit()
{
  int t;
  if(!currentBuffer->updated) {
    if(!bufferQuit) quit("");
    else closeBuffer();
    return;
  }
  displayBottomRow();
  mvaddstr(maxY-1,0,"Save before quit? y/n/[C]");
  move(maxY-1,26);
  t = getch();
  mvaddch(maxY-1,26,' ');
  if(t=='y' || t=='Y') { 
    save(); 
    t = 'n';
  }
  if(t=='n' || t=='N') {
    if(!bufferQuit) quit("");
    else closeBuffer();
  }
  helpBarUpdate = 1;
  currentBuffer->lineUpdate.offset = -1;
}

void quit(char *text)
{
  struct line *l;
  int t;

  for(t=0;t<numberOfBuffers;t++) {
    if(t==currentBufferNum) continue;
    if(buffers[t].updated) {
      displayBottomRow();
      mvaddstr(maxY-1,0,"One or more buffers have not been saved. Quit? y/[N]");
      t = getch();
      if(t=='y' || t=='Y') {
        break;
      }
      else {
        helpBarUpdate = 1;
        return;
      }
    }
  } 

  for(t=0;t<maxX;t++) {
    mvaddch(maxY-1,t,' ');
  }
  nodelay(stdscr, TRUE);
  getch();
  endwin();
  
  if(undoEnabled) {
    for(t=0;t<numberOfBuffers;t++) {
      free(buffers[t].undoMoves);
    }
  }
  
  for(t=0;t<numberOfBuffers;t++) {
    l = buffers[t].head;
    while(l != buffers[t].tail) { 
      l=l->next; 
      if(l->prev->data) free(l->prev->data); 
      free(l->prev); 
    }  
    free(buffers[t].tail);
  }
  
  free(buffers);
  free(lastDisplayed);
  printf("%s",text);
  exit(0);
}

void doArguments(int argc, char *argv[])
{
  int x;
  char firstFile = 1;
  for(x=1;x<argc;x++)
  {
    if(argv[x][0]!='-') {
      /* Specifying a file name */
      if(!firstFile) {
        goToNextBuffer();
      }      
      load(argv[x]);
      firstFile = 0;
    } else { 
      /* Option */
      if(!strcmp(argv[x],"--help")) {
        displayHelp();
      } else if(!strcmp(argv[x],"--version")) {
        displayVersion();
      } else if(strstr(argv[x], "-l")!=NULL && isdigit(argv[x][2])) {
        gotoLine(atoi(&argv[x][2]));
      } else {
        /* Mistyped something */
        displayHelp();
      }
    }    
  }
  
  /* Go to first buffer */
  while (currentBuffer != &buffers[0]) {
    goToPrevBuffer();
  }
  
  displayScreen();
}

void displayVersion()
{
  char text[30];
  sprintf(text, "Dav version %s\n", version);
  quit(text);
}

void displayHelp()
{
  char *c = getenv("HOME");
  int t;
  endwin();
  printf("Dav v%s, written by David Gucwa\n",version);
  printf("Usage: dav [arguments] [FILENAME] [FILENAME] ...\n");
  printf("  where FILENAMEs, if specified, are the names of the files you wish to load.\n");
  printf("Arguments list:\n");
  printf("  --help : Display this help screen\n");
  printf("  --version: Display the version of Dav that you are running\n");
  printf("  -l#: Initialize Dav at a specific line number. (eg -l123)\n");
  printf("Basic commands:\n");
  for(t=0;t<12;t++)
  {
    if(!Fn_ptr[t] || Fn_ptr[t]==nothing)
      continue;
    printf("  F%i : ",t+1);
    if(Fn_ptr[t] == search)
      printf("Search\n");
    else if(Fn_ptr[t] == replace)
      printf("Find and replace\n");
    else if(Fn_ptr[t] == save)
      printf("Save current file\n");
    else if(Fn_ptr[t] == saveAs)
      printf("Save current file, prompt for filename\n");
    else if(Fn_ptr[t] == askLoad)
      printf("Load file from within Dav\n");
    else if(Fn_ptr[t] == tryQuit)
      printf("Quit (ask for save if needed)\n");
    else if(Fn_ptr[t] == Undo)
      printf("Undo last keypress\n");
    else if(Fn_ptr[t] == toggleAutoIndent)
      printf("Toggle auto-indenting\n");
    else if(Fn_ptr[t] == tryCompile)
      printf("Compile and print error messages\n");
    else if(Fn_ptr[t] == toggleBottomRow)
      printf("Toggle help bar\n");  
    else if(Fn_ptr[t] == goToNextBuffer)
      printf("Switch to next text buffer\n");
    else if(Fn_ptr[t] == goToPrevBuffer)
      printf("Switch to previous text buffer\n");  
    
  }
  printf("  Ctrl-C : Quit (won't ask for save)\n");
  printf("  Ctrl-K : Erase to end of line\n");
  printf("  Ctrl-U : Erase whole line\n");
  printf("Personal options:\n");
  printf("  Located in %s/.davrc\n",c);
  printf("Also edit %s/.davrc to customize function key bindings\n",c);
  initscr();
  quit("");
}

void loadSettings()
{
  int l;
  char s[80];
  char home[80];
  char *r;
  char *c;
  FILE *fp;
  int gotten=0;
  char FnGotten[12];
  for(l=0;l<12;l++)
    FnGotten[l] = 0;
  strcpy(home,getenv("HOME"));
  strcat(home,"/.davrc");
  fp = fopen(home,"r");
  if(fp==NULL) //File doesn't exist, make one
  {
    fp = fopen(home,"w");
    if(fp==NULL) { return; }
    writeRC(fp);
    fclose(fp);
    fp = fopen(home,"r");
  }
  //It's there, so read from it
  while(!feof(fp)) {
    fgets(s, 200, fp);
    if(s[0]=='#') continue;
    r = strtok(s," =");    
    c = strtok(NULL," =");
    if(c==NULL) continue;
    l = atoi(c);
    if(!strcmp(r,"Undo")) { undoEnabled = l; gotten|=1; }
    if(!strcmp(r,"UndoBuffer")) { maxUndoLength = l; gotten|=2; }
    if(!strcmp(r,"autoIndent")) { autoIndent = l; gotten|=4; }
    if(!strcmp(r,"helpBarInit")) { bottomRowToggle = l; gotten|=8; }
    if(!strcmp(r,"buffers")) { numberOfBuffers = l; gotten|=16; }
    if(!strcmp(r,"bufferQuit")) { bufferQuit = l; gotten|=32; }
    if(!strcmp(r,"tabWidth")) { tabWidth = l; gotten|=64; }
    if(!strcmp(r,"smartCursor")) { smartCursor = l; gotten|=128; }
    if(!strcmp(r,"optimize")) { optimize = l; gotten|=256; }
    if(r[0] == 'F')
    {
      c[strlen(c)-1]  = '\0';
      r++;
      l = atoi(r);
      l--;
      //Function key binding
      if(!strcmp(c, "SEARCH"))
      {
        Fn_ptr[l] = search;
        FnGotten[l] = 1;
      }
      else if(!strcmp(c, "SAVE"))
      {
        Fn_ptr[l] = save;
        FnGotten[l] = 2;
      }
      else if(!strcmp(c, "SAVE_AS"))
      {
        Fn_ptr[l] = saveAs;
        FnGotten[l] = 3;
      }
      else if(!strcmp(c, "LOAD"))
      {
        Fn_ptr[l] = askLoad;
        FnGotten[l] = 4;
      }
      else if(!strcmp(c, "QUIT"))
      {
        Fn_ptr[l] = tryQuit;
        FnGotten[l] = 5;
      }
      else if(!strcmp(c, "UNDO"))
      {
        Fn_ptr[l] = Undo;
        FnGotten[l] = 6;
      }
      else if(!strcmp(c, "COMPILE"))
      {
        Fn_ptr[l] = tryCompile;
        FnGotten[l] = 7;
      }
      else if(!strcmp(c, "TOGGLE_AUTOINDENT"))
      {
        Fn_ptr[l] = toggleAutoIndent;
        FnGotten[l] = 8;
      }
      else if(!strcmp(c, "TOGGLE_BOTTOM_ROW"))
      {
        Fn_ptr[l] = toggleBottomRow;
        FnGotten[l] = 9;
      }
      else if(!strcmp(c, "NOTHING"))
      {
        Fn_ptr[l] = nothing;
        FnGotten[l] = 10;
      }
      else if(!strcmp(c, "REPLACE"))
      {
        Fn_ptr[l] = replace;
        FnGotten[l] = 11;
      }
      else if(!strcmp(c, "PREV"))
      {
        Fn_ptr[l] = goToPrevBuffer;
        FnGotten[l] = 12;
      }
      else if(!strcmp(c, "NEXT"))
      {
        Fn_ptr[l] = goToNextBuffer;
        FnGotten[l] = 13;
      }
      else 
      {
        Fn_ptr[l] = nothing;
        FnGotten[l] = 0;
      }
    }
  }
  fclose(fp);
  for(l=0;l<12;l++)
  {
    if(FnGotten[l]==0)
      gotten = 0;
  }
  if(gotten!=511)
  {
    fp = fopen(home,"w");
    if(fp==NULL) return;
    writeRC(fp);
    fclose(fp);
  }
}

void writeRC(FILE *fp)
{
  int t;
  fprintf(fp,"#Set this to 1 if you want undoing enabled, otherwise set it to 0.\n");
  fprintf(fp,"#Having the undo feature enabled uses a little more processor power.\n");
  fprintf(fp,"Undo = %i\n\n",undoEnabled);
  fprintf(fp,"#This determines how big your undo buffer will be.\n");
  fprintf(fp,"#Actual memory usage in bytes is the following number times nine.\n");
  fprintf(fp,"UndoBuffer = %i\n\n",maxUndoLength);
  fprintf(fp,"#Set this to 1 if you want auto indenting enabled, otherwise set it to 0.\n");
  fprintf(fp,"#If auto indent is enabled, new lines will be indented.\n");
  fprintf(fp,"autoIndent = %i\n\n",autoIndent);
  fprintf(fp,"#This line will determine whether the help bar is enabled by default.\n");
  fprintf(fp,"#You can toggle it any time by hitting F10 inside Dav.\n");
  fprintf(fp,"helpBarInit = %i\n\n",bottomRowToggle);
  fprintf(fp,"#How many text buffers will Dav use?\n");
  fprintf(fp,"#The default value is 10. The maximum is 100.\n");
  fprintf(fp,"buffers = %i\n\n",numberOfBuffers);
  fprintf(fp,"#0 = QUIT function exits Dav\n");
  fprintf(fp,"#1 = QUIT function closes only the current buffer\n");
  fprintf(fp,"#    (If there are no more buffers left, it will exit Dav)\n");
  fprintf(fp,"bufferQuit = %i\n\n",bufferQuit);
  fprintf(fp,"#Tab width (default value is 8)\n");
  fprintf(fp,"tabWidth = %i\n\n",tabWidth);
  fprintf(fp,"#SmartCursor controls whether the cursor will try to stay on the same column\n");
  fprintf(fp,"#during up/down movement between lines of varying widths.\n");
  fprintf(fp,"smartCursor = %i\n\n",smartCursor);
  fprintf(fp,"#Optimize controls whether Dav is optimized for memory or cpu efficiency.\n");
  fprintf(fp,"#Right now this is only used for sorting directories by filename.\n");
  fprintf(fp,"#Default value is 0. If you notice lag in the load/save dialogue, you may\n");
  fprintf(fp,"# want to change it to 1.\n");
  fprintf(fp,"#0 = Optimized for memory efficiency (uses quicksort)\n");
  fprintf(fp,"#1 = Optimized for cpu efficiency (uses radix sort)\n");
  fprintf(fp,"optimize = %i\n\n",optimize);  
  fprintf(fp,"#Function Key definitions:\n");
  fprintf(fp,"#  SEARCH : Search the file for a string\n");
  fprintf(fp,"#  REPLACE : Find and replace strings\n");
  fprintf(fp,"#  SAVE : Saves current file\n");
  fprintf(fp,"#  SAVE_AS : Saves current file, prompts for filename first\n");
  fprintf(fp,"#  LOAD : Load a different file\n");
  fprintf(fp,"#  QUIT : Exits out of Dav\n");
  fprintf(fp,"#  UNDO : Undoes your last action\n");
  fprintf(fp,"#  COMPILE : Runs a Makefile and displays error messages\n");
  fprintf(fp,"#  TOGGLE_AUTOINDENT : Toggles auto indenting\n");
  fprintf(fp,"#  TOGGLE_BOTTOM_ROW : Switches between displaying Fn bindings and file name\n");
  fprintf(fp,"#  PREV : Switches to the previous text buffer (of 10)\n");
  fprintf(fp,"#  NEXT : Switches to the next text buffer (of 10)\n");
  for(t=0;t<12;t++)
  {
    fprintf(fp,"F%i = ", t+1);
    if(Fn_ptr[t] == search)
      fprintf(fp,"SEARCH\n");
    else if(Fn_ptr[t] == save)
      fprintf(fp,"SAVE\n");
    else if(Fn_ptr[t] == saveAs)
      fprintf(fp,"SAVE_AS\n");
    else if(Fn_ptr[t] == askLoad)
      fprintf(fp,"LOAD\n");
    else if(Fn_ptr[t] == tryQuit)
      fprintf(fp,"QUIT\n");
    else if(Fn_ptr[t] == Undo)
      fprintf(fp,"UNDO\n");
    else if(Fn_ptr[t] == tryCompile)
      fprintf(fp,"COMPILE\n");
    else if(Fn_ptr[t] == toggleAutoIndent)
      fprintf(fp,"TOGGLE_AUTOINDENT\n");
    else if(Fn_ptr[t] == toggleBottomRow)
      fprintf(fp,"TOGGLE_BOTTOM_ROW\n");
    else if(Fn_ptr[t] == replace)
      fprintf(fp,"REPLACE\n");
    else if(Fn_ptr[t] == goToNextBuffer)
      fprintf(fp,"NEXT\n");
    else if(Fn_ptr[t] == goToPrevBuffer)
      fprintf(fp,"PREV\n");
    else fprintf(fp,"NOTHING\n");
  }
}

void addLineAfter(struct line *whichLine, char *data)
{
  struct line *temp = whichLine->next;
  struct line *newLine = (struct line *)malloc(sizeof(struct line));
  temp->prev = newLine;
  whichLine->next = newLine;
  newLine->next = temp;
  newLine->prev = whichLine;
  newLine->data = (unsigned char *)malloc(strlen(data));
  strcpy(newLine->data, data);
  newLine->length = strlen(data);
  countTabs(newLine);
  currentBuffer->numLines++;
}

char positionDown(struct position *p) {
  /*
  Returns 0 upon normal movement
  Returns 1 if the position stayed on the same line (end of file)
  */
  
  int tempX = p->cursX;
  char temp = 0;
  
  while(!temp) {
    /* 
    Move the cursor right until it wraps to the next line.
    If it hits the end of the file, return 1 instead.
    */
    
    temp = moveRight(p);
    if(temp==1) {
      return 1;
    }
  }
  while(1) {
    /* Move the cursor right until it hits the correct location. */
    
    if(p->cursX >= tempX) {
      return 0;
    } else if(p->offset == p->l->length - 1) {
      return 0;
    }
    
    temp = moveRight(p);
    if(temp == 1) {
      return 0;
    } else if(temp > 1) {
      moveLeft(p);
      return 0;
    }
  }
}

char positionUp(struct position *p)
{
  /*
  Returns 0 upon normal movement
  Returns 1 if the position stayed on the same line (beginning of file)
  */

  int tempX = p->cursX;
  char temp=0;
  while(!temp) {
    temp = moveLeft(p);
    if(temp==1) {
      if(p == &currentBuffer->cursor) {
        currentBuffer->cursor.wantCursX = currentBuffer->cursor.cursX;
      }
      return 1;
    }
  }
  while(1) {
    if(p->cursX <= tempX) {
      return 0;
    }
    temp = moveLeft(p);
    if(temp == 1) {
      return 0;
    } else if(temp > 1) {
      moveRight(p);
      return 0;
    }
  }
}

void connectLines(struct line *baseline)
{
  struct line *l = baseline->next;
  unsigned char *ptr = (unsigned char *)malloc(baseline->length + l->length);
  memmove(ptr, baseline->data, baseline->length);
  memmove(ptr+baseline->length, l->data, l->length);
  free(baseline->data);
  baseline->data = ptr;
  baseline->length += l->length;
  baseline->next = l->next;
  l->next->prev = baseline;
  baseline->hasTabs += l->hasTabs;
  free(l->data);
  free(l);
  currentBuffer->numLines--;
}

void determineLineNum(struct position *p)
{
  struct position temp;
  int cX=p->cursX,cY=p->cursY;

  temp.l = currentBuffer->head->next;
  temp.offset = 0;
  temp.lineNum = 0;
  while(temp.l != p->l)
    positionDown(&temp);

  while(temp.offset+maxX <= p->offset)
    positionDown(&temp);

  p->lineNum = temp.lineNum;
  p->cursX=cX;
  p->cursY=cY;
}

void countTabs(struct line *l)
{
  int t;
  l->hasTabs = 0;
  for(t=l->length-1;t>=0;t--)
    if(l->data[t]==9) l->hasTabs++;
}

void determineCursX(struct position *p)
{
  struct position temp;
  unsigned char c;
  
  temp.l = p->l;
  temp.offset = 0;
  temp.cursX = 0;
  while(p->offset!=temp.offset)
  {
    c = temp.l->data[temp.offset];
    temp.offset++;
    if(c!=9)    
      temp.cursX++;
    else
      temp.cursX+= tabWidth - (temp.cursX % tabWidth); 
    if(temp.cursX >= maxX) temp.cursX=0;
  }  
  p->cursX = temp.cursX;
} 

void logMsg(char *msg) {
  char text[256];
  sprintf(text, "echo \"%s\" >> log", msg);
  system(text);
}

void sigcatch() {
  quit("");
}

void radixSort(char **strings, int number) {
  char **buckets[256];
  int numberInBuckets[256];
  int radix = 0;
  int t;
  int i,j;
  
  for(i=0; i<256; i++) {
    buckets[i] = (char **)malloc(0*sizeof(char *));
  }

  for(radix=255; radix>=0; radix--) {
    for(t=0; t<256; t++) {
      numberInBuckets[t] = 0;
    }
    
    for(t=0; t<number; t++) {
      int bucket = (int)((unsigned char)strings[t][radix]);
      buckets[bucket] = realloc(buckets[bucket], (numberInBuckets[bucket] + 1)*sizeof(char *));
      buckets[bucket][numberInBuckets[bucket]] = strings[t];
      numberInBuckets[bucket]++;
    }
    
    t = 0;
    for(i=0; i<256; i++) {
      for(j=0; j<numberInBuckets[i]; j++) {
        strings[t] = buckets[i][j];
        t++;
      }
    }
  }
  
  for(i=0; i<256; i++) {
    free(buckets[i]);
  }
}

void randomizedQuickSort(char **strings, int low, int high) {
  //Pick a random element
  int axis;
  int oldLow = low;
  int oldHigh = high;
  char *temp;
  
  if (low >= high) { //Zero or one element
    return;
  }
  
  if (high - low == 1) { //Only two elements
    if (strcmp(strings[high], strings[low]) < 0) {
      temp = strings[high];
      strings[high] = strings[low];
      strings[low] = temp;
    }
    return;
  }
  
  //Swap axis element with last element
  axis = (rand() % (high - low + 1)) + low;
  temp = strings[axis];
  strings[axis] = strings[high];
  strings[high] = temp;
  axis = high;
  high--;
  
  while (1) {
    while (strcmp(strings[low], strings[axis]) <= 0 && low < high) {
      low++;
    }
    
    while (strcmp(strings[high], strings[axis]) >= 0 && low < high) {
      high--;
    }
    
    if (low >= high) {
      break;
    }
    
    temp = strings[low];
    strings[low] = strings[high];
    strings[high] = temp;
  }

  if (strcmp(strings[low], strings[axis]) < 0) {
    low++;
  }  
  temp = strings[axis];
  strings[axis] = strings[low];
  strings[low] = temp;
  
  randomizedQuickSort(strings, oldLow, low-1);
  randomizedQuickSort(strings, low+1, oldHigh);
}
/*
Copyright 2001-2003 David Gucwa

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/
//#include "move.h"
//#include "main.h"

void moveDown(struct position *p) {
  positionDown(p);
  if(p->cursY==maxY-1 && p==&currentBuffer->cursor) { 
    scrollDown(); 
  }
}

void moveUp(struct position *p) {
  positionUp(p);
  if(p->cursY==-1 && p==&currentBuffer->cursor) { 
    scrollUp(); 
  }
}

char moveLeft(struct position *p) {
  /*
  Returns 0 upon normal movement
  Returns 1 if the position could not be moved left
  Returns 2 if moving left caused the position to enter the previous line
  Returns 3 if moving left caused the position to wrap on the same line
  */
  
  char r = 0;
  if(p->l == currentBuffer->head->next && p->offset == 0) {
    /* Beginning of file */
    return 1;
  }
  if(!p->offset) {
  /* Beginning of line */
    p->l = p->l->prev;
    p->offset = p->l->length - 1;
    if(p->l->hasTabs) {
      determineCursX(p);
    }
    else {
      p->cursX = p->offset % maxX;
    }
    p->cursY--;
    p->lineNum--;
    r = 2;
  }
  else {
    p->offset--;
    if(!p->cursX) {
      r = 3;
      p->cursY--;
      if(p->l->hasTabs) {
        determineCursX(p);
      }
      else {
        p->cursX = maxX - 1;
      }
    }
    else {
      if(p->l->hasTabs)
        determineCursX(p);
      else
        p->cursX--;
    }

  }
  if(p->cursY==-1 && p==&currentBuffer->cursor) { 
    scrollUp(); 
  }
  return r;
}

char moveRight(struct position *p) {
  /* 
  Returns 0 upon normal movement
  Returns 1 if the position could not be moved right (end of file)
  Returns 2 if moving right caused the position to enter the next line
  Returns 3 if moving right caused the position to wrap on the same line
  */

  char r=0;
  if(p->l->next == currentBuffer->tail && p->offset == p->l->length-1) {
    /* End of file */
    return 1;
  }
  
  if(p->offset < p->l->length - 1) {
    /* Normal movement */
    int temp = p->cursX;
    p->offset++;
    if (p->l->hasTabs) {
      determineCursX(p);
    } else {
      p->cursX++;
      if (p->cursX == maxX) {
        p->cursX=0;
      }
    }
    if (p->cursX < temp) {
      p->cursY++;
      r = 3;
    }
  }
  else {
    /* Next line */
    p->l = p->l->next;
    p->cursX = p->offset = 0;
    p->cursY++;
    p->lineNum++;
    r = 2; //Hit a new line
  }
  if(p->cursY == maxY-1 && p==&currentBuffer->cursor) { 
    scrollDown(); 
  }
  return r;
}

char scrollDown()
{
  /* Returns 1 if the screen did not scroll down */

  if(currentBuffer->topLine.lineNum + (maxY>>1) > currentBuffer->numLines) {
    return 1;
  }

  if(currentBuffer->cursor.cursY==0) {
    positionDown(&currentBuffer->cursor);
  }

  if(!positionDown(&currentBuffer->topLine)) {
    currentBuffer->cursor.cursY--;
  }

  currentBuffer->lineUpdate = currentBuffer->topLine;
  currentBuffer->lineUpdate.lineNum = 0;
  currentBuffer->keepGoing = 1;
  return 0;
}

char scrollUp()
{
  /* Returns 1 if the screen did not scroll up */
  if(currentBuffer->cursor.cursY==maxY-1) {
    positionUp(&currentBuffer->cursor);
  }
  
  if(!positionUp(&currentBuffer->topLine)) {
    currentBuffer->cursor.cursY++;
  }
  
  currentBuffer->lineUpdate = currentBuffer->topLine;
  currentBuffer->lineUpdate.lineNum = 0;
  currentBuffer->keepGoing = 1;
  return 0;
}
/*
Copyright 2001-2003 David Gucwa

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/
#include <ncurses.h>
#include <string.h>

//#include "screenIO.h"
//#include "main.h"
//#include "fileIO.h"
//#include "features.h"
//#include "buffers.h"
//#include "undo.h"
//#include "move.h"

void displayLine(int line, struct position *pos) {
  int ch;
  unsigned char *data = pos->l->data + pos->offset;
  int length = pos->l->length;
  unsigned char *end = pos->l->data + length;   
  int screenX = 0;
  
  if(pos->l != currentBuffer->tail) {
    while(1) {
      ch = *data++;
      if(ch==9) { 
        /* Tab */
        while((screenX % tabWidth) != tabWidth-1) {
          mvaddch(line, screenX++, ' ');
        }
      }
      mvaddch(line, screenX, ch);
      if (screenX++ >= maxX || data==end) { 
        screenX--; 
        break; 
      }
    }
  }

  length = lastDisplayed[line];
  lastDisplayed[line] = screenX;
  while (screenX<length) {
    mvaddch(line, screenX++, ' ');
  }
  
}

void displayScreen() {
  int lineNum = currentBuffer->lineUpdate.lineNum;

  if(currentBuffer->lineUpdate.offset == -1) {
    return;
  }
  
  if (displayWholeScreen) {
    int i;
    for (i=0; i<maxY; i++) {
      lastDisplayed[i] = maxX;
    }
    displayWholeScreen = 0;
  }
  
  while(currentBuffer->lineUpdate.cursX) {
    moveLeft(&currentBuffer->lineUpdate);
  }

  do {
    displayLine(lineNum++, &currentBuffer->lineUpdate);
  } while(!positionDown(&currentBuffer->lineUpdate) && currentBuffer->lineUpdate.cursY<maxY-1);
  
  if(currentBuffer->keepGoing) {
    while(lineNum<maxY-1) {
      displayLine(lineNum, &currentBuffer->lineUpdate);
      if(positionDown(&currentBuffer->lineUpdate)==1) {
        currentBuffer->lineUpdate.l = currentBuffer->tail;
      }
      lineNum++;
    }
  }
  
  currentBuffer->keepGoing = 0;
}

void showRow() {
  char num[5];
  char total[5];
  int t;
  num[0] = ((currentBuffer->cursor.lineNum+1)/10000) % 10 + 48;
  num[1] = ((currentBuffer->cursor.lineNum+1)/1000) % 10 + 48;
  num[2] = ((currentBuffer->cursor.lineNum+1)/100) % 10 + 48;
  num[3] = ((currentBuffer->cursor.lineNum+1)/10) % 10 + 48;
  num[4] = (currentBuffer->cursor.lineNum+1) % 10 + 48;

  total[0] = ((currentBuffer->numLines+1)/10000) % 10 + 48;
  total[1] = ((currentBuffer->numLines+1)/1000) % 10 + 48;
  total[2] = ((currentBuffer->numLines+1)/100) % 10 + 48;
  total[3] = ((currentBuffer->numLines+1)/10) % 10 + 48;
  total[4] = (currentBuffer->numLines+1) % 10 + 48;
  for (t=0; t<4; t++) { 
    if(num[t]==48) { 
      num[t]=' ';
    } else {
      break; 
    }
  }
  for (t=0; t<4; t++) { 
    if(total[t]==48) {
      total[t]=' '; 
    } else {
      break;
    }
  }
  mvaddstr(maxY-1,maxX-11,num);
  mvaddch(maxY-1,maxX-6,'/');
  mvaddstr(maxY-1,maxX-5,total);
}

void helpBar() {
  char c[200];
  char *ptr = c;
  int t;
  displayBottomRow();
  
  if(bottomRowToggle) {
    strcpy(ptr,"F|");
    ptr += 2;
    for(t=0;t<12;t++)
    {
      if(t<=8)
        *ptr++ = t + '1';
      else
      {
        *ptr++ = '1';
        *ptr++ = t + '1' - 10;
      }
      *ptr++ = ':';
      if(Fn_ptr[t] == search) { 
        strcpy(ptr, "Search");
        ptr+=6; 
      } else if(Fn_ptr[t] == save) {
        strcpy(ptr, "Save");
        ptr+=4; 
      } else if(Fn_ptr[t] == saveAs) {
        strcpy(ptr, "SaveAs");
        ptr+=6; 
      } else if(Fn_ptr[t] == askLoad) {
        strcpy(ptr, "Load");
        ptr+=4; 
      } else if(Fn_ptr[t] == tryQuit) {
        strcpy(ptr, "Quit");
        ptr+=4; 
      } else if(Fn_ptr[t] == Undo) {
        strcpy(ptr, "Undo");
        ptr+=4; 
      } else if(Fn_ptr[t] == tryCompile) {
        strcpy(ptr, "Compile");
        ptr+=7; 
      } else if(Fn_ptr[t] == toggleAutoIndent) { 
        strcpy(ptr, "AutoIndent");
        ptr+=10; 
      } else if(Fn_ptr[t] == toggleBottomRow) { 
        strcpy(ptr, "BottomRow");
        ptr+=9; 
      } else if(Fn_ptr[t] == replace) { 
        strcpy(ptr, "Replace");
        ptr+=7; 
      } else if(Fn_ptr[t] == goToNextBuffer) { 
        strcpy(ptr, "Next");
        ptr+=4; 
      } else if(Fn_ptr[t] == goToPrevBuffer) { 
        strcpy(ptr, "Prev");
        ptr+=4; 
      } else if(Fn_ptr[t] == nothing) { 
        ptr-=3; 
      }
      *ptr++ = '|';
    }
    *ptr = '\0';
    mvaddnstr(maxY-1,0,c,maxX-1);
  } else {
    char temp[3];
    temp[0] = (currentBufferNum / 10) + '0';
    temp[1] = (currentBufferNum % 10) + '0';
    temp[2] = '\0';
    strcpy(c,"Editing ");
    strcat(c,currentBuffer->fname);
    strcat(c," [");
    if(currentBufferNum >= 10) {
      strcat(c,temp);
    } else {
      strcat(c,temp+1);
    }
    strcat(c,"]");
    mvaddstr(maxY-1,0,c);
  }
  showRow();
}

void displayBottomRow() {
  int x;
  for(x=maxX-12; x; x--) {
    mvaddch(maxY-1, x, ' ');
  }
}
/*
Copyright 2001-2003 David Gucwa

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/
//#include "undo.h"
//#include "main.h"
//#include "keyboard.h"
//#include "move.h"

void Do(int keypress)
{
  switch(keypress)
  {
    case 0:
      addToUndo((int)currentBuffer->cursor.l->data[currentBuffer->cursor.offset]);
      break;

    case 1:
      addToUndo(0);
      break;

    default:
      break;
  }
}  

void addToUndo(int keypress)
{
  currentBuffer->undoMoves[currentBuffer->undoBufferPointer].c = keypress;
  currentBuffer->undoMoves[currentBuffer->undoBufferPointer].line = currentBuffer->cursor.lineNum;
  currentBuffer->undoMoves[currentBuffer->undoBufferPointer].offset = currentBuffer->cursor.offset;
  currentBuffer->undoBufferPointer++;
  currentBuffer->undoBufferPointer %= maxUndoLength;
  if(++currentBuffer->undoBufferLength>maxUndoLength) currentBuffer->undoBufferLength--;
}

void Undo()
{
  int key;
  if(!undoEnabled) return;
  if(currentBuffer->undoBufferLength==0) return;
  currentBuffer->undoBufferLength--;
  if(--currentBuffer->undoBufferPointer == -1) currentBuffer->undoBufferPointer=maxUndoLength-1;
  key = (int)currentBuffer->undoMoves[currentBuffer->undoBufferPointer].c;
  while(currentBuffer->cursor.lineNum > currentBuffer->undoMoves[currentBuffer->undoBufferPointer].line)
    moveUp(&currentBuffer->cursor);
  while(currentBuffer->cursor.lineNum < currentBuffer->undoMoves[currentBuffer->undoBufferPointer].line)
    moveDown(&currentBuffer->cursor);
  while(currentBuffer->cursor.offset < currentBuffer->undoMoves[currentBuffer->undoBufferPointer].offset)
    moveRight(&currentBuffer->cursor);
  while(currentBuffer->cursor.offset > currentBuffer->undoMoves[currentBuffer->undoBufferPointer].offset)
    moveLeft(&currentBuffer->cursor);

  if(key=='\n') key=13;
  if(key == 0) key = 330;
  keyHit(key,0);
  currentBuffer->lineUpdate = currentBuffer->topLine;
  currentBuffer->lineUpdate.lineNum = 0;
  currentBuffer->keepGoing = 1;
}
