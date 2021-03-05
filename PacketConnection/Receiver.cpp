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
        this->Socket.bind(address);
        this->Bound = true;
    }

    /// Change binding port of the socket. Default ip is localhost
    void Receiver::Bind(unsigned short port)
    {
        this->Socket.bind(boost::asio::ip::udp::endpoint(boost::asio::ip::udp::v4(), port));
        this->Bound = false;
    }

    /// Provide the function used to read the data from buffer until the end.Return the packet of the data and address
    Packet Receiver::Receive()
    {
        Packet packet;
        packet.Data.resize(DefaultBufferSize);
        Socket.receive_from(boost::asio::buffer(packet.Data.data(), DefaultBufferSize),packet.Address);
        return packet;
    }

    /// Provide the function used to read the data from buffer with limited length.Return the packet of the data and address.
    Packet Receiver::Receive(std::size_t length)
    {
        Packet packet;
        packet.Data.resize(length);
        Socket.receive_from(boost::asio::buffer(packet.Data),packet.Address);
        return packet;
    }
}