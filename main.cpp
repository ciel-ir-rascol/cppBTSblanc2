#include <iostream>
#include <iomanip> // Pour afficher en hexa

using namespace std;

int main() {
    // Adresse MAC 0xA48DB6 --> --:--:--:A4:8D:B6 --> 10784182
    unsigned int macAddr {0xA48DB6}; // Seuls les 3 derniers octets de l'addr MAC, les 3 premiers sont tjs les mêmes !

    // Pour sélectionner le 1er octet du groupe de 3 octets, il faut faire un décalage à droite de 16 bits (2 x 8 octets)
    unsigned int macAddrOctet1 {macAddr>>16};
    cout << "Octet 1 : " <<macAddrOctet1 << " " << hex << macAddrOctet1 << endl;

    // Pour sélectionner le 2ème octet du groupe de 3 octets, il faut faire un décalage à droite de 8 bits (1 octet)
    // et masquer afin d'enlever le 1er octet (le mettre à 0)
    unsigned int macAddrOctet2 {macAddr>>8 & 0xFF};
    cout << "Octet 2 : " << dec << macAddrOctet2 << " " << hex << macAddrOctet2 << endl;

    // Pour sélectionner le 3ème octet du groupe de 3 octets, il faut masquer les 2 premiers octets (les mettre à 0)
    unsigned int macAddrOctet3 {macAddr & 0xFF};
    cout << "Octet 3 : " << dec << macAddrOctet3 << " " << hex << macAddrOctet3 << endl;

    return 0;
}
