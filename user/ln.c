#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
strncmp(const char *p, const char *q, uint n)
{
  while(n > 0 && *p && *p == *q)
    n--, p++, q++;
  if(n == 0)
    return 0;
  return (uchar)*p - (uchar)*q;
}

int
main(int argc, char *argv[])
{
  if(argc != 4){
    fprintf(2, "Usage: ln old new\n");
    exit(1);
  }
  if(!strncmp(argv[1] , "-l" , 2)){
  if(link(argv[2], argv[3]) < 0)
    fprintf(2, "link %s %s: failed\n", argv[1], argv[2]);
  }else{
    if(strncmp(argv[1] , "-s" , 2)){
      fprintf(2, "Usage: not soft link\n");
      exit(1);
    }
    if(symlink(argv[2], argv[3]) < 0)
      fprintf(2, "link %s %s: failed\n", argv[1], argv[2]);

  }
  exit(0);
}
