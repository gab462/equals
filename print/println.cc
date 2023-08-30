auto
print (int value) -> void {
  printf ("%d ", value);
  fflush (stdout);
}

auto
print (string_view s) -> void {
  write (STDOUT_FILENO, s.ptr, s.length);
  write (STDOUT_FILENO, " ", 1);
}

template <typename ...A> auto
println (A... values) -> void {
  (print (values), ...); // FIXME: guaranteed order?

  write (STDOUT_FILENO, "\n", 1);
}
