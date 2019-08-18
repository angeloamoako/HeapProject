Angelo Amoako
## Cosa include il progetto ##

* `CMakeLists.txt`
    - compilazione con i flag -Wall, -Wextra, -Wpedantic, -Werror (make)
    - test (`make test`)
    - clean all (doc, build, etc.) (`make clean-all`)
    - install (make install)
    
* `HeapInterface Class`
    - classe con template
    - alcuni metodi pure virtual
    - implementazione dei metodi non virtual nel file .i.h
    - friend operator <<
    - overload operator[]
    - parent(), left(), right() constexpr
    
* `MaxHeap Class`
    - classe con template
    - implementazione nel file .i.h
    - override heapify e push
     - overload operator+

* `HeapInterface Class`
    - classe con template
    - implementazione nel file .i.h
    - override heapify e push
     - overload operator+
    

* `Test` 
    - test funzionalita' di base e polimorfismo
    
* **Altre note**:  
        - codice all'interno di `namespace`
        - construttore marcati `explicit`
        - libreria `catch2` per il testing
        - metodi marcati `const`
        - Doxygen: parametri in/out
        - distinzione tra variabili di classe e non (prefisso `_`)   
    
## Utilizzo ##
Dopo aver clonato il repository in locale digitare i seguenti comandi per compilare il progetto ed eseguire i test:  
```bash
cd HeapProject
mkdir build
mkdir bin
mkdir docs
cd build
cmake ..
make
make test
```

**Nota**: La compilazione del file di test impiega circa 20 secondi

Per ottenere la documentazione digitare, sempre dalla directory build, il comando
`make doc` il cui output potrà essere trovato nella directory docs.
fe