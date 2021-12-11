
public class test {
    public static void main(String[] args) {
//        writeFiles.clearFiles();
//        for(int i=0; i<4; i++){
//            writeFiles.writeTransFile();
//            writeFiles.writeMasterFile();
//        }

        FileMatch.perform_match();
        System.out.print("------- OLD MASTER -------");
        FileMatch.read_file("oldmast.txt");
        System.out.print("\n------- NEW MASTER -------");
        FileMatch.read_file("newMast.txt");
        System.out.println("\n------- TRANS -------");
        FileMatch.read_file("trans.txt");
        System.out.println("\n------- LOG -------");
        FileMatch.read_file("log.txt");
    }
}
