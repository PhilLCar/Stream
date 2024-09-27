#ifndef FILESTREAM_H
#define FILESTREAM_H

// C
#include <stdio.h>

// CUT
#include <charstream.h>
#include <oop.h>

#define TYPENAME FileStream

OBJECT (const char *filename, const char *mode) INHERIT (CharStream)
END("", "");

void  _(close)()            VIRTUAL (close);
void *_(peek) ()            VIRTUAL (peek);
void *_(get)  ()            VIRTUAL (get);
void  _(unget)(void *token) VIRTUAL (unget);

#undef TYPENAME
#endif
