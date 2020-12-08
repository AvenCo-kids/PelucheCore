/*
** EPITECH PROJECT, 2020
** 
** File description:
** API
*/

#ifndef API_HPP_
#define API_HPP_

#include <curl/curl.h>
#include <string>

namespace APC
{
    class API
    {
    public:
        API();
        ~API();

        std::pair<std::string, long> launchStory(std::string id, std::string storyID);
        std::pair<std::string, long> getStory(std::string storyID);
        std::pair<std::string, long> listStories(std::string limit, std::string skip);

        CURL *getCurl(void) const;
    private:
        void initCurl(void);
        std::pair<std::string, long> getRequest(std::string url);

    private:
        std::string _url = "http://localhost:3000/";
        CURL *_curl;
    };
} // namespace APC

#endif /* !API_HPP_ */
