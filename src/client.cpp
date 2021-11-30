#include <iostream>
#include <vector>
#include <tuple>
#include <optional>
#include <httplib.h>
#include <nlohmann/json.hpp>

httplib::Client client("http://localhost:1234");
std::string token;

void print_options(std::vector<std::tuple<std::string, std::function<void(void)>>> options) {
    while (true) {
        for (int i = 0; i < options.size(); i++) {
            std::cout << i + 1 << ": " << std::get<0>(options[i]) << std::endl;
        }
        std::cout << "Please select an option, 0 to return to last index: ";
        int option;
        std::cin >> option;
        if (option < 0 || option > options.size()) {
            std::cout << "Invalid option.\n";
            continue;
        }
        if (option == 0) {
            return;
        }
        std::get<1>(options[option - 1])();
    }
}

void get_account_info() {
    auto res = client.Get("/account/info");
    if (res->status == 200) {
        nlohmann::json json = nlohmann::json::parse(res->body);
        std::cout << "Account info: " << std::endl;
        std::cout << "id: " << json["id"] << std::endl;
        std::cout << "first_name: " << json["first_name"] << std::endl;
        std::cout << "last_name: " << json["last_name"] << std::endl;
        std::cout << "phone: " << json["phone"] << std::endl;
        std::cout << "balance: " << json["balance"] << std::endl;
    } else {
        std::cout << "Failed to get account info.\n";
    }
}

void update_account_info() {
    std::cout << "Please enter the new first name(q to skip): ";
    std::string first_name;
    std::cin >> first_name;
    if (first_name == "q") {
        first_name = "";
    }
    std::cout << "Please enter the new last name(q to skip): ";
    std::string last_name;
    std::cin >> last_name;
    if (last_name == "q") {
        last_name = "";
    }
    std::cout << "Please enter the new phone(q to skip): ";
    std::string phone;
    std::cin >> phone;
    if (phone == "q") {
        phone = "";
    }
    std::cout << "Please enter the new password(q to skip): ";
    std::string password;
    std::cin >> password;
    if (password == "q") {
        password = "";
    }
    httplib::Params params;
    params.emplace("first_name", first_name);
    params.emplace("last_name", last_name);
    params.emplace("phone", phone);
    params.emplace("password", password);
    auto res = client.Post("/account/update", params);
    if (res->status == 200) {
        std::cout << "Successfully updated account info.\n";
        if (password != "") {
            token = res->body;
            client.set_default_headers({{"token", token}});
        }
    } else {
        std::cout << "Failed to update account info.\n";
        std::cout << res->body << std::endl;
    }
}

void delete_account() {
    std::cout << "Confirm to delete account?(y/n): ";
    std::string confirm;
    std::cin >> confirm;
    if (confirm == "y") {
        auto res = client.Post("/account/delete");
        if (res->status == 200) {
            std::cout << "Successfully deleted account.\n";
            token = "";
            client.set_default_headers({{"token", token}});
        } else {
            std::cout << "Failed to delete account.\n";
        }
    }
    exit(0);
}

void deposit() {
    std::cout << "Please enter the amount to deposit: ";
    unsigned int amount;
    std::cin >> amount;
    auto res = client.Post("/transaction/deposit", "{\"amount\":" + std::to_string(amount) + "}", "application/json");
    if (res->status == 200) {
        std::cout << "Successfully deposited " << amount << ".\n";
        std::cout << "New balance: " << res->body << std::endl;
    } else {
        std::cout << "Failed to deposit " << amount << ".\n";
        std::cout << res->body << std::endl;
    }
}

void withdraw() {
    std::cout << "Please enter the amount to withdraw: ";
    unsigned int amount;
    std::cin >> amount;
    httplib::Params params;
    auto res = client.Post("/transaction/withdraw", "{\"amount\":" + std::to_string(amount) + "}", "application/json");
    if (res->status == 200) {
        std::cout << "Successfully withdrew " << amount << ".\n";
        std::cout << "New balance: " << res->body << std::endl;
    } else {
        std::cout << "Failed to withdraw " << amount << ".\n";
        std::cout << res->body << std::endl;
    }
}

void transfer() {
    std::cout << "Please enter the amount to transfer: ";
    unsigned int amount;
    std::cin >> amount;
    std::cout << "Please enter the receiver's account id: ";
    int receiver_id;
    std::cin >> receiver_id;
    std::cout << "Please enter the description: ";
    std::string description;
    std::cin >> description;
    httplib::Params params;
    auto res = client.Post("/transaction/transfer", "{\"amount\":" + std::to_string(amount) + ",\"to_id\":" + std::to_string(receiver_id) + ",\"description\":\"" + description + "\"}", "application/json");
    if (res->status == 200) {
        std::cout << "Successfully transferred " << amount << ".\n";
        std::cout << "New balance: " << res->body << std::endl;
    } else {
        std::cout << "Failed to transfer " << amount << ".\n";
        std::cout << res->body << std::endl;
    }
}

void get_transactions() {
    auto res = client.Get("/transaction/list");
    if (res->status == 200) {
        nlohmann::json json = nlohmann::json::parse(res->body);
        std::cout << "Transactions: " << std::endl;
        for (auto &transaction : json) {
            std::cout << "id: " << transaction["id"] << std::endl;
            std::cout << "amount: " << transaction["amount"] << std::endl;
            std::cout << "from_account_id: " << transaction["from_account_id"] << std::endl;
            std::cout << "to_account_id: " << transaction["to_account_id"] << std::endl;
            std::cout << "description: " << transaction["description"] << std::endl;
            std::cout << "----------------------------------------" << std::endl;
        }
    } else {
        std::cout << "Failed to get transactions.\n";
    }
}

void print_menu() {
    print_options({
        {"Get account info", get_account_info},
        {"Update account info", update_account_info},
        {"Delete account", delete_account},
        {"Deposit", deposit},
        {"Withdraw", withdraw},
        {"Transfer", transfer},
        {"Get transactions", get_transactions},
        {"Exit", []() { exit(0); }}
    });
}

void login() {
    std::cout << "Login\n";
    std::cout << "UserID: ";
    std::string id;
    std::cin >> id;
    std::cout << "Password: ";
    std::string password;
    std::cin >> password;
    auto res = client.Post("/account/login", "id=" + id + "&password=" + password, "application/x-www-form-urlencoded");
    if (res->status == 200) {
        std::cout << "Login successful.\n";
        token = res->body;
        client.set_default_headers({{"token", token}});
        print_menu();
    } else {
        std::cout << "Login failed.\n";
    }
}

void register_account() {
    std::cout << "Register\n";
    std::cout << "First name: ";
    std::string first_name;
    std::cin >> first_name;
    std::cout << "Last name: ";
    std::string last_name;
    std::cin >> last_name;
    std::cout << "Phone: ";
    std::string phone;
    std::cin >> phone;
    std::cout << "Password: ";
    std::string password;
    std::cin >> password;
    auto res = client.Post("/account/new", "first_name=" + first_name + "&last_name=" + last_name + "&phone=" + phone + "&password=" + password, "application/x-www-form-urlencoded");
    if (res->status == 200) {
        std::cout << "Register successful.\n";
        std::cout << "UserID: " << res->body << "\n";
    } else {
        std::cout << "Register failed.\n";
    }
}

int main()
{
    print_options({
        {"Login", login},
        {"Register", register_account},
    });
    std::cout << "Hello World!\n";
}