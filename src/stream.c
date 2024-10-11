#include <stream.h>

#define TYPENAME Stream

////////////////////////////////////////////////////////////////////////////////
Stream *_(cons)(void *stream)
{
  if (this && stream) {
    const Type *type = gettype(this);

    // This will fail if abstract class is not implemented
    this->close  = (void*)virtual(type, "close");
    this->get    = (void*)virtual(type, "get");
    this->peek   = (void*)virtual(type, "peek");
    this->unget  = (void*)virtual(type, "unget");
    this->put    = (void*)virtual(type, "put");

    if (!this->close || !this->get || !this->peek || !this->unget || !this->put) {
      this = NULL;
    } else {
      this->base = stream;
      this->eos  = 0;
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
  return this->get(this);
}

////////////////////////////////////////////////////////////////////////////////
const void _(unget)(const void *token)
{
  this->unget(this, token);
}

////////////////////////////////////////////////////////////////////////////////
const void _(put)(const void *token)
{
  this->put(this, token);
}