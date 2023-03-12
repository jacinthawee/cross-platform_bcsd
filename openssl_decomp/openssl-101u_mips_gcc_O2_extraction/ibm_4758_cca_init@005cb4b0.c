
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 ibm_4758_cca_init(void)

{
  undefined4 uVar1;
  char *pcVar2;
  undefined4 uVar3;
  
  if (dso == 0) {
    pcVar2 = CCA4758_LIB_NAME;
    if (CCA4758_LIB_NAME == (char *)0x0) {
      pcVar2 = "CSUNSAPI";
    }
    dso = (*(code *)PTR_DSO_load_006a8884)(0,pcVar2,0,0);
    if (dso != 0) {
      keyRecordRead = (*(code *)PTR_DSO_bind_func_006a888c)(dso,"CSNDKRR");
      if ((((keyRecordRead != 0) &&
           (randomNumberGenerate = (*(code *)PTR_DSO_bind_func_006a888c)(dso,"CSNBRNG"),
           randomNumberGenerate != 0)) &&
          (digitalSignatureGenerate = (*(code *)PTR_DSO_bind_func_006a888c)(dso,"CSNDDSG"),
          digitalSignatureGenerate != 0)) &&
         (((digitalSignatureVerify = (*(code *)PTR_DSO_bind_func_006a888c)(dso,"CSNDDSV"),
           digitalSignatureVerify != 0 &&
           (publicKeyExtract = (*(code *)PTR_DSO_bind_func_006a888c)(dso,"CSNDPKX"),
           publicKeyExtract != 0)) &&
          ((pkaEncrypt = (*(code *)PTR_DSO_bind_func_006a888c)(dso,"CSNDPKE"), pkaEncrypt != 0 &&
           (pkaDecrypt = (*(code *)PTR_DSO_bind_func_006a888c)(dso,"CSNDPKD"), pkaDecrypt != 0))))))
      {
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
    uVar3 = 0x67;
    uVar1 = 0x122;
  }
  else {
    if (CCA4758_lib_error_code == 0) {
      CCA4758_lib_error_code = (*(code *)PTR_ERR_get_next_error_library_006a9538)();
    }
    uVar3 = 100;
    uVar1 = 0x11c;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(CCA4758_lib_error_code,0x66,uVar3,"e_4758cca.c",uVar1);
LAB_005cb544:
  if (dso != 0) {
    (*(code *)PTR_DSO_free_006a8874)();
  }
  keyRecordRead = 0;
  digitalSignatureGenerate = 0;
  digitalSignatureVerify = 0;
  publicKeyExtract = 0;
  pkaEncrypt = 0;
  pkaDecrypt = 0;
  randomNumberGenerate = 0;
  dso = 0;
  return 0;
}

