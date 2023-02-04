


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "Dio.h"
#include "DIO_private.h"


Dio_LevelType Dio_ReadChannel( Dio_ChannelType ChannelId )
{
	u8 Local_u8Result=0;
	
	
	if (ChannelId <= ChannelId_34 )
	{
		switch( ChannelId /16 )
		{
			/* PORT A */
			case 0 :  Local_u8Result = GET_BIT( GPIOA->IDR , ChannelId    ); break;
			/* PORT B */
			case 1 :  Local_u8Result = GET_BIT( GPIOB->IDR , ChannelId-16 ); break;
			/* PORT C*/			
			case 2 :  Local_u8Result = GET_BIT( GPIOC->IDR , ChannelId-19 ); break;
		}	
	}
	else
	{
		/* Det_ReportError(DIO_E_PARAM_INVALID_CHANNEL_ID); */
	}
	
	return Local_u8Result;
}


void Dio_WriteChannel( Dio_ChannelType ChannelId , Dio_LevelType Level )
{
	u8 Local_u8Result=0;
	
	if (ChannelId <= ChannelId_34 )
	{
		if ( Level == STD_LOW )
		{
			switch( ChannelId /16 )
			{
				/* PORT A */
				case 0 : CLR_BIT(GPIOA->ODR, ChannelId);      break;
				/* PORT B */
				case 1 : CLR_BIT(GPIOB->ODR, ChannelId-16);   break;
				/* PORT C*/			
				case 2 : CLR_BIT(GPIOC->ODR, ChannelId-19);   break;
			}
		}	
		else if ( Level == STD_HIGH )
		{
			
			switch( ChannelId /16 )
			{
				/* PORT A */
				case 0 : SET_BIT(GPIOA->ODR, ChannelId   );   break;
				/* PORT B */
				case 1 : SET_BIT(GPIOB->ODR, ChannelId-16);   break;
				/* PORT C*/			
				case 2 : SET_BIT(GPIOC->ODR, ChannelId-19);   break;
			}
		}
		else
		{
			/* MISRA C */
		}
	}
	else
	{
			/* Det_ReportError(DIO_E_PARAM_INVALID_CHANNEL_ID); */
	}
	
	return Local_u8Result;
}


Dio_PortLevelType Dio_ReadPort( Dio_PortType PortId )
{
		u16 Local_u16Result=0;
		
		switch ( PortId )
		{
			case PortId_0 : Local_u16Result=(u16)GPIOA->IDR;    break;
			case PortId_1 : Local_u16Result=(u16)GPIOB->IDR;    break;
			case PortId_2 : Local_u16Result=(u16)GPIOC->IDR;    break;
			default       : /* Det_ReportError(DIO_E_PARAM_INVALID_PORT_ID); */ break;
		}
		return  Local_u16Result;
}


Dio_PortLevelType Dio_ReadChannelGroup( const Dio_ChannelGroupType* ChannelGroupIdPtr)
{
	u16 Local_u16Result =0;
	
	switch(ChannelGroupIdPtr->port)
	{
		/*PORTA*/
		case 0 : 
		Local_u16Result =( (ChannelGroupIdPtr-offset)>> ((GPIOA->IDR)&(ChannelGroupIdPtr-> mask)) );
			break;
																							break;
		/*PORTB*/                                                
		case 1 :	
		Local_u16Result =( (ChannelGroupIdPtr-offset)>> ((GPIOB->IDR)&(ChannelGroupIdPtr-> mask)) );
			break;
																							break;
		/*PORTC*/
		case 2 : 
		Local_u16Result =( (ChannelGroupIdPtr-offset)>> ((GPIOC->IDR)&(ChannelGroupIdPtr-> mask)) );
			break;
																							break;
		default: /* Det_ReportError(DIO_E_PARAM_INVALID_PORT_ID); */  break;
		
	}
	return  Local_u16Result;
	
}


void Dio_WriteChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr,Dio_PortLevelType Level)
{
	
	switch(ChannelGroupIdPtr->port)
	{
		/*PORTA*/
		case 0 : GPIOA->ODR |= ((Level<< ChannelGroupIdPtr->offset) & (ChannelGroupIdPtr-> mask));
		         break;
		/*PORTB*/                                                
		case 1 : GPIOB->ODR |= ((Level<< ChannelGroupIdPtr->offset) & (ChannelGroupIdPtr-> mask));
		         break;
		/*PORTC*/
		case 2 : GPIOC->ODR |= ((Level<< ChannelGroupIdPtr->offset) & (ChannelGroupIdPtr-> mask));
		         break;
		default: /* Det_ReportError(DIO_E_PARAM_INVALID_PORT_ID); */  break;
		
	}
	
}

Dio_LevelType Dio_FlipChannel( Dio_ChannelType ChannelId )
{
	if (ChannelId <= ChannelId_34 )
	{
			switch( ChannelId /16 )
			{
				/* PORT A */
				case 0 : TOGGLE_BIT(GPIOA->ODR, ChannelId);      break;
				/* PORT B */
				case 1 : TOGGLE_BIT(GPIOB->ODR, ChannelId-16);   break;
				/* PORT C*/			
				case 2 : TOGGLE_BIT(GPIOC->ODR, ChannelId-19);   break;
			}
			
	}
	else
	{
		/* Det_ReportError(DIO_E_PARAM_INVALID_CHANNEL_ID); */
	}
	
	
}


