
/* WARNING: Removing unreachable block (ram,0x006291f4) */

int RSA_padding_add_PKCS1_PSS(RSA *rsa,uchar *EM,uchar *mHash,EVP_MD *Hash,int sLen)

{
  byte bVar1;
  undefined *puVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  undefined4 uVar6;
  uint *puVar7;
  uint *puVar8;
  byte *pbVar10;
  uint uVar11;
  uint *puVar12;
  undefined4 uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  RSA *pRVar17;
  int unaff_s6;
  uint *unaff_s8;
  uint *local_4c;
  undefined auStack_44 [24];
  int local_2c;
  uint *puVar9;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  uVar3 = (*(code *)PTR_EVP_MD_size_006a8f2c)(Hash);
  if ((int)uVar3 < 0) goto LAB_0062907c;
  if (sLen == -1) {
    iVar4 = (*(code *)PTR_BN_num_bits_006a82f4)(rsa->n);
    unaff_s6 = (*(code *)PTR_RSA_size_006a8730)(rsa);
    sLen = uVar3;
joined_r0x006290ec:
    pRVar17 = (RSA *)(iVar4 - 1U & 7);
    if (pRVar17 == (RSA *)0x0) {
      *EM = '\0';
      unaff_s6 = unaff_s6 + -1;
      EM = EM + 1;
      pRVar17 = (RSA *)0x0;
      if (sLen == 0xfffffffe) goto LAB_0062910c;
    }
    if (unaff_s6 <= (int)(uVar3 + sLen + 1)) {
      uVar13 = 0x6e;
      uVar6 = 0xed;
      rsa = pRVar17;
LAB_00629068:
      (*(code *)PTR_ERR_put_error_006a9030)(4,0x94,uVar13,"rsa_pss.c",uVar6);
LAB_0062907c:
      sLen = 0;
      pRVar17 = rsa;
      puVar5 = unaff_s8;
      while (local_2c != *(int *)puVar2) {
        puVar7 = (uint *)(*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_00629470:
        puVar9 = puVar7;
        puVar12 = puVar5;
        do {
          puVar8 = (uint *)((int)puVar9 + 1);
          bVar1 = *(byte *)puVar12;
          puVar12 = (uint *)((int)puVar12 + 1);
          *(byte *)puVar9 = *(byte *)puVar9 ^ bVar1;
          puVar9 = puVar8;
        } while (puVar8 != (uint *)((int)puVar7 + sLen));
LAB_00629424:
        if (pRVar17 != (RSA *)0x0) {
          *EM = (byte)(0xff >> (8U - (int)pRVar17 & 0x1f)) & *EM;
        }
        EM = EM + unaff_s6;
        sLen = 1;
        EM[-1] = 0xbc;
joined_r0x00629294:
        if (puVar5 != (uint *)0x0) {
LAB_00629044:
          (*(code *)PTR_CRYPTO_free_006a7f88)(puVar5);
        }
      }
      return sLen;
    }
    if (sLen < 1) goto LAB_00629120;
LAB_00628fd8:
    puVar5 = (uint *)(*(code *)PTR_CRYPTO_malloc_006a8108)(sLen,"rsa_pss.c",0xf2);
    if (puVar5 == (uint *)0x0) {
      (*(code *)PTR_ERR_put_error_006a9030)(4,0x94,0x41,"rsa_pss.c",0xf5);
      rsa = pRVar17;
      unaff_s8 = puVar5;
      goto LAB_0062907c;
    }
    iVar4 = (*(code *)PTR_RAND_bytes_006a8d44)(puVar5,sLen);
    if (iVar4 < 1) {
LAB_00629040:
      sLen = 0;
      goto LAB_00629044;
    }
    (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(auStack_44);
    iVar4 = (*(code *)PTR_EVP_DigestInit_ex_006a8670)(auStack_44,Hash,0);
    if ((iVar4 == 0) ||
       (iVar4 = (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_44,&zeroes,8), iVar4 == 0))
    goto LAB_00629040;
    local_4c = (uint *)((unaff_s6 - uVar3) + -1);
    iVar4 = (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_44,mHash,uVar3);
    pbVar10 = EM + (int)local_4c;
    if (iVar4 == 0) goto LAB_00629040;
LAB_00629250:
    iVar4 = (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_44,puVar5,sLen);
    if (iVar4 == 0) goto LAB_00629294;
  }
  else {
    if (sLen != -2) {
      if (-3 < sLen) {
        iVar4 = (*(code *)PTR_BN_num_bits_006a82f4)(rsa->n);
        unaff_s6 = (*(code *)PTR_RSA_size_006a8730)(rsa);
        goto joined_r0x006290ec;
      }
      uVar13 = 0x88;
      uVar6 = 0xdc;
      goto LAB_00629068;
    }
    iVar4 = (*(code *)PTR_BN_num_bits_006a82f4)(rsa->n);
    pRVar17 = (RSA *)(iVar4 - 1U & 7);
    unaff_s6 = (*(code *)PTR_RSA_size_006a8730)(rsa);
    if (pRVar17 == (RSA *)0x0) {
      *EM = '\0';
      unaff_s6 = unaff_s6 + -1;
      EM = EM + 1;
      pRVar17 = (RSA *)0x0;
    }
LAB_0062910c:
    sLen = (unaff_s6 - uVar3) - 2;
    if (0 < sLen) goto LAB_00628fd8;
LAB_00629120:
    (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(auStack_44);
    iVar4 = (*(code *)PTR_EVP_DigestInit_ex_006a8670)(auStack_44,Hash,0);
    rsa = pRVar17;
    if ((iVar4 == 0) ||
       (iVar4 = (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_44,&zeroes,8), iVar4 == 0))
    goto LAB_0062907c;
    unaff_s8 = (uint *)((unaff_s6 - uVar3) + -1);
    iVar4 = (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_44,mHash,uVar3);
    pbVar10 = EM + (int)unaff_s8;
    if (iVar4 == 0) goto LAB_0062907c;
    puVar5 = (uint *)0x0;
    local_4c = unaff_s8;
    if (sLen != 0) goto LAB_00629250;
  }
  iVar4 = (*(code *)PTR_EVP_DigestFinal_ex_006a8678)(auStack_44,pbVar10,0);
  if (iVar4 != 0) {
    (*(code *)PTR_EVP_MD_CTX_cleanup_006a7f34)(auStack_44);
    iVar4 = (*(code *)PTR_PKCS1_MGF1_006aaa20)(EM,local_4c,pbVar10,uVar3,Hash);
    if (iVar4 == 0) {
      iVar4 = (unaff_s6 - sLen) - uVar3;
      puVar7 = (uint *)(EM + iVar4 + -1);
      EM[iVar4 + -2] = EM[iVar4 + -2] ^ 1;
      if (sLen < 1) goto LAB_00629424;
      if ((uint)sLen < 7 || puVar5 < EM + iVar4 + 3 && puVar7 < puVar5 + 1) goto LAB_00629470;
      if ((((uint)puVar5 | (uint)puVar7) & 3) != 0) goto LAB_00629470;
      uVar14 = 0;
      uVar11 = (sLen - 4U >> 2) + 1;
      uVar3 = uVar11 * 4;
      puVar9 = puVar7;
      puVar12 = puVar5;
      puVar8 = puVar7;
      do {
        uVar15 = *puVar12;
        uVar14 = uVar14 + 1;
        uVar16 = *puVar8;
        puVar12 = puVar12 + 1;
        puVar8 = puVar8 + 1;
        *puVar9 = uVar15 ^ uVar16;
        puVar9 = puVar9 + 1;
      } while (uVar14 < uVar11);
      puVar7 = puVar7 + uVar11;
      if (sLen == uVar3) goto LAB_00629424;
      *(byte *)puVar7 = *(byte *)(puVar5 + uVar11) ^ *(byte *)puVar7;
      if (sLen <= (int)(uVar3 + 1)) goto LAB_00629424;
      *(byte *)((int)puVar7 + 1) = *(byte *)((int)puVar5 + uVar3 + 1) ^ *(byte *)((int)puVar7 + 1);
      if (sLen <= (int)(uVar3 + 2)) goto LAB_00629424;
      *(byte *)((int)puVar7 + 2) = *(byte *)((int)puVar5 + uVar3 + 2) ^ *(byte *)((int)puVar7 + 2);
      goto LAB_00629424;
    }
  }
LAB_00629294:
  sLen = 0;
  goto joined_r0x00629294;
}
