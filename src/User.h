#ifndef USER_H
#define USER_H

#include <string>

class User {
public:
    User(const std::string& username, const std::string& password);

    // Getters
    std::string getUsername() const;
    std::string getPassword() const;

    // Setter
    void setPassword(const std::string& newPassword);

private:
    std::string username;
    std::string password;
};

#endif // USER_H