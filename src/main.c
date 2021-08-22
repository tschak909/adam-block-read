#include <msx.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>
#include <smartkeys.h>
#include <eos.h>

unsigned char buf[1024];

char pp(unsigned char c)
{
  return ((c > 0x19) && (c < 0x80)) ? c : '.';
}

void main(void)
{
  unsigned char dev;
  unsigned long block;
  char blockstr[16];

  msx_set_mode(2);
  msx_color(15,1,1);  
  clrscr();

  while(1)
    {
      printf("DEV #");
      scanf("%s",blockstr);
      dev=atoi(blockstr);
      printf("BLOCK #");
      scanf("%s",blockstr);
      block=strtoul(blockstr,NULL,16);
      
      printf("BLOCK #%lx\n",block);

      eos_read_block(dev,block,&buf);

      for (int r=0;r<128;r++)
	{
	  int o=r << 3;
	  printf("%02X %02X %02X %02X %02X %02X %02X %02X %c%c%c%c%c%c%c%c", buf[o+0], buf[o+1], buf[o+2], buf[o+3], buf[o+4], buf[o+5], buf[o+6], buf[o+7],
		 pp(buf[o+0]), pp(buf[o+1]), pp(buf[o+2]), pp(buf[o+3]), pp(buf[o+4]), pp(buf[o+5]), pp(buf[o+6]), pp(buf[o+7]));
	}      
    }
}
