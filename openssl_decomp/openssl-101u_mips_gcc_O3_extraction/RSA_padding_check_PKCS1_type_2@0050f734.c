
int RSA_padding_check_PKCS1_type_2(uchar *to,int tlen,uchar *f,int fl,int rsa_len)

{
  undefined4 uVar1;
  byte *pbVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  
  if (tlen < 0) {
    return -1;
  }
  if (fl < 0) {
    return -1;
  }
  if ((fl <= rsa_len) && (10 < rsa_len)) {
    pbVar2 = (byte *)(*(code *)PTR_CRYPTO_malloc_006a7008)(rsa_len,"rsa_pk1.c",0xce);
    if (pbVar2 == (byte *)0x0) {
      uVar5 = 0x41;
      uVar1 = 0xd0;
      goto LAB_0050f7a0;
    }
    (*(code *)PTR_memset_006a99f4)(pbVar2,0,rsa_len);
    (*(code *)PTR_memcpy_006a9aec)(pbVar2 + (rsa_len - fl),f,fl);
    pbVar9 = pbVar2 + 2;
    uVar7 = 0;
    uVar8 = 0;
    uVar6 = 2;
    do {
      uVar3 = uVar6 ^ uVar7;
      uVar4 = (int)(~(uint)*pbVar9 & *pbVar9 - 1) >> 0x1f;
      uVar6 = uVar6 + 1;
      uVar7 = ~uVar8 & uVar3 & uVar4 ^ uVar7;
      uVar8 = uVar8 | uVar4;
      pbVar9 = pbVar9 + 1;
    } while (rsa_len != uVar6);
    uVar6 = rsa_len - (uVar7 + 1);
    if ((~((int)((tlen - uVar6 ^ uVar6 | tlen ^ uVar6) ^ tlen) >> 0x1f) &
        ~((int)((uVar7 - 10 ^ 10 | uVar7 ^ 10) ^ uVar7) >> 0x1f) &
        (int)(~(uint)*pbVar2 & *pbVar2 - 1 & (pbVar2[1] ^ 2) - 1 & ~(pbVar2[1] ^ 2)) >> 0x1f) == 0)
    {
      (*(code *)PTR_CRYPTO_free_006a6e88)(pbVar2);
    }
    else {
      (*(code *)PTR_memcpy_006a9aec)(to,pbVar2 + uVar7 + 1,uVar6);
      (*(code *)PTR_CRYPTO_free_006a6e88)(pbVar2);
      if (uVar6 != 0xffffffff) {
        return uVar6;
      }
    }
  }
  uVar5 = 0x9f;
  uVar1 = 0x111;
LAB_0050f7a0:
  (*(code *)PTR_ERR_put_error_006a7f34)(4,0x71,uVar5,"rsa_pk1.c",uVar1);
  return -1;
}

