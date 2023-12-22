#include <stdio.h>
#include <curl/curl.h>

#define API_ENDPOINT "https://jsonplaceholder.typicode.com/todos/1"
#define API_TOKEN "my_api_token_here"

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

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, fwrite);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, stdout);

    struct curl_slist *headers = NULL;
    char auth_header[50];
    snprintf(auth_header, sizeof(auth_header), "Authorization: Bearer %s", API_TOKEN);
    headers = curl_slist_append(headers, auth_header);
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

    res = curl_easy_perform(curl);

    if (res != CURLE_OK)
        fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));

    curl_easy_cleanup(curl);
    curl_slist_free_all(headers);
    curl_global_cleanup();

    return 0;
}
