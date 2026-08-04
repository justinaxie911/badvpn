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