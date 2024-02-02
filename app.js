import express from "express";
import "dotenv/config";
import weather_router from "./routes/weather_data.js";
import mongoose from "mongoose";
import mqttMiddleware from "./middleware/mqttMiddleware.js";

const app = express();
const port = process.env.PORT;
const urlDB = process.env.URL;

// MIDDLEWARES
app.use(weather_router);
app.use(mqttMiddleware);

app.get("/", (req, res) => {
    res.send("Hello World");
});

//SERVER AND DB CONNECTION
await mongoose.connect("mongodb://127.0.0.1:27017/weatherDB").then(() => {
    console.log("DB Connected!");
    app.listen(port, () => {
        console.log(`Server running in port : ${port}`);
    });
});
