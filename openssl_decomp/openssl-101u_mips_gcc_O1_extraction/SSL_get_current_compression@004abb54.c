
COMP_METHOD * SSL_get_current_compression(SSL *s)

{
  if (s->compress != (COMP_CTX *)0x0) {
    return s->compress->meth;
  }
  return (COMP_METHOD *)0x0;
}

