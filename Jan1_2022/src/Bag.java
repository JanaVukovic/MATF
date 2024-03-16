public class Bag extends Stavka implements Comparable<Bag>{
    int id, ozbiljnost;
    String zaduzen;

    public Bag(String korisnickoIme, String naslov, String sadrzaj, int id, int ozbiljnost, String zaduzen) {
        super(korisnickoIme, naslov, sadrzaj);
        this.id = id;
        this.ozbiljnost = ozbiljnost;
        this.zaduzen = zaduzen;
    }
    void zaduzi(String a){
        this.zaduzen = a;
    }

    public int getId() {
        return id;
    }

    public int getOzbiljnost() {
        return ozbiljnost;
    }

    public String getZaduzen() {
        if(zaduzen.isEmpty())return "Bag nije dodeljen nijednom programeru!";
        return zaduzen;
    }

    @Override
    public String toString() {
        StringBuilder string = new StringBuilder("(!"+id+" " + ozbiljnost);
        if(zaduzen.isEmpty())string.append(")");
        else string.append(" " + zaduzen + ")");
        string.append(super.toString());
        return String.valueOf(string);
    }

    @Override
    public int compareTo(Bag o) {
        if((razresena && o.isRazresena())||(!(razresena && o.isRazresena()))){
            if(ozbiljnost > o.getOzbiljnost()) return 1;
            else if(ozbiljnost == o.getOzbiljnost()) return 0;
            return -1;
        }
        if(razresena) return -1;
        else return 1;
    }
}
