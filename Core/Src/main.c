/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Bare Metal Code to Blink built-in led 
  * @author         : Sarthak Chaudhary
  * @date           : April 19, 2025
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/


#define GPIOC_EN           (1U<<4)    
                                      
#define PIN13              (1U<<13)   
#define LED_PIN             PIN13
#define LED_OFF             (1U<<29)
  

#define GPIOA_EN           (1U<<2)
#define INPUT_PIN           (1U<<6)




/* USER CODE END Includes */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 2 */
	/*Enable clock access to GPIOC*/
	RCC->APB2ENR |= GPIOC_EN;

  GPIOC->CRH |= (1U<<20);
  GPIOC->CRH |= (1U<<21);
  GPIOC->CRH &= ~(1U<<22);
  GPIOC->CRH &= ~(1U<<23);



  RCC->APB2ENR |=GPIOA_EN;

  GPIOA->CRH &= ~(1U<<24);
  GPIOA->CRH &= ~(1U<<25);
  GPIOA->CRH &= ~(1U<<26);
  GPIOA->CRH &= ~(1U<<24);


  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

    if(GPIOA->IDR & INPUT_PIN)
    {
      GPIOC->ODR &= ~LED_PIN;
      // GPIOC->BSRR = LED_OFF;
    }
    else
    {
      // GPIOC->BSRR = LED_PIN;
      GPIOC->ODR |=LED_PIN;
    }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}
 