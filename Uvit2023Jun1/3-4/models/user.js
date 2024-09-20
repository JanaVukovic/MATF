const mongoose = require('mongoose');

const MojaSchema = mongoose.Schema({
    ime:{
        type:String,
        required:true
    },
    prezime:{type:String},
    starost:{type:Number, required:true},
    admin:{type:boolean, default:false}
},{collection:korisnici});

let mojModel = mongoose.model('Korisnik', mojaSchema);

async function dohvatiKorisnike(){
    let korisnici = await mojModel.find().exec();
    return korisnici;
}

async function obrisi(ime, prezime, godine){
    let osoba = await mojModel.find({ime:ime, prezime:prezime, godine:godine}).exec();
    if(osoba.admin){
        return {osoba:osoba, success:false};
    }else{
        await mojModel.deleteOne({ime:ime, prezime:prezime, godine:godine});
        return {osoba:osoba, success:true};
    }
}

async function samo(godine){
    let korisnici = await mojModel.find({starost:godine});
    korisnici.sort(function(a,b){return b.starost - a.starost;});
    return korisnici;
}

module.exports = {
    dohvatiKorisnike,
    obrisi,
    samo
};