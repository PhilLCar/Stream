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
void *_(peek)()
{
  void              *peek = NULL;
  DirectoryIterator *iter = (DirectoryIterator*)*BASE(1);

  if (iter) {
    peek = &iter->current;
  }

  return peek;
}

////////////////////////////////////////////////////////////////////////////////
void *_(get)()
{
  void               *get  = NULL;
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
void _(unget)(void *token)
{
  fprintf(stderr, "Cannot unget on directory stream\n");
}

////////////////////////////////////////////////////////////////////////////////
void _(put)(void *token)
{
  DirectoryItem *item = token;

  if (item->type == DIRTYPE_FILE) {
    fclose(fopen(item->name, "w+"));
  } else if (item->type == DIRTYPE_DIRECTORY) {
    dcreate(item->name);
  }
}