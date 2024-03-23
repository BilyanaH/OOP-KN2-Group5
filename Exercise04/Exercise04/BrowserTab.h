#ifndef BROWSERTAB_H
#define BROWSERTAB_H
class BrowserTab {
private:
	char* url;
	char* html;
public: 
	BrowserTab();
	BrowserTab(const BrowserTab& other);
	BrowserTab(const char* url, const char* content);

};

#endif // !BROWSETAB_H
