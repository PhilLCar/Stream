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

#include "stream.export.h"

// Abstract class
#define LIB_EXPORT STREAM_EXPORT
#define TYPENAME CharStream

// (!) This class must always be initialized using the NEW macro
OBJECT (void *stream) INHERIT (Stream)
END_OBJECT(NULL);

STREAM_EXPORT int  _(Peek)();
STREAM_EXPORT int  _(Get)();
STREAM_EXPORT void _(Unget)(int c);
STREAM_EXPORT void _(Put)(int c);

STREAM_EXPORT int  _(Escape)();
STREAM_EXPORT int  _(Read)();
STREAM_EXPORT int  _(ReadWith)(int escape);
STREAM_EXPORT void _(Write)(int c);
STREAM_EXPORT void _(WriteWith)(int escape, int c);

STREAM_EXPORT int CONST (EOS)();

// Puts the line as is
STREAM_EXPORT void    _(PutStr)(const char *line);
// Puts the line and generates escape sequences based on the specified escape char
STREAM_EXPORT void    _(WriteStr)(const char *line);

// Puts the line as is
STREAM_EXPORT void    _(PutLn)(const char *line);
// Puts the line and generates escape sequences based on the specified escape char
STREAM_EXPORT void    _(WriteLn)(const char *line);

// Gets the line as is
STREAM_EXPORT String *_(GetLine)();

// Gets the line and interprets what's after the escape char
STREAM_EXPORT String *_(ReadLine)();

// Gets and consume the stream
STREAM_EXPORT String *_(GetToEnd)();

// Reads and consume the stream
STREAM_EXPORT String *_(ReadToEnd)();

// Puts an object to the stream
STREAM_EXPORT void _(PutString)(void *object);

// Writes an object to the stream
STREAM_EXPORT void _(WriteString)(void *object);

// Puts an object to the stream and newline
STREAM_EXPORT void _(PutLine)(void *object);

// Writes an object to the stream and newline
STREAM_EXPORT void _(WriteLine)(void *object);


#undef TYPENAME
#undef LIB_EXPORT
#endif