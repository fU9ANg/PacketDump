
#include "handle_analyzer.h"

#ifdef HAVE_PCAP_USB_H
#ifdef DLT_USB_LINUX
//DLT_USB_LINUX
void handle_analyzer::print_usb_linux_48_byte(pkt_buf* buf)
{
    //TODO:
}
#endif
#ifdef DLT_USB_LINUX_MMAPPED
//DLT_USB_LINUX_MMAPPED
void handle_analyzer::print_usb_linux_64_byte(pkt_buf* buf)
{
    //TODO:
}
#endif
#endif
