import express from "express";
import "dotenv/config";
import weather_router from "./routes/weather_data.js";
import mongoose from "mongoose";

const app = express();
const port = process.env.PORT;
const urlDB = process.env.URL;

app.get("/", (req, res) => {
    res.send("Hello World");
});

await mongoose.connect(urlDB).then(() => {
    console.log("DB Connected!");
    app.listen(port, () => {
        console.log(`Server running in port : ${port}`);
    });
});
