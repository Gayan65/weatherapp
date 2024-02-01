import mongoose from "mongoose";

const weatherSchema = new mongoose.Schema({
    temperature: String,
    humidity: String,
    createDate: Date,
});

export const User = mongoose.model("Weather", weatherSchema);
