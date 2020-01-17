#include "USBSerial.h"

USBSerial Serial0;

USBSerial::USBSerial()
{
    baudrate = 115200; 
    tx_cnt = 0;
    rx_cnt = 0;
    tx_err_cnt = 0;
    rx_err_cnt = 0;
}

void USBSerial::begin(uint32_t _baud)
{
  //UNUSED(baud);
  MX_USB_DEVICE_Init();
}

void USBSerial::end(void)
{

}

int USBSerial::available(void)
{
  return vcp_available();
}

int USBSerial::read(void)
{
  if(USBSerial::available() == 0)
  {
    return -1;
  }
  else
  {
    rx_cnt++;
    return vcp_read(); 
  }
}

int USBSerial::write(uint8_t *Buf, uint16_t Len)
{
  vcp_write(Buf, Len);
  tx_cnt += Len;
  return 1;
}

uint32_t USBSerial::getRxCnt(void)
{
  return rx_cnt;
}

uint32_t USBSerial::getTxCnt(void)
{
  return tx_cnt;
}

uint32_t USBSerial::getBaudRate(void)
{
    return baudrate;
}

