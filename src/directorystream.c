#include <directorystream.h>

#define TYPENAME DirectoryStream

////////////////////////////////////////////////////////////////////////////////
DirectoryStream *_(cons)(const char *directory)
{
  return (DirectoryStream*)Stream_cons(BASE(0), dopen(directory));
}

////////////////////////////////////////////////////////////////////////////////
void _(free)()
{
  Stream_free(BASE(0));
}

////////////////////////////////////////////////////////////////////////////////
void _(close)()
{
  dclose((DirectoryIterator**)BASE(1));
}

////////////////////////////////////////////////////////////////////////////////
DirectoryItem *_(peek)()
{
  DirectoryItem     *peek = NULL;
  DirectoryIterator *iter = (DirectoryIterator*)*BASE(1);

  if (iter) {
    peek = &iter->current;
  }

  return peek;
}

////////////////////////////////////////////////////////////////////////////////
DirectoryItem *_(get)()
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
void _(unget)(DirectoryItem *token)
{
  fprintf(stderr, "Cannot unget on directory stream\n");
}

////////////////////////////////////////////////////////////////////////////////
void _(put)(DirectoryItem *token)
{
  if (token->type == DIRTYPE_FILE) {
    fclose(fopen(token->name, "w+"));
  } else if (token->type == DIRTYPE_DIRECTORY) {
    dcreate(token->name);
  }
}