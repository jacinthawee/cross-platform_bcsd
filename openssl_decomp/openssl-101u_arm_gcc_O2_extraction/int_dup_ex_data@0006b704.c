
undefined4 int_dup_ex_data(undefined4 param_1,_STACK **param_2,_STACK **param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  void *ptr;
  void *pvVar4;
  _STACK *p_Var5;
  int iVar6;
  void **ppvVar7;
  undefined4 *puVar8;
  void **ppvVar9;
  void *local_2c [2];
  
  if (*param_3 != (_STACK *)0x0) {
    iVar1 = def_get_class();
    if (iVar1 == 0) {
      return 0;
    }
    CRYPTO_lock(5,2,"ex_data.c",0x1d2);
    iVar2 = sk_num(*(_STACK **)(iVar1 + 4));
    iVar3 = sk_num(*param_3);
    if (iVar3 <= iVar2) {
      iVar2 = iVar3;
    }
    if (iVar2 < 1) {
      CRYPTO_lock(6,2,"ex_data.c",0x1df);
      return 1;
    }
    ptr = CRYPTO_malloc(iVar2 << 2,"ex_data.c",0x1d8);
    if (ptr == (void *)0x0) {
      CRYPTO_lock(6,2,"ex_data.c",0x1df);
      ERR_put_error(0xf,0x6a,0x41,"ex_data.c",0x1e1);
      return 0;
    }
    ppvVar9 = (void **)((int)ptr + -4);
    iVar3 = 0;
    ppvVar7 = ppvVar9;
    do {
      pvVar4 = sk_value(*(_STACK **)(iVar1 + 4),iVar3);
      iVar3 = iVar3 + 1;
      ppvVar7 = ppvVar7 + 1;
      *ppvVar7 = pvVar4;
    } while (iVar3 != iVar2);
    iVar1 = 0;
    CRYPTO_lock(6,2,"ex_data.c",0x1df);
    do {
      if ((*param_3 == (_STACK *)0x0) || (iVar3 = sk_num(*param_3), iVar3 <= iVar1)) {
        pvVar4 = (void *)0x0;
      }
      else {
        pvVar4 = sk_value(*param_3,iVar1);
      }
      ppvVar9 = ppvVar9 + 1;
      puVar8 = (undefined4 *)*ppvVar9;
      local_2c[0] = pvVar4;
      if ((puVar8 == (undefined4 *)0x0) || ((code *)puVar8[4] == (code *)0x0)) {
        p_Var5 = *param_2;
        if (p_Var5 == (_STACK *)0x0) goto LAB_0006b856;
LAB_0006b7e6:
        iVar3 = sk_num(p_Var5);
        do {
          if (iVar1 < iVar3) {
            sk_set(*param_2,iVar1,pvVar4);
            goto LAB_0006b80a;
          }
          iVar6 = sk_push(*param_2,(void *)0x0);
          iVar3 = iVar3 + 1;
        } while (iVar6 != 0);
        ERR_put_error(0xf,0x66,0x41,"ex_data.c",0x26f);
      }
      else {
        (*(code *)puVar8[4])(param_2,param_3,local_2c,iVar1,*puVar8,puVar8[1]);
        p_Var5 = *param_2;
        pvVar4 = local_2c[0];
        if (p_Var5 != (_STACK *)0x0) goto LAB_0006b7e6;
LAB_0006b856:
        pvVar4 = local_2c[0];
        p_Var5 = sk_new_null();
        *param_2 = p_Var5;
        if (p_Var5 != (_STACK *)0x0) goto LAB_0006b7e6;
        ERR_put_error(0xf,0x66,0x41,"ex_data.c",0x267);
      }
LAB_0006b80a:
      iVar1 = iVar1 + 1;
    } while (iVar1 != iVar2);
    CRYPTO_free(ptr);
  }
  return 1;
}

