#include <charstream.h>

#define TYPENAME CharStream

////////////////////////////////////////////////////////////////////////////////
CharStream *_(cons)(void *stream)
{
  Stream_cons(BASE(0), stream);
  
  return this;
}

////////////////////////////////////////////////////////////////////////////////
void _(free)()
{
  Stream_free(BASE(0));
}

////////////////////////////////////////////////////////////////////////////////
int _(peek)()
{
  return (long)Stream_peek(BASE(0));
}

////////////////////////////////////////////////////////////////////////////////
int _(get)()
{
  return (long)Stream_get(BASE(0));
}

////////////////////////////////////////////////////////////////////////////////
void _(unget)(char c)
{
  Stream_unget(BASE(0), (void*)(long)c);
}

////////////////////////////////////////////////////////////////////////////////
int _(esc)()
{
  char c = CharStream_get(this);

  switch (c) {
    // https://en.wikipedia.org/wiki/Escape_sequences_in_C
    case 'a':
      c = '\a';
      break;
    case 'b':
      c = '\b';
      break;
    case 'e':
      c = '\e';
      break;
    case 'f':
      c = '\f';
      break;
    case 'n':
      c = '\n';
      break;
    case 'r':
      c = '\r';
      break;
    case 's':
      c = ' ';
      break;
    case 't':
      c = '\t';
      break;
    case 'v':
			c = '\v';
      break;
    case '\\':
    case '\'':
    case '\"':
    case '\n':
    case '?':
			// do nothing
      break;
    case 'x': // hexa
      break;
    case 'X': // HEXA
    case 'u': // unicode (2 bytes)
      break;
    case 'U': // unicode (4 bytes)
      break;
    default:
    // TODO: (medium): Incomplete: Parse numeric escapes
      if (c > '0' && c <= '9') {
      } else if (c == '0') {
      }
      break;
  }

  return 0;
}

////////////////////////////////////////////////////////////////////////////////
int _(eos)()
{
  return BASE(0)->eos;
}