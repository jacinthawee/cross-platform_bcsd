
undefined4 i2r_certpol(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  while( true ) {
    iVar1 = (*(code *)PTR_sk_num_006a7f2c)(param_2);
    iVar4 = iVar3 + 1;
    if (iVar1 <= iVar3) break;
    puVar2 = (undefined4 *)(*(code *)PTR_sk_value_006a7f24)(param_2,iVar3);
    (*(code *)PTR_BIO_printf_006a7f38)(param_3,"%*sPolicy: ",param_4,"");
    (*(code *)PTR_i2a_ASN1_OBJECT_006a812c)(param_3,*puVar2);
    (*(code *)PTR_BIO_puts_006a8058)(param_3,"\n");
    iVar3 = iVar4;
    if (puVar2[1] != 0) {
      print_qualifiers(param_3,puVar2[1],param_4 + 2);
    }
  }
  return 1;
}

