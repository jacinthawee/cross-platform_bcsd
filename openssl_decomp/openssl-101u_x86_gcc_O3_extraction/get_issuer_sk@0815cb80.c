
undefined4 get_issuer_sk(void **param_1,int param_2,undefined4 param_3)

{
  _STACK *p_Var1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  p_Var1 = *(_STACK **)(param_2 + 0x18);
  while( true ) {
    iVar3 = sk_num(p_Var1);
    if (iVar3 <= iVar4) {
      *param_1 = (void *)0x0;
      return 0;
    }
    pvVar2 = sk_value(p_Var1,iVar4);
    iVar3 = (**(code **)(param_2 + 0x28))(param_2,param_3,pvVar2);
    if (iVar3 != 0) break;
    iVar4 = iVar4 + 1;
  }
  *param_1 = pvVar2;
  if (pvVar2 == (void *)0x0) {
    return 0;
  }
  CRYPTO_add_lock((int *)((int)pvVar2 + 0x10),1,3,"x509_vfy.c",0x1f1);
  return 1;
}

