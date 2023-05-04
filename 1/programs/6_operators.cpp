#include <bits/stdc++.h>
using namespace std;

int main() {

    int a = 5, b = 9;   // a = 5(0...0101), b = 9(0...01001) // 32 bits (int)
    cout << (a^b) << "\n";   // 00001100      // XOR
    cout << (a << 3) << "\n";   // a * 8
    cout << (~a) << "\n";       // 11...1010
    cout << "2's complement: " << -a << ' ' << (~a + 1) << "\n";
    // &, |

    // https://www.geeksforgeeks.org/c-bitset-and-its-application/

    bitset<10> bset1;
    bitset<10> bset2(20);
    bitset<10> bset3(string("1100"));

    // 0000000000
    // 0000010100
    // 0000001100

    bitset<8> set8; // 00000000

    set8[1] = 1; // 00000010
    set8[4] = set8[1]; // 00010010
    cout << set8 << ' ' << (int)(set8.to_ulong()) << endl;

    // count function returns number of set bits in bitset
    cout << set8.count() << '\n';
  
    // any() function returns true iff atleast 1 bit is set
    // none() function returns true iff none of the bit is set
  
    // set() sets all bits
    cout << set8.set() << endl;
  
    // reset function makes all bits 0
    cout << set8.reset() << endl;
  
    // flip function flips all bits
    cout << set8.flip(2) << endl;
    cout << set8.flip() << endl;        // set8[..]=1

    // Converting decimal number to binary with bitset
    int num = 9;
    cout << num << ' ' << bitset<8>(num);
    
}