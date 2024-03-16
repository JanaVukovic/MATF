import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class ListaPitanja implements KolekcijaStavki<Pitanje>{
    public List<Pitanje> pitanja = new ArrayList<>();
    @Override
    public List listaj() {
        return pitanja;
    }

    @Override
    public boolean dodaj(Pitanje a) {
        pitanja.add(a);
        return true;
    }
    @Override
    public void sortiraj() {
        Collections.sort(pitanja);
    }
}
