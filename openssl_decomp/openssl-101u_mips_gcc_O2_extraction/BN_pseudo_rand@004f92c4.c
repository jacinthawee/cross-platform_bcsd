
int BN_pseudo_rand(BIGNUM *rnd,int bits,int top,int bottom)

{
  undefined *puVar1;
  int iVar2;
  byte bVar4;
  BIGNUM *pBVar3;
  byte *s;
  BIGNUM *pBVar5;
  BIGNUM *pBVar6;
  char *pcVar7;
  char *pcVar8;
  uint unaff_s0;
  uint uVar9;
  uint uVar10;
  uint len;
  byte *unaff_s1;
  uint unaff_s2;
  BIGNUM *unaff_s4;
  char *unaff_s5;
  undefined1 *unaff_s6;
  BIGNUM *unaff_s7;
  byte *pbVar11;
  byte bStack_d1;
  undefined auStack_d0 [4];
  int iStack_cc;
  uint uStack_c8;
  byte *pbStack_c4;
  uint uStack_c0;
  undefined *puStack_bc;
  BIGNUM *pBStack_b8;
  char *pcStack_b4;
  undefined1 *puStack_b0;
  BIGNUM *pBStack_ac;
  undefined1 auStack_80 [4];
  BIGNUM *pBStack_7c;
  uint uStack_74;
  byte *pbStack_70;
  uint uStack_6c;
  undefined *puStack_68;
  BIGNUM *pBStack_64;
  char *pcStack_60;
  undefined1 *puStack_5c;
  BIGNUM *pBStack_58;
  code *pcStack_54;
  undefined4 local_40;
  undefined *local_38;
  undefined1 auStack_30 [4];
  BIGNUM *local_2c;
  
  puStack_68 = PTR___stack_chk_guard_006a9ae8;
  local_38 = &_gp;
  local_2c = *(BIGNUM **)PTR___stack_chk_guard_006a9ae8;
  pBStack_64 = unaff_s4;
  pcStack_60 = unaff_s5;
  pBStack_58 = unaff_s7;
  if (bits < 0) {
LAB_004f948c:
    bits = unaff_s0;
    pBVar5 = (BIGNUM *)&DAT_00000076;
    pcVar7 = "bn_rand.c";
    local_40 = 0x7d;
    uStack_c8 = 0x7f;
    (*(code *)PTR_ERR_put_error_006a7f34)(3);
    uVar9 = 0;
  }
  else {
    pBStack_64 = rnd;
    pcStack_60 = (char *)bottom;
    pBStack_58 = (BIGNUM *)top;
    if (bits == 1) {
      unaff_s0 = bits;
      if (0 < top) goto LAB_004f948c;
    }
    else if (bits == 0) {
      uStack_c8 = bits;
      pBVar5 = (BIGNUM *)top;
      pcVar7 = (char *)bottom;
      BN_set_word(rnd,0);
      uVar9 = 1;
      goto LAB_004f944c;
    }
    unaff_s6 = CAST_S_table3 + 0x110;
    unaff_s2 = bits + 7 >> 3;
    unaff_s1 = (byte *)(*(code *)PTR_CRYPTO_malloc_006a7008)(unaff_s2,"bn_rand.c",0x8a);
    if (unaff_s1 == (byte *)0x0) {
      pcVar7 = "bn_rand.c";
      pBVar5 = (BIGNUM *)&DAT_00000041;
      uStack_c8 = 0x7f;
      local_40 = 0x8c;
      bits = 0;
      (**(code **)(local_38 + -0x6eac))(3);
      uVar9 = 0;
    }
    else {
      unaff_s6 = auStack_30;
      (**(code **)(local_38 + -0x5304))(unaff_s6);
      pcVar7 = (char *)0x0;
      pBVar5 = (BIGNUM *)0x0;
      (**(code **)(local_38 + -0x6ddc))(unaff_s6,4);
      iVar2 = (**(code **)(local_38 + -0x786c))(unaff_s1,unaff_s2);
      if (iVar2 < 1) {
        uVar9 = 0;
      }
      else {
        uVar9 = bits - 1U & 7;
        if (top < 0) {
          bVar4 = *unaff_s1;
        }
        else if (top == 0) {
          bVar4 = (byte)(1 << uVar9) | *unaff_s1;
        }
        else if (uVar9 == 0) {
          bVar4 = 1;
          unaff_s1[1] = unaff_s1[1] | 0x80;
        }
        else {
          bVar4 = (byte)(3 << (uVar9 - 1 & 0x1f)) | *unaff_s1;
        }
        *unaff_s1 = bVar4 & ~(byte)(0xff << uVar9 + 1);
        if (bottom != 0) {
          unaff_s1[unaff_s2 - 1] = unaff_s1[unaff_s2 - 1] | 1;
        }
        pBVar5 = rnd;
        pBVar3 = BN_bin2bn(unaff_s1,unaff_s2,rnd);
        uVar9 = (uint)(pBVar3 != (BIGNUM *)0x0);
      }
      uStack_c8 = unaff_s2;
      (**(code **)(local_38 + -0x7d6c))(unaff_s1);
      (**(code **)(local_38 + -0x7f58))(unaff_s1);
      bits = uVar9;
    }
  }
LAB_004f944c:
  if (local_2c == *(BIGNUM **)puStack_68) {
    return uVar9;
  }
  pcStack_54 = BN_rand;
  pBVar3 = local_2c;
  (**(code **)(local_38 + -0x5330))();
  puStack_bc = PTR___stack_chk_guard_006a9ae8;
  pBStack_7c = *(BIGNUM **)PTR___stack_chk_guard_006a9ae8;
  uVar9 = bits;
  pBStack_b8 = pBStack_64;
  pcStack_b4 = pcStack_60;
  pBStack_ac = pBStack_58;
  uStack_74 = bits;
  pbStack_70 = unaff_s1;
  uStack_6c = unaff_s2;
  puStack_5c = unaff_s6;
  if ((int)uStack_c8 < 0) {
LAB_004f9704:
    uStack_c8 = uVar9;
    pBVar6 = (BIGNUM *)&DAT_00000076;
    pcVar8 = "bn_rand.c";
    uVar9 = 0x7f;
    (*(code *)PTR_ERR_put_error_006a7f34)(3);
    uVar10 = 0;
  }
  else {
    pBStack_b8 = pBVar3;
    pcStack_b4 = pcVar7;
    pBStack_ac = pBVar5;
    if (uStack_c8 == 1) {
      uVar9 = uStack_c8;
      if (0 < (int)pBVar5) goto LAB_004f9704;
    }
    else if (uStack_c8 == 0) {
      uVar9 = uStack_c8;
      pBVar6 = pBVar5;
      pcVar8 = pcVar7;
      BN_set_word(pBVar3,0);
      uVar10 = 1;
      goto LAB_004f96c4;
    }
    uVar9 = (int)(uStack_c8 + 7) >> 3;
    unaff_s1 = (byte *)(*(code *)PTR_CRYPTO_malloc_006a7008)(uVar9,"bn_rand.c",0x8a);
    unaff_s2 = uVar9;
    if (unaff_s1 == (byte *)0x0) {
      pcVar8 = "bn_rand.c";
      pBVar6 = (BIGNUM *)&DAT_00000041;
      uVar9 = 0x7f;
      uStack_c8 = 0;
      (*(code *)PTR_ERR_put_error_006a7f34)(3);
      uVar10 = 0;
      unaff_s6 = CAST_S_table3 + 0x110;
    }
    else {
      (*(code *)PTR_time_006a9adc)(auStack_80);
      pcVar8 = (char *)0x0;
      pBVar6 = (BIGNUM *)0x0;
      (*(code *)PTR_RAND_add_006a8004)(auStack_80,4);
      iVar2 = (*(code *)PTR_RAND_bytes_006a7574)(unaff_s1,uVar9);
      if (iVar2 < 1) {
        uVar10 = 0;
      }
      else {
        uVar10 = uStack_c8 - 1 & 7;
        if ((int)pBVar5 < 0) {
          bVar4 = *unaff_s1;
        }
        else if (pBVar5 == (BIGNUM *)0x0) {
          bVar4 = (byte)(1 << uVar10) | *unaff_s1;
        }
        else if (uVar10 == 0) {
          bVar4 = 1;
          unaff_s1[1] = unaff_s1[1] | 0x80;
        }
        else {
          bVar4 = (byte)(3 << (uVar10 - 1 & 0x1f)) | *unaff_s1;
        }
        *unaff_s1 = bVar4 & ~(byte)(0xff << uVar10 + 1);
        if (pcVar7 != (char *)0x0) {
          unaff_s1[uVar9 - 1] = unaff_s1[uVar9 - 1] | 1;
        }
        pBVar6 = pBVar3;
        pBVar5 = BN_bin2bn(unaff_s1,uVar9,pBVar3);
        uVar10 = (uint)(pBVar5 != (BIGNUM *)0x0);
      }
      (*(code *)PTR_OPENSSL_cleanse_006a7074)(unaff_s1);
      (*(code *)PTR_CRYPTO_free_006a6e88)(unaff_s1);
      uStack_c8 = uVar10;
      unaff_s6 = auStack_80;
    }
  }
LAB_004f96c4:
  if (pBStack_7c == *(BIGNUM **)puStack_bc) {
    return uVar10;
  }
  pBVar5 = pBStack_7c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iStack_cc = *(int *)PTR___stack_chk_guard_006a9ae8;
  pbStack_c4 = unaff_s1;
  uStack_c0 = unaff_s2;
  puStack_b0 = unaff_s6;
  if ((int)uVar9 < 0) {
LAB_004f9998:
    uVar9 = 0x7f;
    (*(code *)PTR_ERR_put_error_006a7f34)(3,0x7f,0x76,"bn_rand.c",0x7d);
    uVar10 = 0;
  }
  else {
    if (uVar9 == 1) {
      if (0 < (int)pBVar6) goto LAB_004f9998;
    }
    else if (uVar9 == 0) {
      BN_set_word(pBVar5,0);
      uVar10 = 1;
      goto LAB_004f9940;
    }
    len = (int)(uVar9 + 7) >> 3;
    s = (byte *)(*(code *)PTR_CRYPTO_malloc_006a7008)(len,"bn_rand.c",0x8a);
    if (s == (byte *)0x0) {
      uVar9 = 0x7f;
      (*(code *)PTR_ERR_put_error_006a7f34)(3,0x7f,0x41,"bn_rand.c",0x8c);
      uVar10 = 0;
    }
    else {
      (*(code *)PTR_time_006a9adc)(auStack_d0);
      (*(code *)PTR_RAND_add_006a8004)(auStack_d0,4,0,0);
      iVar2 = (*(code *)PTR_RAND_bytes_006a7574)(s,len);
      if (iVar2 < 1) {
LAB_004f99c4:
        uVar10 = 0;
      }
      else {
        uVar10 = 0;
        pbVar11 = s;
LAB_004f98b4:
        do {
          iVar2 = (*(code *)PTR_RAND_pseudo_bytes_006a7a60)(&bStack_d1,1);
          if (iVar2 < 0) goto LAB_004f99c4;
          if ((char)bStack_d1 < '\0') {
            if (uVar10 != 0) {
              *pbVar11 = pbVar11[-1];
            }
          }
          else if (bStack_d1 < 0x2a) {
            *pbVar11 = 0;
          }
          else if (bStack_d1 < 0x54) {
            uVar10 = uVar10 + 1;
            *pbVar11 = 0xff;
            pbVar11 = pbVar11 + 1;
            if (len == uVar10) break;
            goto LAB_004f98b4;
          }
          uVar10 = uVar10 + 1;
          pbVar11 = pbVar11 + 1;
        } while (len != uVar10);
        uVar9 = uVar9 - 1 & 7;
        if ((int)pBVar6 < 0) {
          bVar4 = *s;
        }
        else if (pBVar6 == (BIGNUM *)0x0) {
          bVar4 = (byte)(1 << uVar9) | *s;
        }
        else if (uVar9 == 0) {
          bVar4 = 1;
          s[1] = s[1] | 0x80;
        }
        else {
          bVar4 = (byte)(3 << (uVar9 - 1 & 0x1f)) | *s;
        }
        *s = bVar4 & ~(byte)(0xff << uVar9 + 1);
        if (pcVar8 != (char *)0x0) {
          s[len - 1] = s[len - 1] | 1;
        }
        pBVar5 = BN_bin2bn(s,len,pBVar5);
        uVar10 = (uint)(pBVar5 != (BIGNUM *)0x0);
      }
      (*(code *)PTR_OPENSSL_cleanse_006a7074)(s,len);
      (*(code *)PTR_CRYPTO_free_006a6e88)(s);
      uVar9 = len;
    }
  }
LAB_004f9940:
  if (iStack_cc == *(int *)puVar1) {
    return uVar10;
  }
  iVar2 = iStack_cc;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar2 = bn_rand_range(0,iVar2,uVar9);
  return iVar2;
}

