#pragma once
#include <boost/asio.hpp>
namespace Gaia::Connections::ChannelConnection
{
    /**
     * @brief Create a Channel for the TCP connection.
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
        //Whether the Channel is established already.
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