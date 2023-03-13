
int RSA_verify_PKCS1_PSS(RSA *rsa,uchar *mHash,EVP_MD *Hash,uchar *EM,int sLen)

{
  byte bVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint *puVar9;
  byte *pbVar10;
  uint uVar11;
  int iVar12;
  uint *puVar13;
  undefined4 uVar14;
  uint uVar15;
  char *pcVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint *unaff_s8;
  int local_90;
  undefined auStack_84 [24];
  undefined auStack_6c [64];
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(auStack_84);
  iVar3 = (*(code *)PTR_EVP_MD_size_006a7e3c)(Hash);
  if (iVar3 < 0) goto LAB_00627b44;
  iVar8 = iVar3;
  if (((sLen == -1) || (iVar8 = sLen, sLen == -2)) || (-3 < sLen)) {
    iVar4 = (*(code *)PTR_BN_num_bits_006a71f4)(rsa->n);
    uVar19 = iVar4 - 1U & 7;
    iVar4 = (*(code *)PTR_RSA_size_006a7640)(rsa);
    if (((uint)*EM & 0xff << uVar19) == 0) {
      if (uVar19 == 0) {
        EM = EM + 1;
        iVar4 = iVar4 + -1;
      }
      if (iVar3 + iVar8 + 1 < iVar4) {
        if (*(byte *)((int)EM + iVar4 + -1) == 0xbc) {
          iVar4 = iVar4 - iVar3;
          uVar17 = iVar4 - 1;
          local_90 = 0x680000;
          unaff_s8 = (uint *)(*(code *)PTR_CRYPTO_malloc_006a7008)(uVar17,"rsa_pss.c",0x87);
          pbVar10 = (byte *)((int)EM + uVar17);
          if (unaff_s8 == (uint *)0x0) {
            (*(code *)PTR_ERR_put_error_006a7f34)(4,0x95,0x41,"rsa_pss.c",0x89);
            goto LAB_00627b44;
          }
          iVar6 = (*(code *)PTR_PKCS1_MGF1_006a9910)
                            (unaff_s8,uVar17,(byte *)((int)EM + uVar17),iVar3,Hash);
          if (iVar6 < 0) goto LAB_00627dd8;
          if ((int)uVar17 < 1) {
LAB_00627d38:
            if (uVar19 == 0) {
              uVar19 = (uint)*(byte *)unaff_s8;
              goto LAB_00627d58;
            }
          }
          else {
            if ((6 < uVar17 && ((uint *)((int)EM + 4) <= unaff_s8 || unaff_s8 + 1 <= EM)) &&
               ((((uint)EM | (uint)unaff_s8) & 3) == 0)) {
              uVar18 = 0;
              uVar7 = (iVar4 - 5U >> 2) + 1;
              uVar11 = uVar7 * 4;
              puVar13 = unaff_s8;
              puVar9 = (uint *)EM;
              do {
                uVar15 = *puVar9;
                uVar18 = uVar18 + 1;
                puVar9 = puVar9 + 1;
                *puVar13 = uVar15 ^ *puVar13;
                puVar13 = puVar13 + 1;
              } while (uVar18 < uVar7);
              if (uVar17 != uVar11) {
                iVar6 = uVar11 + 1;
                *(byte *)(unaff_s8 + uVar7) =
                     *(byte *)((int)EM + uVar7 * 4) ^ *(byte *)(unaff_s8 + uVar7);
                if (iVar6 < (int)uVar17) {
                  iVar12 = uVar11 + 2;
                  *(byte *)((int)unaff_s8 + iVar6) =
                       *(byte *)((int)EM + iVar6) ^ *(byte *)((int)unaff_s8 + iVar6);
                  if (iVar12 < (int)uVar17) {
                    *(byte *)((int)unaff_s8 + iVar12) =
                         *(byte *)((int)EM + iVar12) ^ *(byte *)((int)unaff_s8 + iVar12);
                  }
                }
              }
              goto LAB_00627d38;
            }
            puVar13 = unaff_s8;
            do {
              puVar9 = (uint *)((int)puVar13 + 1);
              bVar1 = *EM;
              EM = (uchar *)((int)EM + 1);
              *(byte *)puVar13 = *(byte *)puVar13 ^ bVar1;
              puVar13 = puVar9;
            } while (puVar9 != (uint *)((int)unaff_s8 + uVar17));
            if (uVar19 == 0) {
              uVar19 = (uint)*(byte *)unaff_s8;
              goto LAB_00627d58;
            }
          }
          uVar19 = 0xff >> (8 - uVar19 & 0x1f) & (uint)*(byte *)unaff_s8;
          *(byte *)unaff_s8 = (byte)uVar19;
LAB_00627d58:
          if (uVar19 == 0) {
            if (2 < iVar4) {
              iVar6 = 0;
              puVar13 = unaff_s8;
              do {
                puVar13 = (uint *)((int)puVar13 + 1);
                uVar19 = (uint)*(byte *)puVar13;
                iVar12 = iVar6 + 1;
                if (uVar19 != 0) {
                  uVar7 = iVar6 + 2;
                  goto LAB_00627d98;
                }
                iVar6 = iVar12;
              } while (iVar12 != iVar4 + -2);
            }
          }
          else {
            uVar7 = 1;
LAB_00627d98:
            if (uVar19 == 1) {
              if ((-1 < iVar8) && (iVar8 != uVar17 - uVar7)) {
                uVar14 = 0x88;
                pcVar16 = "rsa_pss.c";
                uVar5 = 0x98;
                goto LAB_00627dc8;
              }
              iVar8 = (*(code *)PTR_EVP_DigestInit_ex_006a757c)(auStack_84,Hash,0);
              if (iVar8 == 0) goto LAB_00627dd8;
              iVar8 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_84,&zeroes,8);
              if (iVar8 == 0) goto LAB_00627dd8;
              iVar8 = (*(code *)PTR_EVP_DigestUpdate_006a7580)(auStack_84,mHash,iVar3);
              if (iVar8 == 0) goto LAB_00627dd8;
              if ((uVar17 != uVar7) &&
                 (iVar8 = (*(code *)PTR_EVP_DigestUpdate_006a7580)
                                    (auStack_84,(byte *)((int)unaff_s8 + uVar7),uVar17 - uVar7),
                 iVar8 == 0)) goto LAB_00627dd8;
              iVar8 = (*(code *)PTR_EVP_DigestFinal_ex_006a7584)(auStack_84,auStack_6c,0);
              if (iVar8 == 0) goto LAB_00627dd8;
              iVar3 = (*(code *)PTR_memcmp_006a9ad0)(auStack_6c,pbVar10,iVar3);
              if (iVar3 != 0) goto LAB_00627f4c;
              iVar3 = 1;
              goto LAB_00627ddc;
            }
          }
          uVar14 = 0x87;
          pcVar16 = "rsa_pss.c";
          uVar5 = 0x94;
          goto LAB_00627dc8;
        }
        uVar14 = 0x86;
        uVar5 = 0x82;
      }
      else {
        uVar14 = 0x6d;
        uVar5 = 0x7e;
      }
    }
    else {
      uVar14 = 0x85;
      uVar5 = 0x76;
    }
  }
  else {
    uVar14 = 0x88;
    uVar5 = 0x6f;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(4,0x95,uVar14,"rsa_pss.c",uVar5);
LAB_00627b44:
  iVar3 = 0;
  while( true ) {
    (*(code *)PTR_EVP_MD_CTX_cleanup_006a6e34)(auStack_84);
    if (local_2c == *(int *)puVar2) break;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_00627f4c:
    uVar14 = 0x68;
    pcVar16 = (char *)(local_90 + -0x3c48);
    uVar5 = 0xa6;
LAB_00627dc8:
    (*(code *)PTR_ERR_put_error_006a7f34)(4,0x95,uVar14,pcVar16,uVar5);
LAB_00627dd8:
    iVar3 = 0;
LAB_00627ddc:
    (*(code *)PTR_CRYPTO_free_006a6e88)(unaff_s8);
  }
  return iVar3;
}

