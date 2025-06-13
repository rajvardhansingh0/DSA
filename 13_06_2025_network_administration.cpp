#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct NetworkDevice {
    string name;
    string ipAddress;
    string macAddress;
    string type;
};

struct Network {
    map<string, NetworkDevice> devices;

    void addDevice(const NetworkDevice& device) {
        devices[device.name] = device;
    }

    void removeDevice(const string& name) {
        devices.erase(name);
    }

    NetworkDevice* findDevice(const string& name) {
        auto it = devices.find(name);
        if (it != devices.end()) {
            return &(it->second);
        }
        return nullptr;
    }

    void printNetwork() {
        for (const auto& pair : devices) {
            cout << "Name: " << pair.second.name << endl;
            cout << "IP Address: " << pair.second.ipAddress << endl;
            cout << "MAC Address: " << pair.second.macAddress << endl;
            cout << "Type: " << pair.second.type << endl;
            cout << endl;
        }
    }
};


int main() {
    Network network;

    NetworkDevice router = {"Router1", "192.168.1.1", "AA:BB:CC:DD:EE:FF", "Router"};
    NetworkDevice switch1 = {"Switch1", "192.168.1.2", "11:22:33:44:55:66", "Switch"};
    NetworkDevice pc1 = {"PC1", "192.168.1.10", "77:88:99:AA:BB:CC", "PC"};


    network.addDevice(router);
    network.addDevice(switch1);
    network.addDevice(pc1);

    network.printNetwork();

    network.removeDevice("Switch1");

    cout << "Network after removing Switch1:" << endl;
    network.printNetwork();

    return 0;
}