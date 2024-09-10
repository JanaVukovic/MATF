const express = require("express");
const controller = require("../controllers/recipes");

const router = express.Router();

router.post('/new', controller.addNewRecipe);
router.post('/search', controller.searchRecipes);
router.get('/', controller.showAllRecipes);

module.exports = router;
