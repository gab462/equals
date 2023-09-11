template <typename T>
struct opt {
  bool ok;
  T data;

  opt (T obj);
  opt ();

  auto operator* () -> T&;
};
