/*
 * Bar.h
 *
 *  Created on: Mar 11, 2021
 *      Author: lmthi
 */

#ifndef BAR_H_
#define BAR_H_

#include "main.h"
#include "stm32f1xx_hal_spi.h"
#include "stm32f1xx_hal_tim.h"
#include "usbd_cdc_if.h"

#define _nled 640
#define _pwm_step 8

//extern volatile uint8_t usb_packet[1000];
extern uint8_t usb_data[_nled*2];
extern uint16_t dataSize;
extern uint8_t check_usb;
extern uint16_t data_count;
extern uint8_t data_ready;

typedef struct rgb_pointer{
    uint8_t* r_pointer;
    uint8_t* g_pointer;
    uint8_t* b_pointer;
} RGB_pointer;

typedef struct color{
    uint8_t r_cl;
    uint8_t g_cl;
    uint8_t b_cl;
} Color;

typedef struct point{
	int X;
	int Y;
}Point;

typedef enum colors		//base color
{
	black=0,
	red,
	green,
	blue,
	yellow,
	cyan,
	purple,
	white,
}Mycolors;

extern SPI_HandleTypeDef hspi2;
extern DMA_HandleTypeDef hdma_spi2_tx;

extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;
extern TIM_HandleTypeDef htim4;

extern DMA_HandleTypeDef hdma_memtomem_dma1_channel6;
extern DMA_HandleTypeDef hdma_memtomem_dma1_channel4;
extern DMA_HandleTypeDef hdma_memtomem_dma1_channel1;
extern DMA_HandleTypeDef hdma_memtomem_dma1_channel7;

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/
void graphic_updata_DMA(void);
void graphic_updata(void);
void load_map_h_gradian_random(RGB_pointer point, uint8_t* map, int step);
void load_map_h_2color_random(RGB_pointer point, uint8_t* map);
int check_color_eq(Color cl1, Color cl2);
Color gradient_random2(int step);
Color gradient_random(int step);
Color color_random(uint8_t rate);
void load_map_v_gradianx(RGB_pointer point, uint8_t* map,Color backgroud, int step,int inv);
void load_map_h_gradian(RGB_pointer point, uint8_t* map,Color backgroud, int step, int inv);
void load_map_h(RGB_pointer point, uint8_t* map,Color _cl);
void load_map_v_gradian(RGB_pointer point, uint8_t* map,Color (*color_gen)(int), int step);
void load_map_v(RGB_pointer point, uint8_t* map,Color _cl);

 void usb_load(RGB_pointer point);
 void sun_in(int hold);
 void sun_ou(int hold);
 void galaxy_ou(void);
 void galaxy_in(void);
 void rota_mx_lr(RGB_pointer point,char ud, char roll);
 void rota_mx_ud(RGB_pointer point,char ud, char roll);
 void write_matrix(RGB_pointer point,int x, int y,Color _cl);// y=16
 Color read_matrix(RGB_pointer point,int x, int y);
 uint8_t RGB_color_change(Color* cl_s,Color* cl_d,uint8_t ratio);
 void Delayms(uint16_t _t);
 void RGB_write(RGB_pointer point,Color _cl,uint16_t first_point,uint16_t last_point);
 RGB_pointer point_to(uint8_t* _r,uint8_t* _g,uint8_t* _b);
 Color RGB_convert(uint8_t _r,uint8_t _g,uint8_t _b);
 Color RGB_base_convert(Mycolors _color);
 void RGB_rotatal(RGB_pointer point,uint16_t first_point,uint16_t last_point,uint8_t direct);
 void color_scan(void);
 void pwm_nled3(void);
 void _LAT(void);
 void _OE_ENABLE(void);
 void _OE_DISABLE(void);
 void setPWM(TIM_HandleTypeDef, uint32_t, uint16_t, uint16_t);
 void brigthness(uint8_t val);
 void _run(void);
#endif /* BAR_H_ */
