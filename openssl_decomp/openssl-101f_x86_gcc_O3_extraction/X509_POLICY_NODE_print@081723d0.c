
void X509_POLICY_NODE_print(BIO *out,X509_POLICY_NODE *node,int indent)

{
  byte *pbVar1;
  char *pcVar2;
  
  pbVar1 = *(byte **)node;
  BIO_printf(out,"%*sPolicy: ",indent,&DAT_081ec74a);
  i2a_ASN1_OBJECT(out,*(ASN1_OBJECT **)(pbVar1 + 4));
  BIO_puts(out,"\n");
  pcVar2 = "Critical";
  if ((*pbVar1 & 0x10) == 0) {
    pcVar2 = "Non Critical";
  }
  BIO_printf(out,"%*s%s\n",indent + 2,&DAT_081ec74a,pcVar2);
  if (*(int *)(pbVar1 + 8) != 0) {
    print_qualifiers();
    return;
  }
  BIO_printf(out,"%*sNo Qualifiers\n",indent + 2,&DAT_081ec74a);
  return;
}

