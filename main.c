#include "sha256.h"
#include <string.h>
#include <stdio.h>

int main()
{
    static unsigned const char * passwd = "password";
    static unsigned const char * salt = "identity.mozilla.com/gombot/v1/derivation:foo@example.org";
    static unsigned const char * saltAuth = "identity.mozilla.com/gombot/v1/authentication";
    static unsigned const char * saltCrypt = "identity.mozilla.com/gombot/v1/encryption";

    unsigned char dkey[32];
    unsigned char akey[32];
    unsigned char ckey[32];
    int i;

    s_PBKDF2_SHA256(passwd, strlen(passwd), salt, strlen(salt), 250000, dkey, sizeof(dkey));
    s_PBKDF2_SHA256(dkey, sizeof(dkey), saltAuth, strlen(saltAuth), 1, akey, sizeof(akey));
    s_PBKDF2_SHA256(dkey, sizeof(dkey), saltCrypt, strlen(saltCrypt), 1, ckey, sizeof(ckey));

    printf("authKey: ");
    for (i=0; i<sizeof(akey); i++) {
        printf("%02x", akey[i]);
    }
    printf("\n");

    printf("cryptKey: ");
    for (i=0; i<sizeof(ckey); i++) {
        printf("%02x", ckey[i]);
    }
    printf("\n");

    return 0;
}
