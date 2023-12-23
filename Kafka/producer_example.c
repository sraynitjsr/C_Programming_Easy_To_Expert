#include <librdkafka/rdkafka.h>

int main() {
    rd_kafka_conf_t *conf = rd_kafka_conf_new();

  rd_kafka_conf_set(conf, "bootstrap.servers", "my_kafka_broker", NULL);

    rd_kafka_t *producer = rd_kafka_new(RD_KAFKA_PRODUCER, conf, NULL, 0);
    if (!producer) {
        fprintf(stderr, "Failed to create producer\n");
        return 1;
    }

    rd_kafka_topic_t *topic = rd_kafka_topic_new(producer, "my_topic", NULL);
    if (!topic) {
        fprintf(stderr, "Failed to create topic\n");
        return 1;
    }

    rd_kafka_produce(topic, RD_KAFKA_PARTITION_UA, RD_KAFKA_MSG_F_COPY,
                     "my_message_data", strlen("my_message_data"),
                     "my_message_key", strlen("my_message_key"),
                     NULL);

    rd_kafka_flush(producer, 1000);

    rd_kafka_topic_destroy(topic);
    rd_kafka_destroy(producer);
    rd_kafka_wait_destroyed(1000);

    return 0;
}
