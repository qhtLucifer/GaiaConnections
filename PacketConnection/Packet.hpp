#pragma once

#include <boost/asio.hpp>

namespace Gaia::Connections::PacketConnection
{
    /**
     * @brief Data Packet
     * @details
     *  Encapsulate transmission data and endpoint information.
     *  If this packet is received from a remote socket,
     *  then Address describe the address of the remote sender;
     *  if this packet is going to be sent to a remote socket,
     *  then Address describe the destination to which this packet should be sent.
     */
    class Packet
    {
    public:
		/// Structure used to describe a Internet address.
        using EndPoint = boost::asio::ip::udp::endpoint;

        /**
         * @brief IP and port of a remote socket
         * @details
         *  It can be used to describe the sender address of this packet,
         *  or the destination to which this packet should be sent.
         */
        EndPoint Address;

        /**
         * @brief Data to transmit
         * @details
         *  This vector will not alloc memory during construction,
         *  so manually invoke its resize() function before using it is necessary.
         */
        std::vector<unsigned char> Data;

        /// Default initialization
        Packet() = default;
        /// Initialize with address
        explicit Packet(EndPoint address);
        /// Initialize with address and data
        Packet(EndPoint address, std::vector<unsigned char> data);

    };
}