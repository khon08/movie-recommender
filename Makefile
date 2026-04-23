all:
	clang++ main.cpp Movie.cpp MovieManager.cpp User.cpp UserManager.cpp Rating.cpp RatingManager.cpp -std=c++17 -o movie_recommender

clean:
	rm -f movie_recommender
