#include <charstream.h>

#define TYPENAME CharStream

////////////////////////////////////////////////////////////////////////////////
CharStream *_(Construct)(void *stream)
{
  return (CharStream*)Stream_Construct(BASE(0), stream);
}

////////////////////////////////////////////////////////////////////////////////
void _(Destruct)()
{
  if (this) {
    Stream_Destruct(BASE(0));
  }
}

////////////////////////////////////////////////////////////////////////////////
int _(Peek)()
{
  return ((int(*)(CharStream*))BASE(0)->Peek)(this);
}

////////////////////////////////////////////////////////////////////////////////
int _(Get)()
{
  return ((int(*)(CharStream*))BASE(0)->Get)(this);
}

////////////////////////////////////////////////////////////////////////////////
void _(Unget)(int c)
{
  ((int(*)(CharStream*,int))BASE(0)->Unget)(this, c);
}

////////////////////////////////////////////////////////////////////////////////
void _(Put)(int c)
{
  ((int(*)(CharStream*,int))BASE(0)->Put)(this, c);
}

int _(Escape)()
{
  int c = CharStream_Get(this);

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

  return c;
}

////////////////////////////////////////////////////////////////////////////////
int _(Read)()
{
  return CharStream_ReadWith(this, '\\');
}

////////////////////////////////////////////////////////////////////////////////
int _(ReadWith)(int escape)
{
  int c = CharStream_Get(this);
  
  if (c == escape) {
    c = CharStream_Escape(this);
  }

  return c;
}

////////////////////////////////////////////////////////////////////////////////
void _(Write)(int c)
{
  CharStream_WriteWith(this, '\\', c);
}

////////////////////////////////////////////////////////////////////////////////
void _(WriteWith)(int escape, int c)
{
  switch (c) {
    // https://en.wikipedia.org/wiki/Escape_sequences_in_C
    case '\a':
      CharStream_Put(this, escape);
      CharStream_Put(this, 'a');
      break;
    case '\b':
      CharStream_Put(this, escape);
      CharStream_Put(this, 'b');
      break;
    case '\e':
      CharStream_Put(this, escape);
      CharStream_Put(this, 'e');
      break;
    case '\f':
      CharStream_Put(this, escape);
      CharStream_Put(this, 'f');
      break;
    case '\n':
      CharStream_Put(this, escape);
      CharStream_Put(this, 'n');
      break;
    case '\r':
      CharStream_Put(this, escape);
      CharStream_Put(this, 'r');
      break;
    case '\t':
      CharStream_Put(this, escape);
      CharStream_Put(this, 't');
      break;
    case '\v':
      CharStream_Put(this, escape);
      CharStream_Put(this, 'v');
      break;
    case '\\':
      CharStream_Put(this, escape);
      CharStream_Put(this, '\\');
      break;
    case '\'':
      CharStream_Put(this, escape);
      CharStream_Put(this, '\'');
      break;
    case '\"':
      CharStream_Put(this, escape);
      CharStream_Put(this, '\"');
      break;
    // TODO: (medium): Incomplete: Produce numeric escapes
    default:
      CharStream_Put(this, c);
      break;
  }
}

////////////////////////////////////////////////////////////////////////////////
int CONST (EOS)()
{
  return BASE(0)->eos;
}

////////////////////////////////////////////////////////////////////////////////
void _(PutStr)(const char *line)
{
	for (int i = 0; line[i]; i++) {
		CharStream_Put(this, line[i]);
	}
}

////////////////////////////////////////////////////////////////////////////////
void _(WriteStr)(const char *line)
{
	for (int i = 0; line[i]; i++) {
		CharStream_Write(this, line[i]);
	}
}

////////////////////////////////////////////////////////////////////////////////
void _(PutLn)(const char *line)
{
	CharStream_PutStr(this, line);
	CharStream_Put(this, '\n');
}

////////////////////////////////////////////////////////////////////////////////
void _(WriteLn)(const char *line)
{
	CharStream_WriteStr(this, line);
	CharStream_Put(this, '\n');
}

////////////////////////////////////////////////////////////////////////////////
String *_(GetLine)()
{
	String *line = NEW (String) ("");
	char c;

	while((c = CharStream_Get(this)) != '\n' && !BASE(0)->eos) {
    if (c != '\r') String_Append(line, c); 
  } 

	if (BASE(0)->eos && !line->length) {
		DELETE (line);
	}

  return line;
}

////////////////////////////////////////////////////////////////////////////////
String *_(ReadLine)()
{
	String *line = NEW (String) ("");
	char c;

	while((c = CharStream_Read(this)) != '\n' && !BASE(0)->eos) {
    if (c != '\r') String_Append(line, c); 
  } 

	if (BASE(0)->eos && !line->length) {
		DELETE (line);
	}

  return line;
}

////////////////////////////////////////////////////////////////////////////////
String *_(GetToEnd)()
{
	String *result = NEW (String) ("");

	String *line;

	while ((line = CharStream_GetLine(this))) {
		if (result->length) String_Append(result, '\n');

		String_Concat(result, line);
	}

	DELETE (this);

	return result;
}

////////////////////////////////////////////////////////////////////////////////
String *_(ReadToEnd)()
{
	String *result = NEW (String) ("");

	String *line;

	while ((line = CharStream_ReadLine(this))) {
		if (result->length) String_Append(result, '\n');

		String_Concat(result, line);
	}

	DELETE (this);

	return result;
}

////////////////////////////////////////////////////////////////////////////////
void _(PutString)(void *object)
{
	String *string = String_ToString(object);

	CharStream_PutStr(this, string->base);

	DELETE (string);
}

////////////////////////////////////////////////////////////////////////////////
void _(WriteString)(void *object)
{
	String *string = String_ToString(object);

	CharStream_WriteStr(this, string->base);

	DELETE (string);
}

////////////////////////////////////////////////////////////////////////////////
void _(PutLine)(void *object)
{
	CharStream_PutString(this, object);
	CharStream_Put(this, '\n');
}

////////////////////////////////////////////////////////////////////////////////
void _(WriteLine)(void *object)
{
	CharStream_WriteString(this, object);
	CharStream_Put(this, '\n');
}


#undef TYPENAME
