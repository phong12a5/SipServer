#ifndef UDP_CLIENT_HPP
#define UDP_CLIENT_HPP

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#include <iostream>
#include <atomic>
#include <functional>
#include <thread>

namespace gstivr {

class UdpClient
{
public:
	using OnNewMessageEvent = std::function<void(std::string, sockaddr_in)>;
	static constexpr int BUFFER_SIZE = 2048;

    UdpClient(std::string ip, int port, OnNewMessageEvent event);
    ~UdpClient();

    std::string getIp() const;
    int getPort() const;

	void startReceive();
    int send(std::string buffer);

private:
	void closeServer();

	std::string _ip;
	int _port;
	int _sockfd;
	sockaddr_in _servaddr;
	OnNewMessageEvent _onNewMessageEvent;
	std::atomic<bool> _keepRunning;
	std::thread _receiverThread;
};

} // namespace gstivr
#endif
