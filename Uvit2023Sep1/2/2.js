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

const ol = document.getElementById('lista');
let n = korisnici.length;

if(ol != null){
    for(let i = 0; i < n; i++){
        let txt = document.createTextNode(korisnici[i].ime+" "+korisnici[i].prezime);
        let li = document.createElement('li');
        li.appendChild(txt);
        ol.appendChild(li); 
    }
    let lis = document.getElementsByTagName('li');
    for(let i = 0; i < n; i++){
        lis[i].addEventListener('click', obrisi);
    }
}

function obrisi(e){
    e.target.style.color = "red";
    setTimeout(function(){
        ol.removeChild(e.target);
    },2000);
}