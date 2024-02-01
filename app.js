import express from "express";
import "dotenv/config";
import weather_router from "./routes/weather_data.js";

const app = express();
const port = process.env.PORT;

app.get("/", (req, res) => {
    res.send("Hello World");
});

app.listen(port, () => {
    console.log(`Server running in port : ${port}`);
});
