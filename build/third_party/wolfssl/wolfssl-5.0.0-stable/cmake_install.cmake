# Install script for directory: /Users/name1e5s/Documents/Code/TiandiEBank/backend/third_party/wolfssl/wolfssl-5.0.0-stable

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/name1e5s/Documents/Code/TiandiEBank/backend/build/third_party/wolfssl/wolfssl-5.0.0-stable/libwolfssl.a")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libwolfssl.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libwolfssl.a")
    execute_process(COMMAND "/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libwolfssl.a")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/wolfssl" TYPE DIRECTORY FILES "/Users/name1e5s/Documents/Code/TiandiEBank/backend/third_party/wolfssl/wolfssl-5.0.0-stable/wolfssl/" FILES_MATCHING REGEX "/[^/]*\\.h$" REGEX "(internal|    options|    pic32mz-crypt|    ti-hash|    ti-ccm|    nrf51|    ksdk_port|    dcp_port|    xil-sha3|    caam_driver|    wolfcaam|    wolfcaam_sha|    stm32|    stsafe|    esp32-cry|    cryptocell|    renesas-tsip-crypt|    psoc6_crypto).h" EXCLUDE)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/wolfssl/example" TYPE FILE FILES
    "/Users/name1e5s/Documents/Code/TiandiEBank/backend/third_party/wolfssl/wolfssl-5.0.0-stable/examples/echoserver/echoserver.c"
    "/Users/name1e5s/Documents/Code/TiandiEBank/backend/third_party/wolfssl/wolfssl-5.0.0-stable/examples/sctp/sctp-server.c"
    "/Users/name1e5s/Documents/Code/TiandiEBank/backend/third_party/wolfssl/wolfssl-5.0.0-stable/examples/sctp/sctp-client-dtls.c"
    "/Users/name1e5s/Documents/Code/TiandiEBank/backend/third_party/wolfssl/wolfssl-5.0.0-stable/examples/sctp/sctp-client.c"
    "/Users/name1e5s/Documents/Code/TiandiEBank/backend/third_party/wolfssl/wolfssl-5.0.0-stable/examples/sctp/sctp-server-dtls.c"
    "/Users/name1e5s/Documents/Code/TiandiEBank/backend/third_party/wolfssl/wolfssl-5.0.0-stable/examples/echoclient/echoclient.c"
    "/Users/name1e5s/Documents/Code/TiandiEBank/backend/third_party/wolfssl/wolfssl-5.0.0-stable/examples/server/server.c"
    "/Users/name1e5s/Documents/Code/TiandiEBank/backend/third_party/wolfssl/wolfssl-5.0.0-stable/examples/benchmark/tls_bench.c"
    "/Users/name1e5s/Documents/Code/TiandiEBank/backend/third_party/wolfssl/wolfssl-5.0.0-stable/examples/client/client.c"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/wolfssl/wolfssl" TYPE FILE FILES
    "/Users/name1e5s/Documents/Code/TiandiEBank/backend/third_party/wolfssl/wolfssl-5.0.0-stable/doc/README.txt"
    "/Users/name1e5s/Documents/Code/TiandiEBank/backend/third_party/wolfssl/wolfssl-5.0.0-stable/certs/taoCert.txt"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/wolfssl/wolfssl-config.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/wolfssl/wolfssl-config.cmake"
         "/Users/name1e5s/Documents/Code/TiandiEBank/backend/build/third_party/wolfssl/wolfssl-5.0.0-stable/CMakeFiles/Export/lib/cmake/wolfssl/wolfssl-config.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/wolfssl/wolfssl-config-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/wolfssl/wolfssl-config.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/wolfssl" TYPE FILE FILES "/Users/name1e5s/Documents/Code/TiandiEBank/backend/build/third_party/wolfssl/wolfssl-5.0.0-stable/CMakeFiles/Export/lib/cmake/wolfssl/wolfssl-config.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/wolfssl" TYPE FILE FILES "/Users/name1e5s/Documents/Code/TiandiEBank/backend/build/third_party/wolfssl/wolfssl-5.0.0-stable/CMakeFiles/Export/lib/cmake/wolfssl/wolfssl-config-debug.cmake")
  endif()
endif()

