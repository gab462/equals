struct command {
  const char* program;
  vector<const char*> args;

  command ();
  template <typename ...A> command (const char* c, A... a);

  auto execute () -> void;
};

struct build_config {
  const char* compiler;
  list<const char*> files;
  list<string> flags;
  list<string> includes;
  list<string> libraries;
  list<string> macros;

  auto set_compiler (const char* cxx) -> void;
  auto add_file (const char* file);
  auto add_flag (string_view flag) -> void;
  auto include (string_view directory) -> void;
  auto link (string_view library) -> void;
  auto define (string_view macro) -> void;
  auto run () -> void;
};
