class Student{
    public String name;
    public Course[] coureses = new Course[5];
    public double AverageGPA;
    coureses[0].setDate("Math",4,71.5);
    public void setGPA(){
        int i=0;
        for(i=0;i<5;i++){

                if(coureses[i].CourseScore>=85){
                    coureses[i].CourseGPA = 4;
                }
                else if(coureses[i].CourseScore>=75){
                    coureses[i].CourseGPA = 3;
                }
                else if(coureses[i].CourseScore>=60){
                    coureses[i].CourseGPA = 2;
                }
                else if (coureses[i].CourseScore>=45){
                    coureses[i].CourseGPA = 1;
                }
                else{
                    coureses[i].CourseGPA = 0;
                }
            
        }
        
    }
    public void CalculateAverageGPA(){
        int i=0;
        double sum = 0;
        double f = 0;
        for(i=0;i<5;i++)
        {
            sum = sum + coureses[i].CourseGPA * coureses[i].CourseXuefen;
            f = f + coureses[i].CourseXuefen;
        }
        this.AverageGPA = sum / f;   
    }
    

    // public Student(String name,String CourseName,double CourseXuefen,double CourseScore){
    //     this.name = name;
    //     this.coureses[0].CourseXuefen = CourseXuefen;
    //     this.coureses[0].CourseScore = CourseScore;
    // }
    // public Student(){

    // }
    

}

