cmake_minimum_required(VERSION 3.19)
project(TiandiEBank)

set(CMAKE_CXX_STANDARD 17)

add_definitions(-DOPENSSL_ALL -DATOMIC_USER -DECC_SHAMIR -DECC_TIMING_RESISTANT -DHAVE_AESGCM -DHAVE_CHACHA -DHAVE_CRL -DHAVE_CRL_MONITOR -DHAVE_DH -DHAVE_DH_DEFAULT_PARAMS -DHAVE_ECC -DHAVE_ENCRYPT_THEN_MAC -DHAVE_EXTENDED_MASTER -DHAVE_FFDHE_2048 -DHAVE_HASHDRBG -DHAVE_HKDF -DHAVE_OCSP -DHAVE_ONE_TIME_AUTH -DHAVE_PK_CALLBACKS -DHAVE_POLY1305 -DHAVE_PTHREAD -DHAVE_SUPPORTED_CURVES -DHAVE_THREAD_LS -DHAVE_TLS_EXTENSIONS -DOPENSSL_EXTRA -DPERSIST_CERT_CACHE -DPERSIST_SESSION_CACHE -DTFM_ECC256 -DTFM_NO_ASM -DTFM_TIMING_RESISTANT -DUSE_FAST_MATH -DWC_NO_ASYNC_THREADING -DWC_RSA_BLINDING -DWC_RSA_PSS -DWOLFSSL_BASE64_ENCODE -DWOLFSSL_DTLS -DWOLFSSL_IGNORE_FILE_WARN -DWOLFSSL_SHA224 -DWOLFSSL_SHA3 -DWOLFSSL_SHA384 -DWOLFSSL_SHA512 -DWOLFSSL_SHAKE256 -DWOLFSSL_TLS13 -DWOLFSSL_X86_64_BUILD -D_POSIX_THREADS)

include_directories(
    third_party/wolfssl/wolfssl-5.0.0-stable/wolfssl
    third_party/wolfssl/wolfssl-5.0.0-stable/
    third_party/jwt-cpp/include
    third_party/cpp-httplib
    third_party/sqlite_orm/
    third_party/sqlite/
)

add_subdirectory(third_party/sqlite)
add_subdirectory(third_party/wolfssl)

add_subdirectory(src)
