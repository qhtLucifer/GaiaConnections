#include "Sender.hpp"

namespace Gaia::Connections::PacketConnection
{
	/// Acquire the socket for sending packet.
	boost::asio::ip::udp::socket& Sender::GetSocket()
	{
		// Use inner static variable to prevent exception from escaping during its construction.
		static boost::asio::io_context context_instance {};
		static boost::asio::ip::udp::socket socket_instance {context_instance};
		return socket_instance;
	}

    /// Static function for sending packet that has been constructed.
    void Sender::Send(const Packet& packet)
    {
        // Send the data of packet to the packet's destination
        GetSocket().send_to(boost::asio::buffer(packet.Data), packet.Address);

    }

    /// Static function in order to sending packet only for temporariness without constructing Packet.
    void Sender::Send(const Packet::EndPoint& address, const std::vector<unsigned char>& data)
    {
        // Send the data to the destination described in the parameter
        GetSocket().send_to(boost::asio::buffer(data), address);

    }
}
