
undefined4
rsa_item_sign(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int *obj;
  void *obj_00;
  ASN1_STRING *pAVar5;
  int iVar6;
  undefined4 uVar7;
  int local_38;
  undefined4 local_34;
  ASN1_OCTET_STRING *local_30;
  int local_2c;
  ASN1_OCTET_STRING *local_28;
  int local_24;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  uVar7 = *(undefined4 *)(param_1 + 0x10);
  local_24 = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar2 = (*(code *)PTR_EVP_PKEY_CTX_ctrl_006a80ec)(uVar7,6,0xffffffff,0x1006,0,&local_38);
  if (iVar2 < 1) {
    uVar3 = 0;
    goto LAB_005fb308;
  }
  uVar3 = 2;
  if (local_38 != 6) goto LAB_005fb308;
  local_30 = (ASN1_OCTET_STRING *)0x0;
  uVar3 = (*(code *)PTR_EVP_PKEY_CTX_get0_pkey_006aa6e0)(uVar7);
  uVar4 = (*(code *)PTR_EVP_MD_CTX_md_006a85fc)(param_1);
  iVar2 = (*(code *)PTR_EVP_PKEY_CTX_ctrl_006a80ec)(uVar7,6,0xf8,0x1008,0,&local_34);
  if ((iVar2 < 1) ||
     (iVar2 = (*(code *)PTR_EVP_PKEY_CTX_ctrl_006a80ec)(uVar7,6,0x18,0x1007,0,&local_2c), iVar2 == 0
     )) {
LAB_005fb604:
    uVar3 = 0;
  }
  else {
    if (local_2c == -1) {
      local_2c = (*(code *)PTR_EVP_MD_size_006a8f2c)(uVar4);
    }
    else if (local_2c == -2) {
      iVar2 = (*(code *)PTR_EVP_PKEY_size_006a85f4)(uVar3);
      iVar6 = (*(code *)PTR_EVP_MD_size_006a8f2c)(uVar4);
      local_2c = (iVar2 - iVar6) + -2;
      iVar2 = (*(code *)PTR_EVP_PKEY_bits_006a80e4)(uVar3);
      if ((iVar2 - 1U & 7) == 0) {
        local_2c = local_2c + -1;
      }
    }
    obj = (int *)(*(code *)PTR_RSA_PSS_PARAMS_new_006aa818)();
    if (obj == (int *)0x0) goto LAB_005fb604;
    if (local_2c == 0x14) {
LAB_005fb430:
      iVar2 = (*(code *)PTR_EVP_MD_type_006a84cc)(uVar4);
      if (iVar2 != 0x40) {
        iVar2 = (*(code *)PTR_X509_ALGOR_new_006a8fb8)();
        *obj = iVar2;
        if (iVar2 == 0) goto LAB_005fb5c8;
        (*(code *)PTR_X509_ALGOR_set_md_006aa81c)(iVar2,uVar4);
      }
      iVar2 = (*(code *)PTR_EVP_MD_type_006a84cc)(local_34);
      if (iVar2 == 0x40) {
        pAVar5 = ASN1_item_pack(obj,(ASN1_ITEM *)PTR_RSA_PSS_PARAMS_it_006aa820,&local_30);
        if (pAVar5 == (ASN1_STRING *)0x0) goto LAB_005fb5c8;
        obj_00 = (void *)0x0;
LAB_005fb534:
        if (param_5 != 0) {
          iVar2 = (*(code *)PTR_ASN1_STRING_dup_006a9ddc)(local_30);
          if (iVar2 == 0) goto LAB_005fb5fc;
          uVar7 = (*(code *)PTR_OBJ_nid2obj_006a8240)(0x390);
          (*(code *)PTR_X509_ALGOR_set0_006a9e04)(param_5,uVar7,0x10,iVar2);
        }
        uVar3 = 3;
        uVar7 = (*(code *)PTR_OBJ_nid2obj_006a8240)(0x390);
        (*(code *)PTR_X509_ALGOR_set0_006a9e04)(param_4,uVar7,0x10,local_30);
        local_30 = (ASN1_OCTET_STRING *)0x0;
      }
      else {
        local_28 = (ASN1_OCTET_STRING *)0x0;
        obj_00 = (void *)(*(code *)PTR_X509_ALGOR_new_006a8fb8)();
        (*(code *)PTR_X509_ALGOR_set_md_006aa81c)(obj_00,local_34);
        pAVar5 = ASN1_item_pack(obj_00,(ASN1_ITEM *)PTR_X509_ALGOR_it_006aa508,&local_28);
        if (pAVar5 != (ASN1_STRING *)0x0) {
          iVar2 = (*(code *)PTR_X509_ALGOR_new_006a8fb8)();
          obj[1] = iVar2;
          if (iVar2 != 0) {
            uVar7 = (*(code *)PTR_OBJ_nid2obj_006a8240)(0x38f);
            (*(code *)PTR_X509_ALGOR_set0_006a9e04)(iVar2,uVar7,0x10,local_28);
            pAVar5 = ASN1_item_pack(obj,(ASN1_ITEM *)PTR_RSA_PSS_PARAMS_it_006aa820,&local_30);
            if (pAVar5 != (ASN1_STRING *)0x0) goto LAB_005fb534;
          }
        }
LAB_005fb5fc:
        uVar3 = 0;
      }
      if (obj_00 != (void *)0x0) {
        (*(code *)PTR_X509_ALGOR_free_006a8f94)(obj_00);
      }
    }
    else {
      iVar2 = (*(code *)PTR_ASN1_INTEGER_new_006a8260)();
      obj[2] = iVar2;
      if ((iVar2 != 0) &&
         (iVar2 = (*(code *)PTR_ASN1_INTEGER_set_006a8264)(iVar2,local_2c), iVar2 != 0))
      goto LAB_005fb430;
LAB_005fb5c8:
      uVar3 = 0;
    }
    (*(code *)PTR_RSA_PSS_PARAMS_free_006aa824)(obj);
  }
  if (local_30 != (ASN1_OCTET_STRING *)0x0) {
    (*(code *)PTR_ASN1_STRING_free_006a98bc)();
  }
LAB_005fb308:
  if (local_24 != *(int *)puVar1) {
    iVar2 = local_24;
    (*(code *)PTR___stack_chk_fail_006aabb8)();
                    /* WARNING: Could not recover jumptable at 0x005fb6b8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar7 = (*(code *)PTR_i2d_RSAPrivateKey_006a9ee0)(*(undefined4 *)(iVar2 + 0x14));
    return uVar7;
  }
  return uVar3;
}
