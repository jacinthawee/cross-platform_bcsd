
int SSL_set_session_id_context(SSL *ssl,uchar *sid_ctx,uint sid_ctx_len)

{
  undefined *puVar1;
  
  puVar1 = PTR_memcpy_006a9aec;
  if (sid_ctx_len < 0x21) {
    ssl->sid_ctx_length = sid_ctx_len;
    (*(code *)puVar1)(ssl->sid_ctx);
    return 1;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xda,0x111,"ssl_lib.c",0x1a1);
  return 0;
}

