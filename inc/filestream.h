#ifndef FILESTREAM_H
#define FILESTREAM_H

// C
#include <stdio.h>

// CUT
#include <diagnostic.h>
#include <oop.h>
#include <charstream.h>
#include <file.h>

#include "stream.export.h"

#define LIB_EXPORT STREAM_EXPORT
#define TYPENAME FileStream

OBJECT (FILE* file) INHERIT (CharStream)
END_OBJECT(stdin);

STREAM_EXPORT FileStream *STATIC (Open)(const char *name, AccessModes mode);

STREAM_EXPORT void _(Close)()      VIRTUAL (Close);
STREAM_EXPORT int  _(Peek) ()      VIRTUAL (Peek);
STREAM_EXPORT int  _(Get)  ()      VIRTUAL (Get);
STREAM_EXPORT void _(Unget)(int c) VIRTUAL (Unget);
STREAM_EXPORT void _(Put)  (int c) VIRTUAL (Put);

#undef TYPENAME
#undef LIB_EXPORT
#endif
