#include <service/account.h>
#include <db/account.h>

#include <jwt-cpp/jwt.h>

namespace service
{
    namespace account
    {
        int create_account(const std::string &first_name, const std::string &last_name, const std::string &phone, const std::string &password)
        {
            return db::account::create_account(first_name, last_name, phone, password);
        }

        std::optional<std::string> login_account(int id, const std::string &password)
        {
            auto account_opt = db::account::get_account(id);
            if (!account_opt)
            {
                return std::nullopt;
            }
            auto account = account_opt.value();
            if (account.password != password)
            {
                return std::nullopt;
            }

            auto token = jwt::create()
                             .set_issuer("tiandi")
                             .set_issued_at(std::chrono::system_clock::now())
                             .set_expires_at(std::chrono::system_clock::now() + std::chrono::seconds{3600})
                             .set_payload_claim("id", picojson::value(int64_t{id}))
                             .sign(jwt::algorithm::hs256{account.password});
            return token;
        }

        std::optional<entity::BankAccount> get_account(int id)
        {
            return db::account::get_account(id);
        }

        std::optional<int> extract_id(const std::string &token)
        {
            try
            {
                auto decoded = jwt::decode(token);
                auto id = decoded.get_payload_claims()["id"].as_int();
                auto account_opt = db::account::get_account(id);
                if (!account_opt.has_value())
                {
                    return std::nullopt;
                }
                auto account = account_opt.value();

                auto verifier = jwt::verify()
                                    .allow_algorithm(jwt::algorithm::hs256{account.password})
                                    .with_issuer("tiandi");
                verifier.verify(decoded);
                return id;
            }
            catch (std::exception &e)
            {
                return std::nullopt;
            }
        }

        std::optional<std::string> update_account_info(int id, const std::optional<std::string> &first_name, const std::optional<std::string> &last_name, const std::optional<std::string> &phone, const std::optional<std::string> &password)
        {
            auto account_opt = db::account::get_account(id);
            if (!account_opt.has_value())
            {
                return std::nullopt;
            }
            auto account = account_opt.value();
            if (first_name.has_value())
            {
                account.first_name = first_name.value();
            }
            if (last_name.has_value())
            {
                account.last_name = last_name.value();
            }
            if (phone.has_value())
            {
                account.phone = phone.value();
            }
            if (password.has_value())
            {
                account.password = password.value();
            }
            db::account::update_account(account);
            if (password.has_value())
            {
                auto token = jwt::create()
                                 .set_issuer("tiandi")
                                 .set_issued_at(std::chrono::system_clock::now())
                                 .set_expires_at(std::chrono::system_clock::now() + std::chrono::seconds{3600})
                                 .set_payload_claim("id", picojson::value(int64_t{id}))
                                 .sign(jwt::algorithm::hs256{account.password});
                return token;
            }
            return std::nullopt;
        }

        void delete_account(int id)
        {
            db::account::delete_account(id);
        }
    }
}