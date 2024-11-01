#ifndef DIRECTORYSTREAM_H
#define DIRECTORYSTREAM_H

// C
#include <stdio.h>

// CUT
#include <directory.h>
#include <oop.h>
#include <stream.h>

#define TYPENAME DirectoryStream

OBJECT (const char *directory) INHERIT (Stream)
END_OBJECT(".");

void           _(Close)()                     VIRTUAL (Close);
DirectoryItem *_(Peek) ()                     VIRTUAL (Peek);
DirectoryItem *_(Get)  ()                     VIRTUAL (Get);
void           _(Unget)(DirectoryItem *token) VIRTUAL (Unget);
void           _(Put)  (DirectoryItem *token) VIRTUAL (Put);

#undef TYPENAME
#endif
