#include <iostream>
#include <fstream>
#include "person.pb.h"

int main() {
    // Create a Person message
    tutorial::Person person;
    person.set_name("John Doe");
    person.set_id(123);
    person.set_email("john.doe@example.com");

    // Serialize the message to a string
    std::string serialized;
    person.SerializeToString(&serialized);

    // Deserialize the string back to a Person message
    tutorial::Person deserialized_person;
    deserialized_person.ParseFromString(serialized);

    // Display the content of the deserialized message
    std::cout << "Name: " << deserialized_person.name() << std::endl;
    std::cout << "ID: " << deserialized_person.id() << std::endl;
    if (deserialized_person.has_email()) {
        std::cout << "Email: " << deserialized_person.email() << std::endl;
    } else {
        std::cout << "Email not provided." << std::endl;
    }

    return 0;
}
