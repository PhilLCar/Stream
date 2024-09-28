#ifndef STREAM_H
#define STREAM_H

//C
#include <stdio.h>
#include <stdlib.h>

// CUT
#include <diagnostic.h>
#include <macro.h>
#include <oop.h>

#define TYPENAME Stream
#define EOS      (void*)EOF

// (!) This class must always be initialized using the NEW macro
OBJECT (void *stream) INHERIT (void*)
  int eos;

  // Abstract methods
  const void  (*close)(Stream *stream);
  const void *(*peek) (Stream *stream);
  const void *(*get)  (Stream *stream);
  const void  (*unget)(Stream *stream, const void *token);
END(NULL);

const void *_(peek)();
const void *_(get)();
const void  _(unget)(const void *token);

#undef TYPENAME
#endif