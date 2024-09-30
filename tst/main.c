#include <stdio.h>

#include <charstream.h>
#include <filestream.h>
#include <stream.h>

int main(void)
{
  CHECK_MEMORY

  CharStream *test = (CharStream*) NEW (FileStream) ("tst/test.txt", "r");

  printf("Initialized\n");
  while (1)
  {
    char c = CharStream_get(test);

    if (cseos(test)) break;

    if (c == '?')
    {
      csunget(test, '.');
      continue;
    }

    printf("%c", c);
  }

  fflush(stdout);

  DELETE (test);

  printf("\n%s\n", "Looks like they are!");

  CHECK_MEMORY

  STOP_WATCHING
}