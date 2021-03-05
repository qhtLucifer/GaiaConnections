#pragma once

#include <boost/asio.hpp>

namespace Gaia::Connections::PacketConnection
{
    /**
     * @brief Data Packet
     * @details Encapsulate transmission data and endpoints
     */
    class Packet
    {
    public:

        using EndPoint = boost::asio::ip::udp::endpoint;

        /// In order to save the target client or server ip and port
        EndPoint Address;
        /// Data transmitted
        std::vector<unsigned char> Data;

        /// Default initialization
        Packet() = default;
        /// Initialize with address
        explicit Packet(EndPoint address);
        /// Initialize with address and data
        Packet(EndPoint address, std::vector<unsigned char> data);

    };
}