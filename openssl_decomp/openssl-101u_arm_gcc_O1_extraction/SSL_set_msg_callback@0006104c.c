
void SSL_set_msg_callback(SSL *ssl,cb *cb)

{
  ssl->msg_callback = (_func_3150 *)cb;
  return;
}

