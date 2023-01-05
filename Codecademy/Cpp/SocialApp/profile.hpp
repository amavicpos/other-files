#include <iostream>
#include <vector>

using namespace std;

class Profile {
private:
  string name;
  int age;
  string city;
  string country;
  string pronouns;
  vector<string> hobbies;
public:
  Profile(string new_name, int new_age, string new_city, string new_country, string new_pronouns = "they/them") {
    name = new_name;
    age = new_age;
    city = new_city;
    country = new_country;
    pronouns = new_pronouns;
  }
  string view_profile();
  void add_hobby(string new_hobby);
};
