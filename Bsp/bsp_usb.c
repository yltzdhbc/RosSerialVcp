#include "bsp_usb.h"



uint32_t UserTxBufPtrIn = 0;    /* Increment this pointer or roll it back to
                                 * start address when data are received over
                                 * USART */
uint32_t UserTxBufPtrOut = 0;   /* Increment this pointer or roll it back to
                                 * start address when data are sent over USB */

/* this ring buffer used to store usb rx data*/
uint8_t usb_rxBuffer[USB_RX_DATA_SIZE];
uint32_t usb_rxBufPtrIn = 0;
uint32_t usb_rxBufPtrOut = 0;

USBD_CDC_LineCodingTypeDef LineCoding = {
  115200,                       /* baud rate */
  0x00,                         /* stop bits-1 */
  0x00,                         /* parity - none */
  0x08                          /* nb. of bits 8 */
};

int vcp_available(void)
{
  return ((uint32_t)(USB_RX_DATA_SIZE + usb_rxBufPtrIn - usb_rxBufPtrOut)) % USB_RX_DATA_SIZE;
}

int vcp_read(void)
{
  // if the head isn't ahead of the tail, we don't have any characters
  if(usb_rxBufPtrIn == usb_rxBufPtrOut)
  {
    return -1;
  }
  else
  {
    unsigned char ch = usb_rxBuffer[usb_rxBufPtrOut];
    usb_rxBufPtrOut = (uint16_t)(usb_rxBufPtrOut + 1) % USB_RX_DATA_SIZE;
    return ch;
  }
}
void vcp_write(uint8_t* Buf, uint16_t Len)
{
  while(CDC_Transmit_FS(Buf, Len) != HAL_OK);
}

void vcp_printf( const char *fmt, ...)
{
//  int32_t ret = 0;
  va_list arg;
  va_start (arg, fmt);
  int32_t len;
  static char print_buffer[255];

  len = vsnprintf(print_buffer, 255, fmt, arg);
  va_end (arg);


  /*ret = */vcp_write( (uint8_t *) print_buffer, len);

  //return ret;
}