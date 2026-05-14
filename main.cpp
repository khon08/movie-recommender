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
        if (choice == 1) {
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
                cout << "Recommended Movie IDs: ";
                for (int id : result)
                    cout << id << " ";
                cout << endl;
            }
        }
        else {
            cout << "Invalid choice." << endl;
        }
    }
    return 0;
}
