
long SSL_CTX_callback_ctrl(SSL_CTX *param_1,int param_2,void *param_3)

{
  long lVar1;
  
  if (param_2 == 0xf) {
    param_1->msg_callback = (_func_3095 *)param_3;
    return 1;
  }
                    /* WARNING: Could not recover jumptable at 0x080c0d56. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  lVar1 = (*param_1->method->ssl_ctx_callback_ctrl)(param_1,param_2,(fp *)param_3);
  return lVar1;
}

