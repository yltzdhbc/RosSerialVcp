#ifndef __BSP_USB_H
#define __BSP_USB_H

#ifdef __cplusplus
extern "C" {
#endif

#include "usbd_cdc_if.h"
#include <string.h>
#include <stdarg.h>
#include <stdio.h>

int vcp_available(void);
int vcp_read(void);
void vcp_write(uint8_t* Buf, uint16_t Len);
void vcp_printf( const char *fmt, ...);


#ifdef __cplusplus
}
#endif

#endif

