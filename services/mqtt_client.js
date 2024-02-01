import mqtt from "mqtt";
import "dotenv/config";

// MQTT SERVER, TOPIC
const mqttServer = process.env.MQTT;
const topic = process.env.TOPIC;

const client = mqtt.connect(mqttServer);

client.on("connect", () => {
    client.subscribe(topic, (err) => {
        if (!err) {
            client.publish(topic, "MQTT server connected successfully !");
        }
    });
});

client.on("message", (topic, message) => {
    // message is Buffer
    console.log(message.toString());
    //client.end();
});

export default client;
