
undefined4 sxnet_i2r(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  ASN1_INTEGER **ppAVar2;
  char *pcVar3;
  int iVar4;
  
  iVar1 = (*(code *)PTR_ASN1_INTEGER_get_006a831c)(*param_2);
  (*(code *)PTR_BIO_printf_006a7f38)(param_3,"%*sVersion: %ld (0x%lX)",param_4,"",iVar1 + 1,iVar1);
  iVar1 = 0;
  while( true ) {
    iVar4 = (*(code *)PTR_sk_num_006a7f2c)(param_2[1]);
    if (iVar4 <= iVar1) break;
    ppAVar2 = (ASN1_INTEGER **)(*(code *)PTR_sk_value_006a7f24)(param_2[1],iVar1);
    pcVar3 = i2s_ASN1_INTEGER((X509V3_EXT_METHOD *)0x0,*ppAVar2);
    (*(code *)PTR_BIO_printf_006a7f38)(param_3,"\n%*sZone: %s, User: ",param_4,"",pcVar3);
    (*(code *)PTR_CRYPTO_free_006a7f88)(pcVar3);
    (*(code *)PTR_ASN1_STRING_print_006a9e74)(param_3,ppAVar2[1]);
    iVar1 = iVar1 + 1;
  }
  return 1;
}

