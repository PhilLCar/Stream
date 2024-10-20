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

void           _(close)()                     VIRTUAL (close);
DirectoryItem *_(peek) ()                     VIRTUAL (peek);
DirectoryItem *_(get)  ()                     VIRTUAL (get);
void           _(unget)(DirectoryItem *token) VIRTUAL (unget);
void           _(put)  (DirectoryItem *token) VIRTUAL (put);

#undef TYPENAME
#endif
