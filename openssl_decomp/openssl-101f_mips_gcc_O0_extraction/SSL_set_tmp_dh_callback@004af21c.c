
void SSL_set_tmp_dh_callback(SSL *ssl,dh *dh)

{
                    /* WARNING: Could not recover jumptable at 0x004af228. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*ssl->method->ssl_callback_ctrl)(ssl,6,(fp *)dh);
  return;
}

