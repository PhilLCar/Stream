#ifndef PROCESSSTREAM_H
#define PROCESSSTREAM_H

// C
#include <stdio.h>

// CUT
#include <diagnostic.h>
#include <oop.h>
#include <charstream.h>

#define TYPENAME ProcessStream

OBJECT (FILE *stream) INHERIT (CharStream)
END_OBJECT(NULL);

ProcessStream *STATIC (Open)(const char *command, AccessModes mode);

void _(Close)()      VIRTUAL (Close);
int  _(Peek) ()      VIRTUAL (Peek);
int  _(Get)  ()      VIRTUAL (Get);
void _(Unget)(int c) VIRTUAL (Unget);
void _(Put)  (int c) VIRTUAL (Put);

#undef TYPENAME
#endif
