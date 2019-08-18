//
// Created by angel on 11/08/2019.
//

namespace HeapNS{
template<typename T>
    void MinHeap<T>::heapify(uint64_t father) {
        uint64_t l = HeapInterface<T>::left(father), r = HeapInterface<T>::right(father);
        uint64_t smallest = father; // suppongo che la radice abbia la chiave minima

        // individuo il nodo con chiave minima tra nodo radice ed i suoi 2 figli
        if((l < _heap_size) && (_heap_array[l].key < _heap_array[father].key) )
            smallest = l;
        if ((r < _heap_size) && (_heap_array[r].key < _heap_array[smallest].key) )
            smallest = r;

        if (smallest != father){
            std::swap(_heap_array[father].key, _heap_array[smallest].key);
            heapify(smallest);
        }
    }

    template<typename T>
    void MinHeap<T>::push(T key) {
        // aumento di 1 la dimensione dello heap ed aggiungo key alle foglie.

        if (_capacity == 0){
            Node<T>* temp = new Node<T>;
            _capacity = 1;
            _heap_size = 1;
            temp->key = key;
            _heap_array = temp;
        }
        else{

            if (_heap_size  + 1> _capacity){
                _capacity *= 2;
                Node<T>* temp = new Node<T>[_capacity];
                std::copy(_heap_array, _heap_array + _heap_size , temp);
                delete [] (_heap_array);
                _heap_array = temp;
            }
            _heap_size++;
            int index = _heap_size - 1;

            while (index >= 1 && _heap_array[HeapInterface<T>::parent(index)].key >= key){
                _heap_array[index].key  = _heap_array[HeapInterface<T>::parent(index)].key;
                index = HeapInterface<T>::parent(index);
            }
            _heap_array[index].key = key;
        }
    }

    template<typename T>
    MinHeap <T> MinHeap<T>::operator+(const MinHeap <T> &other) {
        auto *tempArray= new Node<T>[_heap_size + other._heap_size];
        std::copy(_heap_array, _heap_array + _heap_size, tempArray);
        std::copy(other._heap_array, other._heap_array + other._heap_size, tempArray + _heap_size);

        auto res = MinHeap(tempArray, _heap_size + other._heap_size);
        res.build_heap();

        delete []tempArray;
        return res;
    }


    template<typename T>
     bool MinHeap<T>::checkMinHeap(Node<T>* array, int index, int size) {
        // if i is a leaf node, return true as every leaf node is a heap
        if (2*index + 2 > size)
            return true;

        // if i is an internal node

        // recursively check if left child is heap
        bool left = (array[index].key <= array[2*index + 1].key) && checkMaxHeap(array, 2*index + 1, size);

        // recursively check if right child is heap (to avoid array out
        // of bound, we first check if right child exists or not)
        bool right = (2*index + 2 == size) ||
                     (array[index].key <= array[2*index + 2].key && checkMaxHeap(array, 2*index + 2, size) );

        // return true if both left and right child are heap
        return left && right;
    }


}
