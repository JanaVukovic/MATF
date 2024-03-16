import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public interface KolekcijaStavki<T extends Stavka>{
    List<T> listaj();
    boolean dodaj(T a);
    void sortiraj();
}
