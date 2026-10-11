cmake_minimum_required(VERSION 3.20)
project(mdssc_cbom_cmake_fixture C)

find_package(OpenSSL REQUIRED)
add_executable(tls_client tls_client.c)
target_link_libraries(tls_client PRIVATE OpenSSL::SSL OpenSSL::Crypto)
target_compile_definitions(tls_client PRIVATE OPENSSL_NO_MD5)
