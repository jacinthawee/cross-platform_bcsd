
X509_ALGOR * TS_MSG_IMPRINT_set_algo(X509_ALGOR **param_1,X509_ALGOR *param_2)

{
  X509_ALGOR *pXVar1;
  
  if (*param_1 == param_2) {
    pXVar1 = (X509_ALGOR *)0x1;
  }
  else {
    pXVar1 = X509_ALGOR_dup(param_2);
    if (pXVar1 == (X509_ALGOR *)0x0) {
      ERR_put_error(0x2f,0x76,0x41,"ts_req_utils.c",0x6a);
    }
    else {
      X509_ALGOR_free(*param_1);
      *param_1 = pXVar1;
      pXVar1 = (X509_ALGOR *)0x1;
    }
  }
  return pXVar1;
}

