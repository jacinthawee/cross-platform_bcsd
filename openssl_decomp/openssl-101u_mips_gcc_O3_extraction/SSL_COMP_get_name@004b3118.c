
char * SSL_COMP_get_name(COMP_METHOD *comp)

{
  if (comp != (COMP_METHOD *)0x0) {
    return comp->name;
  }
  return (char *)0x0;
}

