all:
	clang++ main.cpp Movie.cpp User.cpp Rating.cpp -std=c++17 -o movie_recommender

clean:
	rm -f movie_recommender