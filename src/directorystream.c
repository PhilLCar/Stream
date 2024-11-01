#include <directorystream.h>

#define TYPENAME DirectoryStream

////////////////////////////////////////////////////////////////////////////////
DirectoryStream *_(Construct)(const char *directory)
{
  return (DirectoryStream*)Stream_Construct(BASE(0), dopen(directory));
}

////////////////////////////////////////////////////////////////////////////////
void _(Destruct)()
{
  Stream_Destruct(BASE(0));
}

////////////////////////////////////////////////////////////////////////////////
void _(Close)()
{
  dclose((DirectoryIterator**)BASE(1));
}

////////////////////////////////////////////////////////////////////////////////
DirectoryItem *_(Peek)()
{
  DirectoryItem     *peek = NULL;
  DirectoryIterator *iter = (DirectoryIterator*)*BASE(1);

  if (iter) {
    peek = &iter->current;
  }

  return peek;
}

////////////////////////////////////////////////////////////////////////////////
DirectoryItem *_(Get)()
{
  DirectoryItem      *get  = NULL;
  DirectoryIterator **iter = (DirectoryIterator**)BASE(1);
  
  if (*iter) {
    get = &(*iter)->current;
    dnext(iter);
  } else {
    BASE(0)->eos = !*iter;
  }

  return get;
}

////////////////////////////////////////////////////////////////////////////////
void _(Unget)(DirectoryItem *token)
{
  THROW(NEW (Exception)("Cannot unget on directory stream"));
}

////////////////////////////////////////////////////////////////////////////////
void _(Put)(DirectoryItem *token)
{
  if (token->type == DIRTYPE_FILE) {
    fclose(fopen(token->name, "w+"));
  } else if (token->type == DIRTYPE_DIRECTORY) {
    dcreate(token->name);
  }
}

#undef TYPENAME
