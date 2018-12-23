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
