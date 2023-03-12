
undefined4 ssl_get_server_send_cert(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  ASN1_OBJECT *o;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  int iVar7;
  EVP_PKEY *pkey;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int in_GS_OFFSET;
  bool bVar16;
  bool bVar17;
  bool bVar18;
  bool bVar19;
  bool bVar20;
  bool bVar21;
  bool bVar22;
  bool bVar23;
  uint local_64;
  uint local_60;
  X509 *local_58;
  int local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  int local_28;
  int local_24;
  int local_20;
  
  local_28 = 0;
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_24 = 0;
  iVar2 = *(int *)(param_1 + 0x98);
  iVar12 = *(int *)(*(int *)(param_1 + 0x58) + 0x344);
  if (iVar2 != 0) {
    iVar12 = (-(uint)((*(uint *)(iVar12 + 0x20) & 8) == 0) & 0x200) + 0x200;
    if (*(RSA **)(iVar2 + 0x18) == (RSA *)0x0) {
      bVar19 = *(int *)(iVar2 + 0x1c) != 0;
      bVar20 = *(int *)(iVar2 + 0x1c) != 0;
    }
    else {
      bVar19 = true;
      bVar20 = true;
      if (*(int *)(iVar2 + 0x1c) == 0) {
        iVar7 = RSA_size(*(RSA **)(iVar2 + 0x18));
        bVar20 = iVar7 * 8 <= iVar12;
      }
    }
    if (*(DH **)(iVar2 + 0x20) == (DH *)0x0) {
      bVar17 = *(int *)(iVar2 + 0x24) != 0;
      iVar7 = *(int *)(iVar2 + 0x28);
      bVar18 = *(int *)(iVar2 + 0x24) != 0;
    }
    else {
      bVar17 = true;
      bVar18 = true;
      if (*(int *)(iVar2 + 0x24) == 0) {
        iVar7 = DH_size(*(DH **)(iVar2 + 0x20));
        bVar18 = iVar7 * 8 <= iVar12;
      }
      iVar7 = *(int *)(iVar2 + 0x28);
    }
    bVar23 = true;
    if (iVar7 == 0) {
      bVar23 = *(int *)(iVar2 + 0x2c) != 0;
    }
    if ((*(int *)(iVar2 + 0x30) == 0) || (*(EVP_PKEY **)(iVar2 + 0x34) == (EVP_PKEY *)0x0)) {
      uVar15 = 0;
      local_48 = 0;
      if (*(int *)(iVar2 + 0x3c) != 0) goto LAB_080c2e0a;
LAB_080c325d:
      bVar16 = false;
      local_64 = uVar15;
      if (*(int *)(iVar2 + 0x48) != 0) goto LAB_080c2e33;
LAB_080c3278:
      bVar21 = false;
    }
    else {
      uVar15 = 1;
      iVar7 = EVP_PKEY_size(*(EVP_PKEY **)(iVar2 + 0x34));
      local_48 = (uint)(iVar7 * 8 <= iVar12);
      if (*(int *)(iVar2 + 0x3c) == 0) goto LAB_080c325d;
LAB_080c2e0a:
      local_64 = 1;
      if (*(int *)(iVar2 + 0x40) == 0) {
        local_64 = uVar15;
      }
      bVar16 = *(int *)(iVar2 + 0x40) != 0;
      if (*(int *)(iVar2 + 0x48) == 0) goto LAB_080c3278;
LAB_080c2e33:
      bVar21 = *(int *)(iVar2 + 0x4c) != 0;
    }
    if ((*(int *)(iVar2 + 0x54) == 0) || (*(EVP_PKEY **)(iVar2 + 0x58) == (EVP_PKEY *)0x0)) {
      bVar6 = false;
      bVar3 = false;
    }
    else {
      iVar7 = EVP_PKEY_size(*(EVP_PKEY **)(iVar2 + 0x58));
      bVar6 = true;
      bVar3 = iVar7 * 8 <= iVar12;
    }
    if ((*(int *)(iVar2 + 0x60) == 0) || (*(EVP_PKEY **)(iVar2 + 100) == (EVP_PKEY *)0x0)) {
      local_58 = *(X509 **)(iVar2 + 0x6c);
      bVar5 = false;
      bVar4 = false;
      if (local_58 != (X509 *)0x0) goto LAB_080c2eba;
LAB_080c31f3:
      bVar22 = false;
      if (*(int *)(iVar2 + 0x84) != 0) goto LAB_080c2ed6;
LAB_080c3210:
      uVar13 = 0;
      uVar11 = 0x100;
      if (*(int *)(iVar2 + 0x78) != 0) goto LAB_080c2f07;
      uVar13 = 0;
      uVar14 = uVar13;
    }
    else {
      iVar7 = EVP_PKEY_size(*(EVP_PKEY **)(iVar2 + 100));
      local_58 = *(X509 **)(iVar2 + 0x6c);
      bVar5 = true;
      bVar4 = iVar7 * 8 <= iVar12;
      if (local_58 == (X509 *)0x0) goto LAB_080c31f3;
LAB_080c2eba:
      bVar22 = *(int *)(iVar2 + 0x70) != 0;
      if (*(int *)(iVar2 + 0x84) == 0) goto LAB_080c3210;
LAB_080c2ed6:
      uVar11 = (-(uint)(*(int *)(iVar2 + 0x88) == 0) & 0xfffffe00) + 0x300;
      uVar13 = ~-(uint)(*(int *)(iVar2 + 0x88) == 0) & 0x200;
      uVar14 = uVar13;
      if (*(int *)(iVar2 + 0x78) != 0) {
LAB_080c2f07:
        uVar14 = uVar13;
        if (*(int *)(iVar2 + 0x7c) != 0) {
          uVar13 = uVar11;
          uVar14 = 0x200;
        }
      }
    }
    if ((uVar15 != 0) || ((bool)(bVar16 & bVar19))) {
      uVar14 = uVar14 | 1;
    }
    uVar15 = 1;
    if ((local_48 == 0) && (uVar15 = local_48, bVar20)) {
      uVar15 = local_64;
    }
    if (bVar18) {
      uVar15 = uVar15 | 8;
    }
    if (bVar17) {
      uVar14 = uVar14 | 8;
    }
    if (bVar6) {
      uVar14 = uVar14 | 2;
    }
    if (bVar3) {
      uVar15 = uVar15 | 2;
    }
    if (bVar5) {
      uVar14 = uVar14 | 4;
    }
    if (bVar4) {
      uVar15 = uVar15 | 4;
    }
    if (local_64 != 0) {
      uVar13 = uVar13 | 1;
      uVar11 = 5;
      uVar9 = 7;
      uVar10 = 3;
    }
    else {
      uVar11 = 4;
      uVar9 = 6;
      uVar10 = 2;
    }
    local_48 = (uint)(local_64 != 0);
    local_64 = uVar11;
    if (bVar21) {
      uVar13 = uVar13 | 2;
      local_64 = uVar9;
      local_48 = uVar10;
    }
    local_60 = uVar13 | 4;
    uVar11 = uVar14;
    if (bVar22) {
      X509_check_purpose(local_58,-1,0);
      if ((*(byte *)&local_58->ex_flags & 2) == 0) {
        local_4c = 1;
        local_44 = 1;
      }
      else {
        local_44 = local_58->ex_kusage & 0x80;
        local_4c = local_58->ex_kusage & 8;
      }
      pkey = X509_get_pubkey(local_58);
      local_50 = 0;
      if (pkey != (EVP_PKEY *)0x0) {
        local_50 = EVP_PKEY_bits(pkey);
      }
      EVP_PKEY_free(pkey);
      if ((local_58->sig_alg != (X509_ALGOR *)0x0) &&
         (o = local_58->sig_alg->algorithm, o != (ASN1_OBJECT *)0x0)) {
        iVar12 = OBJ_obj2nid(o);
        OBJ_find_sigid_algs(iVar12,&local_24,&local_28);
      }
      if (local_4c != 0) {
        if ((local_28 == 6) || (local_28 == 0x13)) {
          local_60 = uVar13 | 0x14;
          uVar11 = uVar14 | 0x20;
          if (0xa3 < local_50) goto LAB_080c31b0;
          uVar15 = uVar15 | 0x20;
          local_64 = local_48 | 0x14;
          if (local_28 != 0x198) goto LAB_080c31bb;
          uVar11 = uVar14 | 0x60;
LAB_080c33e6:
          uVar15 = uVar15 | 0x40;
          local_64 = local_64 | 0x10;
        }
        else {
LAB_080c31b0:
          if (local_28 == 0x198) {
            uVar11 = uVar11 | 0x40;
            local_60 = local_60 | 0x10;
            if (local_50 < 0xa4) goto LAB_080c33e6;
          }
        }
      }
LAB_080c31bb:
      if (local_44 != 0) {
        local_60 = local_60 | 0x40;
        local_64 = local_64 | 0x40;
      }
    }
    if (bVar23) {
      uVar11 = uVar11 | 0x80;
      uVar15 = uVar15 | 0x80;
    }
    *(uint *)(iVar2 + 8) = uVar11 | 0x100;
    *(uint *)(iVar2 + 0x10) = uVar15 | 0x100;
    *(undefined4 *)(iVar2 + 4) = 1;
    *(uint *)(iVar2 + 0xc) = local_60 | 0x80;
    *(uint *)(iVar2 + 0x14) = local_64 | 0x80;
    iVar12 = *(int *)(*(int *)(param_1 + 0x58) + 0x344);
  }
  uVar15 = *(uint *)(iVar12 + 0xc);
  if (((uVar15 & 0x60) == 0) && (uVar13 = *(uint *)(iVar12 + 0x10), (uVar13 & 0x40) == 0)) {
    if ((uVar15 & 2) != 0) {
      iVar12 = 0x24;
      goto LAB_080c302f;
    }
    if ((uVar15 & 4) != 0) {
      iVar12 = 0x30;
      goto LAB_080c302f;
    }
    if ((uVar13 & 2) != 0) {
      iVar12 = 0x18;
      goto LAB_080c302f;
    }
    if ((uVar13 & 1) != 0) {
      iVar12 = (uint)(*(int *)(iVar2 + 0x30) == 0) * 0xc;
      goto LAB_080c302f;
    }
    if ((uVar13 & 0x20) == 0) {
      if ((uVar13 & 0x100) == 0) {
        iVar12 = 0x54;
        if ((uVar13 & 0x200) == 0) {
          ERR_put_error(0x14,0x13d,0x44,"ssl_lib.c",0x92f);
          goto LAB_080c3430;
        }
      }
      else {
        iVar12 = 0x48;
      }
      goto LAB_080c302f;
    }
  }
  else {
    iVar12 = 0x3c;
LAB_080c302f:
    puVar1 = (undefined4 *)(iVar2 + 0x30 + iVar12);
    if (puVar1 != (undefined4 *)0x0) {
      uVar8 = *puVar1;
      goto LAB_080c303d;
    }
  }
LAB_080c3430:
  uVar8 = 0;
LAB_080c303d:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return uVar8;
}

