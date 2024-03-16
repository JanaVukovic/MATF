import java.util.Collection;
import java.util.Collections;
import java.util.Comparator;
import java.util.Optional;

public class MaxFinder<T> implements GenericMax{
    public Comparator<T> comparator;

    public MaxFinder(Comparator<T> comparator) {
        this.comparator = comparator;
    }

    public MaxFinder() {
    }

    @Override
    public Optional findMax(Collection collection, Comparator comparator) {
        Optional<T> rezultat;
        if(collection.isEmpty()) rezultat = Optional.empty();
        else{
            T max = (T) Collections.max(collection, comparator);
            rezultat = Optional.of(max);
        }
        return rezultat;
    }

    @Override
    public Optional findMax(Collection collection) {
        if(comparator == null)
            throw new RuntimeException("Comparator nije prosledjen");
        else return findMax(collection, this.comparator);
    }
}
