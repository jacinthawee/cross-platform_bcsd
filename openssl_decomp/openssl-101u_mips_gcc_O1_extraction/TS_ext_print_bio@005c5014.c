
undefined4 TS_ext_print_bio(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  
  (*(code *)PTR_BIO_printf_006a6e38)(param_1,"Extensions:\n");
  iVar1 = (*(code *)PTR_X509v3_get_ext_count_006a8f44)(param_2);
  if (0 < iVar1) {
    iVar6 = 0;
    do {
      while( true ) {
        iVar2 = (*(code *)PTR_X509v3_get_ext_006a8f54)(param_2,iVar6);
        uVar3 = (*(code *)PTR_X509_EXTENSION_get_object_006a7bb4)(iVar2);
        (*(code *)PTR_i2a_ASN1_OBJECT_006a702c)(param_1,uVar3);
        iVar4 = (*(code *)PTR_X509_EXTENSION_get_critical_006a8d4c)(iVar2);
        pcVar5 = "critical";
        if (iVar4 == 0) {
          pcVar5 = "";
        }
        iVar6 = iVar6 + 1;
        (*(code *)PTR_BIO_printf_006a6e38)(param_1,": %s\n",pcVar5);
        iVar4 = (*(code *)PTR_X509V3_EXT_print_006a8d50)(param_1,iVar2,0,4);
        if (iVar4 != 0) break;
        (*(code *)PTR_BIO_printf_006a6e38)(param_1,&DAT_00672f50,"");
        (*(code *)PTR_ASN1_STRING_print_006a8d54)(param_1,*(undefined4 *)(iVar2 + 8));
        (*(code *)PTR_BIO_write_006a6e14)(param_1,"\n",1);
        if (iVar1 == iVar6) {
          return 1;
        }
      }
      (*(code *)PTR_BIO_write_006a6e14)(param_1,"\n",1);
    } while (iVar1 != iVar6);
  }
  return 1;
}

