#ifndef FILESTREAM_H
#define FILESTREAM_H

// C
#include <stdio.h>

// CUT
#include <oop.h>
#include <charstream.h>

#define TYPENAME FileStream

OBJECT (FILE *file) INHERIT (CharStream)
END_OBJECT(stdin);

void _(Close)()      VIRTUAL (Close);
int  _(Peek) ()      VIRTUAL (Peek);
int  _(Get)  ()      VIRTUAL (Get);
void _(Unget)(int c) VIRTUAL (Unget);
void _(Put)  (int c) VIRTUAL (Put);

#undef TYPENAME
#endif
