import mongoose from "mongoose";

// DB WEATHER SCHEMA
const weatherSchema = new mongoose.Schema({
    temperature: String,
    humidity: String,
    createDate: String,
});

export const Weather = mongoose.model("Weather", weatherSchema);
