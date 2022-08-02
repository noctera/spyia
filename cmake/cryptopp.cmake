project(cryptopp-git NONE)

include(FetchContent)
FetchContent_Declare(
    cryptopp
    GIT_REPOSITORY https://github.com/weidai11/cryptopp.git
)

FetchContent_MakeAvailable(cryptopp)