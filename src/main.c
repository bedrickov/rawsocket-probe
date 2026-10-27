#include <stdio.h>
#include "packet_parser.h"

int main() {
    printf("[RawSocket-Probe] Windows NT Raw Socket Network Telemetry Probe\n");
    printf("Initializing Winsock 2.2 subsystem...\n");

    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
        printf("Failed to initialize Winsock.\n");
        return 1;
    }

    printf("Winsock initialized successfully.\n");
    printf("Raw sockets require elevated administrator privileges (SeCreateGlobalPrivilege).\n");
    printf("System telemetry capture engine ready.\n");

    WSACleanup();
    return 0;
}
