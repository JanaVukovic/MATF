public enum PolDeteta {
        MUSKI('M'),
        ZENSKI('Z');
        private final char Skracenica;
        private PolDeteta(char Skracenica){
            this.Skracenica = Skracenica;
        }
        public static PolDeteta odSkracenice(char Skracenica){
            switch(Skracenica){
                case 'Z': return ZENSKI;
                case 'M': return MUSKI;
                default: return ZENSKI;
            }
        }

    public char getSkracenica() {
        return Skracenica;
    }
}
