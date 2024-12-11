#ifndef CHARSTREAM_H
#define CHARSTREAM_H

//C
#include <stdio.h>
#include <stdlib.h>

// CUT
#include <diagnostic.h>
#include <str.h>
#include <stream.h>
#include <macro.h>
#include <oop.h>

// Abstract class
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

int CONST (EOS)();

// Puts the line as is
void    _(PutStr)(const char *line);
// Puts the line and generates escape sequences based on the specified escape char
void    _(WriteStr)(const char *line);

// Puts the line as is
void    _(PutLn)(const char *line);
// Puts the line and generates escape sequences based on the specified escape char
void    _(WriteLn)(const char *line);

// Gets the line as is
String *_(GetLine)();

// Gets the line and interprets what's after the escape char
String *_(ReadLine)();

// Gets and consume the stream
String *_(GetToEnd)();

// Reads and consume the stream
String *_(ReadToEnd)();

// Puts and consume the string
void _(PutString)(void *object);

// Writes and consume the string
void _(WriteString)(void *object);

// Puts line and consume the string
void _(PutLine)(void *object);

// Writes line and consume the string
void _(WriteLine)(void *object);


#undef TYPENAME
#endif