
undefined4 * ssl_session_dup(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  
  puVar1 = (undefined4 *)CRYPTO_malloc(0xf4,"ssl_sess.c",0xee);
  if (puVar1 == (undefined4 *)0x0) {
    (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x15c,0x41,"ssl_sess.c",0x15d);
    return (undefined4 *)0x0;
  }
  puVar4 = puVar1;
  puVar5 = param_1;
  do {
    uVar8 = *puVar5;
    uVar7 = puVar5[1];
    uVar6 = puVar5[2];
    uVar2 = puVar5[3];
    puVar5 = puVar5 + 4;
    *puVar4 = uVar8;
    puVar4[1] = uVar7;
    puVar4[2] = uVar6;
    puVar4[3] = uVar2;
    puVar4 = puVar4 + 4;
  } while (puVar5 != param_1 + 0x3c);
  *puVar4 = *puVar5;
  *(undefined *)(puVar1 + 0x30) = 0;
  puVar1[0x23] = 0;
  puVar1[0x24] = 0;
  puVar1[0x2f] = 0;
  puVar1[0x34] = 0;
  puVar1[0x36] = 0;
  puVar1[0x38] = 0;
  puVar1[0x39] = 0;
  puVar1[0x3c] = 0;
  *(undefined *)((int)puVar1 + 0xc1) = 0;
  *(undefined *)((int)puVar1 + 0xc2) = 0;
  *(undefined *)((int)puVar1 + 0xc3) = 0;
  *(undefined *)(puVar1 + 0x31) = 0;
  *(undefined *)((int)puVar1 + 0xc5) = 0;
  *(undefined *)((int)puVar1 + 0xc6) = 0;
  *(undefined *)((int)puVar1 + 199) = 0;
  puVar1[0x32] = 0;
  puVar1[0x33] = 0;
  puVar1[0x29] = 1;
  if (param_1[0x26] != 0) {
    CRYPTO_add_lock((int *)(param_1[0x26] + 0x78),1,0xf,"ssl_sess.c",0x111);
  }
  if (param_1[0x27] != 0) {
    CRYPTO_add_lock((int *)(param_1[0x27] + 0x10),1,3,"ssl_sess.c",0x114);
  }
  if (param_1[0x23] != 0) {
    iVar3 = (*(code *)PTR_BUF_strdup_006a6fdc)();
    puVar1[0x23] = iVar3;
    if (iVar3 == 0) goto LAB_004ae5a8;
  }
  if (param_1[0x24] != 0) {
    iVar3 = (*(code *)PTR_BUF_strdup_006a6fdc)();
    puVar1[0x24] = iVar3;
    if (iVar3 == 0) goto LAB_004ae5a8;
  }
  if (param_1[0x2f] != 0) {
    iVar3 = (*(code *)PTR_sk_dup_006a7f54)();
    puVar1[0x2f] = iVar3;
    if (iVar3 == 0) goto LAB_004ae5a8;
  }
  iVar3 = CRYPTO_dup_ex_data(3,(CRYPTO_EX_DATA *)(puVar1 + 0x30),(CRYPTO_EX_DATA *)(param_1 + 0x30))
  ;
  if (iVar3 != 0) {
    if (param_1[0x34] != 0) {
      iVar3 = (*(code *)PTR_BUF_strdup_006a6fdc)();
      puVar1[0x34] = iVar3;
      if (iVar3 == 0) goto LAB_004ae5a8;
    }
    if (param_1[0x36] != 0) {
      iVar3 = (*(code *)PTR_BUF_memdup_006a8080)(param_1[0x36],param_1[0x35]);
      puVar1[0x36] = iVar3;
      if (iVar3 == 0) goto LAB_004ae5a8;
    }
    if (param_1[0x38] != 0) {
      iVar3 = (*(code *)PTR_BUF_memdup_006a8080)(param_1[0x38],param_1[0x37]);
      puVar1[0x38] = iVar3;
      if (iVar3 == 0) goto LAB_004ae5a8;
    }
    if (param_2 == 0) {
      puVar1[0x3b] = 0;
      puVar1[0x3a] = 0;
    }
    else {
      iVar3 = (*(code *)PTR_BUF_memdup_006a8080)(param_1[0x39],param_1[0x3a]);
      puVar1[0x39] = iVar3;
      if (iVar3 == 0) goto LAB_004ae5a8;
    }
    if (param_1[0x3c] == 0) {
      return puVar1;
    }
    iVar3 = (*(code *)PTR_BUF_strdup_006a6fdc)();
    puVar1[0x3c] = iVar3;
    if (iVar3 != 0) {
      return puVar1;
    }
  }
LAB_004ae5a8:
  (*(code *)PTR_ERR_put_error_006a7f34)(0x14,0x15c,0x41,"ssl_sess.c",0x15d);
  iVar3 = CRYPTO_add_lock(puVar1 + 0x29,-1,0xe,"ssl_sess.c",0x36c);
  if (iVar3 < 1) {
    SSL_SESSION_free_part_2(puVar1);
    return (undefined4 *)0x0;
  }
  return (undefined4 *)0x0;
}

