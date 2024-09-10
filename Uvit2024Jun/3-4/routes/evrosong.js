const express = require("express");

const router = express.Router();

const controller = require('../controller/evrosong');

router.get('/poeni', controller.prikaziGlasoveDrzave);

router.get('/', controller.prikaziPocetnu);

router.post('/final', controller.prikaziKonacno);

module.exports = router;
