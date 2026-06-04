# Movie Recommender System
**학번 (Student ID):** 20230114
**이름 (Name):** 파이줄라이브 셔히자헌
C++ based movie recommendation system using collaborative filtering.

## M4 Completed ✅

---

## Features
- BaseManager inheritance with pure virtual functions
- Similarity calculation between users
- Movie recommendation (collaborative filtering)
- CSV file I/O
- Edge case handling
- **[NEW] Genre filter (filterByGenre)**
- **[NEW] Statistics: average rating, by genre, Top N**

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
    g++ -std=c++17 Movie.cpp MovieManager.cpp Rating.cpp RatingManager.cpp Recommender.cpp User.cpp UserManager.cpp main.cpp -o movie_app

## How to Run
    ./movie_app

---

## Menu
    1. Add Movie
    2. Show All Movies
    3. Add User
    4. Show All Users
    5. Add Rating
    6. Show All Ratings
    7. Recommend Movies
    8. Filter by Genre      ← NEW
    9. Statistics           ← NEW
    0. Exit

---

## Recommendation Algorithm
recommend(userId, K, N) — 5 step flow:
1. Get my ratings
2. Calculate similarity with all other users
3. Select top K similar users
4. Collect movies I have not seen
5. Return top N movies by score

Similarity formula: common * 10 - diff

---

## Extended Features (Week 14)
### Genre Filter
- filterByGenre(genre) — returns movies matching the genre
- Integrated into menu option 8

### Statistics
- getAverageRating() — overall average rating
- getAverageRatingByGenre() — average rating per genre
- getTopN(n) — top N movies by rating

---

## Data Format
movies.csv

    id,title,genre,rating
    101,인터스텔라,SF,8.7

users.csv

    id,name
    1,Alice

ratings.csv

    userId,movieId,score
    1,101,5

---

## Requirements Checklist
- [x] BaseManager class (pure virtual: loadFromFile, saveToFile, size)
- [x] MovieManager, UserManager, RatingManager inherit BaseManager
- [x] Recommender class with similarity calculation
- [x] recommend() function (5-step flow)
- [x] CSV file I/O
- [x] Edge case handling
- [x] .gitignore applied
- [x] Genre filter (filterByGenre)
- [x] Statistics (average, by genre, Top N)
- [x] Git branch workflow (feature/genre-filter)
