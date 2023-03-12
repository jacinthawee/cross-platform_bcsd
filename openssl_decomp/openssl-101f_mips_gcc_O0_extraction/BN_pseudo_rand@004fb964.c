
int BN_pseudo_rand(BIGNUM *rnd,int bits,int top,int bottom)

{
  undefined *puVar1;
  int iVar2;
  byte bVar5;
  BIGNUM *pBVar3;
  byte *s;
  int iVar4;
  BIGNUM *pBVar6;
  BIGNUM *pBVar7;
  char *pcVar8;
  char *pcVar9;
  uint unaff_s0;
  uint uVar10;
  byte *unaff_s2;
  BIGNUM *unaff_s4;
  char *unaff_s5;
  BIGNUM *unaff_s6;
  undefined1 *unaff_s7;
  byte *pbVar11;
  byte bStack_d1;
  undefined auStack_d0 [4];
  int iStack_cc;
  uint uStack_c8;
  int iStack_c4;
  byte *pbStack_c0;
  undefined *puStack_bc;
  BIGNUM *pBStack_b8;
  char *pcStack_b4;
  BIGNUM *pBStack_b0;
  undefined1 *puStack_ac;
  undefined1 auStack_80 [4];
  BIGNUM *pBStack_7c;
  uint uStack_74;
  int iStack_70;
  byte *pbStack_6c;
  undefined *puStack_68;
  BIGNUM *pBStack_64;
  char *pcStack_60;
  BIGNUM *pBStack_5c;
  undefined1 *puStack_58;
  code *pcStack_54;
  undefined4 local_40;
  undefined *local_38;
  undefined1 auStack_30 [4];
  BIGNUM *local_2c;
  
  puStack_68 = PTR___stack_chk_guard_006aabf0;
  local_38 = &_gp;
  local_2c = *(BIGNUM **)PTR___stack_chk_guard_006aabf0;
  iStack_70 = bits + 7;
  if (bits == 0) {
    BN_set_word(rnd,0);
    uVar10 = 1;
    pBVar6 = (BIGNUM *)top;
    pcVar8 = (char *)bottom;
  }
  else {
    if (iStack_70 < 0) {
      iStack_70 = bits + 0xe;
    }
    unaff_s7 = CAST_S_table6 + 0x370;
    iStack_70 = iStack_70 >> 3;
    unaff_s2 = (byte *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iStack_70,"bn_rand.c",0x86);
    unaff_s4 = rnd;
    unaff_s5 = (char *)bottom;
    unaff_s6 = (BIGNUM *)top;
    if (unaff_s2 == (byte *)0x0) {
      pcVar8 = "bn_rand.c";
      pBVar6 = (BIGNUM *)&DAT_00000041;
      bits = 0x7f;
      local_40 = 0x89;
      unaff_s0 = 0;
      (**(code **)(local_38 + -0x6eb0))(3);
      uVar10 = 0;
    }
    else {
      unaff_s7 = auStack_30;
      (**(code **)(local_38 + -0x52fc))(unaff_s7);
      pcVar8 = (char *)0x0;
      pBVar6 = (BIGNUM *)0x0;
      (**(code **)(local_38 + -0x6ec0))(unaff_s7,4);
      iVar2 = (**(code **)(local_38 + -0x787c))(unaff_s2,iStack_70);
      if (iVar2 == -1) {
        uVar10 = 0;
      }
      else {
        uVar10 = bits - 1U & 0x80000007;
        if ((int)uVar10 < 0) {
          uVar10 = (uVar10 - 1 | 0xfffffff8) + 1;
        }
        if (top == -1) {
          bVar5 = *unaff_s2;
        }
        else if (top == 0) {
          bVar5 = (byte)(1 << (uVar10 & 0x1f)) | *unaff_s2;
        }
        else if (uVar10 == 0) {
          bVar5 = 1;
          unaff_s2[1] = unaff_s2[1] | 0x80;
        }
        else {
          bVar5 = (byte)(3 << (uVar10 - 1 & 0x1f)) | *unaff_s2;
        }
        *unaff_s2 = bVar5 & ~(byte)(0xff << (uVar10 + 1 & 0x1f));
        if (bottom != 0) {
          unaff_s2[iStack_70 + -1] = unaff_s2[iStack_70 + -1] | 1;
        }
        pBVar6 = rnd;
        pBVar3 = BN_bin2bn(unaff_s2,iStack_70,rnd);
        uVar10 = (uint)(pBVar3 != (BIGNUM *)0x0);
      }
      bits = iStack_70;
      (**(code **)(local_38 + -0x7d6c))(unaff_s2);
      (**(code **)(local_38 + -0x7f58))(unaff_s2);
      unaff_s0 = uVar10;
    }
  }
  if (local_2c == *(BIGNUM **)puStack_68) {
    return uVar10;
  }
  pcStack_54 = BN_rand;
  pBVar3 = local_2c;
  (**(code **)(local_38 + -0x5328))();
  puStack_bc = PTR___stack_chk_guard_006aabf0;
  pBStack_7c = *(BIGNUM **)PTR___stack_chk_guard_006aabf0;
  iStack_c4 = bits + 7;
  uStack_74 = unaff_s0;
  pbStack_6c = unaff_s2;
  pBStack_64 = unaff_s4;
  pcStack_60 = unaff_s5;
  pBStack_5c = unaff_s6;
  puStack_58 = unaff_s7;
  if (bits == 0) {
    BN_set_word(pBVar3,0);
    uVar10 = 1;
    pBVar7 = pBVar6;
    pcVar9 = pcVar8;
  }
  else {
    if (iStack_c4 < 0) {
      iStack_c4 = bits + 0xe;
    }
    iStack_c4 = iStack_c4 >> 3;
    unaff_s2 = (byte *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iStack_c4,"bn_rand.c",0x86);
    unaff_s4 = pBVar3;
    unaff_s5 = pcVar8;
    unaff_s6 = pBVar6;
    if (unaff_s2 == (byte *)0x0) {
      pcVar9 = "bn_rand.c";
      pBVar7 = (BIGNUM *)&DAT_00000041;
      bits = 0x7f;
      unaff_s0 = 0;
      (*(code *)PTR_ERR_put_error_006a9030)(3);
      uVar10 = 0;
      unaff_s7 = CAST_S_table6 + 0x370;
    }
    else {
      (*(code *)PTR_time_006aabe4)(auStack_80);
      pcVar9 = (char *)0x0;
      pBVar7 = (BIGNUM *)0x0;
      (*(code *)PTR_RAND_add_006a9020)(auStack_80,4);
      iVar2 = (*(code *)PTR_RAND_bytes_006a8d44)(unaff_s2,iStack_c4);
      if (iVar2 < 1) {
        uVar10 = 0;
      }
      else {
        uVar10 = bits - 1U & 0x80000007;
        if ((int)uVar10 < 0) {
          uVar10 = (uVar10 - 1 | 0xfffffff8) + 1;
        }
        if (pBVar6 == (BIGNUM *)0xffffffff) {
          bVar5 = *unaff_s2;
        }
        else if (pBVar6 == (BIGNUM *)0x0) {
          bVar5 = (byte)(1 << (uVar10 & 0x1f)) | *unaff_s2;
        }
        else if (uVar10 == 0) {
          bVar5 = 1;
          unaff_s2[1] = unaff_s2[1] | 0x80;
        }
        else {
          bVar5 = (byte)(3 << (uVar10 - 1 & 0x1f)) | *unaff_s2;
        }
        *unaff_s2 = bVar5 & ~(byte)(0xff << (uVar10 + 1 & 0x1f));
        if (pcVar8 != (char *)0x0) {
          unaff_s2[iStack_c4 + -1] = unaff_s2[iStack_c4 + -1] | 1;
        }
        pBVar7 = pBVar3;
        pBVar6 = BN_bin2bn(unaff_s2,iStack_c4,pBVar3);
        uVar10 = (uint)(pBVar6 != (BIGNUM *)0x0);
      }
      bits = iStack_c4;
      (*(code *)PTR_OPENSSL_cleanse_006a8174)(unaff_s2);
      (*(code *)PTR_CRYPTO_free_006a7f88)(unaff_s2);
      unaff_s0 = uVar10;
      unaff_s7 = auStack_80;
    }
  }
  if (pBStack_7c == *(BIGNUM **)puStack_bc) {
    return uVar10;
  }
  pBVar6 = pBStack_7c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStack_cc = *(int *)PTR___stack_chk_guard_006aabf0;
  uStack_c8 = unaff_s0;
  pbStack_c0 = unaff_s2;
  pBStack_b8 = unaff_s4;
  pcStack_b4 = unaff_s5;
  pBStack_b0 = unaff_s6;
  puStack_ac = unaff_s7;
  if (bits == 0) {
    BN_set_word(pBVar6,0);
    uVar10 = 1;
  }
  else {
    iVar2 = bits + 7;
    if (bits + 7 < 0) {
      iVar2 = bits + 0xe;
    }
    iVar2 = iVar2 >> 3;
    s = (byte *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar2,"bn_rand.c",0x86);
    if (s == (byte *)0x0) {
      bits = 0x7f;
      (*(code *)PTR_ERR_put_error_006a9030)(3,0x7f,0x41,"bn_rand.c",0x89);
      uVar10 = 0;
    }
    else {
      (*(code *)PTR_time_006aabe4)(auStack_d0);
      (*(code *)PTR_RAND_add_006a9020)(auStack_d0,4,0,0);
      iVar4 = (*(code *)PTR_RAND_pseudo_bytes_006a8664)(s,iVar2);
      if (iVar4 == -1) {
        uVar10 = 0;
      }
      else {
        if (0 < iVar2) {
          iVar4 = 0;
          pbVar11 = s;
          do {
            while ((*(code *)PTR_RAND_pseudo_bytes_006a8664)(&bStack_d1,1), (char)bStack_d1 < '\0')
            {
              if (0 < iVar4) {
                *pbVar11 = pbVar11[-1];
              }
LAB_004fbf30:
              iVar4 = iVar4 + 1;
              pbVar11 = pbVar11 + 1;
              if (iVar2 == iVar4) goto LAB_004fbf84;
            }
            if (bStack_d1 < 0x2a) {
              *pbVar11 = 0;
              goto LAB_004fbf30;
            }
            if (0x53 < bStack_d1) goto LAB_004fbf30;
            iVar4 = iVar4 + 1;
            *pbVar11 = 0xff;
            pbVar11 = pbVar11 + 1;
          } while (iVar2 != iVar4);
        }
LAB_004fbf84:
        uVar10 = bits - 1U & 0x80000007;
        if ((int)uVar10 < 0) {
          uVar10 = (uVar10 - 1 | 0xfffffff8) + 1;
        }
        if (pBVar7 == (BIGNUM *)0xffffffff) {
          bVar5 = *s;
        }
        else if (pBVar7 == (BIGNUM *)0x0) {
          bVar5 = (byte)(1 << (uVar10 & 0x1f)) | *s;
        }
        else if (uVar10 == 0) {
          bVar5 = 1;
          s[1] = s[1] | 0x80;
        }
        else {
          bVar5 = (byte)(3 << (uVar10 - 1 & 0x1f)) | *s;
        }
        *s = bVar5 & ~(byte)(0xff << (uVar10 + 1 & 0x1f));
        if (pcVar9 != (char *)0x0) {
          s[iVar2 + -1] = s[iVar2 + -1] | 1;
        }
        pBVar6 = BN_bin2bn(s,iVar2,pBVar6);
        uVar10 = (uint)(pBVar6 != (BIGNUM *)0x0);
      }
      (*(code *)PTR_OPENSSL_cleanse_006a8174)(s,iVar2);
      (*(code *)PTR_CRYPTO_free_006a7f88)(s);
      bits = iVar2;
    }
  }
  if (iStack_cc != *(int *)puVar1) {
    iVar2 = iStack_cc;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    iVar2 = bn_rand_range(0,iVar2,bits);
    return iVar2;
  }
  return uVar10;
}

