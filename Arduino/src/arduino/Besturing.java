package arduino;

public class Besturing {
    private Connectie c;
    
    public Besturing(Connectie c){
        this.c = c;
    }
    
    // plaats hier je functies
    
    public void omhoog(){
        c.sendData("u");
        try{
            Thread.sleep(2000);
        }catch (InterruptedException ie){}
    }
    
    public void omlaag(){
        c.sendData("d");
        try{
            Thread.sleep(2000);
        }catch (InterruptedException ie){}
    }
    
    public void start(int delay){
        c.sendData("g");
        try{
            Thread.sleep(delay);
        }catch (InterruptedException ie){}
    }
    
    public void stop(){
        c.sendData("s");
        try{
            Thread.sleep(2000);
        }catch (InterruptedException ie){}
    }
}
