/**************
 * 
 *  file pcg.h
 *  Created on Wed Mar 15 2023 by
 *  chatgpt 
 * 
 **************/
#include "pcg.h"

vector<double> pcg_solver(const vector<vector<double>>& A, const vector<double>& b, int max_iter, double tol) {
    int n = b.size();
    vector<double> x(n, 0.0);
    vector<double> r = b;
    vector<double> p = r;
    double alpha, beta, rr_old, rr_new;
    
    for (int k = 0; k < max_iter; ++k) {
        rr_old = rr_new;
        rr_new = 0.0;
        for (int i = 0; i < n; ++i) {
            rr_new += r[i] * r[i];
        }
        if (k == 0) {
            p = r;
        } else {
            beta = rr_new / rr_old;
            for (int i = 0; i < n; ++i) {
                p[i] = r[i] + beta * p[i];
            }
        }
        vector<double> Ap(n, 0.0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                Ap[i] += A[i][j] * p[j];
            }
        }
        double pAp = 0.0;
        for (int i = 0; i < n; ++i) {
            pAp += p[i] * Ap[i];
        }
        alpha = rr_new / pAp;
        for (int i = 0; i < n; ++i) {
            x[i] += alpha * p[i];
            r[i] -= alpha * Ap[i];
        }
        if (rr_new < tol * tol) {
            break;
        }
    }
    return x;
}
