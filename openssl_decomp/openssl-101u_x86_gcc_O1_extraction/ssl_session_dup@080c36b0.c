
undefined4 * ssl_session_dup(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  char *pcVar2;
  _STACK *p_Var3;
  void *pvVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  byte bVar9;
  
  bVar9 = 0;
  puVar1 = (undefined4 *)CRYPTO_malloc(0xf4,"ssl_sess.c",0xee);
  if (puVar1 == (undefined4 *)0x0) {
    ERR_put_error(0x14,0x15c,0x41,"ssl_sess.c",0x15d);
    return (undefined4 *)0x0;
  }
  *puVar1 = *param_1;
  iVar5 = (int)puVar1 - (int)(undefined4 *)((uint)(puVar1 + 1) & 0xfffffffc);
  puVar1[0x3c] = param_1[0x3c];
  puVar7 = (undefined4 *)((int)param_1 - iVar5);
  puVar8 = (undefined4 *)((uint)(puVar1 + 1) & 0xfffffffc);
  for (uVar6 = iVar5 + 0xf4U >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *puVar8 = *puVar7;
    puVar7 = puVar7 + (uint)bVar9 * -2 + 1;
    puVar8 = puVar8 + (uint)bVar9 * -2 + 1;
  }
  puVar1[0x30] = 0;
  puVar1[0x23] = 0;
  puVar1[0x24] = 0;
  puVar1[0x2f] = 0;
  puVar1[0x34] = 0;
  puVar1[0x36] = 0;
  puVar1[0x38] = 0;
  puVar1[0x39] = 0;
  puVar1[0x3c] = 0;
  puVar1[0x31] = 0;
  iVar5 = param_1[0x26];
  puVar1[0x32] = 0;
  puVar1[0x33] = 0;
  puVar1[0x29] = 1;
  if (iVar5 != 0) {
    CRYPTO_add_lock((int *)(iVar5 + 0x78),1,0xf,"ssl_sess.c",0x111);
  }
  if (param_1[0x27] != 0) {
    CRYPTO_add_lock((int *)(param_1[0x27] + 0x10),1,3,"ssl_sess.c",0x114);
  }
  if ((char *)param_1[0x23] != (char *)0x0) {
    pcVar2 = BUF_strdup((char *)param_1[0x23]);
    puVar1[0x23] = pcVar2;
    if (pcVar2 == (char *)0x0) goto LAB_080c3948;
  }
  if ((char *)param_1[0x24] != (char *)0x0) {
    pcVar2 = BUF_strdup((char *)param_1[0x24]);
    puVar1[0x24] = pcVar2;
    if (pcVar2 == (char *)0x0) goto LAB_080c3948;
  }
  if ((_STACK *)param_1[0x2f] != (_STACK *)0x0) {
    p_Var3 = sk_dup((_STACK *)param_1[0x2f]);
    puVar1[0x2f] = p_Var3;
    if (p_Var3 == (_STACK *)0x0) goto LAB_080c3948;
  }
  iVar5 = CRYPTO_dup_ex_data(3,(CRYPTO_EX_DATA *)(puVar1 + 0x30),(CRYPTO_EX_DATA *)(param_1 + 0x30))
  ;
  if (iVar5 != 0) {
    if ((char *)param_1[0x34] != (char *)0x0) {
      pcVar2 = BUF_strdup((char *)param_1[0x34]);
      puVar1[0x34] = pcVar2;
      if (pcVar2 == (char *)0x0) goto LAB_080c3948;
    }
    if ((void *)param_1[0x36] != (void *)0x0) {
      pvVar4 = BUF_memdup((void *)param_1[0x36],param_1[0x35]);
      puVar1[0x36] = pvVar4;
      if (pvVar4 == (void *)0x0) goto LAB_080c3948;
    }
    if ((void *)param_1[0x38] != (void *)0x0) {
      pvVar4 = BUF_memdup((void *)param_1[0x38],param_1[0x37]);
      puVar1[0x38] = pvVar4;
      if (pvVar4 == (void *)0x0) goto LAB_080c3948;
    }
    if (param_2 == 0) {
      puVar1[0x3b] = 0;
      puVar1[0x3a] = 0;
    }
    else {
      pvVar4 = BUF_memdup((void *)param_1[0x39],param_1[0x3a]);
      puVar1[0x39] = pvVar4;
      if (pvVar4 == (void *)0x0) goto LAB_080c3948;
    }
    if ((char *)param_1[0x3c] == (char *)0x0) {
      return puVar1;
    }
    pcVar2 = BUF_strdup((char *)param_1[0x3c]);
    puVar1[0x3c] = pcVar2;
    if (pcVar2 != (char *)0x0) {
      return puVar1;
    }
  }
LAB_080c3948:
  ERR_put_error(0x14,0x15c,0x41,"ssl_sess.c",0x15d);
  iVar5 = CRYPTO_add_lock(puVar1 + 0x29,-1,0xe,"ssl_sess.c",0x36c);
  if (iVar5 < 1) {
    SSL_SESSION_free_part_2();
  }
  return (undefined4 *)0x0;
}

