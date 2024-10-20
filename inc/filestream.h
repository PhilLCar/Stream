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

void _(close)()      VIRTUAL (close);
int  _(peek) ()      VIRTUAL (peek);
int  _(get)  ()      VIRTUAL (get);
void _(unget)(int c) VIRTUAL (unget);
void _(put)  (int c) VIRTUAL (put);

#undef TYPENAME
#endif
