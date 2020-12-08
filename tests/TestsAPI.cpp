#include <criterion/criterion.h>
#include <curl/curl.h>
#include "../include/API.hpp"

Test(api, initialization)
{
    APC::API api;
    cr_assert(api.getCurl() != NULL, "CURL initialization failed.");
}

Test(api, get_list_of_stories)
{
    APC::API api;
    auto r = api.listStories("0", "10");
    cr_assert(r.second == 200, "Failed to gather the list of stories.");
}

Test(api, get_list_of_stories_invalid_params)
{
    APC::API api;
    auto r = api.listStories("1", "-1");
    cr_assert(r.second >= 300, "Succeeded upon negative list size.");
}

Test(api, request_story)
{
    APC::API api;
    auto r = api.getStory("0" /* existing ID */);
    cr_assert(r.second == 200, "Couldn't get the requested story.");
}

Test(api, request_story_nonexistent)
{
    APC::API api;
    auto r = api.getStory(std::to_string(0xDEADBEEF));
    cr_assert(r.second >= 300, "Got Success on a nonexistent story ID.");
}

Test(api, launch_story)
{
    APC::API api;
    auto r = api.launchStory("0", "0" /* existing IDs */);
    cr_assert(r.second == 200, "Couldn't start the requested story.");
}

Test(api, launch_story_nonexistent)
{
    APC::API api;
    auto r = api.launchStory("0", std::to_string(0xDEADBEEF));
    cr_assert(r.second >= 300, "Succeeded to launch a nonexistent story.");
}
