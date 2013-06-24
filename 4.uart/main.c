#include "serial.h"
#include "s3c24xx.h"
/*
��������Ǵ�NOR�����еģ����Ա������ص�NOR��0��ַ�в�����ȷ���С�
*/
int main()
{
    unsigned char c;
    uart0_init();   // ������115200��8N1(8������λ����У��λ��1��ֹͣλ)
	
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
