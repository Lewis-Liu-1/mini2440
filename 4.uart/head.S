@******************************************************************************
@ File：head.S
@ 功能：设置SDRAM，将程序复制到SDRAM，然后跳到SDRAM继续执行
@******************************************************************************       
   
.extern     main
.text 
.global _start 
_start:
Reset:                  
	ldr sp, =0x40000000+3*1024      //从NOR启动时内部SRAM的起始地址是0x40000000
    bl  disable_watch_dog   @ 关闭WATCHDOG，否则CPU会不断重启
    // bl是位置无关码，相当于：PCnew = PC + 偏移
    //                         PCnew = (4+8) + 0x28 = 0x34      
    bl  clock_init          @ 设置MPLL，改变FCLK、HCLK、PCLK
    ldr pc, =main           @ 调用main函数
halt_loop:
    b   halt_loop
