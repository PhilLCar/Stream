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
END(NULL);

int  _(peek)();
int  _(get)();
void _(unget)(char c);
void _(put)(char c);
int  _(read)();
void _(write)(char c);
int  _(eos)();

// Puts the line as is
void    _(putstr)(const char *line);
// Puts the line and generates escape sequences based on the specified escape char
void    _(writestr)(const char *line);

// Puts the line as is
void    _(putline)(const char *line);
// Puts the line and generates escape sequences based on the specified escape char
void    _(writeline)(const char *line);

#undef TYPENAME
// Shortnames
__attribute__((unused)) static int  (*cspeek) (CharStream*)       = CharStream_peek;
__attribute__((unused)) static int  (*csget)  (CharStream*)       = CharStream_get;
__attribute__((unused)) static void (*csunget)(CharStream*, char) = CharStream_unget;
__attribute__((unused)) static int  (*csread) (CharStream*)       = CharStream_read;
__attribute__((unused)) static void (*csput)  (CharStream*, char) = CharStream_put;
__attribute__((unused)) static void (*cswrite)(CharStream*, char) = CharStream_write;
__attribute__((unused)) static int  (*cseos)  (CharStream*)       = CharStream_eos;

__attribute__((unused)) static void (*csputstr)   (CharStream*, const char *line) = CharStream_putstr;
__attribute__((unused)) static void (*cswritestr) (CharStream*, const char *line) = CharStream_writestr;
__attribute__((unused)) static void (*csputline)  (CharStream*, const char *line) = CharStream_putline;
__attribute__((unused)) static void (*cswriteline)(CharStream*, const char *line) = CharStream_writeline;
#endif