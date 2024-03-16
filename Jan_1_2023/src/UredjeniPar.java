public class UredjeniPar<T1, T2> {
    T1 prvi;
    T2 drugi;

    public UredjeniPar(T1 prvi, T2 drugi) {
        this.prvi = prvi;
        this.drugi = drugi;
    }

    public T1 getPrvi() {
        return prvi;
    }

    public T2 getDrugi() {
        return drugi;
    }

    public void setPrvi(T1 prvi) {
        this.prvi = prvi;
    }

    public void setDrugi(T2 drugi) {
        this.drugi = drugi;
    }
}
