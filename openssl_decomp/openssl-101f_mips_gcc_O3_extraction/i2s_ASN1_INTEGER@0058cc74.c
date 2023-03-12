
char * i2s_ASN1_INTEGER(X509V3_EXT_METHOD *meth,ASN1_INTEGER *aint)

{
  int iVar1;
  char *pcVar2;
  
  if (aint == (ASN1_INTEGER *)0x0) {
    return (char *)0x0;
  }
  iVar1 = (*(code *)PTR_ASN1_INTEGER_to_BN_006a8114)(aint,0);
  if (iVar1 != 0) {
    pcVar2 = (char *)(*(code *)PTR_BN_bn2dec_006a8f28)(iVar1);
    if (pcVar2 != (char *)0x0) goto LAB_0058cccc;
  }
  pcVar2 = (char *)0x0;
  (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x78,0x41,"v3_utl.c",0x9a);
LAB_0058cccc:
  (*(code *)PTR_BN_free_006a811c)(iVar1);
  return pcVar2;
}

