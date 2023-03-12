
undefined4 *
rsa_item_verify(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
               undefined4 param_5,undefined4 param_6)

{
  undefined *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  int *piVar10;
  undefined4 *puVar11;
  undefined4 local_30;
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar2 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*param_4);
  if (iVar2 != 0x390) {
    (*(code *)PTR_ERR_put_error_006a9030)(4,0x9c,0x9b,"rsa_ameth.c",0x1d9);
    puVar3 = (undefined4 *)0xffffffff;
    goto LAB_005fc994;
  }
  puVar3 = (undefined4 *)param_4[1];
  if ((puVar3 != (undefined4 *)0x0) &&
     (param_4 = (undefined4 *)*puVar3, param_4 == (undefined4 *)&SUB_00000010)) {
    local_30 = ((undefined4 *)puVar3[1])[2];
    piVar4 = (int *)(*(code *)PTR_d2i_RSA_PSS_PARAMS_006aa834)(0,&local_30,*(undefined4 *)puVar3[1])
    ;
    if (piVar4 != (int *)0x0) {
      puVar3 = (undefined4 *)piVar4[1];
      if (puVar3 == (undefined4 *)0x0) {
        puVar11 = (undefined4 *)0x0;
LAB_005fcbc8:
        iVar2 = (*(code *)PTR_EVP_sha1_006a86c4)();
LAB_005fca4c:
        if ((undefined4 *)*piVar4 == (undefined4 *)0x0) {
          iVar6 = (*(code *)PTR_EVP_sha1_006a86c4)();
LAB_005fca8c:
          if (piVar4[2] == 0) {
            iVar7 = 0x14;
          }
          else {
            iVar7 = (*(code *)PTR_ASN1_INTEGER_get_006a831c)();
            if (iVar7 < 0) {
              uVar9 = 0x96;
              uVar5 = 0x210;
              goto LAB_005fc954;
            }
          }
          if ((piVar4[3] != 0) && (iVar8 = (*(code *)PTR_ASN1_INTEGER_get_006a831c)(), iVar8 != 1))
          {
            uVar9 = 0x8b;
            uVar5 = 0x21c;
            goto LAB_005fc954;
          }
          iVar6 = (*(code *)PTR_EVP_DigestVerifyInit_006a85f0)(param_1,&local_30,iVar6,0,param_6);
          if ((((iVar6 == 0) ||
               (iVar6 = (*(code *)PTR_EVP_PKEY_CTX_ctrl_006a80ec)(local_30,6,0xffffffff,0x1001,6,0),
               iVar6 < 1)) ||
              (iVar6 = (*(code *)PTR_EVP_PKEY_CTX_ctrl_006a80ec)(local_30,6,0x18,0x1002,iVar7,0),
              iVar6 < 1)) ||
             (iVar2 = (*(code *)PTR_EVP_PKEY_CTX_ctrl_006a80ec)(local_30,6,0xf8,0x1005,0,iVar2),
             iVar2 < 1)) goto LAB_005fc968;
          param_4 = (undefined4 *)&SUB_00000002;
        }
        else {
          uVar5 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*(undefined4 *)*piVar4);
          uVar5 = (*(code *)PTR_OBJ_nid2sn_006a819c)(uVar5);
          iVar6 = (*(code *)PTR_EVP_get_digestbyname_006a802c)(uVar5);
          if (iVar6 != 0) goto LAB_005fca8c;
          uVar9 = 0x98;
          uVar5 = 0x200;
LAB_005fc954:
          (*(code *)PTR_ERR_put_error_006a9030)(4,0x9c,uVar9,"rsa_ameth.c",uVar5);
LAB_005fc968:
          param_4 = (undefined4 *)0xffffffff;
        }
        (*(code *)PTR_RSA_PSS_PARAMS_free_006aa824)(piVar4);
        puVar3 = param_4;
        if (puVar11 == (undefined4 *)0x0) goto LAB_005fc994;
      }
      else {
        piVar10 = (int *)puVar3[1];
        iVar2 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*puVar3);
        if ((iVar2 == 0x38f) && (*piVar10 == 0x10)) {
          puVar3 = (undefined4 *)piVar10[1];
          local_30 = puVar3[2];
          puVar11 = (undefined4 *)(*(code *)PTR_d2i_X509_ALGOR_006a9ee4)(0,&local_30,*puVar3);
          puVar3 = (undefined4 *)piVar4[1];
        }
        else {
          puVar3 = (undefined4 *)piVar4[1];
          puVar11 = (undefined4 *)0x0;
        }
        if (puVar3 == (undefined4 *)0x0) goto LAB_005fcbc8;
        iVar2 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*puVar3);
        if (iVar2 != 0x38f) {
          uVar9 = 0x99;
          uVar5 = 0x1e9;
          goto LAB_005fc954;
        }
        if (puVar11 == (undefined4 *)0x0) {
          (*(code *)PTR_ERR_put_error_006a9030)(4,0x9c,0x9a,"rsa_ameth.c",0x1ee);
          (*(code *)PTR_RSA_PSS_PARAMS_free_006aa824)(piVar4);
          puVar3 = (undefined4 *)0xffffffff;
          goto LAB_005fc994;
        }
        uVar5 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*puVar11);
        uVar5 = (*(code *)PTR_OBJ_nid2sn_006a819c)(uVar5);
        iVar2 = (*(code *)PTR_EVP_get_digestbyname_006a802c)(uVar5);
        if (iVar2 != 0) goto LAB_005fca4c;
        param_4 = (undefined4 *)0xffffffff;
        (*(code *)PTR_ERR_put_error_006a9030)(4,0x9c,0x97,"rsa_ameth.c",500);
        (*(code *)PTR_RSA_PSS_PARAMS_free_006aa824)(piVar4);
      }
      (*(code *)PTR_X509_ALGOR_free_006a8f94)(puVar11);
      puVar3 = param_4;
      goto LAB_005fc994;
    }
  }
  (*(code *)PTR_ERR_put_error_006a9030)(4,0x9c,0x95,"rsa_ameth.c",0x1e1);
  (*(code *)PTR_RSA_PSS_PARAMS_free_006aa824)(0);
  puVar3 = (undefined4 *)0xffffffff;
LAB_005fc994:
  while (local_2c != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006aabb8)();
    puVar3 = param_4;
  }
  return puVar3;
}

