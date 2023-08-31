template <typename T>
struct pointer {
  T* data;

  pointer (T obj);
  pointer (pointer const& other);
  ~ pointer ();

  auto operator* () -> T&;
  auto operator= (pointer const& other) -> void;
};
