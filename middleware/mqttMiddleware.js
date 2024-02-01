import client from "../services/mqtt_client.js";

// Middleware for MQTT CLIENT
const mqttMiddleware = (req, res, next) => {
    console.log("Middleware executed");
    next();
};

export default mqttMiddleware;
