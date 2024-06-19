#ifndef STREAM_H
#define STREAM_H

//C
#include <stdio.h>
#include <stdlib.h>

// CUT
#include <diagnostic.h>
#include <macro.h>
#include <oop.h>

#define TYPENAME Stream

OBJECT (void *stream, const char *typename) INHERIT (void*)
  const int  (*getc)  (void*);
  const int  (*peek)  (void*);
  const void (*ungetc)(void*, int);
  const void (*close) (void*);

  int eos;
END_OBJECT;

#define FROM_STREAM \
__attribute((unused)) static Stream *EXPAND3(from, TYPENAME, Stream)(EXPAND2(TYPENAME, Stream) *stream) {\
  return NEW (Stream) (stream, STRINGIZE(TYPENAME));\
}

#define FROM_OBJECT \
__attribute((unused)) static Stream *EXPAND2(from, TYPENAME)(TYPENAME *base) {\
  return EXPAND3(from, TYPENAME, Stream)(EXPAND2(TYPENAME, _open)(base));\
}

#define STREAMABLE \
typedef struct {\
  EXPAND(TYPENAME) *base;\
  int               pos;\
} EXPAND2(TYPENAME, Stream);\
\
EXPAND2(TYPENAME, Stream) *EXPAND2(TYPENAME, _open  )(EXPAND(TYPENAME) *base);\
void                       EXPAND2(TYPENAME, _close )(EXPAND2(TYPENAME, Stream) *stream)        VIRTUAL (close);\
int                        EXPAND2(TYPENAME, _getc  )(EXPAND2(TYPENAME, Stream) *stream)        VIRTUAL (getc);\
void                       EXPAND2(TYPENAME, _ungetc)(EXPAND2(TYPENAME, Stream) *stream, int c) VIRTUAL (ungetc);\
int                        EXPAND2(TYPENAME, _peek  )(EXPAND2(TYPENAME, Stream) *stream)        VIRTUAL (peek);\
\
EXPAND(FROM_STREAM)\
EXPAND(FROM_OBJECT)

void _(close)();
int  _(getc)();
void _(ungetc)(char c);
int  _(peek)();
int  _(esc)();
#undef TYPENAME

// Shortnames
__attribute((unused)) static void (*sclose) (Stream*)       = Stream_close;
__attribute((unused)) static int  (*sgetc)  (Stream*)       = Stream_getc;
__attribute((unused)) static void (*sungetc)(Stream*, char) = Stream_ungetc;
__attribute((unused)) static int  (*speek)  (Stream*)       = Stream_peek;
__attribute((unused)) static int  (*sesc)   (Stream*)       = Stream_esc;
#endif