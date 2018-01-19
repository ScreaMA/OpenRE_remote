/***********************************************************************************************************************
* Copyright (c) Hands Free Team. All rights reserved.
* FileName: 
* Contact:  QQ Exchange Group -- 521037187
* Version:  V2.0
*
* LICENSING TERMS:
* The Hands Free is licensed generally under a permissive 3-clause BSD license. 
* Contributions are requiredto be made under the same license.
*
* History:
* <author>      <time>      <version>      <desc>
*
* Description:   
***********************************************************************************************************************/

#include "board.h"
#include "os_include.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f10x_it.h"

void USART1_IRQHandler(void)
{
    unsigned char data;
#if SYSTEM_SUPPORT_OS == 1
    OSIntEnter();
#endif
    if(USART1->SR&(1<<5))
    {
        data=USART1->DR;
        //HF_USART_Put_Char(4,data);

        //        if(Board::getInstance()->getByteHighFourBit(Board::getInstance()->device_type[USART_PC]) == 1)
        //        {
        //            Board::getInstance()->usartDeviceWriteByte(Board::getInstance()->device_type[USART_DEBUG], data);
        //        }
        //        else if(Board::getInstance()->getByteHighFourBit(Board::getInstance()->device_type[USART_DEBUG]) == 1)
        //        {
        //            Board::getInstance()->usartDeviceWriteByte(Board::getInstance()->device_type[USART_PC], data);
        //        }

        if( Board::getInstance()->getUsartQueue(1)->fullCheck() ==0 ){
            Board::getInstance()->getUsartQueue(1)->putData(data);
        }
        USART_ClearITPendingBit(USART1, USART_IT_RXNE);   // clear interrupt flag
    }
#if SYSTEM_SUPPORT_OS == 1
    OSIntExit();
#endif
}

void USART2_IRQHandler(void)
{
    unsigned char data = 0;
#if SYSTEM_SUPPORT_OS == 1
    OSIntEnter();
#endif
    if(USART_GetITStatus(USART2, USART_IT_RXNE) != RESET)
    {
        data = USART_ReceiveData(USART2);

//        if(Board::getInstance()->getByteHighFourBit(Board::getInstance()->device_type[USART_PC]) == 2)
//        {
//            Board::getInstance()->usartDeviceWriteByte(Board::getInstance()->device_type[USART_DEBUG], data);
//        }
//        else if(Board::getInstance()->getByteHighFourBit(Board::getInstance()->device_type[USART_DEBUG]) == 2)
//        {
//            Board::getInstance()->usartDeviceWriteByte(Board::getInstance()->device_type[USART_PC], data);
//        }

        if( Board::getInstance()->getUsartQueue(2)->fullCheck() ==0 ){
            Board::getInstance()->getUsartQueue(2)->putData(data);
        }
        USART_ClearITPendingBit(USART2, USART_IT_RXNE);  // clear interrupt flag
    }
#if SYSTEM_SUPPORT_OS == 1
    OSIntExit();
#endif
}

void USART3_IRQHandler(void)
{
    unsigned char data = 0;
#if SYSTEM_SUPPORT_OS == 1
    OSIntEnter();
#endif
    if (USART_GetITStatus(USART3, USART_IT_RXNE) != RESET)
    {
        data=USART_ReceiveData(USART3);

//        if(Board::getInstance()->getByteHighFourBit(Board::getInstance()->device_type[USART_PC]) == 3)
//        {
//            Board::getInstance()->usartDeviceWriteByte(Board::getInstance()->device_type[USART_DEBUG], data);
//        }
//        else if(Board::getInstance()->getByteHighFourBit(Board::getInstance()->device_type[USART_DEBUG]) == 3)
//        {
//            Board::getInstance()->usartDeviceWriteByte(Board::getInstance()->device_type[USART_PC], data);
//        }

        if( Board::getInstance()->getUsartQueue(3)->fullCheck() ==0 ){
            Board::getInstance()->getUsartQueue(3)->putData(data);
        }
        USART_ClearITPendingBit(USART3,USART_IT_RXNE);  //clear interrupt flag
    }
#if SYSTEM_SUPPORT_OS == 1
    OSIntExit();
#endif
}

