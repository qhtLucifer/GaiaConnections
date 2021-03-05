#pragma once

#include "Packet.hpp"

namespace Gaia::Connections::PacketConnection
{
    /**
     * @brief Static class for sending packet to a remote UDP socket.
     * @details
     *  There are two overloaded static function in the class Sender.
     *  The function whose parameter is packet is designed for sending data encapsulated with target address in the packet.
     *  The function whose parameters are address and data is designed for sending data avoiding creating temporary packet. The users just need to
     *  provide the data and address.
     */
    class Sender
    {
    private:
    	/**
    	 * @brief Acquire the static instance of the socket used for sending packet.
    	 * @return Reference of the static instance of socket.
    	 */
        static boost::asio::ip::udp::socket& GetSocket();

    public:
        /**
         * @brief Send a packet to the address marked in it.
         * @param packet Packet to send.
         */
        static void Send(const Packet& packet);
	    /**
		 * @brief Send a package of bytes to the address.
		 * @param address Where this package of bytes should be sent.
	     * @param data Bytes to transmit.
		 */
        static void Send(const Packet::EndPoint& address, const std::vector<unsigned char>& data);
    };
}