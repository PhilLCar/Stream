#ifndef STREAM_H
#define STREAM_H

//C
#include <stdio.h>
#include <stdlib.h>

// CUT
#include <diagnostic.h>
#include <macro.h>
#include <oop.h>
#include <exception.h>

#define TYPENAME Stream

typedef enum {
  ACCESS_READ   = 1,
  ACCESS_WRITE  = 2,
  ACCESS_APPEND = 4,
  ACCESS_CREATE = 8
} AccessModes;

// (!) This class must always be initialized using the NEW macro
OBJECT (void *stream) BASED (void*)
  int eos; // End of Stream
  int cod; // Close on Destruct

  // Abstract methods
  const void  (*Close)(Stream *stream);
  const void *(*Peek) (Stream *stream);
  const void *(*Get)  (Stream *stream);
  const void  (*Unget)(Stream *stream, const void *token);
  const void  (*Put)  (Stream *stream, const void *token);
END_OBJECT(NULL);

const void  _(Close)();
const void *_(Peek)();
const void *_(Get)();
const void  _(Unget)(const void *token);
const void  _(Put)(const void *token);

// TODO: Add seek methods

void STATIC (Mode)(AccessModes mode, char *buffer);

#undef TYPENAME
#endif