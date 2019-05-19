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
	// [代码1]//重写public void speakHello()方法，要求输出"你好，吃饭了吗"汉语信息
	// [代码2]//重写public void averageHeight()方法，要求输出"中国人的平均身高：173.0厘米"汉语信息
    // [代码3]//重写public void averageWeight()方法，要求输出"中国人的平均体重：67.34公斤"汉语信息
    public void speakHello(){
        System.out.println("你好，吃饭了吗");
    }
    public void averageHeight()
    {
        height=173;
        System.out.println("中国人的平均身高:"+height+"厘米");
    }
    public void averageWeight()
    {
        weight = 67.34;
        System.out.println("中国人的平均体重:"+weight+"公斤");
    }
	public void chinaGongfu()
	{
        // [代码4]//输出中国武术信息，例如："坐如钟，站如松，睡如弓"
        System.out.println("中国武术:坐如钟，站如松，睡如弓");
	}
}

class AmericanPeople extends People
{
	// [代码5]//重写public void speakHello()方法，要求输出"How do you do"
	// [代码6]//重写public void averageHeight()方法
    // [代码7]//重写public void averageWeight()方法
    public void speakHello(){
        System.out.println("How do you do?");
    }
    public void averageHeight()
    {
        height=178;
        System.out.println("美国人的平均身高:"+height+"厘米");
    }
    public void averageWeight()
    {
        weight = 70.23;
        System.out.println("美国人的平均体重:"+weight+"公斤");
    }
	public void americanBoxing()
	{
    // [代码8]//输出拳术信息，例如："直拳、勾拳"
        System.out.println("美国格斗:直拳、勾拳");
	}
}

class BeijingPeople extends ChinaPeople
{
	// [代码9]//重写public void speakHello()方法，要求输出"您好，这里是北京"
	// [代码10]//重写public void averageHeight()方法
    // [代码11]//重写public void averageWeight()方法
    public void speakHello(){
        System.out.println("您好，这里是北京");
    }
    public void averageHeight()
    {
        height=172.5;
        System.out.println("北京人的平均身高:"+height+"厘米");
    }
    public void averageWeight()
    {
        weight = 68.23;
        System.out.println("北京人的平均体重:"+weight+"公斤");
    }
	public void beijingOpera()
	{
        // [代码12]//输出京剧信息，例如："京剧术语"
        System.out.println("北京特色:京剧术语");
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
