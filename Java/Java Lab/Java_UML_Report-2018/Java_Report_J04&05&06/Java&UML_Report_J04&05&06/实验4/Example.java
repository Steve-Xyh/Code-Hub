class People
{
    protected double weight,height;

    public void speakHello(){
        System.out.println("yayawawa");
    }
    public void averageHeight()
    {
        height=173;
        System.out.println("average height:"+height);
    }
    public void averageWeight()
    {
        weight = 70;
        System.out.println("average weight:"+weight);
    }
}

class ChinaPeople extends People
{
	// [����1]//��дpublic void speakHello()������Ҫ�����"��ã��Է�����"������Ϣ
	// [����2]//��дpublic void averageHeight()������Ҫ�����"�й��˵�ƽ����ߣ�173.0����"������Ϣ
    // [����3]//��дpublic void averageWeight()������Ҫ�����"�й��˵�ƽ�����أ�67.34����"������Ϣ
    public void speakHello(){
        System.out.println("��ã��Է�����");
    }
    public void averageHeight()
    {
        height=173;
        System.out.println("�й��˵�ƽ�����:"+height+"����");
    }
    public void averageWeight()
    {
        weight = 67.34;
        System.out.println("�й��˵�ƽ������:"+weight+"����");
    }
	public void chinaGongfu()
	{
        // [����4]//����й�������Ϣ�����磺"�����ӣ�վ���ɣ�˯�繭"
        System.out.println("�й�����:�����ӣ�վ���ɣ�˯�繭");
	}
}

class AmericanPeople extends People
{
	// [����5]//��дpublic void speakHello()������Ҫ�����"How do you do"
	// [����6]//��дpublic void averageHeight()����
    // [����7]//��дpublic void averageWeight()����
    public void speakHello(){
        System.out.println("How do you do?");
    }
    public void averageHeight()
    {
        height=178;
        System.out.println("�����˵�ƽ�����:"+height+"����");
    }
    public void averageWeight()
    {
        weight = 70.23;
        System.out.println("�����˵�ƽ������:"+weight+"����");
    }
	public void americanBoxing()
	{
    // [����8]//���ȭ����Ϣ�����磺"ֱȭ����ȭ"
        System.out.println("������:ֱȭ����ȭ");
	}
}

class BeijingPeople extends ChinaPeople
{
	// [����9]//��дpublic void speakHello()������Ҫ�����"���ã������Ǳ���"
	// [����10]//��дpublic void averageHeight()����
    // [����11]//��дpublic void averageWeight()����
    public void speakHello(){
        System.out.println("���ã������Ǳ���");
    }
    public void averageHeight()
    {
        height=172.5;
        System.out.println("�����˵�ƽ�����:"+height+"����");
    }
    public void averageWeight()
    {
        weight = 68.23;
        System.out.println("�����˵�ƽ������:"+weight+"����");
    }
	public void beijingOpera()
	{
        // [����12]//���������Ϣ�����磺"��������"
        System.out.println("������ɫ:��������");
	}
}

public class Example
{
	public static void main(String args[])
	{
		ChinaPeople chinaPeople = new ChinaPeople();
		AmericanPeople americanPeople = new AmericanPeople();
		BeijingPeople beijingPeople = new BeijingPeople();
		chinaPeople.speakHello();
        americanPeople.speakHello();
        beijingPeople.speakHello();
		chinaPeople.averageHeight();
		americanPeople.averageHeight();
		beijingPeople.averageHeight();
		chinaPeople.averageWeight();
		americanPeople.averageWeight();
	    beijingPeople.averageWeight();
        chinaPeople.chinaGongfu();
        americanPeople.americanBoxing();
        beijingPeople.beijingOpera();
        beijingPeople.chinaGongfu();
	}
}
