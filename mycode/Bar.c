/*
 * Bar.cpp
 *
 *  Created on: Mar 11, 2021
 *      Author: lmthi
 */
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "Bar.h"
#include "image.h"

#define PI 3.14159265359f
uint8_t _counter_pwm = _pwm_step;
uint8_t _color_select = 0;
uint16_t _point_pwm;

//usb
uint8_t usb_data[_nled*2];

uint16_t dataSize = 0;
uint8_t check_usb = 0;
uint16_t data_count;
uint8_t data_ready;
//

uint8_t pwm;
uint8_t _bit_pwm[_nled/8];
volatile uint8_t _r[_nled],_g[_nled],_b[_nled];
volatile uint8_t t_r[_nled],t_g[_nled],t_b[_nled];

const uint8_t _bitmap[8]={1,2,4,8,16,32,64,128};

//gradient var
Color color_s, color_d,color_buf;
Color color_s2, color_d2,color_buf2;
Color cls,cld,temp;

//var
uint8_t var,var1,var2,var3,var4,var5,var6;



char test[] ={"Hello!!/n"};

void _run(void)
{
		data_count = 0;
		data_ready = 0;
		check_usb = 0;
		 HAL_TIM_Base_Start_IT(&htim2);
		 HAL_TIM_Base_Start_IT(&htim3);
		 HAL_Delay(1000);
		 brigthness(30);
		 Color cls = RGB_base_convert(rand()%7);
		 Color cld = RGB_base_convert(rand()%7);
		 Color temp=RGB_base_convert(rand()%7);
		 color_s = cls;
		 color_d = cld;
		 color_s2 = cld;
		 color_d2 = cls;
		 RGB_write(point_to(&_r,&_g,&_b),RGB_base_convert(black),0,_nled-1);

	while(1)
	{
/*
		while(1){

			if(data_ready)
			{
				usb_load(point_to(&_r,&_g,&_b));
				data_ready = 0;
				data_count = 0;
			//	CDC_Transmit_FS("Z",1);
			}
			HAL_Delay(1);
			}

*/

		while(1)
		{

			var5 = rand()%2;
		//	var5 +=2;
		//	var5 = 3;
				switch(var5)
				{
				case 0:
					load_map_h_gradian(point_to(&t_r,&t_g,&t_b),image[rand()%46],RGB_base_convert(black),1,rand()%2);
				break;
				case 1:
					load_map_h_gradian_random2(point_to(&t_r,&t_g,&t_b),image[rand()%46],&gradient_random,&gradient_random2,1);
				break;

				case 2:
					for(int i = 0; i<16; i++) sun_in(100);
					break;
				case 3:

					for(int i = 0; i<16; i++) sun_ou(100);
					break;

				case 4:
					 galaxy_in();
					break;
				case 5:
					 galaxy_ou();
					 break;
				case 6:
					load_map_h_2color_random(point_to(&t_r,&t_g,&t_b),image[rand()%46]);
					break;
				case 7:
					load_map_v_gradianx(point_to(&t_r,&t_g,&t_b),image[rand()%46],RGB_base_convert(black),1,rand()%2);
					break;
				default:
					break;
				}
				var6++;
									var3 = rand()%2;

									if(var3)
									{
										var = rand()%2;
										var1 = rand()%2;
										for(int i = 0; i<64; i++)
										{

										 if (var) rota_mx_ud(point_to(&t_r,&t_g,&t_b),var1,1);
										 else rota_mx_lr(point_to(&t_r,&t_g,&t_b),var1,1);

										 graphic_updata();
										// graphic_updata_DMA();
										 HAL_Delay(100);
										}
									}
									else
									{

										var = rand()%2;
										var1 = rand()%2;
										var4 = rand()%2;
										for(int i = 0; i<64; i++)
										{
										 if (var)
											 {

											 	 rota_mx_lr(point_to(&t_r,&t_g,&t_b),var4,1);
											 	 rota_mx_ud(point_to(&t_r,&t_g,&t_b),var1,1);


											 }
										 else
											 {

											 	 rota_mx_lr(point_to(&t_r,&t_g,&t_b),var1,1);
											 	 rota_mx_ud(point_to(&t_r,&t_g,&t_b),var4,1);

											 }
										 graphic_updata();
										// graphic_updata_DMA();
										 HAL_Delay(100);
										}

									}



		}
			while(1)
			{

			//	 RGB_write(point_to(&_r,&_g,&_b),RGB_base_convert(black),0,_nled-1);
			//	for(int i = 0; i<8; i++) draw_roundL(point_to(&_r,&_g,&_b), rand()%40, rand()%16,1+ rand()%8,RGB_base_convert((rand()%8)));
			//	for(int i = 0; i<64; i++)
			//		{

					rota_mx_ud(point_to(&_r,&_g,&_b),0,1);
					rota_mx_lr(point_to(&_r,&_g,&_b),1,1);
					HAL_Delay(100);
				//	}

			}

		while(1){

			for(int i = 0; i<16; i++) sun_in(30);
			 galaxy_in();
			for(int i = 0; i<16; i++) sun_ou(30);
			 galaxy_ou();

		}

		while(1){
			RGB_write(point_to(&_r,&_g,&_b),RGB_base_convert(black),0,_nled-1);
			for(int i = 0; i<2; i++) galaxy_in();
			RGB_write(point_to(&_r,&_g,&_b),RGB_base_convert(black),0,_nled-1);
			for(int i = 0; i<2; i++) galaxy_ou();
			for(int i = 0; i<2; i++) galaxy_in();
			for(int i = 0; i<2; i++) galaxy_ou();
		}

//		RGB_write(point_to(&_r,&_g,&_b),RGB_convert(rand()%(_pwm_step+1),rand()%(_pwm_step+1),rand()%(_pwm_step+1)),0,0);
//		RGB_rotatal(point_to(&_r,&_g,&_b),0,31,1);

		cls = temp;
		cld =RGB_base_convert(rand()%8);
		temp = cld;
		while(RGB_color_change(&cls,&cld,1)==0)
		{
		//	RGB_write(point_to(&_r,&_g,&_b),cls,0,0);
		//	RGB_rotatal(point_to(&_r,&_g,&_b),0,_nled-1,0);

			RGB_write(point_to(&_r,&_g,&_b),cls,0,_nled-1);
			//	Delayms(50);

			HAL_Delay(100);
		}

		HAL_Delay(2000);

			//		HAL_SPI_Transmit(&hspi2,&temp,4,0);
			//		_LAT();
			//		_OE_ENABLE();
//
	}

}




