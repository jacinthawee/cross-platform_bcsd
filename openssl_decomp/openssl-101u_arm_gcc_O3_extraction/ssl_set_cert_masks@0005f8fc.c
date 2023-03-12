
void ssl_set_cert_masks(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  ASN1_OBJECT *o;
  EVP_PKEY *pkey;
  EVP_PKEY *pEVar3;
  uint uVar4;
  X509 *pXVar5;
  EVP_PKEY *pkey_00;
  int iVar6;
  uint uVar7;
  EVP_PKEY *pEVar8;
  uint uVar9;
  EVP_PKEY *pEVar10;
  EVP_PKEY *pEVar11;
  EVP_PKEY *pEVar12;
  uint uVar13;
  uint uVar14;
  X509 *x;
  uint local_4c;
  int local_48;
  EVP_PKEY *local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  int local_30;
  int local_2c [2];
  
  local_30 = 0;
  local_2c[0] = 0;
  if (param_1 != 0) {
    local_38 = *(uint *)(param_1 + 0x1c);
    if ((*(uint *)(param_2 + 0x20) & 8) == 0) {
      iVar6 = 0x400;
    }
    else {
      iVar6 = 0x200;
    }
    if (*(RSA **)(param_1 + 0x18) == (RSA *)0x0) {
      local_34 = local_38;
      if (local_38 != 0) {
        local_38 = 1;
        local_34 = local_38;
      }
    }
    else if (local_38 == 0) {
      local_38 = 1;
      iVar1 = RSA_size(*(RSA **)(param_1 + 0x18));
      local_34 = (uint)(iVar6 + iVar1 * -8 < 0 == SBORROW4(iVar6,iVar1 * 8));
    }
    else {
      local_38 = 1;
      local_34 = 1;
    }
    local_40 = *(uint *)(param_1 + 0x24);
    if (*(DH **)(param_1 + 0x20) == (DH *)0x0) {
      local_3c = local_40;
      if (local_40 != 0) {
        local_40 = 1;
        local_3c = local_40;
      }
    }
    else if (local_40 == 0) {
      local_40 = 1;
      iVar1 = DH_size(*(DH **)(param_1 + 0x20));
      local_3c = (uint)(iVar6 + iVar1 * -8 < 0 == SBORROW4(iVar6,iVar1 * 8));
    }
    else {
      local_40 = 1;
      local_3c = 1;
    }
    if (*(int *)(param_1 + 0x28) == 0) {
      local_48 = *(int *)(param_1 + 0x2c);
      if (local_48 != 0) {
        local_48 = 1;
      }
    }
    else {
      local_48 = 1;
    }
    pEVar10 = *(EVP_PKEY **)(param_1 + 0x30);
    pEVar11 = pEVar10;
    if ((pEVar10 != (EVP_PKEY *)0x0) &&
       (pEVar10 = *(EVP_PKEY **)(param_1 + 0x34), pEVar11 = pEVar10, pEVar10 != (EVP_PKEY *)0x0)) {
      iVar1 = EVP_PKEY_size(pEVar10);
      pEVar10 = (EVP_PKEY *)0x1;
      if (iVar6 + iVar1 * -8 < 0 == SBORROW4(iVar6,iVar1 * 8)) {
        pEVar11 = (EVP_PKEY *)0x1;
      }
      else {
        pEVar11 = (EVP_PKEY *)0x0;
      }
    }
    local_44 = *(EVP_PKEY **)(param_1 + 0x3c);
    if ((local_44 == (EVP_PKEY *)0x0) ||
       (local_44 = *(EVP_PKEY **)(param_1 + 0x40), local_44 == (EVP_PKEY *)0x0)) {
      iVar1 = *(int *)(param_1 + 0x48);
      pEVar8 = pEVar10;
    }
    else {
      iVar1 = *(int *)(param_1 + 0x48);
      pEVar8 = (EVP_PKEY *)0x1;
      local_44 = (EVP_PKEY *)0x1;
    }
    if (iVar1 == 0) {
      pkey_00 = *(EVP_PKEY **)(param_1 + 0x54);
    }
    else {
      iVar1 = *(int *)(param_1 + 0x4c);
      if (iVar1 != 0) {
        iVar1 = 1;
      }
      pkey_00 = *(EVP_PKEY **)(param_1 + 0x54);
    }
    pEVar12 = pkey_00;
    if ((pkey_00 != (EVP_PKEY *)0x0) &&
       (pkey_00 = *(EVP_PKEY **)(param_1 + 0x58), pEVar12 = pkey_00, pkey_00 != (EVP_PKEY *)0x0)) {
      iVar2 = EVP_PKEY_size(pkey_00);
      pkey_00 = (EVP_PKEY *)0x1;
      if (iVar6 + iVar2 * -8 < 0 == SBORROW4(iVar6,iVar2 * 8)) {
        pEVar12 = (EVP_PKEY *)0x1;
      }
      else {
        pEVar12 = (EVP_PKEY *)0x0;
      }
    }
    pkey = *(EVP_PKEY **)(param_1 + 0x60);
    pEVar3 = pkey;
    if ((pkey != (EVP_PKEY *)0x0) &&
       (pkey = *(EVP_PKEY **)(param_1 + 100), pEVar3 = pkey, pkey != (EVP_PKEY *)0x0)) {
      iVar2 = EVP_PKEY_size(pkey);
      pEVar3 = (EVP_PKEY *)0x1;
      if (iVar6 + iVar2 * -8 < 0 == SBORROW4(iVar6,iVar2 * 8)) {
        pkey = (EVP_PKEY *)0x1;
      }
      else {
        pkey = (EVP_PKEY *)0x0;
      }
    }
    x = *(X509 **)(param_1 + 0x6c);
    pXVar5 = x;
    if ((x != (X509 *)0x0) && (pXVar5 = *(X509 **)(param_1 + 0x70), pXVar5 != (X509 *)0x0)) {
      pXVar5 = (X509 *)0x1;
    }
    uVar7 = *(uint *)(param_1 + 0x84);
    if (uVar7 == 0) {
      uVar13 = 0x100;
    }
    else if (*(int *)(param_1 + 0x88) == 0) {
      uVar13 = 0x100;
      uVar7 = 0;
    }
    else {
      uVar13 = 0x300;
      uVar7 = 0x200;
    }
    uVar14 = uVar7;
    if ((*(int *)(param_1 + 0x78) != 0) && (*(int *)(param_1 + 0x7c) != 0)) {
      uVar7 = 0x200;
      uVar14 = uVar13;
    }
    if ((pEVar10 != (EVP_PKEY *)0x0) || ((int)(((uint)local_44 & local_38) << 0x1f) < 0)) {
      uVar7 = uVar7 | 1;
    }
    if (pEVar11 == (EVP_PKEY *)0x0) {
      pEVar11 = pEVar8;
      if (local_34 == 0) {
        pEVar11 = (EVP_PKEY *)0x0;
      }
    }
    else {
      pEVar11 = (EVP_PKEY *)0x1;
    }
    if (local_3c != 0) {
      pEVar11 = (EVP_PKEY *)((uint)pEVar11 | 8);
    }
    if (local_40 != 0) {
      uVar7 = uVar7 | 8;
    }
    if (pkey_00 != (EVP_PKEY *)0x0) {
      uVar7 = uVar7 | 2;
    }
    if (pEVar12 != (EVP_PKEY *)0x0) {
      pEVar11 = (EVP_PKEY *)((uint)pEVar11 | 2);
    }
    if (pEVar3 != (EVP_PKEY *)0x0) {
      uVar7 = uVar7 | 4;
    }
    if (pkey != (EVP_PKEY *)0x0) {
      pEVar11 = (EVP_PKEY *)((uint)pEVar11 | 4);
    }
    if (pEVar8 == (EVP_PKEY *)0x0) {
      uVar4 = 4;
      uVar13 = 6;
      pEVar10 = (EVP_PKEY *)0x2;
    }
    else {
      uVar14 = uVar14 | 1;
      uVar4 = 5;
      uVar13 = 7;
      pEVar10 = (EVP_PKEY *)0x3;
      pEVar8 = (EVP_PKEY *)0x1;
    }
    if (iVar1 == 0) {
      uVar9 = uVar14 | 4;
      uVar13 = uVar4;
      pEVar10 = pEVar8;
      uVar4 = uVar14;
    }
    else {
      uVar4 = uVar14 | 2;
      uVar9 = uVar14 | 6;
    }
    if (pXVar5 != (X509 *)0x0) {
      X509_check_purpose(x,-1,0);
      if ((int)(x->ex_flags << 0x1e) < 0) {
        uVar14 = x->ex_kusage & 8;
        local_4c = x->ex_kusage & 0x80;
      }
      else {
        uVar14 = 1;
        local_4c = uVar14;
      }
      pEVar8 = X509_get_pubkey(x);
      local_44 = pEVar8;
      if (pEVar8 != (EVP_PKEY *)0x0) {
        local_44 = (EVP_PKEY *)EVP_PKEY_bits(pEVar8);
      }
      EVP_PKEY_free(pEVar8);
      if ((x->sig_alg != (X509_ALGOR *)0x0) && (o = x->sig_alg->algorithm, o != (ASN1_OBJECT *)0x0))
      {
        iVar6 = OBJ_obj2nid(o);
        OBJ_find_sigid_algs(iVar6,local_2c,&local_30);
      }
      if (uVar14 != 0) {
        if (local_30 == 6 || local_30 == 0x13) {
          uVar7 = uVar7 | 0x20;
          uVar9 = uVar4 | 0x14;
          if ((int)local_44 < 0xa4) {
            pEVar11 = (EVP_PKEY *)((uint)pEVar11 | 0x20);
            uVar13 = (uint)pEVar10 | 0x14;
          }
        }
        if (local_30 == 0x198) {
          uVar7 = uVar7 | 0x40;
          uVar9 = uVar9 | 0x10;
          if ((int)local_44 < 0xa4) {
            pEVar11 = (EVP_PKEY *)((uint)pEVar11 | 0x40);
            uVar13 = uVar13 | 0x10;
          }
        }
      }
      if (local_4c != 0) {
        uVar9 = uVar9 | 0x40;
        uVar13 = uVar13 | 0x40;
      }
    }
    if (local_48 != 0) {
      uVar7 = uVar7 | 0x80;
      pEVar11 = (EVP_PKEY *)((uint)pEVar11 | 0x80);
    }
    *(uint *)(param_1 + 0x10) = (uint)pEVar11 | 0x100;
    *(uint *)(param_1 + 8) = uVar7 | 0x100;
    *(uint *)(param_1 + 0xc) = uVar9 | 0x80;
    *(uint *)(param_1 + 0x14) = uVar13 | 0x80;
    *(undefined4 *)(param_1 + 4) = 1;
    return;
  }
  return;
}

