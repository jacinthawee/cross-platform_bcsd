
stack_st_OPENSSL_BLOCK * ASN1_seq_unpack(uchar *buf,int len,undefined1 *d2i,free_func *free_func)

{
  undefined *puVar1;
  stack_st_OPENSSL_BLOCK *psVar2;
  int iVar3;
  int iVar4;
  stack_st_OPENSSL_BLOCK *psVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  int *piVar8;
  stack_st_OPENSSL_BLOCK **ppsVar9;
  stack_st_OPENSSL_BLOCK **ppsVar10;
  undefined4 uVar11;
  char *pcVar12;
  int unaff_s1;
  int iStack_f0;
  int iStack_ec;
  undefined *puStack_e4;
  int iStack_e0;
  undefined *puStack_dc;
  uchar **ppuStack_d8;
  stack_st_OPENSSL_BLOCK **ppsStack_d4;
  int *piStack_d0;
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
  
  psStack_98 = (stack_st_OPENSSL_BLOCK *)PTR___stack_chk_guard_006a9ae8;
  ppuStack_d8 = &local_10;
  local_c = *(stack_st_OPENSSL_BLOCK **)PTR___stack_chk_guard_006a9ae8;
  local_10 = buf;
  psVar2 = d2i_ASN1_SET((stack_st_OPENSSL_BLOCK **)0x0,ppuStack_d8,len,d2i,free_func,0x10,0);
  if (psVar2 == (stack_st_OPENSSL_BLOCK *)0x0) {
    len = (int)&DAT_0000006e;
    pcVar12 = "asn_pack.c";
    ppuStack_d8 = (uchar **)0x7f;
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd);
    d2i = pcVar12;
  }
  if (local_c == *(stack_st_OPENSSL_BLOCK **)psStack_98) {
    return psVar2;
  }
  psVar2 = local_c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_dc = PTR___stack_chk_guard_006a9ae8;
  puStack_64 = (undefined *)psStack_98;
  puStack_6c = *(undefined4 **)PTR___stack_chk_guard_006a9ae8;
  iVar3 = i2d_ASN1_SET(psVar2,(uchar **)0x0,(undefined1 *)ppuStack_d8,0x10,0,0);
  if (iVar3 == 0) {
    ppsVar10 = (stack_st_OPENSSL_BLOCK **)0x7e;
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x7e,0x70,"asn_pack.c");
    psVar2 = (stack_st_OPENSSL_BLOCK *)0x0;
  }
  else {
    psStack_98 = (stack_st_OPENSSL_BLOCK *)
                 (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar3,"asn_pack.c",0x62);
    unaff_s1 = iVar3;
    if (psStack_98 == (stack_st_OPENSSL_BLOCK *)0x0) {
      ppsVar10 = (stack_st_OPENSSL_BLOCK **)0x7e;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x7e,0x41,"asn_pack.c");
      psVar2 = (stack_st_OPENSSL_BLOCK *)0x0;
    }
    else {
      ppsVar10 = &psStack_70;
      psStack_70 = psStack_98;
      i2d_ASN1_SET(psVar2,(uchar **)ppsVar10,(undefined1 *)ppuStack_d8,0x10,0,0);
      if ((int *)d2i != (int *)0x0) {
        *(int *)d2i = iVar3;
      }
      psVar2 = psStack_98;
      if ((stack_st_OPENSSL_BLOCK **)len != (stack_st_OPENSSL_BLOCK **)0x0) {
        *(stack_st_OPENSSL_BLOCK **)len = psStack_98;
      }
    }
  }
  if (puStack_6c == *(undefined4 **)puStack_dc) {
    return psVar2;
  }
  pcStack_94 = ASN1_unpack_string;
  puVar7 = puStack_6c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_e4 = PTR___stack_chk_guard_006a9ae8;
  uStack_a0 = puVar7[2];
  ppsVar9 = (stack_st_OPENSSL_BLOCK **)*puVar7;
  puVar7 = &uStack_a0;
  puStack_b0 = &_gp;
  iStack_9c = *(int *)PTR___stack_chk_guard_006a9ae8;
  psVar2 = (stack_st_OPENSSL_BLOCK *)(*(code *)ppsVar10)(0);
  if (psVar2 == (stack_st_OPENSSL_BLOCK *)0x0) {
    ppsVar9 = (stack_st_OPENSSL_BLOCK **)&DAT_0000006e;
    uStack_b8 = 0x79;
    puVar7 = (undefined4 *)&DAT_00000088;
    psStack_a4 = psVar2;
    (**(code **)(puStack_b0 + -0x6eac))(0xd,0x88,0x6e,"asn_pack.c");
    psVar2 = psStack_a4;
  }
  if (iStack_9c == *(int *)puStack_e4) {
    return psVar2;
  }
  pcStack_cc = ASN1_pack_string;
  iVar3 = iStack_9c;
  (**(code **)(puStack_b0 + -0x5330))();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iStack_ec = *(int *)PTR___stack_chk_guard_006a9ae8;
  iStack_e0 = unaff_s1;
  ppsStack_d4 = (stack_st_OPENSSL_BLOCK **)len;
  piStack_d0 = (int *)d2i;
  if (ppsVar9 == (stack_st_OPENSSL_BLOCK **)0x0) {
    psVar2 = (stack_st_OPENSSL_BLOCK *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
    if (psVar2 != (stack_st_OPENSSL_BLOCK *)0x0) goto LAB_0060f614;
LAB_0060f754:
    ppsVar10 = (stack_st_OPENSSL_BLOCK **)&DAT_00000041;
    piVar8 = (int *)&DAT_0000007c;
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x7c,0x41,"asn_pack.c",0x86);
    psVar5 = (stack_st_OPENSSL_BLOCK *)0x0;
  }
  else {
    psVar2 = *ppsVar9;
    if (psVar2 == (stack_st_OPENSSL_BLOCK *)0x0) {
      psVar2 = (stack_st_OPENSSL_BLOCK *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
      if (psVar2 == (stack_st_OPENSSL_BLOCK *)0x0) goto LAB_0060f754;
      *ppsVar9 = psVar2;
    }
LAB_0060f614:
    iVar4 = (*(code *)puVar7)(iVar3,0);
    (psVar2->stack).num = iVar4;
    if (iVar4 == 0) {
      ppsVar10 = (stack_st_OPENSSL_BLOCK **)&DAT_00000070;
      piVar8 = (int *)&DAT_0000007c;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x7c,0x70,"asn_pack.c",0x8f);
    }
    else {
      ppsVar10 = (stack_st_OPENSSL_BLOCK **)&DAT_00000092;
      iStack_f0 = (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar4,"asn_pack.c");
      if (iStack_f0 != 0) {
        piVar8 = &iStack_f0;
        (psVar2->stack).sorted = iStack_f0;
        (*(code *)puVar7)(iVar3,piVar8);
        psVar5 = psVar2;
        goto LAB_0060f670;
      }
      ppsVar10 = (stack_st_OPENSSL_BLOCK **)&DAT_00000041;
      piVar8 = (int *)&DAT_0000007c;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x7c,0x41,"asn_pack.c",0x93);
    }
    if (ppsVar9 == (stack_st_OPENSSL_BLOCK **)0x0) {
      (*(code *)PTR_ASN1_STRING_free_006a879c)(psVar2);
      psVar5 = (stack_st_OPENSSL_BLOCK *)0x0;
    }
    else {
      psVar5 = *ppsVar9;
      if (psVar5 == (stack_st_OPENSSL_BLOCK *)0x0) {
        (*(code *)PTR_ASN1_STRING_free_006a879c)(psVar2);
        *ppsVar9 = (stack_st_OPENSSL_BLOCK *)0x0;
      }
      else {
        psVar5 = (stack_st_OPENSSL_BLOCK *)0x0;
      }
    }
  }
