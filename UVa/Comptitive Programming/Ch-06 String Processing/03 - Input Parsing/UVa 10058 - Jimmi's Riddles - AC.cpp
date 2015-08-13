import java.io.*;
 
class Main {
  private static final String VERB = "(hate|love|know|like)s*";
  private static final String NOUN = "(tom|jerry|goofy|mickey|jimmy|dog|cat|mouse)";
  private static final String ARTICLE = "(a|the)";
  private static final String ACTOR = "(" + NOUN + "|" + ARTICLE + " " + NOUN + ")";
  private static final String ACTIVE_LIST = "(" + ACTOR + " and )*" + ACTOR;
  private static final String ACTION = ACTIVE_LIST + " " + VERB + " " + ACTIVE_LIST;
  private static final String STATEMENT = ACTION + "( , " + ACTION + ")*";
 
  public static void main(String args[]) throws Exception {
    BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
    String riddle;
    while ((riddle = sc.readLine()) != null) {
      // There is always space before and after a comma (,). Therefore, it is optional to clean up input with
      // replaceAll() and trim().
      System.out.println(riddle.replaceAll(" +", " ").trim().matches(STATEMENT) ? "YES I WILL" : "NO I WON'T");
    }
  }
}
