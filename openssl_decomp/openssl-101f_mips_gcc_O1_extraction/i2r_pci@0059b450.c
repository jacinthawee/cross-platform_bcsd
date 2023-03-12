
undefined4 i2r_pci(undefined4 param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  (*(code *)PTR_BIO_printf_006a7f38)(param_3,"%*sPath Length Constraint: ",param_4,"");
  if (*param_2 == 0) {
    (*(code *)PTR_BIO_printf_006a7f38)(param_3,"infinite");
  }
  else {
    (*(code *)PTR_i2a_ASN1_INTEGER_006a86e4)(param_3);
  }
  (*(code *)PTR_BIO_puts_006a8058)(param_3,"\n");
  (*(code *)PTR_BIO_printf_006a7f38)(param_3,"%*sPolicy Language: ",param_4,"");
  (*(code *)PTR_i2a_ASN1_OBJECT_006a812c)(param_3,*(undefined4 *)param_2[1]);
  (*(code *)PTR_BIO_puts_006a8058)(param_3,"\n");
  if ((*(int *)(param_2[1] + 4) != 0) &&
     (iVar1 = *(int *)(*(int *)(param_2[1] + 4) + 8), iVar1 != 0)) {
    (*(code *)PTR_BIO_printf_006a7f38)(param_3,"%*sPolicy Text: %s\n",param_4,"",iVar1);
  }
  return 1;
}

