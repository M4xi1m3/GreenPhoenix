#include "TestHandler.hpp"
#include <iostream>
#include <exception>

TestHandler::~TestHandler() {
}

void TestHandler::handle() {
    int i = 0;
    while (!mustStop() && i < 10) {
        try {
            std::string line;
            std::getline(m_is, line);
            m_os << line << "\n";
            m_os.flush();
            i++;
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
            break;
        }
    }
    m_socket.close();
}

void TestHandler::stop() {
    m_os << "Stopping!\n";
    m_os.flush();
    m_socket.shutdown();
    m_socket.close();
}
