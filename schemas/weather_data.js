import mongoose from "mongoose";

const weatherSchema = new mongoose.Schema({
    temperature: String,
    humidity: String,
    createDate: Date,
});

export const Weather = mongoose.model("Weather", weatherSchema);
