
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 ibm_4758_load_privkey(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  char *pcVar7;
  undefined4 uVar8;
  undefined4 local_c58;
  undefined4 local_c54;
  int local_c50;
  undefined auStack_c4c [4];
  undefined4 local_c48;
  undefined4 local_c44;
  undefined auStack_c40 [8];
  undefined auStack_c38 [8];
  undefined auStack_c30 [64];
  undefined auStack_bf0 [256];
  undefined auStack_af0 [256];
  char local_9f0;
  char local_9ef;
  char local_9e8;
  char local_9e7;
  ushort local_9e2;
  undefined2 local_9de;
  undefined auStack_9dc [2480];
  int local_2c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_c58 = 0x9c4;
  local_c54 = 0x9c4;
  local_c48 = 0;
  local_c44 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  uVar3 = (*(code *)PTR_strlen_006a9a24)(param_2);
  if (uVar3 < 0x41) {
    (*(code *)PTR_memset_006a99f4)(auStack_c30,0x20,0x40);
    (*(code *)PTR___memcpy_chk_006a9a48)(auStack_c30,param_2,uVar3,0x40);
    puVar4 = (undefined4 *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x9c8,"e_4758cca.c",0x1ad);
    if (puVar4 == (undefined4 *)0x0) {
      if (CCA4758_lib_error_code == 0) {
        CCA4758_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
      }
      (*(code *)PTR_ERR_put_error_006a7f34)(CCA4758_lib_error_code,0x67,0x41,"e_4758cca.c",0x1af);
      uVar5 = 0;
    }
    else {
      (*keyRecordRead)(&local_c50,auStack_c4c,&local_c48,auStack_c40,&local_c44,auStack_c38,
                       auStack_c30,&local_c54,puVar4 + 1);
      if (local_c50 == 0) {
        (*publicKeyExtract)(&local_c50,auStack_c4c,&local_c48,auStack_c40,&local_c44,auStack_c38,
                            &local_c54,puVar4 + 1,&local_c58,&local_9f0);
        if (local_c50 == 0) {
          if ((((local_9f0 == '\x1e') && (local_9ef == '\0')) && (local_9e8 == '\x04')) &&
             (uVar3 = (uint)local_9e2, local_9e7 == '\0')) {
            (*(code *)PTR___memcpy_chk_006a9a48)(auStack_af0,auStack_9dc,uVar3,0x100);
            (*(code *)PTR___memcpy_chk_006a9a48)(auStack_bf0,auStack_9dc + uVar3,local_9de,0x100);
            puVar1 = PTR_RSA_new_method_006a772c;
            *puVar4 = local_c54;
            iVar6 = (*(code *)puVar1)(param_1);
            (*(code *)PTR_RSA_set_ex_data_006a953c)(iVar6,hndidx,puVar4);
            uVar5 = (*(code *)PTR_BN_bin2bn_006a7904)(auStack_af0,uVar3,0);
            puVar1 = PTR_BN_bin2bn_006a7904;
            *(undefined4 *)(iVar6 + 0x14) = uVar5;
            uVar5 = (*(code *)puVar1)(auStack_bf0,local_9de,0);
            *(undefined4 *)(iVar6 + 0x10) = uVar5;
            puVar1 = PTR_EVP_PKEY_new_006a7620;
            *(uint *)(iVar6 + 0x3c) = *(uint *)(iVar6 + 0x3c) | 0x20;
            uVar5 = (*(code *)puVar1)();
            (*(code *)PTR_EVP_PKEY_assign_006a83cc)(uVar5,6,iVar6);
            goto LAB_005cb1c4;
          }
          if (CCA4758_lib_error_code == 0) {
            CCA4758_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
          }
          (*(code *)PTR_ERR_put_error_006a7f34)
                    (CCA4758_lib_error_code,0x67,0x68,"e_4758cca.c",0x1cc);
        }
        else {
          if (CCA4758_lib_error_code == 0) {
            CCA4758_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
          }
          (*(code *)PTR_ERR_put_error_006a7f34)
                    (CCA4758_lib_error_code,0x67,0x68,"e_4758cca.c",0x1c4);
        }
      }
      else {
        if (CCA4758_lib_error_code == 0) {
          CCA4758_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
        }
        (*(code *)PTR_ERR_put_error_006a7f34)(CCA4758_lib_error_code,0x67,0x68,"e_4758cca.c",0x1b9);
      }
      (*(code *)PTR_CRYPTO_free_006a6e88)(puVar4);
      uVar5 = 0;
    }
  }
  else {
    if (CCA4758_lib_error_code == 0) {
      CCA4758_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(CCA4758_lib_error_code,0x67,0x6b,"e_4758cca.c",0x1a6);
    uVar5 = 0;
  }
LAB_005cb1c4:
  if (local_2c == *(int *)puVar2) {
    return uVar5;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (dso == 0) {
    pcVar7 = CCA4758_LIB_NAME;
    if (CCA4758_LIB_NAME == (char *)0x0) {
      pcVar7 = "CSUNSAPI";
    }
    dso = (*(code *)PTR_DSO_load_006a8884)(0,pcVar7,0,0);
    if (dso != 0) {
      keyRecordRead = (code *)(*(code *)PTR_DSO_bind_func_006a888c)(dso,"CSNDKRR");
      if (((((keyRecordRead != (code *)0x0) &&
            (randomNumberGenerate = (*(code *)PTR_DSO_bind_func_006a888c)(dso,"CSNBRNG"),
            randomNumberGenerate != 0)) &&
           ((digitalSignatureGenerate = (*(code *)PTR_DSO_bind_func_006a888c)(dso,"CSNDDSG"),
            digitalSignatureGenerate != 0 &&
            ((digitalSignatureVerify = (*(code *)PTR_DSO_bind_func_006a888c)(dso,"CSNDDSV"),
             digitalSignatureVerify != 0 &&
             (publicKeyExtract = (code *)(*(code *)PTR_DSO_bind_func_006a888c)(dso,"CSNDPKX"),
             publicKeyExtract != (code *)0x0)))))) &&
          (pkaEncrypt = (*(code *)PTR_DSO_bind_func_006a888c)(dso,"CSNDPKE"), pkaEncrypt != 0)) &&
         (pkaDecrypt = (*(code *)PTR_DSO_bind_func_006a888c)(dso,"CSNDPKD"), pkaDecrypt != 0)) {
        hndidx = (*(code *)PTR_RSA_get_ex_new_index_006a9540)
                           (0,"IBM 4758 CCA RSA key handle",0,0,cca_ex_free);
        return 1;
      }
      if (CCA4758_lib_error_code == 0) {
        CCA4758_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
      }
      (*(code *)PTR_ERR_put_error_006a7f34)(CCA4758_lib_error_code,0x66,0x67,"e_4758cca.c",0x135);
      goto LAB_005cb544;
    }
    if (CCA4758_lib_error_code == 0) {
      CCA4758_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    uVar8 = 0x67;
    uVar5 = 0x122;
  }
  else {
    if (CCA4758_lib_error_code == 0) {
      CCA4758_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    uVar8 = 100;
    uVar5 = 0x11c;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(CCA4758_lib_error_code,0x66,uVar8,"e_4758cca.c",uVar5);
LAB_005cb544:
  if (dso != 0) {
    (*(code *)PTR_DSO_free_006a8874)();
  }
  keyRecordRead = (code *)0x0;
  digitalSignatureGenerate = 0;
  digitalSignatureVerify = 0;
  publicKeyExtract = (code *)0x0;
  pkaEncrypt = 0;
  pkaDecrypt = 0;
  randomNumberGenerate = 0;
  dso = 0;
  return 0;
}
