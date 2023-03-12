
stack_st_X509_EXTENSION * TS_REQ_add_ext(int param_1,X509_EXTENSION *param_2,int param_3)

{
  stack_st_X509_EXTENSION *psVar1;
  
  psVar1 = X509v3_add_ext((stack_st_X509_EXTENSION **)(param_1 + 0x14),param_2,param_3);
  if (psVar1 != (stack_st_X509_EXTENSION *)0x0) {
    psVar1 = (stack_st_X509_EXTENSION *)0x1;
  }
  return psVar1;
}

