#include <filestream.h>

#define TYPENAME FileStream

FileStream *_(cons)(const char *filename, const char *mode)
{
  if (this) {
    FILE *stream = fopen(filename, mode);

    if (stream) CharStream_cons(BASE(0), stream);
    else        this = NULL;
  }

  return this;
}

void _(free)()
{
  CharStream_free(BASE(0));
}

void _(close)()
{
  fclose((FILE*)BASE(2));
}

void *_(peek)()
{
  long c = fgetc((FILE*)BASE(2));

  ungetc(c, (FILE*)BASE(2));

  return (void*)c;
}

void *_(get)()
{
  return (void*)(long)fgetc((FILE*)BASE(2));
}

void _(unget)(void *token)
{
  ungetc((long)token, (FILE*)BASE(2));
}