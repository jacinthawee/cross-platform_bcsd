
int CMS_SignerInfo_verify_content(CMS_SignerInfo *si,BIO *chain)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 uVar8;
  code *pcVar9;
  undefined4 uStack_b0;
  int *piStack_ac;
  undefined *puStack_a4;
  int iStack_a0;
  code *pcStack_9c;
  undefined4 local_88;
  undefined *local_80;
  int local_78;
  undefined auStack_74 [24];
  undefined auStack_5c [64];
  int local_1c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  puStack_a4 = auStack_74;
  local_80 = &_gp;
  local_1c = *(int *)PTR___stack_chk_guard_006a9ae8;
  (*(code *)PTR_EVP_MD_CTX_init_006a6e1c)(puStack_a4);
  iVar2 = (**(code **)(local_80 + -0x5aac))(si);
  if (iVar2 < 0) {
    iVar7 = *(int *)(si + 8);
    iVar2 = cms_DigestAlgorithm_find_ctx(puStack_a4,chain);
    if (iVar2 == 0) goto LAB_005ba348;
    iVar7 = **(int **)(si + 0x14);
    chain = (BIO *)(*(int **)(si + 0x14))[2];
    iStack_a0 = (**(code **)(local_80 + -0x6e04))(puStack_a4,chain,iVar7,*(undefined4 *)(si + 0x20))
    ;
    if (iStack_a0 < 1) {
      iVar7 = 0x9e;
      local_88 = 0x334;
      chain = (BIO *)0x9a;
      iStack_a0 = 0;
      (**(code **)(local_80 + -0x6eac))(0x2e,0x9a,0x9e,"cms_sd.c");
    }
  }
  else {
    uVar3 = (**(code **)(local_80 + -0x7ca0))(0x33);
    piVar4 = (int *)(**(code **)(local_80 + -0x5a40))(si,uVar3,0xfffffffd,4);
    if (piVar4 == (int *)0x0) {
      iVar7 = 0x72;
      local_88 = 0x311;
      chain = (BIO *)0x9a;
      iStack_a0 = -1;
      (**(code **)(local_80 + -0x6eac))(0x2e,0x9a,0x72,"cms_sd.c");
    }
    else {
      iVar7 = *(int *)(si + 8);
      iVar2 = cms_DigestAlgorithm_find_ctx(puStack_a4,chain);
      if (iVar2 != 0) {
        iVar2 = (**(code **)(local_80 + -0x785c))(puStack_a4,auStack_5c,&local_78);
        if (iVar2 < 1) {
          pcVar9 = *(code **)(local_80 + -0x6eac);
          iVar7 = 0x93;
          local_88 = 800;
        }
        else {
          iVar7 = *piVar4;
          if (iVar7 == local_78) {
            chain = (BIO *)piVar4[2];
            iVar2 = (**(code **)(local_80 + -0x5310))(auStack_5c,chain);
            if (iVar2 == 0) {
              iStack_a0 = 1;
            }
            else {
              iVar7 = 0x9e;
              local_88 = 0x32b;
              chain = (BIO *)0x9a;
              iStack_a0 = 0;
              (**(code **)(local_80 + -0x6eac))(0x2e,0x9a,0x9e,"cms_sd.c");
            }
            goto LAB_005ba23c;
          }
          pcVar9 = *(code **)(local_80 + -0x6eac);
          iVar7 = 0x78;
          local_88 = 0x325;
        }
        chain = (BIO *)0x9a;
        (*pcVar9)(0x2e,0x9a,iVar7,"cms_sd.c");
      }
LAB_005ba348:
      iStack_a0 = -1;
    }
  }
LAB_005ba23c:
  (**(code **)(local_80 + -0x7fac))(puStack_a4);
  if (local_1c == *(int *)puVar1) {
    return iStack_a0;
  }
  pcStack_9c = CMS_add_smimecap;
  iVar2 = local_1c;
  (**(code **)(local_80 + -0x5330))();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  puVar6 = &uStack_b0;
  uStack_b0 = 0;
  piStack_ac = *(int **)PTR___stack_chk_guard_006a9ae8;
  iVar5 = (*(code *)PTR_i2d_X509_ALGORS_006a93a4)(chain,puVar6);
  if (iVar5 < 1) {
    iVar2 = 0;
  }
  else {
    iVar7 = 0x10;
    puVar6 = (undefined4 *)0xa7;
    iVar2 = (*(code *)PTR_CMS_signed_add1_attr_by_NID_006a9390)(iVar2,0xa7,0x10,uStack_b0,iVar5);
    (*(code *)PTR_CRYPTO_free_006a6e88)(uStack_b0);
  }
  if (piStack_ac == *(int **)puVar1) {
    return iVar2;
  }
  piVar4 = piStack_ac;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (iVar7 < 1) {
    iVar2 = (*(code *)PTR_X509_ALGOR_new_006a7ec8)();
    if (iVar2 == 0) {
      return 0;
    }
    iVar5 = 0;
    uVar3 = (*(code *)PTR_OBJ_nid2obj_006a7140)(puVar6);
    uVar8 = 0xffffffff;
  }
  else {
    iVar5 = (*(code *)PTR_ASN1_INTEGER_new_006a7160)();
    if (iVar5 == 0) {
      return 0;
    }
    iVar2 = (*(code *)PTR_ASN1_INTEGER_set_006a7164)(iVar5,iVar7);
    if (iVar2 == 0) {
      return 0;
    }
    iVar2 = (*(code *)PTR_X509_ALGOR_new_006a7ec8)();
    if (iVar2 == 0) {
      (*(code *)PTR_ASN1_INTEGER_free_006a6e94)(iVar5);
      return 0;
    }
    uVar3 = (*(code *)PTR_OBJ_nid2obj_006a7140)(puVar6);
    uVar8 = 2;
  }
  (*(code *)PTR_X509_ALGOR_set0_006a8ce4)(iVar2,uVar3,uVar8,iVar5);
  iVar7 = *piVar4;
  if (iVar7 == 0) {
    iVar7 = (*(code *)PTR_sk_new_null_006a6fa4)();
    *piVar4 = iVar7;
    if (iVar7 == 0) goto LAB_005ba520;
  }
  iVar7 = (*(code *)PTR_sk_push_006a6fa8)(iVar7,iVar2);
  if (iVar7 != 0) {
    return 1;
  }
LAB_005ba520:
  (*(code *)PTR_X509_ALGOR_free_006a7ea4)(iVar2);
  return 0;
}

