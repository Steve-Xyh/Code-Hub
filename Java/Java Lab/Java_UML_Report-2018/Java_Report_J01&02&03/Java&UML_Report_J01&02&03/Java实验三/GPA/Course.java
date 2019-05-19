class Course{
    public String CourseName;
    public double CourseXuefen;
    public double CourseScore;
    int CourseGPA;

    public void setDate(String CourseName,double CourseXuefen,double CourseScore){
        this.CourseName  = CourseName;
        this.CourseXuefen = CourseXuefen;
        this.CourseScore = CourseScore;
    }

    public Course(){
        CourseName = " ";
        CourseXuefen = 0;
        CourseScore = 0;
        CourseGPA = 0;
    }
}