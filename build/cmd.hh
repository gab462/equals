struct cmd {
  const char* program;
  vec<const char*> args;

  cmd ();
  template <typename ...A> cmd (const char* c, A... a);

  auto execute () -> void;
};
