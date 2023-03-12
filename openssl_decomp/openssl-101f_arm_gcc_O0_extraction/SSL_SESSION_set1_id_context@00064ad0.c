
int SSL_SESSION_set1_id_context(SSL_SESSION *s,uchar *sid_ctx,uint sid_ctx_len)

{
  if (sid_ctx_len < 0x21) {
    s->sid_ctx_length = sid_ctx_len;
    memcpy(s->sid_ctx,sid_ctx,sid_ctx_len);
    return 1;
  }
  ERR_put_error(0x14,0x138,0x111,"ssl_sess.c",0x372);
  return 0;
}

