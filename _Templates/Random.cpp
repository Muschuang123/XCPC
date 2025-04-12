mt19937_64 rnd(chrono::system_clock::now().time_since_epoch().count());

// t is a random number:
t = rnd();

// the epoch of mt19937_64 is so long
// so we can generate a random array by this:
for (int i = 1; i <= 1e6; i++) {
    a[i] = rnd();
}