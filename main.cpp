#include <iostream>
#include <vector>
#include "Movie.h"
#include "User.h"
#include "Rating.h"

using namespace std;

int main() {
    vector<Movie> movies;
    vector<User> users;
    vector<Rating> ratings;

    int choice;

    while (true) {
        cout << "\n=== Movie Recommender ===\n";
        cout << "1. Add Movie\n";
        cout << "2. Show All Movies\n";
        cout << "3. Add User\n";
        cout << "4. Show All Users\n";
        cout << "5. Add Rating\n";
        cout << "6. Show All Ratings\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 0) {
            cout << "Program ended.\n";
            break;
        }

        if (choice == 1) {
            int id;
            string title, genre;
            float rating;

            cout << "Movie ID: ";
            cin >> id;
            cin.ignore();

            cout << "Title: ";
            getline(cin, title);

            cout << "Genre: ";
            getline(cin, genre);

            cout << "Rating: ";
            cin >> rating;

            movies.push_back(Movie(id, title, genre, rating));
            cout << "Movie added successfully.\n";
        }

        else if (choice == 2) {
            for (const auto& movie : movies) {
                cout << movie << endl;
            }
        }

        else if (choice == 3) {
            int id;
            string name;

            cout << "User ID: ";
            cin >> id;
            cin.ignore();

            cout << "Name: ";
            getline(cin, name);

            users.push_back(User(id, name));
            cout << "User added successfully.\n";
        }

        else if (choice == 4) {
            for (const auto& user : users) {
                cout << user << endl;
            }
        }

        else if (choice == 5) {
            int userId, movieId;
            float score;

            cout << "User ID: ";
            cin >> userId;

            cout << "Movie ID: ";
            cin >> movieId;

            cout << "Score: ";
            cin >> score;

            ratings.push_back(Rating(userId, movieId, score));
            cout << "Rating added successfully.\n";
        }

        else if (choice == 6) {
            for (const auto& rating : ratings) {
                cout << rating << endl;
            }
        }

        else {
            cout << "Invalid choice.\n";
        }
    }

    return 0;
}