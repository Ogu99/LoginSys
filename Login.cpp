#include <iostream>
#include <list>

using namespace std;

int main() {
  std::list<std::string> list;

  cout << "Weclome to the Login! Please enter your user name and password! \n"
       << "If you don't have an account please consider creating an account! \n"
       << "\n"
       << "Type 'c' for creating and an account \n"
       << "Type 'l' to log in to your account! \n";

  do {
    std::string option;
    cin >> option;

    std::string usr;
    std::string pw;

    if (option == "c") {
      cout << "Type in your username first and then your password: \n";
      cin >> usr >> pw;

      cout << "Confirm? [y/n] \n";
      char confirm;
      cin >> confirm;

      if (confirm == 'y') {
        list.push_back(usr + pw);
        goto CONTINUE;
      } else if (confirm == 'n')
        goto CONTINUE;
      else
        cout << "Invalid option!";

    } else if (option == "l") {
      cout << "Please enter first your username then your password! \n";
      cin >> usr >> pw;

      for (std::string s : list) {
        if (s == usr + pw) {
          cout << "You successfully logged in! Welcome " + usr + "\n";
          goto CONTINUE;
        }
      }

      cout << "Login failed! Invalid username or password!";

    } else if (option == "quit")
      break;
    else
      cout << "You entered an invalid argument! \n";

    CONTINUE:
      cout << "\nChoose an option:\n";
      continue;
  } while (true);
}
