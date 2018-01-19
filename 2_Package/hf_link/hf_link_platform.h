#ifndef HF_LINK_PLATFORM_H
#define HF_LINK_PLATFORM_H

#define HF_LINK_NODE_MODEL  2    //1:master(PC)  0 :slave(MCU)
#include "board.h"
#if (HF_LINK_NODE_MODEL==0 || HF_LINK_NODE_MODEL==2)

#include "board.h"

inline unsigned char HFLinkSendBuffer(unsigned char port_num , unsigned char* buffer, unsigned short int size)
{

    while(size--)  Board::getInstance()->usartDeviceWriteByte((DeviceType)port_num , *buffer++);
    return 1;

    //    if(port_num == 1){
    //        while(size--) HF_USART_Put_Char(1 , *buffer++);
    //        return 1;
    //    }
    //    else if(port_num == 2){
    //        while(size--) HF_USART_Put_Char(2 , *buffer++);
    //        return 1;
    //    }
    //    else if(port_num == 3){
    //        while(size--) HF_USART_Put_Char(3 , *buffer++);
    //        return 1;
    //    }
    //    else if(port_num == 4){
    //        while(size--) HF_USART_Put_Char(4 , *buffer++);
    //        return 1;
    //    }
    //    return 0;
}

#endif

#endif // HF_LINK_PLATFORM_H

