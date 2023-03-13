
int BN_bntest_rand(BIGNUM *rnd,int bits,int top,int bottom)

{
  undefined *puVar1;
  byte *s;
  int iVar2;
  int iVar3;
  BIGNUM *pBVar4;
  byte bVar5;
  int iVar6;
  uint uVar7;
  byte *pbVar8;
  byte local_31;
  undefined auStack_30 [4];
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (bits < 0) {
LAB_004f9998:
    bits = 0x7f;
    (*(code *)PTR_ERR_put_error_006a7f34)(3,0x7f,0x76,"bn_rand.c",0x7d);
    uVar7 = 0;
  }
  else {
    if (bits == 1) {
      if (0 < top) goto LAB_004f9998;
    }
    else if (bits == 0) {
      BN_set_word(rnd,0);
      uVar7 = 1;
      goto LAB_004f9940;
    }
    iVar6 = bits + 7 >> 3;
    s = (byte *)(*(code *)PTR_CRYPTO_malloc_006a7008)(iVar6,"bn_rand.c",0x8a);
    if (s == (byte *)0x0) {
      bits = 0x7f;
      (*(code *)PTR_ERR_put_error_006a7f34)(3,0x7f,0x41,"bn_rand.c",0x8c);
      uVar7 = 0;
    }
    else {
      (*(code *)PTR_time_006a9adc)(auStack_30);
      (*(code *)PTR_RAND_add_006a8004)(auStack_30,4,0,0);
      iVar2 = (*(code *)PTR_RAND_bytes_006a7574)(s,iVar6);
      if (iVar2 < 1) {
LAB_004f99c4:
        uVar7 = 0;
      }
      else {
        iVar2 = 0;
        pbVar8 = s;
LAB_004f98b4:
        do {
          iVar3 = (*(code *)PTR_RAND_pseudo_bytes_006a7a60)(&local_31,1);
          if (iVar3 < 0) goto LAB_004f99c4;
          if ((char)local_31 < '\0') {
            if (iVar2 != 0) {
              *pbVar8 = pbVar8[-1];
            }
          }
          else if (local_31 < 0x2a) {
            *pbVar8 = 0;
          }
          else if (local_31 < 0x54) {
            iVar2 = iVar2 + 1;
            *pbVar8 = 0xff;
            pbVar8 = pbVar8 + 1;
            if (iVar6 == iVar2) break;
            goto LAB_004f98b4;
          }
          iVar2 = iVar2 + 1;
          pbVar8 = pbVar8 + 1;
        } while (iVar6 != iVar2);
        uVar7 = bits - 1U & 7;
        if (top < 0) {
          bVar5 = *s;
        }
        else if (top == 0) {
          bVar5 = (byte)(1 << uVar7) | *s;
        }
        else if (uVar7 == 0) {
          bVar5 = 1;
          s[1] = s[1] | 0x80;
        }
        else {
          bVar5 = (byte)(3 << (uVar7 - 1 & 0x1f)) | *s;
        }
        *s = bVar5 & ~(byte)(0xff << uVar7 + 1);
        if (bottom != 0) {
          s[iVar6 + -1] = s[iVar6 + -1] | 1;
        }
        pBVar4 = BN_bin2bn(s,iVar6,rnd);
        uVar7 = (uint)(pBVar4 != (BIGNUM *)0x0);
      }
      (*(code *)PTR_OPENSSL_cleanse_006a7074)(s,iVar6);
      (*(code *)PTR_CRYPTO_free_006a6e88)(s);
      bits = iVar6;
    }
  }
LAB_004f9940:
  if (local_2c == *(int *)puVar1) {
    return uVar7;
  }
  iVar6 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar6 = bn_rand_range(0,iVar6,bits);
  return iVar6;
}

