
int EVP_PKEY_print_private(BIO *out,EVP_PKEY *pkey,int indent,ASN1_PCTX *pctx)

{
  code *UNRECOVERED_JUMPTABLE;
  int iVar1;
  char *pcVar2;
  
  if ((pkey->ameth != (EVP_PKEY_ASN1_METHOD *)0x0) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(pkey->ameth + 0x2c), UNRECOVERED_JUMPTABLE != (code *)0x0))
  {
                    /* WARNING: Could not recover jumptable at 0x08131584. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*UNRECOVERED_JUMPTABLE)();
    return iVar1;
  }
  BIO_indent(out,indent,0x80);
  pcVar2 = OBJ_nid2ln(pkey->type);
  BIO_printf(out,"%s algorithm \"%s\" unsupported\n","Private Key",pcVar2);
  return 1;
}

