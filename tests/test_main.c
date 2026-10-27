#include <stdio.h>
#include <assert.h>
#include "packet_parser.h"

int main() {
    printf("Running RawSocket-Probe packet parser unit tests...\n");

    PACKET_METRICS metrics = {0};

    // Simulated IPv4 + TCP packet
    uint8_t dummy_tcp[40] = {0};
    dummy_tcp[0] = 0x45; // IPv4, IHL = 5 (20 bytes)
    dummy_tcp[9] = 6;    // TCP protocol
    *(uint16_t*)&dummy_tcp[2] = htons(40); // Total length

    parse_packet(dummy_tcp, 40, &metrics);

    assert(metrics.total_packets == 1);
    assert(metrics.tcp_packets == 1);
    assert(metrics.udp_packets == 0);
    assert(metrics.total_bytes == 40);

    // Simulated IPv4 + UDP packet
    uint8_t dummy_udp[28] = {0};
    dummy_udp[0] = 0x45;
    dummy_udp[9] = 17;   // UDP
    *(uint16_t*)&dummy_udp[2] = htons(28);

    parse_packet(dummy_udp, 28, &metrics);

    assert(metrics.total_packets == 2);
    assert(metrics.tcp_packets == 1);
    assert(metrics.udp_packets == 1);
    assert(metrics.total_bytes == 68);

    printf("All packet parser unit tests passed successfully!\n");
    return 0;
}
