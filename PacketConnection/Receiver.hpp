#pragma once
#include <boost/asio.hpp>
#include "Packet.hpp"
namespace Gaia::Connections::PacketConnection
{
    /**
     * @brief Receive data from binding port
     * @details
     *  The Receiver has a default buffer size : 512. Please Remember to change the buffer size when users need
     *  Receiver need to be bound with the port first.
     *  The Receiver could be initialized with address, port or nothing.
     *  Use Bind function to bind socket with a new address or port.
     *  Use Receive to start receive data on the bound port.
     *  @attention Only the data which is sent after the Receive was transferred could be received successfully
     */
    class Receiver
    {
    private:

        // Create io_context for initializing Socket
        boost::asio::io_context Context{};
        // Initializing Socket
        boost::asio::ip::udp::socket Socket;
        // Default status: no binding port or address
        bool Bound = false;


    public:

        static inline std::size_t DefaultBufferSize {512};

        /// Default Constructor without binding port or address
        Receiver();
        /// Construct with binding address
        explicit Receiver(const boost::asio::ip::udp::endpoint& address);
        /// Construct with binding port. Default ip is localhost
        explicit Receiver(unsigned short port);


        /// Change binding address of the socket
        void Bind(const boost::asio::ip::udp::endpoint& address);
        /// Change binding port of the socket. Default ip is localhost
        void Bind(unsigned short port);


        /// Start receive the data on the specified port
        Packet Receive();
        /// Start receive the data on the specified port with limited length
        Packet Receive(size_t length);
    };
}