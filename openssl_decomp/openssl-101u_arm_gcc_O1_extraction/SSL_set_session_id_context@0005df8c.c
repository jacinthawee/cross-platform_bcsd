
int SSL_set_session_id_context(SSL *ssl,uchar *sid_ctx,uint sid_ctx_len)

{
  if (sid_ctx_len < 0x21) {
    ssl->sid_ctx_length = sid_ctx_len;
    memcpy(ssl->sid_ctx,sid_ctx,sid_ctx_len);
    return 1;
  }
  ERR_put_error(0x14,0xda,0x111,"ssl_lib.c",0x1a1);
  return 0;
}

