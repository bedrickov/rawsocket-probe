# RawSocket-Probe

<div align="center">

![Platform](https://img.shields.io/badge/Platform-Windows%20(x64)-0078D4?style=flat-square&logo=windows)
![Language](https://img.shields.io/badge/Language-C11-A8B9CC?style=flat-square&logo=c)
![License](https://img.shields.io/badge/License-MIT-blue?style=flat-square)
![Build](https://img.shields.io/badge/Build-Passing-brightgreen?style=flat-square)

**Низкоуровневый анализатор сетевого трафика и IPv4/TCP/UDP заголовков на чистом C.**  
*Прямой захват и валидация сетевых фреймов через нативный Winsock 2 SPI без сторонних драйверов вроде WinPcap/Npcap.*

</div>

---

## Архитектура

- Реализация разбора битовых полей заголовков IPv4 (`ihl`, `tos`, `ttl`, `protocol`) и TCP/UDP на чистом C с выравниванием (`#pragma pack(push, 1)`).
- Сбор микросекундной статистики распределения сетевого трафика (TCP/UDP/ICMP).
- Отсутствие внешних зависимостей — сборка слинкована только со стандартным системным `ws2_32.dll`.

## Сборка и тесты

```powershell
gcc -O2 -Iinclude src/packet_parser.c tests/test_main.c -lws2_32 -o rawsocket_tests.exe
.\rawsocket_tests.exe
```

## Лицензия
MIT

<!-- verified: 2026-10-30 -->