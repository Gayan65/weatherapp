import express from "express";
import { Weather } from "../schemas/weather_data.js";

const weather_router = express();
weather_router.use(bodyParser.urlencoded({ extended: false }));

//API for the weather data
weather_router.get("/weather", async (req, res) => {
    try {
        await Weather.find().then((weather) => {
            return res.status(200).json({
                success: true,
                allWeatherData: weather,
            });
        });
    } catch (error) {
        return res.status(400).json({
            success: false,
            error: error.message,
        });
    }
});
