#include <stdio.h>

#include <charstream.h>
#include <filestream.h>
#include <directorystream.h>
#include <stream.h>

int main(void)
{
  CHECK_MEMORY

  CharStream *test = (CharStream*) NEW (FileStream) (fopen("tst/test.txt", "r"));

  printf("Initialized\n");
  while (1)
  {
    char c = CharStream_Get(test);

    if (CharStream_EOS(test)) break;

    if (c == '?')
    {
      CharStream_Unget(test, '.');
      continue;
    } else if (c == 't' && CharStream_Peek(test) == ' ') {
      CharStream_Unget(test, ',');
    }

    printf("%c", c);
  }

  fflush(stdout);

  DELETE (test);

  printf("\n%s\n", "Looks like they are!");

  CHECK_MEMORY

  Stream *dir = (Stream*) NEW (DirectoryStream) (".");

  while (1) {
    const DirectoryItem *item = Stream_Get(dir);

    if (dir->eos) break;

    printf("%s\n", item->name);
  }

  DELETE (dir);

  CHECK_MEMORY

  STOP_WATCHING
}