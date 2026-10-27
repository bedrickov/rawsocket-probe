#pragma once
#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
#include <stdint.h>
#include <string.h>

#pragma pack(push, 1)
typedef struct _IPV4_HEADER {
    uint8_t  ihl : 4;
    uint8_t  version : 4;
    uint8_t  tos;
    uint16_t total_length;
    uint16_t id;
    uint16_t flags_fragment_offset;
    uint8_t  ttl;
    uint8_t  protocol;
    uint16_t checksum;
    uint32_t src_ip;
    uint32_t dst_ip;
} IPV4_HEADER;

typedef struct _TCP_HEADER {
    uint16_t src_port;
    uint16_t dst_port;
    uint32_t seq_num;
    uint32_t ack_num;
    uint8_t  reserved : 4;
    uint8_t  data_offset : 4;
    uint8_t  flags;
    uint16_t window_size;
    uint16_t checksum;
    uint16_t urgent_ptr;
} TCP_HEADER;

typedef struct _UDP_HEADER {
    uint16_t src_port;
    uint16_t dst_port;
    uint16_t length;
    uint16_t checksum;
} UDP_HEADER;
#pragma pack(pop)

typedef struct _PACKET_METRICS {
    uint64_t total_packets;
    uint64_t tcp_packets;
    uint64_t udp_packets;
    uint64_t icmp_packets;
    uint64_t other_packets;
    uint64_t total_bytes;
} PACKET_METRICS;

void parse_packet(const uint8_t* buffer, size_t size, PACKET_METRICS* metrics);
