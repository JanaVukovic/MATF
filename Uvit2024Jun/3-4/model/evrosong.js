const mongoose = require('mongoose')

const MojaSchema = new mongoose.Schema({
    drzava1:{
        type: String,
        required: true
    },
    drzava2:{
        type: String,
        required: true
    },
    poeni:{
        type: Number,
        required: true
    },
    drzave:{
        type:[String],
        required: false,
    }
}, {collection: 'glasanjes'});

const glasanjeModel = mongoose.model('Glasanje', MojaSchema);

module.exports.model = glasanjeModel;

async function dohvatiUkupneGlasove() {
    console.log("Poslednja funkcija");
    let rezultati = [];
    let svi = await glasanjeModel.find().exec();
    for(let i = 0; i < svi.length; i++){
        if(findFirst(svi[i].drzava2) !== i)continue;
        let ime = svi[i].drzava2;
        let sum = 0;
        for(let j = 0; j < svi.length; j++){
            if(svi[j].drzava2 == ime){
                sum+=svi[j].poeni;
            }
        }
        rezultati.push({country: ime, points: sum});
    }
    rezultati.sort((a, b)=>(b.points - a.points));
    return rezultati;

    function findFirst(str){
        for(let i = 0; i < svi.length; i++){
            if(svi[i].drzava2 == str)return i;
        }
        return svi.length+1;
    };
} 


async function dohvatiGlasoveDrzave(drzava){
    let op = await glasanjeModel.find({drzava1: drzava}).exec();
    if(op == null){
        console.log("Nismo pronasli " + drzava);
        return null;
    }
    let poeni = [];
    for(let i = 0; i < op.length; i++){
        poeni.push({country:op[i].drzava2, points:op[i].poeni});
    }
    poeni.sort((a, b) => b.points - a.points);
    return poeni;
}

async function dodajNoviGlas(odDrzave, drzavi, poeni){
    let check = await glasanjeModel.find({drzava1: odDrzave, drzava2: drzavi});
    if(check.length != 0){
        console.log("Nije dodato");
        return false;
    }else{
        await glasanjeModel.create({
            drzava1: odDrzave,
            drzava2: drzavi,
            poeni: poeni});
        return true;
    }
}

module.exports = {
    dohvatiUkupneGlasove,
    dohvatiGlasoveDrzave,
    dodajNoviGlas
};
