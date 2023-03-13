
int TS_CONF_load_certs(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  
  iVar1 = (*(code *)PTR_BIO_new_file_006a6eac)(param_1,"r");
  if (iVar1 != 0) {
    iVar2 = (*(code *)PTR_sk_new_null_006a6fa4)();
    if (iVar2 != 0) {
      uVar3 = (*(code *)PTR_PEM_X509_INFO_read_bio_006a75c4)(iVar1,0,0,0);
      iVar6 = 0;
      while( true ) {
        iVar4 = (*(code *)PTR_sk_num_006a6e2c)(uVar3);
        iVar7 = iVar6 + 1;
        if (iVar4 <= iVar6) break;
        piVar5 = (int *)(*(code *)PTR_sk_value_006a6e24)(uVar3,iVar6);
        iVar6 = iVar7;
        if (*piVar5 != 0) {
          (*(code *)PTR_sk_push_006a6fa8)(iVar2,*piVar5);
          *piVar5 = 0;
        }
      }
      goto LAB_005c5508;
    }
  }
  uVar3 = 0;
  iVar2 = 0;
  (*(code *)PTR___fprintf_chk_006a9980)
            (*(undefined4 *)PTR_stderr_006a9af8,1,"unable to load certificates: %s\n",param_1);
LAB_005c5508:
  (*(code *)PTR_sk_pop_free_006a7058)(uVar3,PTR_X509_INFO_free_006a75c8);
  (*(code *)PTR_BIO_free_006a6e70)(iVar1);
  return iVar2;
}

