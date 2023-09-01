command :: command (): program {nullptr}, args {} {}

template <typename ...A>
command :: command (const char* c, A... a): program {c}, args {c, a..., nullptr} {}

auto
command :: execute () -> void {
  // Any way other than const_cast?
  execvp (program, const_cast<char* const*>(args.data));
}

build_config :: build_config (const char* file): entry {file} {
  this->flags.append ("-Wall");
  this->flags.append ("-Wextra");
  this->flags.append ("-Wshadow");
  this->flags.append ("-pedantic");
}

auto
build_config :: include (string_view directory) -> void {
  includes.append (string {"-I"}.append (directory).with_null ());
}

auto
build_config :: link (string_view library) -> void {
  libraries.append (string {"-l"}.append (library).with_null ());
}

auto
build_config :: define (string_view macro) -> void {
  macros.append (string {"-D"}.append (macro).with_null ());
}

auto
build_config :: run () -> void {
  vector<const char*> v;

  v.resize (4 // compiler, standard, entry and nullptr
            + this->flags.size ()
            + this->includes.size ()
            + this->libraries.size ()
            + this->macros.size ());

  size_t i = 0;

  v[i++] = this->compiler;

  string std =
    string {"-std=c++"}
    .append (this->standard)
    .with_null ();

  v[i++] = std.data;

  for (auto const& f: this->flags)
    v[i++] = f;

  for (auto const& d: this->includes)
    v[i++] = d.data;

  v[i++] = this->entry;

  for (auto const& l: this->libraries)
    v[i++] = l.data;

  for (auto const& m: this->macros)
    v[i++] = m.data;

  v[i] = nullptr;

  command c;
  c.program = this->compiler;
  c.args.resize (v.size ());
  c.args = v;

  c.execute ();
}