void graphic_updata(void)
{
	for(int i = 0;i<_nled;i++)
	{
		_r[i]=t_r[i];
		_g[i]=t_g[i];
		_b[i]=t_b[i];

	}
}

void graphic_updata_DMA(void)
{

	HAL_DMA_Start(&hdma_memtomem_dma1_channel1,&t_r, &_r,_nled);
	HAL_DMA_PollForTransfer(&hdma_memtomem_dma1_channel1, HAL_DMA_FULL_TRANSFER, 1000);
	HAL_DMA_Start(&hdma_memtomem_dma1_channel4,&t_g, &_g,_nled);
	HAL_DMA_PollForTransfer(&hdma_memtomem_dma1_channel4, HAL_DMA_FULL_TRANSFER, 1000);
	HAL_DMA_Start(&hdma_memtomem_dma1_channel6,&t_b, &_b,_nled);
	HAL_DMA_PollForTransfer(&hdma_memtomem_dma1_channel6, HAL_DMA_FULL_TRANSFER, 1000);


}


void usb_load(RGB_pointer point)
{
	uint16_t MSB;
	uint16_t LSB;
	uint16_t tem;
	for(int i = 0;i<_nled;i++){
		LSB = usb_data[i*2];
		MSB = usb_data[(i*2)+1];
		tem = (MSB<<8)|LSB;
		point.r_pointer[i] =(uint8_t)(tem&0x001F);
		point.g_pointer[i] =(uint8_t)((tem>>5)&0x001F);
		point.b_pointer[i] = (uint8_t)((tem>>10)&0x001F);
	}

}




