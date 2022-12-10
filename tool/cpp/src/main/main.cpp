#include<yaml-cpp/yaml.h>
#include<iostream>

int main() {
    YAML::Node primes = YAML::Load("[2, 3, 5, 7, 11]");
    for (YAML::const_iterator it=primes.begin();it!=primes.end();++it) {
      std::cout << it->as<int>() << "\n";
    }
}
