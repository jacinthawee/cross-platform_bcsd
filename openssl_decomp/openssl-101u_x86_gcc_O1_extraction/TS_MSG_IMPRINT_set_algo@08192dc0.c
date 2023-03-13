
undefined4 TS_MSG_IMPRINT_set_algo(X509_ALGOR **param_1,X509_ALGOR *param_2)

{
  X509_ALGOR *pXVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  if (*param_1 != param_2) {
    pXVar1 = X509_ALGOR_dup(param_2);
    if (pXVar1 == (X509_ALGOR *)0x0) {
      uVar2 = 0;
      ERR_put_error(0x2f,0x76,0x41,"ts_req_utils.c",0x69);
    }
    else {
      X509_ALGOR_free(*param_1);
      *param_1 = pXVar1;
    }
  }
  return uVar2;
}

