/*!
 * Simple chat program (client side).cpp - http://github.com/hassanyf
 * Version - 2.0.1
 *
 * Copyright (c) 2016 Hassan M. Yousuf
 */
#include <ctime>
#include <time.h>
#include <fstream>
#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <string.h>

using namespace std;

//func
void testing_new_feature()
{
//std::cout<<"Its working HERE LOLOLOL"<<std::endl;
}
//end fucn
int main()
{
    /* ---------- INITIALIZING VARIABLES ---------- */

int NodeSetup=0;
string SetupMsg[8]={"1 InsertVNode name1","0 InsertVNode name0","2 InsertVNode name2","1 Insert html1 1.1.1.1","0 Insert html0 0.0.0.0","2 Insert html2 2.2.2.2", "2 Lookup html0", "STOP"};
    /*  
       1. client is a file descriptor to store the values 
       returned by the socket system call and the accept 
       system call.

       2. portNum is for storing port number on which
       the accepts connections

       3. isExit is bool variable which will be used to 
       end the loop

       4. The client reads characters from the socket 
       connection into a dynamic variable (buffer).

       5. A sockaddr_in is a structure containing an internet 
       address. This structure is already defined in netinet/in.h, so
       we don't need to declare it again.

        DEFINITION:

        struct sockaddr_in
        {
          short   sin_family;
          u_short sin_port;
          struct  in_addr sin_addr;
          char    sin_zero[8];
        };

        6. serv_addr will contain the address of the server

    */
std::string Bf;
system("NS_LOG=ndn.Producer:ndn.Consumer ./waf --run=ndn-simple-new");
    int client;
    int portNum = 1500; // NOTE that the port number is same for both client and server
    bool isExit = false;
    int bufsize = 1024;
    char buffer[bufsize];
    char* ip = "127.0.0.1";

    struct sockaddr_in server_addr;

    client = socket(AF_INET, SOCK_STREAM, 0);

    /* ---------- ESTABLISHING SOCKET CONNECTION ----------*/
    /* --------------- socket() function ------------------*/

    if (client < 0) 
    {
        cout << "\nError establishing socket..." << endl;
        exit(1);
    }

    /*
        The socket() function creates a new socket.
        It takes 3 arguments,

            a. AF_INET: address domain of the socket.
            b. SOCK_STREAM: Type of socket. a stream socket in 
            which characters are read in a continuous stream (TCP)
            c. Third is a protocol argument: should always be 0. The 
            OS will choose the most appropiate protocol.

            This will return a small integer and is used for all 
            references to this socket. If the socket call fails, 
            it returns -1.

    */
//system("NS_LOG=ndn.Producer:ndn.Consumer ./waf --run=ndn-simple");
    cout << "\n=> Socket client has been created..." << endl;
    
    /* 
        The variable serv_addr is a structure of sockaddr_in. 
        sin_family contains a code for the address family. 
        It should always be set to AF_INET.

        htons() converts the port number from host byte order 
        to a port number in network byte order.

    */

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(portNum);

    // this function returns returns 1 if the IP is valid
    // and 0 if invalid
    // inet_pton converts IP to packets
    // inet_ntoa converts back packets to IP
    //inet_pton(AF_INET, ip, &server_addr.sin_addr);

    /*if (connect(client,(struct sockaddr *)&server_addr, sizeof(server_addr)) == 0)
        cout << "=> Connection to the server " << inet_ntoa(server_addr.sin_addr) << " with port number: " << portNum << endl;*/


    /* ---------- CONNECTING THE SOCKET ---------- */
    /* ---------------- connect() ---------------- */

    if (connect(client,(struct sockaddr *)&server_addr, sizeof(server_addr)) == 0)
        cout << "=> Connection to the server port number: " << portNum << endl;

    /* 
        The connect function is called by the client to 
        establish a connection to the server. It takes 
        three arguments, the socket file descriptor, the 
        address of the host to which it wants to connect 
        (including the port number), and the size of this 
        address. 

        This function returns 0 on success and -1 
        if it fails.

        Note that the client needs to know the port number of
        the server but not its own port number.
    */

    cout << "=> Awaiting confirmation from the server..." << endl; //line 40
    recv(client, buffer, bufsize, 0);
    cout << "=> Connection confirmed, you are good to go...";

    cout << "\n\n=> Enter # to end the connection\n" << endl;

    // Once it reaches here, the client can send a message first.

//ofstream sdfout("BUFFER.txt", std::ofstream::out | std::ofstream::trunc);
//ofstream sdfout("BUFFER.txt", std::ios::app);
/////autosend
string s = "*";
char cstr[bufsize];
strcpy(cstr,s.c_str());
/////
    do {
ofstream sdfout("BUFFER.txt", std::ofstream::out | std::ofstream::trunc);
        cout << "Client: ";
clock_t start = clock();  
        do {
if (NodeSetup<8){
ofstream sdfout("BUFFER.txt", std::ios::app);
//cout<<buffer<<endl;
//cin >> buffer;
strcpy(buffer,s.c_str());
        sdfout << SetupMsg[NodeSetup] <<"   ";
cout<<"counter :: "<<NodeSetup <<" SENDING MESSAGE :: "<< SetupMsg[NodeSetup] << endl; 
NodeSetup++;
//if (NodeSetup==6)
//isExit = true;
}
else{
ofstream sdfout("BUFFER.txt", std::ios::app);

usleep(1000);
system("NS_LOG=ndn.Producer:ndn.Consumer ./waf --run=ndn-simple-new");
/*std::ifstream ifs("DB.txt");
  std::string showMe( (std::istreambuf_iterator<char>(ifs) ),
                       (std::istreambuf_iterator<char>()    ) );
std::cout<<"LookUp : "<<showMe<<std::endl;*/

            cin >> buffer;
Bf=buffer;

//out<<buffer<<endl;
        sdfout << Bf <<"   ";
}
            send(client, buffer, bufsize, 0);
            if (*buffer == '#') {
                send(client, buffer, bufsize, 0);
                *buffer = '*';
                isExit = true;
            }

        } while (*buffer != 42);

        cout << "Server: ";
clock_t stop = clock();    
double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;    
 
printf("Time elapsed in ms: %f", elapsed);
        do {

            recv(client, buffer, bufsize, 0);
            cout << buffer << " ";
            if (*buffer == '#') {
                *buffer = '*';
                isExit = true;
            }

        } while (*buffer != 42);
        cout << endl;
//system("NS_LOG=ndn.Producer:ndn.Consumer ./waf --run=ndn-simple-new");//sdadsda
/*std::ifstream ifs("C:\hello.txt");
  std::string content( (std::istreambuf_iterator<char>(ifs) ),
                       (std::istreambuf_iterator<char>()    ) );
std::cout<<"BUFFER "<<content<<std::endl;*/

    } while (!isExit);

    /* ---------------- CLOSE CALL ------------- */
    /* ----------------- close() --------------- */

    /* 
        Once the server presses # to end the connection,
        the loop will break and it will close the server 
        socket connection and the client connection.
    */

    cout << "\n=> Connection terminated.\nGoodbye...\n";

    close(client);
    return 0;
}
