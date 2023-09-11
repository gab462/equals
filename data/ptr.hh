template <typename T>
struct ptr {
  T* data;

  template <typename ...A> ptr (A... args);
  ptr (T obj);
  ptr (ptr const& other);
  ~ ptr ();

  auto operator* () -> T&;
  auto operator= (ptr const& other) -> void;
};
