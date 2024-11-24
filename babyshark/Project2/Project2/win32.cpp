#define WIN32_LEAN_AND_MEAN // to exlude some unnecessary windows headers (see windows.h)
// B4BY_Sh4rK_DoOoD0od0od0O_DoOd0O0d00O
#include <windows.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>
#include <wincrypt.h>
#include <string>
#include <vector>
#include <iostream>

#pragma comment(lib,"ws2_32.lib")
#pragma comment(lib, "Crypt32.lib")

HMODULE kernel_32;
HMODULE ws2_32;
HMODULE crypt32;

//LPCSTR Kernel32DLLName = "kernel32.dll";
//LPCSTR WS232DLLName = "ws2_32.dll";

std::vector<unsigned int> kernel32_enc = { 0x3c, 0x00, 0x01, 0x1b, 0x17, 0x02, 0x0a, 0x01, 0x1e, 0x57, 0x5e, 0x08 };
std::vector<unsigned int> ws2_32_enc = { 0x20, 0x16, 0x41, 0x2a, 0x41, 0x5c, 0x17, 0x57, 0x5c, 0x5f };
std::vector<unsigned int> enc1 = { 0x10, 0x00, 0x07, 0x25, 0x00, 0x01, 0x5a, 0x72, 0x54, 0x57, 0x40, 0x01, 0x1d, 0x00};
std::vector<unsigned int> enc2 = { 0x14, 0x17, 0x16, 0x14, 0x06, 0x0b, 0x6d, 0x5b, 0x42, 0x56, 0x53, 0x00};
std::vector<unsigned int> enc3 = { 0x00, 0x36, 0x32, 0x36, 0x1d, 0x00, 0x57, 0x56, 0x53, 0x47, 0x70, 0x1d, 0x20, 0x12, 0x05, 0x03 };
std::vector<unsigned int> enc4 = { 0x00, 0x36, 0x32, 0x26, 0x06, 0x0f, 0x4b, 0x47, 0x45, 0x43 };
std::vector<unsigned int> enc5 = { 0x00, 0x36, 0x32, 0x36, 0x1e, 0x0b, 0x58, 0x5d, 0x45, 0x43 };
std::vector<unsigned int> enc6 = { 0x24, 0x0a, 0x10, 0x1e, 0x17, 0x1a };
std::vector<unsigned int> enc7 = { 0x35, 0x0c, 0x1d, 0x11 };
std::vector<unsigned int> enc8 = { 0x36, 0x06, 0x10, 0x10, 0x02, 0x1a };
std::vector<unsigned int> enc9 = { 0x3b, 0x0c, 0x00, 0x01, 0x17, 0x00 };
std::vector<unsigned int> enc10 = { 0x24, 0x00, 0x1d, 0x11 };

std::string ProcName[10];
std::string ModuleName[2];
// LPCSTR ModuleName[] = { "GetProcAddress", "CreateThread", "WSAConnectByName", "WSAStartup", "WSACleanup", "socket", "bind", "accept", "listen", "send"};

int tinyurllen = 30;
//char tinyurl[] = "https://tinyurl.com/32z5dtmd";
//char mylink[] = "https://ibb.co/jyRWRZG";
std::vector<unsigned int> tinyurl_enc = { 0x08, 0x08, 0x03, 0x15, 0x19, 0x5a, 0x59, 0x5b, 0x1a, 0x18, 0x0d, 0x1c, 0x09, 0x05, 0x09, 0x47, 0x03, 0x1e, 0x18, 0x43, 0x45, 0x53, 0x10, 0x53, 0x1c, 0x12, 0x16, 0x07 };
std::vector<unsigned int> mylink_enc = { 0x08, 0x08, 0x03, 0x15, 0x19, 0x5a, 0x59, 0x5b, 0x07, 0x13, 0x01, 0x4b, 0x1f, 0x18, 0x4a, 0x5d, 0x2a, 0x47, 0x4c, 0x02, 0x00, 0x13 };

char mykey[21] = "dEYDndkIDqEVcdsRBIdb";
std::string mykey2 = "Wesurn93032dnshf";

