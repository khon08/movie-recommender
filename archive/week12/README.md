# Week 12 — 성능 측정과 최적화

C++ Programming | 숭실대학교 컴퓨터공학부

## 실습 목록

### 실습 1 — chrono 시간 측정
반복문 vs 수식으로 1억까지의 합 계산

| 방법 | 시간 |
|------|------|
| 반복문 | 114,985 us |
| 수식 | 0 ns |

### 실습 2 — const& 최적화
값 전달 vs const 참조 전달 비교

| 방법 | 시간 |
|------|------|
| 값 전달 | 3,274 ms |
| const& 전달 | 0 ms |

### 실습 3 — C++ vs Python
100만까지 소수 개수 세기 (결과: 78,498개)

| 언어 | 시간 |
|------|------|
| Python | 1,450 ms |
| C++ -O0 | 49 ms |
| C++ -O2 | 32 ms |

### 과제 — Timer + MovieManager
RAII 기반 Timer 클래스로 주요 함수 3개 측정

| 함수 | 시간 |
|------|------|
| printAll() | 4,411 us |
| search() | 76 us |
| recommend() | 47 us |

## 빌드 및 실행

make        # 컴파일
make run    # 전체 실행
make clean  # 삭제