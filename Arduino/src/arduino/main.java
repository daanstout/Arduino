package arduino;

public class main {
    public static void main(String[] args) throws Exception{
        Connectie connect = new Connectie();
        Besturing bestuur = new Besturing(connect);
        
        if(connect.initialize()){
            bestuur.omhoog();
            bestuur.start(2000);
            bestuur.stop();
            bestuur.omlaag();
            bestuur.start(2000);
            bestuur.stop();
            connect.close();
        }
        
        try{
            Thread.sleep(2000);
        }catch (InterruptedException ie){}
    }
}