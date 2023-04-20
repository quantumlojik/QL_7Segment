/*
  Quantum Lojik (info@quantumlojik.com | www.quantumlojik.com)
  Tek parça 7 segment display'ler için geliştirilmiştir.
  v1.0 Nisan 2023
  Aykut Taşdelen
*/

#include <QL_7Segment.h>

static GPIO_TypeDef* port;

static uint16_t pins[8];

/*
 * Port ve pin ayarlamalarını gerçekleştirir.
   1. parametresi: Hangi port'un kullanılacağını belirler (Örn: GPIOA)
   2 - 9. parametreler: LED pinlerinin bağlandığı pin numaralarıdır (Örn: GPIO_PIN_5)
*/
void QL7S_Init(GPIO_TypeDef* PORT, uint16_t P1, uint16_t P2, uint16_t P3,
		uint16_t P4, uint16_t P5, uint16_t P6, uint16_t P7, uint16_t P8)
{
	port = PORT;
	pins[0] = P1;
	pins[1] = P2;
	pins[2] = P3;
	pins[3] = P4;
	pins[4] = P5;
	pins[5] = P6;
	pins[6] = P7;
	pins[7] = P8;

	QL7S_Clear();
}


// 8 bitlik sayının tüm bitlerini ilgili port'un pinlerine yazar
void QL7S_WriteToPort(uint8_t number)
{
	int t, and_maskesi;

	for (int i = 7; i >= 0; --i)
	{
		and_maskesi = 1 << i;
		t = number & and_maskesi;
		HAL_GPIO_WritePin(port, pins[i], t);
	}
}

// Parametresine gönderilen sayıyı gösterir
void QL7S_DisplayNumber(uint8_t number)
{
	switch (number)
	{
	case 0:
		QL7S_WriteToPort(0b11101101);
		break;
	case 1:
		QL7S_WriteToPort(0b00101000);
		break;
	case 2:
		QL7S_WriteToPort(0b11001011);
		break;
	case 3:
		QL7S_WriteToPort(0b01101011);
		break;
	case 4:
		QL7S_WriteToPort(0b00101110);
		break;
	case 5:
		QL7S_WriteToPort(0b01100111);
		break;
	case 6:
		QL7S_WriteToPort(0b11100110);
		break;
	case 7:
		QL7S_WriteToPort(0b00101001);
		break;
	case 8:
		QL7S_WriteToPort(0b11101111);
		break;
	case 9:
		QL7S_WriteToPort(0b00101111);
		break;
	}
}

// Nokta'yı gösterir
void QL7S_DisplayPoint()
{
	QL7S_WriteToPort(0b00010000);
}

// 7 segment üzerindeki tüm LED'leri söndürür
void QL7S_Clear()
{
	QL7S_WriteToPort(0b00000000);
}
