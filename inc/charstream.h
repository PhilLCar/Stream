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
int  _(esc)();
int  _(eos)();

#undef TYPENAME
// Shortnames
__attribute__((unused)) static int  (*sgetc)  (CharStream*)       = CharStream_get;
__attribute__((unused)) static void (*sungetc)(CharStream*, char) = CharStream_unget;
__attribute__((unused)) static int  (*speek)  (CharStream*)       = CharStream_peek;
__attribute__((unused)) static int  (*sesc)   (CharStream*)       = CharStream_esc;
__attribute__((unused)) static int  (*seos)   (CharStream*)       = CharStream_eos;
#endif