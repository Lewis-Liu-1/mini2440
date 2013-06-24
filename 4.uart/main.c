#include "serial.h"
#include "s3c24xx.h"
/*
这个程序是从NOR中运行的，所以必须下载到NOR的0地址中才能正确运行。
*/
int main()
{
    unsigned char c;
    uart0_init();   // 波特率115200，8N1(8个数据位，无校验位，1个停止位)
	
	putStr("\r\n\r\ncommon list:\r\n");
	putStr("v:get version\r\n");
	putStr("r:reset\r\n");
    while(1)
    {
		c=getc();
		switch(c)
		{
		case 'v':
		case 'V':
			putStr("Uart test form NOR V0.01\r\n");
		break;
		case 'r':
		case 'R':
			putStr("reset cpu ...\r\n");
			((void (*) (void))0x00000000)();
		break;
		}
	     
    }

    return 0;
}
