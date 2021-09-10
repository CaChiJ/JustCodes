import java.io.IOException;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        br.close();

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String stars = "*".repeat(N);
        String spaces = " ".repeat(N);
        for (int i = 0; i < N; ++i) {
            bw.write(spaces, 0, i);
            bw.write(stars, 0, N - i);
            bw.newLine();
        }

        bw.flush();
        bw.close();
    }
}