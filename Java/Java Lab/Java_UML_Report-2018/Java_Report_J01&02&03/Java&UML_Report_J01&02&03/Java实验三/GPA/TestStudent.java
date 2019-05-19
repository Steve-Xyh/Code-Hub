public class TestStudent{
   public static void main(String args[])   {
        Student A = new Student();
        A.name = "Zhang";
        // A.coureses[0].CourseName = "Math";
        // A.coureses[0].CourseXuefen = 4;
        // A.coureses[0].CourseScore = 71.5;
        // A.coureses[1].CourseName = "English";
        // A.coureses[1].CourseXuefen = 3.5;
        // A.coureses[1].CourseScore = 80.4;
        // A.coureses[1].CourseName = "DataStructure";
        // A.coureses[1].CourseXuefen = 3;
        // A.coureses[1].CourseScore = 95.5;
        A.coureses[0].setDate("Math",4,71.5);
        A.setGPA();
        A.CalculateAverageGPA();
        System.out.println("AverageGPA="+A.AverageGPA);

   }
}