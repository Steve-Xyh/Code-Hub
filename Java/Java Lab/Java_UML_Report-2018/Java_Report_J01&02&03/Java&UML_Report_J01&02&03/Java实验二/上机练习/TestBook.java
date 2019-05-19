public class TestBook{
   public static void main(String args[])   {
      Book A = new Book("Computer",2018,6,30,2000);
      // Book A = new Book();
      // A.Title = "Computer";
      // A.Pdate.Year = 2018;
      // A.Pdate.Month = 6;
      // A.Pdate.Day = 30;
      System.out.println("Title="+A.Title);
      System.out.println("Datenum="+A.setDatenum());
      System.out.println("Words="+A.Words);
      A.setDatenum();
      System.out.println("Price="+A.getPrice());

   }
}