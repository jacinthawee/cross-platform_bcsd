
int RSA_sign_ASN1_OCTET_STRING(int type,uchar *m,uint m_length,uchar *sigret,uint *siglen,RSA *rsa)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uchar **ppuVar7;
  uchar *puVar8;
  char *pcVar9;
  int unaff_s0;
  int unaff_s7;
  int iStack_90;
  int iStack_8c;
  int iStack_84;
  uint uStack_80;
  undefined *puStack_7c;
  RSA *pRStack_78;
  uint *puStack_74;
  uchar *puStack_70;
  uint *puStack_6c;
  int iStack_68;
  code *pcStack_64;
  int local_50;
  undefined4 uStack_4c;
  undefined *local_48;
  int local_40;
  uint local_3c;
  undefined4 local_38;
  uchar *local_34;
  int local_2c;
  
  puStack_7c = PTR___stack_chk_guard_006aabf0;
  puStack_74 = &local_3c;
  local_38 = 4;
  local_48 = &_gp;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  local_3c = m_length;
  local_34 = m;
  uStack_80 = (*(code *)PTR_i2d_ASN1_OCTET_STRING_006a94f8)(puStack_74,0);
  iVar2 = (**(code **)(local_48 + -0x77b0))(rsa);
  if ((int)uStack_80 < iVar2 + -10) {
    unaff_s7 = iVar2 + 1;
    unaff_s0 = (**(code **)(local_48 + -0x7dd8))(unaff_s7,"rsa_saos.c",0x55);
    if (unaff_s0 == 0) {
      pcVar9 = "rsa_saos.c";
      puVar8 = &DAT_00000041;
      iVar2 = 0x76;
      local_50 = 0x58;
      (**(code **)(local_48 + -0x6eb0))(4,0x76,0x41,"rsa_saos.c");
      uVar3 = 0;
    }
    else {
      local_40 = unaff_s0;
      (**(code **)(local_48 + -0x69e8))(puStack_74,&local_40);
      local_50 = 1;
      puVar8 = sigret;
      pcVar9 = (char *)rsa;
      uVar3 = (**(code **)(local_48 + -0x77a4))(uStack_80,unaff_s0,sigret,rsa);
      if (0 < (int)uVar3) {
        *siglen = uVar3;
      }
      uVar3 = (uint)(0 < (int)uVar3);
      iVar2 = unaff_s7;
      (**(code **)(local_48 + -0x7d6c))(unaff_s0,unaff_s7);
      (**(code **)(local_48 + -0x7f58))(unaff_s0);
      uStack_80 = uVar3;
    }
  }
  else {
    puVar8 = &DAT_00000070;
    pcVar9 = "rsa_saos.c";
    local_50 = 0x52;
    iVar2 = 0x76;
    (**(code **)(local_48 + -0x6eb0))(4,0x76,0x70,"rsa_saos.c");
    uVar3 = 0;
  }
  if (local_2c == *(int *)puStack_7c) {
    return uVar3;
  }
  pcStack_64 = RSA_verify_ASN1_OCTET_STRING;
  (**(code **)(local_48 + -0x5328))();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  pRStack_78 = rsa;
  puStack_6c = siglen;
  iStack_8c = *(int *)PTR___stack_chk_guard_006aabf0;
  iStack_84 = unaff_s0;
  puStack_70 = sigret;
  iStack_68 = unaff_s7;
  iVar4 = (*(code *)PTR_RSA_size_006a8730)(uStack_4c);
  if (iVar4 == local_50) {
    iVar5 = (*(code *)PTR_CRYPTO_malloc_006a8108)(iVar4,"rsa_saos.c",0x78);
    if (iVar5 == 0) {
      (*(code *)PTR_ERR_put_error_006a9030)(4,0x78,0x41,"rsa_saos.c",0x7b);
      iVar2 = 0;
    }
    else {
      iVar6 = (*(code *)PTR_RSA_public_decrypt_006a8740)(iVar4,pcVar9,iVar5,uStack_4c,1);
      if ((iVar6 < 1) ||
         (iStack_90 = iVar5,
         ppuVar7 = (uchar **)(*(code *)PTR_d2i_ASN1_OCTET_STRING_006a9510)(0,&iStack_90,iVar6),
         ppuVar7 == (uchar **)0x0)) {
        iVar2 = 0;
      }
      else {
        if ((*ppuVar7 == puVar8) &&
           (iVar2 = (*(code *)PTR_memcmp_006aabd8)(iVar2,ppuVar7[2]), iVar2 == 0)) {
          iVar2 = 1;
        }
        else {
          iVar2 = 0;
          (*(code *)PTR_ERR_put_error_006a9030)(4,0x78,0x68,"rsa_saos.c",0x89);
        }
        (*(code *)PTR_ASN1_STRING_free_006a98bc)(ppuVar7);
      }
      (*(code *)PTR_OPENSSL_cleanse_006a8174)(iVar5,iVar4);
      (*(code *)PTR_CRYPTO_free_006a7f88)(iVar5);
    }
  }
  else {
    (*(code *)PTR_ERR_put_error_006a9030)(4,0x78,0x77,"rsa_saos.c",0x74);
    iVar2 = 0;
  }
  if (iStack_8c != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    iVar2 = (*(code *)PTR_ERR_func_error_string_006a9560)(RSA_str_functs._0_4_);
    if (iVar2 == 0) {
      (*(code *)PTR_ERR_load_strings_006a9564)(0,RSA_str_functs);
                    /* WARNING: Could not recover jumptable at 0x005fb270. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar2 = (*(code *)PTR_ERR_load_strings_006a9564)(0,RSA_str_reasons);
      return iVar2;
    }
    return iVar2;
  }
  return iVar2;
}

