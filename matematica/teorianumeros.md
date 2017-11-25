# Teoria dos Números


## Divisibilidade
----
Um número a é dito divisível por b, se a % b = 0.

Podemos definir o símbolo "|" (divide) da seguinte forma:

    a | b (lê-se 'a divide b'), se b é divisível por a.

Da mesma forma, se b não é divisível por a, então:

    a !| b (a não divide b).

Se a | b, então:

    b = c.a

Se a !| b, então:

    b = c.a + r, r != 0

**Divisor próprio:** a é dito divisor próprio de b, se a != b e a | b.

**Número primo:** é um número que contém apenas um divisor próprio.

**Alg. 01. verificação de primalidade O(n):**
```c++
bool is_prime(ll N) {
    if (N == 1) {
        return false;
    }

    for (ll i = 2; i < N; i++) {
        if (N % i == 0) {
            return false;
        }
    }

    return true;
}
```

**Otimização 1:**

Se n ∉ P, onde P é o conjunto de números primos.

Então:

    n = a.b, onde a.b > 1

Ou a ou b é menor ou igual a sqrt(n).

Por contradição, se a > sqrt(n) e b > sqrt(n), temos:

    a = sqrt(n) + c1,
    b = sqrt(n) + c2

    n = a.b = (sqrt(n) + c1)(sqrt(n) + c2)
        n = n + sqrt(n)(c1 + c2) + c1.c2 // c1, c2 > 0

**Otimização 2:**

O número 2 é o único primo par.

**Alg. 02: verificação de primalidade O(sqrt(n)):**
```c++
bool is_prime(ll N) {
    if (N == 1 || (N > 2 && N % 2 == 0)) {
        return false;
    }

    for (ll i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}
```

### Encontrando todos os primos até um limite N:
* Utilizar a função is_prime(n) ∀ a <= N
* **Crivo de Eratóstenes:** suponha inicialmente que todos os números menores ou iguais a N são "prováveis primos". Comece pelo número 2 e "corte" todos os seus múltiplos no intervalo [p², N]. Repita o processo até p <= N.

```c++
vi sieve(ll N) {
    ui primes = vi(2, 1);
    bitset<10^8> is_prime;
    is_prime.set();

    for (ll i = 3; i <= N; i += 2) {
        if (is_prime[i])  {
            primes.push_back(i);
            for (ll j = i * i; j <= N; j += 2 * i) {
                is_prime[j] = false;
            }
        }
    }

    return primes;
}
```

**Ordem de complexidade:**

    N * (N/P1 + N/P2 + N/P3 + ... N/Pm), ∀ Pi <= N
    N² * (1/2 + 1/3 + 1/5 + ...)
    N . ∑ n/p ≈ n log(log(n))

    O(N.log(log(n))) 

**Alg. 04: verificação de primalidade utilizando o crivo O(#primos <= sqrt(n)):**

* Função ∏(n): quantidade de números primos até N.

    ∏(n) ≈  N/log(sqrt(n)) + 1

```c++
bool is_prime(ll N) {
    if (N == 1) {
        return false;
    }

    for (ll i = 0; primes[i] <= sqrt(N); i++) {
        if (N % primes[i] == 0) {
            return false;
        }
    }

    return true;
}
```

## Fatoração
----

* **Teorema Fundamental da Aritmética:** Todo número natural pode ser representado como as potências de produtos de números primos, e essa representação é única.

    n = p0^k0 p1^k1 ... pm^km, p ∈ P, k ∈ N

**Alg 05: Fatoração de um inteiro positivo N.**
```c++
vi factors(ll N) {
    vi fac;
    for (ll i = 0; primes[i] <= sqrt(N); i++) {
        while (N % primes[i] == 0) {
            fac.push_back(primes[i]);
            N /= primes[i];
        }
    }
    if (N != 1) {
        fac.push_back(N);
    }

    return fac;
}
```

## Maior Divisor Comum (GCD)
---

    A = 2³ . 3⁵ . 11²
    B = 2 . 5² . 11⁸

    gcd(A, B) = 2 . 11²

gcd(A, B) é o maior c, tal que c | A e c | B.

    gcd(A, B) = gcd(abs(A - B), min(A, B))
                                - Euclides
                                  300 b.C

    gcd(36, 26) = gcd(10, 26)
                = gcd(16, 10)
                = gcd(6, 10)
                = gcd(4, 6)
                = gcd(2, 4)
                = gcd(2, 2)
                = gcd(0, 2)
                = gcd(2, 0)
                = 2

    gcd(252, 104) = gcd(148, 104)
                  = gcd(44, 104)

    gcd(A, B) = gcd(max % min, min)
    gcd(A, 0) = A
    gcd(A, B) = gcd(B, A(mod B))

**Alg. 06: gcd, fórmula de Euclides:**
```c++
ll gcd(ll A, ll B) {
    return (!B = ? A : gcd(B, A % B));
}
```

### Teorema de Gabriel Lamé
----
O gcd calculado pela fórmula de Euclides realiza, no máximo, **5 . (#dígitos min(A, B))** ciclos para encontrar o resultado.

* O(log(min(A, B)))

### Aplicação do GCD
---
* **Simplificação de frações**

    36 / 26 = 18 / 13

    Exemplo: pontos no grid:
        
        1⁰ ponto com coordenadas inteiras:
        (A/gcd(A, B), B/gcd(A, B))

### Menor Múltiplo Comum (LCM)
---
    A = 2³ . 7² . 13
    B = 2² . 7 . 11
    lcm(A,B) = 2³ . 7² . 11 . 13

    A . B = 2³ . 2² . 7² . 7 . 11 . 13
          = (2³ . 7² . 11 . 13) . (2² . 7)

    lcm(A, B) = (A . B) / gcd(A, B)

**Alg. 07: menor múltiplo comum**
```c++
ll lcm(ll A, ll B) {
    return A * (B / gcd(A, B));
}
```

***Estudar***

* sumPF(A) - soma de fatores primos
* diffPF(A, B) 
* numDiffPF(A)
* numDiv(A)
* sumDiv(A)

## Número de Fibonnacci
---
    Fn = F(n-1) + F(n - 2), se n >= 2
       = 1, c.c.

    fn = [F(n + 1)]    f0 = [1]
         [   Fn   ];        [0]

    f1 = [1, 1]        f0 = [1, 1] . [1] = [1.1 + 1.0]
         [1, 0]             [1, 0]   [0]   [1.1 + 0.0]

    f(n+1) = [1, 1] . [F(n + 1)] = [F(n + 1) + Fn] = [F(n + 2)]
             [1, 0]   [   Fn   ]   [   F(n + 1)  ]   [F(n + 1)]

    f(n+1) = [A] . fn = [A].[A].f(n-1)
    f(n+1) = A^n . f0

```c++
vvi mult(vvi A, vvi B) {
    vvi C;
    C[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0];
    ...
    return C;
}

vvi pow(vvi A, ll p) {
    vvi base = A;
    vvi ans = (2, vi(2, 0));

    while (p) {
        if (p & 1) {
            ans = mult(base, ans);
        }
        base = mult(base, base);
        p >>= 1;
    }
    return ans; 
}

int main() {
    vvi A(2, vi(2, 0));
    A[0][0] = A[0][1] = A[1][0] = 1;

    int N;
    cin >> N;
    A = pow(A, N);

    cout << A[0][0] << endl;
}
```