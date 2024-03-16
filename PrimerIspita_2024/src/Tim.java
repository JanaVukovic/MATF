import java.util.Comparator;

public class Tim implements Comparable<Tim>{
    String ime;
    int poeni;
    boolean diskvalifikovan;

    public Tim(String ime, int poeni) {
        this.ime = ime;
        this.poeni = poeni;
        if(poeni != -1)
            diskvalifikovan = false;
        else diskvalifikovan = true;
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
