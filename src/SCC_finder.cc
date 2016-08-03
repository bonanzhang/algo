#include <iostream>
#include <string>
#include <sstream>
int main() {
    int src;
    int dst;
    long counter;
    std::string line;
    std::stringstream ss;
    counter = 0;
    while (std::getline(std::cin, line)) {
        ss << line;
        ss >> src >> dst;
        counter++;
    }
    std::cout << "edge count: " << counter << std::endl;
    return 0;
}
