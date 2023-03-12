
int dtls1_read_failed(SSL *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  BIO *pBVar3;
  
  if (param_2 < 1) {
    iVar1 = dtls1_is_timer_expired();
    if (iVar1 == 0) {
      return param_2;
    }
    uVar2 = SSL_state(param_1);
    if (((uVar2 & 0x3000) != 0) || (param_1->tlsext_heartbeat != 0)) {
      iVar1 = dtls1_handle_timeout(param_1);
      return iVar1;
    }
    pBVar3 = SSL_get_rbio(param_1);
    (*(code *)PTR_BIO_set_flags_006a7570)(pBVar3,1);
  }
  else {
    (*(code *)PTR___fprintf_chk_006a9980)
              (*(undefined4 *)PTR_stderr_006a9af8,1,"invalid state reached %s:%d","d1_both.c",0x4a7)
    ;
    param_2 = 1;
  }
  return param_2;
}

