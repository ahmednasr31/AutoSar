

typedef 	Dio_ChannelType  u32;
typedef 	Dio_PortType	 u32;

typedef struct 
{
	u8 			  mask;
	u8 			  offset;
	Dio_PortType  port;
	
}Dio_ChannelGroupType;


typedef Dio_LevelType u8;


#define 	STD_LOW  	0x00 
#define 	STD_HIGH 	0x01 


typedef 	Dio_PortLevelType  u16;


typedef enum 
{
 ChannelId_0  ,	 /* GPIOA PIN0  */
 ChannelId_1  ,	 /* GPIOA PIN1  */
 ChannelId_2  ,	 /* GPIOA PIN2  */
 ChannelId_3  ,	 /* GPIOA PIN3  */
 ChannelId_4  ,	 /* GPIOA PIN4  */
 ChannelId_5  ,	 /* GPIOA PIN5  */
 ChannelId_6  ,	 /* GPIOA PIN6  */
 ChannelId_7  ,	 /* GPIOA PIN7  */
 ChannelId_8  ,	 /* GPIOA PIN8  */
 ChannelId_9  ,	 /* GPIOA PIN9  */
 ChannelId_10 ,	 /* GPIOA PIN10 */
 ChannelId_11 ,	 /* GPIOA PIN11 */
 ChannelId_12 ,	 /* GPIOA PIN12 */
 ChannelId_13 ,	 /* GPIOA PIN13 */
 ChannelId_14 ,	 /* GPIOA PIN14 */
 ChannelId_15 ,	 /* GPIOA PIN15 */
 ChannelId_16 ,	 /* GPIOB PIN0  */
 ChannelId_17 ,	 /* GPIOB PIN1  */
 ChannelId_18 ,	 /* GPIOB PIN2  */
 ChannelId_19 ,	 /* GPIOB PIN3  */
 ChannelId_20 ,	 /* GPIOB PIN4  */
 ChannelId_21 ,	 /* GPIOB PIN5  */
 ChannelId_22 ,	 /* GPIOB PIN6  */
 ChannelId_23 ,	 /* GPIOB PIN7  */
 ChannelId_24 ,	 /* GPIOB PIN8  */
 ChannelId_25 ,	 /* GPIOB PIN9  */
 ChannelId_26 ,	 /* GPIOB PIN10 */
 ChannelId_27 ,	 /* GPIOB PIN11 */
 ChannelId_28 ,	 /* GPIOB PIN12 */
 ChannelId_29 ,	 /* GPIOB PIN13 */
 ChannelId_30 ,	 /* GPIOB PIN14 */
 ChannelId_31 ,	 /* GPIOB PIN15 */
 ChannelId_32 ,	 /* GPIOC PIN13 */
 ChannelId_33 ,	 /* GPIOC PIN14 */
 ChannelId_34 	 /* GPIOC PIN15 */
 
}ChannelId;


typedef enum 
{
	PortId_0 /* GPIOA */
	PortId_1 /* GPIOB */
	PortId_2 /* GPIOC */
	
}PortId;



#define  DIO_E_PARAM_INVALID_CHANNEL_ID    0x0A

#define  DIO_E_PARAM_INVALID_PORT_ID       0x14

#define  DIO_E_PARAM_INVALID_GROUP         0x1F

#define  DIO_E_PARAM_POINTER               0x20 