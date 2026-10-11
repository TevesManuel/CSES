# Tower of Hanoi

- game: https://www.mathsisfun.com/games/towerofhanoi.html

Tuve la idea de hacer un algoritmo greddy de toma de decisiones con un vector de 3 stacks lifo

### 4 pieces (solved in 15 movements with std::vector<std::stack<int>> view(3))
__________________________
1 0 0
2 1 0
3 1 2
3 0 1
4 3 1
1 3 2
1 2 0
4 1 0
0 1 4
0 2 1
2 3 1
1 3 4
1 0 3
2 1 3
0 1 2
0 0 1
__________________________

### 3 pieces (solved in 7 movements with std::vector<std::stack<int>> view(3))
__________________________
1 0 0
2 0 1
3 2 1
3 1 0
0 1 3
1 2 3
1 0 2
0 0 1
__________________________

#### 1ra observacion
Siendo N el numero de piezas, si N es par => empieza como ( 1 0 0 -> 2 1 0 -> 3 1 2 ) sino ( es impar ) => ( 1 0 0 -> 2 0 1 -> 3 2 1 )

#### 2da obs
1 se mueve cada 2 turnos, para par A -> B -> C -> A -> B -> C -> ... y para impar A -> C -> B -> A -> B -> ...

#### 3ra obs
Si tengo un movimiento ciclico de 1 cada 2 turnos (Turno A -> Turno B -> Turno C), si en A y en C se va a mover el 1, signifca que en B tengo un solo movimiento posible.