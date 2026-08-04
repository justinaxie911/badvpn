# Tambahkan definisi backend secara manual untuk Android NDK
add_definitions(-DBADVPN_BREACTOR_BADVPN_USE_EPOLL=1)
add_definitions(-DBADVPN_BUNIXSIGNAL_USE_SIGNALFD=1)
add_definitions(-DBADVPN_BTIMER_USE_TIMERFD=1)
add_definitions(-DBADVPN_LINUX)

add_library(tun2socks SHARED
    tun2socks.c
    SocksUdpGwClient.c
    tun2socks_jni.c
)

target_link_libraries(tun2socks system flow tuntap lwip socksclient udpgw_client socks_udp_client log)

# Perintah install di bawah ini dikomentari karena tidak diperlukan untuk library JNI Android
# install(
#     TARGETS badvpn-tun2socks
#     RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
# )

# install(
#     FILES badvpn-tun2socks.8
#     DESTINATION ${CMAKE_INSTALL_MANDIR}/man8
# )
