#include <iostream>
#include <fstream>
#include <time.h>
#include <direct.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stack>
#include <stdlib.h>
#include <stdio.h>
#include <string> 
#include <pthread.h>
#include <unistd.h>
#include <winsock2.h>
#include <Windows.h>
#include <vector>
#include <cstring>
#include <cstdio>
#include <sstream>
#pragma comment(lib, "ws2_32.lib")
using namespace std;
string src;
double fileByte = 0;
void Download_Image(string imageUrl, string HostName, string dirname, int s);
void Download_Image(string imageUrl, string HostName, string dirname, int s){
	if(imageUrl.find("http",0) != std::string::npos || imageUrl.find("https",0) != std::string::npos){
		imageUrl = imageUrl;
	}
	else if(imageUrl.find("/", 0) != std::string::npos){
		imageUrl = "http://" + HostName + imageUrl;
	}
	else if(imageUrl.find("./", 0) != std::string::npos){
		imageUrl = imageUrl.substr(1, imageUrl.length() - 1);
		imageUrl = "http://" + HostName + imageUrl;
	}
	else{
		imageUrl = "http://" + HostName + "/" + imageUrl;
	}
    char temp[800];  
    strcpy(temp, imageUrl.c_str());  
    size_t begin = imageUrl.find_first_of("/", 0) + 2;
    size_t end = imageUrl.find_first_of("/", begin + 2);
    string hostname = imageUrl.substr(begin, end - begin);
    string pagepath = imageUrl.substr(end, imageUrl.size() - end); 
    string filename = imageUrl.substr(imageUrl.find_last_of("."));
    WSADATA wd;  
    WSAStartup(MAKEWORD(2, 2), &wd);  
    SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);  
    if (sock == INVALID_SOCKET){  
        return;  
    }  
    sockaddr_in sa = { AF_INET };  
    int n = bind(sock, (sockaddr*)&sa, sizeof(sa));  
    if (n == SOCKET_ERROR){  
        return;  
    }  
    struct hostent *p = gethostbyname(hostname.c_str());  
    if (p == NULL){  
        return;  
    }  
    sa.sin_port = htons(80);  
    memcpy(&sa.sin_addr, p->h_addr, 4); 
    n = connect(sock, (sockaddr*)&sa, sizeof(sa));  
    if (n == SOCKET_ERROR){  
        return;  
    }  
    string reqInfo = "GET " + pagepath + " HTTP/1.1\r\nHost: " + hostname + "\r\nConnection:Close\r\n\r\n";  
    if (SOCKET_ERROR == send(sock, reqInfo.c_str(), reqInfo.size(), 0)){
        closesocket(sock);  
        return;  
    }  
    stringstream ss;
    ss << s;
    string num = ss.str();
    string path = ".\\" + dirname + "\\file" + num + filename;
    fstream file;
	file.open(path, ios::out | ios::binary);
    char buf[1024];  
    memset(buf, 0, sizeof(buf));  
    n = recv(sock, buf, sizeof(buf) - 1, 0);  
    char *cpos = strstr(buf, "\r\n\r\n");  
    file.write(cpos + strlen("\r\n\r\n"), n - (cpos - buf) - strlen("\r\n\r\n"));  
    while ((n = recv(sock, buf, sizeof(buf) -1 , 0)) > 0){  
        file.write(buf, n);    
    }  
    file.close(); 
    string r = "file" + num + filename;
    src = r;
    /*FILE *fp;
    long size;
    fp = fopen(path.c_str(), "rb");
    if(fp){
    	fseek(fp, 0, SEEK_END);
    	size = ftell(fp);
    	fclose(fp);
	}
	size /= 1024.0;
	fileByte += size;*/
	ifstream File(path.c_str() ,ios::in | ios::binary | ios::ate);
  	ifstream::pos_type eof = File.tellg();
  	fileByte += eof;
}
int main(int argc, char** argv){
	string address, dirname;
	if(argc == 1){
		cout << "請輸入網址：" << endl;
		cin >> address;
		cout << "請輸入要放置的資料夾名稱：" << endl;
		cin >> dirname;
	}
	else if(argc == 3){
		address = argv[1];
		dirname = argv[2];
	}
	else{
		cout << "參數數量錯誤！" << endl;
		exit(1); 
	}
	if(address.find("http") == std::string::npos || address.find("\\") != std::string::npos){
		cout << "輸入的網址有誤！" << endl;
		exit(1); 
	}
	double time = 0;
	double counts = 0;
	LARGE_INTEGER nFreq;
	LARGE_INTEGER nBeginTime;
	LARGE_INTEGER nEndTime;
	QueryPerformanceFrequency(&nFreq);
	QueryPerformanceCounter(&nBeginTime); //開始計時 
    size_t begin = address.find_first_of("/", 0) + 2;
    size_t end = address.find_first_of("/", begin + 2);
    string hostname = address.substr(begin, end - begin);
    string pagepath = address.substr(end, address.size() - end); 
    string reqInfo = "GET " + pagepath + " HTTP/1.1\r\nHost: " + hostname + "\r\nConnection:Close\r\n\r\n";
    WSADATA wsaData;  
    WSAStartup(MAKEWORD(2, 2), &wsaData);  
    SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);  
    if (sock == INVALID_SOCKET){  
        return 0;  
    }  
    sockaddr_in sa = { AF_INET };  
    int n = bind(sock, (sockaddr*)&sa, sizeof(sa));  
    if (n == SOCKET_ERROR){  
        return 0;  
    }  
    struct hostent *host = gethostbyname(hostname.c_str()); 
    if (host == NULL){  
        return 0;  
    }  
    sa.sin_port = htons(80);  
    memcpy(&sa.sin_addr, host->h_addr, 4);
    n = connect(sock, (sockaddr*)&sa, sizeof(sa));  
    if (n == SOCKET_ERROR){  
        return 0;  
    }  
    if (SOCKET_ERROR == send(sock, reqInfo.c_str(), reqInfo.size(), 0)){
        closesocket(sock);  
        return 0;  
    } 
    char buf[1000];	
    GetCurrentDirectory(1000, buf);
    string pathname = buf;
    pathname = pathname + "\\" + dirname;	
	if (access(pathname.c_str(), 0)){
		cout << "欲存放的資料夾不存在！" << endl;
		exit(1); 
	    //mkdir(pathname.c_str());
	}									
    send(sock, reqInfo.c_str(), strlen(reqInfo.c_str()), 0);
    char txt[500000] = {};
    recv(sock, txt, sizeof(txt), 0);
    //cout << txt;
    string txt_str = txt;
    if(txt_str.find("200 OK", 0) == std::string::npos){
		cout << "此網址無效!" << endl;
		exit(1);
	}
	else{
		cout << "200 OK" << endl;
	}
    size_t cut1;
    if(txt_str.find("<!DOCTYPE ", 0) != std::string::npos){
    	cut1 = txt_str.find("<!DOCTYPE ", 0);
	}
	else{
		cut1 = txt_str.find("<html", 0);
	}
	//cout << cut1 << endl;
    string htmlcontext = txt_str.substr(cut1);
    //cout << "htmlcontext:" << htmlcontext;
    closesocket(sock);
    istringstream iss(htmlcontext);
    vector<string> url;
    string token;
    while(getline(iss, token, '"')){
		url.push_back(token);
	}	 
	bool out = false;
	int s = 0;
	for(auto u : url){
		string str = u;
		if(out == true){
			s++; 
			Download_Image(u, hostname, dirname, s);
			//cout << u << endl;
			out = false;
			htmlcontext.replace(htmlcontext.find(str), str.length(), src);
		}
		/*if(u == " src="){
			out = true;
		}*/
		if(str.find(" src=", 0) != std::string::npos){
			out = true;
		}
	}
	char context[100000];
	int i;
	for(i = 0; i < htmlcontext.length(); i++){
		context[i] = htmlcontext[i];
	}
	context[i] = '\0';
	string htmlname = ".\\" + dirname + "\\Michael.html";
	fstream File;
	File.open(htmlname, ios::out | ios::binary);
	File.write(context, sizeof(context));
	File.close();
	ifstream htmlbyte(htmlname.c_str(), ios::in | ios::binary | ios::ate);
	ifstream::pos_type eof = htmlbyte.tellg();	
	//fileByte *= 1000;
	fileByte += eof;
	QueryPerformanceCounter(&nEndTime); //停止計時  
	time = (double)(nEndTime.QuadPart - nBeginTime.QuadPart) / (double)nFreq.QuadPart; //計算程式執行時間單位為s
	s++;
	cout << "檔案數量：" << s << "個" << endl; 
	cout << "下載總容量：" << fileByte << "bytes" << endl; 
	cout << "下載時間：" << time * 1000 << "ms" << endl;
}
