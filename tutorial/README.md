# protobuf
protobuf tutorial with c++

To execute, firstly protoc should be installed in system, follow link to install https://github.com/protocolbuffers/protobuf/tree/main/src .

-> clone the repo and switch to tutorial directory

-> EXECUTE 'protoc -I=. --cpp_out=. person.proto'

-> g++ -std=c++11 -o main main.cpp person.pb.cc -lprotobuf

-> ./main