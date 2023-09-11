template <typename T>
struct arg {
  T data;
  char option;
};

struct arg_parser {
  lst<str_view> inputs;
  lst<arg<bool>> flags;
  lst<arg<int>> int_options;
  lst<arg<str_view>> str_options;

  auto input () -> str_view&;
  auto flag (char option, bool default_value = false) -> bool&;
  auto int_option (char option, int default_value = 0) -> int&;
  auto string_option (char option, str_view default_value = "") -> str_view&;
  auto parse (int argc, char** argv) -> void;
};
