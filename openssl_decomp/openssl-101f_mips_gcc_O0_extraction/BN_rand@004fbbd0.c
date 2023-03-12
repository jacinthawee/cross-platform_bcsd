
int BN_rand(BIGNUM *rnd,int bits,int top,int bottom)

{
  undefined *puVar1;
  int iVar2;
  byte bVar5;
  BIGNUM *pBVar3;
  byte *s;
  int iVar4;
  BIGNUM *pBVar6;
  char *pcVar7;
  uint unaff_s0;
  uint uVar8;
  byte *unaff_s2;
  BIGNUM *unaff_s4;
  int unaff_s5;
  int unaff_s6;
  undefined1 *unaff_s7;
  byte *pbVar9;
  byte bStack_81;
  undefined auStack_80 [4];
  int iStack_7c;
  uint uStack_78;
  int iStack_74;
  byte *pbStack_70;
  undefined *puStack_6c;
  BIGNUM *pBStack_68;
  int iStack_64;
  int iStack_60;
  undefined1 *puStack_5c;
  undefined1 auStack_30 [4];
  BIGNUM *local_2c;
  
  puStack_6c = PTR___stack_chk_guard_006aabf0;
  local_2c = *(BIGNUM **)PTR___stack_chk_guard_006aabf0;
  iStack_74 = bits + 7;
  if (bits == 0) {
    BN_set_word(rnd,0);
    uVar8 = 1;
    pBVar6 = (BIGNUM *)top;
    pcVar7 = (char *)bottom;
  }
  else {
    if (iStack_74 < 0) {
      iStack_74 = bits + 0xe;
    }
    unaff_s7 = CAST_S_table6 + 0x370;
    iStack_74 = iStack_74 >> 3;
    unaff_s2 = (byte *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iStack_74,"bn_rand.c",0x86);
    unaff_s4 = rnd;
    unaff_s5 = bottom;
    unaff_s6 = top;
    if (unaff_s2 == (byte *)0x0) {
      pcVar7 = "bn_rand.c";
      pBVar6 = (BIGNUM *)&DAT_00000041;
      bits = 0x7f;
      unaff_s0 = 0;
      (*(code *)PTR_ERR_put_error_006a9030)(3);
      uVar8 = 0;
    }
    else {
      unaff_s7 = auStack_30;
      (*(code *)PTR_time_006aabe4)(unaff_s7);
      pcVar7 = (char *)0x0;
      pBVar6 = (BIGNUM *)0x0;
      (*(code *)PTR_RAND_add_006a9020)(unaff_s7,4);
      iVar2 = (*(code *)PTR_RAND_bytes_006a8d44)(unaff_s2,iStack_74);
      if (iVar2 < 1) {
        uVar8 = 0;
      }
      else {
        uVar8 = bits - 1U & 0x80000007;
        if ((int)uVar8 < 0) {
          uVar8 = (uVar8 - 1 | 0xfffffff8) + 1;
        }
        if (top == -1) {
          bVar5 = *unaff_s2;
        }
        else if (top == 0) {
          bVar5 = (byte)(1 << (uVar8 & 0x1f)) | *unaff_s2;
        }
        else if (uVar8 == 0) {
          bVar5 = 1;
          unaff_s2[1] = unaff_s2[1] | 0x80;
        }
        else {
          bVar5 = (byte)(3 << (uVar8 - 1 & 0x1f)) | *unaff_s2;
        }
        *unaff_s2 = bVar5 & ~(byte)(0xff << (uVar8 + 1 & 0x1f));
        if (bottom != 0) {
          unaff_s2[iStack_74 + -1] = unaff_s2[iStack_74 + -1] | 1;
        }
        pBVar6 = rnd;
        pBVar3 = BN_bin2bn(unaff_s2,iStack_74,rnd);
        uVar8 = (uint)(pBVar3 != (BIGNUM *)0x0);
      }
      bits = iStack_74;
      (*(code *)PTR_OPENSSL_cleanse_006a8174)(unaff_s2);
      (*(code *)PTR_CRYPTO_free_006a7f88)(unaff_s2);
      unaff_s0 = uVar8;
    }
  }
  if (local_2c == *(BIGNUM **)puStack_6c) {
    return uVar8;
  }
  pBVar3 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStack_7c = *(int *)PTR___stack_chk_guard_006aabf0;
  uStack_78 = unaff_s0;
  pbStack_70 = unaff_s2;
  pBStack_68 = unaff_s4;
  iStack_64 = unaff_s5;
  iStack_60 = unaff_s6;
  puStack_5c = unaff_s7;
  if (bits == 0) {
    BN_set_word(pBVar3,0);
    uVar8 = 1;
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
      uVar8 = 0;
    }
    else {
      (*(code *)PTR_time_006aabe4)(auStack_80);
      (*(code *)PTR_RAND_add_006a9020)(auStack_80,4,0,0);
      iVar4 = (*(code *)PTR_RAND_pseudo_bytes_006a8664)(s,iVar2);
      if (iVar4 == -1) {
        uVar8 = 0;
      }
      else {
        if (0 < iVar2) {
          iVar4 = 0;
          pbVar9 = s;
          do {
            while ((*(code *)PTR_RAND_pseudo_bytes_006a8664)(&bStack_81,1), (char)bStack_81 < '\0')
            {
              if (0 < iVar4) {
                *pbVar9 = pbVar9[-1];
              }
LAB_004fbf30:
              iVar4 = iVar4 + 1;
              pbVar9 = pbVar9 + 1;
              if (iVar2 == iVar4) goto LAB_004fbf84;
            }
            if (bStack_81 < 0x2a) {
              *pbVar9 = 0;
              goto LAB_004fbf30;
            }
            if (0x53 < bStack_81) goto LAB_004fbf30;
            iVar4 = iVar4 + 1;
            *pbVar9 = 0xff;
            pbVar9 = pbVar9 + 1;
          } while (iVar2 != iVar4);
        }
LAB_004fbf84:
        uVar8 = bits - 1U & 0x80000007;
        if ((int)uVar8 < 0) {
          uVar8 = (uVar8 - 1 | 0xfffffff8) + 1;
        }
        if (pBVar6 == (BIGNUM *)0xffffffff) {
          bVar5 = *s;
        }
        else if (pBVar6 == (BIGNUM *)0x0) {
          bVar5 = (byte)(1 << (uVar8 & 0x1f)) | *s;
        }
        else if (uVar8 == 0) {
          bVar5 = 1;
          s[1] = s[1] | 0x80;
        }
        else {
          bVar5 = (byte)(3 << (uVar8 - 1 & 0x1f)) | *s;
        }
        *s = bVar5 & ~(byte)(0xff << (uVar8 + 1 & 0x1f));
        if (pcVar7 != (char *)0x0) {
          s[iVar2 + -1] = s[iVar2 + -1] | 1;
        }
        pBVar6 = BN_bin2bn(s,iVar2,pBVar3);
        uVar8 = (uint)(pBVar6 != (BIGNUM *)0x0);
      }
      (*(code *)PTR_OPENSSL_cleanse_006a8174)(s,iVar2);
      (*(code *)PTR_CRYPTO_free_006a7f88)(s);
      bits = iVar2;
    }
  }
  if (iStack_7c != *(int *)puVar1) {
    iVar2 = iStack_7c;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    iVar2 = bn_rand_range(0,iVar2,bits);
    return iVar2;
  }
  return uVar8;
}

