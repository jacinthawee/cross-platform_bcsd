
int X509_load_cert_crl_file_part_0(int param_1,undefined4 param_2)

{
  BIO *bp;
  stack_st_X509_INFO *psVar1;
  int iVar2;
  X509 **ppXVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  bp = (BIO *)(*(code *)PTR_BIO_new_file_006a6eac)(param_2,"r");
  if (bp == (BIO *)0x0) {
    uVar5 = 2;
    uVar4 = 0xfd;
  }
  else {
    psVar1 = PEM_X509_INFO_read_bio(bp,(stack_st_X509_INFO *)0x0,(undefined1 *)0x0,(void *)0x0);
    (*(code *)PTR_BIO_free_006a6e70)(bp);
    if (psVar1 != (stack_st_X509_INFO *)0x0) {
      iVar8 = 0;
      iVar6 = 0;
      while( true ) {
        iVar2 = (*(code *)PTR_sk_num_006a6e2c)(psVar1);
        iVar7 = iVar6 + 1;
        if (iVar2 <= iVar6) break;
        ppXVar3 = (X509 **)(*(code *)PTR_sk_value_006a6e24)(psVar1,iVar6);
        if (*ppXVar3 != (X509 *)0x0) {
          iVar8 = iVar8 + 1;
          X509_STORE_add_cert(*(X509_STORE **)(param_1 + 0x10),*ppXVar3);
        }
        iVar6 = iVar7;
        if (ppXVar3[1] != (X509 *)0x0) {
          iVar8 = iVar8 + 1;
          X509_STORE_add_crl(*(X509_STORE **)(param_1 + 0x10),(X509_CRL *)ppXVar3[1]);
        }
      }
      (*(code *)PTR_sk_pop_free_006a7058)(psVar1,PTR_X509_INFO_free_006a75c8);
      return iVar8;
    }
    uVar5 = 9;
    uVar4 = 0x103;
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0xb,0x84,uVar5,"by_file.c",uVar4);
  return 0;
}

