template <typename T>
struct pointer {
  T* data;

  pointer (T obj);
  ~ pointer ();

  auto operator* () -> T&;
};
