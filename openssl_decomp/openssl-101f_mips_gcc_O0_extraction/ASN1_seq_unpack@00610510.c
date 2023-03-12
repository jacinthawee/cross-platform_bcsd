
stack_st_OPENSSL_BLOCK * ASN1_seq_unpack(uchar *buf,int len,undefined1 *d2i,free_func *free_func)

{
  undefined *puVar1;
  stack_st_OPENSSL_BLOCK *psVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int *piVar7;
  stack_st_OPENSSL_BLOCK **ppsVar8;
  stack_st_OPENSSL_BLOCK **ppsVar9;
  undefined4 uVar10;
  char *pcVar11;
  int unaff_s1;
  int iStack_e8;
  int iStack_e4;
  undefined *puStack_e0;
  int iStack_dc;
  undefined *puStack_d8;
  uchar **ppuStack_d4;
  stack_st_OPENSSL_BLOCK **ppsStack_d0;
  code *pcStack_cc;
  undefined4 uStack_b8;
  undefined *puStack_b0;
  stack_st_OPENSSL_BLOCK *psStack_a4;
  undefined4 uStack_a0;
  int iStack_9c;
  stack_st_OPENSSL_BLOCK *psStack_98;
  code *pcStack_94;
  stack_st_OPENSSL_BLOCK *psStack_70;
  undefined4 *puStack_6c;
  undefined *puStack_64;
  uchar *local_10;
  stack_st_OPENSSL_BLOCK *local_c;
  
  psStack_98 = (stack_st_OPENSSL_BLOCK *)PTR___stack_chk_guard_006aabf0;
  ppuStack_d4 = &local_10;
  local_c = *(stack_st_OPENSSL_BLOCK **)PTR___stack_chk_guard_006aabf0;
  local_10 = buf;
  psVar2 = d2i_ASN1_SET((stack_st_OPENSSL_BLOCK **)0x0,ppuStack_d4,len,d2i,free_func,0x10,0);
  if (psVar2 == (stack_st_OPENSSL_BLOCK *)0x0) {
    len = (int)&DAT_0000006e;
    pcVar11 = "asn_pack.c";
    ppuStack_d4 = (uchar **)0x7f;
    (*(code *)PTR_ERR_put_error_006a9030)(0xd);
    d2i = pcVar11;
  }
  if (local_c == *(stack_st_OPENSSL_BLOCK **)psStack_98) {
    return psVar2;
  }
  psVar2 = local_c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_d8 = PTR___stack_chk_guard_006aabf0;
  puStack_64 = (undefined *)psStack_98;
  puStack_6c = *(undefined4 **)PTR___stack_chk_guard_006aabf0;
  iVar3 = i2d_ASN1_SET(psVar2,(uchar **)0x0,(undefined1 *)ppuStack_d4,0x10,0,0);
  if (iVar3 == 0) {
    ppsVar9 = (stack_st_OPENSSL_BLOCK **)0x7e;
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x7e,0x70,"asn_pack.c");
    psVar2 = (stack_st_OPENSSL_BLOCK *)0x0;
  }
  else {
    psStack_98 = (stack_st_OPENSSL_BLOCK *)
                 (*(code *)PTR_CRYPTO_malloc_006a8108)(iVar3,"asn_pack.c",0x5f);
    unaff_s1 = iVar3;
    if (psStack_98 == (stack_st_OPENSSL_BLOCK *)0x0) {
      ppsVar9 = (stack_st_OPENSSL_BLOCK **)0x7e;
      (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x7e,0x41,"asn_pack.c");
      psVar2 = (stack_st_OPENSSL_BLOCK *)0x0;
    }
    else {
      ppsVar9 = &psStack_70;
      psStack_70 = psStack_98;
      i2d_ASN1_SET(psVar2,(uchar **)ppsVar9,(undefined1 *)ppuStack_d4,0x10,0,0);
      if ((int *)d2i != (int *)0x0) {
        *(int *)d2i = iVar3;
      }
      psVar2 = psStack_98;
      if ((stack_st_OPENSSL_BLOCK **)len != (stack_st_OPENSSL_BLOCK **)0x0) {
        *(stack_st_OPENSSL_BLOCK **)len = psStack_98;
      }
    }
  }
  if (puStack_6c == *(undefined4 **)puStack_d8) {
    return psVar2;
  }
  pcStack_94 = ASN1_unpack_string;
  puVar6 = puStack_6c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_e0 = PTR___stack_chk_guard_006aabf0;
  uStack_a0 = puVar6[2];
  ppsVar8 = (stack_st_OPENSSL_BLOCK **)*puVar6;
  puVar6 = &uStack_a0;
  puStack_b0 = &_gp;
  iStack_9c = *(int *)PTR___stack_chk_guard_006aabf0;
  psVar2 = (stack_st_OPENSSL_BLOCK *)(*(code *)ppsVar9)(0);
  if (psVar2 == (stack_st_OPENSSL_BLOCK *)0x0) {
    ppsVar8 = (stack_st_OPENSSL_BLOCK **)&DAT_0000006e;
    uStack_b8 = 0x74;
    puVar6 = (undefined4 *)&DAT_00000088;
    psStack_a4 = psVar2;
    (**(code **)(puStack_b0 + -0x6eb0))(0xd,0x88,0x6e,"asn_pack.c");
    psVar2 = psStack_a4;
  }
  if (iStack_9c == *(int *)puStack_e0) {
    return psVar2;
  }
  pcStack_cc = ASN1_pack_string;
  iVar3 = iStack_9c;
  (**(code **)(puStack_b0 + -0x5328))();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStack_e4 = *(int *)PTR___stack_chk_guard_006aabf0;
  iStack_dc = unaff_s1;
  ppsStack_d0 = (stack_st_OPENSSL_BLOCK **)len;
  if (ppsVar8 == (stack_st_OPENSSL_BLOCK **)0x0) {
    psVar2 = (stack_st_OPENSSL_BLOCK *)(*(code *)PTR_ASN1_STRING_new_006a98b4)();
    if (psVar2 != (stack_st_OPENSSL_BLOCK *)0x0) goto LAB_0061083c;
LAB_00610928:
    ppsVar9 = (stack_st_OPENSSL_BLOCK **)&DAT_00000041;
    uVar5 = 0x81;
LAB_006108f8:
    piVar7 = (int *)&DAT_0000007c;
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x7c,ppsVar9,"asn_pack.c",uVar5);
    psVar2 = (stack_st_OPENSSL_BLOCK *)0x0;
  }
  else {
    psVar2 = *ppsVar8;
    if (psVar2 == (stack_st_OPENSSL_BLOCK *)0x0) {
      psVar2 = (stack_st_OPENSSL_BLOCK *)(*(code *)PTR_ASN1_STRING_new_006a98b4)();
      if (psVar2 == (stack_st_OPENSSL_BLOCK *)0x0) goto LAB_00610928;
      *ppsVar8 = psVar2;
    }
LAB_0061083c:
    iVar4 = (*(code *)puVar6)(iVar3,0);
    (psVar2->stack).num = iVar4;
    if (iVar4 == 0) {
      ppsVar9 = (stack_st_OPENSSL_BLOCK **)&DAT_00000070;
      uVar5 = 0x88;
      goto LAB_006108f8;
    }
    ppsVar9 = (stack_st_OPENSSL_BLOCK **)&DAT_0000008b;
    iStack_e8 = (*(code *)PTR_CRYPTO_malloc_006a8108)(iVar4,"asn_pack.c");
    if (iStack_e8 == 0) {
      ppsVar9 = (stack_st_OPENSSL_BLOCK **)&DAT_00000041;
      piVar7 = (int *)&DAT_0000007c;
      (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x7c,0x41,"asn_pack.c",0x8c);
      psVar2 = (stack_st_OPENSSL_BLOCK *)0x0;
    }
    else {
      piVar7 = &iStack_e8;
      (psVar2->stack).sorted = iStack_e8;
      (*(code *)puVar6)(iVar3,piVar7);
    }
  }
  if (iStack_e4 == *(int *)puVar1) {
    return psVar2;
  }
  iVar3 = iStack_e4;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (ppsVar9 == (stack_st_OPENSSL_BLOCK **)0x0) {
    psVar2 = (stack_st_OPENSSL_BLOCK *)(*(code *)PTR_ASN1_STRING_new_006a98b4)();
    if (psVar2 == (stack_st_OPENSSL_BLOCK *)0x0) {
LAB_00610a48:
      uVar10 = 0x41;
      uVar5 = 0x9e;
      goto LAB_00610a5c;
    }
  }
  else {
    psVar2 = *ppsVar9;
    if (psVar2 == (stack_st_OPENSSL_BLOCK *)0x0) {
      psVar2 = (stack_st_OPENSSL_BLOCK *)(*(code *)PTR_ASN1_STRING_new_006a98b4)();
      if (psVar2 == (stack_st_OPENSSL_BLOCK *)0x0) goto LAB_00610a48;
      *ppsVar9 = psVar2;
    }
  }
  if ((psVar2->stack).sorted != 0) {
    (*(code *)PTR_CRYPTO_free_006a7f88)();
    (psVar2->stack).sorted = 0;
  }
  iVar3 = (*(code *)PTR_ASN1_item_i2d_006a979c)(iVar3,&(psVar2->stack).sorted,piVar7);
  (psVar2->stack).num = iVar3;
  if (iVar3 == 0) {
    uVar10 = 0x70;
    uVar5 = 0xaa;
  }
  else {
    if ((psVar2->stack).sorted != 0) {
      return psVar2;
    }
    uVar10 = 0x41;
    uVar5 = 0xae;
  }
LAB_00610a5c:
  (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xc6,uVar10,"asn_pack.c",uVar5);
  return (stack_st_OPENSSL_BLOCK *)0x0;
}

