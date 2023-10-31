# Steps to run

-> protoc -I=. --cpp_out=. --grpc_out=. --plugin=protoc-gen-grpc=\`which grpc_cpp_plugin` tutorial.proto

-> g++ -std=c++11 server.cpp tutorial.grpc.pb.cc tutorial.pb.cc -lgrpc++ -lgrpc -lprotobuf -pthread -o server

-> g++ -std=c++11 client.cpp tutorial.grpc.pb.cc tutorial.pb.cc -lgrpc++ -lgrpc -lprotobuf -pthread -o client

-> ./server

-> ./client
