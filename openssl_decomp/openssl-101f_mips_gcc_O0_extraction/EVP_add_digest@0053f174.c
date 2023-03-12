
int EVP_add_digest(EVP_MD *digest)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  (*(code *)PTR_OPENSSL_init_006a9598)();
  uVar1 = (*(code *)PTR_OBJ_nid2sn_006a819c)(digest->type);
  iVar2 = (*(code *)PTR_OBJ_NAME_add_006a9540)(uVar1,1,digest);
  if (iVar2 != 0) {
    (*(code *)PTR_check_defer_006a9b7c)(digest->type);
    uVar3 = (*(code *)PTR_OBJ_nid2ln_006a821c)(digest->type);
    iVar2 = (*(code *)PTR_OBJ_NAME_add_006a9540)(uVar3,1,digest);
    if (iVar2 != 0) {
      if (digest->pkey_type == 0) {
        return iVar2;
      }
      if (digest->pkey_type == digest->type) {
        return iVar2;
      }
      uVar3 = (*(code *)PTR_OBJ_nid2sn_006a819c)();
      iVar2 = (*(code *)PTR_OBJ_NAME_add_006a9540)(uVar3,0x8001,uVar1);
      if (iVar2 != 0) {
        (*(code *)PTR_check_defer_006a9b7c)(digest->pkey_type);
        uVar3 = (*(code *)PTR_OBJ_nid2ln_006a821c)(digest->pkey_type);
                    /* WARNING: Could not recover jumptable at 0x0053f2a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        iVar2 = (*(code *)PTR_OBJ_NAME_add_006a9540)(uVar3,0x8001,uVar1);
        return iVar2;
      }
    }
  }
  return 0;
}

