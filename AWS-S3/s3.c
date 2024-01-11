#include <aws/core/Aws.h>
#include <aws/s3/S3Client.h>
#include <aws/s3/model/CreateBucketRequest.h>
#include <aws/s3/model/PutObjectRequest.h>
#include <aws/s3/model/GetObjectRequest.h>
#include <stdio.h>

int main()
{
    aws_sdk_init();

    struct aws_credentials credentials;
    aws_credentials_load_from_environment(&credentials);
    struct aws_client_configuration client_config = {
        .region = aws_byte_cursor_from_c_str("ap-south-1"),
        .credentials = &credentials,
    };

    struct aws_s3_client *s3_client = aws_s3_client_new(&client_config);

    const char *bucket_name = "my-unique-bucket-name";

    struct aws_s3_create_bucket_request create_bucket_request = {
        .bucket_name = aws_byte_cursor_from_c_str(bucket_name),
    };
    struct aws_s3_create_bucket_response *create_bucket_response = aws_s3_create_bucket(s3_client, &create_bucket_request);

    if (create_bucket_response == NULL || create_bucket_response->error_code) {
        printf("Error creating S3 bucket: %s\n", aws_error_str(aws_last_error()));
        aws_s3_create_bucket_response_destroy(create_bucket_response);
        aws_s3_client_destroy(s3_client);
        aws_sdk_clean_up();
        return 1;
    }

    printf("S3 bucket created successfully!\n");

    const char *key_name = "example.txt";
    const char *data = "Hello, AWS S3 from C!";
    struct aws_byte_cursor data_cursor = aws_byte_cursor_from_c_str(data);

    struct aws_s3_put_object_request put_object_request = {
        .bucket_name = aws_byte_cursor_from_c_str(bucket_name),
        .key = aws_byte_cursor_from_c_str(key_name),
        .body = aws_input_stream_new_from_cursor(aws_default_allocator(), &data_cursor),
    };
    struct aws_s3_put_object_response *put_object_response = aws_s3_put_object(s3_client, &put_object_request);

    if (put_object_response == NULL || put_object_response->error_code) {
        printf("Error uploading object to S3: %s\n", aws_error_str(aws_last_error()));
        aws_s3_put_object_response_destroy(put_object_response);
        aws_s3_client_destroy(s3_client);
        aws_sdk_clean_up();
        return 1;
    }

    printf("Object uploaded to S3 successfully!\n");

    struct aws_s3_get_object_request get_object_request = {
        .bucket_name = aws_byte_cursor_from_c_str(bucket_name),
        .key = aws_byte_cursor_from_c_str(key_name),
    };
    struct aws_s3_get_object_response *get_object_response = aws_s3_get_object(s3_client, &get_object_request);

    if (get_object_response == NULL || get_object_response->error_code) {
        printf("Error downloading object from S3: %s\n", aws_error_str(aws_last_error()));
        aws_s3_get_object_response_destroy(get_object_response);
        aws_s3_client_destroy(s3_client);
        aws_sdk_clean_up();
        return 1;
    }

    uint8_t buffer[1024];
    size_t bytes_read;
    while (aws_input_stream_read(get_object_response->body, buffer, sizeof(buffer), &bytes_read) == AWS_OP_SUCCESS) {
        fwrite(buffer, 1, bytes_read, stdout);
    }
    printf("\n");

    aws_s3_get_object_response_destroy(get_object_response);
    aws_s3_put_object_response_destroy(put_object_response);
    aws_s3_create_bucket_response_destroy(create_bucket_response);
    aws_s3_client_destroy(s3_client);
    aws_sdk_clean_up();

    return 0;
}
