
# CMakeLists.txt

cmake_minimum_required (VERSION 2.8)
project (PacketDump)

SET (CMAKE_CXX_FLAGS_DEBUG " -O0 -Wall -Werror -g -ggdb")
SET (CMAKE_C_FLAGS_DEBUG " -O0 -Wall -Werror -g -ggdb")
SET (CMAKE_BUILD_TYPE Debug)


SET (CMAKE_CXX_COMPILER "ccache")
SET (CMAKE_CXX_COMPILER_ARG1 "g++")


SET (CMAKE_C_COMPILER "ccache")
SET (CMAKE_C_COMPILER_ARG1 "gcc")

INCLUDE_DIRECTORIES (
    .
    ./printer
    ./printer/ndo
)

SET (SRC_LIST
    pkt_lock.cpp
    pkt_logger.cpp
    pkt_memman.cpp
    pkt_pool.cpp
    pkt_analyzer.cpp
    pkt_pcap.cpp
    pkt_common.cpp
    printer/handle_analyzer.cpp
    printer/print_ap1394.cpp
    printer/print_arcnet.cpp
    printer/print_arcnet_linux.cpp
    printer/print_atm.cpp
    printer/print_bt.cpp
    printer/print_c_chdlc.cpp
    printer/print_chdlc.cpp
    printer/print_cip.cpp
    printer/print_enc.cpp
    printer/print_fddi.cpp
    printer/print_fr.cpp
    printer/print_frela.cpp
    printer/print_ieee802_11.cpp
    printer/print_ieee802_11_radio_avs.cpp
    printer/print_ieee802_11_radio.cpp
    printer/print_ieee802.cpp
    printer/print_ipfc.cpp
    printer/print_ipv4.cpp
    printer/print_ipv6.cpp
    printer/print_juniper_atm1.cpp
    printer/print_juniper_atm2.cpp
    printer/print_juniper_chdlc.cpp
    printer/print_juniper_es.cpp
    printer/print_juniper_ether.cpp
    printer/print_juniper_frelay.cpp
    printer/print_juniper_ggsn.cpp
    printer/print_juniper_mfr.cpp
    printer/print_juniper_mlfr.cpp
    printer/print_juniper_mlppp.cpp
    printer/print_juniper_monitor.cpp
    printer/print_juniper_ppp.cpp
    printer/print_juniper_pppoe_atm.cpp
    printer/print_juniper_pppoe.cpp
    printer/print_juniper_services.cpp
    printer/print_lane8023.cpp
    printer/print_ltask.cpp
    printer/print_mfr.cpp
    printer/print_null.cpp
    printer/print_pflog.cpp
    printer/print_ppp_bsdos.cpp
    printer/print_ppp.cpp
    printer/print_ppp_hdlc.cpp
    printer/print_pppoe.cpp
    printer/print_ppp_withdirection.cpp
    printer/print_prism.cpp
    printer/print_raw.cpp
    printer/print_sl.cpp
    printer/print_slip_bsdos.cpp
    printer/print_sll.cpp
    printer/print_sunatm.cpp
    printer/print_symantec.cpp
    printer/print_usb_linux_X_byte.cpp
    printer/ndo/print_ether.cpp
    printer/ndo/print_ieee802_15_4.cpp
    printer/ndo/print_ieee802_15_4_nofc.cpp
    printer/ndo/print_ipnet.cpp
    printer/ndo/print_netanalyzer.cpp
    printer/ndo/print_netanalyzer_transparent.cpp
    printer/ndo/print_ppi.cpp
    main.cpp
)

SET (EXTRA_LIBS
    -lpthread
    -lrt
    -lpcap
)

add_executable (PacketDump ${SRC_LIST})
target_link_libraries (PacketDump ${EXTRA_LIBS})
