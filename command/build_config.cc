command :: command (): program {nullptr}, args {} {}

template <typename ...A>
command :: command (const char* c, A... a): program {c}, args {c, a..., nullptr} {}

auto
command :: execute () -> void {
  // Any way other than const_cast?
  execvp (program, const_cast<char* const*>(args.data));
}

auto
build_config :: set_compiler (const char* cxx) -> void {
  this->compiler = cxx;
}

auto
build_config :: add_file (const char* file) {
  this->files.append (file);
}

auto
build_config :: add_flag (string_view flag) -> void {
  string f {flag.size () + 2};

  f.copy ("-");
  f.copy (flag, 1);
  f.data [f.size () - 1] = '\0';

  flags.append (f);
}

auto
build_config :: include (string_view directory) -> void {
  string d {directory.size () + 3};

  d.copy ("-I");
  d.copy (directory, 2);
  d.data [d.size () - 1] = '\0';

  includes.append (d);
}

auto
build_config :: link (string_view library) -> void {
  string l {library.size () + 3};

  l.copy ("-l");
  l.copy (library, 2);
  l.data [l.size () - 1] = '\0';

  libraries.append (l);
}

auto
build_config :: define (string_view macro) -> void {
  string m {macro.size () + 3};

  m.copy ("-D");
  m.copy (macro, 2);
  m.data [m.size () - 1] = '\0';

  macros.append (m.data);
}

auto
build_config :: run () -> void {
  vector<const char*> v;

  v.resize (this->files.size ()
            + this->flags.size ()
            + this->includes.size ()
            + this->libraries.size ()
            + this->macros.size ()
            + 2); // compiler and nullptr

  size_t i = 0;

  v[i++] = this->compiler;

  for (auto const& f: this->flags)
    v[i++] = f.data;

  for (auto const& d: this->includes)
    v[i++] = d.data;

  for (auto const& f: this->files)
    v[i++] = f;

  for (auto const& l: this->libraries)
    v[i++] = l.data;

  for (auto const& m: this->macros)
    v[i++] = m.data;

  v[i] = nullptr;

  command c;
  c.program = this->compiler;
  c.args.resize (v.size ());
  c.args = v;

  c.execute();
}
