# ndn-dht-tcp
NDN+Chord through TCP socket
Quick guide:
- Please put chord-run.cc in "~/ns-3/examples/chord-run" folder
- Put "client.cpp" in "~/ns-3" folder
- Change original forwarder.cpp to new "forwarder.cpp"
- Put "ndn-simple-new.cpp" into "~/ns-3/src/ndnSIM/examples"

In order to work:
1) Please open 2 terminals in ns-3 folder and run chord-run first, by using "./waf --run=chord-run"
2) Wait until you see on server terminal "waiting for client":
first "g++ client.cpp -o client", then "./client"

Helpful information:
- Don't need to touch the server terminal. In case of errors, kill the client only in the client terminal and run it again. 

If you want to close server and run it again, you should close port manually by command:
"fuser -k -n tcp 1500".