LAB_0060f670:
  if (iStack_ec == *(int *)puVar1) {
    return psVar5;
  }
  iVar3 = iStack_ec;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (ppsVar10 == (stack_st_OPENSSL_BLOCK **)0x0) {
    psVar2 = (stack_st_OPENSSL_BLOCK *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
    if (psVar2 == (stack_st_OPENSSL_BLOCK *)0x0) {
LAB_0060f874:
      uVar11 = 0x41;
      uVar6 = 0xac;
      goto LAB_0060f888;
    }
  }
  else {
    psVar2 = *ppsVar10;
    if (psVar2 == (stack_st_OPENSSL_BLOCK *)0x0) {
      psVar2 = (stack_st_OPENSSL_BLOCK *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
      if (psVar2 == (stack_st_OPENSSL_BLOCK *)0x0) goto LAB_0060f874;
      *ppsVar10 = psVar2;
    }
  }
  if ((psVar2->stack).sorted != 0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)();
    (psVar2->stack).sorted = 0;
  }
  iVar3 = (*(code *)PTR_ASN1_item_i2d_006a8678)(iVar3,&(psVar2->stack).sorted,piVar8);
  (psVar2->stack).num = iVar3;
  if (iVar3 == 0) {
    uVar11 = 0x70;
    uVar6 = 0xba;
  }
  else {
    if ((psVar2->stack).sorted != 0) {
      return psVar2;
    }
    uVar11 = 0x41;
    uVar6 = 0xbe;
  }
LAB_0060f888:
  (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xc6,uVar11,"asn_pack.c",uVar6);
  return (stack_st_OPENSSL_BLOCK *)0x0;
}

