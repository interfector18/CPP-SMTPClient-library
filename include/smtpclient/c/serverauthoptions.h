#ifndef SMTPCLIENT_C_SERVERAUTHOPTIONS_H
#define SMTPCLIENT_C_SERVERAUTHOPTIONS_H

namespace jed_utils {
struct ServerAuthOptions {
    bool Plain = false;
    bool Login = false;
    bool XOAuth2 = false;
    bool Plain_ClientToken = false;
    bool OAuthBearer = false;
    bool XOAuth = false;
};
}  // namespace jed_utils

#endif
