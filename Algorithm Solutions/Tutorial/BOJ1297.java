import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.lang.Math;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] s = br.readLine().split(" ");
        int D = Integer.parseInt(s[0]);
        int H = Integer.parseInt(s[1]);
        int W = Integer.parseInt(s[2]);
        br.close();

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        double a = Math.sqrt((D * D) / (double) (H * H + W * W));
        int h = (int) (H * a);
        int w = (int) (W * a);
        bw.write(String.valueOf(h) + ' ' + String.valueOf(w));
        bw.flush();
        bw.close();
    }
}