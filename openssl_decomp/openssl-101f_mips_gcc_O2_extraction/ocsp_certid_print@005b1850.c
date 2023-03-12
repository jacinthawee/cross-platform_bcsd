
undefined4 ocsp_certid_print(undefined4 param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  
  iVar1 = param_3 + 2;
  (*(code *)PTR_BIO_printf_006a7f38)(param_1,"%*sCertificate ID:\n",param_3,"");
  (*(code *)PTR_BIO_printf_006a7f38)(param_1,"%*sHash Algorithm: ",iVar1,"");
  (*(code *)PTR_i2a_ASN1_OBJECT_006a812c)(param_1,*(undefined4 *)*param_2);
  (*(code *)PTR_BIO_printf_006a7f38)(param_1,"\n%*sIssuer Name Hash: ",iVar1,"");
  (*(code *)PTR_i2a_ASN1_STRING_006aa1a4)(param_1,param_2[1],4);
  (*(code *)PTR_BIO_printf_006a7f38)(param_1,"\n%*sIssuer Key Hash: ",iVar1,"");
  (*(code *)PTR_i2a_ASN1_STRING_006aa1a4)(param_1,param_2[2],4);
  (*(code *)PTR_BIO_printf_006a7f38)(param_1,"\n%*sSerial Number: ",iVar1,"");
  (*(code *)PTR_i2a_ASN1_INTEGER_006a86e4)(param_1,param_2[3]);
  (*(code *)PTR_BIO_printf_006a7f38)(param_1,"\n");
  return 1;
}

