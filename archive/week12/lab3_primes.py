import time

def is_prime(n):
    if n < 2: return False
    if n == 2: return True
    if n % 2 == 0: return False
    i = 3
    while i * i <= n:
        if n % i == 0: return False
        i += 2
    return True

N = 1000000

s = time.perf_counter()
count = sum(1 for i in range(2, N + 1) if is_prime(i))
e = time.perf_counter()

ms = (e - s) * 1000
print(f"=== 실습 3: Python 소수 세기 ===")
print(f"소수 개수: {count}")
print(f"실행 시간: {ms:.0f} ms")