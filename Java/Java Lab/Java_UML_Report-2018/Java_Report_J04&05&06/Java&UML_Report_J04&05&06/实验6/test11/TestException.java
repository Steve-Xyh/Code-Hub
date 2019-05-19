class UserException extends Exception{
    private int idnumber;
    public UserException(String message,int id){
      super(message);
      this.idnumber=id;}
    public int getId(){
      return idnumber;
     }
   }
public class TestException {
   public void regist(int num) throws UserException{
     if(num<0){
        throw new UserException("����Ϊ��ֵ��������",3);
     }
     System.out.println("�Ǽ�����: "+num);
   }
   public void manager(){
   try{
      regist(-100);
   }catch(UserException e){
      System.out.println("�Ǽǳ������"+e.getId());
   }
   System.out.println("���εǼǲ�������");
   }
   public static void main(String[] args) {
    TestException t=new TestException();
    t.manager();
   }
 }
