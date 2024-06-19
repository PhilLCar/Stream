#include <stream.h>

#define TYPENAME Stream

////////////////////////////////////////////////////////////////////////////////
TYPENAME *_(cons)(void *stream, const char *typename)
{
  if (_this) {
    _this->base   = stream;

    // V-lookup only once
    _this->getc   = (void*)_virtual("getc",   typename);
    _this->peek   = (void*)_virtual("peek",   typename);
    _this->ungetc = (void*)_virtual("ungetc", typename);
    _this->close  = (void*)_virtual("close",  typename);
  }
  
  return _this;
}

////////////////////////////////////////////////////////////////////////////////
void _(free)()
{
  _this->close(_this->base);
}

////////////////////////////////////////////////////////////////////////////////
int _(peek)()
{
  return _this->peek(_this->base);
}

////////////////////////////////////////////////////////////////////////////////
int _(getc)()
{
  int c = _this->getc(_this->base);

  _this->eos = c == EOF;

  return c;
}

////////////////////////////////////////////////////////////////////////////////
void _(ungetc)(char c)
{
  _this->ungetc(_this->base, c);
  _this->eos = 0;
}

////////////////////////////////////////////////////////////////////////////////
void _(close)()
{
  DELETE (_this);
}

////////////////////////////////////////////////////////////////////////////////
int _(esc)()
{
  char c = _this->getc(_this->base);

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
