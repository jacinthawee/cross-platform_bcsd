
void X509_POLICY_NODE_print(BIO *out,X509_POLICY_NODE *node,int indent)

{
  uint *puVar1;
  char *pcVar2;
  
  puVar1 = *(uint **)node;
  BIO_printf(out,"%*sPolicy: ",indent,"");
  i2a_ASN1_OBJECT(out,(ASN1_OBJECT *)puVar1[1]);
  BIO_puts(out,"\n");
  pcVar2 = "Non Critical";
  if ((*puVar1 & 0x10) != 0) {
    pcVar2 = "Critical";
  }
  BIO_printf(out,"%*s%s\n",indent + 2,"",pcVar2);
  if (puVar1[2] != 0) {
    print_qualifiers(out,puVar1[2],indent + 2);
    return;
  }
  BIO_vprintf(out,"%*sNo Qualifiers\n",&stack0xfffffff8);
  return;
}

