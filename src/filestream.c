#include <filestream.h>

#define TYPENAME FileStream

////////////////////////////////////////////////////////////////////////////////
FileStream *_(cons)(FILE *stream)
{
  if (this) {
    if (stream) CharStream_cons(BASE(0), stream);
    else        this = NULL;
  }

  return this;
}

////////////////////////////////////////////////////////////////////////////////
void _(free)()
{
  CharStream_free(BASE(0));
}

////////////////////////////////////////////////////////////////////////////////
void _(close)()
{
  fclose(*BASE(2));
}

////////////////////////////////////////////////////////////////////////////////
void *_(peek)()
{
  long c = fgetc(*BASE(2));

  ungetc(c, *BASE(2));

  return (void*)c;
}

////////////////////////////////////////////////////////////////////////////////
void *_(get)()
{
  return (void*)(long)fgetc(*BASE(2));
}

////////////////////////////////////////////////////////////////////////////////
void _(unget)(void *token)
{
  ungetc((long)token, *BASE(2));
}

////////////////////////////////////////////////////////////////////////////////
void _(put)(void *token)
{
  fputc((long)token, *BASE(2));
}