Color gradient_random(int step)
{

			while(RGB_color_change(&color_s,&color_d,step))
			{
				color_s =color_d ;
				color_d =RGB_base_convert(1+rand()%7);
			}
			return color_s;
}


Color gradient_random2(int step)
{

			while(RGB_color_change(&color_s2,&color_d2,step))
			{
				color_s2 =color_d2 ;
				color_d2 =RGB_base_convert(1+rand()%7);
			}
			return color_s2;
}


Color color_random(uint8_t rate)
{
	Color _cl;
	if(rate<=0) rate = 1;
	_cl = RGB_base_convert(rand()%8);
	_cl.b_cl /=rate;
	_cl.g_cl /=rate;
	_cl.r_cl /=rate;
	return _cl;
}


void load_map_h_gradian_random(RGB_pointer point, uint8_t* map, int step)
{
	uint8_t data,n;
	Color _cl,_cl2;
	for(int i = 0;i<16;i++)
	{
		do {
			_cl = gradient_random(step);
			_cl2 = gradient_random2(step);
			} while (check_color_eq(_cl2,_cl));

		for(int j = 0;j<40;j++)
		{
			data = (j/8)+(5*i);
				n=j%8;
			if(map[data]&(1<<n))
				{
					write_matrix(point, j, i,_cl);
				}
			else write_matrix(point, j, i,_cl2);
		}
	}
}




int check_color_eq(Color cl1, Color cl2)
{
	if((cl1.r_cl==cl2.r_cl)&&(cl1.g_cl==cl2.g_cl)&&(cl1.b_cl==cl2.b_cl)) return 1;
	return 0;


}


void load_map_h_2color_random(RGB_pointer point, uint8_t* map)
{
	uint8_t data,n;
	Color _cl,_cl2;
	do {
		_cl =color_random(1);
		_cl2 = color_random(1);
		} while (check_color_eq(_cl2,_cl));

	for(int i = 0;i<16;i++)
	{
		for(int j = 0;j<40;j++)
		{
			data = (j/8)+(5*i);
				n=j%8;
			if(map[data]&(1<<n))
				{
					write_matrix(point, j, i,_cl);
				}
			else write_matrix(point, j, i,_cl2);
		}
	}
}



void load_map_h_gradian_random2(RGB_pointer point, uint8_t* map,Color (*color_gen)(int),Color (*color_gen2)(int), int step)
{
	uint8_t data,n;
	Color _cl,_cl2;
	for(int i = 0;i<16;i++)
	{
		do {
		_cl =color_gen(step);
		_cl2 = color_gen2(step);
		} while (check_color_eq(_cl2,_cl));


		for(int j = 0;j<40;j++)
		{
			data = (j/8)+(5*i);
				n=j%8;
			if(map[data]&(1<<n))
				{
					write_matrix(point, j, i,_cl);
				}
			else write_matrix(point, j, i,_cl2);
		}
	}
}




void load_map_h_gradian(RGB_pointer point, uint8_t* map,Color backgroud, int step, int inv)
{
	uint8_t data,n;
	Color _cl,_cl2;
	for(int i = 0;i<16;i++)
	{

		if(inv)  {
				_cl = gradient_random(step);
				_cl2 = backgroud;

			}
		else	{
				_cl2 = gradient_random(step);
				_cl = backgroud;
			}

		for(int j = 0;j<40;j++)
		{
			data = (j/8)+(5*i);
				n=j%8;
			if(map[data]&(1<<n))
				{
					write_matrix(point, j, i,_cl);
				}
			else	write_matrix(point, j, i,_cl2);
		}
	}
}



