class Date {
    int Year;
    int Month;
    int Day;
    
    public Date(){
        Year = 0;
        Month = 0;
        Day = 0;
    }
    public Date(int Year,int Month,int Day){
        this.Year = Year;
        this.Month = Month;
        this.Day = Day;
    }

    public void setDate(int Year,int Month,int Day ){
        this.Year = Year;
        this.Month = Month;
        this.Day = Day;
    }
}