/*************************************************************************************
*     Author      : Ahmed NASR                                                       *
*     Description : Dio Driver                                   	                   *
*     Date        : 14 MAR 2022                                                      *
*     Version     : 1.0                                                              *
*************************************************************************************/

/*****************************************************
 * guard of file will call one time in .c  	        *
 *****************************************************/

#ifndef  DIO_PRIVATE_H
#define  DIO_PRIVATE_H

#define GPIOA_BASE_ADDRESS			0x40010800
#define GPIOB_BASE_ADDRESS			0x40010C00
#define GPIOC_BASE_ADDRESS			0x40011000



typedef struct
{
	volatile u32 CRL ;
	volatile u32 CRH ;
	volatile u32 IDR ;
	volatile u32 ODR ;
    volatile u32 BSR ;
	volatile u32 BRR ;
    volatile u32 LCK ;
				 			 
}GPIO_Type;



#define GPIOA   ((volatile GPIO_Type *) (GPIOA_BASE_ADDRESS) )

#define GPIOB   ((volatile GPIO_Type *) (GPIOB_BASE_ADDRESS) )

#define GPIOC   ((volatile GPIO_Type *) (GPIOC_BASE_ADDRESS) )





#endif