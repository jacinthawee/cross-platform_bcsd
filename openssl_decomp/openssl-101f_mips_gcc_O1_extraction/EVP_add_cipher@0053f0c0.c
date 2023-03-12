
int EVP_add_cipher(EVP_CIPHER *cipher)

{
  undefined4 uVar1;
  int iVar2;
  
  if (cipher == (EVP_CIPHER *)0x0) {
    return 0;
  }
  (*(code *)PTR_OPENSSL_init_006a9598)();
  uVar1 = (*(code *)PTR_OBJ_nid2sn_006a819c)(cipher->nid);
  iVar2 = (*(code *)PTR_OBJ_NAME_add_006a9540)(uVar1,2,cipher);
  if (iVar2 == 0) {
    return 0;
  }
  (*(code *)PTR_check_defer_006a9b7c)(cipher->nid);
  uVar1 = (*(code *)PTR_OBJ_nid2ln_006a821c)(cipher->nid);
                    /* WARNING: Could not recover jumptable at 0x0053f164. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar2 = (*(code *)PTR_OBJ_NAME_add_006a9540)(uVar1,2,cipher);
  return iVar2;
}

