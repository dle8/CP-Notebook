Wilson theorem: n is prime <=> (n - 1)! mod n = n - 1

Given an array of n integers: a[1], a[2], ..., a[n]
|a[1] - x| + |a[2] - x| + ... + |a[n] - x| min when x = median(a[1], a[2], ..., a[n])
(a[1] - x) ^ 2 + (a[2] - x) ^ 2 + ... + (a[n] - x) ^ 2 min when x = mean(a[1], a[2], ..., a[n])

n = f[1]^p[1] * f[2]^p[2] * ... * f[k]^p[k]
Number of factors of n: (p[1] + 1) * (p[2] + 1) * ... * (p[k] + 1)
Sum of factors of n: multiplication of (f[i] ^ (p[i] + 1) - 1) / (f[i] - 1) for i = 1 -> k

Modular multiplicative inverse m of x: inv(m, x), which means (x * inv(m, x)) mod m = 1
If m is prime, inv(m, x) = x ^ (m - 2)

Diophante equation: We can find x, y such that a * x + b * y = gcd(a, b)
