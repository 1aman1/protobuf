#include <iostream>
#include <grpcpp/grpcpp.h>
#include "tutorial.grpc.pb.h"

class GreeterClient
{
public:
  GreeterClient(std::shared_ptr<grpc::Channel> channel)
      : m_stub(tutorial::Greeter::NewStub(channel)) {}

  std::string SayHello(const std::string &name)
  {
    tutorial::HelloRequest request;
    request.set_name(name);

    tutorial::HelloResponse response;
    grpc::ClientContext context;

    grpc::Status status = m_stub->SayHello(&context, request, &response);

    if (status.ok())
    {
      return response.message();
    }
    else
    {
      return "RPC failed";
    }
  }

private:
  std::unique_ptr<tutorial::Greeter::Stub> m_stub;
};

int main()
{
  GreeterClient client(
      grpc::CreateChannel("localhost:33000",
                          grpc::InsecureChannelCredentials()));
  std::string user("World");
  std::string reply = client.SayHello(user);
  std::cout << "Received: " << reply << std::endl;

  return 0;
}
