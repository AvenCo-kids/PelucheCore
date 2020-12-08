/*
** EPITECH PROJECT, 2020
** 
** File description:
** API
*/

#include "../include/API.hpp"

namespace APC
{
    API::API()
    {
        _curl = curl_easy_init();
    }

    API::~API()
    {
        if (_curl)
            curl_easy_cleanup(_curl);
    }

    CURL *API::getCurl(void) const
    {
        return _curl;
    }

    void API::initCurl(void)
    {
        if (!_curl)
            _curl = curl_easy_init();
    }

    static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
    {
        ((std::string *)userp)->append((char *)contents, size * nmemb);
        return size * nmemb;
    }

    std::pair<std::string, long> API::getRequest(std::string url)
    {
        std::string buffer;
        CURLcode res;
        long httpCode;

        initCurl();
        curl_easy_setopt(_curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(_curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(_curl, CURLOPT_WRITEDATA, &buffer);
        res = curl_easy_perform(_curl);
        curl_easy_getinfo(_curl, CURLINFO_RESPONSE_CODE, &httpCode);
        if (httpCode != 200)
            buffer = "[Error]";
        return std::make_pair(buffer, httpCode);
    }

    std::pair<std::string, long> API::launchStory(std::string id, std::string storyID)
    {
        std::string url = _url;

        url += "story/launch/";
        url += id;
        url += "/";
        url += storyID;

        return getRequest(url);
    }

    std::pair<std::string, long> API::getStory(std::string storyID)
    {
        std::string url = _url;

        url += "story/";
        url += storyID;
        return getRequest(url);
    }

    std::pair<std::string, long> API::listStories(std::string limit, std::string skip)
    {
        std::string url = _url;

        url += "story?limit=";
        url += limit;
        url += "&skip=";
        url += skip;
        return getRequest(url);
    }
}
