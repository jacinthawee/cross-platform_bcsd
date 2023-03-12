
int BN_bntest_rand(BIGNUM *rnd,int bits,int top,int bottom)

{
  undefined *puVar1;
  byte *s;
  int iVar2;
  byte bVar4;
  BIGNUM *pBVar3;
  int iVar5;
  uint uVar6;
  byte *pbVar7;
  byte local_31;
  undefined auStack_30 [4];
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (bits == 0) {
    BN_set_word(rnd,0);
    uVar6 = 1;
  }
  else {
    iVar5 = bits + 7;
    if (bits + 7 < 0) {
      iVar5 = bits + 0xe;
    }
    iVar5 = iVar5 >> 3;
    s = (byte *)(*(code *)PTR_CRYPTO_malloc_006a8108)(iVar5,"bn_rand.c",0x86);
    if (s == (byte *)0x0) {
      bits = 0x7f;
      (*(code *)PTR_ERR_put_error_006a9030)(3,0x7f,0x41,"bn_rand.c",0x89);
      uVar6 = 0;
    }
    else {
      (*(code *)PTR_time_006aabe4)(auStack_30);
      (*(code *)PTR_RAND_add_006a9020)(auStack_30,4,0,0);
      iVar2 = (*(code *)PTR_RAND_pseudo_bytes_006a8664)(s,iVar5);
      if (iVar2 == -1) {
        uVar6 = 0;
      }
      else {
        if (0 < iVar5) {
          iVar2 = 0;
          pbVar7 = s;
          do {
            while ((*(code *)PTR_RAND_pseudo_bytes_006a8664)(&local_31,1), (char)local_31 < '\0') {
              if (0 < iVar2) {
                *pbVar7 = pbVar7[-1];
              }
LAB_004fbf30:
              iVar2 = iVar2 + 1;
              pbVar7 = pbVar7 + 1;
              if (iVar5 == iVar2) goto LAB_004fbf84;
            }
            if (local_31 < 0x2a) {
              *pbVar7 = 0;
              goto LAB_004fbf30;
            }
            if (0x53 < local_31) goto LAB_004fbf30;
            iVar2 = iVar2 + 1;
            *pbVar7 = 0xff;
            pbVar7 = pbVar7 + 1;
          } while (iVar5 != iVar2);
        }
LAB_004fbf84:
        uVar6 = bits - 1U & 0x80000007;
        if ((int)uVar6 < 0) {
          uVar6 = (uVar6 - 1 | 0xfffffff8) + 1;
        }
        if (top == -1) {
          bVar4 = *s;
        }
        else if (top == 0) {
          bVar4 = (byte)(1 << (uVar6 & 0x1f)) | *s;
        }
        else if (uVar6 == 0) {
          bVar4 = 1;
          s[1] = s[1] | 0x80;
        }
        else {
          bVar4 = (byte)(3 << (uVar6 - 1 & 0x1f)) | *s;
        }
        *s = bVar4 & ~(byte)(0xff << (uVar6 + 1 & 0x1f));
        if (bottom != 0) {
          s[iVar5 + -1] = s[iVar5 + -1] | 1;
        }
        pBVar3 = BN_bin2bn(s,iVar5,rnd);
        uVar6 = (uint)(pBVar3 != (BIGNUM *)0x0);
      }
      (*(code *)PTR_OPENSSL_cleanse_006a8174)(s,iVar5);
      (*(code *)PTR_CRYPTO_free_006a7f88)(s);
      bits = iVar5;
    }
  }
  if (local_2c != *(int *)puVar1) {
    iVar5 = local_2c;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    iVar5 = bn_rand_range(0,iVar5,bits);
    return iVar5;
  }
  return uVar6;
}

