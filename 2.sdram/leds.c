
#define	GPBCON		(*(volatile unsigned long *)0x56000010)
#define	GPBDAT		(*(volatile unsigned long *)0x56000014)


/*
 * LED1,LED2,LED4对应GPB5、GPB6、GPB7、GPB8
 */
#define	GPB5_out	(1<<(5*2))
#define	GPB6_out	(1<<(6*2))
#define	GPB7_out	(1<<(7*2))
#define	GPB8_out	(1<<(8*2))


void  wait(volatile unsigned long dly)
{
	for(; dly > 0; dly--);
}

int main(void)
{
	unsigned long i = 0;

	// LED1,LED2,LED3,LED4对应的4根引脚设为输出
	GPBCON = GPB5_out | GPB6_out | GPB7_out | GPB8_out;

	while(1){
		wait(30000);
		GPBDAT = (~(i<<5));	 	// 根据i的值，点亮LED1,2,3,4
		if(++i == 16)
			i = 0;
	}

	return 0;
}

#define BWSCON 		(*(volatile long *)0x48000000)
#define BANKCON0 	(*(volatile long *)0x48000004)
#define BANKCON1 	(*(volatile long *)0x48000008)
#define BANKCON2 	(*(volatile long *)0x4800000C)
#define BANKCON3 	(*(volatile long *)0x48000010)
#define BANKCON4 	(*(volatile long *)0x48000014)
#define BANKCON5 	(*(volatile long *)0x48000018)
#define BANKCON6 	(*(volatile long *)0x4800001C)
#define BANKCON7 	(*(volatile long *)0x48000020)
#define REFRESH 	(*(volatile long *)0x48000024)
#define BANKSIZE 	(*(volatile long *)0x48000028)
#define MRSRB6 		(*(volatile long *)0x4800002C)
#define MRSRB7 		(*(volatile long *)0x48000030)


void SDRAM_init(void)
{
//由于没有使用PLL所以SDRAM的时钟=12Mhz  1/12Mhz=0.08333333us=83.333ns

	//BWSCON=0x22011110;      	// BWSCON bank6=bank7 不使用UB/LB 不使用wait信号 32数据总线
	BWSCON=0x22000000;			// BWSCON bank6=bank7 不使用UB/LB 不使用wait信号 32数据总线 其余保持默认
	//以下没有使用设为默认值
	BANKCON0=0x00000700;      	// BANKCON0
	BANKCON1=0x00000700;      	// BANKCON1
	BANKCON2=0x00000700;      	// BANKCON2
	BANKCON3=0x00000700;      	// BANKCON3  
	BANKCON4=0x00000700;      	// BANKCON4
	BANKCON5=0x00000700;      	// BANKCON5
	
	BANKCON6=0x00018005;      	// BANKCON6 memory type=DRAM Trcd=3 clocks SCAN=9 bit
	BANKCON7=0x00018005;     	// BANKCON7 memory type=DRAM Trcd=3 clocks SCAN=9 bit
	REFRESH=0x008C07A3;      	// REFRESH Refresh Enable、Auto Refresh
	BANKSIZE=0x000000B1;      	// BANKSIZE
	MRSRB6=0x00000030;      	// MRSRB6
	MRSRB7=0x00000030;      	// MRSRB7
}
