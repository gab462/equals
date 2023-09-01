struct command {
  const char* program;
  vector<const char*> args;

  command ();
  template <typename ...A> command (const char* c, A... a);

  auto execute () -> void;
};

struct build_config { // Unibuild
  const char* compiler = "c++";
  const char* standard = "17";
  const char* entry;
  list<const char*> flags;
  list<string> includes;
  list<string> libraries;
  list<string> macros;

  build_config (const char* file);

  auto include (string_view directory) -> void;
  auto link (string_view library) -> void;
  auto define (string_view macro) -> void;
  auto run () -> void;
};
