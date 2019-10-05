import java.util.*;
import java.math.BigInteger;

class Main {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    BigInteger a = in.nextBigInteger();
    BigInteger b = in.nextBigInteger();

    // Addition
    System.out.println(a.add(b));
    // Division
    System.out.println(a.divide(b));
    // GCD
    System.out.println(a.gcd(b));
    // Mod
    System.out.println(a.mod(b));
    // Modulo arithmetic: compute value of (a^b) mod n
    BigInteger n = in.nextBigInteger();
    System.out.println(a.modPow(b, n));
  }
}

// javac Java_BigInteger.java
// java Main
