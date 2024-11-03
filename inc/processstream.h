#ifndef PROCESSSTREAM_H
#define PROCESSSTREAM_H

// C
#include <stdio.h>

// CUT
#include <oop.h>
#include <charstream.h>

#define TYPENAME ProcessStream

OBJECT (const char *command, int read) INHERIT (CharStream)
END_OBJECT("exit", 0);

void _(Close)()      VIRTUAL (Close);
int  _(Peek) ()      VIRTUAL (Peek);
int  _(Get)  ()      VIRTUAL (Get);
void _(Unget)(int c) VIRTUAL (Unget);
void _(Put)  (int c) VIRTUAL (Put);

#undef TYPENAME
#endif
