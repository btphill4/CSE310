import java.util.*;
 class bstValidity {
      public static void main(String[] args) {
        //intro
        System.out.println("\n\nWelcome to yeet's tool for valid BST detection!");
        ArrayList<String> violations = new ArrayList<String>();
        System.out.println("To start, please enter how many elements your (potential) BST has:\n");
        Scanner kb = new Scanner(System.in);
        int arrayLength = kb.nextInt();
        int[] array = new int[arrayLength];
        int[] greaterThan = new int[arrayLength];
        int[] lessThan = new int[arrayLength];
        System.out.println("Great! Now please enter the values in the order they appear.");

        for (int i = 0; i < arrayLength; i++) {
          int a = kb.nextInt();
          array[i] = a;
        }

        System.out.print("Great! The potential BST currently looks like this:\n {");    
        for (int i = 0; i < arrayLength; i++) {
          if (i != arrayLength -1) System.out.print(array[i] + ", ");
          else System.out.print(array[i]);
        }
        System.out.println("}");
        boolean validBST = true;
        int numLessThan = 0;
        int numGreaterThan = 0;
         int  ltindex = 0;
         int  gtindex = 0;
        for (int i = 0; i < arrayLength - 1; i++) {
          int curNum = array[i];
          for (int l = 0; l < ltindex+1; l++) {
            if (curNum > lessThan[l] && lessThan[l] != 0) {
              validBST = false;
              violations.add("" + curNum + " > " + lessThan[l] + " \n");
              break;
            }
          }
          for (int g = 0; g < gtindex +1; g++) {
            if (curNum < greaterThan[g] && greaterThan[g] != 0) {
               violations.add("" + curNum + " < " + greaterThan[g] + " \n");
              validBST = false;
              break;
            }
          }
          if (curNum < array[i+1]) {
            greaterThan[++gtindex] = curNum;
          }
          else {
            lessThan[++ltindex] = curNum;
          }

        }

        //one final check for the last element;
        int curNum = array[arrayLength -1];
                  for (int l = 0; l < ltindex+1; l++) {
            if (curNum > lessThan[l] && lessThan[l] != 0) {
              validBST = false;
              violations.add("" + curNum + " > " + lessThan[l] + " \n");
              break;
            }
          }
          for (int g = 0; g < gtindex +1; g++) {
            if (curNum < greaterThan[g] && greaterThan[g] != 0) {
              violations.add("" + curNum + " < " + greaterThan[g] + " \n");
              validBST = false;
              break;
            }
          }




        if (validBST) System.out.println("Valid BST!");
        else {
          System.out.println("Invalid BST!\nThe following violations were found:\n");
          for (String s : violations) System.out.print(s);
          
        }
        
      }
 }