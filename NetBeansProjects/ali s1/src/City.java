public class City {
    private String cityName;
    private int cityPopulation;
    private int registeredVoters;
    private boolean isCapital = false;
    static private int totalCities;
    
    public City(String cn, int cp){
        this.cityName = cn;
        this.setCityPopulation(cp);
        this.setRegisteredVoters();
        this.setIsCapital();
        totalCities++;
    }
    public City(String cn){
        this.cityName = cn;
        this.cityPopulation = 1000000;
        this.setRegisteredVoters();
        this.setIsCapital();
        totalCities++;
    }
    
    public String toString(){
        return String.format("Name: %s, Population: %d, Registed voters: %d, Capital: %b, No. of cities: %d", this.getCityName(), this.getCityPopulation(), this.getRegisteredVoters(), this.isCapital, this.totalCities);
    }

    public String getCityName() {
        return cityName;
    }
    public void setCityName(String cityName) {
        this.cityName = cityName;
    }

    public int getCityPopulation() {
        return cityPopulation;
    }
    public void setCityPopulation(int cityPopulation) {
        if(cityPopulation > 0){
            this.cityPopulation = cityPopulation;
        }
    }

    public int getRegisteredVoters() {
        return registeredVoters;
    }
    public void setRegisteredVoters() {
        this.registeredVoters = (int) (0.15 * this.cityPopulation);
    }

    public boolean isIsCapital() {
        return isCapital;
    }
    public void setIsCapital() {
        if(this.cityName.equalsIgnoreCase("islamabad")){
            this.isCapital = true;
        }
    }

    public static int getTotalCities() {
        return totalCities;
    }
    public static void setTotalCities(int aTotalCities) {
        totalCities = aTotalCities;
    }   
}