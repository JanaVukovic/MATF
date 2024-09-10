const mongoose = require('mongoose');

const mojaSchema = new mongoose.Schema({
    meal:{
        type: String,
        required: true
    },
    image:{
        type: String,
        required: true
    },
    preparation:{
        type: String,
        required: true
    },
    ingredients:{
        type: [String],
        required: true
    }},{collection:'recipes'})

const mojmodel = mongoose.model('Recipe', mojaSchema);

async function getAllRecipes(){
    let recipes = await mojmodel.find().exec();    
    return recipes;
}

async function searchRecipes(search){
    let recipes = await mojmodel.find({meal: search}).exec();
    return recipes;
}

async function addNewRecipe(recipe){
    console.log(recipe.ingredients[0]);
    await mojmodel.create({meal: recipe.meal, image: recipe.image, preparation: recipe.preparation, ingredients: recipe.ingredients});
    return true;
}

module.exports = {
    getAllRecipes,
    searchRecipes,
    addNewRecipe
};
