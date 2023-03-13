
void X509_POLICY_NODE_print(BIO *out,X509_POLICY_NODE *node,int indent)

{
  char *pcVar1;
  int iVar2;
  uint *puVar3;
  
  iVar2 = indent + 2;
  puVar3 = *(uint **)node;
  (*(code *)PTR_BIO_printf_006a6e38)(out,"%*sPolicy: ",indent,"");
  (*(code *)PTR_i2a_ASN1_OBJECT_006a702c)(out,puVar3[1]);
  (*(code *)PTR_BIO_puts_006a6f58)(out,"\n");
  if ((*puVar3 & 0x10) == 0) {
    pcVar1 = "Non Critical";
  }
  else {
    pcVar1 = "Critical";
  }
  (*(code *)PTR_BIO_printf_006a6e38)(out,"%*s%s\n",iVar2,"",pcVar1);
  if (puVar3[2] != 0) {
    print_qualifiers(out,puVar3[2],iVar2);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00592234. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_BIO_printf_006a6e38)(out,"%*sNo Qualifiers\n",iVar2,"");
  return;
}

