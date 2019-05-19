class CCircle
{
    double pi;    
    double radius;
    double getRadius(){
        return radius;
    } 
    //实例化圆的面积
    double getSquare(){
        return pi*radius*radius;
    }
    void setCircle(double r, double p){     
        pi=p;
        radius=r;   
   }
}