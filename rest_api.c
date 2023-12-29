#include "mongoose.h"
#include <stdio.h>

static const char *s_http_port = "8080";
static struct mg_serve_http_opts s_http_server_opts;

static void handle_api_request(struct mg_connection *nc, struct http_message *hm) {
    if (mg_vcmp(&hm->uri, "/api/users") == 0) {
        if (strcmp(hm->method.ptr, "GET") == 0) {
            mg_printf(nc, "HTTP/1.1 200 OK\r\nContent-Type: application/json\r\n\r\n");
            mg_printf(nc, "{ \"message\": \"List of users\" }");
        } else if (strcmp(hm->method.ptr, "POST") == 0) {
            mg_printf(nc, "HTTP/1.1 201 Created\r\nContent-Type: application/json\r\n\r\n");
            mg_printf(nc, "{ \"message\": \"User created\" }");
        } else if (strcmp(hm->method.ptr, "PUT") == 0) {
            mg_printf(nc, "HTTP/1.1 200 OK\r\nContent-Type: application/json\r\n\r\n");
            mg_printf(nc, "{ \"message\": \"User updated\" }");
        } else if (strcmp(hm->method.ptr, "DELETE") == 0) {
            mg_printf(nc, "HTTP/1.1 200 OK\r\nContent-Type: application/json\r\n\r\n");
            mg_printf(nc, "{ \"message\": \"User deleted\" }");
        } else {
            mg_http_send_error(nc, 405, "Method Not Allowed", "Allow: GET, POST, PUT, DELETE\r\n");
        }
    } else {
        mg_http_send_error(nc, 404, "Not Found", "");
    }
}

static void ev_handler(struct mg_connection *nc, int ev, void *ev_data) {
    struct http_message *hm = (struct http_message *)ev_data;

    switch (ev) {
        case MG_EV_HTTP_REQUEST:
            handle_api_request(nc, hm);
            break;
        default:
            break;
    }
}

int main(void) {
    struct mg_mgr mgr;
    struct mg_connection *nc;

    mg_mgr_init(&mgr, NULL);

    nc = mg_bind(&mgr, s_http_port, ev_handler);
    if (nc == NULL) {
        fprintf(stderr, "Error starting the server.\n");
        return 1;
    }

    mg_set_protocol_http_websocket(nc);
    s_http_server_opts.document_root = ".";

    printf("Server is running on http://localhost:%s\n", s_http_port);

    while (1) {
        mg_mgr_poll(&mgr, 1000);
    }

    mg_mgr_free(&mgr);

    return 0;
}
