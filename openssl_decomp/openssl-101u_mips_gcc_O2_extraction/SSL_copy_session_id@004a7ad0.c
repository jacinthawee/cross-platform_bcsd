
void SSL_copy_session_id(SSL *to,SSL *from)

{
  undefined *UNRECOVERED_JUMPTABLE;
  SSL_SESSION *session;
  cert_st *pcVar1;
  _func_3053 *p_Var2;
  
  session = SSL_get_session(from);
  SSL_set_session(to,session);
  if (to->method != from->method) {
    (*to->method->ssl_free)(to);
    p_Var2 = from->method->ssl_new;
    to->method = from->method;
    (*p_Var2)(to);
  }
  pcVar1 = to->cert;
  if (from->cert == (cert_st *)0x0) {
    to->cert = (cert_st *)0x0;
  }
  else {
    CRYPTO_add_lock((int *)(from->cert + 0x90),1,0xd,"ssl_lib.c",0x377);
    to->cert = from->cert;
  }
  if (pcVar1 != (cert_st *)0x0) {
    ssl_cert_free(pcVar1);
  }
  UNRECOVERED_JUMPTABLE = PTR_memcpy_006a9aec;
  if (from->sid_ctx_length < 0x21) {
    to->sid_ctx_length = from->sid_ctx_length;
                    /* WARNING: Could not recover jumptable at 0x004a7bc8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)UNRECOVERED_JUMPTABLE)(to->sid_ctx,from->sid_ctx);
    return;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0xda,0x111,"ssl_lib.c",0x1a1);
  return;
}

