package arduino;

public class Besturing {
    private Connectie c;
    
    public Besturing(Connectie c){
        this.c = c;
    }
    
    // plaats hier je functies
    
    public void naarLinks()
    {
        c.sendData("naarLinks");
        try
        {
            Thread.sleep(2000);
        }
        catch (InterruptedException ie)
        {
        }
    }
    
    public void ledAan(){
        c.sendData("ledAan");
        try{
            Thread.sleep(2000);
        }catch(InterruptedException ie){
            
        }
    }
    
    public void ledUit(){
        c.sendData("ledUit");
        try{
            Thread.sleep(2000);
        }catch(InterruptedException ie){
            
        }
    }
    
    public void ledBlink(){
        ledAan();
        ledUit();
        ledAan();
        ledUit();
        
        try{
            Thread.sleep(2000);
        }catch(InterruptedException ie){
            
        }
    }
}
