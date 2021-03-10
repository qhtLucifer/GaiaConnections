#pragma once

#include <boost/asio.hpp>

#include "Packet.hpp"

namespace Gaia::Connections::PacketConnection
{
    /**
     * @brief Maintain a socket with UDP protocol for reading data
     * @details
     *  Receiver can bind a port with UDP protocol and then receive data with boost.asio module.
     */
    class Receiver
    {
    private:
        // IO context for following IO operations.
        boost::asio::io_context Context{};
        // Socket for listening.
        boost::asio::ip::udp::socket Socket;
        // Describe whether this Receiver is bound to a port or not.
        bool Bound {false};

    public:
    	/// Structure used to describe a Internet address.
    	using Endpoint = boost::asio::ip::udp::endpoint;

    	/**
    	 * @brief Default buffer size for data reading.
    	 * @details
    	 *  Receive functions will create a buffer of this count to receive incoming data,
    	 *  and functions will return immediately once it's buffer full.
    	 */
        static inline std::size_t DefaultBufferSize {512};

        /// Default Constructor without binding port or address.
        Receiver();
        /**
         * @brief Construct and bind a specific address.
         * @param address Address to bind.
         *  Sometimes IP is necessary when there are multiple network cards on the computer,
         *  and users want to bind Receiver on one of them.
         */
        Receiver(const boost::asio::ip::udp::endpoint& address);
        /**
         * @brief Construct and bind to a port on local host.
         * @param port Port to bind.
         */
        explicit Receiver(unsigned short port);

        /// Bind to a specific address.
        void Bind(const boost::asio::ip::udp::endpoint& address);
        /// Bind to a port on local host.
        void Bind(unsigned short port);

        /**
         * @brief Start to receive data.
         * @pre Already bound to an address.
         * @return Packet of the transmitted data.
         * @details
         *  After this function is called, incoming data will be stored in buffer,
         *  which means transmitted data before this function call will not be received.
         */
        Packet Receive();
	    /**
		 * @brief Start to receive a specific amount of data.
		 * @pre Already bound to an address.
	     * @param length Amount of bytes to receive.
		 * @return Packet of the transmitted data of specified length.
		 * @details
		 *  After this function is called, incoming data will be stored in buffer,
		 *  which means transmitted data before this function call will not be received.
	      * This function will return immediately when Receiver got the specified amount of data.
		 */
        Packet Receive(std::size_t length);
    };
}
