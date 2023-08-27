auto
argument_parser :: input () -> string_view& {
  return this->inputs.append ({});
}

auto
argument_parser :: flag (char option, bool default_value) -> bool& {
  return this->flags.append ({
    default_value,
    option,
  }).data;
}

auto
argument_parser :: int_option (char option, int default_value) -> int& {
  return this->int_options.append ({
    default_value,
    option,
  }).data;
}

auto
argument_parser :: string_option (char option, string_view default_value) -> string_view& {
  return this->string_options.append ({
    default_value,
    option,
  }).data;
}

auto
argument_parser :: parse (int argc, char** argv) -> void {
  size_t input_n = 0;

  for (int i = 1; i < argc; ++i) {
    string_view arg = argv[i];

    if (arg.data[0] != '-') {
      assert (input_n < this->inputs.size () && "Too many arguments");

      this->inputs[input_n++] = arg;
    } else {
      // FIXME: Less ugly way to do this

      bool processed = false;

      for (auto& option: this->flags) {
        if (arg.data[1] == option.option) {
          option.data = !option.data;

          processed = true;
          break;
        }
      }

      if (processed)
        continue;

      for (auto& option: this->int_options) {
        if (arg.data[1] == option.option) {
          assert (i + 1 < argc && "Option provided without value");

          string_view value = argv[++i];
          option.data = string::to_int (value);

          processed = true;
          break;
        }
      }

      if (processed)
        continue;

      for (auto& option: this->string_options) {
        if (arg.data[1] == option.option) {
          assert (i + 1 < argc && "Option provided without value");

          string_view value = argv[++i];
          option.data = value;

          processed = true;
          break;
        }
      }

      if (processed)
        continue;

      // Option in none of the lists, invalid
      assert (false && "Unknown argument");
    }
  }

  assert (input_n == this->inputs.size () && "Not enough arguments");
}