void UART4_IRQHandler(void)
{
    unsigned char data = 0;
#if SYSTEM_SUPPORT_OS == 1
    OSIntEnter();
#endif
    if(USART_GetITStatus(UART4, USART_IT_RXNE) != RESET)
    {
        data = USART_ReceiveData(UART4);
        //HF_USART_Put_Char(1,data);

//        if(Board::getInstance()->getByteHighFourBit(Board::getInstance()->device_type[USART_PC]) == 4)
//        {
//            Board::getInstance()->usartDeviceWriteByte(Board::getInstance()->device_type[USART_DEBUG], data);
//        }
//        else if(Board::getInstance()->getByteHighFourBit(Board::getInstance()->device_type[USART_DEBUG]) == 4)
//        {
//            Board::getInstance()->usartDeviceWriteByte(Board::getInstance()->device_type[USART_PC], data);
//        }

        if( Board::getInstance()->getUsartQueue(4)->fullCheck() ==0 ){
            Board::getInstance()->getUsartQueue(4)->putData(data);
        }
        USART_ClearITPendingBit(UART4, USART_IT_RXNE);     //clear interrupt flag
    }
#if SYSTEM_SUPPORT_OS == 1
    OSIntExit();
#endif
}

void UART5_IRQHandler(void)
{
    unsigned char data = 0;
#if SYSTEM_SUPPORT_OS == 1
    OSIntEnter();
#endif
    if(USART_GetITStatus(UART5, USART_IT_RXNE) != RESET)
    {
        data = USART_ReceiveData(UART5);

//        if(Board::getInstance()->getByteHighFourBit(Board::getInstance()->device_type[USART_PC]) == 5)
//        {
//            Board::getInstance()->usartDeviceWriteByte(Board::getInstance()->device_type[USART_DEBUG], data);
//        }
//        else if(Board::getInstance()->getByteHighFourBit(Board::getInstance()->device_type[USART_DEBUG]) == 5)
//        {
//            Board::getInstance()->usartDeviceWriteByte(Board::getInstance()->device_type[USART_PC], data);
//        }

        if( Board::getInstance()->getUsartQueue(5)->fullCheck() ==0 ){
            Board::getInstance()->getUsartQueue(5)->putData(data);
        }
        USART_ClearITPendingBit(UART5 , USART_IT_RXNE);   //clear interrupt flag
    }
#if SYSTEM_SUPPORT_OS == 1
    OSIntExit();
#endif
}

void TIM6_IRQHandler(void)
{
#if SYSTEM_SUPPORT_OS == 1
    OSIntEnter();
#endif
    if(TIM_GetITStatus(TIM6 , TIM_IT_Update)== SET  )
    {
        Board::getInstance()->cnt_1ms++;
        Board::getInstance()->cnt_2ms++;
        Board::getInstance()->cnt_5ms++;
        Board::getInstance()->cnt_10ms++;
        Board::getInstance()->cnt_20ms++;
        Board::getInstance()->cnt_50ms++;
        TIM_ClearITPendingBit(TIM6 , TIM_FLAG_Update);     // clear interrupt flag
    }
#if SYSTEM_SUPPORT_OS == 1
    OSIntExit();
#endif
}

void HardFault_Handler(void)
{
#if SYSTEM_SUPPORT_OS == 1
    OSIntEnter();
#endif

    Board::getInstance()->setBeepModel(3); // 10hz

    //	__disable_fault_irq();  //reset
    //	NVIC_SystemReset();
#if SYSTEM_SUPPORT_OS == 1
    OSIntExit();
#endif
}

#ifdef __cplusplus
}
#endif
