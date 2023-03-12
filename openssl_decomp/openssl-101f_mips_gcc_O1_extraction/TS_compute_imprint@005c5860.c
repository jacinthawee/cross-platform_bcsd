
undefined4
TS_compute_imprint(undefined4 param_1,undefined *param_2,int *param_3,int *param_4,int *param_5)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined *puVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  int *piVar9;
  int *piVar10;
  char *pcVar11;
  undefined auStack_103c [24];
  undefined auStack_1024 [4096];
  undefined4 *local_24;
  
  puVar2 = PTR___stack_chk_guard_006aabf0;
  local_24 = *(undefined4 **)PTR___stack_chk_guard_006aabf0;
  piVar10 = param_3;
  pcVar11 = (char *)param_4;
  uVar3 = TS_TST_INFO_get_msg_imprint(param_2);
  uVar3 = TS_MSG_IMPRINT_get_algo(uVar3);
  *param_3 = 0;
  puVar5 = PTR_X509_ALGOR_dup_006aa514;
  *param_4 = 0;
  puVar4 = (undefined4 *)(*(code *)puVar5)(uVar3);
  *param_3 = (int)puVar4;
  if (puVar4 != (undefined4 *)0x0) {
    uVar3 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*puVar4);
    uVar3 = (*(code *)PTR_OBJ_nid2sn_006a819c)(uVar3);
    puVar5 = (undefined *)(*(code *)PTR_EVP_get_digestbyname_006a802c)(uVar3);
    if (puVar5 == (undefined *)0x0) {
      piVar10 = (int *)0x7e;
      pcVar11 = "ts_rsp_verify.c";
      param_2 = (undefined *)0x91;
      (*(code *)PTR_ERR_put_error_006a9030)(0x2f,0x91,0x7e,"ts_rsp_verify.c",0x25a);
      puVar4 = (undefined4 *)*param_3;
    }
    else {
      iVar6 = (*(code *)PTR_EVP_MD_size_006a8f2c)(puVar5);
      puVar1 = PTR_CRYPTO_malloc_006a8108;
      if (-1 < iVar6) {
        piVar10 = (int *)0x263;
        *param_5 = iVar6;
        iVar6 = (*(code *)puVar1)(iVar6,"ts_rsp_verify.c");
        *param_4 = iVar6;
        if (iVar6 == 0) {
          pcVar11 = "ts_rsp_verify.c";
          piVar10 = (int *)&DAT_00000041;
          param_2 = (undefined *)0x91;
          (*(code *)PTR_ERR_put_error_006a9030)(0x2f,0x91,0x41,"ts_rsp_verify.c",0x265);
          puVar4 = (undefined4 *)*param_3;
          goto LAB_005c5984;
        }
        iVar6 = (*(code *)PTR_EVP_DigestInit_006a8f30)(auStack_103c,puVar5);
        param_2 = puVar5;
        if (iVar6 != 0) {
          do {
            piVar10 = (int *)(*(code *)PTR_BIO_read_006a85bc)(param_1,auStack_1024,0x1000);
            if ((int)piVar10 < 1) {
              piVar10 = (int *)0x0;
              param_2 = (undefined *)*param_4;
              iVar6 = (*(code *)PTR_EVP_DigestFinal_006a8f34)(auStack_103c,param_2);
              if (iVar6 != 0) {
                uVar3 = 1;
                goto LAB_005c59ac;
              }
              break;
            }
            param_2 = auStack_1024;
            iVar6 = (*(code *)PTR_EVP_DigestUpdate_006a8674)(auStack_103c,auStack_1024);
          } while (iVar6 != 0);
        }
      }
      puVar4 = (undefined4 *)*param_3;
    }
  }
LAB_005c5984:
  (*(code *)PTR_X509_ALGOR_free_006a8f94)(puVar4);
  (*(code *)PTR_CRYPTO_free_006a7f88)(*param_4);
  uVar3 = 0;
  *param_5 = 0;
LAB_005c59ac:
  if (local_24 == *(undefined4 **)puVar2) {
    return uVar3;
  }
  puVar4 = local_24;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  iVar6 = TS_TST_INFO_get_msg_imprint(pcVar11);
  puVar7 = (undefined4 *)TS_MSG_IMPRINT_get_algo(iVar6);
  if (((puVar4 == (undefined4 *)0x0) ||
      (((iVar8 = (*(code *)PTR_OBJ_cmp_006a9de4)(*puVar4,*puVar7), iVar8 == 0 &&
        ((puVar4[1] == 0 || (iVar8 = (*(code *)PTR_ASN1_TYPE_get_006a85b0)(), iVar8 == 5)))) &&
       ((puVar7[1] == 0 || (iVar8 = (*(code *)PTR_ASN1_TYPE_get_006a85b0)(), iVar8 == 5)))))) &&
     (piVar9 = (int *)(*(code *)PTR_ASN1_STRING_length_006a842c)(*(undefined4 *)(iVar6 + 4)),
     piVar9 == piVar10)) {
    uVar3 = (*(code *)PTR_ASN1_STRING_data_006a8430)(*(undefined4 *)(iVar6 + 4));
    iVar6 = (*(code *)PTR_memcmp_006aabd8)(param_2,uVar3,piVar10);
    if (iVar6 == 0) {
      return 1;
    }
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x2f,100,0x67,"ts_rsp_verify.c",0x296);
  return 0;
}

