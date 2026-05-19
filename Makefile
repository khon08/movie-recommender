CXX = clang++
CXXFLAGS = -std=c++17 -Wall -Wextra

SRCS = main.cpp Movie.cpp MovieManager.cpp User.cpp UserManager.cpp \
       Rating.cpp RatingManager.cpp Recommender.cpp

TARGET = movie_recommender

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)