#include "Receiver.hpp"
#include <iostream>
namespace Gaia::Connections::PacketConnection
{
    /// Default Constructor without binding port or address
    Receiver::Receiver(): Socket(Context)

    {}
    /// Construct with binding address
    Receiver::Receiver(const boost::asio::ip::udp::endpoint& address): Socket(Context, address), Bound(true)
    {}

    /// Construct with binding port. Default ip is localhost
    Receiver::Receiver(unsigned short port):
            Socket(Context, boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), port)), Bound(true)
    {}

    /// Change binding address of the socket
    void Receiver:: Bind(const boost::asio::ip::udp::endpoint& address)
    {
        Socket.bind(address);
        Bound = true;
    }

    /// Change binding port of the socket. Default ip is localhost
    void Receiver::Bind(unsigned short port)
    {
        Socket.bind(boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), port));
        Bound = true;
    }

    /// Provide the function used to read the data from buffer until the end.Return the packet of the data and address
    Packet Receiver::Receive()
    {
        Packet packet;
        packet.Data.resize(DefaultBufferSize);
        auto length = Socket.receive_from(boost::asio::buffer(packet.Data.data(), packet.Data.size()),packet.Address);
        packet.Data.resize(length);
        return packet;
    }

    /// Provide the function used to read the data from buffer with limited length.Return the packet of the data and address.
    Packet Receiver::Receive(std::size_t length)
    {
        Packet packet;
        packet.Data.resize(length);

        std::size_t received_size = 0;

        while (received_size < length)
        {
        	received_size += Socket.receive_from(boost::asio::buffer(packet.Data.data() + received_size,
																  length - received_size),
											  packet.Address);
        }

        return packet;
    }
}