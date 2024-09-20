const mongoose = require('mongoose')

const mojaSchema = new mongoose.Schema({
    igrac1:{
        type:String,
        required:true
    },
    igrac2:{
        type:String,
        required:true
    },
    poeni1:{
        type:String,
        required:true
    },
    poeni2:{
        type:String,
        required:true
    },
    vreme:{
        type:String
    },
    turnir:{
        type:String
    }
},{collection: 'turniri'});

const mojModel = mongoose.model('Turniri', mojaSchema);

async function dohvatiIgreZaTurnir(turnir) {
    let igre = await mojModel.find({turnir:turnir}).exec();
    return igre;
} 


async function dohvatiTurnire() {
    let turniri = [];
    let sve = await mojModel.find().exec();
    console.log(sve);
    for(let i = 0; i < sve.length; i++){
        let has = false;
        for(let j = 0; j < turniri.length; j++){
            console.log(turniri[j], sve[i].turnir);
            if(turniri[j] == sve[i].turnir){
                has = true;
                break;
            }
        }
        if(!has){
            turniri.push(sve[i].turnir);
        }
    }
    return turniri;
}

async function unesiTurnir(igrac1, igrac2, poeni1, poeni2, vreme, turnir) {
    await mojModel.create({igrac1:igrac1, igrac2:igrac2, poeni1:poeni1, poeni2:poeni2, vreme:vreme, turnir:turnir});
    return;
} 

module.exports = {
    dohvatiTurnire,
    dohvatiIgreZaTurnir,
    unesiTurnir
};