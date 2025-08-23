#ifndef STRINGSTREAM_H
#define STRINGSTREAM_H

// CUT
#include <diagnostic.h>
#include <str.h>
#include <charstream.h>

#define LIB_EXPORT STREAM_EXPORT
#define TYPENAME StringStream

OBJECT (String *string) INHERIT (CharStream)
  int pos;
END_OBJECT(NULL);

STREAM_EXPORT StringStream *STATIC(Open)(const char *string);

STREAM_EXPORT void  _(Close)()      VIRTUAL (Close);
STREAM_EXPORT int   _(Peek) ()      VIRTUAL (Peek);
STREAM_EXPORT int   _(Get)  ()      VIRTUAL (Get);
STREAM_EXPORT void  _(Unget)(int c) VIRTUAL (Unget);
STREAM_EXPORT void  _(Put)  (int c) VIRTUAL (Put);

#undef TYPENAME
#undef LIB_EXPORT
#endif
