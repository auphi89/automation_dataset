/* CBOM source fixture: OpenSSL EVP, legacy digests, RSA keygen and a TLS client context. */
#include <openssl/evp.h>
#include <openssl/md5.h>
#include <openssl/rsa.h>
#include <openssl/sha.h>
#include <openssl/ssl.h>
#include "openssl_flags.h"

int encrypt_aes_gcm(const unsigned char *key, const unsigned char *iv) {
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    return EVP_EncryptInit_ex(ctx, EVP_aes_256_gcm(), NULL, key, iv);
}

int encrypt_des3(const unsigned char *key, const unsigned char *iv) {
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    return EVP_EncryptInit_ex(ctx, EVP_des_ede3_cbc(), NULL, key, iv);
}

void legacy_digests(const unsigned char *data, size_t len, unsigned char *out) {
    MD5(data, len, out);
    SHA1(data, len, out);
    SHA256(data, len, out);
}

RSA *make_rsa_1024(void) {
    RSA *rsa = RSA_new();
    BIGNUM *e = BN_new();
    BN_set_word(e, RSA_F4);
    RSA_generate_key_ex(rsa, 1024, e, NULL);
    return rsa;
}

SSL_CTX *make_client(void) {
    SSL_CTX *ctx = SSL_CTX_new(TLS_client_method());
    SSL_CTX_set_min_proto_version(ctx, TLS1_VERSION);
    SSL_CTX_set_cipher_list(ctx, "ECDHE-RSA-AES256-GCM-SHA384:DES-CBC3-SHA");
    return ctx;
}
