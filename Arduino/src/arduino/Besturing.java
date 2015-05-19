package arduino;

public class Besturing {
    private Connectie c;
    
    public Besturing(Connectie c){
        this.c = c;
    }
    
    // plaats hier je functies
    
    public void rechts(){
        c.sendData("rechts");
        try{
            Thread.sleep(2000);
        }catch (InterruptedException ie){}
    }
    
    public void links(){
        c.sendData("links");
        try{
            Thread.sleep(2000);
        }catch (InterruptedException ie){}
    }
    
    public void start(){
        c.sendData("start");
        try{
            Thread.sleep(2000);
        }catch (InterruptedException ie){}
    }
    
    public void stop(){
        c.sendData("stop");
        try{
            Thread.sleep(2000);
        }catch (InterruptedException ie){}
    }
}
