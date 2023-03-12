
int SSL_SESSION_set1_id_context(SSL_SESSION *s,uchar *sid_ctx,uint sid_ctx_len)

{
  undefined *puVar1;
  
  puVar1 = PTR_memcpy_006aabf4;
  if (sid_ctx_len < 0x21) {
    s->sid_ctx_length = sid_ctx_len;
    (*(code *)puVar1)(s->sid_ctx);
    return 1;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x138,0x111,"ssl_sess.c",0x372);
  return 0;
}

