#include <librdkafka/rdkafka.h>

int main() {
    rd_kafka_conf_t *conf = rd_kafka_conf_new();
    
    rd_kafka_conf_set(conf, "bootstrap.servers", "my_kafka_broker", NULL);
    
    rd_kafka_t *consumer = rd_kafka_new(RD_KAFKA_CONSUMER, conf, NULL, 0);
    if (!consumer) {
        fprintf(stderr, "Failed to create consumer\n");
        return 1;
    }

    rd_kafka_subscribe(consumer, rd_kafka_topic_partition_list_new("my_topic", RD_KAFKA_PARTITION_UA));

    rd_kafka_message_t *message;
    while (1) {
        message = rd_kafka_consumer_poll(consumer, 1000);
        if (message) {
            printf("Received message: %.*s\n", (int)message->len, (char *)message->payload);
            rd_kafka_message_destroy(message);
        }
    }

    rd_kafka_consumer_close(consumer);
    rd_kafka_destroy(consumer);

    return 0;
}
