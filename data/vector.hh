// TODO: resize (size_t n)

template <typename T>
struct vector {
  T* data;
  size_t length;

  template <typename ...A> vector (A... values);
  vector (vector& other);
  ~ vector ();

  auto operator[] (size_t n) -> T&;
  auto operator= (vector const& other) -> void;

  auto begin () -> T*;
  auto end () -> T*;

  auto size () -> size_t;
  auto in (size_t n) -> optional<T>;
  auto resize (size_t n) -> void;
};
