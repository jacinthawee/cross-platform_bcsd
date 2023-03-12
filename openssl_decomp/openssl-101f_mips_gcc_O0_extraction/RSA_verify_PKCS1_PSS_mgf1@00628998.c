
int RSA_verify_PKCS1_PSS_mgf1
              (RSA *rsa,uchar *mHash,EVP_MD *Hash,EVP_MD *mgf1Hash,uchar *EM,int sLen)

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
  uint uVar14;
  undefined4 uVar15;
  uint uVar16;
  char *pcVar17;
  uint uVar18;
  uint uVar19;
  uint *unaff_s8;
  int local_90;
  undefined auStack_84 [24];
  undefined auStack_6c [64];
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  if (mgf1Hash == (EVP_MD *)0x0) {
    mgf1Hash = Hash;
  }
  (*(code *)PTR_EVP_MD_CTX_init_006a7f1c)(auStack_84);
  iVar3 = (*(code *)PTR_EVP_MD_size_006a8f2c)(Hash);
  if (iVar3 < 0) goto LAB_00628ad4;
  iVar8 = iVar3;
  if (((sLen == -1) || (iVar8 = sLen, sLen == -2)) || (-3 < sLen)) {
    iVar4 = (*(code *)PTR_BN_num_bits_006a82f4)(rsa->n);
    uVar19 = iVar4 - 1U & 7;
    iVar4 = (*(code *)PTR_RSA_size_006a8730)(rsa);
    if (((uint)*EM & 0xff << uVar19) == 0) {
      if (uVar19 == 0) {
        EM = EM + 1;
        iVar4 = iVar4 + -1;
      }
      if (iVar8 + iVar3 + 1 < iVar4) {
        if (*(byte *)((int)EM + iVar4 + -1) == 0xbc) {
          iVar4 = iVar4 - iVar3;
          uVar18 = iVar4 - 1;
          local_90 = 0x680000;
          unaff_s8 = (uint *)(*(code *)PTR_CRYPTO_malloc_006a8108)(uVar18,"rsa_pss.c",0x88);
          pbVar10 = (byte *)((int)EM + uVar18);
          if (unaff_s8 == (uint *)0x0) {
            (*(code *)PTR_ERR_put_error_006a9030)(4,0x95,0x41,"rsa_pss.c",0x8b);
            goto LAB_00628ad4;
          }
          iVar6 = (*(code *)PTR_PKCS1_MGF1_006aaa20)
                            (unaff_s8,uVar18,(byte *)((int)EM + uVar18),iVar3,mgf1Hash);
          if (iVar6 < 0) goto LAB_00628d68;
          if ((int)uVar18 < 1) {
LAB_00628cc8:
            if (uVar19 == 0) {
              uVar19 = (uint)*(byte *)unaff_s8;
              goto LAB_00628ce8;
            }
          }
          else {
            if ((6 < uVar18 && ((uint *)((int)EM + 4) <= unaff_s8 || unaff_s8 + 1 <= EM)) &&
               ((((uint)EM | (uint)unaff_s8) & 3) == 0)) {
              uVar16 = 0;
              uVar7 = (iVar4 - 5U >> 2) + 1;
              uVar11 = uVar7 * 4;
              puVar13 = unaff_s8;
              puVar9 = (uint *)EM;
              do {
                uVar14 = *puVar9;
                uVar16 = uVar16 + 1;
                puVar9 = puVar9 + 1;
                *puVar13 = uVar14 ^ *puVar13;
                puVar13 = puVar13 + 1;
              } while (uVar16 < uVar7);
              if (uVar18 != uVar11) {
                iVar6 = uVar11 + 1;
                *(byte *)(unaff_s8 + uVar7) =
                     *(byte *)((int)EM + uVar7 * 4) ^ *(byte *)(unaff_s8 + uVar7);
                if (iVar6 < (int)uVar18) {
                  iVar12 = uVar11 + 2;
                  *(byte *)((int)unaff_s8 + iVar6) =
                       *(byte *)((int)EM + iVar6) ^ *(byte *)((int)unaff_s8 + iVar6);
                  if (iVar12 < (int)uVar18) {
                    *(byte *)((int)unaff_s8 + iVar12) =
                         *(byte *)((int)EM + iVar12) ^ *(byte *)((int)unaff_s8 + iVar12);
                  }
                }
              }
              goto LAB_00628cc8;
            }
            puVar13 = unaff_s8;
            do {
              puVar9 = (uint *)((int)puVar13 + 1);
              bVar1 = *EM;
              EM = (uchar *)((int)EM + 1);
              *(byte *)puVar13 = *(byte *)puVar13 ^ bVar1;
              puVar13 = puVar9;
            } while (puVar9 != (uint *)((int)unaff_s8 + uVar18));
            if (uVar19 == 0) {
              uVar19 = (uint)*(byte *)unaff_s8;
              goto LAB_00628ce8;
            }
          }
          uVar19 = 0xff >> (8 - uVar19 & 0x1f) & (uint)*(byte *)unaff_s8;
          *(byte *)unaff_s8 = (byte)uVar19;
LAB_00628ce8:
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
                  goto LAB_00628d28;
                }
                iVar6 = iVar12;
              } while (iVar12 != iVar4 + -2);
            }
          }
          else {
            uVar7 = 1;
LAB_00628d28:
            if (uVar19 == 1) {
              if ((-1 < iVar8) && (iVar8 != uVar18 - uVar7)) {
                uVar15 = 0x88;
                pcVar17 = "rsa_pss.c";
                uVar5 = 0x9c;
                goto LAB_00628d58;
              }
              iVar8 = (*(code *)PTR_EVP_DigestInit_ex_006a8670)(auStack_84,Hash,0);
              if (iVar8 == 0) goto LAB_00628d68;
              iVar8 = (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_84,&zeroes,8);
              if (iVar8 == 0) goto LAB_00628d68;
              iVar8 = (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_84,mHash,iVar3);
              if (iVar8 == 0) goto LAB_00628d68;
              if ((uVar18 != uVar7) &&
                 (iVar8 = (*(code *)PTR_EVP_DigestUpdate_006a8674)
                                    (auStack_84,(byte *)((int)unaff_s8 + uVar7),uVar18 - uVar7),
                 iVar8 == 0)) goto LAB_00628d68;
              iVar8 = (*(code *)PTR_EVP_DigestFinal_ex_006a8678)(auStack_84,auStack_6c,0);
              if (iVar8 == 0) goto LAB_00628d68;
              iVar3 = (*(code *)PTR_memcmp_006aabd8)(auStack_6c,pbVar10,iVar3);
              if (iVar3 != 0) goto LAB_00628edc;
              iVar3 = 1;
              goto LAB_00628d6c;
            }
          }
          uVar15 = 0x87;
          pcVar17 = "rsa_pss.c";
          uVar5 = 0x97;
          goto LAB_00628d58;
        }
        uVar15 = 0x86;
        uVar5 = 0x83;
      }
      else {
        uVar15 = 0x6d;
        uVar5 = 0x7e;
      }
    }
    else {
      uVar15 = 0x85;
      uVar5 = 0x74;
    }
  }
  else {
    uVar15 = 0x88;
    uVar5 = 0x6c;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(4,0x95,uVar15,"rsa_pss.c",uVar5);
LAB_00628ad4:
  iVar3 = 0;
  while( true ) {
    (*(code *)PTR_EVP_MD_CTX_cleanup_006a7f34)(auStack_84);
    if (local_2c == *(int *)puVar2) break;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_00628edc:
    uVar15 = 0x68;
    pcVar17 = (char *)(local_90 + -0x33b8);
    uVar5 = 0xac;
LAB_00628d58:
    (*(code *)PTR_ERR_put_error_006a9030)(4,0x95,uVar15,pcVar17,uVar5);
LAB_00628d68:
    iVar3 = 0;
LAB_00628d6c:
    (*(code *)PTR_CRYPTO_free_006a7f88)(unaff_s8);
  }
  return iVar3;
}
