#include <filestream.h>

#define TYPENAME FileStream

////////////////////////////////////////////////////////////////////////////////
FileStream *_(Construct)(FILE *stream)
{
  if (CharStream_Construct(BASE(0), stream)) {
    // The user is responsible for setting cod in other cases, but these are obvious
    BASE(1)->cod = !(stream == stdin || stream == stdout || stream == stderr);
  }

  return this;
}

////////////////////////////////////////////////////////////////////////////////
void _(Destruct)()
{
  CharStream_Destruct(BASE(0));
}

////////////////////////////////////////////////////////////////////////////////
FileStream *STATIC (Open)(const char *name, AccessModes mode)
{
  char buffer[8];

  Stream_Mode(mode, buffer);

  if (mode & ACCESS_CREATE && !fexists(name, FILE_EXISTS)) {
    newfile(name);
  }

  return NEW (FileStream) (fopen(name, buffer));
}

////////////////////////////////////////////////////////////////////////////////
void _(Close)()
{
  if (BASE(1)->cod)
  {
    fclose(*BASE(2));
  }
}

////////////////////////////////////////////////////////////////////////////////
int _(Peek)()
{
  int c = fgetc(*BASE(2));

  ungetc(c, *BASE(2));

  return c;
}

////////////////////////////////////////////////////////////////////////////////
int _(Get)()
{
  int c = fgetc(*BASE(2));

  BASE(1)->eos = c == EOF;

  return c;
}

////////////////////////////////////////////////////////////////////////////////
void _(Unget)(int c)
{
  ungetc(c, *BASE(2));
  BASE(1)->eos = 0;
}

////////////////////////////////////////////////////////////////////////////////
void _(Put)(int c)
{
  fputc(c, *BASE(2));
}

#undef TYPENAME
