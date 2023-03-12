
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 * ibm_4758_load_pubkey(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  char *pcVar7;
  undefined4 uVar8;
  undefined *unaff_s1;
  undefined *unaff_s5;
  uint unaff_s6;
  undefined *unaff_s7;
  undefined4 uStack_1118;
  undefined4 uStack_1114;
  int iStack_1110;
  undefined auStack_110c [4];
  undefined4 uStack_1108;
  undefined4 uStack_1104;
  undefined auStack_1100 [8];
  undefined auStack_10f8 [8];
  undefined auStack_10f0 [64];
  undefined auStack_10b0 [256];
  undefined auStack_fb0 [256];
  char cStack_eb0;
  char cStack_eaf;
  char cStack_ea8;
  char cStack_ea7;
  ushort uStack_ea2;
  undefined2 uStack_e9e;
  undefined auStack_e9c [2480];
  int iStack_4ec;
  undefined4 *puStack_4e8;
  undefined *puStack_4e4;
  undefined *puStack_4e0;
  char *pcStack_4dc;
  undefined4 uStack_4d8;
  undefined *puStack_4d4;
  uint uStack_4d0;
  undefined *puStack_4cc;
  int local_48c;
  undefined auStack_488 [4];
  undefined4 local_484;
  undefined4 local_480;
  undefined auStack_47c [16];
  undefined auStack_46c [64];
  undefined auStack_42c [512];
  undefined auStack_22c [512];
  int local_2c;
  
  puStack_4e0 = PTR___stack_chk_guard_006a9ae8;
  local_484 = 0;
  local_480 = 0;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  pcStack_4dc = (char *)(*(code *)PTR_strlen_006a9a24)(param_2);
  if (pcStack_4dc < (char *)0x41) {
    unaff_s1 = auStack_46c;
    (*(code *)PTR_memset_006a99f4)(unaff_s1,0x20,0x40);
    (*(code *)PTR___memcpy_chk_006a9a48)(unaff_s1,param_2,pcStack_4dc,0x40);
    puStack_4e8 = (undefined4 *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x9c8,"e_4758cca.c",0x201);
    pcStack_4dc = "encrypt";
    if (puStack_4e8 == (undefined4 *)0x0) {
      puStack_4e8 = (undefined4 *)&_gp_1;
      if (CCA4758_lib_error_code == 0) {
        CCA4758_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
      }
      uVar6 = 0x68;
      (*(code *)PTR_ERR_put_error_006a7f34)(CCA4758_lib_error_code,0x68,0x41,"e_4758cca.c");
      puVar3 = (undefined4 *)0x0;
    }
    else {
      (*keyRecordRead)(&local_48c,auStack_488,&local_484,auStack_47c);
      if (local_48c == 0) {
        if ((((*(char *)(puStack_4e8 + 1) == '\x1e') && (*(char *)((int)puStack_4e8 + 5) == '\0'))
            && (*(char *)(puStack_4e8 + 3) == '\x04')) &&
           (unaff_s7 = auStack_22c, *(char *)((int)puStack_4e8 + 0xd) == '\0')) {
          pcStack_4dc = (char *)(uint)*(ushort *)((int)puStack_4e8 + 0x12);
          unaff_s6 = (uint)*(ushort *)((int)puStack_4e8 + 0x16);
          (*(code *)PTR___memcpy_chk_006a9a48)(unaff_s7,puStack_4e8 + 6,pcStack_4dc,0x200);
          unaff_s5 = auStack_42c;
          (*(code *)PTR___memcpy_chk_006a9a48)
                    (unaff_s5,(char *)((int)(puStack_4e8 + 6) + (int)pcStack_4dc),unaff_s6,0x200);
          puVar1 = PTR_RSA_new_method_006a772c;
          *puStack_4e8 = 0x9c4;
          unaff_s1 = (undefined *)(*(code *)puVar1)(param_1);
          (*(code *)PTR_RSA_set_ex_data_006a953c)(unaff_s1,hndidx,puStack_4e8);
          uVar6 = (*(code *)PTR_BN_bin2bn_006a7904)(unaff_s7,pcStack_4dc,0);
          puVar1 = PTR_BN_bin2bn_006a7904;
          *(undefined4 *)(unaff_s1 + 0x14) = uVar6;
          uVar6 = (*(code *)puVar1)(unaff_s5,unaff_s6,0);
          *(undefined4 *)(unaff_s1 + 0x10) = uVar6;
          puVar1 = PTR_EVP_PKEY_new_006a7620;
          *(uint *)(unaff_s1 + 0x3c) = *(uint *)(unaff_s1 + 0x3c) | 0x20;
          puVar3 = (undefined4 *)(*(code *)puVar1)();
          uVar6 = 6;
          (*(code *)PTR_EVP_PKEY_assign_006a83cc)(puVar3,6,unaff_s1);
          puStack_4e8 = puVar3;
          goto LAB_005cadb4;
        }
        if (CCA4758_lib_error_code == 0) {
          CCA4758_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
        }
        uVar6 = 0x68;
        (*(code *)PTR_ERR_put_error_006a7f34)(CCA4758_lib_error_code,0x68,0x69,"e_4758cca.c");
      }
      else {
        if (CCA4758_lib_error_code == 0) {
          CCA4758_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
        }
        uVar6 = 0x68;
        (*(code *)PTR_ERR_put_error_006a7f34)(CCA4758_lib_error_code,0x68,0x41,"e_4758cca.c");
      }
      unaff_s1 = &_gp_1;
      (*(code *)PTR_CRYPTO_free_006a6e88)(puStack_4e8);
      puVar3 = (undefined4 *)0x0;
    }
  }
  else {
    puStack_4e8 = (undefined4 *)&_gp_1;
    if (CCA4758_lib_error_code == 0) {
      CCA4758_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    uVar6 = 0x68;
    (*(code *)PTR_ERR_put_error_006a7f34)(CCA4758_lib_error_code,0x68,0x6b,"e_4758cca.c");
    puVar3 = (undefined4 *)0x0;
  }
LAB_005cadb4:
  if (local_2c == *(int *)puStack_4e0) {
    return puVar3;
  }
  iVar5 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  uStack_1118 = 0x9c4;
  uStack_1114 = 0x9c4;
  uStack_1108 = 0;
  uStack_1104 = 0;
  iStack_4ec = *(int *)PTR___stack_chk_guard_006a9ae8;
  puStack_4e4 = unaff_s1;
  uStack_4d8 = param_1;
  puStack_4d4 = unaff_s5;
  uStack_4d0 = unaff_s6;
  puStack_4cc = unaff_s7;
  uVar4 = (*(code *)PTR_strlen_006a9a24)(uVar6);
  if (uVar4 < 0x41) {
    (*(code *)PTR_memset_006a99f4)(auStack_10f0,0x20,0x40);
    (*(code *)PTR___memcpy_chk_006a9a48)(auStack_10f0,uVar6,uVar4,0x40);
    puVar3 = (undefined4 *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x9c8,"e_4758cca.c",0x1ad);
    if (puVar3 == (undefined4 *)0x0) {
      if (CCA4758_lib_error_code == 0) {
        CCA4758_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
      }
      (*(code *)PTR_ERR_put_error_006a7f34)(CCA4758_lib_error_code,0x67,0x41,"e_4758cca.c",0x1af);
      puVar3 = (undefined4 *)0x0;
    }
    else {
      (*keyRecordRead)(&iStack_1110,auStack_110c,&uStack_1108,auStack_1100,&uStack_1104,auStack_10f8
                       ,auStack_10f0,&uStack_1114,puVar3 + 1);
      if (iStack_1110 == 0) {
        (*publicKeyExtract)(&iStack_1110,auStack_110c,&uStack_1108,auStack_1100,&uStack_1104,
                            auStack_10f8,&uStack_1114,puVar3 + 1,&uStack_1118,&cStack_eb0);
        if (iStack_1110 == 0) {
          if (((cStack_eb0 == '\x1e') && (cStack_eaf == '\0')) &&
             ((cStack_ea8 == '\x04' && (uVar4 = (uint)uStack_ea2, cStack_ea7 == '\0')))) {
            (*(code *)PTR___memcpy_chk_006a9a48)(auStack_fb0,auStack_e9c,uVar4,0x100);
            (*(code *)PTR___memcpy_chk_006a9a48)(auStack_10b0,auStack_e9c + uVar4,uStack_e9e,0x100);
            puVar2 = PTR_RSA_new_method_006a772c;
            *puVar3 = uStack_1114;
            iVar5 = (*(code *)puVar2)(iVar5);
            (*(code *)PTR_RSA_set_ex_data_006a953c)(iVar5,hndidx,puVar3);
            uVar6 = (*(code *)PTR_BN_bin2bn_006a7904)(auStack_fb0,uVar4,0);
            puVar2 = PTR_BN_bin2bn_006a7904;
            *(undefined4 *)(iVar5 + 0x14) = uVar6;
            uVar6 = (*(code *)puVar2)(auStack_10b0,uStack_e9e,0);
            *(undefined4 *)(iVar5 + 0x10) = uVar6;
            puVar2 = PTR_EVP_PKEY_new_006a7620;
            *(uint *)(iVar5 + 0x3c) = *(uint *)(iVar5 + 0x3c) | 0x20;
            puVar3 = (undefined4 *)(*(code *)puVar2)();
            (*(code *)PTR_EVP_PKEY_assign_006a83cc)(puVar3,6,iVar5);
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
      (*(code *)PTR_CRYPTO_free_006a6e88)(puVar3);
      puVar3 = (undefined4 *)0x0;
    }
  }
  else {
    if (CCA4758_lib_error_code == 0) {
      CCA4758_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    (*(code *)PTR_ERR_put_error_006a7f34)(CCA4758_lib_error_code,0x67,0x6b,"e_4758cca.c",0x1a6);
    puVar3 = (undefined4 *)0x0;
  }
LAB_005cb1c4:
  if (iStack_4ec == *(int *)puVar1) {
    return puVar3;
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
      if ((((keyRecordRead != (code *)0x0) &&
           (randomNumberGenerate = (*(code *)PTR_DSO_bind_func_006a888c)(dso,"CSNBRNG"),
           randomNumberGenerate != 0)) &&
          ((digitalSignatureGenerate = (*(code *)PTR_DSO_bind_func_006a888c)(dso,"CSNDDSG"),
           digitalSignatureGenerate != 0 &&
           (((digitalSignatureVerify = (*(code *)PTR_DSO_bind_func_006a888c)(dso,"CSNDDSV"),
             digitalSignatureVerify != 0 &&
             (publicKeyExtract = (code *)(*(code *)PTR_DSO_bind_func_006a888c)(dso,"CSNDPKX"),
             publicKeyExtract != (code *)0x0)) &&
            (pkaEncrypt = (*(code *)PTR_DSO_bind_func_006a888c)(dso,"CSNDPKE"), pkaEncrypt != 0)))))
          ) && (pkaDecrypt = (*(code *)PTR_DSO_bind_func_006a888c)(dso,"CSNDPKD"), pkaDecrypt != 0))
      {
        hndidx = (*(code *)PTR_RSA_get_ex_new_index_006a9540)
                           (0,"IBM 4758 CCA RSA key handle",0,0,cca_ex_free);
        return (undefined4 *)0x1;
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
    uVar6 = 0x122;
  }
  else {
    if (CCA4758_lib_error_code == 0) {
      CCA4758_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    uVar8 = 100;
    uVar6 = 0x11c;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(CCA4758_lib_error_code,0x66,uVar8,"e_4758cca.c",uVar6);
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
  return (undefined4 *)0x0;
}

