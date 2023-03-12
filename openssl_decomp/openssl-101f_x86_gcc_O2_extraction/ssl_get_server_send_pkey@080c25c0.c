
int ssl_get_server_send_pkey(int param_1)

{
  int iVar1;
  ASN1_OBJECT *o;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  int iVar6;
  EVP_PKEY *pkey;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  int in_GS_OFFSET;
  bool bVar14;
  bool bVar15;
  bool bVar16;
  bool bVar17;
  bool bVar18;
  bool bVar19;
  bool bVar20;
  bool bVar21;
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
  iVar1 = *(int *)(param_1 + 0x98);
  iVar10 = *(int *)(*(int *)(param_1 + 0x58) + 0x344);
  if (iVar1 != 0) {
    iVar10 = (-(uint)((*(uint *)(iVar10 + 0x20) & 8) == 0) & 0x200) + 0x200;
    if (*(RSA **)(iVar1 + 0x18) == (RSA *)0x0) {
      bVar17 = *(int *)(iVar1 + 0x1c) != 0;
      bVar18 = *(int *)(iVar1 + 0x1c) != 0;
    }
    else {
      bVar17 = true;
      bVar18 = true;
      if (*(int *)(iVar1 + 0x1c) == 0) {
        iVar6 = RSA_size(*(RSA **)(iVar1 + 0x18));
        bVar18 = iVar6 * 8 <= iVar10;
      }
    }
    if (*(DH **)(iVar1 + 0x20) == (DH *)0x0) {
      bVar15 = *(int *)(iVar1 + 0x24) != 0;
      bVar16 = *(int *)(iVar1 + 0x24) != 0;
    }
    else {
      bVar15 = true;
      bVar16 = true;
      if (*(int *)(iVar1 + 0x24) == 0) {
        iVar6 = DH_size(*(DH **)(iVar1 + 0x20));
        bVar16 = iVar6 * 8 <= iVar10;
      }
    }
    bVar21 = true;
    if (*(int *)(iVar1 + 0x28) == 0) {
      bVar21 = *(int *)(iVar1 + 0x2c) != 0;
    }
    if ((*(int *)(iVar1 + 0x30) == 0) || (*(EVP_PKEY **)(iVar1 + 0x34) == (EVP_PKEY *)0x0)) {
      uVar13 = 0;
      local_48 = 0;
      if (*(int *)(iVar1 + 0x3c) == 0) goto LAB_080c2a95;
LAB_080c26ba:
      local_64 = 1;
      if (*(int *)(iVar1 + 0x40) == 0) {
        local_64 = uVar13;
      }
      bVar14 = *(int *)(iVar1 + 0x40) != 0;
      if (*(int *)(iVar1 + 0x48) != 0) goto LAB_080c26e3;
LAB_080c2ab0:
      bVar19 = false;
      if (*(int *)(iVar1 + 0x54) != 0) goto LAB_080c26fc;
LAB_080c2ac8:
      bVar5 = false;
      bVar2 = false;
      if (*(int *)(iVar1 + 0x60) == 0) goto LAB_080c2ae8;
LAB_080c2735:
      if (*(EVP_PKEY **)(iVar1 + 100) == (EVP_PKEY *)0x0) goto LAB_080c2ae8;
      iVar6 = EVP_PKEY_size(*(EVP_PKEY **)(iVar1 + 100));
      local_58 = *(X509 **)(iVar1 + 0x6c);
      bVar4 = true;
      bVar3 = iVar6 * 8 <= iVar10;
      if (local_58 == (X509 *)0x0) goto LAB_080c2afb;
LAB_080c276a:
      bVar20 = *(int *)(iVar1 + 0x70) != 0;
      if (*(int *)(iVar1 + 0x84) != 0) goto LAB_080c2786;
LAB_080c2b18:
      uVar11 = 0;
      uVar9 = 0x100;
      if (*(int *)(iVar1 + 0x78) != 0) goto LAB_080c27b7;
      uVar11 = 0;
      uVar12 = uVar11;
    }
    else {
      uVar13 = 1;
      iVar6 = EVP_PKEY_size(*(EVP_PKEY **)(iVar1 + 0x34));
      local_48 = (uint)(iVar6 * 8 <= iVar10);
      if (*(int *)(iVar1 + 0x3c) != 0) goto LAB_080c26ba;
LAB_080c2a95:
      bVar14 = false;
      local_64 = uVar13;
      if (*(int *)(iVar1 + 0x48) == 0) goto LAB_080c2ab0;
LAB_080c26e3:
      bVar19 = *(int *)(iVar1 + 0x4c) != 0;
      if (*(int *)(iVar1 + 0x54) == 0) goto LAB_080c2ac8;
LAB_080c26fc:
      if (*(EVP_PKEY **)(iVar1 + 0x58) == (EVP_PKEY *)0x0) goto LAB_080c2ac8;
      iVar6 = EVP_PKEY_size(*(EVP_PKEY **)(iVar1 + 0x58));
      bVar5 = true;
      bVar2 = iVar6 * 8 <= iVar10;
      if (*(int *)(iVar1 + 0x60) != 0) goto LAB_080c2735;
LAB_080c2ae8:
      local_58 = *(X509 **)(iVar1 + 0x6c);
      bVar4 = false;
      bVar3 = false;
      if (local_58 != (X509 *)0x0) goto LAB_080c276a;
LAB_080c2afb:
      bVar20 = false;
      if (*(int *)(iVar1 + 0x84) == 0) goto LAB_080c2b18;
LAB_080c2786:
      uVar9 = (-(uint)(*(int *)(iVar1 + 0x88) == 0) & 0xfffffe00) + 0x300;
      uVar11 = ~-(uint)(*(int *)(iVar1 + 0x88) == 0) & 0x200;
      uVar12 = uVar11;
      if (*(int *)(iVar1 + 0x78) != 0) {
LAB_080c27b7:
        uVar12 = uVar11;
        if (*(int *)(iVar1 + 0x7c) != 0) {
          uVar11 = uVar9;
          uVar12 = 0x200;
        }
      }
    }
    if ((uVar13 != 0) || ((bool)(bVar14 & bVar17))) {
      uVar12 = uVar12 | 1;
    }
    uVar13 = 1;
    if ((local_48 == 0) && (uVar13 = local_48, bVar18)) {
      uVar13 = local_64;
    }
    if (bVar16) {
      uVar13 = uVar13 | 8;
    }
    if (bVar15) {
      uVar12 = uVar12 | 8;
    }
    if (bVar5) {
      uVar12 = uVar12 | 2;
    }
    if (bVar2) {
      uVar13 = uVar13 | 2;
    }
    if (bVar4) {
      uVar12 = uVar12 | 4;
    }
    if (bVar3) {
      uVar13 = uVar13 | 4;
    }
    if (local_64 != 0) {
      uVar11 = uVar11 | 1;
      uVar9 = 5;
      uVar7 = 7;
      uVar8 = 3;
    }
    else {
      uVar9 = 4;
      uVar7 = 6;
      uVar8 = 2;
    }
    local_48 = (uint)(local_64 != 0);
    local_64 = uVar9;
    if (bVar19) {
      uVar11 = uVar11 | 2;
      local_64 = uVar7;
      local_48 = uVar8;
    }
    local_60 = uVar11 | 4;
    uVar9 = uVar12;
    if (bVar20) {
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
        iVar10 = OBJ_obj2nid(o);
        OBJ_find_sigid_algs(iVar10,&local_24,&local_28);
      }
      if (local_4c != 0) {
        if ((local_28 == 6) || (local_28 == 0x13)) {
          local_60 = uVar11 | 0x14;
          uVar9 = uVar12 | 0x20;
          if (0xa3 < local_50) goto LAB_080c2a50;
          uVar13 = uVar13 | 0x20;
          local_64 = local_48 | 0x14;
          if (local_28 != 0x198) goto LAB_080c2a5b;
          uVar9 = uVar12 | 0x60;
LAB_080c2c96:
          uVar13 = uVar13 | 0x40;
          local_64 = local_64 | 0x10;
        }
        else {
LAB_080c2a50:
          if (local_28 == 0x198) {
            uVar9 = uVar9 | 0x40;
            local_60 = local_60 | 0x10;
            if (local_50 < 0xa4) goto LAB_080c2c96;
          }
        }
      }
LAB_080c2a5b:
      if (local_44 != 0) {
        local_60 = local_60 | 0x40;
        local_64 = local_64 | 0x40;
      }
    }
    if (bVar21) {
      uVar9 = uVar9 | 0x80;
      uVar13 = uVar13 | 0x80;
    }
    *(uint *)(iVar1 + 8) = uVar9 | 0x100;
    *(uint *)(iVar1 + 0x10) = uVar13 | 0x100;
    *(undefined4 *)(iVar1 + 4) = 1;
    *(uint *)(iVar1 + 0xc) = local_60 | 0x80;
    *(uint *)(iVar1 + 0x14) = local_64 | 0x80;
    iVar10 = *(int *)(*(int *)(param_1 + 0x58) + 0x344);
  }
  uVar13 = *(uint *)(iVar10 + 0xc);
  if (((uVar13 & 0x60) == 0) && (uVar11 = *(uint *)(iVar10 + 0x10), (uVar11 & 0x40) == 0)) {
    if ((uVar13 & 2) == 0) {
      if ((uVar13 & 4) == 0) {
        if ((uVar11 & 2) == 0) {
          if ((uVar11 & 1) == 0) {
            if ((uVar11 & 0x20) != 0) {
              iVar10 = 0;
              goto LAB_080c28df;
            }
            if ((uVar11 & 0x100) == 0) {
              iVar10 = 0x54;
              if ((uVar11 & 0x200) == 0) {
                ERR_put_error(0x14,0x13d,0x44,"ssl_lib.c",0x92f);
                iVar10 = 0;
                goto LAB_080c28df;
              }
            }
            else {
              iVar10 = 0x48;
            }
          }
          else {
            iVar10 = (uint)(*(int *)(iVar1 + 0x30) == 0) * 0xc;
          }
        }
        else {
          iVar10 = 0x18;
        }
      }
      else {
        iVar10 = 0x30;
      }
    }
    else {
      iVar10 = 0x24;
    }
  }
  else {
    iVar10 = 0x3c;
  }
  iVar10 = iVar1 + 0x30 + iVar10;
LAB_080c28df:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar10;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

