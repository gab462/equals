// TODO: resize (size_t n)

template <typename T>
struct vec {
  T* data;
  size_t length;

  template <typename ...A> vec (A... values);
  vec (vec& other);
  ~ vec ();

  auto operator[] (size_t n) -> T&;
  auto operator= (vec const& other) -> void;

  auto begin () -> T*;
  auto end () -> T*;

  auto size () -> size_t;
  auto resize (size_t n) -> void;
};
