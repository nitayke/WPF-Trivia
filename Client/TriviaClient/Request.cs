namespace TriviaClient
{
    class LoginRequest
    {
        public string username;
        public string password;
    }
    class SignupRequest
    {
        public string username;
        public string password;
        public string email;
    }
    class CreateRoomRequest
    {
        public string roomName;
        public int maxUsers;
        public int questionCount;
        public int answerTimeout;
    }
    class JoinRoomRequest
    {
        public int roomId;
    }
    class CreateRoomResponse
    {
        public int roomId;
        public int status;
    }
    class GetUserScoreResponse
    {
        public string statistics;
    }
}
