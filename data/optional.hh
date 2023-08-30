template <typename T>
struct optional {
  bool ok;
  T data;

  optional (T obj);
  optional ();

  auto operator* () -> T&;
};
