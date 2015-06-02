package arduino;

public class main {
    public static void main(String[] args) throws Exception{
        Connectie connect = new Connectie();
        Besturing bestuur = new Besturing(connect);
        
        if(connect.initialize()){
            bestuur.sendString("1");
            while(connect.getOutput() == null){
                
            }
            connect.close();
        }
        String test = connect.getOutput();
        System.out.println("testen "+connect.getOutput());
        if(test != null){
           System.out.println("hi");
        }
        
        try{
            Thread.sleep(2000);
        }catch (InterruptedException ie){}
    }
}