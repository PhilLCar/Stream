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
  fclose(*BASE(2));
}

void *_(peek)()
{
  long c = fgetc(*BASE(2));

  ungetc(c, *BASE(2));

  return (void*)c;
}

void *_(get)()
{
  return (void*)(long)fgetc(*BASE(2));
}

void _(unget)(void *token)
{
  ungetc((long)token, *BASE(2));
}