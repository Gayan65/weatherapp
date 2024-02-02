import express from "express";
import "dotenv/config";
import weather_router from "./routes/weather_data.js";
import mongoose from "mongoose";
import mqttMiddleware from "./middleware/mqttMiddleware.js";
import axios from "axios";

const app = express();
const port = process.env.PORT;
const urlDB = process.env.URL;

// MIDDLEWARES
app.use(weather_router);
app.use(mqttMiddleware);

app.get("/", async (req, res) => {
    await axios.get(`http://localhost:${port}/weather/all`).then((response) => {
        res.render("index.ejs", {
            name: response.data.weather[response.data.weather.length - 1]
                .temperature,
        });
    });
});

//SERVER AND DB CONNECTION
await mongoose.connect("mongodb://127.0.0.1:27017/weatherDB").then(() => {
    console.log("DB Connected!");
    app.listen(port, () => {
        console.log(`Server running in port : ${port}`);
    });
});
