// TODO: resize (size_t n)

template <typename T>
struct vector {
  T* data;
  size_t length;

  template <typename ...A> vector (A... values);
  ~ vector ();

  auto begin () -> T*;
  auto end () -> T*;

  auto size () -> size_t;
  auto operator[] (size_t n) -> T&;
  auto in (size_t n) -> optional<T>;
  auto resize (size_t n) -> void;
};
