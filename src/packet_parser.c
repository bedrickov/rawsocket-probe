#include "packet_parser.h"

void parse_packet(const uint8_t* buffer, size_t size, PACKET_METRICS* metrics) {
    if (!buffer || size < sizeof(IPV4_HEADER) || !metrics) return;

    metrics->total_packets++;
    metrics->total_bytes += size;

    const IPV4_HEADER* ip = (const IPV4_HEADER*)buffer;
    size_t ip_hdr_len = (ip->ihl) * 4;

    if (ip_hdr_len < sizeof(IPV4_HEADER) || ip_hdr_len > size) {
        metrics->other_packets++;
        return;
    }

    switch (ip->protocol) {
        case 6: // TCP
            metrics->tcp_packets++;
            break;
        case 17: // UDP
            metrics->udp_packets++;
            break;
        case 1: // ICMP
            metrics->icmp_packets++;
            break;
        default:
            metrics->other_packets++;
            break;
    }
}
