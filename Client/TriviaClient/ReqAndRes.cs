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
    class GetRoomsResponse
    {
        public string rooms;
    }
    class GetRoomStateResponse
    {
        public int status;
        public int hasGameBegun;
        public string players;
        public int questionCount;
        public int answerTimeout;
    }

    enum ReqCode
    {
        LOGIN,
        SIGNUP,
        ERRORCODE,
        LOGOUT,
        GETROOMS, // 4
        JOINROOM,
        CREATEROOM,
        GETPLAYERSINROOM,
        GETSTATISTICS, // 8
        CLOSEROOM,
        GETUSERSCORE,
        STARTGAME,
        LEAVEROOM, // 12
        GETROOMSTATE
    }

    enum SignupCode
    {
        SIGNUP_SUCCESS,
        SIGNUP_USERNAME_EXISTS
    }

    enum LoginCode
    {
        LOGIN_SUCCESS,
        LOGIN_USERNAME_NOT_EXISTS,
        LOGIN_WRONG_PASSWORD,
        LOGIN_USER_ALREADY_CONNECTED
    };
}
