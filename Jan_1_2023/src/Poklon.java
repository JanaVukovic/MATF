public abstract class Poklon {
    String naziv, ID;
    int cena;

    public Poklon(String naziv, String ID, int cena) {
        this.naziv = naziv;
        this.ID = ID;
        this.cena = cena;
    }
    public String getNaziv() {
        return naziv;
    }

    public String getID() {
        return ID;
    }

    public int getCena() {
        return cena;
    }
    public abstract boolean prikladanPoklon(PolDeteta polDeteta);

    @Override
    public String toString() {
        return ID + " - " + naziv + ", " + cena + "din";
    }
}
