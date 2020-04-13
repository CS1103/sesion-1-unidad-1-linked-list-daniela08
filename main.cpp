#include <iostream>
#include <cassert>
#include <string>
#include "linked_list.h"

using namespace std;

int main() {

    utec::linked_list_t ll;

    // Probar el metodo push_front;
    for(int i = 0; i < 10; ++i) {
        ll.push_front(i);
    }
    // Verifico el tamano
    assert(ll.size() == 10);
    string result;
    for (int i = 0; i < 10; ++i) {
        result += to_string(ll.item(i)) + " ";
    }
    assert(result == "9 8 7 6 5 4 3 2 1 0 ");


    // Probar el metodo pop_front;
    for(int i = 0; i < 5; ++i) {
        ll.pop_front();
    }
    // Verifico el tamano
    assert(ll.size() == 5);
    string result2;
    for(int i = 0; i < 5; ++i) {
        result2 += to_string(ll.item(i))+ " ";
    }
    assert(result2 == "4 3 2 1 0 ");


    //Probar el metodo push_back
    for(int i = 0; i < 5; ++i){
        ll.push_back(i);
    }
    //Verifico el tamano
    assert(ll.size() == 10);
    string result3;
    for(int i = 0; i < 10; ++i){
        result3 += to_string(ll.item(i))+ " ";
    }
    assert(result3 == "4 3 2 1 0 0 1 2 3 4 ");


    //Probar el metodo pop_back
    for(int i = 0; i < 5; ++i) {
        ll.pop_back();
    }
    //Verifico el tamano
    assert(ll.size() == 5);
    string result4;
    for(int i = 0; i < 5; ++i) {
        result4 += to_string(ll.item(i))+ " ";
    }
    assert(result4 == "4 3 2 1 0 ");


    //Probar el metodo insert
    ll.insert(3,1);
    //Verifico el tamano
    assert(ll.size() == 6);
    string result5;
    for(int i = 0; i < 6; ++i) {
        result5 += to_string(ll.item(i))+ " ";
    }
    assert(result5 == "4 3 2 1 1 0 ");


    //Probar el metodo erase
    ll.erase(4);
    //Verifico el tamano
    assert(ll.size() == 5);
    string result6;
    for(int i = 0; i < 5; ++i) {
        result6 += to_string(ll.item(i))+ " ";
    }
    assert(result6 == "4 3 2 1 0 ");


    cout << "Ejecucion exitosa!!" << endl;
    return 0;
}
