//
// Created by angel on 11/08/2019.
//

#pragma once

#include "HeapInterface.h"

namespace HeapNS{

    template <typename T>
    class MaxHeap : public HeapInterface<T>{
    public:

        /**
         * @brief Costruisce un MaxHeap a partire dalle chiavi contenute in array
         *  @param array Array di Node<T> contenente le chiavi dello heap.
         *  @param size numero di elementi in array
         */
        explicit MaxHeap(Node<T>* array, size_t size): HeapInterface<T>(array, size) {};
        /**
         * @brief Copy-constructor
         * @param other MaxHeap a partire dal quale viene fatta la copia
         */
        MaxHeap(const MaxHeap<T> &other): HeapInterface<T>(other) {};

        /**
         * @brief Default constructor
         */
        explicit MaxHeap() = default;

        /**
         * @brief Costruisce un MaxHeap di count elementi inizializzati al valore di default di T
         * @param count Numero di elementi del MaxHeap
         */
        explicit MaxHeap(const size_t count): HeapInterface<T>(count) {};

        /**
        *  @brief Controlla se la chiave del nodo padre è maggiore di quella dei figli, in caso negativo sposta la
        *  chiave maggiore nel nodo padre e la procedura viene invocata ricorsivamente sul nodo figlio che è stato
        *  scambiato.
        * @param father indice del nodo padre
        */
        void heapify(uint64_t father) override;

        /**
         * @brief Verifica se array rappresenta un MaxHeap
         * @param array Array contenente le chiavi dello heap
         * @param index Indice del nodo corrente. Inizialmente va posto a 0 per far partire l'algoritmo dalla radice
         * @param size Numero di elementi in array
         * @return true se array è uno MaxHeap, false altrimenti
         */
        static bool checkMaxHeap(Node<T>* array, int index, int size);

        /**
         * @brief Crea un nuovo MaxHeap con gli elementi di this ed other.
         * @param other MaxHeap i cui elementi costituiscono parte dello Heap risultato
         * @return Restituisce un nuovo MaxHeap con gli elementi di this ed other
         */
        MaxHeap<T> operator+(const MaxHeap<T> &other);

        /**
         * @brief Inserisce un nodo di chiave key all'interno dello heap
         * @param key Chiave del nodo da inserire
         */
        void push(T key) override;
        ~MaxHeap() = default;


    private:
        using HeapInterface<T>::_heap_size;
        using HeapInterface<T>::_heap_array;
        using HeapInterface<T>::_capacity;
        using HeapInterface<T>::_instances;

    };
} //HeapNS

#include "impl/MaxHeap.i.h"