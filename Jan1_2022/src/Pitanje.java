public class Pitanje extends Stavka implements Comparable<Pitanje>{
    String odgovor;

    public Pitanje(String korisnickoIme, String naslov, String sadrzaj) {
        super(korisnickoIme, naslov, sadrzaj);
    }
    public String razresi(String odg){
        razresi();
        this.odgovor = odg;
    }

    public String getOdgovor() {
        if(razresena)return odgovor;
        else return "Pitanje nema odgovor!";
    }

    @Override
    public String toString() {
        String a = "(?) " + super.toString();
        if(razresena) return a + " - " + odgovor;
        return a;
    }

    @Override
    public int compareTo(Pitanje o) {
        if(razresena && o.isRazresena()) return 0;
        if(!(razresena && o.isRazresena()))return 0;
        if(razresena)return 1;
        return -1;
    }
}
