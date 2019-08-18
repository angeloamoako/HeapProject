//
// Created by angel on 11/08/2019.
//

#pragma once
#include "HeapInterface.h"

namespace HeapNS{

    template <typename T>
    class MinHeap : public HeapInterface<T> {
    public:

        /**
         * @brief Costruisce un MinHeap a partire dalle chiavi contenute in array
         *  @param array Array di Node<T> contenente le chiavi dello heap.
         *  @param size numero di elementi in array
         */
        explicit MinHeap(Node<T>* array, size_t size): HeapInterface<T>(array, size) {};

        /**
         * @brief Costruisce un MinHeap di count elementi inizializzati al valore di default di T
         * @param count Numero di elementi del MinHeap
         */
        MinHeap(const MinHeap<T> &other);

        /**
         * @brief Costruisce un MinHeap di count elementi inizializzati al valore di default di T
         * @param count Numero di elementi del MinHeap
         */
        explicit MinHeap(int count): HeapInterface<T>(count) {};

        /**
         * @brief Copy-constructor
         * @param other MaxHeap a partire dal quale viene fatta la copia
         */
        MinHeap(const MaxHeap<T> &other) : HeapInterface<T>(other) {};


        /**
        *  @brief Controlla se la chiave del nodo padre è minore di quella dei figli, in caso negativo sposta la
        *  chiave minore nel nodo padre e la procedura viene invocata ricorsivamente sul nodo figlio che è stato
        *  scambiato.
        * @param father indice del nodo padre
        */
        void heapify(uint64_t father) override ;

        /**
         * @brief Inserisce un nodo di chiave key all'interno dello heap
         * @param key Chiave del nodo da inserire
         */
        void push(T key) override;

        /**
         * @brief Crea un nuovo heap con gli elementi di this ed other.
         * @param other Heap i cui elementi costituiscono parte dello Heap risultato
         * @return Restituisce un nuovo heap con gli elementi di this ed other
         */
        MinHeap<T> operator+(const MinHeap<T> &other);


        /**
         * @brief Verifica se array rappresenta un MinHeap
         * @param array Array contenente le chiavi dello heap
         * @param index Indice del nodo corrente. Inizialmente va posto a 0 per far partire l'algoritmo dalla radice
         * @param size Numero di elementi in array
         * @return true se array è uno MinHeap, false altrimenti
         */
        static bool checkMinHeap(Node<T>* array, int index, int size) ;

        ~MinHeap() = default;

    private:
        using HeapInterface<T>::_heap_size;
        using HeapInterface<T>::_heap_array;
        using HeapInterface<T>::_capacity;
        using HeapInterface<T>::_instances;
    };
} // HeapNS

#include "impl/MinHeap.i.h"
