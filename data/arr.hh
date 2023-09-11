template <typename T, size_t N>
struct arr {
  T data[N];

  auto operator[] (size_t n) -> T&;

  auto begin () -> T*;
  auto end () -> T*;

  auto size () -> size_t;
};
