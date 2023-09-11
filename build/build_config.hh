struct build_config { // Unibuild
  const char* compiler = "c++";
  const char* standard = "17";
  const char* entry;
  lst<const char*> flags;
  lst<str> includes;
  lst<str> libraries;
  lst<str> macros;

  explicit build_config (const char* file);

  auto include (str_view directory) -> void;
  auto link (str_view library) -> void;
  auto define (str_view macro) -> void;
  auto run () -> void;
};
