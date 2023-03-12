
void ssl_set_cert_masks(int param_1,int param_2)

{
  ASN1_OBJECT *o;
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  DH *dh;
  int iVar5;
  uint uVar6;
  EVP_PKEY *pkey;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int in_GS_OFFSET;
  bool bVar13;
  bool bVar14;
  bool bVar15;
  bool bVar16;
  bool bVar17;
  bool bVar18;
  bool bVar19;
  bool bVar20;
  uint local_60;
  X509 *local_5c;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  int local_28;
  int local_24;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  local_28 = 0;
  local_24 = 0;
  if (param_1 == 0) goto LAB_080c2040;
  iVar9 = (-(uint)((*(uint *)(param_2 + 0x20) & 8) == 0) & 0x200) + 0x200;
  if (*(RSA **)(param_1 + 0x18) == (RSA *)0x0) {
    bVar14 = *(int *)(param_1 + 0x1c) != 0;
    bVar15 = *(int *)(param_1 + 0x1c) != 0;
    dh = *(DH **)(param_1 + 0x20);
    if (dh != (DH *)0x0) goto LAB_080c1ddc;
LAB_080c22b0:
    bVar16 = *(int *)(param_1 + 0x24) != 0;
    iVar5 = *(int *)(param_1 + 0x28);
    bVar17 = *(int *)(param_1 + 0x24) != 0;
  }
  else {
    bVar14 = true;
    bVar15 = true;
    if (*(int *)(param_1 + 0x1c) == 0) {
      iVar5 = RSA_size(*(RSA **)(param_1 + 0x18));
      bVar15 = iVar5 * 8 <= iVar9;
    }
    dh = *(DH **)(param_1 + 0x20);
    if (dh == (DH *)0x0) goto LAB_080c22b0;
LAB_080c1ddc:
    bVar16 = true;
    bVar17 = true;
    if (*(int *)(param_1 + 0x24) == 0) {
      iVar5 = DH_size(dh);
      bVar17 = iVar5 * 8 <= iVar9;
    }
    iVar5 = *(int *)(param_1 + 0x28);
  }
  bVar20 = true;
  if (iVar5 == 0) {
    bVar20 = *(int *)(param_1 + 0x2c) != 0;
  }
  if ((*(int *)(param_1 + 0x30) == 0) || (*(EVP_PKEY **)(param_1 + 0x34) == (EVP_PKEY *)0x0)) {
    uVar12 = 0;
    local_50 = 0;
    if (*(int *)(param_1 + 0x3c) != 0) goto LAB_080c1e4b;
LAB_080c223d:
    bVar13 = false;
    local_60 = uVar12;
    if (*(int *)(param_1 + 0x48) != 0) goto LAB_080c1e74;
LAB_080c2258:
    bVar18 = false;
  }
  else {
    uVar12 = 1;
    iVar5 = EVP_PKEY_size(*(EVP_PKEY **)(param_1 + 0x34));
    local_50 = (uint)(iVar5 * 8 <= iVar9);
    if (*(int *)(param_1 + 0x3c) == 0) goto LAB_080c223d;
LAB_080c1e4b:
    local_60 = 1;
    if (*(int *)(param_1 + 0x40) == 0) {
      local_60 = uVar12;
    }
    bVar13 = *(int *)(param_1 + 0x40) != 0;
    if (*(int *)(param_1 + 0x48) == 0) goto LAB_080c2258;
LAB_080c1e74:
    bVar18 = *(int *)(param_1 + 0x4c) != 0;
  }
  if ((*(int *)(param_1 + 0x54) == 0) || (*(EVP_PKEY **)(param_1 + 0x58) == (EVP_PKEY *)0x0)) {
    bVar4 = false;
    bVar1 = false;
  }
  else {
    iVar5 = EVP_PKEY_size(*(EVP_PKEY **)(param_1 + 0x58));
    bVar4 = true;
    bVar1 = iVar5 * 8 <= iVar9;
  }
  if ((*(int *)(param_1 + 0x60) == 0) || (*(EVP_PKEY **)(param_1 + 100) == (EVP_PKEY *)0x0)) {
    local_5c = *(X509 **)(param_1 + 0x6c);
    bVar3 = false;
    bVar2 = false;
    if (local_5c != (X509 *)0x0) goto LAB_080c1efb;
LAB_080c21d3:
    bVar19 = false;
    if (*(int *)(param_1 + 0x84) != 0) goto LAB_080c1f17;
LAB_080c21f0:
    uVar10 = 0;
    uVar8 = 0x100;
    if (*(int *)(param_1 + 0x78) != 0) goto LAB_080c1f48;
    uVar10 = 0;
    uVar11 = uVar10;
  }
  else {
    iVar5 = EVP_PKEY_size(*(EVP_PKEY **)(param_1 + 100));
    local_5c = *(X509 **)(param_1 + 0x6c);
    bVar3 = true;
    bVar2 = iVar5 * 8 <= iVar9;
    if (local_5c == (X509 *)0x0) goto LAB_080c21d3;
LAB_080c1efb:
    bVar19 = *(int *)(param_1 + 0x70) != 0;
    if (*(int *)(param_1 + 0x84) == 0) goto LAB_080c21f0;
LAB_080c1f17:
    uVar8 = (-(uint)(*(int *)(param_1 + 0x88) == 0) & 0xfffffe00) + 0x300;
    uVar10 = ~-(uint)(*(int *)(param_1 + 0x88) == 0) & 0x200;
    uVar11 = uVar10;
    if (*(int *)(param_1 + 0x78) != 0) {
LAB_080c1f48:
      uVar11 = uVar10;
      if (*(int *)(param_1 + 0x7c) != 0) {
        uVar10 = uVar8;
        uVar11 = 0x200;
      }
    }
  }
  if ((uVar12 != 0) || ((bool)(bVar13 & bVar14))) {
    uVar11 = uVar11 | 1;
  }
  uVar12 = 1;
  if ((local_50 == 0) && (uVar12 = local_50, bVar15)) {
    uVar12 = local_60;
  }
  if (bVar17) {
    uVar12 = uVar12 | 8;
  }
  if (bVar16) {
    uVar11 = uVar11 | 8;
  }
  if (bVar4) {
    uVar11 = uVar11 | 2;
  }
  if (bVar1) {
    uVar12 = uVar12 | 2;
  }
  if (bVar3) {
    uVar11 = uVar11 | 4;
  }
  if (bVar2) {
    uVar12 = uVar12 | 4;
  }
  if (local_60 != 0) {
    uVar10 = uVar10 | 1;
    uVar8 = 5;
    uVar7 = 7;
    uVar6 = 3;
  }
  else {
    uVar8 = 4;
    uVar7 = 6;
    uVar6 = 2;
  }
  local_54 = (uint)(local_60 != 0);
  if (bVar18) {
    uVar10 = uVar10 | 2;
    uVar8 = uVar7;
    local_54 = uVar6;
  }
  local_60 = uVar10 | 4;
  uVar6 = uVar11;
  if (bVar19) {
    X509_check_purpose(local_5c,-1,0);
    if ((*(byte *)&local_5c->ex_flags & 2) == 0) {
      local_48 = 1;
      local_4c = 1;
    }
    else {
      local_4c = local_5c->ex_kusage & 0x80;
      local_48 = local_5c->ex_kusage & 8;
    }
    pkey = X509_get_pubkey(local_5c);
    local_50 = 0;
    if (pkey != (EVP_PKEY *)0x0) {
      local_50 = EVP_PKEY_bits(pkey);
    }
    EVP_PKEY_free(pkey);
    if ((local_5c->sig_alg != (X509_ALGOR *)0x0) &&
       (o = local_5c->sig_alg->algorithm, o != (ASN1_OBJECT *)0x0)) {
      iVar9 = OBJ_obj2nid(o);
      OBJ_find_sigid_algs(iVar9,&local_24,&local_28);
    }
    if (local_48 != 0) {
      if ((local_28 == 6) || (local_28 == 0x13)) {
        local_60 = uVar10 | 0x14;
        uVar6 = uVar11 | 0x20;
        if (0xa3 < (int)local_50) goto LAB_080c2198;
        uVar12 = uVar12 | 0x20;
        uVar8 = local_54 | 0x14;
        if (local_28 != 0x198) goto LAB_080c21a3;
        uVar6 = uVar11 | 0x60;
LAB_080c2396:
        uVar12 = uVar12 | 0x40;
        uVar8 = uVar8 | 0x10;
      }
      else {
LAB_080c2198:
        if (local_28 == 0x198) {
          uVar6 = uVar6 | 0x40;
          local_60 = local_60 | 0x10;
          if ((int)local_50 < 0xa4) goto LAB_080c2396;
        }
      }
    }
LAB_080c21a3:
    if (local_4c != 0) {
      local_60 = local_60 | 0x40;
      uVar8 = uVar8 | 0x40;
    }
  }
  if (bVar20) {
    uVar6 = uVar6 | 0x80;
    uVar12 = uVar12 | 0x80;
  }
  *(uint *)(param_1 + 8) = uVar6 | 0x100;
  *(uint *)(param_1 + 0x10) = uVar12 | 0x100;
  *(uint *)(param_1 + 0x14) = uVar8 | 0x80;
  *(undefined4 *)(param_1 + 4) = 1;
  *(uint *)(param_1 + 0xc) = local_60 | 0x80;
LAB_080c2040:
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return;
}

