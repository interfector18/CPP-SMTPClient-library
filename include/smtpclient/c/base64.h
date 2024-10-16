#ifndef SMTPCLIENT_C_BASE64_H
#define SMTPCLIENT_C_BASE64_H

#include <string>

namespace jed_utils {
class Base64 {
 public:
    static std::string Encode(unsigned char const *bytes_to_encode, size_t in_len);
    static std::string Decode(std::string const &encoded_string);
};
}  // namespace jed_utils

#endif
