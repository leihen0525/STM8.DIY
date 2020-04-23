/*
 * RF.LT8920.Cfg.c
 *
 *  Created on: 2020年4月18日
 *      Author: Master.HE
 */
#include "RF.LT8920.Cfg.h"

const RF_LT8920_Register_Init_Type RF_LT8920_Register_Init[]=
{
	{ 0, 0x6fef },
	{ 1, 0x5681 },
	{ 2, 0x6617 },
	{ 4, 0x9cc9 },
	{ 5, 0x6637 },
	{ 7, 0x0000 },							  //channel is 2402Mhz
	{ 8, 0x6c90 },
	{ 9, 0x4800 },			  				  //PA -12.2dbm
	{10, 0x7ffd },
	{11, 0x0008 },
	{12, 0x0000 },
	{13, 0x48bd },
	{22, 0x00ff },
	{23, 0x8005 },//1:在 TX/RX 开启前重新校准 VCO
	{24, 0x0067 },
	{25, 0x1659 },
	{26, 0x19e0 },
	{27, 0x1300 },
	{28, 0x1800 },
	{32, 0xEA40 },//8920在62.5kbps下同步头只能是32或16bit
	{33, 0x3fc7 },
	{34, 0x2000 },
	{35, 0x0500 },				    /* 重发次数为9次 一共发3次*/
//#ifdef SYNC_TEST
	{36, 0x0380 },
	{37, 0x0380 },
	{38, 0x5a5a },
	{39, 0x0380 },
//#else
	//{36, 0x0380 },
	//{37, 0x0380 },
	//{38, 0x5a5a },
	//{39, 0x0380 },
//#endif
	{40, 0x4402 },//?????
	//{41, 0xb400 },	/*CRC is ON; scramble is OFF; AUTO_ACK is OFF*/
	{41, 0xb800 },	        /*CRC is ON; scramble is OFF; AUTO_ACK is ON*/
	{42, 0xfdFF },					/*等待RX_ACK时间 176us*/
	{43, 0x000f },
	{44, 0x1000 },
	{45, 0x0552 },		 //62.5k
	{50, 0x0000 },
};
uint8_t RF_LT8920_GET_Init_Len(void)
{
	return (sizeof(RF_LT8920_Register_Init)/sizeof(RF_LT8920_Register_Init_Type));
}
