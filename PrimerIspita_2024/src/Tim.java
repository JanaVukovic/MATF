public class Tim implements Comparable<Tim>{
    String ime;
    int poeni;
    boolean diskvalifikovan;

    public Tim(String ime, int poeni) {
        this.ime = ime;
        this.poeni = poeni;
        diskvalifikovan = poeni == -1;
    }

    public String getIme() {
        return ime;
    }

    public int getPoeni() {
        return poeni;
    }

    public boolean isDiskvalifikovan() {
        return diskvalifikovan;
    }

    @Override
    public int compareTo(Tim o) {
        if(this.getPoeni() == o.getPoeni())return this.getIme().compareTo(o.getIme());
        return (this.getPoeni() - o.getPoeni());
    }

    @Override
    public String toString() {
        if(isDiskvalifikovan())
            return ime + " d";
        else
            return ime + " " + poeni;
    }
}
