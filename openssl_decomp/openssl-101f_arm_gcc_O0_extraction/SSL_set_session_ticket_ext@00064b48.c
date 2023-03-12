
int SSL_set_session_ticket_ext(SSL *s,void *ext_data,int ext_len)

{
  undefined2 *puVar1;
  
  if (s->version < 0x301) {
    puVar1 = (undefined2 *)0x0;
  }
  else {
    if ((void *)s->tlsext_opaque_prf_input_len != (void *)0x0) {
      CRYPTO_free((void *)s->tlsext_opaque_prf_input_len);
      s->tlsext_opaque_prf_input_len = 0;
    }
    puVar1 = (undefined2 *)CRYPTO_malloc(ext_len + 8,"ssl_sess.c",0x3a7);
    s->tlsext_opaque_prf_input_len = (size_t)puVar1;
    if (puVar1 == (undefined2 *)0x0) {
      ERR_put_error(0x14,0x126,0x41,"ssl_sess.c",0x3aa);
    }
    else {
      if (ext_data == (void *)0x0) {
        *puVar1 = 0;
        *(undefined4 *)(puVar1 + 2) = 0;
        return 1;
      }
      *puVar1 = (short)ext_len;
      *(undefined2 **)(puVar1 + 2) = puVar1 + 4;
      memcpy(puVar1 + 4,ext_data,ext_len);
      puVar1 = (undefined2 *)0x1;
    }
  }
  return (int)puVar1;
}

