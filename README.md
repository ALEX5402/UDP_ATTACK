# UDP Flood Tool

This is a simple multi-threaded UDP flood attack tool implemented in C++. It sends multiple UDP payloads to a specified IP address and port for a user-defined duration and number of threads.

## Disclaimer

**This tool is for educational and testing purposes only.** Unauthorized use of this tool may violate applicable laws. The author assumes no responsibility for any damage caused by misuse of this tool.

## Features

- Sends predefined UDP payloads to a specified IP address and port.
- Multi-threaded to increase efficiency and load.
- Customizable duration of the attack and number of threads.
- Error handling for socket creation and data transmission.

## Requirements

- Linux-based system (due to use of `arpa/inet.h` and `sys/socket.h`)
- C++11 or later (for multi-threading support)
- GCC or any C++ compiler

## How to Compile

You can compile the tool using `g++`:

```bash
g++ udp_flood.cpp -o udp_flood -lpthread
```

## Usage

```bash
./udp_flood <IP> <Port> <Duration (seconds)> <Number of Threads>
```

- `<IP>`: Target IP address (e.g., `192.168.1.1`).
- `<Port>`: Target UDP port (e.g., `8080`).
- `<Duration>`: Duration of the attack in seconds (e.g., `30` for 30 seconds).
- `<Threads>`: Number of threads to use (e.g., `10` for 10 concurrent threads).

### Example

```bash
./udp_flood 192.168.1.100 8080 60 5
```

This will send UDP packets to IP `192.168.1.100` on port `8080` for 60 seconds using 5 threads.

## Payloads

The tool sends the following UDP payloads to the target:

```plaintext
\x08\xb2\x00\x21
\x08\xb2\x00
\xD8\x39\x84\x00
```

These payloads can be customized directly in the source code in the `payloads[]` array.

## Code Structure

- **`send_udp_message()`**: Handles the creation of the socket and sending the payloads to the target IP and port. It also includes error handling for the `sendto()` function.
- **`udp_flood_thread()`**: A wrapper for creating and managing threads to send UDP messages.
- **`main()`**: Accepts command-line arguments, manages thread creation, and runs the UDP flood attack for the specified duration.

## License

This project is open source and available under the [MIT License](LICENSE).
