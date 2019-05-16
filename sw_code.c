/*********************************************************************************************************
** ������ ������һ�����ϵļ�ͷ
** ����˵�� ���˳����õ�������200us/������1000us/��ͼ��Ƶ�ʵ����壬8��ϸ�ֱ�����
** ����Ƶ�� ��12Mhz
** ע������ϵ�Ѿ�������������������ϵ
*********************************************************************************************************/		 
#include<reg52.h>
#include<LCD1602.h>
#include<math.h>
#include<float.h>
#define uchar	unsigned char
#define uint	unsigned int

const float PI=3.141593;

uint Cont = 0;	 //ContΪ����������еĲ���
bit flag = 0;	 //��Ϊ������0����ͼ��1���ı�־λ�����ߵ����Ƶ�ʲ�һ��	

/*********************************************************************************************************
** �������弰���������������뵥Ƭ���Ľӿڶ���
*********************************************************************************************************/

sbit xsr=P1^3;   //�������壺x�����˶�����(��)
sbit xsl=P1^0;   //�������壺x�����˶�����(ǰ)
sbit xen=P2^0;   //����x����ʹ�ܵĶ˿�
sbit xcw=P2^1;   //����x����ת��Ķ˿�
sbit xcp=P2^2;   //�������x����������˿�


sbit ysr=P1^4;   //�������壺y�����˶�����(��)
sbit ysl=P1^1;   //�������壺y�����˶�����(��)
sbit yen=P2^3;   //����y����ʹ�ܵĶ˿�
sbit ycw=P2^4;   //�������y����ת��Ķ˿�
sbit ycp=P2^5;   //�������y����������˿�


sbit zsr=P1^5;   //�������壺z�����˶�����(��)
sbit zsl=P1^2;   //�������壺z�����˶�����(��)
sbit zen=P2^6;	 //����z����ʹ�ܵĶ˿�
sbit zcw=P2^7;	 //�������z����ת��Ķ˿�
sbit zcp=P1^7;	 //�������z����������˿�

/*********************************************************************************************************
** �������� ���ϵ��ʼ��
*********************************************************************************************************/
void Motor_INIT()  //���������ʼ��
{
	xen=0;
	yen=0;
	zen=0;
}
void TIM_INIT()	    		//��ʱ����ʼ��
{  
   TMOD = 0x01;     		//��ʱ��0,������ʽ1 	                 	  
   PCON = 0x80;     		//SMOD=1;      								 
   TH0=0Xff;   TL0=0X9b;	//��ʱ��0װ��ֵ
   ET0=1;                   //��ʱ��0�����ж�
   TR0=1;             		//timer 0 run  
   EA=1; 					//CPU�����ж�
}
/*********************************************************************************************************
** �������� ����ʱ���ж����ã����ö�ʱ��������������
*********************************************************************************************************/
void timer0 () interrupt 1 using 2
{
	if(flag)				 
		{TH0=0xfe; TL0=0x01;}		//��ͼ����1020us
	else
		{TH0=0xff; TL0=0x9b;} 		//��������200us   5K Hz
 	if (Cont!=0)					//Ҫ�ߵĲ���Cont��Ϊ0����û���������	  
	{
		Cont--;
		if(xen==1)
		{ 
		   xcp=~xcp;				//����1����ȡ��
		}
		if(yen==1)
		{ 
		   ycp=~ycp;
		}
        if(zen==1)
		{ 
		   zcp=~zcp;
		}
   	}		
}

/*********************************************************************************************************								
			3��������X_Move(���򣬴�С)��Y_Move(���򣬴�С)��Z_Move(���򣬴�С)
			   ����1 Ϊ����0 Ϊ��
			   ��С��1 ~ 16000
*********************************************************************************************************/
void X_Move(bit direction,uint dx)
{
	xen=1;yen=0;zen=0;                       //x����ʹ��
	xcw=direction;ycw=0;zcw=0;      	 	 //x����ת��   ��������ϵ������Ϊ������
	Cont=dx;
	while(Cont!=0);
	xcp=1;
}
void Y_Move(bit direction,uint dy)
{
	xen=0;yen=1;zen=0;                       //y����ʹ��
	xcw=0;ycw=~direction;zcw=0;      		 //y����ת��
	Cont=dy;
	while(Cont!=0);
	ycp=1;
}
void Z_Move(bit direction,uint dz)
{
	xen=0;yen=0;zen=1;                       //z����ʹ��
	xcw=0;ycw=0;zcw=direction;      		 //z����ת��
	Cont=dz;
	while(Cont!=0);
	zcp=1;
}
/********************************************************************************************************
** �������� ������ɨ��
*********************************************************************************************************/
void SCAN_KEY()
{
	flag=0;
	if(xsr==0)
	{
	 X_Move(1,100);
	} 
	else if(xsl==0)
	{
	 X_Move(0,100);
	} 
	if(ysr==0)
	{
	 Y_Move(1,100);
	} 
	else if(ysl==0)
	{
	 Y_Move(0,100);
	} 
	if(zsr==0)
	{
	 Z_Move(1,100);
	} 
	else if(zsl==0)
	{												   
	 Z_Move(0,100);
	}
}

