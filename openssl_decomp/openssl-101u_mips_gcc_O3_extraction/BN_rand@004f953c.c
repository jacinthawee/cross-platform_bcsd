
int BN_rand(BIGNUM *rnd,int bits,int top,int bottom)

{
  undefined *puVar1;
  int iVar2;
  byte bVar6;
  BIGNUM *pBVar3;
  byte *s;
  int iVar4;
  int iVar5;
  BIGNUM *pBVar7;
  char *pcVar8;
  uint unaff_s0;
  uint uVar9;
  int iVar10;
  byte *unaff_s1;
  int unaff_s2;
  BIGNUM *unaff_s4;
  int unaff_s5;
  undefined1 *unaff_s6;
  int unaff_s7;
  byte *pbVar11;
  byte bStack_81;
  undefined auStack_80 [4];
  int iStack_7c;
  uint uStack_78;
  byte *pbStack_74;
  int iStack_70;
  undefined *puStack_6c;
  BIGNUM *pBStack_68;
  int iStack_64;
  undefined1 *puStack_60;
  int iStack_5c;
  undefined1 auStack_30 [4];
  BIGNUM *local_2c;
  
  puStack_6c = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(BIGNUM **)PTR___stack_chk_guard_006a9ae8;
  pBStack_68 = unaff_s4;
  iStack_64 = unaff_s5;
  iStack_5c = unaff_s7;
  if (bits < 0) {
LAB_004f9704:
    bits = unaff_s0;
    pBVar7 = (BIGNUM *)&DAT_00000076;
    pcVar8 = "bn_rand.c";
    iVar2 = 0x7f;
    (*(code *)PTR_ERR_put_error_006a7f34)(3);
    uVar9 = 0;
  }
  else {
    pBStack_68 = rnd;
    iStack_64 = bottom;
    iStack_5c = top;
    if (bits == 1) {
      unaff_s0 = bits;
      if (0 < top) goto LAB_004f9704;
    }
    else if (bits == 0) {
      iVar2 = bits;
      pBVar7 = (BIGNUM *)top;
      pcVar8 = (char *)bottom;
      BN_set_word(rnd,0);
      uVar9 = 1;
      goto LAB_004f96c4;
    }
    unaff_s6 = CAST_S_table3 + 0x110;
    unaff_s2 = bits + 7 >> 3;
    unaff_s1 = (byte *)(*(code *)PTR_CRYPTO_malloc_006a7008)(unaff_s2,"bn_rand.c",0x8a);
    if (unaff_s1 == (byte *)0x0) {
      pcVar8 = "bn_rand.c";
      pBVar7 = (BIGNUM *)&DAT_00000041;
      iVar2 = 0x7f;
      bits = 0;
      (*(code *)PTR_ERR_put_error_006a7f34)(3);
      uVar9 = 0;
    }
    else {
      unaff_s6 = auStack_30;
      (*(code *)PTR_time_006a9adc)(unaff_s6);
      pcVar8 = (char *)0x0;
      pBVar7 = (BIGNUM *)0x0;
      (*(code *)PTR_RAND_add_006a8004)(unaff_s6,4);
      iVar2 = (*(code *)PTR_RAND_bytes_006a7574)(unaff_s1,unaff_s2);
      if (iVar2 < 1) {
        uVar9 = 0;
      }
      else {
        uVar9 = bits - 1U & 7;
        if (top < 0) {
          bVar6 = *unaff_s1;
        }
        else if (top == 0) {
          bVar6 = (byte)(1 << uVar9) | *unaff_s1;
        }
        else if (uVar9 == 0) {
          bVar6 = 1;
          unaff_s1[1] = unaff_s1[1] | 0x80;
        }
        else {
          bVar6 = (byte)(3 << (uVar9 - 1 & 0x1f)) | *unaff_s1;
        }
        *unaff_s1 = bVar6 & ~(byte)(0xff << uVar9 + 1);
        if (bottom != 0) {
          unaff_s1[unaff_s2 + -1] = unaff_s1[unaff_s2 + -1] | 1;
        }
        pBVar7 = rnd;
        pBVar3 = BN_bin2bn(unaff_s1,unaff_s2,rnd);
        uVar9 = (uint)(pBVar3 != (BIGNUM *)0x0);
      }
      iVar2 = unaff_s2;
      (*(code *)PTR_OPENSSL_cleanse_006a7074)(unaff_s1);
      (*(code *)PTR_CRYPTO_free_006a6e88)(unaff_s1);
      bits = uVar9;
    }
  }
LAB_004f96c4:
  if (local_2c == *(BIGNUM **)puStack_6c) {
    return uVar9;
  }
  pBVar3 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iStack_7c = *(int *)PTR___stack_chk_guard_006a9ae8;
  uStack_78 = bits;
  pbStack_74 = unaff_s1;
  iStack_70 = unaff_s2;
  puStack_60 = unaff_s6;
  if (iVar2 < 0) {
LAB_004f9998:
    iVar2 = 0x7f;
    (*(code *)PTR_ERR_put_error_006a7f34)(3,0x7f,0x76,"bn_rand.c",0x7d);
    uVar9 = 0;
  }
  else {
    if (iVar2 == 1) {
      if (0 < (int)pBVar7) goto LAB_004f9998;
    }
    else if (iVar2 == 0) {
      BN_set_word(pBVar3,0);
      uVar9 = 1;
      goto LAB_004f9940;
    }
    iVar10 = iVar2 + 7 >> 3;
    s = (byte *)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar10,"bn_rand.c",0x8a);
    if (s == (byte *)0x0) {
      iVar2 = 0x7f;
      (*(code *)PTR_ERR_put_error_006a7f34)(3,0x7f,0x41,"bn_rand.c",0x8c);
      uVar9 = 0;
    }
    else {
      (*(code *)PTR_time_006a9adc)(auStack_80);
      (*(code *)PTR_RAND_add_006a8004)(auStack_80,4,0,0);
      iVar4 = (*(code *)PTR_RAND_bytes_006a7574)(s,iVar10);
      if (iVar4 < 1) {
LAB_004f99c4:
        uVar9 = 0;
      }
      else {
        iVar4 = 0;
        pbVar11 = s;
LAB_004f98b4:
        do {
          iVar5 = (*(code *)PTR_RAND_pseudo_bytes_006a7a60)(&bStack_81,1);
          if (iVar5 < 0) goto LAB_004f99c4;
          if ((char)bStack_81 < '\0') {
            if (iVar4 != 0) {
              *pbVar11 = pbVar11[-1];
            }
          }
          else if (bStack_81 < 0x2a) {
            *pbVar11 = 0;
          }
          else if (bStack_81 < 0x54) {
            iVar4 = iVar4 + 1;
            *pbVar11 = 0xff;
            pbVar11 = pbVar11 + 1;
            if (iVar10 == iVar4) break;
            goto LAB_004f98b4;
          }
          iVar4 = iVar4 + 1;
          pbVar11 = pbVar11 + 1;
        } while (iVar10 != iVar4);
        uVar9 = iVar2 - 1U & 7;
        if ((int)pBVar7 < 0) {
          bVar6 = *s;
        }
        else if (pBVar7 == (BIGNUM *)0x0) {
          bVar6 = (byte)(1 << uVar9) | *s;
        }
        else if (uVar9 == 0) {
          bVar6 = 1;
          s[1] = s[1] | 0x80;
        }
        else {
          bVar6 = (byte)(3 << (uVar9 - 1 & 0x1f)) | *s;
        }
        *s = bVar6 & ~(byte)(0xff << uVar9 + 1);
        if (pcVar8 != (char *)0x0) {
          s[iVar10 + -1] = s[iVar10 + -1] | 1;
        }
        pBVar7 = BN_bin2bn(s,iVar10,pBVar3);
        uVar9 = (uint)(pBVar7 != (BIGNUM *)0x0);
      }
      (*(code *)PTR_OPENSSL_cleanse_006a7074)(s,iVar10);
      (*(code *)PTR_CRYPTO_free_006a6e88)(s);
      iVar2 = iVar10;
    }
  }
LAB_004f9940:
  if (iStack_7c == *(int *)puVar1) {
    return uVar9;
  }
  iVar10 = iStack_7c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar2 = bn_rand_range(0,iVar10,iVar2);
  return iVar2;
}

