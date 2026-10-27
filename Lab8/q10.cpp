#include <iostream>
#include <iomanip>
using namespace std;

class Recommender {
public:
    virtual ~Recommender() {}
    virtual double generateRecommendation(int userRating, int popularity) const {
        return 0.0;
    }
};

class PersonalizedRecommender : public Recommender {
public:
    double generateRecommendation(int userRating, int popularity) const override {
        return 0.7 * userRating + 0.3 * popularity;
    }
};

class TrendingRecommender : public Recommender {
public:
    double generateRecommendation(int userRating, int popularity) const override {
        return 0.3 * userRating + 0.7 * popularity;
    }
};

int main() {
    int rating, popularity;
    cout << "Enter user rating (0-100): ";
    cin >> rating;
    cout << "Enter popularity (0-100): ";
    cin >> popularity;
    if (!cin || rating < 0 || rating > 100 || popularity < 0 || popularity > 100) {
        cout << "Invalid input. Both values must be between 0 and 100.\n";
        return 1;
    }

    Recommender* r1 = new PersonalizedRecommender();
    Recommender* r2 = new TrendingRecommender();

    cout << fixed << setprecision(2);
    cout << "\nPersonalized recommendation score : " << r1->generateRecommendation(rating, popularity) << endl;
    cout << "Trending recommendation score     : " << r2->generateRecommendation(rating, popularity) << endl;

    delete r1;
    delete r2;
    return 0;
}
