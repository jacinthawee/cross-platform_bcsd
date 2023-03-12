
undefined4 pkcs7_decrypt_rinfo(int *param_1,int *param_2,int *param_3,char *param_4)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  int iVar7;
  int *piVar8;
  undefined4 uVar9;
  int local_30;
  int *local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iVar7 = 0;
  local_2c = *(int **)PTR___stack_chk_guard_006aabf0;
  piVar8 = param_3;
  iVar2 = (*(code *)PTR_EVP_PKEY_CTX_new_006a80e0)(param_4);
  if (iVar2 == 0) {
    uVar9 = 0xffffffff;
    goto LAB_005a417c;
  }
  iVar3 = (*(code *)PTR_EVP_PKEY_decrypt_init_006a8dd4)(iVar2);
  piVar6 = piVar8;
  if (iVar3 < 1) {
LAB_005a4164:
    piVar8 = piVar6;
    uVar9 = 0xffffffff;
  }
  else {
    iVar7 = (*(code *)PTR_EVP_PKEY_CTX_ctrl_006a80ec)(iVar2,0xffffffff,0x200,4,0,param_3);
    if (iVar7 < 1) {
      piVar8 = (int *)&DAT_00000098;
      param_4 = "pk7_doit.c";
      iVar7 = 0x85;
      uVar9 = 0xffffffff;
      (*(code *)PTR_ERR_put_error_006a9030)(0x21,0x85,0x98,"pk7_doit.c",0xdb);
    }
    else {
      piVar8 = &local_30;
      iVar7 = 0;
      param_4 = (char *)((undefined4 *)param_3[3])[2];
      piVar6 = piVar8;
      iVar3 = (*(code *)PTR_EVP_PKEY_decrypt_006a8dfc)
                        (iVar2,0,piVar8,param_4,*(undefined4 *)param_3[3]);
      if (iVar3 < 1) goto LAB_005a4164;
      iVar3 = (*(code *)PTR_CRYPTO_malloc_006a8108)(local_30,"pk7_doit.c",0xe3);
      if (iVar3 == 0) {
        param_4 = "pk7_doit.c";
        piVar8 = (int *)&DAT_00000041;
        iVar7 = 0x85;
        uVar9 = 0xffffffff;
        (*(code *)PTR_ERR_put_error_006a9030)(0x21,0x85,0x41,"pk7_doit.c",0xe7);
      }
      else {
        param_4 = (char *)((undefined4 *)param_3[3])[2];
        iVar7 = iVar3;
        iVar4 = (*(code *)PTR_EVP_PKEY_decrypt_006a8dfc)
                          (iVar2,iVar3,piVar8,param_4,*(undefined4 *)param_3[3]);
        if (iVar4 < 1) {
          param_4 = "pk7_doit.c";
          piVar8 = (int *)&DAT_00000006;
          iVar7 = 0x85;
          (*(code *)PTR_ERR_put_error_006a9030)(0x21,0x85,6,"pk7_doit.c",0xef);
          (*(code *)PTR_EVP_PKEY_CTX_free_006a7f7c)(iVar2);
          (*(code *)PTR_CRYPTO_free_006a7f88)(iVar3);
          uVar9 = 0;
          goto LAB_005a417c;
        }
        if (*param_1 != 0) {
          iVar7 = *param_2;
          (*(code *)PTR_OPENSSL_cleanse_006a8174)();
          (*(code *)PTR_CRYPTO_free_006a7f88)(*param_1);
        }
        uVar9 = 1;
        *param_1 = iVar3;
        *param_2 = local_30;
      }
    }
  }
  (*(code *)PTR_EVP_PKEY_CTX_free_006a7f7c)(iVar2);
LAB_005a417c:
  if (local_2c == *(int **)puVar1) {
    return uVar9;
  }
  piVar6 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar2 = *piVar6;
  if (iVar2 == 0) {
    iVar2 = (*(code *)PTR_sk_new_null_006a80a4)();
    *piVar6 = iVar2;
    if (iVar2 == 0) {
      return 0;
    }
  }
  else {
    for (iVar3 = 0; iVar2 = (*(code *)PTR_sk_num_006a7f2c)(iVar2), iVar3 < iVar2; iVar3 = iVar3 + 1)
    {
      puVar5 = (undefined4 *)(*(code *)PTR_sk_value_006a7f24)(*piVar6,iVar3);
      iVar2 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*puVar5);
      if (iVar2 == iVar7) {
        (*(code *)PTR_X509_ATTRIBUTE_free_006a9c00)(puVar5);
        iVar7 = (*(code *)PTR_X509_ATTRIBUTE_create_006aa258)(iVar7,piVar8,param_4);
        if (iVar7 == 0) {
          return 0;
        }
        iVar2 = (*(code *)PTR_sk_set_006a9478)(*piVar6,iVar3,iVar7);
        if (iVar2 != 0) {
          return 1;
        }
        (*(code *)PTR_X509_ATTRIBUTE_free_006a9c00)(iVar7);
        return 0;
      }
      iVar2 = *piVar6;
    }
  }
  iVar7 = (*(code *)PTR_X509_ATTRIBUTE_create_006aa258)(iVar7,piVar8,param_4);
  if (iVar7 == 0) {
    return 0;
  }
  iVar2 = (*(code *)PTR_sk_push_006a80a8)(*piVar6,iVar7);
  if (iVar2 != 0) {
    return 1;
  }
  (*(code *)PTR_X509_ATTRIBUTE_free_006a9c00)(iVar7);
  return 0;
}

