
GENERAL_NAME * TS_TST_INFO_set_tsa(int param_1,GENERAL_NAME *param_2)

{
  GENERAL_NAME *pGVar1;
  
  if (*(GENERAL_NAME **)(param_1 + 0x20) == param_2) {
    pGVar1 = (GENERAL_NAME *)0x1;
  }
  else {
    pGVar1 = GENERAL_NAME_dup(param_2);
    if (pGVar1 == (GENERAL_NAME *)0x0) {
      ERR_put_error(0x2f,0x8f,0x41,"ts_rsp_utils.c",0x14c);
    }
    else {
      GENERAL_NAME_free(*(GENERAL_NAME **)(param_1 + 0x20));
      *(GENERAL_NAME **)(param_1 + 0x20) = pGVar1;
      pGVar1 = (GENERAL_NAME *)0x1;
    }
  }
  return pGVar1;
}

