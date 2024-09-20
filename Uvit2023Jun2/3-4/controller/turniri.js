const mongoose = require('mongoose');
const turniriModel = require('../model/turniri');


async function prikaziPocetnu(req, res, next) {
    try {
        let turniri = await turniriModel.dohvatiTurnire();
        res.render('pocetna.ejs', {turniri:turniri});
    } catch(err){
        next(err);
    }
}


async function prikaziTurnir(req, res, next) {
    try {
        let mecevi = await turniriModel.dohvatiIgreZaTurnir(req.query.turnir);
        res.render('turnir.ejs', {mecevi:mecevi, turnir:req.query.turnir});
    } catch(err){
        next(err);
    }
}


async function unesiMec(req, res, next) {
    try {
        let poeni1 = req.query.prvi + '-' + req.query.drugi + '-' + req.query.treci;
        let poeni2 = req.query.prvi2 + '-' + req.query.drugi2 + '-' + req.query.treci2;
        await turniriModel.unesiTurnir(req.query.igrac1, req.query.igrac2, poeni1, poeni2, req.query.vreme, req.query.turnir);        
        prikaziTurnir(req, res, next);
    } catch(err){
        next(err);
    }
}


module.exports = {
    prikaziPocetnu,
    prikaziTurnir,
    unesiMec
};