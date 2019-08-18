//
// Created by angel on 11/08/2019.
//

namespace HeapNS{

    template <typename T>
    HeapInterface<T>::HeapInterface(Node<T>* array, size_t size) : _capacity(size), _heap_size(size) {
        _heap_array = new Node<T>[_capacity];
        std::copy(array, array + _heap_size, _heap_array);
        _instances++;
    }

    template<typename T>
    constexpr size_t HeapInterface<T>::left(size_t index) const {
        return (index * 2) + 1;
    }

    template<typename T>
    void HeapInterface<T>::print() {
        for(size_t i = 0; i < _heap_size ; i++)
            std::cout << _heap_array[i].key << " ";

        std::cout << std::endl;
    }

    template<typename T>
    constexpr size_t HeapInterface<T>::right(size_t index)  const{
        return  (index * 2) + 2;
    }


    template<typename T>
    constexpr size_t HeapInterface<T>::parent(size_t child) {
        return (child - 1) / 2;
    }


    template <typename T>
    HeapInterface<T>::~HeapInterface(){
        delete[](_heap_array);
        _instances--;
    }

    template<typename T>
    void HeapInterface<T>::build_heap(){
        for(int i = (_heap_size / 2) ; i >= 0; i-- )
            heapify(i);
    }

    template<typename T>
    Node<T>* HeapInterface<T>::getData() const{
        return _heap_array;
    }

    template <typename T>
    size_t HeapInterface<T>::size() const{
        return _heap_size;
    }

    template<typename B>
    std::ostream &operator<<(std::ostream &stream, const HeapInterface <B> &heap) {
        for(size_t i = 0; i < heap._heap_size ; i++)
            stream << heap._heap_array[i].key << " ";

        stream << std::endl;
        return stream;
    }

    template<typename T>
    int HeapInterface<T>::count_instances() {
        return _instances;
    }

    template<typename T>
    bool HeapInterface<T>::empty() const {
        return _heap_size == 0;
    }

    template<typename T>
    T HeapInterface<T>::top() const{
        return _heap_array[0].key;
    }

    template<typename T>
    T HeapInterface<T>::pop() {
        if (_heap_size < 1){
            std::cout << "Heap underflow!";
            return -1;
        }

        T max = top() ;
        _heap_array[0].key = _heap_array[_heap_size - 1].key;
        _heap_size --;
        heapify(0);

        return max;
    }

    template<typename T>
    const T& HeapInterface<T>::operator[](const size_t index) const{
        // valuta se usare uno static assert
        if (index >= 0 && index <= _heap_size - 1)
            return _heap_array[index].key;
        std::cerr << "Invalid index";
        std::exit(EXIT_FAILURE);
    }

    template <typename T>
    T& HeapInterface<T>::operator[](const size_t index) {
        // valuta se usare uno static assert
        if (index >= 0 && index <= _heap_size - 1)
            return _heap_array[index].key;
        std::cerr << "Invalid index";
        std::exit(EXIT_FAILURE);
    }



    template<typename T>
    bool HeapInterface<T>::erase(size_t index) {

        if (index <= (_heap_size - 1) ){
            std::swap(_heap_array[index].key, _heap_array[_heap_size - 1].key);
            _heap_size --;
            heapify(index);
            return true;
        }
        return false;
    }

    template<typename T>
    HeapInterface<T>::HeapInterface(const size_t count):_capacity(count), _heap_size(count) {
        _heap_array = new Node<T>[count];
    }

    template<typename T>
    HeapInterface<T>::HeapInterface(const HeapInterface <T> &other) {
        _heap_size = other._heap_size;
        _heap_array = new Node<T>[_heap_size];
        std::copy(other._heap_array, other._heap_array + _heap_size, _heap_array);
        _capacity = other._capacity;
        _instances++ ;

    }


} // HeapNS