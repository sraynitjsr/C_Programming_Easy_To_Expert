#include <stdio.h>
#include <curl/curl.h>

#define API_ENDPOINT "https://jsonplaceholder.typicode.com/posts"

size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    printf("%.*s", (int)realsize, (char *)contents);
    return realsize;
}

int main() {
    CURL *curl;
    CURLcode res;

    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "Error initializing curl.\n");
        return 1;
    }

    curl_easy_setopt(curl, CURLOPT_URL, API_ENDPOINT);

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);

    res = curl_easy_perform(curl);

    if (res != CURLE_OK)
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
    
    curl_easy_cleanup(curl);
    curl_global_cleanup();

    return 0;
}
