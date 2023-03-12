
uchar * ASN1_seq_pack(stack_st_OPENSSL_BLOCK *safes,undefined1 *i2d,uchar **buf,int *len)

{
  undefined *puVar1;
  int iVar2;
  uchar *puVar3;
  int iVar4;
  undefined4 uVar5;
  uchar **pp;
  undefined4 *puVar6;
  int *piVar7;
  int **ppiVar8;
  undefined4 uVar9;
  uchar *unaff_s0;
  int *piVar10;
  int unaff_s1;
  int iStack_a8;
  int iStack_a4;
  undefined *puStack_a0;
  int iStack_9c;
  undefined *puStack_98;
  undefined1 *puStack_94;
  uchar **ppuStack_90;
  code *pcStack_8c;
  undefined4 uStack_78;
  undefined *puStack_70;
  uchar *puStack_64;
  undefined4 uStack_60;
  int iStack_5c;
  uchar *puStack_58;
  code *pcStack_54;
  uchar *local_30;
  undefined4 *local_2c;
  
  puStack_98 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(undefined4 **)PTR___stack_chk_guard_006aabf0;
  iVar2 = i2d_ASN1_SET(safes,(uchar **)0x0,i2d,0x10,0,0);
  if (iVar2 == 0) {
    pp = (uchar **)0x7e;
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x7e,0x70,"asn_pack.c");
    puVar3 = (uchar *)0x0;
  }
  else {
    unaff_s0 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar2,"asn_pack.c",0x5f);
    unaff_s1 = iVar2;
    if (unaff_s0 == (uchar *)0x0) {
      pp = (uchar **)0x7e;
      (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x7e,0x41,"asn_pack.c");
      puVar3 = (uchar *)0x0;
    }
    else {
      pp = &local_30;
      local_30 = unaff_s0;
      i2d_ASN1_SET(safes,pp,i2d,0x10,0,0);
      if (len != (int *)0x0) {
        *len = iVar2;
      }
      puVar3 = unaff_s0;
      if (buf != (uchar **)0x0) {
        *buf = unaff_s0;
      }
    }
  }
  if (local_2c == *(undefined4 **)puStack_98) {
    return puVar3;
  }
  pcStack_54 = ASN1_unpack_string;
  puVar6 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puStack_a0 = PTR___stack_chk_guard_006aabf0;
  uStack_60 = puVar6[2];
  ppiVar8 = (int **)*puVar6;
  puVar6 = &uStack_60;
  puStack_70 = &_gp;
  iStack_5c = *(int *)PTR___stack_chk_guard_006aabf0;
  puStack_58 = unaff_s0;
  puVar3 = (uchar *)(*(code *)pp)(0);
  if (puVar3 == (uchar *)0x0) {
    ppiVar8 = (int **)&DAT_0000006e;
    uStack_78 = 0x74;
    puVar6 = (undefined4 *)&DAT_00000088;
    puStack_64 = puVar3;
    (**(code **)(puStack_70 + -0x6eb0))(0xd,0x88,0x6e,"asn_pack.c");
    puVar3 = puStack_64;
  }
  if (iStack_5c == *(int *)puStack_a0) {
    return puVar3;
  }
  pcStack_8c = ASN1_pack_string;
  iVar2 = iStack_5c;
  (**(code **)(puStack_70 + -0x5328))();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStack_a4 = *(int *)PTR___stack_chk_guard_006aabf0;
  iStack_9c = unaff_s1;
  puStack_94 = i2d;
  ppuStack_90 = buf;
  if (ppiVar8 == (int **)0x0) {
    piVar10 = (int *)(*(code *)PTR_ASN1_STRING_new_006a98b4)();
    if (piVar10 != (int *)0x0) goto LAB_0061083c;
LAB_00610928:
    ppiVar8 = (int **)&DAT_00000041;
    uVar5 = 0x81;
LAB_006108f8:
    piVar7 = (int *)&DAT_0000007c;
    (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x7c,ppiVar8,"asn_pack.c",uVar5);
    piVar10 = (int *)0x0;
  }
  else {
    piVar10 = *ppiVar8;
    if (piVar10 == (int *)0x0) {
      piVar10 = (int *)(*(code *)PTR_ASN1_STRING_new_006a98b4)();
      if (piVar10 == (int *)0x0) goto LAB_00610928;
      *ppiVar8 = piVar10;
    }
LAB_0061083c:
    iVar4 = (*(code *)puVar6)(iVar2,0);
    *piVar10 = iVar4;
    if (iVar4 == 0) {
      ppiVar8 = (int **)&DAT_00000070;
      uVar5 = 0x88;
      goto LAB_006108f8;
    }
    ppiVar8 = (int **)&DAT_0000008b;
    iStack_a8 = (*(code *)PTR_CRYPTO_malloc_006a8108)(iVar4,"asn_pack.c");
    if (iStack_a8 == 0) {
      ppiVar8 = (int **)&DAT_00000041;
      piVar7 = (int *)&DAT_0000007c;
      (*(code *)PTR_ERR_put_error_006a9030)(0xd,0x7c,0x41,"asn_pack.c",0x8c);
      piVar10 = (int *)0x0;
    }
    else {
      piVar7 = &iStack_a8;
      piVar10[2] = iStack_a8;
      (*(code *)puVar6)(iVar2,piVar7);
    }
  }
  if (iStack_a4 == *(int *)puVar1) {
    return (uchar *)piVar10;
  }
  iVar2 = iStack_a4;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (ppiVar8 == (int **)0x0) {
    piVar10 = (int *)(*(code *)PTR_ASN1_STRING_new_006a98b4)();
    if (piVar10 == (int *)0x0) {
LAB_00610a48:
      uVar9 = 0x41;
      uVar5 = 0x9e;
      goto LAB_00610a5c;
    }
  }
  else {
    piVar10 = *ppiVar8;
    if (piVar10 == (int *)0x0) {
      piVar10 = (int *)(*(code *)PTR_ASN1_STRING_new_006a98b4)();
      if (piVar10 == (int *)0x0) goto LAB_00610a48;
      *ppiVar8 = piVar10;
    }
  }
  if (piVar10[2] != 0) {
    (*(code *)PTR_CRYPTO_free_006a7f88)();
    piVar10[2] = 0;
  }
  iVar2 = (*(code *)PTR_ASN1_item_i2d_006a979c)(iVar2,piVar10 + 2,piVar7);
  *piVar10 = iVar2;
  if (iVar2 == 0) {
    uVar9 = 0x70;
    uVar5 = 0xaa;
  }
  else {
    if (piVar10[2] != 0) {
      return (uchar *)piVar10;
    }
    uVar9 = 0x41;
    uVar5 = 0xae;
  }
LAB_00610a5c:
  (*(code *)PTR_ERR_put_error_006a9030)(0xd,0xc6,uVar9,"asn_pack.c",uVar5);
  return (uchar *)0x0;
}

