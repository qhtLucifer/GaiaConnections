#pragma once

#include "Packet.hpp"

namespace Gaia::Connections::PacketConnection
{
    /**
     * @brief data sent
     * @details
     *  There are two overloaded static function in the class Sender.
     *  The function whose parameter is packet is designed for sending data encapsulated with target address in the packet.
     *  The function whose parameters are address and data is designed for sending data avoiding creating temporary packet. The users just need to
     *  provide the data and address.
     */
    class Sender{
    private:
    	/**
    	 * @brief Acquire the static instance of the socket used for sending packet.
    	 * @return Reference of the static instance of socket.
    	 */
        static boost::asio::ip::udp::socket& GetSocket();

    public:
        /// Static function for sending packet
        static void Send(const Packet& packet);
        /// Static function in order to sending packet only for temporariness without constructing Packet
        static void Send(const Packet::EndPoint& address, const std::vector<unsigned char>& data);
    };
}