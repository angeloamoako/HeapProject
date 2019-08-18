// Created by Angelo Amoako on 25/07/2019.


#pragma once
#include <iostream> //std::cout
#include <cstddef> // size_t
#include <algorithm> // std::copy

namespace HeapNS{

    /**
     * @brief Struct contenente la chiave di un nodo dello heap
     * @tparam T tipo della chiave
     */
    template<typename T>
    struct Node {
        T key;
    };

    template<typename T>
    class HeapInterface {

    public:

        /**
        * @brief Defaul constructor: crea uno Heap vuoto
        * @return
        */
        HeapInterface() = default;

        /**
        * @brief User provided constructor: Costruisce uno heap con gli elementi contenuti in array.
         * @param[in] array Puntatore al primo elemento di un array di struct Node.
         * @param[in] size Rappresenta il numero di chiavi che saranno presenti nello heap.
        * @return
        */
        explicit HeapInterface(Node<T>* array, size_t size);
        HeapInterface(const HeapInterface<T> &other);

        /**
         * @brief Costruisce uno heap con count elementi  inizializzati al valore di default di T
         * @param[in] count numero di elementi che conterrà lo heap
         */
        explicit HeapInterface(size_t count);

        /**
        * @brief  Dealloca _heap_array
        *
        */
        virtual ~HeapInterface();

       /**
        * @brief
        *
        */
        virtual void heapify(uint64_t father) = 0;


        /**
        *  @brief Costruisce ricorsivamente uno heap a partire dall'array heap_array
        */
        void build_heap();

        /**
         * @brief Calcola la posizione del figlio sinistro
         * @param[in] index Indice del nodo di cui si vuole ottenere il figlio sinistro
         * @return Restituisce l'indice del figlio sinistro del nodo index
         */
        constexpr size_t left(size_t index) const;

        /**
         * @brief Calcola la posizione del figlio destro
         * @param[in] index Indice del nodo di cui si vuole ottenere il figlio destro
         * @return Restituisce l'indice del figlio destro del nodo index
         */
        constexpr size_t right(size_t index) const;

        /**
         *  @brief Calcola la posizione del padre di child
         * @param[in] child Indice del nodo di cui si vuole ottenere il padre
         * @return Restituisce l'indice del nodo padre di  child
         */
        constexpr size_t parent(size_t child) ;

        /**
         * @brief Stampa il contenuto dello heap
         */
        void print();

        /**
         * @brief Verifica se lo heap è vuoto
         * @return Restituisce true se lo heap non contiene nodi, false altrimenti
         */
        bool empty() const;


        /**
         * @brief Restituisce la chiave massima(MaxHeap) / minima(MinHeap) presente nello heap
         * @return Restituisce la chiave del nodo che risiede nella radice
         */
        T top() const;


        /**
         * @brief Estrae la radice
         * @return Estrae il nodo di chiave massima(MaxHeap) / minima(MinHeap), che risiede nella radice, e riordina la struttura sottostante
         */
        T pop () ;

        // const overloading
        const T& operator[] (const size_t index) const;
        T& operator[] (const size_t index) ;


        /**
         * @brief Mostra i dati dello heap
         * @return Restituisce un array contenente i nodi dello heap
         */
        Node<T>* getData() const;

        /**
         * @brief Mostra la dimensione dello heap
         * @return Restituisce il numero di elementi attualmente contenuti nello heap
         */
        size_t size() const;


        /**
         * @brief Overload dello stream operator
         * @param[in] heap Heap di cui si vuole stampare il contenuto
         * @param[out] stream su cui verrà concatenato il contenuto dello heap
         */
        template<typename B>
        friend std::ostream& operator<< (std::ostream& stream, const HeapInterface<B> &heap);


        /**
        * @brief Conta il numero di Max/Min heap attivi
        * @return Restituisce il numero di istanze attive al momento della chiamata
        */
        static int count_instances();

        bool erase(size_t index);
        virtual void push(T key) = 0;


    protected:
        size_t _capacity { 0 };  // lunghezza di _heap_array
        size_t _heap_size { 0 }; // numero di valori effettivamente memorizzati all'interno dello heap (numero di nodi)
        Node<T>* _heap_array { nullptr };
        static size_t _instances ;
    };

    template<typename T>
    uint64_t HeapInterface<T>::_instances {0};

} // namespace HeapNS

#include "impl/HeapInterface.i.h"
