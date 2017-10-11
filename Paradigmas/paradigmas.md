# Paradigmas de Soluções de Problemas

## Busca Completa (Força Bruta)

Técnica: percorrer todo o conjunto de possíveis soluções para encontrar a
solução correta. Durante a busca, é possível escolher não explorar partes
específicas desse conjunto.

* Obs: Tais soluções costumam não receber WA, apenas TLE, por terem um
custo computacional muito elevado.

### B.C. Iterativa (UVa 725)
Encontre e imprima todos os pares de números A, B, tal que A e B tenham apenas 5 dígitos cada e A / B = N, para um N inteiro e A e B juntos tenham todos os dígitos de 0 a 9.

``` c++
int n;
cin >> n;
for (int a = 1234; a <= 98765; a++) {
    int b = a * n;
    int bits = 0;
    imt tmp = a;

    for (int i = 0; i < 5; i++) {
        bits |= (1 << (tmp % 10));
        tmp /= 10;
    }
    
    tmp = b;

    for (int i = 0; i < 5; i++) {
        bits |= (1 << (tmp % 10));
        tmp /= 10;
    }

    if (bits == (1 << 10) - 1) {
        cout << b << "/" << a << "=" << n << endl;
    }
} 
```

### B.C. vários loops (UVa 441)
Dado 6 < k < 13 inteiros ordenados, encontre todos os subconjuntos de tamanho 6 deste conjunto.

```c++
for (int a = 0; a < k - 5; a++) 
for (int b = a + 1; a < k - 4; a++)
for (int c = a + 2; a < k - 3; a++)
for (int d = a + 3; a < k - 2; a++)
for (int e = a + 4; a < k - 1; a++)
for (int f = a + 5; a < k; a++)
    printf("%d %d %d %d %d %d\n",
        v[a], v[b], v[c], v[d], v[e], v[f]);
```

### B.C. com "poda" (UVa 11565)
Dados 3 números 1 <= A, B, C <= 10⁴, encontre x, y, z, tal que:

    x + y + z = A,
    x * y * z = B,
    x² + y² + z² = C

```c++
for (int x = -100; x <= 100; x++)
for (int y = -100; y <= 100; y++)
for (int z = -100; z <= 100; z++)
    if (x != y && x != z && y != z &&
        x + y + z == A && x * y * z == B &&
        x * x + y * y + z * z == C)
        printf("%d %d %d\n", x, y, z);
```

### B.C. subconjuntos (UVa 12455)
Dada uma lista de até 20 inteiros, imprima todos os subconjuntos desta lista, tal que sua soma seja igual a um inteiro x.

```c++
for (int i = 0; i < (1 << 20); i++) {
    int sum = 0;
    for (int j = 0; j < 20; j++) {
        if (i & (1 << j)) {
            sum += v[j];
        }
    }
}
```

### B.C. Recursivo - Backtracking (UVa 750)
Dado um tabuleiro de xadrez são dispostas 8 rainhas. Imprima todas as formas de colocar as rainhas, tal que, uma não consiga atacar a outra.

```c++
int r[8] = {};
bool isSolution(int col, int row) {
    for (int i = 0; i < col; i++) {
        if (r[i] == row) {
            return false;
        }
        if (abs(col - i) == abs(r[i] - row)) {
            return false;
        }
    }
    return true;
}

void backtracking(int col) {
    if (col == 8) {
        for (int i = 0; i < 8; i++) {
            cout << i << ","<< r[i] << " " << cout << endl;
        }
    }
    for (int i = 0; i < 8; i++) {
        if (isSolution(col, i)) {
            r[col] = i;
            backtracking(col + 1);
        }
    }
}
```

## Dividir e Conquistar

### Técnica:
Dividir o problema em sub-problemas, encontrar as soluções de cada sub-problema e, se necessário, combinar as sub-soluções para encontrar a solução final.

### Busca Binária
Dado um vetor ordenado, determine seum inteiro X está presente no vetor.

* Estudar vector:lower_bound

### Método da Bisseção
Dada uma função f(x) definida em um intervalo [A, B], encontre x0 ∈ [A, B], tal que f(x0) = 0.

## Algoritmos Gulosos

### Técnica:
Faça a melhor escolha local a cada passo, até que (com sorte) seja encontrada a solução.

Em vários casos, algoritmos gulosos não funcionam (problemas de programação dinâmica), mas quando funcionam, o código será pequeno e eficiente.

### Coin Change (Versão gulosa)
Dado um montante M e uma uma lista de moedas disponíveis, determine a menor quantidade de moedas para representar M.

### Balança de Carga (UVa 410)
Dada uma balança com dois pratos e uma lista de pesos, encontre o menor desequilíbrio possível, ao colocarmos todos os pesos nas balanças. 