void load_map_v_gradianx(RGB_pointer point, uint8_t* map,Color backgroud, int step,int inv)
{
	int lsb, msb,data;
	Color _cl,_cl2;
	for(int i = 0;i<40;i++)
	{
	if(inv)  {
				_cl = gradient_random(step);
				_cl2 = backgroud;

			}
		else	{
				_cl2 = gradient_random(step);
				_cl = backgroud;
			}

		lsb= map[i*2];
		msb = map[(i*2)+1];
		data = lsb|(msb<<8);
		for(int j = 0;j<16;j++)
		{

			if(data&(1<<j)) write_matrix(point, i, j, _cl);
			else write_matrix(point, i, j, _cl2);
		}
	}
}



void load_map_h(RGB_pointer point, uint8_t* map,Color _cl)
{
	uint8_t data;
	for(int i = 0;i<16;i++)
	{
		for(int j = 0;j<40;j++)
		{
			data = (j/8)+(5*i);
			if(map[data]&(1<<(j%8))) write_matrix(point, j, i, _cl);
		}
	}
}




void load_map_v_gradian(RGB_pointer point, uint8_t* map,Color (*color_gen)(int), int step)
{
	int lsb, msb,data;
	Color _cl;
	for(int i = 0;i<40;i++)
	{
		lsb= map[i*2];
		msb = map[(i*2)+1];
		data = lsb|(msb<<8);
		_cl = color_gen(step);
		for(int j = 0;j<16;j++)
		{

			if(data&(1<<j)) write_matrix(point, i, j, _cl);
		}
	}
}

void load_map_v(RGB_pointer point, uint8_t* map,Color _cl)
{
	int lsb, msb,data;
	for(int i = 0;i<40;i++)
	{
		lsb= map[i*2];
		msb = map[(i*2)+1];
		data = lsb|(msb<<8);
		for(int j = 0;j<16;j++)
		{
			if(data&(1<<j)) write_matrix(point, i, j, _cl);
		}
	}
}



 void draw_roundL(RGB_pointer point,int x, int y,int r,Color _cl)
    {
        int xx, yy;
        for(int i= 0;i<360;i++)
        {
        	xx = (int)(x + (float)r * cos(i * (PI / 180)));
        	yy = (int)(y + (float)r * sin(i *(PI / 180)));
        	write_matrix(point, xx, yy, _cl);
        }

    }


void sun_in(int hold){
	for(int i = 0; i<16; i++){
		if(RGB_color_change(&cls,&cld,1)!=0)
		{
			cls = temp;
			cld =RGB_base_convert((rand()%8));
			temp = cld;
		}
		rota_mx_ud(point_to(&_r,&_g,&_b),1,0);
	for(int j=0;j<40;j++){
	write_matrix(point_to(&_r,&_g,&_b),j,15,cls);

		}
		HAL_Delay(hold);
	}
}

void sun_ou(int hold){
	for(int i = 0; i<16; i++){
			if(RGB_color_change(&cls,&cld,1)!=0)
			{
				cls = temp;
				cld =RGB_base_convert(1+(rand()%7));
				temp = cld;
			}
		rota_mx_ud(point_to(&_r,&_g,&_b),0,0);
		for(int j=0;j<40;j++){
		write_matrix(point_to(&_r,&_g,&_b),j,0,cls);
			}
		HAL_Delay(hold);
		}
}

void galaxy_in(void){
	for(int i = 0; i<16; i++){
		if(RGB_color_change(&cls,&cld,1)!=0)
		{
			cls = temp;
			cld =RGB_base_convert(1+(rand()%7));
			temp = cld;
		}
	for(int j=0;j<40;j++){
	rota_mx_ud(point_to(&_r,&_g,&_b),0,1);
	write_matrix(point_to(&_r,&_g,&_b),j,0,cls);
	HAL_Delay(50);
		}
	}
}


