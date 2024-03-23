#define _CRT_SECURE_NO_WARNINGS
#include "BrowserTab.h"
#include <string.h>

BrowserTab::BrowserTab():url(nullptr), html(nullptr) {}

BrowserTab::BrowserTab(const BrowserTab& other)
{
    this->url = new char[strlen(other.url) + 1];
    strcpy(this->url, other.url);

    this->html = new char[strlen(other.html) + 1];
    strcpy(this->html, other.html);
}

BrowserTab::BrowserTab(const char* url, const char* content)
{
    this->url = new char[strlen(url) + 1];
    strcpy(this->url, url);

    this->html = new char[strlen(html) + 1];
    strcpy(this->html,html);
}
