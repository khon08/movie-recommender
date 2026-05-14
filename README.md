# Movie Recommender System

C++ based movie recommendation system using collaborative filtering.

## M3 Completed

### Features
- BaseManager inheritance with pure virtual functions
- Similarity calculation between users
- Movie recommendation (collaborative filtering)
- CSV file I/O

### How to build
make

### How to run
./movie_recommender

### M3 Requirements
- [x] BaseManager class (pure virtual: loadFromFile, saveToFile, size)
- [x] MovieManager, UserManager, RatingManager inherit BaseManager
- [x] Recommender class with Similaritycalculate()
- [x] recommend() function (5-step flow)
- [x] CSV file I/O
- [x] Edge case handling