void galaxy_ou(void){
	for(int i = 0; i<16; i++){
		if(RGB_color_change(&cls,&cld,1)!=0)
		{
			cls = temp;
			cld =RGB_base_convert(1+(rand()%7));
			temp = cld;
		}

	for(int j=0;j<40;j++){
	rota_mx_ud(point_to(&_r,&_g,&_b),1,1);
	write_matrix(point_to(&_r,&_g,&_b),j,15,cls);
	HAL_Delay(50);
		}
	}

}


void write_matrix(RGB_pointer point,int x, int y,Color _cl)// y=16
{
	if(y>=16) y = 15;
	if(x>=40) x= 39;
	point.r_pointer[x*16+y] = _cl.r_cl;
	point.g_pointer[x*16+y] = _cl.g_cl;
	point.b_pointer[x*16+y] = _cl.b_cl;
}


Color read_matrix(RGB_pointer point,int x, int y)
{
	Color tem;
	if(y>=16) y = 15;
	if(x>=40) x= 39;
	tem.r_cl= point.r_pointer[x*16+y];
	tem.g_cl= point.g_pointer[x*16+y];
	tem.b_cl= point.b_pointer[x*16+y];
	return tem;
}

void rota_mx_lr(RGB_pointer point,char ud, char roll)
{
	Color tem;
		if(ud==1){
		for(int i=0;i<16;i++){
			if(roll==1) tem = read_matrix(point,0,i);
			for(int j=0;j<39;j++) write_matrix(point,j,i,read_matrix(point,j+1,i));
			if(roll==1) write_matrix(point,39,i,tem);
		}


		}
		else{

			for(int i=0;i<16;i++){
			if(roll==1) tem = read_matrix(point,39,i);
			for(int j=0;j<39;j++) write_matrix(point,39-j,i,read_matrix(point,39-(j+1),i));
			if(roll==1) write_matrix(point,0,i,tem);
		}

}
}


void rota_mx_ud(RGB_pointer point,char ud, char roll)
{
	Color tem;
	if(ud==1){
	for(int j=0;j<40;j++){
		if(roll==1) tem = read_matrix(point,j,0);
		for(int i=0;i<15;i++) write_matrix(point,j,i,read_matrix(point,j,i+1));
		if(roll==1) write_matrix(point,j,15,tem);
	}

	}
	else{
	for(int j=0;j<40;j++){
		if(roll==1) tem = read_matrix(point,j,15);
		for(int i=0;i<15;i++) write_matrix(point,j,15-i,read_matrix(point,j,15-(i+1)));
		if(roll==1) write_matrix(point,j,0,tem);
	}
	}
}




uint8_t RGB_color_change(Color* cl_s,Color* cl_d,uint8_t ratio)
{
	if ((cl_s->b_cl==cl_d->b_cl) &&(cl_s->g_cl==cl_d->g_cl) &&(cl_s->r_cl ==cl_d->r_cl)) return 1;
	for (uint8_t i =0;i<ratio;i++)
	{
		if (cl_s->r_cl>cl_d->r_cl)  cl_s->r_cl-=1;
		else if (cl_s->r_cl<cl_d->r_cl)  cl_s->r_cl+= 1;

		if (cl_s->g_cl>cl_d->g_cl) cl_s->g_cl -=1;
		else if (cl_s->g_cl<cl_d->g_cl) cl_s->g_cl  += 1;

		if (cl_s->b_cl>cl_d->b_cl) cl_s->b_cl -=1;
		else if (cl_s->b_cl<cl_d->b_cl) cl_s->b_cl  += 1;
	}
	return 0;
}




void Delayms(uint16_t _t)
{
	for(uint16_t j = 0;j<_t;j++) for(uint16_t i = 0;i<=3600;i++);
}


