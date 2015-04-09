#include <cstdlib>
#include <iostream>
#include "mongo/client/dbclient.h" // for the driver

using mongo::BSONElement;
using mongo::BSONObj;
using mongo::BSONObjBuilder;

void run() {
	BSONObjBuilder b;
	b.append("name", "Joe");
	b.append("age", 33);
	BSONObj p = b.obj();
    mongo::DBClientConnection c;
    c.connect("localhost");
    c.insert("tutorial.persons", p);
}

int main() {
    mongo::client::initialize();
    try {
        run();
        std::cout << "connected ok" << std::endl;
    } catch( const mongo::DBException &e ) {
        std::cout << "caught " << e.what() << std::endl;
    }
    return EXIT_SUCCESS;
}
