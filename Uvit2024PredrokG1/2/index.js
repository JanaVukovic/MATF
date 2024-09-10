const recipes = [
    {
        name: 'Pizza Margherita', 
        image: 'pizza.jpg'
    },
    {
        name: 'Spaghetti alla Carbonara', 
        image: 'carbonara.jpg'
    },
    {
        name: 'Lasagne', 
        image: 'lasagne.jpg'
    },
    {
        name: 'Fettuccine Alfredo', 
        image: 'fettuccine.jpg'
    },
    {
        name: 'Spaghetti Bolognese', 
        image: 'bolognese.jpg'
    },
    {
        name: 'Spinach & Ricotta Cannelloni', 
        image: 'cannelloni.jpg'
    }
];

let parent = document.getElementById('wrapper');
if(parent != null){
    for(let i = 0; i < recipes.length; i++){
        let naslov = document.createTextNode(recipes[i].name);
        let h2 = document.createElement('h2');
        h2.appendChild(naslov);
        parent.appendChild(h2);
        let slika = document.createElement('img');
        slika.src = recipes[i].image;
        slika.alt = "Ovo je slika recepta sa nazivom iznad";
        slika.style.width = '300px';
        parent.appendChild(slika);
    }
}