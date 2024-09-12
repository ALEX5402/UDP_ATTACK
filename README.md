# UDP Flooder with Hex Payloads

This project demonstrates a simple UDP flooder that sends multiple custom hex payloads to a target IP and port. The tool is designed to create multiple threads, each sending different payloads in rapid succession for a specified duration. It uses the C++ `socket` API for network communication.

## Terms and Conditions
This tool is intended for **educational purposes only**. Use it to understand network protocols and test network configurations in a controlled environment. **Do not use this tool for any unauthorized activities, personal revenge, or to disrupt networks or services**. Ensure you have explicit permission before testing any network or system. Misuse of this tool may lead to legal consequences.

## Notes
- Ensure you have proper permission to run this tool on the network you intend to test.
- **Warning**: Unauthorized use of network stress testing or DoS attacks on networks that you do not own or have explicit permission to test is illegal and unethical.

## Table of Contents
- [Features](#features)
- [Prerequisites](#prerequisites)
- [Usage](#usage)
- [Hex Payloads](#hex-payloads)
- [Compiling](#compiling)
- [Running](#running)
- [Terms and Conditions](#terms-and-conditions)
- [Notes](#notes)
- [License](#license)

## Features
- Sends multiple hex payloads to a target IP and port over UDP.
- Supports multi-threading for higher traffic generation.
- Payloads are sent in a continuous loop until the specified time duration ends.
- Highly configurable: change IP, port, duration, and number of threads.

## Prerequisites
Ensure you have the following installed:
- GCC or any C++ compiler.
- Linux or any UNIX-based system (for socket programming).
- Basic knowledge of terminal/command-line usage.

## Usage
This UDP flooder takes four arguments:
1. Target IP address
2. Target port
3. Duration of the attack (in seconds)
4. Number of threads

Example command:
```bash
./udp_flooder 192.168.1.10 8080 60 10
```
This command will flood the target IP (`192.168.1.10`) on port `8080` for `60` seconds using `10` threads.

### Arguments
| Argument          | Description                               |
|-------------------|-------------------------------------------|
| `<IP>`            | Target IP address.                        |
| `<Port>`          | Target port number.                       |
| `<Duration>`      | Duration of the flood in seconds.         |
| `<Number of Threads>` | Number of threads to spawn.           |

## Hex Payloads
The following hex payloads are used in the flood:
1. **Payload 1**:
   ```text
   ca 75 c9 94 3c 26 fc 04 5e f7 4f ba f4 5e 5b 57
   22 d4 69 80 b3 aa 21 ad 9e 72 14 f7 d2 dd e6 e8
   10 c6 93 51
   ```

2. **Payload 2**:
   ```text
   af 33 b7 21 4d 88 ec 33 99 11 6e bc 2f de 76 8a
   ab 5f 90 b2 12 3d 4b 8e ff cc 55 29 10 ac e7 da
   14 e6 88 92
   ```

3. **Payload 3**:
   ```text
   7c 35 d2 b9 81 25 e8 06 26 7f 1c d0 c6 12 99 4a
   e7 b9 3d 66 b5 ae ee dd d9 01 9d 75 74 ef 64 1f
   23 7b 4e c7 9a 27 38
   ```

4. **Payload 4**:
   ```text
   10 71 08 0e 77 3a a6 ac 0c 77 1d 54 aa 3a ee ec
   54 70 1e e5 f3 0b 61 bf d2 5c 4f e8
   ```

5. **Payload 5**:
   ```text
   ba 12 01 a5 b0 34 a6 c7 fc 2d c1 01 cc 23 e6 21
   b5 98 6b f4 f5 f2 9f ef de ed 7b cf d6 33 bb 98
   8d 60 80 5f 9e f4 68 72 45 92 f5 af 54 fc e6 30
   c3 0c 83 ac b5 4c 69 5a a2 6f b5 7a 96 b9 67 cb
   b6 e7 68 59 9d 76 3d 56 bb 55 48 6d 92 6d 3d 06
   b6 4a 31 55 97 e9 fb 4f 3c bd cf a1 4c 33 53 5e
   3d c6 91 ee f3 ac a7 99 41 d9 a7 76 11 6a 32 62
   a7 00 22 f6 a1 88 30 07 be 68 91 31 3d 11 58 b9
   63 d9 31 d7 40 c4 5b 8c f2 40 13 45 d6 9d 85 f5
   5d 3c e6 b3 81 6b 97 f0 60 cb ee 2b 67 d8 d3 38
   d0 9e 57 d2 fc df 3a ed 51 0f d9 71 6d 3e fd f4
   5e 3f 8c
   ```

## Compiling
To compile the UDP flooder, use `g++` or any other C++ compiler. Here’s how you can do it with `g++`:
```bash
g++ -o udp_flooder udp_flooder.cpp -lpthread
```

This command compiles the C++ source file (`udp_flooder.cpp`) into an executable named `udp_flooder`, linking it with the `pthread` library for multi-threading.

## Running
Once compiled, you can run the UDP flooder with the following command:
```bash
./udp_flooder <IP> <Port> <Duration> <Number of Threads>
```

For example:
```bash
./udp_flooder 192.168.1.100 8080 120 20
```
This will send UDP packets to IP `192.168.1.100` on port `8080` for `120` seconds using `20` threads.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.