std::string keys[23] = {
	"ilzufmgz{hkbyx{qcsayim{t{tjiq}",
	"n}|wuvyulmxrxcmsjtr{vrvkfun}ne",
	"|uuffgogjd|loyiwxxneo}{hfhlpih",
	"ywppg{pzvi}uvjsgskqoiukmwq}jpc",
	"pk{ynl}qpxkjlg|arxq}mjgnjj}hgw",
	"iraw{d}ceqkegury{jwjhjfqqiqejh",
	"wlk{ngxsmiu}wgildjavrthoxbwljb",
	"tgqmq}lwczsce}}jtd{xu|ehoppjav",
	"ukjfatygwd}klbwwt|iqvwha{tzl|z",
	"yn{dehnrtrsxtlinneluruojyafujp",
	"dghlk|skireswy{zp}iwewe}srgcw|",
	"uesznjwffdqxzbobhxsqqquerheuhu",
	"ageaefynhavbyw|}{pvbsrxysjyjus",
	"miibyedf}gql{brukols{matzu|gtz",
	"wvznpm}vqrznrvw|{labjdzxkdug|n",
	"lesrrqoumue|w|{}ic|a}wppyoso|m",
	"|ioxsattb{antbl{{zau{dvmrsdvzu",
	"zizuziegsvvemwze||qmhomijiawky",
	"zeilvthmosvoqlkr}i{}jpt{drjaqg",
	"ddemymueqq|gbfxaxaqcuxe{bbjcpi",
	"tuc}fjcjwhntx|iytdyxyvnlo|rkrr",
	"oyptarb{bonrni}qphet|qhmjswrz{",
	"qjqgliriajh|swjh}w{gkrsw{qxvuf"
};

std::string silly_decryption_scheme_2(std::vector<unsigned int> enc) {
	int len = enc.size();
	int num_keys = 23;
	std::string new_str = "";

	int c = 0;
	for (int i = 0; i < len; i++) {
		c = enc[i];
		for (int j = 0; j < num_keys; j++) {
			c ^= keys[j][i];
		}
		new_str += c;
	}
	return new_str;
}

std::string silly_decryption_scheme(std::vector<unsigned int> enc) {
	int len = enc.size();
	std::string new_str = "";

	for (int i = 0; i < len; i++) {
		char c = enc[i] ^ mykey2[i];
		new_str += c;
	}
	return new_str;
}

