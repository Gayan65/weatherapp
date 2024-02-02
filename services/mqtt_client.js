import mqtt from "mqtt";
import axios from "axios";
import "dotenv/config";

// MQTT SERVER, TOPIC
const mqttServer = process.env.MQTT;
const topic = process.env.TOPIC;
const port = process.env.PORT;

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
    //console.log(message.toString());
    saveMessageToApi(message.toString());

    //client.end();
});

//Making an API request to save realtime data to DB
function saveMessageToApi(message) {
    axios
        .post(`http://localhost:${port}/weather/create`, { message })
        .then((response) => {
            //console.log(response.data);
        })
        .catch((error) => {
            console.error("Error saving message:", error.message);
        });
}

export default client;
