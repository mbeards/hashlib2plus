/* 
 * hashlib++ - a simple hash library for C++
 * 
 * Copyright (c) 2007 Benjamin Grüdelbach
 * 
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 
 * 	1)     Redistributions of source code must retain the above copyright
 * 	       notice, this list of conditions and the following disclaimer.
 * 
 * 	2)     Redistributions in binary form must reproduce the above copyright
 * 	       notice, this list of conditions and the following disclaimer in
 * 	       the documentation and/or other materials provided with the
 * 	       distribution.
 * 	     
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

//---------------------------------------------------------------------- 

/*
 * This is a short example program which shows how to use hashlib++.
 * It produces hashes for a given string or file.
 *
 * THIS PROGRAMM IS JUST AN EXAMPLE HOW TO USE HASHLIB++ AND
 * NO FULL IMPLEMENTED SOFTWARE!
 *
 * usage:
 *
 * [-s string] [-f filename]       
 *
 * Benjamin Grüdelbach
 * 
 * Di 18 Sep 2007
 */


//---------------------------------------------------------------------- 
//hashlib++ includes
#include "sha1wrapper.h"
#include "md5wrapper.h"
#include "hashwrapper.h"

//----------------------------------------------------------------------	
//misc. includes
#include <iostream>
#include <string>

//----------------------------------------------------------------------	
//prototypes
void printUsage (void);

//----------------------------------------------------------------------	

int main ( int argc, char **argv)
{
	bool bCreateFromText = false;
	bool bCreateFromFile = false;
	std::string strInput = "";

	/*
	 * just parse the cmdline
	 */
	for( int i = 1; i < argc ; i++ )
	{
		if( strcmp(argv[i],"-s") == 0 )
		{
			bCreateFromText = true;	
			if( i != argc-1 )
			{
				strInput = argv[i+1];
				break;
			}
		}
		else if( strcmp(argv[i],"-f") == 0 )
		{
			bCreateFromFile = true;	
			if( i != argc-1 )
			{
				strInput = argv[i+1];
				break;
			}
		}
	}

	/*
	 * just print out some little help
	 * if no options have been submited
	 */
	if( (bCreateFromText == false) &&
	    (bCreateFromFile == false) )
	{
		printUsage();
		exit(0);
	}
	
        //--------------------------------------------------------------
	

	/*
	 * We create two wrappers. One for
	 * creating a MD5-hash and the other
	 * one for SHA1
	 */
	hashwrapper *md5 = new md5wrapper();
	hashwrapper *sha1 = new sha1wrapper();

	/*
	 * these two strings will hold our hashes
	 */
	std::string sMD5 = "";
	std::string sSHA1 = "";

	std::cout << "Your hash ";

	if( bCreateFromText )
	{
		std::cout << "for input \""; 

		/*
		 * producing hashes from the given string
		 */
		sMD5 = md5->getHashFromString(strInput);
		sSHA1 = sha1->getHashFromString(strInput);
	}
	else if( bCreateFromFile )
	{
		std::cout << "for file \""; 

		/*
		 * producing hashes from the given file
		 */
		sMD5 = md5->getHashFromFile(strInput);
		sSHA1 = sha1->getHashFromFile(strInput);
	}

	/*
	 * output
	 */
	std::cout << strInput << "\"" << std::endl;
	std::cout << sMD5 << "(MD5)" << std::endl;
	std::cout << sSHA1 << "(SHA1)" << std::endl;

	delete md5;
	delete sha1;

	return 0;
}

//----------------------------------------------------------------------	

void printUsage (void)
{
	std::cout << std::endl;
	std::cout << "hashlib++ example program." << std::endl;
	std::cout << "This software produces MD5 and SHA1 " << std::endl;
	std::cout << "hashes from a given string or file." << std::endl;
	std::cout << std::endl;
	std::cout << "usage: " << std::endl;
	std::cout << "[-s string] [-f filename]" << std::endl;
	std::cout << std::endl;
}

//----------------------------------------------------------------------	
//EOF
