#include <charstream.h>

#define TYPENAME CharStream

////////////////////////////////////////////////////////////////////////////////
CharStream *_(cons)(void *stream)
{
  return (CharStream*)Stream_cons(BASE(0), stream);
}

////////////////////////////////////////////////////////////////////////////////
void _(free)()
{
  Stream_free(BASE(0));
}

////////////////////////////////////////////////////////////////////////////////
int _(peek)()
{
  return (long)BASE(0)->peek(BASE(0));
}

////////////////////////////////////////////////////////////////////////////////
int _(get)()
{
  return (long)BASE(0)->get(BASE(0));
}

////////////////////////////////////////////////////////////////////////////////
void _(unget)(char c)
{
  BASE(0)->unget(BASE(0), (void*)(long)c);
}

////////////////////////////////////////////////////////////////////////////////
void _(put)(char c)
{
  BASE(0)->put(BASE(0), (void*)(long)c);
}

////////////////////////////////////////////////////////////////////////////////
int _(read)()
{
  return CharStream_readwith(this, '\\');
}

////////////////////////////////////////////////////////////////////////////////
int _(readwith)(char escape)
{
  char c = CharStream_get(this);
  
  if (c == escape) {
    c = CharStream_get(this);

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
  }

  return c;
}

////////////////////////////////////////////////////////////////////////////////
void _(write)(char c)
{
  CharStream_writewith(this, '\\', c);
}

////////////////////////////////////////////////////////////////////////////////
void _(writewith)(char escape, char c)
{
  switch (c) {
    // https://en.wikipedia.org/wiki/Escape_sequences_in_C
    case '\a':
      CharStream_put(this, escape);
      CharStream_put(this, 'a');
      break;
    case '\b':
      CharStream_put(this, escape);
      CharStream_put(this, 'b');
      break;
    case '\e':
      CharStream_put(this, escape);
      CharStream_put(this, 'e');
      break;
    case '\f':
      CharStream_put(this, escape);
      CharStream_put(this, 'f');
      break;
    case '\n':
      CharStream_put(this, escape);
      CharStream_put(this, 'n');
      break;
    case '\r':
      CharStream_put(this, escape);
      CharStream_put(this, 'r');
      break;
    case '\t':
      CharStream_put(this, escape);
      CharStream_put(this, 't');
      break;
    case '\v':
      CharStream_put(this, escape);
      CharStream_put(this, 'v');
      break;
    case '\\':
      CharStream_put(this, escape);
      CharStream_put(this, '\\');
      break;
    case '\'':
      CharStream_put(this, escape);
      CharStream_put(this, '\'');
      break;
    case '\"':
      CharStream_put(this, escape);
      CharStream_put(this, '\"');
      break;
    // TODO: (medium): Incomplete: Produce numeric escapes
    default:
      CharStream_put(this, c);
      break;
  }
}

////////////////////////////////////////////////////////////////////////////////
int _(eos)()
{
  return BASE(0)->eos;
}

////////////////////////////////////////////////////////////////////////////////
void _(putstr)(const char *line)
{
	for (int i = 0; line[i]; i++) {
		CharStream_put(this, line[i]);
	}
}

////////////////////////////////////////////////////////////////////////////////
void _(writestr)(const char *line)
{
	for (int i = 0; line[i]; i++) {
		CharStream_write(this, line[i]);
	}
}

////////////////////////////////////////////////////////////////////////////////
void _(putline)(const char *line)
{
	CharStream_putstr(this, line);
	CharStream_put(this, '\n');
}

////////////////////////////////////////////////////////////////////////////////
void _(writeline)(const char *line)
{
	CharStream_writestr(this, line);
	CharStream_put(this, '\n');
}