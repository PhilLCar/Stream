#ifndef CHARSTREAM_H
#define CHARSTREAM_H

//C
#include <stdio.h>
#include <stdlib.h>

// CUT
#include <stream.h>
#include <diagnostic.h>
#include <macro.h>
#include <oop.h>

#define TYPENAME CharStream

// (!) This class must always be initialized using the NEW macro
OBJECT (void *stream) INHERIT (Stream)
END_OBJECT(NULL);

int  _(Peek)();
int  _(Get)();
void _(Unget)(int c);
void _(Put)(int c);

int  _(Escape)();
int  _(Read)();
int  _(ReadWith)(int escape);
void _(Write)(int c);
void _(WriteWith)(int escape, int c);

// Puts the line as is
void    _(PutStr)(const char *line);
// Puts the line and generates escape sequences based on the specified escape char
void    _(WriteStr)(const char *line);

// Puts the line as is
void    _(PutLn)(const char *line);
// Puts the line and generates escape sequences based on the specified escape char
void    _(WriteLn)(const char *line);

int CONST (EOS)();

#undef TYPENAME
#endif