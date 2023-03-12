
uchar * ASN1_seq_pack(stack_st_OPENSSL_BLOCK *safes,undefined1 *i2d,uchar **buf,int *len)

{
  undefined *puVar1;
  int iVar2;
  uchar *puVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  uchar **pp;
  undefined4 *puVar7;
  int *piVar8;
  int **ppiVar9;
  int **ppiVar10;
  undefined4 uVar11;
  uchar *unaff_s0;
  int unaff_s1;
  int *piVar12;
  int iStack_b0;
  int iStack_ac;
  undefined *puStack_a4;
  int iStack_a0;
  undefined *puStack_9c;
  undefined1 *puStack_98;
  uchar **ppuStack_94;
  int *piStack_90;
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
  
  puStack_9c = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(undefined4 **)PTR___stack_chk_guard_006a9ae8;
  iVar2 = i2d_ASN1_SET(safes,(uchar **)0x0,i2d,0x10,0,0);
  if (iVar2 == 0) {
    pp = (uchar **)0x7e;
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x7e,0x70,"asn_pack.c");
    puVar3 = (uchar *)0x0;
  }
  else {
    unaff_s0 = (uchar *)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar2,"asn_pack.c",0x62);
    unaff_s1 = iVar2;
    if (unaff_s0 == (uchar *)0x0) {
      pp = (uchar **)0x7e;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x7e,0x41,"asn_pack.c");
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
  if (local_2c == *(undefined4 **)puStack_9c) {
    return puVar3;
  }
  pcStack_54 = ASN1_unpack_string;
  puVar7 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puStack_a4 = PTR___stack_chk_guard_006a9ae8;
  uStack_60 = puVar7[2];
  ppiVar9 = (int **)*puVar7;
  puVar7 = &uStack_60;
  puStack_70 = &_gp;
  iStack_5c = *(int *)PTR___stack_chk_guard_006a9ae8;
  puStack_58 = unaff_s0;
  puVar3 = (uchar *)(*(code *)pp)(0);
  if (puVar3 == (uchar *)0x0) {
    ppiVar9 = (int **)&DAT_0000006e;
    uStack_78 = 0x79;
    puVar7 = (undefined4 *)&DAT_00000088;
    puStack_64 = puVar3;
    (**(code **)(puStack_70 + -0x6eac))(0xd,0x88,0x6e,"asn_pack.c");
    puVar3 = puStack_64;
  }
  if (iStack_5c == *(int *)puStack_a4) {
    return puVar3;
  }
  pcStack_8c = ASN1_pack_string;
  iVar2 = iStack_5c;
  (**(code **)(puStack_70 + -0x5330))();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iStack_ac = *(int *)PTR___stack_chk_guard_006a9ae8;
  iStack_a0 = unaff_s1;
  puStack_98 = i2d;
  ppuStack_94 = buf;
  piStack_90 = len;
  if (ppiVar9 == (int **)0x0) {
    piVar12 = (int *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
    if (piVar12 != (int *)0x0) goto LAB_0060f614;
LAB_0060f754:
    ppiVar10 = (int **)&DAT_00000041;
    piVar8 = (int *)&DAT_0000007c;
    (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x7c,0x41,"asn_pack.c",0x86);
    piVar5 = (int *)0x0;
  }
  else {
    piVar12 = *ppiVar9;
    if (piVar12 == (int *)0x0) {
      piVar12 = (int *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
      if (piVar12 == (int *)0x0) goto LAB_0060f754;
      *ppiVar9 = piVar12;
    }
LAB_0060f614:
    iVar4 = (*(code *)puVar7)(iVar2,0);
    *piVar12 = iVar4;
    if (iVar4 == 0) {
      ppiVar10 = (int **)&DAT_00000070;
      piVar8 = (int *)&DAT_0000007c;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x7c,0x70,"asn_pack.c",0x8f);
    }
    else {
      ppiVar10 = (int **)&DAT_00000092;
      iStack_b0 = (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar4,"asn_pack.c");
      if (iStack_b0 != 0) {
        piVar8 = &iStack_b0;
        piVar12[2] = iStack_b0;
        (*(code *)puVar7)(iVar2,piVar8);
        piVar5 = piVar12;
        goto LAB_0060f670;
      }
      ppiVar10 = (int **)&DAT_00000041;
      piVar8 = (int *)&DAT_0000007c;
      (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0x7c,0x41,"asn_pack.c",0x93);
    }
    if (ppiVar9 == (int **)0x0) {
      (*(code *)PTR_ASN1_STRING_free_006a879c)(piVar12);
      piVar5 = (int *)0x0;
    }
    else {
      piVar5 = *ppiVar9;
      if (piVar5 == (int *)0x0) {
        (*(code *)PTR_ASN1_STRING_free_006a879c)(piVar12);
        *ppiVar9 = (int *)0x0;
      }
      else {
        piVar5 = (int *)0x0;
      }
    }
  }
LAB_0060f670:
  if (iStack_ac == *(int *)puVar1) {
    return (uchar *)piVar5;
  }
  iVar2 = iStack_ac;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (ppiVar10 == (int **)0x0) {
    piVar12 = (int *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
    if (piVar12 == (int *)0x0) {
LAB_0060f874:
      uVar11 = 0x41;
      uVar6 = 0xac;
      goto LAB_0060f888;
    }
  }
  else {
    piVar12 = *ppiVar10;
    if (piVar12 == (int *)0x0) {
      piVar12 = (int *)(*(code *)PTR_ASN1_STRING_new_006a8790)();
      if (piVar12 == (int *)0x0) goto LAB_0060f874;
      *ppiVar10 = piVar12;
    }
  }
  if (piVar12[2] != 0) {
    (*(code *)PTR_CRYPTO_free_006a6e88)();
    piVar12[2] = 0;
  }
  iVar2 = (*(code *)PTR_ASN1_item_i2d_006a8678)(iVar2,piVar12 + 2,piVar8);
  *piVar12 = iVar2;
  if (iVar2 == 0) {
    uVar11 = 0x70;
    uVar6 = 0xba;
  }
  else {
    if (piVar12[2] != 0) {
      return (uchar *)piVar12;
    }
    uVar11 = 0x41;
    uVar6 = 0xbe;
  }
LAB_0060f888:
  (*(code *)PTR_ERR_put_error_006a7f34)(0xd,0xc6,uVar11,"asn_pack.c",uVar6);
  return (uchar *)0x0;
}

