using System.Net;
using System.Net.Sockets;

namespace TriviaClient
{
    static class Communicator
    {
        public static Socket serverSocket;
        public static int roomId;
        public static bool Connect(string serverIP, int port)
        {
            Socket sock = new Socket(SocketType.Stream, ProtocolType.Tcp);
            IPAddress iP = IPAddress.Parse(serverIP);
            IPEndPoint iPEndPoint = new IPEndPoint(iP, port);
            try
            {
                sock.Connect(iPEndPoint);
            }
            catch
            {
                serverSocket = null;
                return false;
            }
            serverSocket = sock;
            return true;
        }
        public static string Send(string data, byte code)
        {
            byte[] buffer = new byte[1024];
            buffer[0] = code;
            buffer[1] = 0; buffer[2] = 0; buffer[3] = 0; buffer[4] = (byte)(data.Length);
            byte[] dataBytes = System.Text.Encoding.ASCII.GetBytes(data);
            for (int i = 5; i < dataBytes.Length + 5; i++)
            {
                buffer[i] = dataBytes[i-5];
            }
            serverSocket.Send(buffer);
            byte[] input = new byte[1024];
            serverSocket.Receive(input, 1024, SocketFlags.None);
            return System.Text.Encoding.ASCII.GetString(input);
        }
    }
}
