template <typename T, size_t N>
struct array {
  T data[N];

  auto begin () -> T*;
  auto end () -> T*;

  auto size () -> size_t;
  auto operator[] (size_t n) -> T&;
  auto in (size_t n) -> optional<T>;
};
