/*
  Quantum Lojik (info@quantumlojik.com | www.quantumlojik.com)
  Tek parça 7 segment display'ler için geliştirilmiştir.
  v1.0 Nisan 2023
  Aykut Taşdelen
*/

#ifndef QL_SEVENSEGMENT_H_
#define QL_SEVENSEGMENT_H_

#include "stm32f4xx_hal.h"

void QL7S_Init(GPIO_TypeDef* PORT, uint16_t P1, uint16_t P2, uint16_t P3, uint16_t P4,
		                           uint16_t P5, uint16_t P6, uint16_t P7, uint16_t P8);

void QL7S_WriteToPort(uint8_t number);

void QL7S_DisplayNumber(uint8_t number);

void QL7S_DisplayPoint();

void QL7S_Clear();

#endif
