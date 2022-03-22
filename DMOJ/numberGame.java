import java.util.*;
public class numberGame{
	int ans = -1;
	public static void main(String[] args){
		new numberGame();
	}
	public numberGame(){
		Scanner scan = new Scanner(System.in);
		long n = scan.nextLong();
		// O(logN) sol
		solve(n, "0");
		System.out.println(ans);
		// O(N) sol
		// int sum = 0;
		// for (long i = 0; i <= n; i++){
		// 	boolean invalid=false;
		// 	for (char c : String.valueOf(i)){
		// 		if (c != '2' && c != '3') invalid=true;
		// 	}
		// 	if (!invalid) sum++;
		// }
		// System.out.println(sum);
	}
	public void solve(long n, String num){
		if (Long.parseLong(num) > n) return;
		if (num.equals("0")) num="";
		solve(n, num+"2");
		solve(n, num+"3");
		ans++;
	}
}