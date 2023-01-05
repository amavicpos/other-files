class Language {
    protected String name;
    protected int numSpeakers;
    protected String regionsSpoken;
    protected String wordOrder;

    public Language(String name, int numSpeakers, String regionsSpoken, String wordOrder) {
        this.name = name;
        this.numSpeakers = numSpeakers;
        this.regionsSpoken = regionsSpoken;
        this.wordOrder = wordOrder;
    }

    public void getInfo() {
        System.out.println(name + " is spoken by " + numSpeakers + " people mainly in " + regionsSpoken +
                ".\nThe language follows the word order: " + wordOrder + ".");
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setNumSpeakers(int num) {
        this.numSpeakers = num;
    }

    public void setRegionsSpoken(String region) {
        this.regionsSpoken = region;
    }

    public void setWordOrder(String order) {
        this.wordOrder = order;
    }

    public static void main(String[] args) {
        Language Basque = new Language("Basque", 750000, "Basque Country",
                "subject-object-verb");
        Language Chontal = new Mayan("Chontal", 36810);
        Language Chinese = new SinoTibetan("Mandarin Chinese", 920000000);
        Language Burmese = new SinoTibetan("Burmese", 33000000);

        Language[] languages = {Basque, Chontal, Chinese, Burmese};
        for (Language language: languages) {
            language.getInfo();
        }

        Basque.setRegionsSpoken("Spain, France");
    }
}
