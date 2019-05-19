class Book {
    String Title;
    Date Pdate = new Date();
    int Words;
    double date_num;

    public double setDatenum(){
        if(Pdate.Month >= 7)
            date_num = 1.18;
        else
            date_num = 1.2;
        return date_num;
    }
    
    public double getPrice(){
        return (Words / 1000 * 35 * date_num);
    }

    public Book(String Title,int Year,int Month,int Day,int Words){
        this.Title = Title;
        this.Pdate.setDate(Year,Month,Day);
        this.Words = Words;
    }
    public Book(){
        this.Title = "";
        this.Pdate.setDate(0,0,0);
        this.Words = 0;
    }
    

}

