#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"  // Pico W Wi-Fi library
#include "lwip/ip4_addr.h"
#include "lwip/sockets.h"

#define WIFI_SSID "Siva"
#define WIFI_PASSWORD "1234567890"
#define PORT 80

// Function to connect to Wi-Fi
void connect_to_wifi() {
    if (cyw43_arch_init()) {
        printf("Wi-Fi init failed\n");
        return;
    }

    cyw43_arch_enable_sta_mode();

    printf("Connecting to Wi-Fi...\n");
    if (cyw43_arch_wifi_connect_timeout_ms(WIFI_SSID, WIFI_PASSWORD, CYW43_AUTH_WPA2_AES_PSK, 10000)) {
        printf("Failed to connect to Wi-Fi\n");
    } else {
        printf("Connected to Wi-Fi\n");
        printf("IP Address: %s\n", ip4addr_ntoa(netif_ip4_addr(&cyw43_state.netif[CYW43_ITF_STA])));
    }
}

// // Example of opening a TCP socket connection
// void run_tcp_server() {
//     int sock, new_sock;
//     struct sockaddr_in server_addr, client_addr;
//     char buffer[1024];
//     socklen_t addr_len = sizeof(client_addr);

//     sock = socket(AF_INET, SOCK_STREAM, 0);
//     if (sock < 0) {
//         printf("Socket creation failed\n");
//         return;
//     }

//     server_addr.sin_family = AF_INET;
//     server_addr.sin_port = htons(PORT);
//     server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

//     if (bind(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
//         printf("Socket binding failed\n");
//         close(sock);
//         return;
//     }

//     listen(sock, 1);
//     printf("Listening for connections on port %d\n", PORT);

//     new_sock = accept(sock, (struct sockaddr *)&client_addr, &addr_len);
//     if (new_sock < 0) {
//         printf("Connection acceptance failed\n");
//         close(sock);
//         return;
//     }

//     printf("Connection accepted!\n");
//     recv(new_sock, buffer, sizeof(buffer), 0);
//     printf("Received data: %s\n", buffer);

//     close(new_sock);
//     close(sock);
// }

// Main application entry point
int main() {
    stdio_init_all();

    char c =getchar();
    if(c=='c'){
        printf("Starting connce==ect to wifi\n");
        connect_to_wifi();
    }

    // while (true) {
    //     run_tcp_server();  // Serve TCP requests
    //     sleep_ms(1000);
    // }

    return 0;
}
