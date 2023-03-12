
COMP_METHOD * SSL_get_current_expansion(SSL *s)

{
  if (s->expand != (COMP_CTX *)0x0) {
    return s->expand->meth;
  }
  return (COMP_METHOD *)0x0;
}

