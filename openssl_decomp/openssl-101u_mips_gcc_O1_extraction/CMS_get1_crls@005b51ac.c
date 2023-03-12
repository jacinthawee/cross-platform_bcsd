
stack_st_X509_CRL * CMS_get1_crls(CMS_ContentInfo *cms)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  stack_st_X509_CRL *psVar6;
  
  iVar1 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*(undefined4 *)cms);
  if (iVar1 == 0x16) {
    puVar5 = (undefined4 *)(*(int *)(cms + 4) + 0x10);
  }
  else {
    if (iVar1 != 0x17) {
      (*(code *)PTR_ERR_put_error_006a7f34)(0x2e,0x84,0x98,"cms_lib.c",0x1ef);
      return (stack_st_X509_CRL *)0x0;
    }
    puVar5 = (undefined4 *)(*(int *)(*(int *)(cms + 4) + 4) + 4);
  }
  if (puVar5 != (undefined4 *)0x0) {
    psVar6 = (stack_st_X509_CRL *)0x0;
    iVar1 = 0;
    while( true ) {
      do {
        iVar2 = (*(code *)PTR_sk_num_006a6e2c)(*puVar5);
        iVar4 = iVar1 + 1;
        if (iVar2 <= iVar1) {
          return psVar6;
        }
        piVar3 = (int *)(*(code *)PTR_sk_value_006a6e24)(*puVar5,iVar1);
        iVar1 = iVar4;
      } while (*piVar3 != 0);
      if ((psVar6 == (stack_st_X509_CRL *)0x0) &&
         (psVar6 = (stack_st_X509_CRL *)(*(code *)PTR_sk_new_null_006a6fa4)(),
         psVar6 == (stack_st_X509_CRL *)0x0)) {
        return (stack_st_X509_CRL *)0x0;
      }
      iVar2 = (*(code *)PTR_sk_push_006a6fa8)(psVar6,piVar3[1]);
      if (iVar2 == 0) break;
      (*(code *)PTR_CRYPTO_add_lock_006a805c)(piVar3[1] + 0xc,1,6,"cms_lib.c",0x24f);
    }
    (*(code *)PTR_sk_pop_free_006a7058)(psVar6,PTR_X509_CRL_free_006a7060,6);
  }
  return (stack_st_X509_CRL *)0x0;
}

