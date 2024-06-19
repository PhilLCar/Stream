#ifndef FILESTREAM_H
#define FILESTREAM_H

// C
#include <stdio.h>

// CUT
#include <stream.h>
#include <oop.h>

typedef FILE FileStream;

static void fungetc(FileStream *fptr, char c)
{
  ungetc(c, fptr);
}

static int fpeek(FileStream *fptr)
{
  int c;

  c = fgetc(fptr);
  fungetc(fptr, c);

  return c;
}

#define TYPENAME File

FOREIGN_VIRTUAL(close,  fclose);
FOREIGN_VIRTUAL(getc,   fgetc);
FOREIGN_VIRTUAL(peek,   fpeek);
FOREIGN_VIRTUAL(ungetc, fungetc);

FROM_STREAM;

#undef TYPENAME

static Stream *fromFile(const char *filename, const char *mode)
{
  return fromFileStream(fopen(filename, mode));
}

#endif
