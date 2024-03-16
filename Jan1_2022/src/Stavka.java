public abstract class Stavka {
    String korisnickoIme, naslov, sadrzaj;
    Labela labela;
    boolean razresena;

    public Stavka(String korisnickoIme, String naslov, String sadrzaj) {
        this.korisnickoIme = korisnickoIme;
        this.naslov = naslov;
        this.sadrzaj = sadrzaj;
    }
    public void labeliraj(Labela labela){
        this.labela = labela;
    }
    public void razresi(){
        this.razresena = true;
    }
    public String getKorisnickoIme() {
        return korisnickoIme;
    }

    public String getNaslov() {
        return naslov;
    }

    public String getSadrzaj() {
        return sadrzaj;
    }

    public Labela getLabela() {
        return labela;
    }

    public boolean isRazresena() {
        return razresena;
    }

    @Override
    public String toString() {
        String a;
        if(razresena) {
            a = "[X] ";
        } else {
            a = "[ ] ";
        }
        a = a + "(" + labela +") "+korisnickoIme +": " +naslov+'\n'+sadrzaj;
        return a;
    }
}
