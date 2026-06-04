# Debug Report — Week 10 2차시

## BUG 1 — 결과 값이 잘못됨 (buggy_v1)

### 사용 도구
조건부 BP + print 표현식

### LLDB 세션 로그
break set -f SimilarityCalculator.cpp -l 21
run
print commonCount    → 2
print scoreDiffSum   → 1
print commonCount * 10 - scoreDiffSum  → 19 (기대값)

### 원인
return commonCount - scoreDiffSum; 에서 * 10 이 빠짐

### 수정
return commonCount * 10 - scoreDiffSum;

---

## BUG 2 — scoreDiffSum 누적 이상 (buggy_v2)

### 사용 도구
Watchpoint + print 변수

### LLDB 세션 로그
watch set var scoreDiffSum
continue
scoreDiffSum 변하지 않음, 결과 -100
getUserId() 비교로 user1(ID=1)과 user2(ID=2)가 매칭 안 됨

### 원인
r1.getUserId() == r2.getUserId() 로 비교해서 공통 영화를 못 찾음

### 수정
if (r1.getMovieId() == r2.getMovieId())

---

## BUG 3 — Segmentation Fault (buggy_v3)

### 사용 도구
Backtrace + frame N

### LLDB 세션 로그
run → EXC_BAD_ACCESS (code=1, address=0x0)
bt
#0 vector::begin (this=NULL)
#1 calculate (user2=size=0)
#2 main.cpp:15
frame select 3
print user2Ptr → nullptr

### 원인
user2Ptr = nullptr 로 초기화하고 역참조(*user2Ptr)하여 Segfault 발생

### 수정
std::vector<Rating> user2 = {
    Rating(2, 101, 5),
    Rating(2, 102, 5),
    Rating(2, 104, 4)
};
int sim = SimilarityCalculator::calculate(user1, user2);