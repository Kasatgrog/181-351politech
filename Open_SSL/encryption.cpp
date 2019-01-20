#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <iostream>
#include <openssl/conf.h> // functions, structures and configurations consts of OpenSSL
#include <openssl/conf.h>
#include <openssl/evp.h> // crypto functions themselves https://wiki.openssl.org/index.php/EVP
#include <openssl/err.h> // inner errors codes of OpenSSL and their decrypt
#include <openssl/aes.h>
#include <fstream>
#include <string>
#include <cstring>

#pragma comment (lib, "ws2_32.LIB")
#pragma comment (lib, "gdi32.LIB")
#pragma comment (lib, "advapi32.LIB")
#pragma comment (lib, "crypt32")
#pragma comment (lib, "user32")
#pragma comment (lib, "wldap32")

//#define BUFLEN 256
// OpenSSL libraries (openssl.org) are connected not explicitly, dynamicly (see lab 10)

using namespace std;

int main()
{
	// woring with cryptofunctions OpenSSL:
	// 1) creating object with settings
	// 2) encryption itself
	// 3) finalization
	// 4) output of encrypted data

	//in literature structures are ussually used only for storing data
	// not a word about methods constr/destr
	struct name_of_my_struct // pretty simmular to class
	{
		name_of_my_struct()
		{

		}

		int a;
		double b;
		int fnc1()
		{
			return a;
		}
	};
	FILE *in, *out, *outd;
	in = fopen("vvod.txt", "rb");
	unsigned char plaintext[256];
	int plaintext_len;// = fread(plaintext, 1, BUFLEN, in); // text length
	unsigned char *key = (unsigned char *)"0123456789"; // password (key)
	unsigned char *iv = (unsigned char *)"0123456789012345"; // initialysing vector, randomizer
	unsigned char cryptedtext[256]; // encrypted result
	unsigned char decryptedtext[256]; // 

	// 1. The pointer on a carrying structure is created
	EVP_CIPHER_CTX *ctx; // structure

	// 2. Empty sructure of settings is created for the pointer (method, key, init vector etc)
	ctx = EVP_CIPHER_CTX_new(); // creating struct with method's settings

	// 3. structure EVP_CIPHER_CTX filled with settings
	EVP_EncryptInit_ex(ctx, // link on obj/struct to where data is pushed
		EVP_aes_256_cbc(), // link an a crypting kernel AES 256 (func with algorythm)
		NULL,
		key, // password
		iv); // randomizer (random starting vector)

	// 4. actual encryption - FUNC EVP_EncryptUpdate
	int len;
	out = fopen("vivod.txt", "wb");
	for (;;)
	{
		plaintext_len = fread(plaintext, 1, 256, in);
		if (plaintext_len <= 0) break;
		if (!EVP_EncryptUpdate(ctx, // obj with settings
			cryptedtext, // out: where will be encrypted data
			&len, // out: encrypted data length
			plaintext, // in: data to be encrypted
			plaintext_len)) return 0; // in: it's length
		fwrite(cryptedtext, 1, len, out);
	}
	int cryptedtext_len = len;

	// 5. finalisation of encryption
	//nessessary if last block of data is not comletely filled
	EVP_EncryptFinal_ex(ctx, cryptedtext, &len);
	cryptedtext_len += len;
	fwrite(cryptedtext, 1, len, out);

	// 6. deleting the structure
	EVP_CIPHER_CTX_free(ctx);
	fclose(in);
	fclose(out);

	// output of encrypted data
	for (int i = 0; i < cryptedtext_len; i++)
	{
		cout << hex << cryptedtext[i];
		if ((i + 1) % 32 == 0) cout << endl;
	}
	cout << endl;

	// decryption

	// 1.
	ctx = EVP_CIPHER_CTX_new(); // conf struct

	// 2.
	EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv); // init with AES key & vector

	// 3.
	out = fopen("vivod.txt", "rb");
	outd = fopen("decrypt.txt", "wb");
	for (;;)
	{
		cryptedtext_len = fread(cryptedtext, 1, 256, out);
		if (cryptedtext_len <= 0) break;
		if (!EVP_DecryptUpdate(ctx, decryptedtext, &len, cryptedtext, cryptedtext_len)) return 0;// decryption
		fwrite(decryptedtext, 1, len, outd);

	}
	// 4.
	int dectypted_len = len;
	EVP_DecryptFinal_ex(ctx, decryptedtext, &len);//+len

	// 5.
	dectypted_len += len;
	EVP_CIPHER_CTX_free(ctx);
	decryptedtext[dectypted_len] = '\0';
	fwrite(decryptedtext, 1, len, outd);

	cout << decryptedtext << endl;
	fclose(out);
	fclose(outd);

	// --- file encryption 
	// simmular, but done by parts in cycle
	//
	/*
		1) opening files and setting OpenSSL conf
		2) reading first block
		3) while(read_data > 0)
		{
			4) data encryption
			5) writing encrypted arr to the file
			6) reading next block
		}
		7) running finalisation
		8) writing final to the file
		9) closing files
	*/
	getchar();
	return 0;
}
