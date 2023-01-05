#include "profile.hpp"

string list_to_string(vector<string> list);

string Profile::view_profile() {
  if (hobbies.size() == 0) {
    return "My name is " + name + " and I'm " + to_string(age) + " years old. I live in " + city + ", " + country + ". My pronouns are " + pronouns + ".\n";
  } else {
    return "My name is " + name + " and I'm " + to_string(age) + " years old. I live in " + city + ", " + country + ". My pronouns are " + pronouns + " and I love " + list_to_string(hobbies) + ".\n";
  }
}

void Profile::add_hobby(string new_hobby) {
  hobbies.push_back(new_hobby);
}

string list_to_string(vector<string> list) {
  string result = "";
  for (int i = 0; i < list.size(); ++i) {
    if (i == list.size() - 2) {
      result += list[i] + " and ";
    } else if (i == list.size() - 1) {
      result += list[i];
    } else {
      result += list[i] + ", ";
    }
  }
  return result;
}
