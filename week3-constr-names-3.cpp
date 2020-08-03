#include <algorithm>
#include <map>
#include <vector>
#include <string>

using namespace std;

vector<string> FindNamesHistory(const map<int, string>& names_by_year,
   int year) {
   vector<string> names;
   for (const auto& item : names_by_year) {
      if (item.first <= year && (names.empty() || names.back() != item.second)) {
         names.push_back(item.second);
      }
   }
   return names;
}

string BuildJoinedName(vector<string> names) {
   reverse(begin(names), end(names));
   string joined_name = names[0];
   for (int i = 1; i < names.size(); ++i) {
      if (i == 1) {
         joined_name += " (";
      }
      else {
         joined_name += ", ";
      }
      joined_name += names[i];
   }
   if (names.size() > 1) {
      joined_name += ")";
   }
   return joined_name;
}


class Person {
public:
   Person(const string a, const string& b, int year) {
      year_b = year;
      first_names[year_b] = a;
      last_names[year_b] = b;
   }
   void ChangeFirstName(int year, const string& first_name) {
      if (year >= year_b) {
         first_names[year] = first_name;
      }
   }
   void ChangeLastName(int year, const string& last_name) {
      if (year >= year_b) {
         last_names[year] = last_name;
      }
   }

   string GetFullName(int year) const {
      if (year < year_b) {
         return "No person";
      }
      const vector<string> first_name = FindFirstNamesHistory(year);
      const vector<string> last_name = FindLastNamesHistory(year);
      return first_name.back() + " " + last_name.back();
   }

   string GetFullNameWithHistory(int year) const {
      if (year < year_b) {
         return "No person";
      }
      const string first_name = BuildJoinedName(FindFirstNamesHistory(year));
      const string last_name = BuildJoinedName(FindLastNamesHistory(year));
      return first_name + " " + last_name;
   }

private:
   vector<string> FindFirstNamesHistory(int year) const {
      return FindNamesHistory(first_names, year);
   }
   vector<string> FindLastNamesHistory(int year) const {
      return FindNamesHistory(last_names, year);
   }

   int year_b = 0;
   map<int, string> first_names;
   map<int, string> last_names;
};