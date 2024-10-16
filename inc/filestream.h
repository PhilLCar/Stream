#ifndef FILESTREAM_H
#define FILESTREAM_H

// C
#include <stdio.h>

// CUT
#include <oop.h>
#include <charstream.h>

#define TYPENAME FileStream

OBJECT (FILE *file) INHERIT (CharStream)
END(stdin);

void  _(close)()            VIRTUAL (close);
void *_(peek) ()            VIRTUAL (peek);
void *_(get)  ()            VIRTUAL (get);
void  _(unget)(void *token) VIRTUAL (unget);
void  _(put)(void *token)   VIRTUAL (put);

#undef TYPENAME
#endif
