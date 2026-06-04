#include <iostream>
#include "MovieManager.h"
#include "UserManager.h"
#include "RatingManager.h"
#include "Recommender.h"
using namespace std;

int main() {
    MovieManager movieMgr;
    UserManager userMgr;
    RatingManager ratingMgr;
    movieMgr.loadFromFile("data/movies.csv");
    userMgr.loadFromFile("data/users.csv");
    ratingMgr.loadFromFile("data/ratings.csv");
    Recommender recommender(movieMgr, ratingMgr);
    int choice;
    while (true) {
        cout << "\n=== Movie Recommender ===" << endl;
        cout << "1. Add Movie" << endl;
        cout << "2. Show All Movies" << endl;
        cout << "3. Add User" << endl;
        cout << "4. Show All Users" << endl;
        cout << "5. Add Rating" << endl;
        cout << "6. Show All Ratings" << endl;
        cout << "7. Recommend Movies" << endl;
        cout << "8. Filter by Genre" << endl;
        cout << "9. Statistics" << endl;
        cout << "0. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;
        if (choice == 0) {
            movieMgr.saveToFile("data/movies.csv");
            userMgr.saveToFile("data/users.csv");
            ratingMgr.saveToFile("data/ratings.csv");
            cout << "Program ended." << endl;
            break;
        }
        else if (choice == 1) {
            int id; string title, genre; float rating;
            cout << "Movie ID: "; cin >> id; cin.ignore();
            cout << "Title: "; getline(cin, title);
            cout << "Genre: "; getline(cin, genre);
            cout << "Rating: "; cin >> rating;
            movieMgr.addMovie(Movie(id, title, genre, rating));
            cout << "Movie added!" << endl;
        }
        else if (choice == 2) {
            movieMgr.printAll();
        }
        else if (choice == 3) {
            int id; string name;
            cout << "User ID: "; cin >> id; cin.ignore();
            cout << "Name: "; getline(cin, name);
            userMgr.addUser(User(id, name));
            cout << "User added!" << endl;
        }
        else if (choice == 4) {
            userMgr.printAll();
        }
        else if (choice == 5) {
            int uid, mid; float score;
            cout << "User ID: "; cin >> uid;
            cout << "Movie ID: "; cin >> mid;
            cout << "Score: "; cin >> score;
            ratingMgr.addRating(Rating(uid, mid, score));
            cout << "Rating added!" << endl;
        }
        else if (choice == 6) {
            ratingMgr.printAll();
        }
        else if (choice == 7) {
            int uid, k, n;
            cout << "User ID: "; cin >> uid;
            cout << "K (similar users): "; cin >> k;
            cout << "N (recommendations): "; cin >> n;
            vector<int> result = recommender.recommend(uid, k, n);
            if (result.empty()) {
                cout << "No recommendations available." << endl;
            } else {
                cout << "\n=== Recommended Movies ===" << endl;
                for (int i = 0; i < (int)result.size(); i++) {
                    Movie* m = movieMgr.findById(result[i]);
                    if (m)
                        cout << i+1 << ". " << m->getTitle()
                             << " [" << m->getGenre() << "]"
                             << " Rating: " << m->getRating() << endl;
                    else
                        cout << i+1 << ". Movie ID: " << result[i] << endl;
                }
            }
        }
        else if (choice == 8) {
            string genre;
            cout << "Genre (SF/액션/드라마/로맨스): "; 
            cin >> genre;
            vector<Movie> result = movieMgr.filterByGenre(genre);
            if (result.empty()) {
                cout << "No movies found for genre: " << genre << endl;
            } else {
                cout << "\n=== " << genre << " Movies ===" << endl;
                for (int i = 0; i < (int)result.size(); i++)
                    cout << i+1 << ". " << result[i].getTitle()
                         << " Rating: " << result[i].getRating() << endl;
            }
        }
        else if (choice == 9) {
            int statChoice;
            cout << "\n=== Statistics ===" << endl;
            cout << "1. Average Rating" << endl;
            cout << "2. Average Rating by Genre" << endl;
            cout << "3. Top 5 Movies" << endl;
            cout << "Choice: ";
            cin >> statChoice;
            try {
                if (statChoice == 1) {
                    cout << "Average Rating: " << movieMgr.getAverageRating() << endl;
                }
                else if (statChoice == 2) {
                    auto avg = movieMgr.getAverageRatingByGenre();
                    cout << "\n=== Average Rating by Genre ===" << endl;
                    for (const auto& [genre, rating] : avg)
                        cout << genre << ": " << rating << endl;
                }
                else if (statChoice == 3) {
                    auto top = movieMgr.getTopN(5);
                    cout << "\n=== Top 5 Movies ===" << endl;
                    for (int i = 0; i < (int)top.size(); i++)
                        cout << i+1 << ". " << top[i].getTitle()
                             << " Rating: " << top[i].getRating() << endl;
                }
            } catch (const exception& e) {
                cerr << "Error: " << e.what() << endl;
            }
        }
        else {
            cout << "Invalid choice." << endl;
        }
    }
    return 0;
}
