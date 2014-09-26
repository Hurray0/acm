import java.math.BigDecimal;  
import java.math.BigInteger;  
import java.util.Scanner;  
  
public class Main{  
    BigDecimal sum1 = new BigDecimal("0");  
  
    public static void main(String[] args) {  
        Scanner sc = new Scanner(System.in);  
        BigDecimal s1 = new BigDecimal("0");  
        BigDecimal s2 = new BigDecimal("0");  
        String str;  
        while (sc.hasNext()) {  
  
            str = sc.nextLine();  
            if (str.equals("0")) {  
                break;  
            }  
            s2 = new BigDecimal(str);  
            s1 = s1.add(s2);  
        }  
        System.out.println(s1.toPlainString());  
    }  
}  