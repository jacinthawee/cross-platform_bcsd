
int SSL_set_session_ticket_ext(SSL *s,void *ext_data,int ext_len)

{
  undefined *puVar1;
  undefined2 *puVar2;
  int iVar3;
  
  if (s->version < 0x301) {
    return 0;
  }
  if ((void *)s->tlsext_opaque_prf_input_len != (void *)0x0) {
    CRYPTO_free((void *)s->tlsext_opaque_prf_input_len);
    s->tlsext_opaque_prf_input_len = 0;
  }
  puVar2 = (undefined2 *)CRYPTO_malloc(ext_len + 8,"ssl_sess.c",0x3a7);
  s->tlsext_opaque_prf_input_len = (size_t)puVar2;
  puVar1 = PTR_memcpy_006aabf4;
  if (puVar2 == (undefined2 *)0x0) {
    (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x126,0x41,"ssl_sess.c",0x3aa);
    iVar3 = 0;
  }
  else {
    if (ext_data == (void *)0x0) {
      *puVar2 = 0;
      *(undefined4 *)(puVar2 + 2) = 0;
      return 1;
    }
    *puVar2 = (short)ext_len;
    *(undefined2 **)(puVar2 + 2) = puVar2 + 4;
    (*(code *)puVar1)(puVar2 + 4,ext_data,ext_len);
    iVar3 = 1;
  }
  return iVar3;
}

