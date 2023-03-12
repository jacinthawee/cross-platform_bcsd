
void SSL_set_tmp_ecdh_callback(SSL *ssl,ecdh *ecdh)

{
                    /* WARNING: Could not recover jumptable at 0x00060f28. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*ssl->method->ssl_callback_ctrl)(ssl,7,(fp *)ecdh);
  return;
}

