//
// Created by angel on 11/08/2019.
//


namespace HeapNS{

    template<typename T>
    void MaxHeap<T>::push(T key){
        // aumento di 1 la dimensione dello heap ed aggiungo key alle foglie.

        if (_capacity == 0){
            auto temp = new Node<T>;
            _capacity = 1;
            _heap_size = 1;
            temp->key = key;
            _heap_array = temp;
        }
        else{

            if (_heap_size  + 1> _capacity){
                _capacity *= 2;
                auto temp = new Node<T>[_capacity];
                std::copy(_heap_array, _heap_array + _heap_size , temp);
                delete [] (_heap_array);
                _heap_array = temp;
            }
            _heap_size++;
            int index = _heap_size - 1;

            while (index >= 1 && _heap_array[HeapInterface<T>::parent(index)].key <= key){
                _heap_array[index].key  = _heap_array[HeapInterface<T>::parent(index)].key;
                index = HeapInterface<T>::parent(index);
            }
            _heap_array[index].key = key;
        }
    }


    template<typename T>

    bool MaxHeap<T>::checkMaxHeap(Node<T>* array, int index, int size) {
        // if i is a leaf node, return true as every leaf node is a heap
        if (2*index + 2 > size)
            return true;

        // if i is an internal node

        // recursively check if left child is heap
        bool left = (array[index].key >= array[2*index + 1].key) && checkMaxHeap(array, 2*index + 1, size);

        // recursively check if right child is heap (to avoid array out
        // of bound, we first check if right child exists or not)
        bool right = (2*index + 2 == size) ||
                     (array[index].key >= array[2*index + 2].key && checkMaxHeap(array, 2*index + 2, size) );

        // return true if both left and right child are heap
        return left && right;
    }

    template<typename T>
    MaxHeap <T> MaxHeap<T>::operator+(const MaxHeap <T> &other) {
        auto *tempArray= new Node<T>[_heap_size + other._heap_size];
        std::copy(_heap_array, _heap_array + _heap_size, tempArray);
        std::copy(other._heap_array, other._heap_array + other._heap_size, tempArray + _heap_size);

        auto res = MaxHeap(tempArray, _heap_size + other._heap_size);
        res.build_heap();

        delete []tempArray;
        return res;
    }

    template<typename T>
    void MaxHeap<T>::heapify(uint64_t father) {

        uint64_t l = HeapInterface<T>::left(father), r = HeapInterface<T>::right(father);
        uint64_t largest = father; // suppongo che la radice abbia la chiave più grande

        // individuo il nodo con chiave massima tra nodo radice ed i suoi 2 figli
        if((l < _heap_size) && (_heap_array[l].key > _heap_array[father].key) )
            largest = l;
        if ((r < _heap_size) && (_heap_array[r].key > _heap_array[largest].key) )
            largest = r;

        if (largest != father){
            std::swap(_heap_array[father].key, _heap_array[largest].key);
            heapify(largest);
        }
    }


} // HeapNS