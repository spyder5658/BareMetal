/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Bare Metal Code to Blink built-in led 
  * @author         : Sarthak Chaudhary
  * @date           : April 12, 2025
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
/* USER CODE BEGIN Includes */

/*   Understand the below addresses and their significance by reading the blog title know the architecture*/


// #define PERIPHERAL_BASE             (0x40000000UL)
// #define APB2PHERIPHERAL_OFFSET      (0x10000UL)
// #define APB2PERIPHERAL_BASE          (PERIPHERAL_BASE + APB2PHERIPHERAL_OFFSET)

// #define GPIOC_OFFSET                 (0x1000UL)
// #define GPIOC_BASE         (APB2PERIPH_BASE + GPIOC_OFFSET)

// #define RCC_OFFSET         (0x11000UL)
// #define RCC_BASE           (APB2PERIPH_BASE + RCC_OFFSET)

// #define APB2EN_R_OFFSET    (0x18UL)
// #define RCC_APB2EN_R       (*(volatile unsigned int *)(RCC_BASE + APB2EN_R_OFFSET))

// #define CRH_R_OFFSET       (0x04UL)
// #define GPIOC_CRH_R        (*(volatile unsigned int *)(GPIOC_BASE + CRH_R_OFFSET))

// #define OD_R_OFFSET        (0x0CUL)
// #define GPIOC_OD_R         (*(volatile unsigned int *)(GPIOC_BASE + OD_R_OFFSET))

/*------------------------------------------------------------------------------------*/


#define GPIOC_EN           (1U<<4)

#define PIN13              (1U<<13)
#define LED_PIN             PIN13
#define LED_OFF             (1U<<29)


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
  GPIOC->CRH &= ~(0U<<23);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {

    /*----------- X-OR way to blink----------*/
    // GPIOC->ODR ^= LED_PIN;                      //uncomment to 
    // for(int i=0;i<100000;i++);                  //use the code fo X-OR; think how it does the blinking
    /*----------- X-OR way to blink----------*/


    GPIOC->BSRR = LED_PIN;
		for(int i=0; i<100000; i++){}

		GPIOC->BSRR = LED_OFF;
		for(int i=0; i<100000; i++){}
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}
 