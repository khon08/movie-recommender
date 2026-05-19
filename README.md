markdown# Movie Recommender System

**학번 (Student ID):** 20230114
**이름 (Name):** 파이줄라이브 셔히자헌

C++ based movie recommendation system using collaborative filtering.

## M3 Completed

---

## Features

- BaseManager inheritance with pure virtual functions
- Similarity calculation between users
- Movie recommendation (collaborative filtering)
- CSV file I/O
- Edge case handling

---

## Project Structure
movie-recommender/
├── main.cpp
├── Movie.h / Movie.cpp
├── MovieManager.h / MovieManager.cpp
├── User.h / User.cpp
├── UserManager.h / UserManager.cpp
├── Rating.h / Rating.cpp
├── RatingManager.h / RatingManager.cpp
├── Recommender.h / Recommender.cpp
├── BaseManager.h
├── Makefile
├── .gitignore
└── data/
├── movies.csv
├── users.csv
└── ratings.csv

---

## How to Build

```bash
make
```

## How to Run

```bash
./movie_recommender
```

## How to Clean

```bash
make clean
```

---

## Recommendation Algorithm

`recommend(userId, K, N)` — 5 step flow:

1. Get my ratings
2. Calculate similarity with all other users
3. Select top K similar users
4. Collect movies I have not seen
5. Return top N movies by score

Similarity formula: `common * 10 - diff`

---

## Data Format

**movies.csv**
id,title,genre,rating
101,인터스텔라,SF,0

**users.csv**
id,name
1,Alice

**ratings.csv**
userId,movieId,score
1,101,5

---

## M3 Requirements

- [x] BaseManager class (pure virtual: loadFromFile, saveToFile, size)
- [x] MovieManager, UserManager, RatingManager inherit BaseManager
- [x] Recommender class with Similaritycalculate()
- [x] recommend() function (5-step flow)
- [x] CSV file I/O
- [x] Edge case handling
- [x] .gitignore applied (no .o files in repo)
- [x] Makefile with -Wall -Wextra flags