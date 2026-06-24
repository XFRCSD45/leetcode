class Solution {
public:
    static const long long MOD = 1000000007LL;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(const Matrix& A, const Matrix& B) {
        int n = A.size();
        Matrix C(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;

                long long aik = A[i][k];
                for (int j = 0; j < n; j++) {
                    if (B[k][j] == 0) continue;

                    C[i][j] = (C[i][j] + aik * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    Matrix power(Matrix base, long long exp) {
        int n = base.size();

        Matrix res(n, vector<long long>(n, 0));
        for (int i = 0; i < n; i++) res[i][i] = 1;

        while (exp > 0) {
            if (exp & 1) res = multiply(base, res);
            base = multiply(base, base);
            exp >>= 1;
        }
        return res;
    }

    vector<long long> multiplyMatVec(const Matrix& A,
                                     const vector<long long>& v) {
        int n = A.size();
        vector<long long> res(n, 0);

        for (int i = 0; i < n; i++) {
            long long cur = 0;
            for (int j = 0; j < n; j++) {
                cur = (cur + A[i][j] * v[j]) % MOD;
            }
            res[i] = cur;
        }
        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        int S = 2 * m;

        Matrix T(S, vector<long long>(S, 0));


        for (int x = 0; x < m; x++) {

            for (int y = 0; y < x; y++) {
                T[x][m + y] = 1;
            }

            for (int y = x + 1; y < m; y++) {
                T[m + x][y] = 1;
            }
        }

        vector<long long> state2(S, 0);

        for (int x = 0; x < m; x++) {
            state2[x] = x;
            state2[m + x] = m - 1 - x;
        }

        Matrix P = power(T, n - 2);
        vector<long long> finalState = multiplyMatVec(P, state2);

        long long ans = 0;
        for (long long v : finalState) {
            ans = (ans + v) % MOD;
        }

        return (int)ans;
    }
};