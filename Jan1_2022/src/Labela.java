public enum Labela {
    ZA_KASNIJE(1),
    POTREBNO_OBJASNJENJE(1),
    HITNO(2);
    private final int a;
    Labela(int a) {
        this.a = a;
    }
    public static Labela fromInt(int a){
        switch(a){
            case(0): return ZA_KASNIJE;
            case(1): return POTREBNO_OBJASNJENJE;
            case(2): return HITNO;
            default: return HITNO;
        }
    }
}
