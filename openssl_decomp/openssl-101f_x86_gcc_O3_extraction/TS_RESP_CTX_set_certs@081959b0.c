
undefined4 TS_RESP_CTX_set_certs(int param_1,_STACK *param_2)

{
  _STACK *p_Var1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  
  if (*(_STACK **)(param_1 + 8) != (_STACK *)0x0) {
    sk_pop_free(*(_STACK **)(param_1 + 8),X509_free);
    *(undefined4 *)(param_1 + 8) = 0;
  }
  if (param_2 != (_STACK *)0x0) {
    p_Var1 = sk_dup(param_2);
    *(_STACK **)(param_1 + 8) = p_Var1;
    if (p_Var1 == (_STACK *)0x0) {
      ERR_put_error(0x2f,0x81,0x41,"ts_rsp_sign.c",0xf6);
      return 0;
    }
    for (iVar4 = 0; iVar3 = sk_num(p_Var1), iVar4 < iVar3; iVar4 = iVar4 + 1) {
      pvVar2 = sk_value(*(_STACK **)(param_1 + 8),iVar4);
      CRYPTO_add_lock((int *)((int)pvVar2 + 0x10),1,3,"ts_rsp_sign.c",0xfc);
      p_Var1 = *(_STACK **)(param_1 + 8);
    }
  }
  return 1;
}

