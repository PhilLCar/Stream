#include <stream.h>

#define TYPENAME Stream

////////////////////////////////////////////////////////////////////////////////
Stream *_(cons)(void *stream)
{
  if (this) {
    const Type *type = gettype(this);

    // This will fail if abstract class is not implemented
    this->get    = (void*)virtual(type, "get");
    this->peek   = (void*)virtual(type, "peek");
    this->unget  = (void*)virtual(type, "unget");
    this->close  = (void*)virtual(type, "close");

    if (!this->get || !this->peek || !this->unget || !this->close) {
      this = NULL;
    } else {
      this->base = stream;
    }
  }
  
  return this;
}

////////////////////////////////////////////////////////////////////////////////
void _(free)()
{
  this->close(this);
}

////////////////////////////////////////////////////////////////////////////////
const void *_(peek)()
{
  return this->peek(this);
}

////////////////////////////////////////////////////////////////////////////////
const void *_(get)()
{
  const void *token = this->get(this);

  this->eos = token == EOS;

  return token;
}

////////////////////////////////////////////////////////////////////////////////
const void _(unget)(const void *token)
{
  this->unget(this, token);
  this->eos = 0;
}