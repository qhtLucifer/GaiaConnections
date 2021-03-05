#include "Packet.hpp"

namespace Gaia::Connections::PacketConnection
{
    /// Constructor with address initialization
    Packet::Packet(boost::asio::ip::udp::endpoint address) :
        Address(std::move(address)), Data()
    {}

    /// Constructor with address and data initialization
    Packet::Packet(boost::asio::ip::udp::endpoint address, std::vector<unsigned char> data):
        Address(std::move(address)),Data(std::move(data))
    {}
}