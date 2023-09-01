struct command {
  const char* program;
  vector<const char*> args;

  command ();
  template <typename ...A> command (const char* c, A... a);

  auto execute () -> void;
};
