#ifndef FILESTREAM_H
#define FILESTREAM_H

// C
#include <stdio.h>

// CUT
#include <stream.h>

typedef FILE FileStream;

static int fpeek(FileStream *fptr)
{
    int c;

    c = fgetc(fptr);
    ungetc(c, fptr);

    return c;
}

static int (*fungetc)(int, FileStream *) = ungetc;

FROM_STREAM(FileStream, f);

#endif
