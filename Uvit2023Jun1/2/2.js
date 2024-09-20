const korisnici = [
    { ime: 'Rowan', prezime: "O'Connor" },
    { ime: 'Melody', prezime: 'Norton' },
    { ime: 'Minnie', prezime: 'Terry' },
    { ime: 'Damien', prezime: 'Roach' },
    { ime: 'Ida', prezime: 'Macdonald' },
    { ime: 'Zak', prezime: 'Carlson' },
    { ime: 'Nevaeh', prezime: 'Randolph' },
    { ime: 'Dewi', prezime: 'Sanford' },
    { ime: 'Michelle', prezime: 'Rhodes' },
    { ime: 'Oscar', prezime: 'Carter' },
];

let ol = document.getElementById('lista');

for(let i = 0; i < korisnici.length; i++){
    let li = document.createElement('li');
    let ime = document.createElement('span');
    ime.textContent = korisnici[i].ime;
    let prezime = document.createElement('span');
    prezime.textContent = ' ' + korisnici[i].prezime;
    li.appendChild(ime);
    li.appendChild(prezime);
    if(i % 2 == 0){
        prezime.style.color = 'green';
        ime.style.color = 'red';
    }else{
        prezime.style.color = 'red';
        ime.style.color = 'green';
    }
    ol.appendChild(li);
}