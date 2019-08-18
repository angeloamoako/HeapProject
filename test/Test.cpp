#define CATCH_CONFIG_MAIN
#   include "catch.hpp"
#undef CATCH_CONFIG_MAIN

#include "MaxHeap.h"
#include "MinHeap.h"

TEST_CASE("Heap integrity test", "[isHeap]"){

    HeapNS::Node<int> input[] = {35, 33, 42, 10, 14, 19, 27, 44, 26, 31};
    HeapNS::MaxHeap<int> h(input, sizeof(input) / sizeof(input[0]));
    h.build_heap();

    REQUIRE(HeapNS::MaxHeap<int>::checkMaxHeap(h.getData(), 0, h.size())  == true);
}
TEST_CASE("Heap test", "[notHeap]"){
    HeapNS::Node<int> input[] = {1, 2, 3, 4, 5};
    REQUIRE(HeapNS::MaxHeap<int>::checkMaxHeap(input, 0, 5) == false);
}

TEST_CASE("TopANDPopement", "[top/pop]"){
    HeapNS::Node<int> input[] = {500, 20, 30, 10 , 15, 1};
    HeapNS::MaxHeap<int> h(input, sizeof(input)/ sizeof(input[0]));
    h.build_heap();

    REQUIRE(h.top() == 500);
    h.pop();
    REQUIRE(h.top() == 30);
}

TEST_CASE("Copy-ctorAND+", "[copy/+]"){
    HeapNS::Node<int> input[] = {1, 2, 3, 4, 5};
    HeapNS::MaxHeap<int> first(input, sizeof(input)/ sizeof(input[0]));

    HeapNS::MaxHeap<int> second = first;
    REQUIRE( (first + second).size() == (2 * first.size()) );
}

TEST_CASE("Test polymorphism", "[Polymorphism]"){
    HeapNS::Node<int> input[] = {1, 2, 3, 4, 5};

    HeapNS::MaxHeap<int> h(input, 5);
    HeapNS::MinHeap<int> hMin(input, 5);


    HeapNS::HeapInterface<int>& max = h;
    HeapNS::HeapInterface<int>& min = hMin;

    // build_heap chiama 2 versioni di heapify a seconda dell'istanza
    max.build_heap();
    min.build_heap();

    REQUIRE(max.top() == 5);
    REQUIRE (min.top() == 1);
}