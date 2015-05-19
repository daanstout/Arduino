package arduino;

public class main {
    public static void main(String[] args) throws Exception{
        Connectie connect = new Connectie();
        Besturing bestuur = new Besturing(connect);
        
        if(connect.initialize()){
            bestuur.ledAan();
            bestuur.ledUit();
            bestuur.ledBlink();
            connect.close();
        }
        
        try{
            Thread.sleep(2000);
        }
        catch (InterruptedException ie){
        }
    }
}