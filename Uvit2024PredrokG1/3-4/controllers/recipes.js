const recipesModel = require('../models/recipes');

async function showAllRecipes(req, res, next) {
    try{
        let recipes = await recipesModel.getAllRecipes();
        res.render('pocetna.ejs', {recipes: recipes});
    }catch(err){
        next(err);
    }
}

async function searchRecipes(req, res, next) {
    try{
        let recipes = await recipesModel.searchRecipes(req.body.find);
        res.render('pocetna.ejs', {recipes: recipes});
    }catch(err){
        next(err);
    }
}

async function addNewRecipe(req, res, next) {
    try{
        let recipe = {
            meal: req.body.meal,
            image: req.body.image,
            preparation: req.body.preparation,
            ingredients: req.body.ingredients.split(', ')
        }
        let check = await recipesModel.addNewRecipe(recipe);
        res.redirect('/');
    }catch(err){
        next(err);
    }
}

module.exports = {
    showAllRecipes,
    searchRecipes,
    addNewRecipe	
};
