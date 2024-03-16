import java.util.Collections;
import java.util.List;
import java.util.Set;
import java.util.TreeSet;

public class SkupBagova implements KolekcijaStavki<Bag>{
    Set<Bag> skup = new TreeSet<>();
    @Override
    public List<Bag> listaj() {
        return skup.stream().toList();
    }
    @Override
    public boolean dodaj(Bag a) {
        int id = a.getId();
        for(Bag b : skup){
            if(b.getId() == id)return false;
        }
        skup.add(a);
        return true;
    }
    @Override
    public void sortiraj() {
        return;
    }
}
