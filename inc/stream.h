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

OBJECT (void*,
        const int(*)(void*),
        const int(*)(void*), 
        const void(*)(int, void*),
        const void(*)(void*)) INHERIT (void*)

  const int  (*getc)(void*);
  const int  (*peek)(void*);
  const void (*ungetc)(int, void*);
  const void (*close)(void*);
  int    eos;
END_OBJECT;

#define FROM_STREAM(TYPESTREAM, TAG) \
__attribute__((unused)) static Stream *EXPAND2(from, TYPESTREAM)(TYPESTREAM *stream) {\
  return NEW (Stream) ((void*) stream, \
                       (const int(*)(void*))TAG ## getc, \
                       (const int(*)(void*))TAG ## peek, \
                       (const void(*)(int, void*))TAG ## ungetc, \
                       (const void(*)(void*))TAG ## close);\
}

#define STREAMABLE(TAG) typedef struct {\
  EXPAND(TYPENAME) *base;\
  int   pos;\
} EXPAND2(TYPENAME, Stream);\
EXPAND2(TYPENAME, Stream) *TAG ## open(EXPAND(TYPENAME) *base);\
void TAG ## close(EXPAND2(TYPENAME, Stream) *TAG);\
int TAG ## getc(EXPAND2(TYPENAME, Stream) *TAG);\
int TAG ## peek(EXPAND2(TYPENAME, Stream) *TAG);\
void TAG ## ungetc(int c, EXPAND2(TYPENAME, Stream) *TAG);\
FROM_STREAM(EXPAND2(TYPENAME, Stream), TAG)

int  _(peek)();
int  _(getc)();
void _(ungetc)(char c);
void _(close)();
int  _(esc)();
#undef TYPENAME
#endif