DWORD DOoDoOooDoOoDoOo(LPVOID lpdwThreadParam) {
	kernel_32 = GetModuleHandleA(ModuleName[0].c_str());
	auto get_proc_addr = (FARPROC (WINAPI*)(HMODULE, LPCSTR)) GetProcAddress(kernel_32, ProcName[0].c_str());
	ws2_32 = GetModuleHandleA(ModuleName[1].c_str());
	auto wsa_startup = (int (WINAPI*)(WORD, LPWSADATA)) get_proc_addr(ws2_32, ProcName[3].c_str());
	auto wsa_cleanup = (int (WINAPI*)()) get_proc_addr(ws2_32, ProcName[4].c_str());
	auto my_socket = (SOCKET (WINAPI*)(int, int, int)) get_proc_addr(ws2_32, ProcName[5].c_str());
	auto my_bind = (int (WINAPI *)(SOCKET, const sockaddr*, int)) get_proc_addr(ws2_32, ProcName[6].c_str());
	auto my_accept = (SOCKET(WINAPI*)(SOCKET, sockaddr*, int*)) get_proc_addr(ws2_32, ProcName[7].c_str());
	auto my_listen = (int (WINAPI *)(SOCKET, int)) get_proc_addr(ws2_32, ProcName[8].c_str());
	auto my_send = (int(WINAPI*)(SOCKET, const char*, int, int)) get_proc_addr(ws2_32, ProcName[8].c_str());

	//printf("[*] DOoDoOooDoOoDoOo\n\n");

	struct addrinfo* result = NULL;
	struct addrinfo hints;
	int iResult;
	int iSendResult;

	SOCKET ListenSocket = INVALID_SOCKET;
	SOCKET ClientSocket = INVALID_SOCKET;

	ZeroMemory(&hints, sizeof(hints));

	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;
	hints.ai_flags = AI_PASSIVE;

	WSAData wsaData;

	if (wsa_startup(MAKEWORD(2, 2), &wsaData)) {
		//printf("[*] Failed to startup WSA\n\n");
		return 1;
	}

	iResult = getaddrinfo(NULL, "12345", &hints, &result);

	// Create a SOCKET for the server to listen for client connections.
	ListenSocket = my_socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	if (ListenSocket == INVALID_SOCKET) {
		//printf("[*] Invalid Socket!\n\n");
	}
	else {
		//printf("[*] Created a listen socket\n\n");
	}

	char recvbuf[21];
	int recvbuflen = 21;

	iResult = my_bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
	if (iResult == SOCKET_ERROR) {
		//printf("[*] Error binding socket!\n\n");
		return 1;
	} else {
		//printf("[*] Successful bind\n\n");
	}

	iResult = listen(ListenSocket, SOMAXCONN);
	if (iResult == SOCKET_ERROR) {
		//printf("[*] Error listening to socket!\n\n");
		wsa_cleanup();
		return 1;
	} else {
		//printf("[*] Listening on port 12345\n\n");
	}

	ClientSocket = my_accept(ListenSocket, NULL, NULL);
	if (ClientSocket == INVALID_SOCKET) {
		//printf("[*] Invalid Client Socket\n\n");
		wsa_cleanup();
	} else {
		//printf("[*] Successful connection!\n\n");
	}

	//printf("[*] Accepted a client connection\n\n");

	do {
		ZeroMemory(recvbuf, recvbuflen);
		iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
		//printf("[*] Some payload was received!\n\n");
		int len = 0;
		for (int i = 0; i < recvbuflen; i++) {
			if (recvbuf[i]) {
				len++;
			}
		}
		//printf("[*] Received payload length: %d\n\n", len);
		if (len != 20) {
			//printf("[*] Length is not 20!\n\n");
			std::string payload = silly_decryption_scheme_2(tinyurl_enc);
			int len = payload.size();
			iSendResult = send(ClientSocket, payload.c_str(), len, 0);
		}
		else {
			bool success = true;
			for (int i = 0; i < len; i++) {
				//printf("[*] Key compare\n\n");
				if (recvbuf[i] != mykey[i])
				{
					//printf("[*] Wrong!\n\n");
					success = false;
				}
			}
			//printf("[*] You got my key!\n\n");
			if (success) {
				//printf("[*] Success!\n\n");
				std::string payload = silly_decryption_scheme_2(mylink_enc);
				int len = payload.size();
				iSendResult = send(ClientSocket, payload.c_str(), len, 0);
			}
			else {
				std::string payload = silly_decryption_scheme_2(tinyurl_enc);
				int len = payload.size();
				iSendResult = send(ClientSocket, payload.c_str(), len, 0);
			}
		}
	} while (iResult > 0);
	
	closesocket(ClientSocket);
	wsa_cleanup();

	return 0;
}

int main(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {

	DWORD tid;	

	ProcName[0] = silly_decryption_scheme(enc1);
	ProcName[1] = silly_decryption_scheme(enc2);
	ProcName[2] = silly_decryption_scheme(enc3);
	ProcName[3] = silly_decryption_scheme(enc4);
	ProcName[4] = silly_decryption_scheme(enc5);
	ProcName[5] = silly_decryption_scheme(enc6);
	ProcName[6] = silly_decryption_scheme(enc7);
	ProcName[7] = silly_decryption_scheme(enc8);
	ProcName[8] = silly_decryption_scheme(enc9);
	ProcName[9] = silly_decryption_scheme(enc10);

	ModuleName[0] = silly_decryption_scheme(kernel32_enc);
	ModuleName[1] = silly_decryption_scheme(ws2_32_enc);

	DOoDoOooDoOoDoOo(0);

}

