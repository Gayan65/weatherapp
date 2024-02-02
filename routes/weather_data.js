import express from "express";
import bodyParser from "body-parser";
import { Weather } from "../schemas/weather_data.js";

const weather_router = express();
weather_router.use(bodyParser.json());
//weather_router.use(bodyParser.urlencoded({ extended: false }));

//API for the weather data create
weather_router.post("/weather/create", async (req, res) => {
    const mqttMessage = req.body.message;
    //Try to convert the JSON OBJ to JS OBJ
    try {
        var jsObject = JSON.parse(mqttMessage);
        //console.log("Parsed JavaScript Object:", jsObject);
        console.log("Data from mqtt received successfully to create api");
        const { temperature, humidity } = jsObject;
        const weather = new Weather({
            temperature: temperature,
            humidity: humidity,
            //createDate: dateAndTime,
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

    /*

    */
});

//API for the weather data view

//API for the weather data live

export default weather_router;
