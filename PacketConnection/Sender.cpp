#include "Sender.hpp"

namespace Gaia::Connections::PacketConnection
{

    /// Static function for sending packet that has been constructed
    void Sender::Send(const Packet& packet)
    {

        using UDP = boost::asio::ip::udp;
        // Initialize socket
        UDP::socket senderSocket(Context);
        // Send the data of packet to the packet`s address
        senderSocket.send_to(boost::asio::buffer(packet.Data), packet.Address);

    }

    /// Static function in order to sending packet only for temporariness without constructing Packet
    void Sender::Send(const Packet::EndPoint& address, const std::vector<unsigned char>& data)
    {

        using UDP = boost::asio::ip::udp;
        // Initialize socket
        UDP::socket senderSocket(Context,UDP::endpoint(UDP::v4(),0));
        // Send the data to the address in the parameter
        senderSocket.send_to(boost::asio::buffer(data), address);

    }
}
