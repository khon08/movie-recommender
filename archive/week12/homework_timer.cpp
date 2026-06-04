#include <iostream>
#include <chrono>
#include <string>
#include <vector>
#include <algorithm>

// Timer klassi (RAII)
class Timer {
    std::chrono::high_resolution_clock::time_point start;
    std::string label;
public:
    Timer(const std::string& l) : label(l) {
        start = std::chrono::high_resolution_clock::now();
    }
    ~Timer() {
        auto end = std::chrono::high_resolution_clock::now();
        auto us = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
        std::cout << "[Timer] " << label << ": " << us.count() << " us\n";
    }
};

// Movie klassi
struct Movie {
    std::string title;
    std::string genre;
    double rating;
    Movie(const std::string& t, const std::string& g, double r)
        : title(t), genre(g), rating(r) {}
};

// MovieManager klassi
class MovieManager {
    std::vector<Movie> movies;
public:
    void addMovie(const Movie& m) {
        movies.push_back(m);
    }

    void printAll() const {
        Timer t("printAll");
        std::cout << "\n전체 영화 수: " << movies.size() << "개\n";
        for (const Movie& m : movies) {
            std::cout << m.title << " [" << m.genre << "] ★" << m.rating << "\n";
        }
    }

    std::vector<Movie> search(const std::string& keyword) const {
        Timer t("search");
        std::vector<Movie> result;
        for (const Movie& m : movies) {
            if (m.title.find(keyword) != std::string::npos ||
                m.genre.find(keyword) != std::string::npos) {
                result.push_back(m);
            }
        }
        std::cout << "검색 결과: " << result.size() << "개\n";
        return result;
    }

    std::vector<Movie> recommend(double minRating) const {
        Timer t("recommend");
        std::vector<Movie> result;
        for (const Movie& m : movies) {
            if (m.rating >= minRating) result.push_back(m);
        }
        std::sort(result.begin(), result.end(),
            [](const Movie& a, const Movie& b) {
                return a.rating > b.rating;
            });
        std::cout << "추천 결과: " << result.size() << "개\n";
        return result;
    }
};

int main() {
    MovieManager manager;

    std::vector<std::string> genres = {"액션", "드라마", "코미디", "SF", "공포"};
    for (int i = 0; i < 10000; i++) {
        double rating = 5.0 + (i % 50) * 0.1;
        manager.addMovie(Movie("Movie_" + std::to_string(i), genres[i % 5], rating));
    }
    manager.addMovie(Movie("인터스텔라", "SF", 9.5));
    manager.addMovie(Movie("기생충", "드라마", 9.2));
    manager.addMovie(Movie("범죄도시", "액션", 8.7));

    std::cout << "\n[1] printAll()\n";
    manager.printAll();

    std::cout << "\n[2] search('SF')\n";
    manager.search("SF");

    std::cout << "\n[3] recommend(9.0)\n";
    manager.recommend(9.0);

    return 0;
}