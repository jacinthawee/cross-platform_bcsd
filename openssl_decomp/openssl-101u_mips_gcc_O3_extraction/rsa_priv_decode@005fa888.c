
undefined4 * rsa_priv_decode(undefined4 param_1)

{
  undefined *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  char *pcVar11;
  int *piVar12;
  undefined4 uStack_70;
  int iStack_6c;
  undefined *puStack_68;
  undefined *puStack_64;
  undefined4 uStack_60;
  undefined4 uStack_2c;
  undefined auStack_1c [4];
  undefined4 local_18;
  int local_14;
  
  puStack_68 = PTR___stack_chk_guard_006a9ae8;
  pcVar11 = (char *)0x0;
  puStack_64 = auStack_1c;
  local_14 = *(int *)PTR___stack_chk_guard_006a9ae8;
  puVar2 = (undefined4 *)(*(code *)PTR_PKCS8_pkey_get0_006a87a0)(0,puStack_64,&local_18);
  if (puVar2 != (undefined4 *)0x0) {
    iVar9 = (*(code *)PTR_d2i_RSAPrivateKey_006a79e4)(0,puStack_64,local_18);
    if (iVar9 == 0) {
      pcVar11 = "rsa_ameth.c";
      (*(code *)PTR_ERR_put_error_006a7f34)(4,0x93,4);
      puVar2 = (undefined4 *)0x0;
    }
    else {
      (*(code *)PTR_EVP_PKEY_assign_006a83cc)(param_1,6,iVar9);
      puVar2 = (undefined4 *)0x1;
    }
  }
  if (local_14 == *(int *)puStack_68) {
    return puVar2;
  }
  iVar9 = local_14;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iStack_6c = *(int *)PTR___stack_chk_guard_006a9ae8;
  uStack_60 = param_1;
  iVar3 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*(undefined4 *)pcVar11);
  if (iVar3 != 0x390) {
    (*(code *)PTR_ERR_put_error_006a7f34)(4,0x9c,0x9b,"rsa_ameth.c",0x1be);
    puVar2 = (undefined4 *)0xffffffff;
    goto LAB_005faacc;
  }
  puVar2 = *(undefined4 **)((int)pcVar11 + 4);
  if ((puVar2 != (undefined4 *)0x0) && (pcVar11 = (char *)*puVar2, pcVar11 == &SUB_00000010)) {
    uStack_70 = ((undefined4 *)puVar2[1])[2];
    piVar4 = (int *)(*(code *)PTR_d2i_RSA_PSS_PARAMS_006a972c)
                              (0,&uStack_70,*(undefined4 *)puVar2[1]);
    if (piVar4 != (int *)0x0) {
      puVar2 = (undefined4 *)piVar4[1];
      if (puVar2 == (undefined4 *)0x0) {
        piVar12 = (int *)0x0;
LAB_005fad08:
        iVar3 = (*(code *)PTR_EVP_sha1_006a75d0)();
LAB_005fab84:
        if ((undefined4 *)*piVar4 == (undefined4 *)0x0) {
          iVar6 = (*(code *)PTR_EVP_sha1_006a75d0)();
LAB_005fabc4:
          if (piVar4[2] == 0) {
            iVar7 = 0x14;
          }
          else {
            iVar7 = (*(code *)PTR_ASN1_INTEGER_get_006a7208)();
            if (iVar7 < 0) {
              uVar10 = 0x96;
              uVar5 = 0x1eb;
              goto LAB_005faa8c;
            }
          }
          if ((piVar4[3] != 0) && (iVar8 = (*(code *)PTR_ASN1_INTEGER_get_006a7208)(), iVar8 != 1))
          {
            uVar10 = 0x8b;
            uVar5 = 0x1f6;
            goto LAB_005faa8c;
          }
          iVar9 = (*(code *)PTR_EVP_DigestVerifyInit_006a74f4)(iVar9,&uStack_70,iVar6,0,uStack_2c);
          if ((((iVar9 == 0) ||
               (iVar9 = (*(code *)PTR_EVP_PKEY_CTX_ctrl_006a6fec)(uStack_70,6,0xffffffff,0x1001,6,0)
               , iVar9 < 1)) ||
              (iVar9 = (*(code *)PTR_EVP_PKEY_CTX_ctrl_006a6fec)(uStack_70,6,0x18,0x1002,iVar7,0),
              iVar9 < 1)) ||
             (iVar9 = (*(code *)PTR_EVP_PKEY_CTX_ctrl_006a6fec)(uStack_70,6,0xf8,0x1005,0,iVar3),
             iVar9 < 1)) goto LAB_005faaa0;
          pcVar11 = &SUB_00000002;
        }
        else {
          uVar5 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*(undefined4 *)*piVar4);
          uVar5 = (*(code *)PTR_OBJ_nid2sn_006a709c)(uVar5);
          iVar6 = (*(code *)PTR_EVP_get_digestbyname_006a6f2c)(uVar5);
          if (iVar6 != 0) goto LAB_005fabc4;
          uVar10 = 0x98;
          uVar5 = 0x1dd;
LAB_005faa8c:
          (*(code *)PTR_ERR_put_error_006a7f34)(4,0x9c,uVar10,"rsa_ameth.c",uVar5);
LAB_005faaa0:
          pcVar11 = (char *)0xffffffff;
        }
        (*(code *)PTR_RSA_PSS_PARAMS_free_006a971c)(piVar4);
        puVar2 = (undefined4 *)pcVar11;
        if (piVar12 == (int *)0x0) goto LAB_005faacc;
      }
      else {
        piVar12 = (int *)puVar2[1];
        iVar3 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*puVar2);
        if (iVar3 == 0x38f) {
          if (piVar12 != (int *)0x0) {
            if (*piVar12 != 0x10) goto LAB_005faa54;
            uStack_70 = ((undefined4 *)piVar12[1])[2];
            piVar12 = (int *)(*(code *)PTR_d2i_X509_ALGOR_006a8dc4)
                                       (0,&uStack_70,*(undefined4 *)piVar12[1]);
          }
          puVar2 = (undefined4 *)piVar4[1];
        }
        else {
LAB_005faa54:
          puVar2 = (undefined4 *)piVar4[1];
          piVar12 = (int *)0x0;
        }
        if (puVar2 == (undefined4 *)0x0) goto LAB_005fad08;
        iVar3 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*puVar2);
        if (iVar3 != 0x38f) {
          uVar10 = 0x99;
          uVar5 = 0x1cb;
          goto LAB_005faa8c;
        }
        if (piVar12 == (int *)0x0) {
          (*(code *)PTR_ERR_put_error_006a7f34)(4,0x9c,0x9a,"rsa_ameth.c",0x1cf);
          (*(code *)PTR_RSA_PSS_PARAMS_free_006a971c)(piVar4);
          puVar2 = (undefined4 *)0xffffffff;
          goto LAB_005faacc;
        }
        uVar5 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*piVar12);
        uVar5 = (*(code *)PTR_OBJ_nid2sn_006a709c)(uVar5);
        iVar3 = (*(code *)PTR_EVP_get_digestbyname_006a6f2c)(uVar5);
        if (iVar3 != 0) goto LAB_005fab84;
        pcVar11 = (char *)0xffffffff;
        (*(code *)PTR_ERR_put_error_006a7f34)(4,0x9c,0x97,"rsa_ameth.c",0x1d4);
        (*(code *)PTR_RSA_PSS_PARAMS_free_006a971c)(piVar4);
      }
      (*(code *)PTR_X509_ALGOR_free_006a7ea4)(piVar12);
      puVar2 = (undefined4 *)pcVar11;
      goto LAB_005faacc;
    }
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(4,0x9c,0x95,"rsa_ameth.c",0x1c5);
  (*(code *)PTR_RSA_PSS_PARAMS_free_006a971c)(0);
  puVar2 = (undefined4 *)0xffffffff;
LAB_005faacc:
  while (iStack_6c != *(int *)puVar1) {
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
    puVar2 = (undefined4 *)pcVar11;
  }
  return puVar2;
}

