package arduino;

public class main {
    public static void main(String[] args) throws Exception{
        Connectie connect = new Connectie();
        Besturing bestuur = new Besturing(connect);
        
        if(connect.initialize()){
            bestuur.rechts();
            bestuur.start();
            bestuur.stop();
            bestuur.links();
            bestuur.start();
            bestuur.stop();
            connect.close();
        }
        
        try{
            Thread.sleep(2000);
        }
        catch (InterruptedException ie){
        }
    }
}