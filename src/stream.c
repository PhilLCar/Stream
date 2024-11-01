#include <stream.h>

#define TYPENAME Stream

////////////////////////////////////////////////////////////////////////////////
Stream *_(Construct)(void *stream)
{
  if (this) {
    const Type *type = gettype(this);

    this->base = stream;
    this->eos  = 0;
    this->cod  = 1;

    // This will fail if abstract class is not implemented
    this->Close  = (void*)virtual(type, "Close");
    this->Get    = (void*)virtual(type, "Get");
    this->Peek   = (void*)virtual(type, "Peek");
    this->Unget  = (void*)virtual(type, "Unget");
    this->Put    = (void*)virtual(type, "Put");

    if (!this->Close || !this->Get || !this->Peek || !this->Unget || !this->Put) {
      THROW(NEW (Exception)("All abstract methods were not implemented!"));
    }
  } else {
    THROW(NEW (MemoryAllocationException)());
  }
  
  return this;
}

////////////////////////////////////////////////////////////////////////////////
void _(Destruct)()
{
  if (this && this->cod) {
    this->Close(this);
  }
}

////////////////////////////////////////////////////////////////////////////////
const void _(Close)()
{
  this->Close(this);
  this->cod = 0;
}

////////////////////////////////////////////////////////////////////////////////
const void *_(Peek)()
{
  return this->Peek(this);
}

////////////////////////////////////////////////////////////////////////////////
const void *_(Get)()
{
  return this->Get(this);
}

////////////////////////////////////////////////////////////////////////////////
const void _(Unget)(const void *token)
{
  this->Unget(this, token);
  this->eos = 0;
}

////////////////////////////////////////////////////////////////////////////////
const void _(put)(const void *token)
{
  this->Put(this, token);
}

#undef TYPENAME
