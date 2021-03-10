#include "Channel.hpp"


namespace Gaia::Connections::ChannelConnection{
    Channel::Channel(): Socket(Context)
    {

    }
    Channel::Channel(const EndPoint& endPoint): Socket(Context)
    {

        Socket.connect(endPoint, error_code);

        if(!error_code)
        {
            Connected = true;
        }
        else
        {
            throw boost::system::system_error(error_code);
        }
    }

    Channel::Channel(int port):Socket(Context), RemoteEndpoint(boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port))
    {

    }

    void Channel::Bind(int port)
    {
        RemoteEndpoint = boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port);
    }

    void Channel::Bind(boost::asio::ip::tcp::endpoint endpoint_)
    {
        RemoteEndpoint = std::move(endpoint_);

    }

    void Channel::DisConnected() {

        Socket.close(error_code);

        if(!error_code)
        {
            Connected = false;
        }
        else
        {
            throw boost::system::system_error(error_code);
        }
    }

    bool Channel::IsConnected() const
    {
        return Connected;
    }

    void Channel::Connect(const Channel::EndPoint& endPoint)
    {
        Socket.connect(endPoint,error_code);
        if(error_code)
        {
            throw boost::system::system_error(error_code);
        }

    }

    void Channel::Listen()
    {
        boost::asio::ip::tcp::acceptor acceptor_(Context, RemoteEndpoint);
        acceptor_.accept(Socket,error_code);
        if(error_code)
        {
            throw boost::system::system_error(error_code);
        }
    }

    std::vector<unsigned char> Channel::Read()
    {
        std::vector<unsigned char> data(MaxDataSize);
        std::size_t received_size = 0;

        while (received_size < MaxDataSize) {

            received_size += Socket.read_some(boost::asio::buffer(data), error_code);
            if (error_code) {
                throw boost::system::system_error(error_code);
            }
        }
        return data;
    }

    void Channel::SetDataMaxSize(size_t max_data_size)
    {
        MaxDataSize = max_data_size;

    }

    std::vector<unsigned char> Channel::Read(size_t length) {
        std::vector<unsigned char> data(length);
        std::size_t received_size = 0;

        while (received_size < length) {

            received_size += Socket.read_some(boost::asio::buffer(data), error_code);
            if (error_code) {
                throw boost::system::system_error(error_code);
            }
        }

        return data;
    }

    void Channel::Write(std::vector<unsigned char> data) {
        Socket.write_some(boost::asio::buffer(data), error_code);
        if (error_code) {
            throw boost::system::system_error(error_code);
        }
    }
};