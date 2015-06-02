package arduino;

public class Besturing {
    private Connectie c;
    
    public Besturing(Connectie c){
        this.c = c;
    }
    
    // plaats hier je functies
    
    public void sendString(String d){
        c.sendData(d);
        try{
            Thread.sleep(2000);
        }catch (InterruptedException ie){}
    }
    
    public void TSPLiftUp(int hoeveel){
        c.sendData("TSPLiftUp");
        try{
            Thread.sleep(2000);
        }catch (InterruptedException ie){}
        c.sendData(Integer.toString(hoeveel));
        try{
            Thread.sleep(2000);
        }catch (InterruptedException ie){}
    }
    
    public void TSPLiftDown(int hoeveel){
        c.sendData("TSPLiftDown");
        try{
            Thread.sleep(2000);
        }catch (InterruptedException ie){}
        c.sendData(Integer.toString(hoeveel));
        try{
            Thread.sleep(2000);
        }catch (InterruptedException ie){}
    }
    
    public void TSPCarLeft(int hoeveel){
        c.sendData("TSPCarLeft");
        try{
            Thread.sleep(2000);
        }catch (InterruptedException ie){}
        c.sendData(Integer.toString(hoeveel));
        try{
            Thread.sleep(2000);
        }catch (InterruptedException ie){}
    }
    
    public void TSPCarRight(int hoeveel){
        c.sendData("TSPCarRight");
        try{
            Thread.sleep(2000);
        }catch (InterruptedException ie){}
        c.sendData(Integer.toString(hoeveel));
        try{
            Thread.sleep(2000);
        }catch (InterruptedException ie){}
    }
    
    public void TSPServoIn(){
        c.sendData("ServoIn");
        try{
            Thread.sleep(2000);
        }catch (InterruptedException ie){}
    }
    
    public void TSPServoOut(){
        c.sendData("ServoOut");
        try{
            Thread.sleep(2000);
        }catch (InterruptedException ie){}
    }
    
    public void BBPBandLeft(){
        c.sendData("BBPBandLeft");
        try{
            Thread.sleep(2000);
        }catch (InterruptedException ie){}
    }
    
    public void BBPBandRight(){
        c.sendData("BBPBandRight");
        try{
            Thread.sleep(2000);
        }catch (InterruptedException ie){}
    }
    
    public void BBPTrainUp(){
        c.sendData("BBPTrainUp");
        try{
            Thread.sleep(2000);
        }catch (InterruptedException ie){}
    }
    
    public void BBPTrainDown(){
        c.sendData("BBPTrainDown");
        try{
            Thread.sleep(2000);
        }catch (InterruptedException ie){}
    }
}