void RGB_write(RGB_pointer point,Color _cl,uint16_t first_point,uint16_t last_point)
{
	uint16_t _num =( last_point - first_point);
		for (uint16_t i = 0;i<=_num;i++)
			{
				point.r_pointer[first_point+i] = _cl.r_cl;
				point.g_pointer[first_point+i] = _cl.g_cl;
				point.b_pointer[first_point+i] = _cl.b_cl;
			}


}


void RGB_rotatal(RGB_pointer point,uint16_t first_point,uint16_t last_point,uint8_t direct)
{
	Color _buff;
	uint16_t _num = last_point - first_point;
	if (direct==0)
	{
		_buff = RGB_convert(point.r_pointer[first_point],point.g_pointer[first_point],point.b_pointer[first_point]);
		for (uint16_t i = 0;i<_num;i++)
			{
				point.r_pointer[first_point] = point.r_pointer[first_point+1];
				point.g_pointer[first_point] = point.g_pointer[first_point+1];
				point.b_pointer[first_point] = point.b_pointer[first_point+1];
				first_point++;
			}
				point.r_pointer[last_point] = _buff.r_cl;
				point.g_pointer[last_point] = _buff.g_cl;
				point.b_pointer[last_point] = _buff.b_cl;
	}

	else
	{
		_buff = RGB_convert(point.r_pointer[last_point],point.g_pointer[last_point],point.b_pointer[last_point]);

		for (uint16_t i = 0;i<_num;i++)
			{
			point.r_pointer[last_point] = point.r_pointer[last_point-1];
			point.g_pointer[last_point] = point.g_pointer[last_point-1];
			point.b_pointer[last_point] = point.b_pointer[last_point-1];
			last_point--;
			}
				point.r_pointer[first_point] = _buff.r_cl;
				point.g_pointer[first_point] = _buff.g_cl;
				point.b_pointer[first_point] = _buff.b_cl;
	}
}



Color RGB_convert(uint8_t _r,uint8_t _g,uint8_t _b)
{
	Color _temp;
	if(_r>_pwm_step) _r = _pwm_step;
	if(_g>_pwm_step) _g = _pwm_step;
	if(_b>_pwm_step) _b = _pwm_step;
	_temp.r_cl = _r;
	_temp.g_cl = _g;
	_temp.b_cl = _b;
	return _temp;
}

Color RGB_base_convert(Mycolors _color)
{
	Color _temp;
	switch (_color)
	{
	case black:
	_temp.r_cl = 0;
	_temp.g_cl =0;
	_temp.b_cl = 0;
	break;
	case red:
	_temp.r_cl = _pwm_step;
	_temp.g_cl = 0;
	_temp.b_cl = 0;
	break;
	case green:
	_temp.r_cl = 0;
	_temp.g_cl = _pwm_step;
	_temp.b_cl = 0;
	break;
	case blue:
	_temp.r_cl = 0;
	_temp.g_cl = 0;
	_temp.b_cl = _pwm_step;
	break;
	case yellow:
	_temp.r_cl = _pwm_step;
	_temp.g_cl =_pwm_step;
	_temp.b_cl = 0;
	break;
	case purple:
	_temp.r_cl = _pwm_step;
	_temp.g_cl =0;
	_temp.b_cl = _pwm_step;
	break;
	case cyan:
	_temp.r_cl = 0;
	_temp.g_cl =_pwm_step;
	_temp.b_cl = _pwm_step;
	break;

	case white:
	_temp.r_cl = _pwm_step;
	_temp.g_cl =_pwm_step;
	_temp.b_cl = _pwm_step;
	break;
	}
	return _temp;
}



RGB_pointer point_to(uint8_t* _r,uint8_t* _g,uint8_t* _b)
{

	RGB_pointer _temp;
	_temp.r_pointer = _r;
	_temp.g_pointer = _g;
	_temp.b_pointer = _b;
	return _temp;
}




