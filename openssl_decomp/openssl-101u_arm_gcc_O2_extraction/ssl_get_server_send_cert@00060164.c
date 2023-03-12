
int ssl_get_server_send_cert(int param_1)

{
  int iVar1;
  int iVar2;
  ASN1_OBJECT *o;
  EVP_PKEY *pkey;
  EVP_PKEY *pEVar3;
  uint uVar4;
  int iVar5;
  X509 *pXVar6;
  EVP_PKEY *pkey_00;
  int iVar7;
  uint uVar8;
  uint uVar9;
  EVP_PKEY *pEVar10;
  EVP_PKEY *pEVar11;
  X509 *x;
  EVP_PKEY *pEVar12;
  uint uVar13;
  uint uVar14;
  EVP_PKEY *local_50;
  uint local_4c;
  int local_48;
  EVP_PKEY *local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  int local_30;
  int local_2c [2];
  
  iVar7 = *(int *)(param_1 + 0x98);
  local_30 = 0;
  iVar5 = *(int *)(*(int *)(param_1 + 0x58) + 0x344);
  local_2c[0] = 0;
  if (iVar7 == 0) goto LAB_0006033a;
  local_38 = *(uint *)(iVar7 + 0x1c);
  if ((*(uint *)(iVar5 + 0x20) & 8) == 0) {
    iVar5 = 0x400;
  }
  else {
    iVar5 = 0x200;
  }
  if (*(RSA **)(iVar7 + 0x18) == (RSA *)0x0) {
    local_34 = local_38;
    if (local_38 != 0) {
      local_38 = 1;
      local_34 = local_38;
    }
  }
  else if (local_38 == 0) {
    local_38 = 1;
    iVar1 = RSA_size(*(RSA **)(iVar7 + 0x18));
    local_34 = (uint)(iVar5 + iVar1 * -8 < 0 == SBORROW4(iVar5,iVar1 * 8));
  }
  else {
    local_38 = 1;
    local_34 = 1;
  }
  local_40 = *(uint *)(iVar7 + 0x24);
  if (*(DH **)(iVar7 + 0x20) == (DH *)0x0) {
    local_3c = local_40;
    if (local_40 != 0) {
      local_40 = 1;
      local_3c = local_40;
    }
  }
  else if (local_40 == 0) {
    local_40 = 1;
    iVar1 = DH_size(*(DH **)(iVar7 + 0x20));
    local_3c = (uint)(iVar5 + iVar1 * -8 < 0 == SBORROW4(iVar5,iVar1 * 8));
  }
  else {
    local_40 = 1;
    local_3c = 1;
  }
  if (*(int *)(iVar7 + 0x28) == 0) {
    local_48 = *(int *)(iVar7 + 0x2c);
    if (local_48 != 0) {
      local_48 = 1;
    }
  }
  else {
    local_48 = 1;
  }
  pEVar10 = *(EVP_PKEY **)(iVar7 + 0x30);
  pEVar11 = pEVar10;
  if ((pEVar10 != (EVP_PKEY *)0x0) &&
     (pEVar10 = *(EVP_PKEY **)(iVar7 + 0x34), pEVar11 = pEVar10, pEVar10 != (EVP_PKEY *)0x0)) {
    iVar1 = EVP_PKEY_size(pEVar10);
    pEVar10 = (EVP_PKEY *)0x1;
    if (iVar5 + iVar1 * -8 < 0 == SBORROW4(iVar5,iVar1 * 8)) {
      pEVar11 = (EVP_PKEY *)0x1;
    }
    else {
      pEVar11 = (EVP_PKEY *)0x0;
    }
  }
  local_44 = *(EVP_PKEY **)(iVar7 + 0x3c);
  if ((local_44 == (EVP_PKEY *)0x0) ||
     (local_44 = *(EVP_PKEY **)(iVar7 + 0x40), local_44 == (EVP_PKEY *)0x0)) {
    iVar1 = *(int *)(iVar7 + 0x48);
    pEVar12 = pEVar10;
    if (iVar1 != 0) goto LAB_000601fc;
LAB_00060486:
    pkey_00 = *(EVP_PKEY **)(iVar7 + 0x54);
  }
  else {
    iVar1 = *(int *)(iVar7 + 0x48);
    local_44 = (EVP_PKEY *)0x1;
    pEVar12 = (EVP_PKEY *)0x1;
    if (iVar1 == 0) goto LAB_00060486;
LAB_000601fc:
    iVar1 = *(int *)(iVar7 + 0x4c);
    if (iVar1 != 0) {
      iVar1 = 1;
    }
    pkey_00 = *(EVP_PKEY **)(iVar7 + 0x54);
  }
  local_50 = pkey_00;
  if ((pkey_00 != (EVP_PKEY *)0x0) &&
     (pkey_00 = *(EVP_PKEY **)(iVar7 + 0x58), local_50 = pkey_00, pkey_00 != (EVP_PKEY *)0x0)) {
    local_50 = (EVP_PKEY *)0x1;
    iVar2 = EVP_PKEY_size(pkey_00);
    if (iVar5 + iVar2 * -8 < 0 == SBORROW4(iVar5,iVar2 * 8)) {
      pkey_00 = (EVP_PKEY *)0x1;
    }
    else {
      pkey_00 = (EVP_PKEY *)0x0;
    }
  }
  pkey = *(EVP_PKEY **)(iVar7 + 0x60);
  pEVar3 = pkey;
  if ((pkey != (EVP_PKEY *)0x0) &&
     (pkey = *(EVP_PKEY **)(iVar7 + 100), pEVar3 = pkey, pkey != (EVP_PKEY *)0x0)) {
    iVar2 = EVP_PKEY_size(pkey);
    pEVar3 = (EVP_PKEY *)0x1;
    if (iVar5 + iVar2 * -8 < 0 == SBORROW4(iVar5,iVar2 * 8)) {
      pkey = (EVP_PKEY *)0x1;
    }
    else {
      pkey = (EVP_PKEY *)0x0;
    }
  }
  x = *(X509 **)(iVar7 + 0x6c);
  pXVar6 = x;
  if ((x != (X509 *)0x0) && (pXVar6 = *(X509 **)(iVar7 + 0x70), pXVar6 != (X509 *)0x0)) {
    pXVar6 = (X509 *)0x1;
  }
  uVar8 = *(uint *)(iVar7 + 0x84);
  uVar13 = 0x100;
  if (uVar8 != 0) {
    if (*(int *)(iVar7 + 0x88) == 0) {
      uVar13 = 0x100;
      uVar8 = 0;
    }
    else {
      uVar13 = 0x300;
      uVar8 = 0x200;
    }
  }
  uVar14 = uVar8;
  if ((*(int *)(iVar7 + 0x78) != 0) && (*(int *)(iVar7 + 0x7c) != 0)) {
    uVar8 = 0x200;
    uVar14 = uVar13;
  }
  if ((pEVar10 != (EVP_PKEY *)0x0) || ((int)(((uint)local_44 & local_38) << 0x1f) < 0)) {
    uVar8 = uVar8 | 1;
  }
  if (pEVar11 == (EVP_PKEY *)0x0) {
    pEVar11 = pEVar12;
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
    uVar8 = uVar8 | 8;
  }
  if (local_50 != (EVP_PKEY *)0x0) {
    uVar8 = uVar8 | 2;
  }
  if (pkey_00 != (EVP_PKEY *)0x0) {
    pEVar11 = (EVP_PKEY *)((uint)pEVar11 | 2);
  }
  if (pEVar3 != (EVP_PKEY *)0x0) {
    uVar8 = uVar8 | 4;
  }
  if (pkey != (EVP_PKEY *)0x0) {
    pEVar11 = (EVP_PKEY *)((uint)pEVar11 | 4);
  }
  if (pEVar12 == (EVP_PKEY *)0x0) {
    uVar4 = 4;
    uVar13 = 6;
    pEVar10 = (EVP_PKEY *)0x2;
  }
  else {
    uVar14 = uVar14 | 1;
    uVar4 = 5;
    uVar13 = 7;
    pEVar10 = (EVP_PKEY *)0x3;
    pEVar12 = (EVP_PKEY *)0x1;
  }
  if (iVar1 == 0) {
    uVar9 = uVar14 | 4;
    uVar13 = uVar4;
    pEVar10 = pEVar12;
    uVar4 = uVar14;
  }
  else {
    uVar4 = uVar14 | 2;
    uVar9 = uVar14 | 6;
  }
  if (pXVar6 != (X509 *)0x0) {
    X509_check_purpose(x,-1,0);
    if ((x->ex_flags & 2) == 0) {
      local_50 = (EVP_PKEY *)0x1;
      local_4c = (uint)local_50;
    }
    else {
      local_50 = (EVP_PKEY *)(x->ex_kusage & 8);
      local_4c = x->ex_kusage & 0x80;
    }
    pEVar12 = X509_get_pubkey(x);
    local_44 = pEVar12;
    if (pEVar12 != (EVP_PKEY *)0x0) {
      local_44 = (EVP_PKEY *)EVP_PKEY_bits(pEVar12);
    }
    EVP_PKEY_free(pEVar12);
    if ((x->sig_alg != (X509_ALGOR *)0x0) && (o = x->sig_alg->algorithm, o != (ASN1_OBJECT *)0x0)) {
      iVar5 = OBJ_obj2nid(o);
      OBJ_find_sigid_algs(iVar5,local_2c,&local_30);
    }
    if (local_50 != (EVP_PKEY *)0x0) {
      if (local_30 == 6 || local_30 == 0x13) {
        uVar8 = uVar8 | 0x20;
        uVar9 = uVar4 | 0x14;
        if ((int)local_44 < 0xa4) {
          pEVar11 = (EVP_PKEY *)((uint)pEVar11 | 0x20);
          uVar13 = (uint)pEVar10 | 0x14;
        }
      }
      if (local_30 == 0x198) {
        uVar8 = uVar8 | 0x40;
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
    uVar8 = uVar8 | 0x80;
    pEVar11 = (EVP_PKEY *)((uint)pEVar11 | 0x80);
  }
  iVar5 = *(int *)(param_1 + 0x58);
  *(uint *)(iVar7 + 8) = uVar8 | 0x100;
  iVar5 = *(int *)(iVar5 + 0x344);
  *(uint *)(iVar7 + 0xc) = uVar9 | 0x80;
  *(uint *)(iVar7 + 0x10) = (uint)pEVar11 | 0x100;
  *(uint *)(iVar7 + 0x14) = uVar13 | 0x80;
  *(undefined4 *)(iVar7 + 4) = 1;
LAB_0006033a:
  uVar8 = *(uint *)(iVar5 + 0xc);
  iVar5 = *(int *)(iVar5 + 0x10);
  if (((uVar8 & 0x60) == 0) && (-1 < iVar5 << 0x19)) {
    if ((int)(uVar8 << 0x1e) < 0) {
      uVar8 = 3;
    }
    else if ((int)(uVar8 << 0x1d) < 0) {
      uVar8 = 4;
    }
    else if (iVar5 << 0x1e < 0) {
      uVar8 = 2;
    }
    else if (iVar5 << 0x1f < 0) {
      uVar8 = count_leading_zeroes(*(undefined4 *)(iVar7 + 0x30));
      uVar8 = uVar8 >> 5;
    }
    else {
      if (iVar5 << 0x1a < 0) {
        return 0;
      }
      if (iVar5 << 0x17 < 0) {
        uVar8 = 6;
      }
      else {
        if (-1 < iVar5 << 0x16) {
          ERR_put_error(0x14,0x13d,0x44,"ssl_lib.c",0x944);
          return 0;
        }
        uVar8 = 7;
      }
    }
  }
  else {
    uVar8 = 5;
  }
  iVar1 = uVar8 * 0xc + 0x30;
  iVar5 = iVar7 + iVar1;
  if (iVar5 != 0) {
    iVar5 = *(int *)(iVar7 + iVar1);
  }
  return iVar5;
}

