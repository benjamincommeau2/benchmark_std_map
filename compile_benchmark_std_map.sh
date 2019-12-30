if [ $# -eq 0 ]; then
  nerrors=1
else
  nerrors=$1
fi
echo "nerrors=$nerrors"
g++ -std=c++11 -fmax-errors=$nerrors benchmark_std_map.cpp -o benchmark_std_map.out