void pwm_nled3(void)
{
	switch(_color_select)
			{
				case 0:
					for(uint16_t i = 0; i<_nled;i++) if(_r[i]>=_counter_pwm) _bit_pwm[i/8] |= _bitmap[i%8];
					if(_counter_pwm==0)
						{
							color_scan();
							_color_select = 1;
						}
						else _counter_pwm--;
				break;
				case 1:
					for(uint16_t i = 0; i<_nled;i++) if(_g[i]>=_counter_pwm) _bit_pwm[i/8] |= _bitmap[i%8];
					if(_counter_pwm==0)
						{
							color_scan();
							_color_select = 2;
						}
						else _counter_pwm--;
				break;
				case 2:
					for(uint16_t i = 0; i<_nled;i++) if(_b[i]>=_counter_pwm) _bit_pwm[i/8] |= _bitmap[i%8];
					if(_counter_pwm==0)
						{
							color_scan();
							_color_select = 0;
						}
						else _counter_pwm--;
				break;
				default:
				break;
			}
			HAL_SPI_Transmit_DMA(&hspi2,&_bit_pwm,_nled/8);


}


void color_scan(void)
{



	HAL_GPIO_WritePin(GPIOA, RED_Pin|GREEN_Pin|BLUE_Pin, GPIO_PIN_SET);
	switch(_color_select)
	{
		case 0:
			HAL_GPIO_WritePin(GPIOA, RED_Pin, GPIO_PIN_RESET);
			break;
		case 1:
			HAL_GPIO_WritePin(GPIOA, GREEN_Pin, GPIO_PIN_RESET);
			break;
		case 2:
			HAL_GPIO_WritePin(GPIOA, BLUE_Pin, GPIO_PIN_RESET);
			break;
		default:
			break;
	}
	for(uint16_t i = 0; i<(_nled/8);i++) _bit_pwm[i] = 0;
		_counter_pwm =_pwm_step;
}


void HAL_SPI_TxCpltCallback(SPI_HandleTypeDef *hspi)
{
	if(hspi==&hspi2)
	{
		_LAT();
		_OE_ENABLE();
	}

}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim)
{

	if(htim==&htim2)
	{
		 pwm_nled3();

	}
	else if(htim==&htim3)
	{
			HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
	}
}

void _LAT(void)
{
	 HAL_GPIO_WritePin(LAT_GPIO_Port,LAT_Pin, GPIO_PIN_SET);

	 HAL_GPIO_WritePin(LAT_GPIO_Port,LAT_Pin, GPIO_PIN_RESET);

}

void _OE_ENABLE(void)
{
	setPWM(htim4, TIM_CHANNEL_1,255, 255-pwm);
//	setPWM(htim4, TIM_CHANNEL_4,255, 0);
//	 HAL_GPIO_WritePin(GPIOB, OE_Pin, GPIO_PIN_RESET);
}
void _OE_DISABLE(void)
{

	setPWM(htim4, TIM_CHANNEL_1,255, 255);
//	HAL_GPIO_WritePin(GPIOB,OE_Pin, GPIO_PIN_SET);
}


void brigthness(uint8_t val)
{
	pwm = val;
}



/* USER CODE BEGIN 4 */
void setPWM(TIM_HandleTypeDef timer, uint32_t channel, uint16_t period,
uint16_t pulse)
{
 HAL_TIM_PWM_Stop(&timer, channel); // stop generation of pwm
 TIM_OC_InitTypeDef sConfigOC;
 timer.Init.Period = period; // set the period duration
 HAL_TIM_PWM_Init(&timer); // reinititialise with new period value
 sConfigOC.OCMode = TIM_OCMODE_PWM1;
 sConfigOC.Pulse = pulse; // set the pulse duration
 sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
 sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
 HAL_TIM_PWM_ConfigChannel(&timer, &sConfigOC, channel);
 HAL_TIM_PWM_Start(&timer, channel); // start pwm generation
}
/* USER CODE END 4 */


