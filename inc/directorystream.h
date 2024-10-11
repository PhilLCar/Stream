#ifndef DIRECTORYSTREAM_H
#define DIRECTORYSTREAM_H

// C
#include <stdio.h>

// CUT
#include <directory.h>
#include <oop.h>
#include <stream.h>

#define TYPENAME DirectoryStream

OBJECT (const char *directory) INHERIT (Stream)
END(".");

void  _(close)()            VIRTUAL (close);
void *_(peek) ()            VIRTUAL (peek);
void *_(get)  ()            VIRTUAL (get);
void  _(unget)(void *token) VIRTUAL (unget);
void  _(put)(void *token)   VIRTUAL (put);

#undef TYPENAME
#endif
