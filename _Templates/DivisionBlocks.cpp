for (i64 l = 1, r = 0; l <= n; l = r + 1) {
    i64 res = n / l;
    r = min(n, n / res);
    // in [l, r] :
    
}