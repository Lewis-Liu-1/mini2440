@******************************************************************************
@ File��head.S
@ ���ܣ�����SDRAM���������Ƶ�SDRAM��Ȼ������SDRAM����ִ��
@******************************************************************************       
   
.extern     main
.text 
.global _start 
_start:
Reset:                  
	ldr sp, =0x40000000+3*1024      //��NOR����ʱ�ڲ�SRAM����ʼ��ַ��0x40000000
    bl  disable_watch_dog   @ �ر�WATCHDOG������CPU�᲻������
    // bl��λ���޹��룬�൱�ڣ�PCnew = PC + ƫ��
    //                         PCnew = (4+8) + 0x28 = 0x34      
    bl  clock_init          @ ����MPLL���ı�FCLK��HCLK��PCLK
    ldr pc, =main           @ ����main����
halt_loop:
    b   halt_loop