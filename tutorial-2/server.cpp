#include <iostream>
#include <grpcpp/grpcpp.h>
#include "tutorial.grpc.pb.h"

class GreeterServiceImpl final : public tutorial::Greeter::Service
{
public:
  grpc::Status SayHello(grpc::ServerContext *context, const tutorial::HelloRequest *request, tutorial::HelloResponse *response) override
  {
    std::string prefix("Hello, ");
    response->set_message(prefix + request->name());
    return grpc::Status::OK;
  }
};

void RunServer()
{
  std::string server_address("0.0.0.0:33000");
  GreeterServiceImpl service;

  grpc::ServerBuilder builder;
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  builder.RegisterService(&service);

  std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << server_address << std::endl;
  server->Wait();
}

int main()
{
  RunServer();
  return 0;
}
