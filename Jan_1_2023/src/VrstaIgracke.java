public enum VrstaIgracke {
    MUSKA('M'),
    ZENSKA('Z'),
    NEUTRALNA('N');
    public char skracenica;

    VrstaIgracke(char skracenica) {
        this.skracenica = skracenica;
    }
    public static VrstaIgracke odSkracenice(char skracenica){
        switch(skracenica){
            case 'Z': return ZENSKA;
            case 'M': return MUSKA;
            case 'N': return NEUTRALNA;
            default: return NEUTRALNA;
        }
    }

    public char getSkracenica() {
        return skracenica;
    }
}
