const mongoose = require('mongoose');
const evrosongModel = require('../model/evrosong');
const XMLHttpRequest = require("xmlhttprequest").XMLHttpRequest;


async function prikaziPocetnu(req, res, next) {
    try {
        res.render('pocetna.ejs', {results: null});
    } catch(err){
        next(err);
    }
    next();
}


async function prikaziGlasoveDrzave(req, res, next) {
    try {
        let check = await evrosongModel.dodajNoviGlas(req.query.drzava2, req.query.drzava1, req.query.poeni); 
        if(!check){
            const glasovi = await evrosongModel.dohvatiGlasoveDrzave(req.query.drzava2);
            return res.render('poeni.ejs', {
                glas: {
                    ime: req.query.drzava2,
                    dr: glasovi
                }
            });
        }else{
            let xhr = new XMLHttpRequest();
            xhr.open('POST', 'http://localhost:3000/final');
            xhr.setRequestHeader("Content-Type", "application/json");
            xhr.onload = function(){
                if (xhr.status >= 200 && xhr.status < 300) {
                    res.send(xhr.responseText);
                }else{
                    next(xhr.status);
                }
            }
            xhr.send();
        }
    } catch(err){
        next(err);
    }
}


async function prikaziKonacno(req, res, next){
	try {
        let ukupno = await evrosongModel.dohvatiUkupneGlasove();
        res.render('pocetna.ejs', {results: ukupno});
    } catch(err){
        next(err);
    }
}


module.exports = {
    prikaziPocetnu,
    prikaziGlasoveDrzave,
    prikaziKonacno
};
