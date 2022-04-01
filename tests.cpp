#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"

// add your tests here

TEST_CASE("Basic Caesar Encryption"){
    CHECK(encryptCaesar("Way to Go!", 5) == "Bfd yt Lt!");
    CHECK(encryptCaesar("Way to Go!", 5) == "Bfd yt Lt!");
}
TEST_CASE("Solve + Distance Formula"){
   CHECK(encryptCaesar("Way to Go!", 5) == "Bfd yt Lt!");
    CHECK(encryptCaesar("Way to Go!", 5) == "Bfd yt Lt!");
  CHECK(encryptCaesar("Way to Go!", 5) == "Bfd yt Lt!");
    CHECK(encryptCaesar("Way to Go!", 5) == "Bfd yt Lt!");
}