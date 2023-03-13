
undefined4 TS_TST_INFO_set_tsa(int param_1,GENERAL_NAME *param_2)

{
  GENERAL_NAME *pGVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  if (*(GENERAL_NAME **)(param_1 + 0x20) != param_2) {
    pGVar1 = GENERAL_NAME_dup(param_2);
    if (pGVar1 == (GENERAL_NAME *)0x0) {
      uVar2 = 0;
      ERR_put_error(0x2f,0x8f,0x41,"ts_rsp_utils.c",0x14c);
    }
    else {
      GENERAL_NAME_free(*(GENERAL_NAME **)(param_1 + 0x20));
      *(GENERAL_NAME **)(param_1 + 0x20) = pGVar1;
    }
  }
  return uVar2;
}

