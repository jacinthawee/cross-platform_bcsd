
/* WARNING: Removing unreachable block (ram,0x00628dc8) */

int RSA_padding_add_PKCS1_PSS_mgf1
              (RSA *rsa,uchar *EM,uchar *mHash,EVP_MD *Hash,EVP_MD *mgf1Hash,int sLen)

{
  byte bVar1;
  undefined *puVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint *puVar7;
  uint *puVar8;
  uint uVar9;
  uint *puVar10;
  undefined4 uVar11;
  uint *puVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  RSA *pRVar16;
  int unaff_s7;
  uint *unaff_s8;
  uint *local_54;
  int local_50;
  byte *local_4c;
  uint auStack_44 [6];
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  if (mgf1Hash == (EVP_MD *)0x0) {
    mgf1Hash = Hash;
  }
  puVar3 = (uint *)(*(code *)PTR_EVP_MD_size_006a7e3c)(Hash);
  if ((int)puVar3 < 0) goto LAB_00628c04;
  if (sLen == -1) {
    iVar4 = (*(code *)PTR_BN_num_bits_006a71f4)(rsa->n);
    unaff_s7 = (*(code *)PTR_RSA_size_006a7640)(rsa);
    sLen = (int)puVar3;
joined_r0x00628c74:
    pRVar16 = (RSA *)(iVar4 - 1U & 7);
    if (pRVar16 == (RSA *)0x0) {
      *EM = '\0';
      unaff_s7 = unaff_s7 + -1;
      EM = EM + 1;
      pRVar16 = (RSA *)0x0;
      if ((undefined *)sLen == &SUB_fffffffe) goto LAB_00628c94;
    }
    if (unaff_s7 <= (int)((byte *)((int)puVar3 + sLen) + 1)) {
      uVar11 = 0x6e;
      uVar6 = 0xe5;
      rsa = pRVar16;
LAB_00628bf0:
      (*(code *)PTR_ERR_put_error_006a7f34)(4,0x94,uVar11,"rsa_pss.c",uVar6);
LAB_00628c04:
      iVar4 = 0;
      pRVar16 = rsa;
      goto LAB_00628c08;
    }
    if (sLen < 1) goto LAB_00628ca8;
LAB_00628b54:
    unaff_s8 = (uint *)(*(code *)PTR_CRYPTO_malloc_006a7008)(sLen,"rsa_pss.c",0xe9);
    if (unaff_s8 == (uint *)0x0) {
      (*(code *)PTR_ERR_put_error_006a7f34)(4,0x94,0x41,"rsa_pss.c",0xec);
      rsa = pRVar16;
      goto LAB_00628c04;
    }
    iVar4 = (*(code *)PTR_RAND_bytes_006a7574)(unaff_s8,sLen);
    if (iVar4 < 1) {
      iVar4 = 0;
      goto LAB_00628bcc;
    }
    (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(auStack_44);
    iVar4 = 0;
    iVar5 = (*(code *)PTR_EVP_DigestInit_ex_006a757c)(auStack_44,Hash,0);
    if (iVar5 == 0) goto LAB_00628bcc;
    iVar5 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_44,&zeroes,8);
    if (iVar5 == 0) goto LAB_00628bcc;
    local_50 = (unaff_s7 - (int)puVar3) + -1;
    iVar5 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_44,mHash,puVar3);
    local_4c = EM + local_50;
    if (iVar5 == 0) goto LAB_00628bcc;
LAB_00628d3c:
    local_54 = auStack_44;
    iVar4 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(local_54,unaff_s8,sLen);
    if (iVar4 == 0) goto LAB_00628d70;
  }
  else {
    if (sLen != -2) {
      if (-3 < sLen) {
        iVar4 = (*(code *)PTR_BN_num_bits_006a71f4)(rsa->n);
        unaff_s7 = (*(code *)PTR_RSA_size_006a7640)(rsa);
        goto joined_r0x00628c74;
      }
      uVar11 = 0x88;
      uVar6 = 0xd7;
      goto LAB_00628bf0;
    }
    iVar4 = (*(code *)PTR_BN_num_bits_006a71f4)(rsa->n);
    pRVar16 = (RSA *)(iVar4 - 1U & 7);
    unaff_s7 = (*(code *)PTR_RSA_size_006a7640)(rsa);
    if (pRVar16 == (RSA *)0x0) {
      *EM = '\0';
      unaff_s7 = unaff_s7 + -1;
      EM = EM + 1;
      pRVar16 = (RSA *)0x0;
    }
LAB_00628c94:
    sLen = (unaff_s7 - (int)puVar3) + -2;
    if (0 < sLen) goto LAB_00628b54;
LAB_00628ca8:
    unaff_s8 = auStack_44;
    local_50 = (unaff_s7 - (int)puVar3) + -1;
    (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(unaff_s8);
    iVar4 = (*(code *)PTR_EVP_DigestInit_ex_006a757c)(unaff_s8,Hash,0);
    local_4c = EM + local_50;
    rsa = pRVar16;
    if (((iVar4 == 0) ||
        (iVar4 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(unaff_s8,&zeroes,8), iVar4 == 0)) ||
       (iVar4 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(unaff_s8,mHash,puVar3), iVar4 == 0))
    goto LAB_00628c04;
    unaff_s8 = (uint *)0x0;
    if ((uint *)sLen != (uint *)0x0) goto LAB_00628d3c;
  }
  local_54 = auStack_44;
  iVar4 = (*(code *)PTR_EVP_DigestFinal_ex_006a7584)(local_54,local_4c,0);
  if (iVar4 != 0) {
    (*(code *)PTR_EVP_MD_CTX_cleanup_006a6e34)(local_54);
    iVar4 = (*(code *)PTR_PKCS1_MGF1_006a9910)(EM,local_50,local_4c,puVar3,mgf1Hash);
    if (iVar4 == 0) {
      iVar4 = (unaff_s7 - sLen) - (int)puVar3;
      puVar3 = (uint *)(EM + iVar4 + -1);
      EM[iVar4 + -2] = EM[iVar4 + -2] ^ 1;
      if (sLen < 1) goto LAB_00628f50;
      if ((uint)sLen < &DAT_00000007 || unaff_s8 < EM + iVar4 + 3 && puVar3 < unaff_s8 + 1)
      goto LAB_00628f9c;
      if ((((uint)unaff_s8 | (uint)puVar3) & 3) != 0) goto LAB_00628f9c;
      uVar13 = 0;
      uVar9 = ((uint)(sLen + -4) >> 2) + 1;
      puVar8 = (uint *)(uVar9 * 4);
      puVar10 = puVar3;
      puVar7 = unaff_s8;
      puVar12 = puVar3;
      do {
        uVar14 = *puVar7;
        uVar13 = uVar13 + 1;
        uVar15 = *puVar12;
        puVar7 = puVar7 + 1;
        puVar12 = puVar12 + 1;
        *puVar10 = uVar14 ^ uVar15;
        puVar10 = puVar10 + 1;
      } while (uVar13 < uVar9);
      puVar3 = puVar3 + uVar9;
      if ((uint *)sLen == puVar8) goto LAB_00628f50;
      *(byte *)puVar3 = *(byte *)(unaff_s8 + uVar9) ^ *(byte *)puVar3;
      if (sLen <= (int)(byte *)((int)puVar8 + 1)) goto LAB_00628f50;
      sLen = (int)((int)(byte *)((int)puVar8 + 2) < sLen);
      *(byte *)((int)puVar3 + 1) =
           *(byte *)((int)unaff_s8 + (int)(byte *)((int)puVar8 + 1)) ^ *(byte *)((int)puVar3 + 1);
      if ((uint *)sLen == (uint *)0x0) goto LAB_00628f50;
      *(byte *)((int)puVar3 + 2) =
           *(byte *)((int)unaff_s8 + (int)(byte *)((int)puVar8 + 2)) ^ *(byte *)((int)puVar3 + 2);
      goto LAB_00628f50;
    }
  }
LAB_00628d70:
  iVar4 = 0;
  while( true ) {
    if (unaff_s8 != (uint *)0x0) {
LAB_00628bcc:
      (*(code *)PTR_CRYPTO_free_006a6e88)(unaff_s8);
    }
LAB_00628c08:
    if (local_2c == *(int *)puVar2) break;
    puVar3 = (uint *)(*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_00628f9c:
    sLen = (int)puVar3 + sLen;
    puVar10 = unaff_s8;
    do {
      puVar7 = (uint *)((int)puVar3 + 1);
      bVar1 = *(byte *)puVar10;
      puVar10 = (uint *)((int)puVar10 + 1);
      *(byte *)puVar3 = *(byte *)puVar3 ^ bVar1;
      puVar3 = puVar7;
    } while (puVar7 != (uint *)sLen);
LAB_00628f50:
    if (pRVar16 != (RSA *)0x0) {
      *EM = (byte)(0xff >> (8U - (int)pRVar16 & 0x1f)) & *EM;
    }
    EM = EM + unaff_s7;
    iVar4 = 1;
    EM[-1] = 0xbc;
  }
  return iVar4;
}

