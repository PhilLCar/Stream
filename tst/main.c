#include <stdio.h>

#include <stream.h>
#include <filestream.h>

int main(void)
{
  CHECK_MEMORY

  Stream *test = fromFile("tst/test.txt", "r");

  while (1)
  {
    char c = sgetc(test);

    if (test->eos) break;

    if (c == '?')
    {
      sungetc(test, '.');
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