/********************************************************************************************************
** �������� ������X��Y�������ķ����߶�
*********************************************************************************************************/
void Line(int X,int Y)
{
	int t=0;
	float k=0;
	uint dx=0,dy=0;
	if(X!=0)
	{
		k=(1.0*Y)/(1.0*X);
		dx=97;
		dy=1*(abs(1*(97.0*k)));	
		for(t=0;t<abs(0.65*X);t++)				//	ϵ��	0.65  ��Ϊ������Բ�İ뾶������ 
		{		
			X_Move(X>0?1:0,97);
			Y_Move(Y>0?1:0,dy);
		}
	}
	else
	{
		dy=97;
		for(t=0;t<abs(0.65*Y);t++)				//	ϵ��	0.65  ��Ϊ������Բ�İ뾶������ 
		{		
			Y_Move(Y>0?1:0,dy);
		}
	}
}
/********************************************************************************************************
** �������� ����д����0-9
*********************************************************************************************************/
void xieshu()
{
	  Line(200,0);		//д0
	  Line(0,400);
	  Line(-200,0);
	  Line(0,-400);	
	  Z_Move(0,5000);   //д0���
	  Line(100,-100);
	  Z_Move(1,5000);
	  Line(0,-400);		 //д1
	  Z_Move(0,5000);   //д1���
	  Line(-100,-100);
	  Z_Move(1,5000);
	  Line(200,0);		//д2
	  Line(0,-200);     
	  Line(-200,0);
	  Line(0,-200);
	  Line(200,0);
	  Z_Move(0,5000);   //д2���
	  Line(-200,-100);
	  Z_Move(1,5000);
	  Line(200,0);	   //д3
	  Line(0,-400);	  
	  Line(-200,0);
	  Z_Move(0,5000);
	  Line(0,200);
	  Z_Move(1,5000);
	  Line(200,0);
	  Z_Move(0,5000);   //д3���
	  Line(-200,-300);
	  Z_Move(1,5000);
	  Line(0,-200);     //д4
	  Line(200,0);
	  Line(0,200);
	  Line(0,-400);
	  Z_Move(0,5000);	//д4���
	  Line(500,0);
	  Z_Move(1,5000);
	  Line(200,0);       //д5
	  Line(0,200);
	  Line(-200,0);
	  Line(0,200);
	  Line(200,0);
	  Z_Move(0,5000);	  //д5���
	  Line(0,100);
	  Z_Move(1,5000);
	  Line(-200,0);       //д6
	  Line(0,400);
	  Line(0,-200);
	  Line(200,0);
	  Line(0,-200);
	  Z_Move(0,5000);	  //д6���
	  Line(0,500);
	  Z_Move(1,5000);
	  Line(0,400);       //д7
	  Line(-200,0);
	  Z_Move(0,5000);	  //д7���
	  Line(0,100);
	  Z_Move(1,5000);
	  Line(0,400);       //д8
	  Line(200,0);
	  Line(0,-400);
	  Line(-200,0);
	  Line(0,200);
	  Line(200,0);
	  Z_Move(0,5000);	  //д8���
	  Line(0,300);
	  Z_Move(1,5000);
	  Line(0,400);       //д9 
	  Line(-200,0);
	  Line(0,-200);
	  Line(200,0);
	  Z_Move(0,5000);	  //д9���
	  Line(100,0);
}
void main()
{
	TIM_INIT();		     //��ʱ����ʼ��
	Motor_INIT();	     //����������г�ʼ��
	LCD_1602_Init();     //Һ����ʾǰ���г�ʼ��
	flag=1;				 //��ʼ��Ϊ��������Ƶ��
	Write_1602_String("XIESHU",0X80);
	Write_1602_String("x,y,z direction",0XC0);

    xieshu();
	while(1)
		{
			SCAN_KEY();			
		}			
}