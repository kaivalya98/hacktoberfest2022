import java.io.*;

public class Palindrome {
  
  public static void main(String args[])throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    System.out.print("Input a number: ");
    int number = Integer.parseInt(br.readLine());
    int sum = 0;
    int r;
	  int temp = number;
    while (number > 0) {
      r = number % 10;
      sum = (sum * 10) + r;
      number = number / 10;    
    }    
    if (temp == sum) {
      System.out.println("It is a Palindrome number");
    } else {
      System.out.println("It is not a Palindrome number");
    }
  }  

}
