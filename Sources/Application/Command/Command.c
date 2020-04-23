/*
 * Command.c
 *
 *  Created on: 2020年4月19日
 *      Author: Master.HE
 */
#include "Services/Services.h"

#include "Command.h"

const Command_TX_DATA_Type Command_TX_DATA_Default=
{
	.KEY=
	{
		.K1_Up=IO_OFF,
		.K1_Down=IO_OFF,

		.K2_Up=IO_OFF,
		.K2_Down=IO_OFF,

		.K3_Up=IO_OFF,
		.K3_Down=IO_OFF,

		.K4_Up=IO_OFF,
		.K4_Down=IO_OFF,

		.K5_Up=IO_OFF,
		.K5_Down=IO_OFF,

		.K6_Up=IO_OFF,
		.K6_Down=IO_OFF,

		.K7_Up=IO_OFF,
		.K7_Down=IO_OFF,

		.K8_Up=IO_OFF,
		.K8_Down=IO_OFF,
	},
	.Rocker=
	{
		{.X=128,.Y=128},
		{.X=128,.Y=128},
	},
};

const Command_RX_DATA_Type Command_RX_DATA_Default=
{
	.DATA_16Bit={0xFFFF,0xFFFF},
};

Command_TX_DATA_Type Command_TX_DATA;
Command_RX_DATA_Type Command_RX_DATA;

#if defined(__TX__)

#elif defined(__RX__)

#else
#error "NO SET DDR"
#endif

void Command_Init(void)
{

}

void Command_10MS(void)
{
#if defined(__TX__)

	Command_TX_DATA.KEY.K1_Up=Input_GET_DATA(Input_CH_K1_Up);
	Command_TX_DATA.KEY.K1_Down=Input_GET_DATA(Input_CH_K1_Down);

	Command_TX_DATA.KEY.K2_Up=Input_GET_DATA(Input_CH_K2_Up);
	Command_TX_DATA.KEY.K2_Down=Input_GET_DATA(Input_CH_K2_Down);

	Command_TX_DATA.KEY.K3_Up=Input_GET_DATA(Input_CH_K3_Up);
	Command_TX_DATA.KEY.K3_Down=Input_GET_DATA(Input_CH_K3_Down);

	Command_TX_DATA.KEY.K4_Up=Input_GET_DATA(Input_CH_K4_Up);
	Command_TX_DATA.KEY.K4_Down=Input_GET_DATA(Input_CH_K4_Down);

	Command_TX_DATA.KEY.K5_Up=Input_GET_DATA(Input_CH_K5_Up);
	Command_TX_DATA.KEY.K5_Down=Input_GET_DATA(Input_CH_K5_Down);

	Command_TX_DATA.KEY.K6_Up=Input_GET_DATA(Input_CH_K6_Up);
	Command_TX_DATA.KEY.K6_Down=Input_GET_DATA(Input_CH_K6_Down);

	Command_TX_DATA.KEY.K7_Up=Input_GET_DATA(Input_CH_K7_Up);
	Command_TX_DATA.KEY.K7_Down=Input_GET_DATA(Input_CH_K7_Down);

	Command_TX_DATA.KEY.K8_Up=Input_GET_DATA(Input_CH_K8_Up);
	Command_TX_DATA.KEY.K8_Down=Input_GET_DATA(Input_CH_K8_Down);

	Command_TX_DATA.Rocker[0].X=Input_GET_DATA(Input_CH_Rocker1_X);
	Command_TX_DATA.Rocker[0].Y=Input_GET_DATA(Input_CH_Rocker1_Y);

	Command_TX_DATA.Rocker[1].X=Input_GET_DATA(Input_CH_Rocker2_X);
	Command_TX_DATA.Rocker[1].Y=Input_GET_DATA(Input_CH_Rocker2_Y);

#elif defined(__RX__)

#else
#error "NO SET DDR"
#endif
}

#if defined(__RX__)
uint8_t Command_GET_DATA(uint8_t CH)
{
	switch (CH)
	{
		case Command_CH_K1_Up:
		{
			return Command_TX_DATA.KEY.K1_Up;
		}break;
		case Command_CH_K1_Down:
		{
			return Command_TX_DATA.KEY.K1_Down;
		}break;

		case Command_CH_K2_Up:
		{
			return Command_TX_DATA.KEY.K2_Up;
		}break;
		case Command_CH_K2_Down:
		{
			return Command_TX_DATA.KEY.K2_Down;
		}break;

		case Command_CH_K3_Up:
		{
			return Command_TX_DATA.KEY.K3_Up;
		}break;
		case Command_CH_K3_Down:
		{
			return Command_TX_DATA.KEY.K3_Down;
		}break;

		case Command_CH_K4_Up:
		{
			return Command_TX_DATA.KEY.K4_Up;
		}break;
		case Command_CH_K4_Down:
		{
			return Command_TX_DATA.KEY.K4_Down;
		}break;

		case Command_CH_K5_Up:
		{
			return Command_TX_DATA.KEY.K5_Up;
		}break;
		case Command_CH_K5_Down:
		{
			return Command_TX_DATA.KEY.K5_Down;
		}break;

		case Command_CH_K6_Up:
		{
			return Command_TX_DATA.KEY.K6_Up;
		}break;
		case Command_CH_K6_Down:
		{
			return Command_TX_DATA.KEY.K6_Down;
		}break;

		case Command_CH_K7_Up:
		{
			return Command_TX_DATA.KEY.K7_Up;
		}break;
		case Command_CH_K7_Down:
		{
			return Command_TX_DATA.KEY.K7_Down;
		}break;

		case Command_CH_K8_Up:
		{
			return Command_TX_DATA.KEY.K8_Up;
		}break;
		case Command_CH_K8_Down:
		{
			return Command_TX_DATA.KEY.K8_Down;
		}break;

		//摇杆
		case Command_CH_Rocker1_X:
		{
			return Command_TX_DATA.Rocker[0].X;
		}break;
		case Command_CH_Rocker1_Y:
		{
			return Command_TX_DATA.Rocker[0].Y;
		}break;

		case Command_CH_Rocker2_X:
		{
			return Command_TX_DATA.Rocker[1].X;
		}break;
		case Command_CH_Rocker2_Y:
		{
			return Command_TX_DATA.Rocker[1].Y;
		}break;

		default:
		{
			return 0;
		}break;
	}


}
#endif
