
void SSL_set_tmp_rsa_callback(SSL *ssl,cb *cb)

{
                    /* WARNING: Could not recover jumptable at 0x004af200. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*ssl->method->ssl_callback_ctrl)(ssl,5,(fp *)cb);
  return;
}

