#include <reg52.h>

sbit ENA = P1^0;  // 使能引脚 A，控制电机转速和方向
sbit ENB = P1^1;  // 使能引脚 B，控制电机转速和方向

void delay(unsigned int t)
{
    unsigned int i, j;
    for (i = 0; i < t; i++)
        for (j = 0; j < 100; j++);
}

void motor_forward()
{
    ENA = 1;  // 使能引脚 A 为高电平
    ENB = 1;  // 使能引脚 B 为高电平
    
    // 控制电机正反转
    P2 = 0x06;  // 0011 0000
    
    delay(1000);  // 延时 1 秒
    
    // 关闭电机
    P2 = 0x00;  // 0000 0000
    
    ENA = 0;  // 使能引脚 A 为低电平
    ENB = 0;  // 使能引脚 B 为低电平
}

void motor_backward()
{
    ENA = 1;  // 使能引脚 A 为高电平
    ENB = 1;  // 使能引脚 B 为高电平
    
    // 控制电机正反转
    P2 = 0x09;  // 1001 0000
    
    delay(1000);  // 延时 1 秒
    
    // 关闭电机
    P2 = 0x00;  // 0000 0000
    
    ENA = 0;  // 使能引脚 A 为低电平
    ENB = 0;  // 使能引脚 B 为低电平
}

void main()
{
    while (1)
    {
        motor_forward();  // 电机正转
        delay(1000);      // 延时 1 秒
        
        motor_backward(); // 电机反转
        delay(1000);      // 延时 1 秒
    }
}
