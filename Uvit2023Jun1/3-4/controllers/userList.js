const userModel = require('../models/user');

async function prikaziPocetnu(req, res, next) {
    try {
        let korisnici = await userModel.dohvatiKorisnike();
        korisnici.sort(function(a, b){return b.starost - a.starost;});
        res.render('pocetna.ejs', {korisnici:korisnici});
    } catch(err){
        next(err);
    }
}

async function obrisi(req, res, next){
    try{
        let uspelo = await userModel.obrisi(req.query.ime, req.query.prezime, req.query.godine);
        res.render('userList.ejs', {osoba:uspelo.osoba, success:uspelo.success});
    }catch(err){next(err);}
}

async function samo(req, res, next){
    try{
        let korisnici = await userModel.samo(req.body.godine);
        res.render('userList.ejs', korisnici);
    }catch(err){
        next(err);
    }
}