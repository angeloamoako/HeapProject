#include "MaxHeap.h"
#include "MinHeap.h"

int main() {
    HeapNS::Node<int> arr[] = {5, 1, 3, 4 , 2};
    HeapNS::MaxHeap<int> h(arr, 5);
    HeapNS::MinHeap<int> hMin(arr, 5);



    HeapNS::MaxHeap<int> h2 = h;
    auto h3 = h + h2;
    if (h3.size() ==  (2 * h.size())   )
        std::cout << "Le misure sono giuste\n";

    if (HeapNS::MaxHeap<int>::checkMaxHeap(h3.getData(), 0, h3.size()) == true ){
        std::cout << "h3 è uno heap\n";
        std::cout << h3;
    }

    std::cout << "Numero di istanze attive: " << HeapNS::HeapInterface<int>::count_instances();

    return 0;
}