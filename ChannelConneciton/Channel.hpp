#pragma once

#include <boost/asio.hpp>

namespace Gaia::Connections::ChannelConnection
{
    /**
     * @brief Create a Channel for the TCP connection.
     * @details The Channel could be used as a server or a client. As the server, the Socket must be bound with a specified port and
     * IP. The localhost will be bound to the Socket if there is not a specified IP. Then call the function Listen(), the Socket
     * starts wait for the connecting. After connecting successfully, the users could use function Write() or Read() to send or get
     * data from TCP IO stream.
     * As the client, the users can construct the Channel with specified remote endpoint so that the Socket will try to connect to
     * the remote endpoint directly. Another way to connect is the function Connect().Before calling the Connect(), the remote
     * endpoint must be specified.
     * @attention The Channel will throw a exception out the error if here are some errors occur.
     *
     */
    class Channel
    {
    private:
        // IO context for following IO operations.
        boost::asio::io_context Context{};
        // Socket for creating the Channel.
        boost::asio::ip::tcp::socket Socket;
        // The remote endpoint that will be connected.
        boost::asio::ip::tcp::endpoint RemoteEndpoint;
        // The size of Channel`s IO buffer. The default size is 512.
        size_t MaxDataSize = {512};
        // Whether the Channel is established already.
        bool Connected = false;

        boost::system::error_code error_code;
    public:
        using EndPoint = boost::asio::ip::tcp::endpoint;
        //Default Constructor, which only initialize the Socket.
        Channel();

        // Construct with port and remote endpoint.
        // Local Socket will try to connect with the remote endpoint if this constructor is called.
        explicit Channel(const EndPoint& endPoint);

        // Construct with specified port.
        // The Socket will be bound with the specified port if this constructor is called.
        explicit Channel(int port);

        ///Bind The Socket with specified port.
        void Bind(int port);
        ///Bind The Socket with specified port.
        void Bind(boost::asio::ip::tcp::endpoint point_);

        ///Close the established Channel.
        void DisConnected();

        bool IsConnected() const;

        void SetDataMaxSize(size_t max_data_size);

        /**
         * @brief Try to connect with the specified endpoint.
         * @pre The Socket was bound with port and the specified remote endpoint must call the Accept() first.
         */
        void Connect(const EndPoint& endPoint);

        /**
         * @brief Wait for another Socket to Connect
         * @pre Local Socket was bound with specified port first.
         */
        void Listen();

        /**
         * @brief Read the data in the Channel`s buffer till the data size meet the MaxDataSize.
         * @pre The Channel was Established already.
         * @return Vector of the transmitted data.
         */
        std::vector<unsigned char> Read();
        /**
         * @brief Read a specific amount of data from Channel`s buffer.
         * @pre The Channel was Established already.
         * @param length: The specified length of data which is ready to be read
         * @return Vector of the transmitted data of specified length.
         */
        std::vector<unsigned char> Read(size_t length);
        /**
         * @brief Write some data into the Channel`s buffer.
         * @pre The Channel was Established already.
         */
        void Write(std::vector<unsigned char> data);

    };
}