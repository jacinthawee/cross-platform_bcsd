
undefined4 i2r_ocsp_serviceloc(undefined4 param_1,undefined4 *param_2,BIO *param_3,int param_4)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar1 = (*(code *)PTR_BIO_printf_006a7f38)(param_3,"%*sIssuer: ",param_4,"");
  if ((0 < iVar1) &&
     (iVar1 = (*(code *)PTR_X509_NAME_print_ex_006a8cb0)(param_3,*param_2,0,0x82031f), 0 < iVar1)) {
    iVar1 = 0;
    while( true ) {
      iVar3 = (*(code *)PTR_sk_num_006a7f2c)(param_2[1]);
      if (iVar3 <= iVar1) {
        return 1;
      }
      puVar2 = (undefined4 *)(*(code *)PTR_sk_value_006a7f24)(param_2[1],iVar1);
      iVar3 = (*(code *)PTR_BIO_printf_006a7f38)(param_3,"\n%*s",param_4 << 1,"");
      if (iVar3 < 1) break;
      iVar3 = (*(code *)PTR_i2a_ASN1_OBJECT_006a812c)(param_3,*puVar2);
      if (iVar3 < 1) {
        return 0;
      }
      iVar3 = (*(code *)PTR_BIO_puts_006a8058)(param_3,&DAT_006682d4);
      if (iVar3 < 1) {
        return 0;
      }
      iVar3 = GENERAL_NAME_print(param_3,(GENERAL_NAME *)puVar2[1]);
      iVar1 = iVar1 + 1;
      if (iVar3 < 1) {
        return 0;
      }
    }
  }
  return 0;
}

