#include "sha256.h"

int main()
{
    static unsigned char passwd[] = { 'p', 'a', 's', 's', 'w', 'o', 'r', 'd' };
    static unsigned char salt[] =
        { 'f', 'o', 'o', '@', 'e', 'x', 'a', 'm', 'p', 'l', 'e', '.', 'o', 'r', 'g' };
    static unsigned char saltAuth[] =
        { 'i', 'd', 'e', 'n', 't', 'i', 't', 'y', '.', 'm', 'o', 'z', 'i', 'l', 'l', 'a', '.', 'c', 'o', 'm', '/', 'g', 'o', 'm', 'b', 'o', 't', '/', 'v', '1', '/', 'a', 'u', 't', 'h', 'e', 'n', 't', 'i', 'c', 'a', 't', 'i', 'o', 'n',  };
    static unsigned char saltCrypt[] =
        { 'i', 'd', 'e', 'n', 't', 'i', 't', 'y', '.', 'm', 'o', 'z', 'i', 'l', 'l', 'a', '.', 'c', 'o', 'm', '/', 'g', 'o', 'm', 'b', 'o', 't', '/', 'v', '1', '/', 'e', 'n', 'c', 'r', 'y', 'p', 't', 'i', 'o', 'n',  };

    unsigned char dkey[32];
    unsigned char akey[32];
    unsigned char ckey[32];
    int i;

    s_PBKDF2_SHA256(passwd, sizeof(passwd), salt, sizeof(salt), 250000, dkey, sizeof(dkey));
    s_PBKDF2_SHA256(dkey, sizeof(dkey), saltAuth, sizeof(saltAuth), 1, akey, sizeof(akey));
    s_PBKDF2_SHA256(dkey, sizeof(dkey), saltCrypt, sizeof(saltCrypt), 1, ckey, sizeof(ckey));

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
