import express from "express";
import bodyParser from "body-parser";
import { Weather } from "../schemas/weather_data.js";

const weather_router = express();
weather_router.use(bodyParser.json());

//API for the weather data create
weather_router.post("/weather/create", async (req, res) => {
    const mqttMessage = req.body.message;

    try {
        //Create current date and time
        var currentDateAndTime = new Date();

        var formattedDateAndTime =
            currentDateAndTime.toLocaleDateString() +
            " " +
            currentDateAndTime.toLocaleTimeString();
        //Try to convert the JSON OBJ to JS OBJ
        var jsObject = JSON.parse(mqttMessage);
        console.log("Data from mqtt received successfully to create api");
        const { temperature, humidity } = jsObject;
        const weather = new Weather({
            temperature: temperature,
            humidity: humidity,
            createDate: formattedDateAndTime,
        });

        try {
            await weather.save().then((weatherData) => {
                return res.status(200).json({
                    success: true,
                    message: "Weather data successfully saved to DB!",
                    weatherData: weatherData,
                });
            });
        } catch (error) {
            return res.status(400).json({
                success: false,
                message: error.message,
            });
        }
    } catch (error) {
        console.error("Error parsing JSON:", error.message);
    }
});

//API for the weather data view
weather_router.get("/weather/all", async (req, res) => {
    try {
        await Weather.find().then((weatherData) => {
            if (weatherData.length <= 0) {
                res.status(200).json({
                    success: false,
                    message: "No weather data to display !",
                });
            } else {
                res.status(200).json({
                    success: true,
                    message: "Weather data found successfully !",
                    weather: weatherData,
                });
            }
        });
    } catch (error) {
        return res.status(400).json({
            success: false,
            message: error.message,
        });
    }
});

//API for the weather data live

export default weather_router;
