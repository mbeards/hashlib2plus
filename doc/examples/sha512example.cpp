#include <hl_hashwrapper.h>
#include <hl_sha512wrapper.h>
#include <string>

/*
 * creating a wrapper object
 */
hashwrapper *myWrapper = new sha512wrapper();

/*
 * create a hash from a string
 */
std::string hash1 = myWrapper->getHashFromString("Hello World");

/*
 * create a hash based on a file
 */
std::string hash2 = myWrapper->getHashFromFile("README.TXT");

delete myWrapper;

