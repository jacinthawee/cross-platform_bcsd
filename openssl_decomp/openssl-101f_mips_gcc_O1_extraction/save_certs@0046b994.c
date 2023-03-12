
undefined4 save_certs(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (param_1 != 0) {
    iVar1 = (*(code *)PTR_BIO_new_file_006a7fac)(param_1,"w");
    if (iVar1 == 0) {
      uVar3 = 0;
    }
    else {
      iVar4 = 0;
      while( true ) {
        iVar2 = (*(code *)PTR_sk_num_006a7f2c)(param_2);
        if (iVar2 <= iVar4) break;
        uVar3 = (*(code *)PTR_sk_value_006a7f24)(param_2,iVar4);
        (*(code *)PTR_PEM_write_bio_X509_006a8020)(iVar1,uVar3);
        iVar4 = iVar4 + 1;
      }
      (*(code *)PTR_BIO_free_006a7f70)(iVar1);
      uVar3 = 1;
    }
    return uVar3;
  }
  return 1;
}

